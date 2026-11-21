// Native handle layers preserve construction, retention and cleanup.
struct Handle_801F7F10 {union {unsigned long value;struct {signed int generation:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct ParentApplyNativeHandle:Handle_801F7F10 {ParentApplyNativeHandle(){value=0;}};
struct ParentApplyHandle:ParentApplyNativeHandle {ParentApplyHandle(const ParentApplyHandle&);};
struct ParentApplyOwner {char unknown00[0xC];ParentApplyHandle parent;};
struct ParentApplyEntry {ParentApplyOwner*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct ParentApplyManager {char unknown00[8];ParentApplyEntry*entries;};
extern "C" {
extern struct {char unknown00[0x118];ParentApplyManager*manager;}lbl_801E9D24;
void fn_801F86C8(void*,const void*,int);
void fn_802408BC(ParentApplyOwner*,const ParentApplyHandle&,void*);
}
inline ParentApplyHandle::ParentApplyHandle(const ParentApplyHandle&input){value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}
static inline ParentApplyOwner*resolveParentApply(const ParentApplyHandle&h){ParentApplyEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->generation==h.bits.generation)return e->object;return 0;}
extern "C" void fn_80240E50(ParentApplyOwner*self,const ParentApplyHandle&input,void*argument){
 ParentApplyHandle handle(input);
 fn_802408BC(resolveParentApply(self->parent),handle,argument);
}
