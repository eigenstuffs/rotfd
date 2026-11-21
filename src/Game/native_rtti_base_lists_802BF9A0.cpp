#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for ABC_Agent.
NativeRuntimeBaseList<1> lbl_802BF9A0 = {
    {
        { &lbl_80375738, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802BF9AC = {
    {
        { &lbl_80375738, 0 }, // BaseObject_Z
        { &lbl_80375740, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for ParticlesAgent_Z.
NativeRuntimeBaseList<3> lbl_802BF9C0 = {
    {
        { &lbl_80375738, 0 }, // BaseObject_Z
        { &lbl_80375740, 0 }, // ABC_Agent
        { &lbl_80375748, 0 }, // Agent_Z
    }, 0
};

// Base hierarchy for ParticlesAlwaysOn.
NativeRuntimeBaseList<4> lbl_802BF9DC = {
    {
        { &lbl_80375738, 0 }, // BaseObject_Z
        { &lbl_80375740, 0 }, // ABC_Agent
        { &lbl_80375748, 0 }, // Agent_Z
        { &lbl_80375750, 0 }, // ParticlesAgent_Z
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_800C4E04Fv();
void fn_8002392C();
void fn_80023934();
void fn_8002393C();
void fn_80023944();
void fn_80028D58();
void fn_80028D60();
void fn_80028D68();
void fn_80028D6C();
void fn_8002DADC();
void fn_8002DAE4();
void fn_800C4CD0();
void fn_800C4D20();
void fn_800C4D28();
void fn_800C4D30();
void fn_800C4D84();
void fn_80254C74();
void fn_80254E5C();
void fn_80254E90();
void fn_80254F70();
void fn_802551F4();
void fn_8025529C();
void fn_802553C8();
void fn_802556CC();
void fn_80255750();
void fn_80256028();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802BFA00[32] __attribute__((aligned(4))) = {
    &lbl_80375758,
    0,
    (const void*)__dt__15Object_800C4E04Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_80255750,
    (const void*)fn_802551F4,
    (const void*)fn_800C4D20,
    (const void*)fn_800C4D28,
    (const void*)fn_800C4D30,
    (const void*)fn_800C4D84,
    (const void*)fn_802553C8,
    (const void*)fn_8025529C,
    (const void*)fn_802556CC,
    (const void*)fn_80254F70,
    (const void*)fn_800C4CD0,
    (const void*)fn_80254E90,
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
    (const void*)fn_80254C74,
    (const void*)fn_80254E5C,
    0,
};

