#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Volume_Script.
NativeRuntimeBaseList<5> lbl_802B49C0 = {
    {
        { &lbl_80374280, 0 }, // BaseObject_Z
        { &lbl_80374288, 0 }, // ABC_Agent
        { &lbl_80374290, 0 }, // Agent_Z
        { &lbl_80374298, 0 }, // VolumeAgent_Z
        { &lbl_803742A0, 0 }, // Volume_ScriptAndDebug
    }, 0
};

}

// Native volume method table after the existing base hierarchy.
extern "C" {
void __dt__15Object_80045AC4Fv();
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
void fn_80044448();
void fn_80044494();
void fn_80044578();
void fn_800446B8();
void fn_800447A8();
void fn_80044904();
void fn_80044908();
void fn_80045BE8();
void fn_80045C58();
void fn_80045CB4();
void fn_80045D28();
void fn_80045F34();
void fn_800461CC();
void fn_80046568();
void fn_8005218C();
void fn_80052194();
void fn_8005219C();
void fn_80052200();
void fn_80256028();
void fn_8025E11C();
void fn_8025E2FC();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void slot1C__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802B49EC[39] __attribute__((aligned(4))) = {
    &lbl_80374308,
    0,
    (const void*)__dt__15Object_80045AC4Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_80045BE8,
    (const void*)slot1C__12BaseObject_ZFv,
    (const void*)fn_8005218C,
    (const void*)fn_80052194,
    (const void*)fn_8005219C,
    (const void*)fn_80052200,
    (const void*)fn_80044448,
    (const void*)fn_80044494,
    (const void*)fn_80045C58,
    (const void*)fn_8025E2FC,
    (const void*)fn_80045CB4,
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
    (const void*)fn_80045D28,
    (const void*)fn_80044908,
    (const void*)fn_800461CC,
    (const void*)fn_80046568,
    (const void*)fn_80045F34,
};
