#include "Game/service_interface_tables.h"
extern int fn_801EAA7C(unsigned char *);
extern void fn_8020B904(void);
extern void fn_80276A44(void);
extern void fn_80276A48(void);
extern void fn_80275B48(void);
extern void fn_80276A4C(void);
extern void fn_800BE894(void);
extern int fn_800B4D14(void);
extern void fn_80275B4C(void);
extern void fn_80275B50(void);
extern void fn_80276A50(void);
extern void fn_80033118(void);
extern void fn_80031324(void);
extern int fn_800B6B68(void);
StatusStorageInterfaceTable lbl_802ED740 = { 0, 0, fn_801EAA7C, fn_8020B904, fn_80276A44, fn_80276A48, fn_80275B48, fn_80276A4C, fn_800BE894, fn_800B4D14, fn_80275B4C, fn_80275B50, fn_80276A50, fn_80033118, fn_80031324, fn_800B6B68 };
typedef char CheckTableSize[sizeof(StatusStorageInterfaceTable) == 64 ? 1 : -1];
