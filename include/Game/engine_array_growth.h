#ifndef GAME_ENGINE_ARRAY_GROWTH_H
#define GAME_ENGINE_ARRAY_GROWTH_H
#include "Game/array_interface_tables.h"

/* Partial views of the arrays and range returned by these engine routines. */
typedef struct EngineGrowthArray4 { int count, capacity; void *items; } EngineGrowthArray4;
typedef struct EngineGrowthItem168 { unsigned char bytes[168]; } EngineGrowthItem168;
typedef struct EngineGrowthArray168 { int count, capacity; EngineGrowthItem168 *items; } EngineGrowthArray168;
typedef struct EngineGrowthRange { short first, last, count; } EngineGrowthRange;
typedef struct EngineGrowthItem24 { char bytes[24]; } EngineGrowthItem24;
typedef struct EngineGrowthItem140 { char bytes[140]; } EngineGrowthItem140;
typedef struct EngineGrowthArray24 { int count, capacity; EngineGrowthItem24 *items; } EngineGrowthArray24;
typedef struct EngineGrowthArray140 { int count, capacity; EngineGrowthItem140 *items; } EngineGrowthArray140;
typedef struct EngineGrowthOwner {
    void *table;
    int argument;
    EngineGrowthRange range;
    short unknown0E;
    float value10, value14;
    short value18;
    char active;
    char unknown1B;
    EngineGrowthArray24 first;
    EngineGrowthArray140 second;
} EngineGrowthOwner;

extern unsigned char lbl_8028F698[];

extern const float lbl_8037AA40, lbl_8037AA80;
void *fn_8028FAF4(void *, void *, int, int);
void *fn_8028FF24(void *, int);
void fn_8028FD50(void *, void *, int);
void __ct__19BitNativeCopyRecordFRC19BitNativeCopyRecord(EngineGrowthItem168 *, const EngineGrowthItem168 *);
EngineGrowthRange fn_8020C8CC(EngineGrowthOwner *, int, int);
void fn_8023F668(EngineGrowthArray4 *, int);
int fn_80225C58(EngineGrowthArray168 *, const EngineGrowthItem168 *);
EngineGrowthOwner *fn_8020C744(EngineGrowthOwner *, int);

#endif
