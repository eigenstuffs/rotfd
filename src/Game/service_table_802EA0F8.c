#include "Game/service_interface_tables.h"
extern void * fn_801C99AC(struct Object_801C99AC *, short);
extern int fn_801C9AC0(void *);
extern void fn_801C9ABC(void *);
extern int fn_801C9AAC(unsigned char *);
extern void fn_801C9AA0(unsigned char *);
extern void fn_800BE898(void *);
extern void fn_800BEBF8(void *);
extern int fn_801C9A1C(void *);
extern void fn_801C9A24(void *);
extern void fn_801C9A28(void *);
PlatformServiceInterfaceTable lbl_802EA0F8 = { 0, 0, fn_801C99AC, fn_801C9AC0, fn_801C9ABC, fn_801C9AAC, fn_801C9AA0, fn_800BE898, fn_800BEBF8, fn_801C9A1C, fn_801C9A24, fn_801C9A28 };
typedef char CheckTableSize[sizeof(PlatformServiceInterfaceTable) == 48 ? 1 : -1];
