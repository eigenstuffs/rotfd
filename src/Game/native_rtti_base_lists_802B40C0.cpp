#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802B40C0 = {
    {
        { &lbl_80374280, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B40CC = {
    {
        { &lbl_80374280, 0 }, // BaseObject_Z
        { &lbl_80374288, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for VolumeAgent_Z.
NativeRuntimeBaseList<3> lbl_802B40E0 = {
    {
        { &lbl_80374280, 0 }, // BaseObject_Z
        { &lbl_80374288, 0 }, // ABC_Agent
        { &lbl_80374290, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for Volume_ScriptAndDebug.
NativeRuntimeBaseList<4> lbl_802B40FC = {
    {
        { &lbl_80374280, 0 }, // BaseObject_Z
        { &lbl_80374288, 0 }, // ABC_Agent
        { &lbl_80374290, 0 }, // Agent_Z
        { &lbl_80374298, 0 }, // VolumeAgent_Z
    }, 0
};

// Base hierarchy for Volume_CameraPlayerStop.
NativeRuntimeBaseList<5> lbl_802B4120 = {
    {
        { &lbl_80374280, 0 }, // BaseObject_Z
        { &lbl_80374288, 0 }, // ABC_Agent
        { &lbl_80374290, 0 }, // Agent_Z
        { &lbl_80374298, 0 }, // VolumeAgent_Z
        { &lbl_803742A0, 0 }, // Volume_ScriptAndDebug
    }, 0
};

}

// Native volume method tables following the base-list group at 0x802B40C0.
extern "C" {
void __dt__14Agent_8004FAE8Fv();
void __dt__15Object_8004F318Fv();
void __dt__15Object_80050590Fv();
void fn_8002392C();
void fn_80023934();
void fn_8002393C();
void fn_80023944();
void fn_80028D58();
void fn_80028D60();
void fn_80028D68();
void fn_80028D6C();
void fn_8002DAD8();
void fn_8002DADC();
void fn_8002DAE4();
void fn_80035224();
void fn_80035228();
void fn_800443B4();
void fn_80044428();
void fn_80044448();
void fn_80044494();
void fn_80044578();
void fn_800446B8();
void fn_800447A8();
void fn_80044904();
void fn_8004F43C();
void fn_8004F498();
void fn_8004F7E0();
void fn_8004FCFC();
void fn_8004FD30();
void fn_80050134();
void fn_800506F0();
void fn_8005074C();
void fn_800508C8();
void fn_800512A8();
void fn_80051548();
void fn_80051550();
void fn_80051558();
void fn_800515BC();
void fn_80051658();
void fn_80051660();
void fn_80051668();
void fn_800516BC();
void fn_8005173C();
void fn_80051744();
void fn_8005174C();
void fn_800517B0();
void fn_80256028();
void fn_80256370();
void fn_8025E11C();
void fn_8025E2FC();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void slot1C__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802B414C[36] __attribute__((aligned(4))) = {
    &lbl_803742A8,
    0,
    (const void*)__dt__15Object_80050590Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800506F0,
    (const void*)slot1C__12BaseObject_ZFv,
    (const void*)fn_80051548,
    (const void*)fn_80051550,
    (const void*)fn_80051558,
    (const void*)fn_800515BC,
    (const void*)fn_80044448,
    (const void*)fn_80044494,
    (const void*)fn_80044428,
    (const void*)fn_8025E2FC,
    (const void*)fn_8005074C,
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
    (const void*)fn_800508C8,
    (const void*)fn_800512A8,
};

extern "C" NativeRuntimeBaseList<4> lbl_802B41DC = {
    {
        {&lbl_80374280, 0},
        {&lbl_80374288, 0},
        {&lbl_80374290, 0},
        {&lbl_80374298, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802B4200[31] __attribute__((aligned(4))) = {
    &lbl_803742B0,
    0,
    (const void*)__dt__14Agent_8004FAE8Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8004FCFC,
    (const void*)slot1C__12BaseObject_ZFv,
    (const void*)fn_80051658,
    (const void*)fn_80051660,
    (const void*)fn_80051668,
    (const void*)fn_800516BC,
    (const void*)fn_80035224,
    (const void*)fn_80035228,
    (const void*)fn_80256370,
    (const void*)fn_8025E2FC,
    (const void*)fn_8004FD30,
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
    (const void*)fn_80050134,
};

extern "C" NativeRuntimeBaseList<5> lbl_802B427C = {
    {
        {&lbl_80374280, 0},
        {&lbl_80374288, 0},
        {&lbl_80374290, 0},
        {&lbl_80374298, 0},
        {&lbl_803742A0, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802B42A8[36] __attribute__((aligned(4))) = {
    &lbl_803742B8,
    0,
    (const void*)__dt__15Object_8004F318Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8004F43C,
    (const void*)slot1C__12BaseObject_ZFv,
    (const void*)fn_8005173C,
    (const void*)fn_80051744,
    (const void*)fn_8005174C,
    (const void*)fn_800517B0,
    (const void*)fn_80044448,
    (const void*)fn_80044494,
    (const void*)fn_80044428,
    (const void*)fn_8025E2FC,
    (const void*)fn_800443B4,
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
    (const void*)fn_8004F498,
    (const void*)fn_8004F7E0,
};
