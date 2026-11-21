#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B79C0 = {
    {
        { &lbl_80374808, 0 }, // BaseObject_Z
        { &lbl_80374810, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for VolumeAgent_Z.
NativeRuntimeBaseList<3> lbl_802B79D4 = {
    {
        { &lbl_80374808, 0 }, // BaseObject_Z
        { &lbl_80374810, 0 }, // ABC_Agent
        { &lbl_80374818, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for Puzzle.
NativeRuntimeBaseList<4> lbl_802B79F0 = {
    {
        { &lbl_80374808, 0 }, // BaseObject_Z
        { &lbl_80374810, 0 }, // ABC_Agent
        { &lbl_80374818, 0 }, // Agent_Z
        { &lbl_80374820, 0 }, // VolumeAgent_Z
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_80071358Fv();
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
void fn_80071508();
void fn_80071640();
void fn_80071660();
void fn_80071A64();
void fn_800726EC();
void fn_80072754();
void fn_80072BA4();
void fn_80072BAC();
void fn_80072BB4();
void fn_80072C08();
void fn_80256028();
void fn_8025E11C();
void fn_8025E2FC();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void slot1C__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const __vt__15Object_80071358[33] __attribute__((aligned(4))) = {
    &lbl_80374828,
    0,
    (const void*)__dt__15Object_80071358Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_80071508,
    (const void*)slot1C__12BaseObject_ZFv,
    (const void*)fn_80072BA4,
    (const void*)fn_80072BAC,
    (const void*)fn_80072BB4,
    (const void*)fn_80072C08,
    (const void*)fn_80035224,
    (const void*)fn_80035228,
    (const void*)fn_80071640,
    (const void*)fn_8025E2FC,
    (const void*)fn_80071660,
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
    (const void*)fn_80072754,
    (const void*)fn_800726EC,
    (const void*)fn_80071A64,
};

