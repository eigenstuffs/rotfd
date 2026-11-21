/* MatrixCache_Z.cpp: allocation and cleanup of 10,000-record chunks.
 * The two chunk pointers and bitset precede the virtual-pointer declaration.
 * Each record occupies 64 bytes; its default constructor leaves them untouched.
 */
#include "Game/bitset_internal.h"

extern "C" {
extern const char lbl_802ACCE0[], lbl_802ACCF0[];
void* fn_8028FAF4(void*, void*, u32, u32);
void* fn_8028FF24(void*, u32);
void* memset(void*, int, u32);
void* fn_801EFA1C(void*, u32, const char*, const char*, int, u32);
}

inline void* operator new(u32, void* memory) { return memory; }

inline void resizeWordStorage(WordArray* words, int count) {
    if (count) {
        if (words->data)
            words->data = (u32*)fn_8028FAF4(lbl_8028F698, words->data,
                                          words->capacity * 4, count * 4);
        else
            words->data = (u32*)fn_8028FF24(lbl_8028F698, count * 4);
    } else if (words->data) {
        fn_8028FD50(lbl_8028F698, words->data, words->capacity * 4);
        words->data = 0;
    }
}

inline void resizeWords(WordArray* words, int count) {
    if (count > words->count) {
        resizeWordStorage(words, count);
        words->capacity = count;
        for (int i = words->count; i < count; ++i)
            new (&words->data[i]) u32;
        words->count = count;
    } else if (count < words->count) {
        for (int i = words->count - 1; i >= count; --i)
            words->data[i].~u32();
        resizeWordStorage(words, count);
        words->capacity = count;
        words->count = count;
    }
}

inline void resizeBits(BitSet_80207EE8* bits, int count) {
    bits->bits = count;
    if (count && ((count >> 5) + 1) > bits->count)
        resizeWords(bits, (bits->bits >> 5) + 1);
}

inline void* operator new[](u32 size, void* heap, const char* label,
                            const char* file, int line) {
    return fn_801EFA1C(heap, size, label, file, line, 4);
}

struct CacheRecord_801CA1E4 {
    char bytes[64];
    CacheRecord_801CA1E4();
};

struct MatrixCache_Z {
    void* chunks[2];
    BitSet_80207EE8 occupied;
    unsigned char busy, chunkCount;
    char unknown1A[2];
    virtual ~MatrixCache_Z();
    MatrixCache_Z();
    static void operator delete(void* memory) {
        fn_801EF610(lbl_801EF5C8, memory);
    }
};

MatrixCache_Z::~MatrixCache_Z() {
    for (int i = 0; i < chunkCount; ++i) {
        if (chunks[i])
            fn_801EF610(lbl_801EF5C8, (char*)chunks[i] - 0x10);
    }
}

MatrixCache_Z::MatrixCache_Z() {
    busy = 0;
    resizeBits(&occupied, 10000);
    if (occupied.count)
        memset(occupied.data, 0, occupied.count * 4);
    chunkCount = 1;
    for (int i = 0; i < chunkCount; ++i)
        chunks[i] = new (lbl_801EF5C8, lbl_802ACCE0, lbl_802ACCF0, 17)
            CacheRecord_801CA1E4[10000];
}

CacheRecord_801CA1E4::CacheRecord_801CA1E4() {}

typedef char CacheObjectSize[sizeof(MatrixCache_Z) == 0x20 ? 1 : -1];
typedef char CacheRecordSize[sizeof(CacheRecord_801CA1E4) == 0x40 ? 1 : -1];
