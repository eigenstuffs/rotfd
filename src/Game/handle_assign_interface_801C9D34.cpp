struct HandleAssignPrefix_801C9D34 { unsigned int value; };
struct HandleAssignInterface_801C9D34 : HandleAssignPrefix_801C9D34 {
    virtual void assign(unsigned int *);
    virtual void hook0();
    virtual void hook1();
    virtual void hook2();
    virtual void hook3();
};
extern "C" {
extern struct HandleAssignGlobals_801C9D34 { char unknown[0x118]; void *manager; } lbl_801E9D24;
void fn_801F86C8(void *, void *, int);
}
void HandleAssignInterface_801C9D34::hook0() {}
void HandleAssignInterface_801C9D34::hook1() {}
void HandleAssignInterface_801C9D34::hook2() {}
void HandleAssignInterface_801C9D34::hook3() {}
void HandleAssignInterface_801C9D34::assign(unsigned int *handle) {
    fn_801F86C8(lbl_801E9D24.manager, this, -1);
    value = *handle;
    fn_801F86C8(lbl_801E9D24.manager, handle, 1);
}
typedef char CheckHandleAssignInterface[sizeof(HandleAssignInterface_801C9D34) == 8 ? 1 : -1];
