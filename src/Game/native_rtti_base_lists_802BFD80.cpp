#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802BFD80 = {
    {
        { &lbl_803757E0, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for StreamAgent_Z.
NativeRuntimeBaseList<2> lbl_802BFD8C = {
    {
        { &lbl_803757E0, 0 }, // BaseObject_Z
        { &lbl_803757E8, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for StreamGameAgent.
NativeRuntimeBaseList<3> lbl_802BFDA0 = {
    {
        { &lbl_803757E0, 0 }, // BaseObject_Z
        { &lbl_803757E8, 0 }, // ABC_Agent
        { &lbl_803757F0, 0 }, // StreamAgent_Z
    }, 0
};

}

// Adjacent native method and member-pointer records.

extern "C" {
void __dt__22LoadingScreen_800B9214Fv();
void fn_80035224();
void fn_80035228();
void fn_800C07D0();
void fn_800C07D4();
void fn_800C5BB0();
void fn_800C5C58();
void fn_800C5FB4();
void fn_800C6098();
void fn_800C60A0();
void fn_800C60A8();
void fn_800C60EC();
void fn_802534EC();
void fn_80253540();
void fn_80253584();
void fn_80253850();
void fn_80253B0C();
void fn_80253DC8();
void fn_80254084();
void fn_80254340();
void fn_802545FC();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void slot18__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const __vt__22LoadingScreen_800B9214[27] __attribute__((aligned(4))) = {
    &lbl_803757F8,
    0,
    (const void*)__dt__22LoadingScreen_800B9214Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)slot18__12BaseObject_ZFv,
    (const void*)fn_800C5BB0,
    (const void*)fn_800C6098,
    (const void*)fn_800C60A0,
    (const void*)fn_800C60A8,
    (const void*)fn_800C60EC,
    (const void*)fn_80035224,
    (const void*)fn_80035228,
    (const void*)fn_802545FC,
    (const void*)fn_80254340,
    (const void*)fn_80254084,
    (const void*)fn_80253DC8,
    (const void*)fn_80253B0C,
    (const void*)fn_80253850,
    (const void*)fn_800C5C58,
    (const void*)fn_800C5FB4,
    (const void*)fn_800C07D0,
    (const void*)fn_802534EC,
    (const void*)fn_800C07D4,
    (const void*)fn_80253584,
    (const void*)fn_80253540,
};

extern "C" __declspec(section ".data") const void* const lbl_802BFE28[18] __attribute__((aligned(4))) = {
    0,
    (const void*)0x000000AC,
    (const void*)0x00000008,
    0,
    (const void*)0x000000AC,
    (const void*)0x00000008,
    0,
    (const void*)0x000000AC,
    (const void*)0x00000008,
    0,
    (const void*)0x000000AC,
    (const void*)0x00000008,
    0,
    (const void*)0x000000AC,
    (const void*)0x00000008,
    0,
    (const void*)0x000000AC,
    (const void*)0x00000008,
};

