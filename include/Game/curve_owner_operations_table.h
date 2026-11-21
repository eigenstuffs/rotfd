#ifndef GAME_CURVE_OWNER_OPERATIONS_TABLE_H
#define GAME_CURVE_OWNER_OPERATIONS_TABLE_H
struct CurveOwner_BAF8;
struct Object_801DC3F4;
struct RelatedRemoveOwner;
typedef struct CurveOwnerOperationsTable {
    const void *rtti;
    int offset_to_top;
    struct CurveOwner_BAF8 * (*slot08)(struct CurveOwner_BAF8 *, short);
    void (*slot0C)(void *, void **);
    void (*slot10)(void *);
    void (*slot14)(struct Object_801DC3F4 *);
    void (*slot18)(void *);
    signed char (*slot1C)(struct RelatedRemoveOwner *);
    void (*slot20)(void *);
    void (*slot24)(void *);
    void (*slot28)(void *);
    float (*slot2C)(void *);
    void (*slot30)(void *);
    void (*slot34)(void *);
    int (*slot38)(void *);
    int (*slot3C)(void *);
    int (*slot40)(void *);
    int (*slot44)(void *);
    int (*slot48)(void *);
    int (*slot4C)(void *);
    int (*slot50)(void *);
} CurveOwnerOperationsTable;
#ifdef __cplusplus
extern "C" {
#endif
extern CurveOwnerOperationsTable lbl_802EA6C0;
#ifdef __cplusplus
}
#endif
#endif
