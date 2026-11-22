struct Agent_80061AC0 {
    union { double alignment; unsigned char storage[0x200]; };
    Agent_80061AC0();
    ~Agent_80061AC0();
};
typedef void (Agent_80061AC0::*MemberFunction)();
extern "C" {
extern unsigned long lbl_80377700;
extern MemberFunction lbl_802B6028;
extern MemberFunction lbl_802B6034;
void fn_80256448();
void fn_8025E714(Agent_80061AC0*, MemberFunction);
void fn_80061A2C() {
    lbl_80377700=0;
    fn_80256448();
    Agent_80061AC0 object;
    fn_8025E714(&object, lbl_802B6028);
    fn_8025E714(&object, lbl_802B6034);
}
}
