#include "Game/registry_abi_tables.h"
extern void fn_801AEFD0(struct Owner *);
ActionRecordOperationTable lbl_802E9DD8 = { 0, 0, fn_801AEFD0 };
typedef char CheckTableSize[sizeof(ActionRecordOperationTable) == 12 ? 1 : -1];
