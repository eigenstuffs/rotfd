// Native method tables for two related owners and two member-function records.
// The second table changes destructor and override slots; shared slots
// retain the same native target functions. The final two records encode virtual
// callback slots with an eight-byte table offset.
typedef unsigned long u32;
struct MemberPointer { u32 receiverDelta, virtualSlot, tableOffset; };
extern "C" {
void slot5C__11Throwable_ZFv();
void slot60__11Throwable_ZFv();
void slot84__11Throwable_ZFv();
void slot88__11Throwable_ZFv();
void slot8C__11Throwable_ZFv();
void slot74__15AnimatedAgent_ZFv();
void slot70__7Agent_ZFv();
void slot94__10LodAgent_ZFv();
void slot98__10LodAgent_ZFv();
void slot9C__10LodAgent_ZFv();
void slotA0__10LodAgent_ZFv();
void slotA4__10LodAgent_ZFv();
void slotA8__10LodAgent_ZFv();
void slotAC__11CActorAgentFv();
void slot4C__11CActorAgentFv();
void slot50__11CActorAgentFv();
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
    (const void*)slot1C__13MovingAgent_ZFv,
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
    (const void*)slotAC__11CActorAgentFv,
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
    (const void*)slot1C__13MovingAgent_ZFv,
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
    (const void*)slotAC__11CActorAgentFv,
    (const void*)fn_80061224,
};

extern "C" __declspec(section ".data") const MemberPointer lbl_802B6028 __attribute__((aligned(4))) = {0, 216, 8};

extern "C" __declspec(section ".data") const MemberPointer lbl_802B6034 __attribute__((aligned(4))) = {0, 220, 8};

typedef char CheckMemberPointerSize[sizeof(MemberPointer) == 12 ? 1 : -1];
