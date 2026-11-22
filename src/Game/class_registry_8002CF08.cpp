struct Agent_8002CF70 {
    // Stack placement proves eight-byte alignment; this union only expresses storage.
    union { double alignment; unsigned char storage[0x68]; };
    Agent_8002CF70();
    ~Agent_8002CF70();
};
typedef void (Agent_8002CF70::*MemberFunction)();
extern "C" {
extern unsigned long lbl_803775D8;
extern MemberFunction lbl_802B17C0;
void fn_8025CC04();
void fn_8025E714(Agent_8002CF70*, MemberFunction);
void fn_8002CF08()
{
    lbl_803775D8 = 0;
    fn_8025CC04();
    Agent_8002CF70 object;
    fn_8025E714(&object, lbl_802B17C0);
}
}
