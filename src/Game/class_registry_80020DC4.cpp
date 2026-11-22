struct Agent_80021260 {
    union { double alignment; unsigned char storage[0xc0]; };
    Agent_80021260();
    ~Agent_80021260();
};
typedef void (Agent_80021260::*MemberFunction)();
extern "C" {
extern unsigned long lbl_80377558;
extern MemberFunction lbl_802AFBA0;
extern MemberFunction lbl_802AFBAC;
void fn_8025959C();
void fn_8025E714(Agent_80021260*, MemberFunction);
void fn_80020DC4() {
    lbl_80377558=0;
    fn_8025959C();
    Agent_80021260 object;
    fn_8025E714(&object, lbl_802AFBA0);
    fn_8025E714(&object, lbl_802AFBAC);
}
}
