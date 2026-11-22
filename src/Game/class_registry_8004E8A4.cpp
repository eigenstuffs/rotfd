struct Agent_8004E90C {
    // Stack placement proves eight-byte alignment; this union only expresses storage.
    union { double alignment; unsigned char storage[0x78]; };
    Agent_8004E90C();
    ~Agent_8004E90C();
};
typedef void (Agent_8004E90C::*MemberFunction)();
extern "C" {
extern unsigned long lbl_80377674;
extern MemberFunction lbl_802B3F30;
void fn_8025E31C();
void fn_8025E714(Agent_8004E90C*, MemberFunction);
void fn_8004E8A4()
{
    lbl_80377674 = 0;
    fn_8025E31C();
    Agent_8004E90C object;
    fn_8025E714(&object, lbl_802B3F30);
}
}
