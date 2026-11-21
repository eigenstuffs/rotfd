#ifndef GAME_ARRAY_INTERFACE_TABLES_H
#define GAME_ARRAY_INTERFACE_TABLES_H
struct OwnerLifecycleBase;
struct EngineArrayOwnerPair;
typedef struct OwnerArrayInterfaceTable {
    const void *rtti;
    int offset_to_top;
    struct OwnerLifecycleBase *(*cleanup)(struct OwnerLifecycleBase *, int);
    void (*advance)(void *, float);
} OwnerArrayInterfaceTable;
typedef struct PairArrayInterfaceTable {
    const void *rtti;
    int offset_to_top;
    struct EngineArrayOwnerPair *(*cleanup)(struct EngineArrayOwnerPair *, short);
    void (*advance)(void *, float);
} PairArrayInterfaceTable;
#ifdef __cplusplus
extern "C" {
#endif
extern OwnerArrayInterfaceTable lbl_802EAFE0;
extern PairArrayInterfaceTable lbl_802EAFF0;
#ifdef __cplusplus
}
#endif
#endif
