#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802C16C8 = {
    {
        { &lbl_803758B8, 0 }, // BaseObject_Z
        { &lbl_803758C0, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for VolumeAgent_Z.
NativeRuntimeBaseList<3> lbl_802C16DC = {
    {
        { &lbl_803758B8, 0 }, // BaseObject_Z
        { &lbl_803758C0, 0 }, // ABC_Agent
        { &lbl_803758C8, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for Volume_Container_In.
NativeRuntimeBaseList<4> lbl_802C16F8 = {
    {
        { &lbl_803758B8, 0 }, // BaseObject_Z
        { &lbl_803758C0, 0 }, // ABC_Agent
        { &lbl_803758C8, 0 }, // Agent_Z
        { &lbl_803758D0, 0 }, // VolumeAgent_Z
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__17ContainerInVolumeFv();
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
void fn_800CA0E8();
void fn_800CA13C();
void fn_800CA198();
void fn_800CA1C0();
void fn_800CA214();
void fn_800CA254();
void fn_800CA644();
void fn_800CAA20();
void fn_800CADB8();
void fn_800CADC0();
void fn_800CADC8();
void fn_800CAE1C();
void fn_800CAE9C();
void fn_80256028();
void fn_8025E11C();
void fn_8025E2FC();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void slot1C__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802C171C[35] __attribute__((aligned(4))) = {
    &lbl_803758D8,
    0,
    (const void*)__dt__17ContainerInVolumeFv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800CA0E8,
    (const void*)slot1C__12BaseObject_ZFv,
    (const void*)fn_800CADB8,
    (const void*)fn_800CADC0,
    (const void*)fn_800CADC8,
    (const void*)fn_800CAE1C,
    (const void*)fn_800CA198,
    (const void*)fn_800CA1C0,
    (const void*)fn_800CA13C,
    (const void*)fn_8025E2FC,
    (const void*)fn_800CA214,
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
    (const void*)fn_800CAE9C,
    (const void*)fn_800CA644,
    (const void*)fn_800CAA20,
    (const void*)fn_800CA254,
    0,
};

