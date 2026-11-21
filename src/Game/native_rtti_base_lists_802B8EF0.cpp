#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for CStateHookHang.
NativeRuntimeBaseList<2> lbl_802B8EF0 = {
    {
        { &lbl_80374A1C, 0 }, // CState
        { &lbl_80374A24, 0 }, // CStateSBBase
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__15Object_8008F570Fv();
void fn_80084A14();
void fn_80084C4C();
void fn_80084C50();
void fn_80084DCC();
}

extern "C" __declspec(section ".data") const void* const lbl_802B8F04[7] __attribute__((aligned(4))) = {
    &lbl_80374B5C,
    0,
    (const void*)__dt__15Object_8008F570Fv,
    (const void*)fn_80084A14,
    (const void*)fn_80084C4C,
    (const void*)fn_80084DCC,
    (const void*)fn_80084C50,
};

