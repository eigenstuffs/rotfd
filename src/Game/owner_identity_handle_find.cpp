// Native handle layers preserve construction, retention and cleanup.
struct Handle_801F7F10 {union {unsigned long value;struct {signed int generation:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct IdentityFindNativeHandle:Handle_801F7F10 {IdentityFindNativeHandle(){value=0;}};
struct IdentityFindHandle:IdentityFindNativeHandle {IdentityFindHandle(){value=0;}IdentityFindHandle(const IdentityFindHandle&);};
struct IdentityFindObject {void*identity;};
struct IdentityFindEntry {IdentityFindObject*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct IdentityFindManager {char unknown00[8];IdentityFindEntry*entries;};
struct IdentityFindOwner {char unknown00[0x20];int count,capacity;IdentityFindHandle*handles;};
extern "C" {
extern struct {char unknown00[0x118];IdentityFindManager*manager;}lbl_801E9D24;
void fn_801F86C8(void*,const void*,int);
void*fn_801F7EB8(const void*);
}
inline IdentityFindHandle::IdentityFindHandle(const IdentityFindHandle&input){value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}
static inline IdentityFindObject*resolveIdentityFind(const IdentityFindHandle&h){IdentityFindEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->generation==h.bits.generation)return e->object;return 0;}
extern "C" IdentityFindHandle fn_8024BDA0(IdentityFindOwner*self,void*const&identity){
 for(int i=0;i<self->count;++i){
  if(fn_801F7EB8(&self->handles[i])&&resolveIdentityFind(self->handles[i])->identity==identity)return self->handles[i];
 }
 return IdentityFindHandle();
}
