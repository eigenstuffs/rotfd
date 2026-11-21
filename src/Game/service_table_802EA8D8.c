#include "Game/service_interface_tables.h"
extern struct ControllerStorage * fn_801F00B0(struct ControllerStorage *, short);
extern int fn_801F0248(struct Controller *);
extern void fn_801F0244(void *);
extern void fn_801F01AC(struct FlagController *, unsigned int);
extern void fn_801F01BC(struct FlagController *, unsigned int);
extern void fn_800C4500(void *, unsigned int);
extern void fn_800C46C4(void *, unsigned int);
extern void fn_801EFD88(struct Controller *, float);
extern void fn_801F01CC(struct OutputBuffer *);
extern void fn_801F01A8(void *);
ControllerInterfaceTable lbl_802EA8D8 = { 0, 0, fn_801F00B0, fn_801F0248, fn_801F0244, fn_801F01AC, fn_801F01BC, fn_800C4500, fn_800C46C4, fn_801EFD88, fn_801F01CC, fn_801F01A8 };
typedef char CheckTableSize[sizeof(ControllerInterfaceTable) == 48 ? 1 : -1];
