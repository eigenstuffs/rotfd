typedef unsigned long SparseAcquireWord;

struct SparseAcquireRow {
    int count, capacity;
    SparseAcquireWord* items;
    SparseAcquireWord key;
    int refs;

    void setKey(const SparseAcquireWord* value) { key = *value; }
    bool matches(const SparseAcquireWord* value) const { return key == *value; }
};

struct SparseAcquireRows {
    int count, capacity;
    SparseAcquireRow* items;
    SparseAcquireRow& operator[](int index) { return items[index]; }
};

struct SparseAcquireBits {
    int count, capacity;
    SparseAcquireWord* items;
    int requested;
};

extern "C" int fn_80207B94(SparseAcquireBits*, signed char, int);

struct SparseAcquirePool {
    SparseAcquireRows rows;
    SparseAcquireBits occupied;
    int high, active;

    int first() { return !high ? -1 : fn_80207B94(&occupied, 1, 0); }
    int next(int index) {
        return index + 1 >= high ? -1 : fn_80207B94(&occupied, 1, index + 1);
    }
};

struct SparseAcquireOwner {
    char unknown00[0xB0];
    SparseAcquirePool pool;
};

typedef char SparseAcquireRowSize[sizeof(SparseAcquireRow) == 20 ? 1 : -1];
typedef char SparseAcquireBitsSize[sizeof(SparseAcquireBits) == 16 ? 1 : -1];
typedef char SparseAcquirePoolSize[sizeof(SparseAcquirePool) == 36 ? 1 : -1];

extern "C" int fn_801ADC08(SparseAcquirePool*);

extern "C" int fn_801ADB28(SparseAcquireOwner* self, const SparseAcquireWord* key) {
    int index = self->pool.first();
    while (index >= 0) {
        if (self->pool.rows[index].matches(key)) {
            ++self->pool.rows[index].refs;
            return index;
        }
        index = self->pool.next(index);
    }
    index = fn_801ADC08(&self->pool);
    self->pool.rows[index].setKey(key);
    self->pool.rows[index].refs = 1;
    return index;
}
