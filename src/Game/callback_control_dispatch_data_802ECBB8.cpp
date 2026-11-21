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
void fn_80259F0C(void*);
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
void fn_8002392C(void*);
void fn_80023934(void*);
void fn_8002393C(void*);
void fn_8025BAF4(void*);
void fn_8025BAD4(void*);
void fn_8002390C(void*);
void fn_80023914(void*);
void fn_80257C58(void*);
void fn_80257C50(void*);
void fn_80256028(void*);
void fn_80023944(void*);
void fn_80023928(void*);
void fn_8025A5F8(void*);
int fn_8025B448(CallbackControlOwner*, int, CallbackControlRecord*);
void fn_8025BB14(void*);
void fn_8002391C(void*);
void fn_80023920(void*);
void fn_80023924(void*);
void fn_8025B928(void*);
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
fn_80259F0C,
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
fn_8002392C,
fn_80023934,
fn_8002393C,
fn_8025BAF4,
fn_8025BAD4,
fn_8002390C,
fn_80023914,
fn_80257C58,
fn_80257C50,
fn_80256028,
fn_80023944,
fn_80023928,
fn_8025A5F8,
fn_8025B448,
fn_8025BB14,
fn_8002391C,
fn_80023920,
fn_80023924,
fn_8025B928
};
}

