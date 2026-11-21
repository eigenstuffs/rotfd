// Recovered callback registration; see docs/notes/game-class-registry.md.
// SpringboardAgent.h factory proves a 0x70-byte object; fields remain opaque.
struct Agent_80064744 {
    // Stack placement proves eight-byte alignment; this union only expresses storage.
    union { double alignment; unsigned char storage[0x70]; };
    Agent_80064744();
    ~Agent_80064744();
};
typedef void (Agent_80064744::*MemberFunction)();
extern "C" {
extern unsigned long lbl_80377710;
extern MemberFunction lbl_802B65D0;
void fn_80258948();
void fn_8025E714(Agent_80064744*, MemberFunction);
void fn_800646DC()
{
    lbl_80377710 = 0;
    fn_80258948();
    Agent_80064744 object;
    fn_8025E714(&object, lbl_802B65D0);
}
}
