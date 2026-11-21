#ifndef GAME_BITSET_INTERNAL_H
#define GAME_BITSET_INTERNAL_H
// Native bitset range clearing and destruction reconstructed from GSQE78.
typedef unsigned long u32;
extern "C" {
extern char lbl_801EF5C8[];
extern char lbl_8028F698[];
void fn_801EF610(void*, void*);
void fn_8028FD50(void*, void*, u32);
void __ct__15BitSet_80207EE8Fv(void*);
}
struct WordArray {
    int count, capacity;
    u32* data;
    ~WordArray() {
        if (data) {
            for (int i = 0; i < count; ++i)
                data[i].~u32();
            if (data) {
                fn_8028FD50(lbl_8028F698, data, capacity * 4);
                data = 0;
            }
            data = 0;
        }
    }
};
struct BitSet_80207EE8 : WordArray {
    int bits;
    BitSet_80207EE8();
    ~BitSet_80207EE8();
    static void operator delete(void* memory) {
        fn_801EF610(lbl_801EF5C8, memory);
    }
};


#endif
