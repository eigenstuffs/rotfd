#ifndef GAME_ENGINE_ARRAY_OPERATIONS_MORE_H
#define GAME_ENGINE_ARRAY_OPERATIONS_MORE_H

typedef struct ArrayOpsBlob128 { char bytes[128]; } ArrayOpsBlob128;
typedef struct ArrayOpsItem144 {
    ArrayOpsBlob128 blob;
    int value80, value84, value88;
    unsigned short value8C;
} ArrayOpsItem144;
typedef struct ArrayOpsArray144 { int count, capacity; ArrayOpsItem144 *items; } ArrayOpsArray144;
typedef struct ArrayOpsPointerArray { int count, capacity; ArrayOpsItem144 **items; } ArrayOpsPointerArray;
typedef struct ArrayOpsPairOwner {
    char unknown00[0x38];
    ArrayOpsPointerArray pointers;
    char unknown44[0x34];
    ArrayOpsArray144 records;
} ArrayOpsPairOwner;
typedef struct ArrayOpsItem168 { char bytes[168]; } ArrayOpsItem168;
typedef struct ArrayOpsArray168 { int count, capacity; ArrayOpsItem168 *items; } ArrayOpsArray168;
typedef struct ArrayOpsItem8 { short a, b, c, d; } ArrayOpsItem8;
typedef struct ArrayOpsItem16 { short a, b, c, d, e, f, g, h; } ArrayOpsItem16;
typedef struct ArrayOpsArray8 { int count, capacity; ArrayOpsItem8 *items; } ArrayOpsArray8;
typedef struct ArrayOpsArray16 { int count, capacity; ArrayOpsItem16 *items; } ArrayOpsArray16;
typedef struct ArrayOpsArray2 { int count, capacity; short *items; } ArrayOpsArray2;
typedef struct ArrayOpsTripleOwner {
    ArrayOpsArray8 first;
    ArrayOpsArray16 second;
    ArrayOpsArray2 third;
} ArrayOpsTripleOwner;

extern unsigned char lbl_8028F698[];
void *fn_8028FAF4(void *, void *, int, int);
void *fn_8028FF24(void *, int);
void fn_8028FD50(void *, void *, int);
void __ct__16BitDefaultRecordFv(ArrayOpsItem168 *);
int fn_8021C558(ArrayOpsPairOwner *, const ArrayOpsItem144 *);
void fn_80227380(ArrayOpsArray168 *, int, signed char);
ArrayOpsTripleOwner *fn_802358E8(ArrayOpsTripleOwner *);

#endif
