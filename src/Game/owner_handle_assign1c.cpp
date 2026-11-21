struct AssignHandle {unsigned long value;};
struct AssignOwner {char unknown00[0x1C];AssignHandle handle;};
extern "C" {extern struct {char unknown00[0x118];void*manager;}lbl_801E9D24;void fn_801F86C8(void*,const void*,int);void fn_8023D648(AssignOwner*);}
extern "C" void fn_8023EE7C(AssignOwner*self,const AssignHandle&input){fn_801F86C8(lbl_801E9D24.manager,&self->handle,-1);self->handle.value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);fn_8023D648(self);}
