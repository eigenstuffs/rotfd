#ifndef GAME_ENGINE_RANGE_OPERATIONS_H
#define GAME_ENGINE_RANGE_OPERATIONS_H

typedef struct RangeOpsRange { short first, last, count; } RangeOpsRange;
typedef struct RangeOpsOwner {
    char unknown00[8];
    RangeOpsRange range;
    char unknown0E[0x22];
    char *items;
} RangeOpsOwner;
typedef struct RangeOpsRecord { int value, state; RangeOpsRange first, second; } RangeOpsRecord;
typedef struct RangeOpsBlob64 { char bytes[64]; } RangeOpsBlob64;
typedef struct RangeOpsHandle { signed int generation:8; signed int index:24; } RangeOpsHandle;
typedef struct RangeOpsNode {
    int unknown00;
    RangeOpsHandle owner;
    int unknown08;
    RangeOpsHandle parent;
    char unknown10[0xA8];
    RangeOpsHandle related;
    char unknownBC[0x64];
    unsigned int flags;
} RangeOpsNode;
typedef struct RangeOpsEntry {
    RangeOpsNode *object;
    int unknown04, unknown08;
    signed char generation;
    char unknown0D[3];
} RangeOpsEntry;
typedef struct RangeOpsManager { char unknown00[8]; RangeOpsEntry *entries; } RangeOpsManager;
typedef struct RangeOpsContext { char unknown00[0x118]; RangeOpsManager *manager; } RangeOpsContext;
typedef struct RangeOpsHandleArray { int count, capacity; RangeOpsHandle *items; } RangeOpsHandleArray;

extern RangeOpsContext lbl_801E9D24;
RangeOpsRange fn_8020E814(RangeOpsOwner *, const RangeOpsRange *, const RangeOpsRange *);
void fn_8020E938(RangeOpsOwner *, RangeOpsRecord *, int);
void fn_8023E910(RangeOpsBlob64 *, const RangeOpsBlob64 *);
void fn_8023D8D8(RangeOpsNode *);
RangeOpsHandle *fn_8023A5DC(RangeOpsHandleArray *, const RangeOpsHandle *);

#endif
