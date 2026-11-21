#include "Game/platform_native_interface_tables.h"
extern "C" {
int fn_800E8FEC(void);
void fn_800E85D8(void *, unsigned int);
void fn_800E85C8(View_800E85C8 *, unsigned int, unsigned int);
void fn_80279368(void);
void fn_8027936C(void);
void fn_80279370(void);
int fn_800E8C9C(void);
int fn_80279374(void);
MemoryCardBaseOperationsTable lbl_802EDC48 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, fn_800E8FEC, fn_800E85D8, fn_800E85C8, fn_80279368, fn_8027936C, fn_80279370, 0, 0, 0, 0, 0, fn_800E8C9C, 0, 0, fn_80279374 };
}
typedef char CheckTableSize[sizeof(MemoryCardBaseOperationsTable) == 96 ? 1 : -1];
