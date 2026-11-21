#ifndef GAME_ENGINE_RANGE_ALLOCATE_H
#define GAME_ENGINE_RANGE_ALLOCATE_H

typedef struct RangeAllocateRange { short first, last, count; } RangeAllocateRange;
typedef struct RangeAllocateRecord {
    int value, state;
    RangeAllocateRange first, second;
    float stamp;
} RangeAllocateRecord;
typedef struct RangeAllocateItem140 { char bytes[140]; } RangeAllocateItem140;
typedef struct RangeAllocateArray140 { int count, capacity; RangeAllocateItem140 *items; } RangeAllocateArray140;
typedef struct RangeAllocateOwner {
    char unknown00[8];
    RangeAllocateRange range;
    short unknown0E;
    float stamp, threshold;
    char unknown18[4];
    int count, capacity;
    RangeAllocateRecord *records;
    RangeAllocateArray140 entries;
} RangeAllocateOwner;
typedef struct RangeAllocateArray { int count, capacity; void *items; } RangeAllocateArray;
typedef struct RangeAllocateSetup {
    int size;
    RangeAllocateArray array;
    int unknown10, value14;
} RangeAllocateSetup;

#ifdef __cplusplus
struct RangeAllocateIndex {
    int value;
    RangeAllocateIndex(): value(-1) {}
    RangeAllocateIndex(int v): value(v) {}
    RangeAllocateIndex(const RangeAllocateIndex &other): value(other.value) {}
};
extern "C" {
RangeAllocateIndex fn_8020EADC(RangeAllocateOwner *, float);
#endif
extern unsigned char lbl_8028F698[];
void *fn_8028FAF4(void *, void *, int, int);
void *fn_8028FF24(void *, int);
void fn_8028FD50(void *, void *, int);
void fn_8020E8B0(RangeAllocateOwner *, short);
RangeAllocateRange fn_8020C8CC(RangeAllocateOwner *, short, short);
RangeAllocateRange fn_8020E814(RangeAllocateOwner *, const RangeAllocateRange *, const RangeAllocateRange *);
signed char fn_8020E558(RangeAllocateOwner *, RangeAllocateRecord *, short);
void fn_8020C018(RangeAllocateArray *, int, int);
RangeAllocateSetup *fn_8020BFA8(RangeAllocateSetup *);
#ifdef __cplusplus
}
#endif

#endif
