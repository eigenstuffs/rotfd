struct Handle_801F7F10 {
    union {
        unsigned long value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct SparseEraseZero1 : Handle_801F7F10 { SparseEraseZero1() { value = 0; } };
struct SparseEraseHandle : SparseEraseZero1 { SparseEraseHandle() { value = 0; } };
struct SparseEraseObject { char unknown0000[0xD9F8]; long firstState, secondState; };
struct SparseEraseEntry {
    SparseEraseObject* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct SparseEraseManager;
struct SparseEraseVtable { char unknown00[8]; void (*flush)(SparseEraseManager*); };
struct SparseEraseManagerStorage { char unknown00[8]; SparseEraseEntry* entries; char unknown0C[0x18]; };
struct SparseEraseManager : SparseEraseManagerStorage { virtual void flush(); };
extern "C" {
    extern struct { char unknown00[0x118]; SparseEraseManager* manager; } lbl_801E9D24;
    unsigned long fn_801F7EB8(const void*);
}
inline SparseEraseObject* resolveSparseErase(const Handle_801F7F10& handle) {
    int index = handle.bits.index;
    SparseEraseManager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    if (generation == handle.bits.generation) return manager->entries[index].object;
    return 0;
}
struct SparseEraseBits {
    int count, capacity;
    unsigned long* words;
    int bitCount;
    const unsigned long& word(int i) const { unsigned long* base=words; return base[i]; }
    signed char test(int index) const { return (word(index >> 5) & (1UL << (index & 31))) ? 1 : 0; }
};
extern "C" int fn_80207B94(SparseEraseBits*, signed char, int);
struct SparseEraseSelf {
    int count, capacity;
    SparseEraseHandle* items;
    SparseEraseBits occupied;
    int limit, used;
    SparseEraseHandle& operator[](int i) { return items[i]; }
    int first() { if (limit == 0) return -1; return fn_80207B94(&occupied, 1, 0); }
    int next(int i) { if (i + 1 >= limit) return -1; return fn_80207B94(&occupied, 1, i + 1); }
    void erase(int index) {
        if (occupied.test(index)) {
            items[static_cast<unsigned int>(index)].~SparseEraseHandle();
            occupied.words[index >> 5] &= ~(1UL << (index & 31));
            --used;
        }
    }
};
extern "C" void fn_8026B560(SparseEraseSelf* self, const Handle_801F7F10& input) {
    for (int i = self->first(); i >= 0; i = self->next(i)) {
        if (resolveSparseErase((*self)[i]) == resolveSparseErase(input)) {
            if (fn_801F7EB8(&(*self)[i])) {
                SparseEraseObject* target = resolveSparseErase((*self)[i]);
                target->firstState = 0;
                target->secondState = 0;
            }
            self->erase(i);
            break;
        }
    }
    SparseEraseManager* manager = lbl_801E9D24.manager;
    manager->flush();
}
