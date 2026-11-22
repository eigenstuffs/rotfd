#include "Game/native_runtime_type_records_remaining.h"

extern "C" {
// Base hierarchy for Activable_Z.
NativeRuntimeBaseList<1> lbl_802BB598 = {
    {
        { &lbl_80375048, 0 }, // BaseObject_Z
    }, 0
};

// Base hierarchy for Manipulator_Z.
NativeRuntimeBaseList<2> lbl_802BB5A4 = {
    {
        { &lbl_80375048, 0 }, // BaseObject_Z
        { &lbl_80375050, 0 }, // Activable_Z
    }, 0
};

// Base hierarchy for ObjectMove_Z.
NativeRuntimeBaseList<3> lbl_802BB5B8 = {
    {
        { &lbl_80375048, 0 }, // BaseObject_Z
        { &lbl_80375050, 0 }, // Activable_Z
        { &lbl_80375058, 0 }, // Manipulator_Z
    }, 0
};

// Base hierarchy for ObjectThrow_Z.
NativeRuntimeBaseList<4> lbl_802BB5D4 = {
    {
        { &lbl_80375048, 0 }, // BaseObject_Z
        { &lbl_80375050, 0 }, // Activable_Z
        { &lbl_80375058, 0 }, // Manipulator_Z
        { &lbl_80375060, 0 }, // ObjectMove_Z
    }, 0
};

// Base hierarchy for LodMove_Z.
NativeRuntimeBaseList<5> lbl_802BB5F8 = {
    {
        { &lbl_80375048, 0 }, // BaseObject_Z
        { &lbl_80375050, 0 }, // Activable_Z
        { &lbl_80375058, 0 }, // Manipulator_Z
        { &lbl_80375060, 0 }, // ObjectMove_Z
        { &lbl_80375068, 0 }, // ObjectThrow_Z
    }, 0
};

// Base hierarchy for CActorMove.
NativeRuntimeBaseList<7> lbl_802BB624 = {
    {
        { &lbl_80375040, 792 }, // CFSM
        { &lbl_80375048, 0 }, // BaseObject_Z
        { &lbl_80375050, 0 }, // Activable_Z
        { &lbl_80375058, 0 }, // Manipulator_Z
        { &lbl_80375060, 0 }, // ObjectMove_Z
        { &lbl_80375068, 0 }, // ObjectThrow_Z
        { &lbl_80375070, 0 }, // LodMove_Z
    }, 0
};

// Base hierarchy for CScriptMove.
NativeRuntimeBaseList<8> lbl_802BB660 = {
    {
        { &lbl_80375040, 792 }, // CFSM
        { &lbl_80375048, 0 }, // BaseObject_Z
        { &lbl_80375050, 0 }, // Activable_Z
        { &lbl_80375058, 0 }, // Manipulator_Z
        { &lbl_80375060, 0 }, // ObjectMove_Z
        { &lbl_80375068, 0 }, // ObjectThrow_Z
        { &lbl_80375070, 0 }, // LodMove_Z
        { &lbl_80375078, 0 }, // CActorMove
    }, 0
};

}

