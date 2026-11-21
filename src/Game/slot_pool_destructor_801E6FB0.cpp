// SlotPool_801E6FB0::~SlotPool_801E6FB0 (0x801E6FB0, 412 bytes).
// Native bitmap-selected record pool: record storage header at +0, occupancy
// bitset at +0xC, slot limit +0x1C, live count +0x20. Each occupied 36-byte
// record is destroyed in place (its handle array, then its bitset), its bit is
// cleared and the live count decremented; then the pool bitset and record
// storage are released. The record accessor takes an unsigned index: that
// keeps the outer loop's byte-offset induction variable out of strength
// reduction (increment after the index, offset in r25, row in r31).
typedef unsigned long u32;
extern "C" {
extern char lbl_8028F698[], lbl_801EF5C8[];
void fn_8028FD50(void*, void*, u32);
void fn_801EF610(void*, void*);
}
struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct OwnerHandle : Handle_801F7F10 {
    OwnerHandle() { value = 0; }
};
struct ResetHandle2 : OwnerHandle {
    ResetHandle2() { value = 0; }
    ~ResetHandle2() {}
};
template<class T> struct WorldCurveArray {
    int count, capacity;
    T* data;
    ~WorldCurveArray() {
        if (data) {
            for (int i = 0; i < count; ++i) data[i].~T();
            if (data) {
                fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
                data = 0;
            }
            data = 0;
        }
    }
};
struct BitSet_80207EE8 {
    int count, capacity;
    u32* words;
    int bits;
    ~BitSet_80207EE8();
    const u32& word(int i) { u32* base = words; return base[i]; }
    signed char test(int i) { return (word(i >> 5) & (1UL << (i & 31))) ? 1 : 0; }
};
struct SlotRecord {
    u32 name;
    int references;
    BitSet_80207EE8 occupied;
    WorldCurveArray<ResetHandle2> slots;
    ~SlotRecord() {}
};
template<class T> struct SlotRecordStorage {
    int count, capacity;
    T* data;
    T& at(u32 i) { return data[i]; }
    void freeStorage() {
        if (data) {
            fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
            data = 0;
        }
    }
    ~SlotRecordStorage() {
        if (data) {
            freeStorage();
            data = 0;
        }
    }
};
struct SlotPool_801E6FB0 : SlotRecordStorage<SlotRecord> {
    BitSet_80207EE8 occupied;
    int limit, live;
    ~SlotPool_801E6FB0();
    signed char release(int i) {
        if (occupied.test(i)) {
            at(i).~SlotRecord();
            u32 mask = 1UL << (i & 31);
            u32 w = occupied.words[i >> 5];
            w &= ~mask;
            occupied.words[i >> 5] = w;
            --live;
            return 1;
        }
        return 0;
    }
    static void operator delete(void* p) { fn_801EF610(lbl_801EF5C8, p); }
};
typedef char CheckSlotRecord[sizeof(SlotRecord) == 0x24 ? 1 : -1];
typedef char CheckSlotPool[sizeof(SlotPool_801E6FB0) == 0x24 ? 1 : -1];

SlotPool_801E6FB0::~SlotPool_801E6FB0() {
    for (int i = 0; i < limit; ++i) release(i);
}
