// 2 callback registrations; see docs/notes/game-class-registry.md.
// Factory BossDeathVolume.h proves the 0x78-byte object extent.
struct Agent_800E75B0 {
    union { double alignment; unsigned char storage[0x78]; };
    Agent_800E75B0();
    ~Agent_800E75B0();
};
typedef void (Agent_800E75B0::*MemberFunction)();
extern "C" {
extern unsigned long lbl_803778B0;
extern MemberFunction lbl_802C8ED0;
extern MemberFunction lbl_802C8EDC;
void fn_800440B0();
void fn_8025E714(Agent_800E75B0*, MemberFunction);
void fn_800E751C() {
    lbl_803778B0=0;
    fn_800440B0();
    Agent_800E75B0 object;
    fn_8025E714(&object, lbl_802C8ED0);
    fn_8025E714(&object, lbl_802C8EDC);
}
}
