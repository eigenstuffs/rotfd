#include "Game/registry_abi_tables.h"
extern void fn_801F68A4(struct RegistryBase *);
extern char fn_801F5E14(struct RegistryBase *);
RegistryBaseOperationsTable lbl_802EAA98 = { 0, 0, fn_801F68A4, fn_801F5E14 };
typedef char CheckTableSize[sizeof(RegistryBaseOperationsTable) == 16 ? 1 : -1];
