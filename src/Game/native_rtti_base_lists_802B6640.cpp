#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B6640 = {
    {
        { &lbl_80374640, 0 }, // BaseObject_Z
        { &lbl_80374648, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for AnimatedMsgAgent_Z.
NativeRuntimeBaseList<3> lbl_802B6654 = {
    {
        { &lbl_80374640, 0 }, // BaseObject_Z
        { &lbl_80374648, 0 }, // ABC_Agent
        { &lbl_80374650, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for AnimatedAgent_Z.
NativeRuntimeBaseList<4> lbl_802B6670 = {
    {
        { &lbl_80374640, 0 }, // BaseObject_Z
        { &lbl_80374648, 0 }, // ABC_Agent
        { &lbl_80374650, 0 }, // Agent_Z
        { &lbl_80374658, 0 }, // AnimatedMsgAgent_Z
    }, 0
};

// Base hierarchy for CSpringboardAgent.
NativeRuntimeBaseList<5> lbl_802B6694 = {
    {
        { &lbl_80374640, 0 }, // BaseObject_Z
        { &lbl_80374648, 0 }, // ABC_Agent
        { &lbl_80374650, 0 }, // Agent_Z
        { &lbl_80374658, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374660, 0 }, // AnimatedAgent_Z
    }, 0
};

// Base hierarchy for GClam.
NativeRuntimeBaseList<6> lbl_802B66C0 = {
    {
        { &lbl_80374640, 0 }, // BaseObject_Z
        { &lbl_80374648, 0 }, // ABC_Agent
        { &lbl_80374650, 0 }, // Agent_Z
        { &lbl_80374658, 0 }, // AnimatedMsgAgent_Z
        { &lbl_80374660, 0 }, // AnimatedAgent_Z
        { &lbl_80374668, 0 }, // CSpringboardAgent
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__14Agent_80064744Fv();
void fn_80023928();
void fn_8002392C();
void fn_80023934();
void fn_8002393C();
void fn_80023944();
void fn_80028D58();
void fn_80028D60();
void fn_80028D68();
void fn_80028D6C();
void fn_800647FC();
void fn_80064844();
void fn_80064848();
void fn_800648A0();
void fn_800648C0();
void fn_80064A44();
void fn_80064CF4();
void fn_80064DE0();
void fn_80064F90();
void fn_800653B4();
void fn_800653BC();
void fn_800653C4();
void fn_80065438();
void fn_800654F0();
void fn_80065500();
void fn_80065510();
void fn_80065518();
void fn_80065520();
void fn_80065584();
void fn_80256028();
void fn_80257338();
void fn_802573E4();
void fn_80257C50();
void fn_80257C58();
void fn_80257C78();
void fn_80257FF0();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802B66F4[32] __attribute__((aligned(4))) = {
    &lbl_80374670,
    0,
    (const void*)fn_80064CF4,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800647FC,
    (const void*)fn_80257C78,
    (const void*)fn_800653B4,
    (const void*)fn_800653BC,
    (const void*)fn_800653C4,
    (const void*)fn_80065438,
    (const void*)fn_802573E4,
    (const void*)fn_80257338,
    (const void*)fn_80064844,
    (const void*)fn_80257FF0,
    (const void*)fn_80064DE0,
    (const void*)fn_800648A0,
    (const void*)fn_8002392C,
    (const void*)fn_80023934,
    (const void*)fn_8002393C,
    (const void*)fn_800654F0,
    (const void*)fn_80065500,
    (const void*)fn_80028D68,
    (const void*)fn_80028D6C,
    (const void*)fn_80257C58,
    (const void*)fn_80257C50,
    (const void*)fn_80256028,
    (const void*)fn_80023944,
    (const void*)fn_80023928,
    (const void*)fn_80064F90,
    (const void*)fn_80064A44,
};

extern "C" __declspec(section ".data") const void* const lbl_802B6774[33] __attribute__((aligned(4))) = {
    &lbl_80374668,
    0,
    (const void*)__dt__14Agent_80064744Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800647FC,
    (const void*)fn_80257C78,
    (const void*)fn_80065510,
    (const void*)fn_80065518,
    (const void*)fn_80065520,
    (const void*)fn_80065584,
    (const void*)fn_802573E4,
    (const void*)fn_80257338,
    (const void*)fn_80064844,
    (const void*)fn_80257FF0,
    (const void*)fn_80064848,
    (const void*)fn_800648A0,
    (const void*)fn_8002392C,
    (const void*)fn_80023934,
    (const void*)fn_8002393C,
    (const void*)fn_80028D58,
    (const void*)fn_80028D60,
    (const void*)fn_80028D68,
    (const void*)fn_80028D6C,
    (const void*)fn_80257C58,
    (const void*)fn_80257C50,
    (const void*)fn_80256028,
    (const void*)fn_80023944,
    (const void*)fn_80023928,
    (const void*)fn_800648C0,
    (const void*)fn_80064A44,
    0,
};

