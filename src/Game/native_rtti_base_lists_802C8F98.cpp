#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802C8F98 = {
    {
        { &lbl_80375B70, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802C8FA4 = {
    {
        { &lbl_80375B70, 0 }, // BaseObject_Z
        { &lbl_80375B78, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for VolumeAgent_Z.
NativeRuntimeBaseList<3> lbl_802C8FB8 = {
    {
        { &lbl_80375B70, 0 }, // BaseObject_Z
        { &lbl_80375B78, 0 }, // ABC_Agent
        { &lbl_80375B80, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for Volume_ScriptAndDebug.
NativeRuntimeBaseList<4> lbl_802C8FD4 = {
    {
        { &lbl_80375B70, 0 }, // BaseObject_Z
        { &lbl_80375B78, 0 }, // ABC_Agent
        { &lbl_80375B80, 0 }, // Agent_Z
        { &lbl_80375B88, 0 }, // VolumeAgent_Z
    }, 0
};

// Base hierarchy for Volume_BossDeath.
NativeRuntimeBaseList<5> lbl_802C8FF8 = {
    {
        { &lbl_80375B70, 0 }, // BaseObject_Z
        { &lbl_80375B78, 0 }, // ABC_Agent
        { &lbl_80375B80, 0 }, // Agent_Z
        { &lbl_80375B88, 0 }, // VolumeAgent_Z
        { &lbl_80375B90, 0 }, // Volume_ScriptAndDebug
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__14Agent_800E75B0Fv();
void slot48__7Agent_ZFv();
void slot4C__7Agent_ZFv();
void slot50__7Agent_ZFv();
void slot70__7Agent_ZFv();
void slot54__7Agent_ZFv();
void slot58__7Agent_ZFv();
void slot5C__7Agent_ZFv();
void slot60__7Agent_ZFv();
void fn_8002DAD8();
void slot64__7Agent_ZFv();
void slot68__7Agent_ZFv();
void fn_80044448();
void fn_80044494();
void fn_80044578();
void fn_800446B8();
void fn_800447A8();
void fn_80044904();
void fn_80044908();
void fn_800E7668();
void fn_800E76B0();
void fn_800E76F8();
void fn_800E770C();
void fn_800E7784();
void fn_800E7A74();
void fn_800E801C();
void fn_800E8024();
void fn_800E802C();
void fn_800E8090();
void fn_800E812C();
void slot6C__7Agent_ZFv();
void fn_8025E11C();
void fn_8025E2FC();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void slot1C__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802C9024[39] __attribute__((aligned(4))) = {
    &lbl_80375B98,
    0,
    (const void*)__dt__14Agent_800E75B0Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800E7668,
    (const void*)slot1C__12BaseObject_ZFv,
    (const void*)fn_800E801C,
    (const void*)fn_800E8024,
    (const void*)fn_800E802C,
    (const void*)fn_800E8090,
    (const void*)fn_80044448,
    (const void*)fn_80044494,
    (const void*)fn_800E76B0,
    (const void*)fn_8025E2FC,
    (const void*)fn_800E76F8,
    (const void*)fn_8002DAD8,
    (const void*)slot48__7Agent_ZFv,
    (const void*)slot4C__7Agent_ZFv,
    (const void*)slot50__7Agent_ZFv,
    (const void*)slot54__7Agent_ZFv,
    (const void*)slot58__7Agent_ZFv,
    (const void*)slot5C__7Agent_ZFv,
    (const void*)slot60__7Agent_ZFv,
    (const void*)slot64__7Agent_ZFv,
    (const void*)slot68__7Agent_ZFv,
    (const void*)slot6C__7Agent_ZFv,
    (const void*)slot70__7Agent_ZFv,
    (const void*)fn_8025E11C,
    (const void*)fn_80044578,
    (const void*)fn_80044904,
    (const void*)fn_800446B8,
    (const void*)fn_800447A8,
    (const void*)fn_800E812C,
    (const void*)fn_80044908,
    (const void*)fn_800E770C,
    (const void*)fn_800E7A74,
    (const void*)fn_800E7784,
};

extern "C" __declspec(section ".data") const void* const lbl_802C90C0[18] __attribute__((aligned(4))) = {
    0,
    (const void*)0x00000074,
    (const void*)0x00000008,
    0,
    (const void*)0x00000074,
    (const void*)0x00000008,
    0,
    (const void*)0x00000074,
    (const void*)0x00000008,
    0,
    (const void*)0x00000074,
    (const void*)0x00000008,
    0,
    (const void*)0x00000074,
    (const void*)0x00000008,
    0,
    (const void*)0x00000074,
    (const void*)0x00000008,
};

