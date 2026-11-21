// Recovered callback registration; see docs/notes/game-class-registry.md.
// RtcInGameAgent_Z.h factory proves a 0x180-byte object; fields remain opaque.
struct Agent_8003CD88 {
    // Stack placement proves eight-byte alignment; this union only expresses storage.
    union { double alignment; unsigned char storage[0x180]; };
    Agent_8003CD88();
    ~Agent_8003CD88();
};
typedef void (Agent_8003CD88::*MemberFunction)();
extern "C" {
extern unsigned long lbl_80377620;
extern MemberFunction lbl_802B2A70;
void fn_8025DE20();
void fn_8025E714(Agent_8003CD88*, MemberFunction);
void fn_8003CAB4()
{
    lbl_80377620 = 0;
    fn_8025DE20();
    Agent_8003CD88 object;
    fn_8025E714(&object, lbl_802B2A70);
}
}
