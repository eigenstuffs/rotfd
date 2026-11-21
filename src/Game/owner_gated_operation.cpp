struct GatedOperationHandle {signed int generation:8;signed int index:24;};
struct GatedOperationEntry {void*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct GatedOperationManager {char unknown00[8];GatedOperationEntry*entries;};
struct GatedOperationOwner {char unknown00[0x10];GatedOperationHandle handle;char unknown14[0xC8];int keys[4][8];char unknown15C[0x14];int counts[5];signed char active[5];};
extern "C" {extern struct {char unknown00[0x118];GatedOperationManager*manager;}lbl_801E9D24;extern const float lbl_8037B1DC;void*fn_801F7EB8(const void*);void fn_802073E8(GatedOperationOwner*,int,void*,float);}
static inline void*resolveGatedOperation(const GatedOperationHandle&h){GatedOperationEntry*e=&lbl_801E9D24.manager->entries[h.index];if(e->generation==h.generation)return e->object;return 0;}
extern "C" void fn_80231600(GatedOperationOwner*self,int index){
 if(!self->active[index]&&self->counts[index]&&self->keys[index][self->counts[index]]&&fn_801F7EB8(&self->handle)){
  fn_802073E8(self,self->keys[index][self->counts[index]],resolveGatedOperation(self->handle),lbl_8037B1DC);
  self->active[index]=1;
 }
}
