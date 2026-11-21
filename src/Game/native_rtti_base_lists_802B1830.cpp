#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B1830 = {
    {
        { &lbl_803740E8, 0 }, // BaseObject_Z
        { &lbl_803740F0, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for CameraAgent_Z.
NativeRuntimeBaseList<3> lbl_802B1844 = {
    {
        { &lbl_803740E8, 0 }, // BaseObject_Z
        { &lbl_803740F0, 0 }, // ABC_Agent
        { &lbl_803740F8, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for CCameraAgent.
NativeRuntimeBaseList<4> lbl_802B1860 = {
    {
        { &lbl_803740E8, 0 }, // BaseObject_Z
        { &lbl_803740F0, 0 }, // ABC_Agent
        { &lbl_803740F8, 0 }, // Agent_Z
        { &lbl_80374100, 0 }, // CameraAgent_Z
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__14Agent_8002CF70Fv();
void fn_8002392C();
void fn_80023934();
void fn_8002393C();
void fn_80023944();
void fn_80028D58();
void fn_80028D60();
void fn_80028D68();
void fn_80028D6C();
void fn_8002D2F8();
void fn_8002D608();
void fn_8002D940();
void fn_8002D948();
void fn_8002D950();
void fn_8002D9A4();
void fn_8002DA24();
void fn_8002DA2C();
void fn_8002DA34();
void fn_8002DAD8();
void fn_8002DADC();
void fn_8002DAE4();
void fn_80256028();
void fn_802560D8();
void fn_8025BE2C();
void fn_8025BFF8();
void fn_8025C080();
void fn_8025C12C();
void fn_8025C208();
void fn_8025C2E4();
void fn_8025C520();
void fn_8025C858();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802B1884[37] __attribute__((aligned(4))) = {
    &lbl_80374108,
    0,
    (const void*)__dt__14Agent_8002CF70Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8002D2F8,
    (const void*)fn_8025C080,
    (const void*)fn_8002D940,
    (const void*)fn_8002D948,
    (const void*)fn_8002D950,
    (const void*)fn_8002D9A4,
    (const void*)fn_8025C208,
    (const void*)fn_8025C12C,
    (const void*)fn_8025C2E4,
    (const void*)fn_802560D8,
    (const void*)fn_8025BE2C,
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
    (const void*)fn_8002DA24,
    (const void*)fn_8002DA2C,
    (const void*)fn_8025BFF8,
    (const void*)fn_8002DA34,
    (const void*)fn_8025C858,
    (const void*)fn_8025C520,
    (const void*)fn_8002D608,
    0,
};

extern "C" __declspec(section ".data") const void* const lbl_802B1918[18] __attribute__((aligned(4))) = {
    0,
    (const void*)0x00000074,
    (const void*)0x00000008,
    0,
    (const void*)0x00000078,
    (const void*)0x00000008,
    0,
    (const void*)0x0000007C,
    (const void*)0x00000008,
    0,
    (const void*)0x00000080,
    (const void*)0x00000008,
    0,
    (const void*)0x00000084,
    (const void*)0x00000008,
    0,
    (const void*)0x00000088,
    (const void*)0x00000008,
};

