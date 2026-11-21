// Recovered callback registration; see docs/notes/game-class-registry.md.
// VolumeAgents.h factory proves a 0x70-byte object; fields remain opaque.
struct Agent_80044118 {
    // Stack placement proves eight-byte alignment; this union only expresses storage.
    union { double alignment; unsigned char storage[0x70]; };
    Agent_80044118();
    ~Agent_80044118();
};
typedef void (Agent_80044118::*MemberFunction)();
extern "C" {
extern unsigned long lbl_80377648;
extern MemberFunction lbl_802B3708;
void fn_8025E31C();
void fn_8025E714(Agent_80044118*, MemberFunction);
void fn_800440B0()
{
    lbl_80377648 = 0;
    fn_8025E31C();
    Agent_80044118 object;
    fn_8025E714(&object, lbl_802B3708);
}
}