// Adjacent native method and runtime-base records.
extern "C" {
void __dt__11CScriptMoveFv();
void slot9C__12ObjectMove_ZFv();
void slot140__9LodMove_ZFv();
void slot15C__9LodMove_ZFv();
void slot160__9LodMove_ZFiPv();
void slot138__13ObjectThrow_ZFv();
void slot54__12ObjectMove_ZFv();
void slot6C__12ObjectMove_ZFv();
void slot7C__12ObjectMove_ZFv();
void slot8C__12ObjectMove_ZFv();
void slot90__12ObjectMove_ZFv();
void slot94__12ObjectMove_ZFv();
void slot98__12ObjectMove_ZFv();
void slotA0__12ObjectMove_ZFv();
void slotA4__12ObjectMove_ZFv();
void slotA8__12ObjectMove_ZFv();
void slotAC__12ObjectMove_ZFv();
void slotDC__12ObjectMove_ZFv();
void slotE0__12ObjectMove_ZFv();
void slotE4__12ObjectMove_ZFv();
void slotE8__12ObjectMove_ZFv();
void slotEC__12ObjectMove_ZFv();
void slotF0__12ObjectMove_ZFv();
void configure__4CFSMFi();
void reset__4CFSMFv();
void slot74__10CActorMoveFv();
void slot14C__10CActorMoveFv();
void slot150__10CActorMoveFv();
void slot154__10CActorMoveFv();
void slot158__10CActorMoveFv();
void slot144__10CActorMoveFv();
void slot70__10CActorMoveFv();
void slot78__10CActorMoveFf();
void slot168__10CActorMoveFv();
void slot108__10CActorMoveFv();
void slot188__10CActorMoveFv();
void slot18C__10CActorMoveFv();
void slot190__10CActorMoveFv();
void slot194__10CActorMoveFv();
void slot148__10CActorMoveFv();
void slot18__11CScriptMoveFv();
void slot34__11CScriptMoveFv();
void configureCallbacks__11CScriptMoveFv();
void slot44__11CScriptMoveFv();
void slot38__11CScriptMoveFf();
void slot40__11CScriptMoveFPC4Vec3PC4Vec3PC4Vec3if();
void slot198__11CScriptMoveFf();
void slot1A0__11CScriptMoveFv();
void slot1A4__11CScriptMoveFv();
void slot5C__11CScriptMoveFv();
void slot60__11CScriptMoveFv();
void fn_8009FE40();
void fn_8009FE48();
void slot11C__12ObjectMove_ZFv();
void slot114__12ObjectMove_ZFv();
void slot110__12ObjectMove_ZFv();
void slot10C__12ObjectMove_ZFv();
void slot88__12ObjectMove_ZFv();
void slot68__12ObjectMove_ZFv();
void slot104__12ObjectMove_ZFv();
void slot164__9LodMove_ZFv();
void slot4C__9LodMove_ZFv();
void slot50__9LodMove_ZFv();
void slot48__9LodMove_ZFv();
void slot100__13ObjectThrow_ZFv();
void slotF8__12ObjectMove_ZFv();
void slot80__12ObjectMove_ZFv();
void slotC8__12ObjectMove_ZFv();
void slotCC__12ObjectMove_ZFv();
void slotC4__12ObjectMove_ZFv();
void slotB8__12ObjectMove_ZFv();
void slotB4__12ObjectMove_ZFv();
void slotD8__12ObjectMove_ZFv();
void slotD4__12ObjectMove_ZFv();
void slotD0__12ObjectMove_ZFv();
void slot16C__9LodMove_ZFv();
void slot118__9LodMove_ZFv();
void slot58__9LodMove_ZFv();
void slot134__9LodMove_ZFv();
void slot130__9LodMove_ZFv();
void slotC0__9LodMove_ZFv();
void slotBC__9LodMove_ZFv();
void slotB0__9LodMove_ZFv();
void slot13C__9LodMove_ZFv();
void slotF4__13ObjectThrow_ZFv();
void slot124__13ObjectThrow_ZFv();
void slot128__13ObjectThrow_ZFv();
void slot64__13ObjectThrow_ZFv();
void slotFC__13ObjectThrow_ZFv();
void slot120__13ObjectThrow_ZFv();
void slot12C__13ObjectThrow_ZFv();
void slot84__13ObjectThrow_ZFv();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void slot1C__12BaseObject_ZFv();
void slot20__11Activable_ZFv();
void slot24__11Activable_ZFv();
void slot28__11Activable_ZFv();
void slot2C__13Manipulator_ZFf();
void slot30__13Manipulator_ZFv();
void slot3C__13Manipulator_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802BB6A4[107] __attribute__((aligned(4))) = {
    &lbl_80375080,
    0,
    (const void*)__dt__11CScriptMoveFv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)slot18__11CScriptMoveFv,
    (const void*)slot1C__12BaseObject_ZFv,
    (const void*)slot20__11Activable_ZFv,
    (const void*)slot24__11Activable_ZFv,
    (const void*)slot28__11Activable_ZFv,
    (const void*)slot2C__13Manipulator_ZFf,
    (const void*)slot30__13Manipulator_ZFv,
    (const void*)slot34__11CScriptMoveFv,
    (const void*)slot38__11CScriptMoveFf,
    (const void*)slot3C__13Manipulator_ZFv,
    (const void*)slot40__11CScriptMoveFPC4Vec3PC4Vec3PC4Vec3if,
    (const void*)slot44__11CScriptMoveFv,
    (const void*)slot48__9LodMove_ZFv,
    (const void*)slot4C__9LodMove_ZFv,
    (const void*)slot50__9LodMove_ZFv,
    (const void*)slot54__12ObjectMove_ZFv,
    (const void*)slot58__9LodMove_ZFv,
    (const void*)slot5C__11CScriptMoveFv,
    (const void*)slot60__11CScriptMoveFv,
    (const void*)slot64__13ObjectThrow_ZFv,
    (const void*)slot68__12ObjectMove_ZFv,
    (const void*)slot6C__12ObjectMove_ZFv,
    (const void*)slot70__10CActorMoveFv,
    (const void*)slot74__10CActorMoveFv,
    (const void*)slot78__10CActorMoveFf,
    (const void*)slot7C__12ObjectMove_ZFv,
    (const void*)slot80__12ObjectMove_ZFv,
    (const void*)slot84__13ObjectThrow_ZFv,
    (const void*)slot88__12ObjectMove_ZFv,
    (const void*)slot8C__12ObjectMove_ZFv,
    (const void*)slot90__12ObjectMove_ZFv,
    (const void*)slot94__12ObjectMove_ZFv,
    (const void*)slot98__12ObjectMove_ZFv,
    (const void*)slot9C__12ObjectMove_ZFv,
    (const void*)slotA0__12ObjectMove_ZFv,
    (const void*)slotA4__12ObjectMove_ZFv,
    (const void*)slotA8__12ObjectMove_ZFv,
    (const void*)slotAC__12ObjectMove_ZFv,
    (const void*)slotB0__9LodMove_ZFv,
    (const void*)slotB4__12ObjectMove_ZFv,
    (const void*)slotB8__12ObjectMove_ZFv,
    (const void*)slotBC__9LodMove_ZFv,
    (const void*)slotC0__9LodMove_ZFv,
    (const void*)slotC4__12ObjectMove_ZFv,
    (const void*)slotC8__12ObjectMove_ZFv,
    (const void*)slotCC__12ObjectMove_ZFv,
    (const void*)slotD0__12ObjectMove_ZFv,
    (const void*)slotD4__12ObjectMove_ZFv,
    (const void*)slotD8__12ObjectMove_ZFv,
    (const void*)slotDC__12ObjectMove_ZFv,
    (const void*)slotE0__12ObjectMove_ZFv,
    (const void*)slotE4__12ObjectMove_ZFv,
    (const void*)slotE8__12ObjectMove_ZFv,
    (const void*)slotEC__12ObjectMove_ZFv,
    (const void*)slotF0__12ObjectMove_ZFv,
    (const void*)slotF4__13ObjectThrow_ZFv,
    (const void*)slotF8__12ObjectMove_ZFv,
    (const void*)slotFC__13ObjectThrow_ZFv,
    (const void*)slot100__13ObjectThrow_ZFv,
    (const void*)slot104__12ObjectMove_ZFv,
    (const void*)slot108__10CActorMoveFv,
    (const void*)slot10C__12ObjectMove_ZFv,
    (const void*)slot110__12ObjectMove_ZFv,
    (const void*)slot114__12ObjectMove_ZFv,
    (const void*)slot118__9LodMove_ZFv,
    (const void*)slot11C__12ObjectMove_ZFv,
    (const void*)slot120__13ObjectThrow_ZFv,
    (const void*)slot124__13ObjectThrow_ZFv,
    (const void*)slot128__13ObjectThrow_ZFv,
    (const void*)slot12C__13ObjectThrow_ZFv,
    (const void*)slot130__9LodMove_ZFv,
    (const void*)slot134__9LodMove_ZFv,
    (const void*)slot138__13ObjectThrow_ZFv,
    (const void*)slot13C__9LodMove_ZFv,
    (const void*)slot140__9LodMove_ZFv,
    (const void*)slot144__10CActorMoveFv,
    (const void*)slot148__10CActorMoveFv,
    (const void*)slot14C__10CActorMoveFv,
    (const void*)slot150__10CActorMoveFv,
    (const void*)slot154__10CActorMoveFv,
    (const void*)slot158__10CActorMoveFv,
    (const void*)slot15C__9LodMove_ZFv,
    (const void*)slot160__9LodMove_ZFiPv,
    (const void*)slot164__9LodMove_ZFv,
    (const void*)slot168__10CActorMoveFv,
    (const void*)slot16C__9LodMove_ZFv,
    &lbl_80375080,
    (const void*)0xFFFFFCE8,
    (const void*)fn_8009FE48,
    (const void*)fn_8009FE40,
    (const void*)configure__4CFSMFi,
    (const void*)reset__4CFSMFv,
    (const void*)slot188__10CActorMoveFv,
    (const void*)slot18C__10CActorMoveFv,
    (const void*)slot190__10CActorMoveFv,
    (const void*)slot194__10CActorMoveFv,
    (const void*)slot198__11CScriptMoveFf,
    (const void*)configureCallbacks__11CScriptMoveFv,
    (const void*)slot1A0__11CScriptMoveFv,
    (const void*)slot1A4__11CScriptMoveFv,
    0,
};

