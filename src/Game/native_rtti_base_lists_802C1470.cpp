#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802C1470 = {
    {
        { &lbl_80375888, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802C147C = {
    {
        { &lbl_80375888, 0 }, // BaseObject_Z
        { &lbl_80375890, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for VolumeAgent_Z.
NativeRuntimeBaseList<3> lbl_802C1490 = {
    {
        { &lbl_80375888, 0 }, // BaseObject_Z
        { &lbl_80375890, 0 }, // ABC_Agent
        { &lbl_80375898, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for Volume_ScriptAndDebug.
NativeRuntimeBaseList<4> lbl_802C14AC = {
    {
        { &lbl_80375888, 0 }, // BaseObject_Z
        { &lbl_80375890, 0 }, // ABC_Agent
        { &lbl_80375898, 0 }, // Agent_Z
        { &lbl_803758A0, 0 }, // VolumeAgent_Z
    }, 0
};

// Base hierarchy for Volume_Damage.
NativeRuntimeBaseList<5> lbl_802C14D0 = {
    {
        { &lbl_80375888, 0 }, // BaseObject_Z
        { &lbl_80375890, 0 }, // ABC_Agent
        { &lbl_80375898, 0 }, // Agent_Z
        { &lbl_803758A0, 0 }, // VolumeAgent_Z
        { &lbl_803758A8, 0 }, // Volume_ScriptAndDebug
    }, 0
};

}
// Native method table for the volume agent at 0x802C14FC.
extern "C" {
void __dt__14Agent_800C92D4Fv();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void slot1C__12BaseObject_ZFv();
void fn_800C939C();
void fn_800C9DB8();
void fn_800C9DC0();
void fn_800C9DC8();
void fn_800C9E2C();
void fn_80044448();
void fn_80044494();
void fn_800C93E4();
void fn_8025E2FC();
void fn_800C9404();
void fn_8002DAD8();
void fn_8002392C();
void fn_80023934();
void fn_8002393C();
void fn_80028D58();
void fn_80028D60();
void fn_80028D68();
void fn_80028D6C();
void fn_8002DADC();
void fn_8002DAE4();
void fn_80256028();
void fn_80023944();
void fn_8025E11C();
void fn_80044578();
void fn_80044904();
void fn_800446B8();
void fn_800447A8();
void fn_800C94A8();
void fn_800C9B18();
void fn_800C96E0();
}

extern "C" __declspec(section ".data") const void* const lbl_802C14FC[37] __attribute__((aligned(4))) = {
    &lbl_803758B0, 0,
    (const void*)__dt__14Agent_800C92D4Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800C939C,
    (const void*)slot1C__12BaseObject_ZFv,
    (const void*)fn_800C9DB8,
    (const void*)fn_800C9DC0,
    (const void*)fn_800C9DC8,
    (const void*)fn_800C9E2C,
    (const void*)fn_80044448,
    (const void*)fn_80044494,
    (const void*)fn_800C93E4,
    (const void*)fn_8025E2FC,
    (const void*)fn_800C9404,
    (const void*)fn_8002DAD8,
    (const void*)fn_8002392C,
    (const void*)fn_80023934,
    (const void*)fn_8002393C,
    (const void*)fn_80028D58,
    (const void*)fn_80028D60,
    (const void*)fn_80028D68,
    (const void*)fn_80028D6C,
    (const void*)fn_8002DADC,
    (const void*)fn_8002DAE4,
    (const void*)fn_80256028,
    (const void*)fn_80023944,
    (const void*)fn_8025E11C,
    (const void*)fn_80044578,
    (const void*)fn_80044904,
    (const void*)fn_800446B8,
    (const void*)fn_800447A8,
    (const void*)fn_800C94A8,
    (const void*)fn_800C9B18,
    (const void*)fn_800C96E0,
};
typedef char DamageVolumeTableSize[(sizeof(lbl_802C14FC) == 0x94) ? 1 : -1];
