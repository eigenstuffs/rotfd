// Recovered callback registration; see docs/notes/game-class-registry.md.
// GlobalAgent.h factory proves a 0x320-byte object; fields remain opaque.
struct Agent_80052520 {
    // Stack placement proves eight-byte alignment; this union only expresses storage.
    union { double alignment; unsigned char storage[0x320]; };
    Agent_80052520();
    ~Agent_80052520();
};
typedef void (Agent_80052520::*MemberFunction)();
extern "C" {
extern unsigned long lbl_80377688;
extern MemberFunction lbl_802B4BE0;
void fn_8025E5FC();
void fn_8025E714(Agent_80052520*, MemberFunction);
void fn_800524B8()
{
    lbl_80377688 = 0;
    fn_8025E5FC();
    Agent_80052520 object;
    fn_8025E714(&object, lbl_802B4BE0);
}
}
