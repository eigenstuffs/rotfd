// Related agent method tables with a six-entry runtime base list.
// The tables preserve the native slot order and distinct override targets.
typedef unsigned long u32;
struct NativeBase { const void* type; u32 adjustment; };
struct NativeBaseList6 { NativeBase bases[6]; u32 terminator; };
extern "C" {
void __dt__14Agent_800E3250Fv();
void __dt__14Agent_800E3798Fv();
void slot5C__11Throwable_ZFv();
void slot60__11Throwable_ZFv();
void slot84__11Throwable_ZFv();
void slot88__11Throwable_ZFv();
void slot8C__11Throwable_ZFv();
void slot74__15AnimatedAgent_ZFv();
void slot48__7Agent_ZFv();
void slot4C__7Agent_ZFv();
void slot50__7Agent_ZFv();
void slot70__7Agent_ZFv();
void slot54__7Agent_ZFv();
void slot58__7Agent_ZFv();
void slot5C__7Agent_ZFv();
void slot60__7Agent_ZFv();
void fn_800E3308();
void fn_800E33A8();
void fn_800E3424();
void fn_800E34BC();
void fn_800E3850();
void fn_800E38F0();
void fn_800E39F0();
void fn_800E3B30();
void fn_800E3C70();
void fn_800E3EE4();
void fn_800E3EEC();
void fn_800E3EF4();
void fn_800E3F88();
void fn_800E4078();
void fn_800E4080();
void fn_800E4088();
void fn_800E40FC();
void slot6C__7Agent_ZFv();
void slot68__15AnimatedAgent_ZFv();
void slot64__15AnimatedAgent_ZFv();
void fn_80258654();
void fn_80258C74();
void fn_80258D48();
void fn_80258E48();
void fn_80258F60();
void slot1C__13MovingAgent_ZFv();
void fn_80259FB4();
void fn_8025A190();
void fn_8025A244();
void fn_8025A324();
void slot78__13MovingAgent_ZFv();
void slot7C__11Throwable_ZFv();
void slot90__11Throwable_ZFv();
void slot58__11Throwable_ZFv();
void slot54__11Throwable_ZFv();
void slot80__11Throwable_ZFv();
extern char lbl_80375AD8;
extern char lbl_80375AE0;
extern char lbl_80375AE8;
extern char lbl_80375AF0;
extern char lbl_80375AF8;
extern char lbl_80375B00;
extern char lbl_80375B18;
extern char lbl_80375B20;
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802C8C80[39] __attribute__((aligned(4))) = {
    &lbl_80375B18,
    0,
    (const void*)__dt__14Agent_800E3798Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800E3850,
    (const void*)fn_80258F60,
    (const void*)fn_800E3EE4,
    (const void*)fn_800E3EEC,
    (const void*)fn_800E3EF4,
    (const void*)fn_800E3F88,
    (const void*)fn_80258D48,
    (const void*)fn_80258C74,
    (const void*)fn_800E38F0,
    (const void*)fn_80258E48,
    (const void*)fn_800E39F0,
    (const void*)fn_80259FB4,
    (const void*)slot48__7Agent_ZFv,
    (const void*)slot4C__7Agent_ZFv,
    (const void*)slot50__7Agent_ZFv,
    (const void*)slot54__11Throwable_ZFv,
    (const void*)slot58__11Throwable_ZFv,
    (const void*)slot5C__11Throwable_ZFv,
    (const void*)slot60__11Throwable_ZFv,
    (const void*)slot64__15AnimatedAgent_ZFv,
    (const void*)slot68__15AnimatedAgent_ZFv,
    (const void*)slot6C__7Agent_ZFv,
    (const void*)slot70__7Agent_ZFv,
    (const void*)slot74__15AnimatedAgent_ZFv,
    (const void*)slot78__13MovingAgent_ZFv,
    (const void*)slot7C__11Throwable_ZFv,
    (const void*)slot80__11Throwable_ZFv,
    (const void*)slot84__11Throwable_ZFv,
    (const void*)slot88__11Throwable_ZFv,
    (const void*)slot8C__11Throwable_ZFv,
    (const void*)slot90__11Throwable_ZFv,
    (const void*)fn_800E3C70,
    (const void*)fn_800E3B30,
};


extern "C" __declspec(section ".data") const NativeBaseList6 lbl_802C8D1C __attribute__((aligned(4))) = {
    {
        {&lbl_80375AD8, 0},
        {&lbl_80375AE0, 0},
        {&lbl_80375AE8, 0},
        {&lbl_80375AF0, 0},
        {&lbl_80375AF8, 0},
        {&lbl_80375B00, 0},
    }, 0
};

extern "C" __declspec(section ".data") const void* const lbl_802C8D50[34] __attribute__((aligned(4))) = {
    &lbl_80375B20,
    0,
    (const void*)__dt__14Agent_800E3250Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800E3308,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_800E4078,
    (const void*)fn_800E4080,
    (const void*)fn_800E4088,
    (const void*)fn_800E40FC,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_80258654,
    (const void*)fn_8025A324,
    (const void*)fn_800E33A8,
    (const void*)fn_80259FB4,
    (const void*)slot48__7Agent_ZFv,
    (const void*)slot4C__7Agent_ZFv,
    (const void*)slot50__7Agent_ZFv,
    (const void*)slot54__7Agent_ZFv,
    (const void*)slot58__7Agent_ZFv,
    (const void*)slot5C__7Agent_ZFv,
    (const void*)slot60__7Agent_ZFv,
    (const void*)slot64__15AnimatedAgent_ZFv,
    (const void*)slot68__15AnimatedAgent_ZFv,
    (const void*)slot6C__7Agent_ZFv,
    (const void*)slot70__7Agent_ZFv,
    (const void*)slot74__15AnimatedAgent_ZFv,
    (const void*)slot78__13MovingAgent_ZFv,
    (const void*)fn_800E34BC,
    (const void*)fn_800E3424,
    0,
};

typedef char CheckNativeBaseList6Size[sizeof(NativeBaseList6) == 52 ? 1 : -1];
