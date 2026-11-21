// Recovered callback registration; see docs/notes/game-class-registry.md.
// WaterBallAgent.h factory proves a 0x90-byte object; fields remain opaque.
struct Agent_800737D8 {
    // Stack placement proves eight-byte alignment; this union only expresses storage.
    union { double alignment; unsigned char storage[0x90]; };
    Agent_800737D8();
    ~Agent_800737D8();
};
typedef void (Agent_800737D8::*MemberFunction)();
extern "C" {
extern unsigned long lbl_80377758;
extern MemberFunction lbl_802B7CD8;
void fn_8025BCC4();
void fn_8025E714(Agent_800737D8*, MemberFunction);
void fn_80073770()
{
    lbl_80377758 = 0;
    fn_8025BCC4();
    Agent_800737D8 object;
    fn_8025E714(&object, lbl_802B7CD8);
}
}
