#ifndef GAME_REGISTRY_ABI_TABLES_H
#define GAME_REGISTRY_ABI_TABLES_H
struct Owner;
struct RegistryBase;
struct GameRegistry;
struct Registry;
typedef struct ActionRecordOperationTable {
    const void *rtti;
    int offset_to_top;
    void (*reset)(struct Owner *);
} ActionRecordOperationTable;
typedef struct RegistryOperationsTable {
    const void *rtti;
    int offset_to_top;
    void (*reset)(struct RegistryBase *);
    int (*shutdown)(struct GameRegistry *);
    struct Registry *(*cleanup)(struct Registry *, short);
} RegistryOperationsTable;
typedef struct RegistryBaseOperationsTable {
    const void *rtti;
    int offset_to_top;
    void (*reset)(struct RegistryBase *);
    char (*release)(struct RegistryBase *);
} RegistryBaseOperationsTable;
#ifdef __cplusplus
extern "C" {
#endif
extern ActionRecordOperationTable lbl_802E9DD8;
extern RegistryOperationsTable lbl_802EAA80;
extern RegistryBaseOperationsTable lbl_802EAA98;
#ifdef __cplusplus
}
#endif
#endif
