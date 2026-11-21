#include "Game/path_owner_operations_table.h"
extern "C" {
void * fn_801B58B0(void *);
void * fn_801B5890(void *);
void fn_801B4BF0(void *);
SparseHandleDestroyOwner * fn_801B58D0(SparseHandleDestroyOwner *, int);
void fn_801B57F8(Table_801B57F8 *);
void fn_801B480C(Owner *, const char *, const Name &);
void fn_801B4230(Owner_801B4230 *);
void fn_801B4BB8(void *, const char *);
void fn_801B3BE4(PathLookupResult_801B3BE4 *, PathLookupOwner_801B3BE4 *, const char *);
PathOwnerOperationsTable lbl_802E9E70 = { 0, 0, fn_801B58B0, fn_801B5890, fn_801B4BF0, fn_801B58D0, fn_801B57F8, fn_801B480C, fn_801B4230, fn_801B4BB8, fn_801B3BE4 };
}
typedef char PathOwnerTableSize[sizeof(PathOwnerOperationsTable) == 44 ? 1 : -1];
