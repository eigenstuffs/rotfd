// Recovered callback registration; see docs/notes/game-class-registry.md.
// SBPantsAgent.h factory proves a 0x78-byte object; fields remain opaque.
struct Agent_800E3250 {
    // Stack placement proves eight-byte alignment; this union only expresses storage.
    union { double alignment; unsigned char storage[0x78]; };
    Agent_800E3250();
    ~Agent_800E3250();
};
typedef void (Agent_800E3250::*MemberFunction)();
extern "C" {
extern unsigned long lbl_803778A8;
extern MemberFunction lbl_802C8A78;
void fn_8025A930();
void fn_8025E714(Agent_800E3250*, MemberFunction);
void fn_800E31E8()
{
    lbl_803778A8 = 0;
    fn_8025A930();
    Agent_800E3250 object;
    fn_8025E714(&object, lbl_802C8A78);
}
}
