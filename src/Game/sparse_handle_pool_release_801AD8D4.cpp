/* Sparse handle-row pool release and visit (fn_801AD8D4, fn_801AD9FC). */
typedef unsigned long SparsePoolWord;
struct SparsePoolTarget;
struct SparsePoolEntry {
    SparsePoolTarget* object;
    SparsePoolWord unknown04[2];
    signed char generation;
    char pad[3];
    signed char getGeneration() const { return generation; }
};
struct SparsePoolManager { int count, capacity; SparsePoolEntry* entries; };
struct SparsePoolGlobals { char unknown00[0x118]; SparsePoolManager* manager; };
extern "C" {
extern SparsePoolGlobals lbl_801E9D24;
extern char lbl_8028F698[];
void fn_8028FD50(void*, void*, SparsePoolWord);
SparsePoolTarget* fn_801F7EB8(const void*);
}
struct SparsePoolTarget {
    SparsePoolWord unknown00, unknown04;
    virtual ~SparsePoolTarget();
    virtual void slot0C(SparsePoolWord);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
};
struct Handle_801F7F10 {
    union {
        SparsePoolWord value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
    SparsePoolTarget* get() const
    {
        int index = bits.index;
        SparsePoolManager* m = lbl_801E9D24.manager;
        int generation = m->entries[index].getGeneration();
        return generation == bits.generation ? m->entries[index].object : 0;
    }
};
struct SparsePoolHandle1 : Handle_801F7F10 { SparsePoolHandle1() { value = 0; } };
struct SparsePoolHandle : SparsePoolHandle1 { SparsePoolHandle() { value = 0; } ~SparsePoolHandle() {} };
template <class T> struct SparsePoolArray {
    int count, capacity;
    T* data;
    ~SparsePoolArray()
    {
        if (data) {
            for (int i = 0; i < count; ++i) data[i].~T();
            if (data) { fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T)); data = 0; }
            data = 0;
        }
    }
};
struct SparsePoolBits {
    int count, capacity;
    SparsePoolWord* words;
    int bits;
    const SparsePoolWord& word(int i) { SparsePoolWord* base = words; return base[i]; }
    signed char test(int i) { return (word(i >> 5) & (1UL << (i & 31))) ? 1 : 0; }
};
extern "C" int fn_80207B94(SparsePoolBits*, signed char, int);
struct SparsePoolRow {
    SparsePoolArray<SparsePoolHandle> slots;
    SparsePoolWord key;
    int references;
    ~SparsePoolRow() {}
    const int& size() { return slots.count; }
};
struct SparsePool {
    int count, capacity;
    SparsePoolRow* data;
    SparsePoolBits occupied;
    int high, live;
    SparsePoolRow& at(int i) { return data[i]; }
    void release(int record, SparsePoolRow* entry)
    {
        if (occupied.test(record)) {
            entry->~SparsePoolRow();
            SparsePoolWord mask = 1UL << (record & 31);
            SparsePoolWord w = occupied.words[record >> 5];
            w &= ~mask;
            occupied.words[record >> 5] = w;
            --live;
        }
    }
    int first() { return !high ? -1 : fn_80207B94(&occupied, 1, 0); }
    int next(int index) { return index + 1 >= high ? -1 : fn_80207B94(&occupied, 1, index + 1); }
};
struct SparsePoolOwner {
    char unknown00[0xB0];
    SparsePool pool;
};

extern "C" void fn_801AD8D4(SparsePoolOwner* self, int record)
{
    --self->pool.data[record].references;
    SparsePoolRow& entry = self->pool.at(record);
    if (entry.references == 0) self->pool.release(record, &entry);
}

extern "C" void fn_801AD9FC(SparsePoolOwner* self)
{
    int n;
    int offset;
    SparsePoolRow* row;
    int index;
    int i;
    index = self->pool.first();
    while (index >= 0) {
        row = &self->pool.data[index];
        if (row->references) {
            n = row->slots.count;
            for (i = 0, offset = 0; i < n; offset += 4, i++) {
                if (fn_801F7EB8(((SparsePoolHandle*)((char*)row->slots.data + offset)))) ((SparsePoolHandle*)((char*)row->slots.data + offset))->get()->slot1C();
            }
        }
        index = index + 1 >= self->pool.high ? -1 : fn_80207B94(&self->pool.occupied, 1, index + 1);
    }
}
