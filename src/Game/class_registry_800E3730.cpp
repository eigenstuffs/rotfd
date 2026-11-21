// Recovered callback registration; see docs/notes/game-class-registry.md.
// SBPantsAgent.h factory proves a 0x88-byte object; fields remain opaque.
struct Agent_800E3798 {
    // Stack placement proves eight-byte alignment; this union only expresses storage.
    union { double alignment; unsigned char storage[0x88]; };
    Agent_800E3798();
    ~Agent_800E3798();
};
typedef void (Agent_800E3798::*MemberFunction)();
extern "C" {
extern unsigned long lbl_803778AC;
extern MemberFunction lbl_802C8ADC;
void fn_8025959C();
void fn_8025E714(Agent_800E3798*, MemberFunction);
void fn_800E3730()
{
    lbl_803778AC = 0;
    fn_8025959C();
    Agent_800E3798 object;
    fn_8025E714(&object, lbl_802C8ADC);
}
}
