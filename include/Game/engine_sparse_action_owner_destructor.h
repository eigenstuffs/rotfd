#ifndef GAME_ENGINE_SPARSE_ACTION_OWNER_DESTRUCTOR_H
#define GAME_ENGINE_SPARSE_ACTION_OWNER_DESTRUCTOR_H

typedef unsigned long SparseActionWord;
extern "C" {
extern char lbl_8028F698[], lbl_801EF5C8[];
void fn_8028FD50(void*, void*, int);
void fn_801EF610(void*, void*);
}

struct Handle_801F7F10 { SparseActionWord word; ~Handle_801F7F10(); };
struct SparseActionHandle1 : Handle_801F7F10 { ~SparseActionHandle1() {} };
struct SparseActionHandle2 : SparseActionHandle1 { ~SparseActionHandle2() {} };
struct SparseActionHandle3 : SparseActionHandle2 { ~SparseActionHandle3() {} };
struct BitSet_80207EE8 {
    int count, capacity;
    SparseActionWord* data;
    int bits;
    ~BitSet_80207EE8();
};
/* Same-size storage view of the existing externally destroyed fixed array. */
struct WorldHandleArray_801E55C4 {
    char unknown[576];
    ~WorldHandleArray_801E55C4();
};

template<class T> struct SparseActionArray {
    int count, capacity;
    T* data;
    ~SparseActionArray() {
        if (data) {
            for (int i = 0; i < count; i++)
                data[i].~T();
            if (data) {
                fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
                data = 0;
            }
            data = 0;
        }
    }
};
struct SparseActionRecord {
    SparseActionWord word;
    SparseActionHandle2 handle;
    SparseActionWord other;
    ~SparseActionRecord() {}
};
struct SparseActionRecords {
    int count, capacity;
    SparseActionRecord* data;
    ~SparseActionRecords() {
        if (data) {
            if (data) {
                fn_8028FD50(lbl_8028F698, data, capacity * sizeof(SparseActionRecord));
                data = 0;
            }
            data = 0;
        }
    }
};
struct SparseActionPool : SparseActionRecords {
    BitSet_80207EE8 occupied;
    int limit, used;
    const SparseActionWord& word(int i) const {
        SparseActionWord* p = occupied.data;
        return p[i];
    }
    signed char test(int i) const {
        return (word(i >> 5) & (1UL << (i & 31))) ? 1 : 0;
    }
    ~SparseActionPool() {
        for (int i = 0; i < limit; i++) {
            if (test(i)) {
                data[static_cast<unsigned int>(i)].~SparseActionRecord();
                occupied.data[i >> 5] &= ~(1UL << (i & 31));
                --used;
            }
        }
    }
};
struct SparseActionOwner {
    SparseActionArray<SparseActionHandle2> first, second;
    SparseActionHandle2 scalar;
    SparseActionPool records;
    WorldHandleArray_801E55C4 fixed;
    SparseActionHandle2 h280, h284, h288;
    SparseActionHandle3 h28C;
};

extern "C" SparseActionOwner* fn_80263B08(SparseActionOwner*, short);

#endif
