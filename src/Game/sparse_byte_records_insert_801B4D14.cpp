typedef unsigned long SparseByteRecordWord;

extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, SparseByteRecordWord, SparseByteRecordWord);
void* fn_8028FF24(void*, SparseByteRecordWord);
void fn_8028FD50(void*, void*, SparseByteRecordWord);
}

inline void* operator new(unsigned long, void* place) {
    return place;
}

template<class T>
struct SparseByteRecordArray {
    int count;
    int capacity;
    T* items;

    SparseByteRecordArray() {
        count = 0;
        capacity = 0;
        items = 0;
    }

    void reserve(int n) {
        if (n) {
            if (items) {
                items = (T*)fn_8028FAF4(lbl_8028F698, items,
                                        capacity * sizeof(T), n * sizeof(T));
            } else {
                items = (T*)fn_8028FF24(lbl_8028F698, n * sizeof(T));
            }
        } else if (items) {
            fn_8028FD50(lbl_8028F698, items, capacity * sizeof(T));
            items = 0;
        }
        capacity = n;
    }

    void grow() {
        int n = capacity + 32;
        if (n) {
            if (items) {
                items = (T*)fn_8028FAF4(lbl_8028F698, items,
                                        capacity * sizeof(T), n * sizeof(T));
            } else {
                items = (T*)fn_8028FF24(lbl_8028F698, n * sizeof(T));
            }
        } else if (items) {
            fn_8028FD50(lbl_8028F698, items, capacity * sizeof(T));
            items = 0;
        }
        capacity += 32;
    }

    void resize(int n) {
        int i;
        if (n > count) {
            reserve(n);
            for (i = count; i < n; ++i) {
                new (items + i) T;
            }
            count = n;
        } else if (n < count) {
            for (i = count - 1; i >= n; --i) {
                items[i].~T();
            }
            reserve(n);
            count = n;
        }
    }

    void append() {
        if (count + 1 > capacity) {
            grow();
        }
        new (items + count++) T;
    }
};

struct SparseByteRecordRow {
    char bytes[129];
};

struct SparseByteRecordBits {
    SparseByteRecordArray<SparseByteRecordWord> words;
    int requested;

    void resize(int n) {
        requested = n;
        if (n && (n >> 5) + 1 > words.count) {
            words.resize((requested >> 5) + 1);
        }
    }

    void set(int i) {
        words.items[i >> 5] |= 1UL << (i & 31);
    }
};

extern "C" int fn_80207B94(SparseByteRecordBits*, signed char, int);

struct SparseByteRecordPool {
    SparseByteRecordArray<SparseByteRecordRow> rows;
    SparseByteRecordBits bits;
    int high;
    int active;

    int first() {
        return !high ? -1 : fn_80207B94(&bits, 0, 0);
    }
};

extern "C" int fn_801B4D14(SparseByteRecordPool* self) {
    int i = self->first();
    ++self->active;
    if (i == -1) {
        self->rows.append();
        self->bits.resize(self->high + 1);
        self->bits.set(self->high);
        return self->high++;
    }
    new (self->rows.items + i) SparseByteRecordRow;
    self->bits.set(i);
    return i;
}
