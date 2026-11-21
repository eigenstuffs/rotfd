#include "Game/registry_abi_tables.h"
extern void fn_801F68A4(struct RegistryBase *);
extern int fn_801F50B0(struct GameRegistry *);
extern struct Registry *fn_801F5944(struct Registry *, short);
RegistryOperationsTable lbl_802EAA80 = { 0, 0, fn_801F68A4, fn_801F50B0, fn_801F5944 };
typedef char CheckTableSize[sizeof(RegistryOperationsTable) == 20 ? 1 : -1];
