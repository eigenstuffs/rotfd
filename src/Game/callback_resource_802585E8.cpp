typedef unsigned long u32;
struct NativeHandle {u32 value;};
extern "C" {extern struct {char unknown0[0x118];void *manager;} lbl_801E9D24;void fn_801F86C8(void*,const NativeHandle*,short);}
struct View {char unknown0[16];NativeHandle handle;};
extern "C" void fn_802585E8(View *self,const NativeHandle*value) {
 fn_801F86C8(lbl_801E9D24.manager,&self->handle,-1);
 self->handle.value=value->value;
 fn_801F86C8(lbl_801E9D24.manager,value,1);
}
