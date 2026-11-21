typedef unsigned long u32;
extern "C" {
extern char lbl_8028F698[], lbl_801EF5C8[];
void fn_8028FD50(void*, void*, u32);
void fn_801EF610(void*, void*);
}
struct Handle_801F7F10 { u32 value; ~Handle_801F7F10(); };
struct BitSet_80207EE8 {
    int count, capacity; u32* data; int bits;
    ~BitSet_80207EE8();
    signed char test(int i) const { return (data[i >> 5] & (1 << (i & 31))) ? 1 : 0; }
    void clear(int i) { data[i >> 5] &= ~(1 << (i & 31)); }
};
template<class T> inline void destroy(T* p) { if (p) p->~T(); }
template<class T> inline void destroyRef(T& r) { r.~T(); }
template<class T> inline void destroyPtr(T* p) { p->~T(); }
template<class T> struct Array {
    int size, capacity; T* data;
    void releaseStorage() { if (data) { fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T)); data = 0; } }
    ~Array() { if (data) { for (int i = 0; i < size; ++i) destroyRef(data[i]); releaseStorage(); data = 0; } }
};
template<class T> struct Storage {
    int size, capacity; T* data;
    void releaseStorage() { if (data) { fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T)); data = 0; } }
    ~Storage() { if (data) { releaseStorage(); data = 0; } }
};
struct ItemHandle : Handle_801F7F10 { ~ItemHandle() {} };
struct Item { int size, capacity; ItemHandle* data; u32 unknown0C, unknown10;
    void releaseStorage() { if (data) { fn_8028FD50(lbl_8028F698, data, capacity * sizeof(ItemHandle)); data = 0; } }
    ~Item() { if (data) { for (int i = 0; i < size; ++i) destroy(&data[i]); releaseStorage(); data = 0; } }
};
struct BS2 {
    int count, capacity;
    u32* words;
    int bits;
    const u32& word(int i) { u32* base = words; return base[i]; }
    signed char test(int i) { return (word(i >> 5) & (1UL << (i & 31))) ? 1 : 0; }
};
struct HArr { int size, capacity; ItemHandle* data;
    ~HArr() { if (data) { for (int i = 0; i < size; ++i) destroy(&data[i]); if (data) { fn_8028FD50(lbl_8028F698, data, capacity * sizeof(ItemHandle)); data = 0; } data = 0; } }
};
struct Slot { HArr h; u32 a, b; ~Slot() {} void fin() { if (h.data) { for (int i = 0; i < h.size; ++i) destroy(&h.data[i]); if (h.data) { fn_8028FD50(lbl_8028F698, h.data, h.capacity * sizeof(ItemHandle)); h.data = 0; } h.data = 0; } } void fin2() { if (this) fin(); } };
template<class T> struct RecStorage {
    int count, capacity;
    T* data;
    T& at(u32 i) { return data[i]; }
    void freeStorage() { if (data) { fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T)); data = 0; } }
    ~RecStorage() { if (data) { freeStorage(); data = 0; } }
};
struct Pool2 : RecStorage<Slot> {
    BS2 occupied;
    int limit, live;
    signed char release(int i) {
        if (occupied.test(i)) {
            Slot* s = &at(i); if (s) s->h.~HArr();
            u32 mask = 1UL << (i & 31);
            u32 w = occupied.words[i >> 5];
            w &= ~mask;
            occupied.words[i >> 5] = w;
            --live;
            return 1;
        }
        return 0;
    }
};
extern "C" Pool2* fn_801F551C(Pool2* self, short flag) {
    if (self) {
        for (int i = 0; i < self->limit; ++i) self->release(i);
        ((BitSet_80207EE8*)&self->occupied)->~BitSet_80207EE8();
        self->RecStorage<Slot>::~RecStorage();
        if (flag > 0) fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
struct BS {
    int count, capacity; u32* words; int bits;
    const u32& word(int i) const { return words[i]; }
    signed char test(int i) const { const u32& flags = word(i >> 5); return ((1UL << (i & 31)) & flags) ? 1 : 0; }
    void clear(int i) { words[i >> 5] &= ~(1UL << (i & 31)); }
};
extern "C" { extern char lbl_802EAA98[]; void* fn_80208768(void*, int); }
struct Base16 { char bytes[0x10]; void destroy() { fn_80208768(this, -1); } };
struct Word4 { u32 value; void destroy() {} };
template<class T> struct Records {
    int count, capacity; T* items;
    T& at(int i) { return items[i]; }
    ~Records() { if (items) { if (items) { fn_8028FD50(lbl_8028F698, items, capacity * sizeof(T)); items = 0; } items = 0; } }
};
/* Same pool shape written two ways: the trivially-destructible element pools
   and the 16-byte record pool only allocate registers like the original with
   these respective spellings of the occupancy test/clear. */
template<class T> struct Sparse : Records<T> {
    BS occupied; int limit, used;
    signed char release(int i) {
        if (occupied.test(i)) {
            at(i).destroy();
            u32 mask = 1UL << (i & 31);
            u32 w = occupied.words[i >> 5];
            w &= ~mask;
            occupied.words[i >> 5] = w;
            --used;
            return 1;
        }
        return 0;
    }
    ~Sparse() {
        for (int i = 0; i < limit; ++i) release(i);
        ((BitSet_80207EE8*)&occupied)->~BitSet_80207EE8();
    }
};
template<class T> struct SparseRecords : Records<T> {
    BS occupied; int limit, used;
    const u32& word(int i) const { u32* p = occupied.words; return p[i]; }
    signed char test(int i) const { return (word(i >> 5) & (1UL << (i & 31))) ? 1 : 0; }
    ~SparseRecords() {
        for (int i = 0; i < limit; ++i) {
            if (test(i)) {
                items[static_cast<unsigned int>(i)].destroy();
                u32 mask = 1UL << (i & 31);
                u32 w = occupied.words[i >> 5];
                w &= ~mask;
                occupied.words[i >> 5] = w;
                --used;
            }
        }
        ((BitSet_80207EE8*)&occupied)->~BitSet_80207EE8();
    }
};
struct Owner {
    char base[0x10];
    Sparse<Word4> first;
    Sparse<Word4> second;
    SparseRecords<Base16> third;
    void* table;
};
extern "C" Owner* fn_801F56A8(Owner* self, short flag) {
    if (self) {
        self->table = lbl_802EAA98;
        self->third.~SparseRecords<Base16>();
        self->second.~Sparse<Word4>();
        self->first.~Sparse<Word4>();
        fn_80208768(self, -1);
        if (flag > 0) fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
