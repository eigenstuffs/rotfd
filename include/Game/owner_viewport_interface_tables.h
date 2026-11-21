#ifndef GAME_OWNER_VIEWPORT_INTERFACE_TABLES_H
#define GAME_OWNER_VIEWPORT_INTERFACE_TABLES_H
struct RecordArraysDestroyOwner;
struct GroupArrayStreamOwner;
struct GroupArrayInputStream;
struct HandleRebindOwner_801D0518;
struct ActivateOwner;
struct EnginePropertyOwner;
struct SphereCollectOwner;
struct SphereCollectObject;
struct SphereCollectSphere;
struct SphereCollectResult;
struct Viewports_801E1378;
struct Object;
typedef struct RecordArrayOwnerOperationsTable {
    const void *rtti;
    int offset_to_top;
    struct RecordArraysDestroyOwner * (*slot08)(struct RecordArraysDestroyOwner *, int);
    void (*slot0C)(struct GroupArrayStreamOwner *, struct GroupArrayInputStream *);
    void (*slot10)(void *);
    void (*slot14)(struct HandleRebindOwner_801D0518 *);
    void (*slot18)(void *);
    signed char (*slot1C)(struct ActivateOwner *);
    void (*slot20)(void *);
    void (*slot24)(void *);
    void (*slot28)(struct EnginePropertyOwner *, float);
    float (*slot2C)(const void *);
    void (*slot30)(void *);
    void (*slot34)(void *);
    int (*slot38)(void *);
    int (*slot3C)(void *);
    int (*slot40)(void *);
    int (*slot44)(void *);
    int (*slot48)(void *);
    int (*slot4C)(void *);
    int (*slot50)(struct SphereCollectOwner *, struct SphereCollectObject *, const struct SphereCollectSphere *, const void *, struct SphereCollectResult *, int, unsigned long long);
    int (*slot54)(void *);
    void (*slot58)(void *);
    void (*slot5C)(void *);
} RecordArrayOwnerOperationsTable;
typedef struct ViewportOperationsTable {
    const void *rtti;
    int offset_to_top;
    void * (*slot08)(void *, short);
    int (*slot0C)(void *, int, int);
    void (*slot10)(void);
    void (*slot14)(void);
    void (*slot18)(void);
    void (*slot1C)(struct Viewports_801E1378 *);
    void (*slot20)(void);
    void (*slot24)(void);
    void (*slot28)(void);
    void (*slot2C)(void);
    void (*slot30)(void);
    void (*slot34)(void);
    void (*slot38)(void);
    void (*slot3C)(void);
    void (*slot40)(void);
    int (*slot44)(void);
    float (*slot48)(void);
    void (*slot4C)(void);
    void (*slot50)(void);
    void (*slot54)(void);
    void (*slot58)(void);
    void (*slot5C)(void);
    void (*slot60)(void);
    void (*slot64)(void);
    void (*slot68)(void);
    void (*slot6C)(void);
    void (*slot70)(void);
    void (*slot74)(void);
    void (*slot78)(void);
    void (*slot7C)(void);
    void (*slot80)(void);
    void (*slot84)(void);
    void (*slot88)(void);
    void (*slot8C)(void);
    void (*slot90)(void);
    void (*slot94)(void);
    void (*slot98)(void);
    void (*slot9C)(void);
    void (*slotA0)(void);
    void (*slotA4)(void);
    void (*slotA8)(void);
    void (*slotAC)(struct Object *, int);
} ViewportOperationsTable;
typedef struct ViewportAuxiliaryOperationsTable {
    const void *rtti;
    int offset_to_top;
    void (*slot08)(void);
    int (*slot0C)(void);
} ViewportAuxiliaryOperationsTable;
/* The original GLOBAL192-byte allocation contains these two records. */
typedef struct ViewportInterfaceTables {
    ViewportOperationsTable primary;
    ViewportAuxiliaryOperationsTable auxiliary;
} ViewportInterfaceTables;
#ifdef __cplusplus
extern "C" {
#endif
extern RecordArrayOwnerOperationsTable lbl_802EA4F8;
extern ViewportInterfaceTables lbl_802EA718;
#ifdef __cplusplus
}
#endif
#endif
