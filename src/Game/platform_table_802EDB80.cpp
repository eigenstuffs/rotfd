#include "Game/platform_native_interface_tables.h"
extern "C" {
int fn_80278EC4(CardThreadOwnerView *);
void fn_80278E50(MemoryCardInitView *, const char *);
void fn_80276A54(void);
void fn_80278E48(void *, unsigned int);
void fn_80278E1C(SmallOwnerName *, const char *);
int fn_80278BE4(MemoryCardOwnerView *, const char *, void *, int);
int fn_80278788(CardFileReadView *, const char *, void *, int);
int fn_8027857C(MemoryCardOwnerView *, const char *);
void fn_800E85D8(void *, unsigned int);
void fn_800E85C8(View_800E85C8 *, unsigned int, unsigned int);
void fn_80276A6C(MemoryCardOwnerView *);
void fn_80276B48(MemoryCardOwnerView *);
void fn_80276BF0(CardOwnerControlsView *);
void fn_80278454(MemoryCardOwnerView *);
int fn_80278338(MemoryCardOwnerView *);
int fn_802781E4(MemoryCardOwnerView *);
int fn_802781AC(const AllocationOwner_802781AC *, unsigned int *);
int fn_80277EC8(MemoryCardOwnerView *, const char *);
unsigned int fn_80276A58(const void *);
int fn_80277CB4(MemoryCardOwnerView *);
int fn_80277B8C(MemoryCardOwnerView *);
signed char fn_80276A60(const void *);
unsigned long fn_80278138(MemoryCardOwnerView *, const char *);
signed char fn_802780BC(MemoryCardOwnerView *, int);
MemoryCardOperationsTable lbl_802EDB80 = { 0, 0, fn_80278EC4, fn_80278E50, fn_80276A54, fn_80278E48, fn_80278E1C, fn_80278BE4, fn_80278788, fn_8027857C, fn_800E85D8, fn_800E85C8, fn_80276A6C, fn_80276B48, fn_80276BF0, fn_80278454, fn_80278338, fn_802781E4, fn_802781AC, fn_80277EC8, fn_80276A58, fn_80277CB4, fn_80277B8C, fn_80276A60, fn_80278138, fn_802780BC };
}
typedef char CheckTableSize[sizeof(MemoryCardOperationsTable) == 104 ? 1 : -1];
