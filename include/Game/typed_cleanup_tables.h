#ifndef GAME_TYPED_CLEANUP_TABLES_H
#define GAME_TYPED_CLEANUP_TABLES_H
struct Object;
struct EngineArrayOwnerHandles;
struct SnapshotOwner;
struct SparseDestroySelf;
typedef struct ObjectCleanupTable {
    const void *rtti;
    int offset_to_top;
    struct Object *(*cleanup)(struct Object *, short);
} ObjectCleanupTable;
typedef struct HandleArrayCleanupTable {
    const void *rtti;
    int offset_to_top;
    struct EngineArrayOwnerHandles *(*cleanup)(struct EngineArrayOwnerHandles *, short);
} HandleArrayCleanupTable;
typedef struct SnapshotCleanupTable {
    const void *rtti;
    int offset_to_top;
    struct SnapshotOwner *(*cleanup)(struct SnapshotOwner *, int);
} SnapshotCleanupTable;
typedef struct SparsePoolCleanupTable {
    const void *rtti;
    int offset_to_top;
    struct SparseDestroySelf *(*cleanup)(struct SparseDestroySelf *, int);
} SparsePoolCleanupTable;
#ifdef __cplusplus
extern "C" {
#endif
extern ObjectCleanupTable lbl_802EA170;
extern HandleArrayCleanupTable lbl_802EC020;
extern SnapshotCleanupTable lbl_802ED0B0;
extern SparsePoolCleanupTable lbl_802ED168;
#ifdef __cplusplus
}
#endif
#endif
