// Native control callback descriptors, dispatch table, and category strings.
typedef unsigned long ControlCallbackWord;
struct CallbackControlOwner;
struct CallbackControlRecord;
struct ControlCallbackDescriptor {
    ControlCallbackWord receiverAdjustment;
    ControlCallbackWord virtualSlot;
    ControlCallbackWord vptrOffset;
};
extern "C" {

struct ControlCallbackDescriptorPool { ControlCallbackDescriptor entries[6]; };

// Each descriptor dispatches slot 7C through the receiver vptr at offset 8.
ControlCallbackDescriptorPool lbl_802ECBB8 = {{{0, 0x7C, 8}, {0, 0x7C, 8},
    {0, 0x7C, 8}, {0, 0x7C, 8}, {0, 0x7C, 8}, {0, 0x7C, 8}}};
struct ControlCallbackCategories {
    char defaultCategory[12];
    char checkThrownCategory[20];
    char thrownCategory[12];
};
extern const ControlCallbackCategories lbl_802AEC00={"cat_default","cat_check_thrown","cat_thrown"};
}

extern "C" {
void fn_80020FE8(void*);
void slot0C__13Root_80207414FUl(void*);
void slot10__13Root_80207414Fv(void*);
void slot14__13Root_80207414Fv(void*);
void fn_8025BBA8(void*);
void slot1C__13MovingAgent_ZFv(void*);
void fn_8025B2FC(void*);
void fn_8025B304(void*);
void fn_8025B30C(void*);
void fn_8025B388(void*);
void fn_8025A244(void*);
void fn_8025A190(void*);
void fn_8025BB68(void*);
void fn_8025A324(void*);
void fn_8025A0A4(void*);
void fn_80259FB4(void*);
void slot48__7Agent_ZFv(void*);
void slot4C__7Agent_ZFv(void*);
void slot50__7Agent_ZFv(void*);
void slot54__11Throwable_ZFv(void*);
void slot58__11Throwable_ZFv(void*);
void slot5C__11Throwable_ZFv(void*);
void slot60__11Throwable_ZFv(void*);
void slot64__15AnimatedAgent_ZFv(void*);
void slot68__15AnimatedAgent_ZFv(void*);
void slot6C__7Agent_ZFv(void*);
void slot70__7Agent_ZFv(void*);
void slot74__15AnimatedAgent_ZFv(void*);
void slot78__13MovingAgent_ZFv(void*);
int slot7C__11Throwable_ZFv(CallbackControlOwner*, int, CallbackControlRecord*);
void slot80__11Throwable_ZFv(void*);
void slot84__11Throwable_ZFv(void*);
void slot88__11Throwable_ZFv(void*);
void slot8C__11Throwable_ZFv(void*);
void slot90__11Throwable_ZFv(void*);
struct CallbackControlDispatchTable {
const void* typeInfo;
long displacement;
void (*slot8)(void*);
void (*slotC)(void*);
void (*slot10)(void*);
void (*slot14)(void*);
void (*slot18)(void*);
void (*slot1C)(void*);
void (*slot20)(void*);
void (*slot24)(void*);
void (*slot28)(void*);
void (*slot2C)(void*);
void (*slot30)(void*);
void (*slot34)(void*);
void (*slot38)(void*);
void (*slot3C)(void*);
void (*slot40)(void*);
void (*slot44)(void*);
void (*slot48)(void*);
void (*slot4C)(void*);
void (*slot50)(void*);
void (*slot54)(void*);
void (*slot58)(void*);
void (*slot5C)(void*);
void (*slot60)(void*);
void (*slot64)(void*);
void (*slot68)(void*);
void (*slot6C)(void*);
void (*slot70)(void*);
void (*slot74)(void*);
void (*slot78)(void*);
int (*slot7C)(CallbackControlOwner*, int, CallbackControlRecord*);
void (*slot80)(void*);
void (*slot84)(void*);
void (*slot88)(void*);
void (*slot8C)(void*);
void (*slot90)(void*);
};
CallbackControlDispatchTable lbl_802ECC00={
0,
0,
fn_80020FE8,
slot0C__13Root_80207414FUl,
slot10__13Root_80207414Fv,
slot14__13Root_80207414Fv,
fn_8025BBA8,
slot1C__13MovingAgent_ZFv,
fn_8025B2FC,
fn_8025B304,
fn_8025B30C,
fn_8025B388,
fn_8025A244,
fn_8025A190,
fn_8025BB68,
fn_8025A324,
fn_8025A0A4,
fn_80259FB4,
slot48__7Agent_ZFv,
slot4C__7Agent_ZFv,
slot50__7Agent_ZFv,
slot54__11Throwable_ZFv,
slot58__11Throwable_ZFv,
slot5C__11Throwable_ZFv,
slot60__11Throwable_ZFv,
slot64__15AnimatedAgent_ZFv,
slot68__15AnimatedAgent_ZFv,
slot6C__7Agent_ZFv,
slot70__7Agent_ZFv,
slot74__15AnimatedAgent_ZFv,
slot78__13MovingAgent_ZFv,
slot7C__11Throwable_ZFv,
slot80__11Throwable_ZFv,
slot84__11Throwable_ZFv,
slot88__11Throwable_ZFv,
slot8C__11Throwable_ZFv,
slot90__11Throwable_ZFv
};
}

