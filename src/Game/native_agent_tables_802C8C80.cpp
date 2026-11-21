// Related agent method tables with a six-entry runtime base list.
// The tables preserve the native slot order and distinct override targets.
typedef unsigned long u32;
struct NativeBase { const void* type; u32 adjustment; };
struct NativeBaseList6 { NativeBase bases[6]; u32 terminator; };
extern "C" {
void __dt__14Agent_800E3250Fv();
void __dt__14Agent_800E3798Fv();
void fn_8002390C();
void fn_80023914();
void fn_8002391C();
void fn_80023920();
void fn_80023924();
void fn_80023928();
void fn_8002392C();
void fn_80023934();
void fn_8002393C();
void fn_80023944();
void fn_80028D58();
void fn_80028D60();
void fn_80028D68();
void fn_80028D6C();
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
void fn_80256028();
void fn_80257C50();
void fn_80257C58();
void fn_80258654();
void fn_80258C74();
void fn_80258D48();
void fn_80258E48();
void fn_80258F60();
void fn_80259F0C();
void fn_80259FB4();
void fn_8025A190();
void fn_8025A244();
void fn_8025A324();
void fn_8025A5F8();
void fn_8025B448();
void fn_8025B928();
void fn_8025BAD4();
void fn_8025BAF4();
void fn_8025BB14();
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
    (const void*)fn_8002392C,
    (const void*)fn_80023934,
    (const void*)fn_8002393C,
    (const void*)fn_8025BAF4,
    (const void*)fn_8025BAD4,
    (const void*)fn_8002390C,
    (const void*)fn_80023914,
    (const void*)fn_80257C58,
    (const void*)fn_80257C50,
    (const void*)fn_80256028,
    (const void*)fn_80023944,
    (const void*)fn_80023928,
    (const void*)fn_8025A5F8,
    (const void*)fn_8025B448,
    (const void*)fn_8025BB14,
    (const void*)fn_8002391C,
    (const void*)fn_80023920,
    (const void*)fn_80023924,
    (const void*)fn_8025B928,
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
    (const void*)fn_80259F0C,
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
    (const void*)fn_8025A5F8,
    (const void*)fn_800E34BC,
    (const void*)fn_800E3424,
    0,
};

typedef char CheckNativeBaseList6Size[sizeof(NativeBaseList6) == 52 ? 1 : -1];
