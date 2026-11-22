struct CActorScriptAgent {
    // Stack placement proves eight-byte alignment; this union only expresses storage.
    union { double alignment; unsigned char storage[0x200]; };
    CActorScriptAgent();
    ~CActorScriptAgent();
};
typedef void (CActorScriptAgent::*MemberFunction)();
extern "C" {
extern unsigned long lbl_80377708;
extern MemberFunction lbl_802B6270;
void fn_8002B58C();
void fn_8025E714(CActorScriptAgent*, MemberFunction);
void fn_80062DB0()
{
    lbl_80377708 = 0;
    fn_8002B58C();
    CActorScriptAgent object;
    fn_8025E714(&object, lbl_802B6270);
}
}
