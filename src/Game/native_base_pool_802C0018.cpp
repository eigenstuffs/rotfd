// Repeated native runtime-base lists and one adjacent method table.
// The first list has ten bases; each of the following fifteen records
// has eleven bases plus a zero-filled 188-byte reserved tail.
typedef unsigned long u32;
struct NativeBase { const void* type; u32 adjustment; };
struct BasePrefix { NativeBase bases[10]; u32 terminator; };
struct BaseRecord { NativeBase bases[11]; u32 reserved[47]; };
struct BasePool { BasePrefix prefix; BaseRecord records[15]; };
extern "C" {
void __dt__14Agent_800C61B8Fv();
void slot5C__11Throwable_ZFv();
void slot60__11Throwable_ZFv();
void slot84__11Throwable_ZFv();
void slot88__11Throwable_ZFv();
void slot8C__11Throwable_ZFv();
void slot74__15AnimatedAgent_ZFv();
void slot48__7Agent_ZFv();
void slot70__7Agent_ZFv();
void slot94__10LodAgent_ZFv();
void slot98__10LodAgent_ZFv();
void slot9C__10LodAgent_ZFv();
void slotA0__10LodAgent_ZFv();
void slotA4__10LodAgent_ZFv();
void slotA8__10LodAgent_ZFv();
void slot4C__11CActorAgentFv();
void slot50__11CActorAgentFv();
void fn_8006F598();
void fn_8006F5B8();
void fn_800BF5D8();
void fn_800BF664();
void fn_800C6280();
void fn_800C63D0();
void fn_800C63D4();
void fn_800C641C();
void fn_800C662C();
void fn_800C7524();
void fn_800C752C();
void slot6C__7Agent_ZFv();
void slot68__15AnimatedAgent_ZFv();
void slot64__15AnimatedAgent_ZFv();
void slot1C__13MovingAgent_ZFv();
void fn_8025A190();
void fn_8025A244();
void fn_8025A324();
void slot78__13MovingAgent_ZFv();
void slot7C__11Throwable_ZFv();
void slot90__11Throwable_ZFv();
void slot58__11Throwable_ZFv();
void slot54__11Throwable_ZFv();
void slot80__11Throwable_ZFv();
extern char lbl_80375800;
extern char lbl_80375808;
extern char lbl_80375810;
extern char lbl_80375818;
extern char lbl_80375820;
extern char lbl_80375828;
extern char lbl_80375830;
extern char lbl_80375838;
extern char lbl_80375840;
extern char lbl_80375848;
extern char lbl_80375850;
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
}

#define BASES_11 { \
    {&lbl_80375800, 0}, \
    {&lbl_80375808, 0}, \
    {&lbl_80375810, 0}, \
    {&lbl_80375818, 0}, \
    {&lbl_80375820, 0}, \
    {&lbl_80375828, 0}, \
    {&lbl_80375830, 0}, \
    {&lbl_80375838, 0}, \
    {&lbl_80375840, 0}, \
    {&lbl_80375848, 0}, \
    {&lbl_80375850, 0} \
}
#define BASE_RECORD { BASES_11, {0} }

extern "C" __declspec(section ".data") const BasePool lbl_802C0018 __attribute__((aligned(4))) = {
    { {
        {&lbl_80375800, 0},
        {&lbl_80375808, 0},
        {&lbl_80375810, 0},
        {&lbl_80375818, 0},
        {&lbl_80375820, 0},
        {&lbl_80375828, 0},
        {&lbl_80375830, 0},
        {&lbl_80375838, 0},
        {&lbl_80375840, 0},
        {&lbl_80375848, 0},
      }, 0 },
    {
        BASE_RECORD,
        BASE_RECORD,
        BASE_RECORD,
        BASE_RECORD,
        BASE_RECORD,
        BASE_RECORD,
        BASE_RECORD,
        BASE_RECORD,
        BASE_RECORD,
        BASE_RECORD,
        BASE_RECORD,
        BASE_RECORD,
        BASE_RECORD,
        BASE_RECORD,
        BASE_RECORD
    }
};

#undef BASE_RECORD
#undef BASES_11

extern "C" __declspec(section ".data") const void* const lbl_802C1098[46] __attribute__((aligned(4))) = {
    &lbl_80375850,
    0,
    (const void*)__dt__14Agent_800C61B8Fv,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_800C6280,
    (const void*)slot1C__13MovingAgent_ZFv,
    (const void*)fn_800C7524,
    (const void*)fn_800C752C,
    (const void*)fn_800BF5D8,
    (const void*)fn_800BF664,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_800C63D0,
    (const void*)fn_8025A324,
    (const void*)fn_800C63D4,
    (const void*)fn_8006F598,
    (const void*)slot48__7Agent_ZFv,
    (const void*)slot4C__11CActorAgentFv,
    (const void*)slot50__11CActorAgentFv,
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
    (const void*)slot94__10LodAgent_ZFv,
    (const void*)slot98__10LodAgent_ZFv,
    (const void*)slot9C__10LodAgent_ZFv,
    (const void*)slotA0__10LodAgent_ZFv,
    (const void*)slotA4__10LodAgent_ZFv,
    (const void*)slotA8__10LodAgent_ZFv,
    (const void*)fn_800C662C,
    (const void*)fn_800C641C,
    (const void*)fn_8006F5B8,
};

typedef char CheckNativeBaseSize[sizeof(NativeBase) == 8 ? 1 : -1];
typedef char CheckBasePrefixSize[sizeof(BasePrefix) == 84 ? 1 : -1];
typedef char CheckBaseRecordSize[sizeof(BaseRecord) == 276 ? 1 : -1];
typedef char CheckBasePoolSize[sizeof(BasePool) == 4224 ? 1 : -1];
