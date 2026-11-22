#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Volume_Pull.
NativeRuntimeBaseList<4> lbl_802B4338 = {
    {
        { &lbl_80374280, 0 }, // BaseObject_Z
        { &lbl_80374288, 0 }, // ABC_Agent
        { &lbl_80374290, 0 }, // Agent_Z
        { &lbl_80374298, 0 }, // VolumeAgent_Z
    }, 0
};

}

// Native volume method tables following the base-list group at 0x802B4338.
extern "C" {
void __dt__14Agent_8004E90CFv();
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
void fn_80035224();
void fn_80035228();
void fn_8004EAD0();
void fn_8004EB04();
void fn_8004EB70();
void fn_8004EEFC();
void fn_8005184C();
void fn_80051854();
void fn_8005185C();
void fn_800518B0();
void slot6C__7Agent_ZFv();
void fn_8025E11C();
void fn_8025E2FC();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void slot1C__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802B435C[31] __attribute__((aligned(4))) = {
    &lbl_803742C0,
    0,
    (const void*)__dt__14Agent_8004E90CFv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8004EAD0,
    (const void*)slot1C__12BaseObject_ZFv,
    (const void*)fn_8005184C,
    (const void*)fn_80051854,
    (const void*)fn_8005185C,
    (const void*)fn_800518B0,
    (const void*)fn_80035224,
    (const void*)fn_80035228,
    (const void*)fn_8004EB70,
    (const void*)fn_8025E2FC,
    (const void*)fn_8004EB04,
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
    (const void*)fn_8004EEFC,
};
