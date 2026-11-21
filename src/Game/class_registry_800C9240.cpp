// 2 callback registrations; see docs/notes/game-class-registry.md.
// Factory DamageVolume.h proves the 0x80-byte object extent.
struct Agent_800C92D4 {
    union { double alignment; unsigned char storage[0x80]; };
    Agent_800C92D4();
    ~Agent_800C92D4();
};
typedef void (Agent_800C92D4::*MemberFunction)();
extern "C" {
extern unsigned long lbl_80377870;
extern MemberFunction lbl_802C13A8;
extern MemberFunction lbl_802C13B4;
void fn_800440B0();
void fn_8025E714(Agent_800C92D4*, MemberFunction);
void fn_800C9240() {
    lbl_80377870=0;
    fn_800440B0();
    Agent_800C92D4 object;
    fn_8025E714(&object, lbl_802C13A8);
    fn_8025E714(&object, lbl_802C13B4);
}
}
