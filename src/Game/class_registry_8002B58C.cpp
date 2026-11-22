struct Agent_8002B5F4 {
    // Stack placement proves eight-byte alignment; this union only expresses storage.
    union { double alignment; unsigned char storage[0x90]; };
    Agent_8002B5F4();
    ~Agent_8002B5F4();
};
typedef void (Agent_8002B5F4::*MemberFunction)();
extern "C" {
extern unsigned long lbl_803775D0;
extern MemberFunction lbl_802B1568;
void fn_802598F4();
void fn_8025E714(Agent_8002B5F4*, MemberFunction);
void fn_8002B58C()
{
    lbl_803775D0 = 0;
    fn_802598F4();
    Agent_8002B5F4 object;
    fn_8025E714(&object, lbl_802B1568);
}
}
