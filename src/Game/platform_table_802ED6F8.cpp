#include "Game/platform_native_interface_tables.h"
extern "C" {
signed char fn_80276754(StatusInitView *);
void fn_80276750(void);
void fn_80276590(AcquireView *);
void fn_80275B54(void);
void fn_80275B48(void);
void fn_8027658C(void);
void fn_802764B0(PollView *);
bool fn_80275ED4(const SlotFlagOwner_80275ED4 *, unsigned char);
void fn_80275B4C(void);
void fn_80275B50(void);
void fn_802763D0(PollView *);
void fn_80275F7C(PlatformMotorOwner *, int, signed char);
void fn_80275F24(PlatformMotorOwner *, int, unsigned char, unsigned char);
unsigned int fn_80275EA8(const void *, int);
StorageView * fn_802767D0(StorageView *, int);
void fn_8027639C(void *, short);
ControllerOperationsTable lbl_802ED6F8 = { 0, 0, fn_80276754, fn_80276750, fn_80276590, fn_80275B54, fn_80275B48, fn_8027658C, fn_802764B0, fn_80275ED4, fn_80275B4C, fn_80275B50, fn_802763D0, fn_80275F7C, fn_80275F24, fn_80275EA8, fn_802767D0, fn_8027639C };
}
typedef char CheckTableSize[sizeof(ControllerOperationsTable) == 72 ? 1 : -1];
