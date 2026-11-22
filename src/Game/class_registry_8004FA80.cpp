struct Agent_8004FAE8 {
    // Stack placement proves eight-byte alignment; this union only expresses storage.
    union { double alignment; unsigned char storage[0x68]; };
    Agent_8004FAE8();
    ~Agent_8004FAE8();
};
typedef void (Agent_8004FAE8::*MemberFunction)();
extern "C" {
extern unsigned long lbl_80377680;
extern MemberFunction lbl_802B3FF8;
void fn_8025E31C();
void fn_8025E714(Agent_8004FAE8*, MemberFunction);
void fn_8004FA80()
{
    lbl_80377680 = 0;
    fn_8025E31C();
    Agent_8004FAE8 object;
    fn_8025E714(&object, lbl_802B3FF8);
}
}
