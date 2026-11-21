#include "Game/native_runtime_type_records_remaining.h"

extern "C" void fn_80061D18();
extern "C" __declspec(section ".data") const void* const lbl_802B60F0[3] __attribute__((aligned(4))) = {
    &lbl_803745B8, 0, (const void*)fn_80061D18
};
extern "C" NativeRuntimeBaseList<1> lbl_802B60FC = {
    { { &lbl_803745C8, 0 } }, 0
};

extern "C" {
// Base hierarchy for Agent_Z.
NativeRuntimeBaseList<2> lbl_802B6108 = {
    {
        { &lbl_803745C8, 0 }, // BaseObject_Z
        { &lbl_803745D0, 0 }, // ABC_Agent
    }, 0
};

// Base hierarchy for CLevelAgent.
NativeRuntimeBaseList<4> lbl_802B611C = {
    {
        { &lbl_803745C0, 96 }, // CScriptAgent
        { &lbl_803745C8, 0 }, // BaseObject_Z
        { &lbl_803745D0, 0 }, // ABC_Agent
        { &lbl_803745D8, 0 }, // Agent_Z
    }, 0
};

}
