struct ActivateHandle {signed int generation:8;signed int index:24;};
struct ActivateStorage {char unknown00[8];};
struct ActivateObject:ActivateStorage {virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual signed char activate();};
struct ActivateEntry {ActivateObject*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct ActivateManager {char unknown00[8];ActivateEntry*entries;};
struct ActivateOwner {char unknown00[0xB0];int count,capacity;ActivateHandle*handles;};
extern "C" {
extern struct {char unknown00[0x118];ActivateManager*manager;char unknown11C[4];void*world;}lbl_801E9D24;
signed char slot1C__12BaseObject_ZFv(void*);
const ActivateHandle*fn_8023A5DC(void*,const ActivateHandle*);
}
static inline ActivateObject*resolveActivate(const ActivateHandle&h){ActivateEntry*e=&lbl_801E9D24.manager->entries[h.index];if(e->generation==h.generation)return e->object;return 0;}
extern "C" signed char fn_80249BA8(ActivateOwner*self){
 if(!slot1C__12BaseObject_ZFv(self))return 0;
 for(int i=0;i<self->count;++i){
  resolveActivate(self->handles[i])->activate();
  resolveActivate(*fn_8023A5DC(lbl_801E9D24.world,&self->handles[i]))->activate();
 }
 return 1;
}
