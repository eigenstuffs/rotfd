#ifndef GAME_RUNTIME_TYPE_RECORDS_H
#define GAME_RUNTIME_TYPE_RECORDS_H

// CodeWarrior native RTTI: base offsets are measured from the complete object.
struct NativeRuntimeTypeInfo;
struct NativeRuntimeBaseClass {
    const NativeRuntimeTypeInfo* type;
    long offset;
};

// The ABI terminates the entries with a single null type pointer.
template <int Count> struct NativeRuntimeBaseList {
    NativeRuntimeBaseClass entries[Count];
    const NativeRuntimeTypeInfo* end;
};

struct NativeRuntimeTypeInfo {
    const char* name;
    const NativeRuntimeBaseClass* baseClasses;
};

extern "C" {
extern NativeRuntimeTypeInfo lbl_80373E40; // BaseObject_Z
extern NativeRuntimeTypeInfo lbl_80373E48; // ABC_Agent
extern NativeRuntimeTypeInfo lbl_80373E50; // Agent_Z
extern NativeRuntimeTypeInfo lbl_80373E58; // AnimatedMsgAgent_Z
extern NativeRuntimeTypeInfo lbl_80373E60; // AnimatedAgent_Z
extern NativeRuntimeTypeInfo lbl_80373E68; // MovingAgent_Z
extern NativeRuntimeTypeInfo lbl_80373E70; // Throwable_Z
extern NativeRuntimeTypeInfo lbl_80373E78; // Breakable_Z
extern NativeRuntimeTypeInfo lbl_80373E80; // GameBreakable_Z
extern NativeRuntimeTypeInfo lbl_80373E88; // BRK_SandCastle
extern NativeRuntimeBaseList<1> lbl_802AFC68;
extern NativeRuntimeBaseList<2> lbl_802AFC74;
extern NativeRuntimeBaseList<3> lbl_802AFC88;
extern NativeRuntimeBaseList<4> lbl_802AFCA4;
extern NativeRuntimeBaseList<5> lbl_802AFCC8;
extern NativeRuntimeBaseList<6> lbl_802AFCF4;
extern NativeRuntimeBaseList<7> lbl_802AFD28;
extern NativeRuntimeBaseList<8> lbl_802AFD64;
extern NativeRuntimeBaseList<9> lbl_802AFDA8;
}
#endif
