// Native method tables for two related owners and two member-function records.
// The second table changes destructor and override slots; shared slots
// retain the same native target functions. The final two records encode virtual
// callback slots with an eight-byte table offset.
typedef unsigned long u32;
struct MemberPointer { u32 receiverDelta, virtualSlot, tableOffset; };
extern "C" {
void fn_8002390C();
void fn_80023914();
void fn_8002391C();
void fn_80023920();
void fn_80023924();
void fn_80023928();
void fn_80023944();
void fn_80025E04();
void fn_80025E08();
void fn_80025E0C();
void fn_80025E10();
void fn_80025E18();
void fn_80025E1C();
void fn_8002BE80();
void fn_8002CEE8();
void fn_8002CEF8();
void fn_80060F08();
void fn_80060F84();
void fn_80061044();
void fn_80061064();
void fn_80061204();
void fn_80061224();
void fn_800613FC();
void fn_800614C0();
void fn_8006154C();
void fn_8006160C();
void fn_80061610();
void fn_800617B0();
void fn_800617D0();
void fn_800617D8();
void fn_800617E0();
void fn_80061820();
void fn_800618C4();
void fn_80061910();
void fn_80061A1C();
void fn_80061A24();
void fn_80256028();
void fn_80257C50();
void fn_80257C58();
void fn_80259F0C();
void fn_8025A190();
void fn_8025A244();
void fn_8025A324();
void fn_8025A5F8();
void fn_8025B448();
void fn_8025B928();
void fn_8025BAD4();
void fn_8025BAF4();
void fn_8025BB14();
extern char lbl_803745A8;
extern char lbl_803745B0;
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
}

extern "C" __declspec(section ".data") const void* const lbl_802B5EC0[45] __attribute__((aligned(4))) = {
    &lbl_803745B0,
    0,
    (const void*)fn_800614C0,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_8006154C,
    (const void*)fn_80259F0C,
    (const void*)fn_800617D0,
    (const void*)fn_800617D8,
    (const void*)fn_800617E0,
    (const void*)fn_800618C4,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_8006160C,
    (const void*)fn_8025A324,
    (const void*)fn_80061610,
    (const void*)fn_800617B0,
    (const void*)fn_800613FC,
    (const void*)fn_8002CEE8,
    (const void*)fn_8002CEF8,
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
    (const void*)fn_80025E04,
    (const void*)fn_80025E08,
    (const void*)fn_80025E0C,
    (const void*)fn_80025E10,
    (const void*)fn_80025E18,
    (const void*)fn_80025E1C,
    (const void*)fn_8002BE80,
    (const void*)fn_80061224,
};

extern "C" __declspec(section ".data") const void* const lbl_802B5F74[45] __attribute__((aligned(4))) = {
    &lbl_803745A8,
    0,
    (const void*)fn_80060F08,
    (const void*)slot0C__12BaseObject_ZFUl,
    (const void*)slot10__12BaseObject_ZFv,
    (const void*)slot14__12BaseObject_ZFv,
    (const void*)fn_80060F84,
    (const void*)fn_80259F0C,
    (const void*)fn_80061A1C,
    (const void*)fn_80061A24,
    (const void*)fn_80061820,
    (const void*)fn_80061910,
    (const void*)fn_8025A244,
    (const void*)fn_8025A190,
    (const void*)fn_80061044,
    (const void*)fn_8025A324,
    (const void*)fn_80061064,
    (const void*)fn_80061204,
    (const void*)fn_800613FC,
    (const void*)fn_8002CEE8,
    (const void*)fn_8002CEF8,
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
    (const void*)fn_80025E04,
    (const void*)fn_80025E08,
    (const void*)fn_80025E0C,
    (const void*)fn_80025E10,
    (const void*)fn_80025E18,
    (const void*)fn_80025E1C,
    (const void*)fn_8002BE80,
    (const void*)fn_80061224,
};

extern "C" __declspec(section ".data") const MemberPointer lbl_802B6028 __attribute__((aligned(4))) = {0, 216, 8};

extern "C" __declspec(section ".data") const MemberPointer lbl_802B6034 __attribute__((aligned(4))) = {0, 220, 8};

typedef char CheckMemberPointerSize[sizeof(MemberPointer) == 12 ? 1 : -1];
