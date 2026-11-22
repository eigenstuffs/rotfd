struct Agent_80035294 {
    // Stack placement proves eight-byte alignment; this union only expresses storage.
    union { double alignment; unsigned char storage[0x88]; };
    Agent_80035294();
    ~Agent_80035294();
};
typedef void (Agent_80035294::*MemberFunction)();
extern "C" {
extern unsigned long lbl_803775E8;
extern MemberFunction lbl_802B1D08;
void fn_8025BCC4();
void fn_8025E714(Agent_80035294*, MemberFunction);
void fn_8003522C()
{
    lbl_803775E8 = 0;
    fn_8025BCC4();
    Agent_80035294 object;
    fn_8025E714(&object, lbl_802B1D08);
}
}
