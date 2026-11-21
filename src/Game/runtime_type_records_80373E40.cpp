#include "Game/native_runtime_type_records.h"

extern "C" {
extern const char lbl_80299AE4[]; // BaseObject_Z
extern const char lbl_80299AF4[]; // ABC_Agent
extern const char lbl_80378238[]; // Agent_Z
extern const char lbl_80299B00[]; // AnimatedMsgAgent_Z
extern const char lbl_80299B14[]; // AnimatedAgent_Z
extern const char lbl_80299B24[]; // MovingAgent_Z
extern const char lbl_80299B34[]; // Throwable_Z
extern const char lbl_80299B40[]; // Breakable_Z
extern const char lbl_80299B4C[]; // GameBreakable_Z
extern const char lbl_80299AD4[]; // BRK_SandCastle

NativeRuntimeTypeInfo lbl_80373E40 = { lbl_80299AE4, 0 };
NativeRuntimeTypeInfo lbl_80373E48 = { lbl_80299AF4, lbl_802AFC68.entries };
NativeRuntimeTypeInfo lbl_80373E50 = { lbl_80378238, lbl_802AFC74.entries };
NativeRuntimeTypeInfo lbl_80373E58 = { lbl_80299B00, lbl_802AFC88.entries };
NativeRuntimeTypeInfo lbl_80373E60 = { lbl_80299B14, lbl_802AFCA4.entries };
NativeRuntimeTypeInfo lbl_80373E68 = { lbl_80299B24, lbl_802AFCC8.entries };
NativeRuntimeTypeInfo lbl_80373E70 = { lbl_80299B34, lbl_802AFCF4.entries };
NativeRuntimeTypeInfo lbl_80373E78 = { lbl_80299B40, lbl_802AFD28.entries };
NativeRuntimeTypeInfo lbl_80373E80 = { lbl_80299B4C, lbl_802AFD64.entries };
NativeRuntimeTypeInfo lbl_80373E88 = { lbl_80299AD4, lbl_802AFDA8.entries };
}
