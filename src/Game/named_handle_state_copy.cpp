/* Named resource lookup followed by value and record-array transfer. */
struct Handle_801F7F10 {
 union { unsigned long value; struct {signed int generation:8; signed int index:24;} bits; };
 Handle_801F7F10(); ~Handle_801F7F10();
};
struct NamedStateHash {unsigned long value; NamedStateHash(const char*);};
struct NamedStateVector {float x,y,z,w;};
struct NamedStateArray {int count,capacity;void*items;};
struct NamedStateObject {char unknown00[0xC];unsigned long key;NamedStateVector values;unsigned long unknown20;NamedStateArray array24,array30;};
struct NamedStateEntry {NamedStateObject*object;unsigned long key,unknown08;signed char generation;char unknown0D[3];};
struct NamedStateManager {int count,capacity;NamedStateEntry*entries;};
extern "C" {
 extern struct {char unknown00[0x118];NamedStateManager*manager;}lbl_801E9D24;
 extern const char lbl_802AEAF8[];
 unsigned long fn_801F948C(void*,const char*);
 void fn_801F86C8(NamedStateManager*,const Handle_801F7F10*,short);
 Handle_801F7F10 fn_801B550C(NamedStateManager*,const NamedStateHash&,const NamedStateHash&);
}
inline NamedStateHash::NamedStateHash(const char* s){value=fn_801F948C(this,s);}
struct NamedStateZero1:Handle_801F7F10 {NamedStateZero1(){value=0;}};
struct NamedStateCopy:NamedStateZero1 {NamedStateCopy(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct NamedStateZero2:NamedStateZero1 {NamedStateZero2(){value=0;}};
struct NamedStateZero3:NamedStateZero2 {NamedStateZero3(){value=0;}};
struct NamedStateOwned:NamedStateZero3 {NamedStateOwned(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct NamedStateOwner {NamedStateHash name;char unknown04[8];unsigned long key;NamedStateVector values;unsigned long unknown20;NamedStateArray array24,array30;};
inline void assignNamedState(Handle_801F7F10&target,const NamedStateCopy&source){fn_801F86C8(lbl_801E9D24.manager,&target,-1);target.value=source.value;fn_801F86C8(lbl_801E9D24.manager,&source,1);}
inline NamedStateObject* resolveNamedState(const Handle_801F7F10&h){NamedStateEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->generation==h.bits.generation)return entry->object;return 0;}
extern "C" void fn_802495A0(NamedStateArray*,const NamedStateArray*);
extern "C" void fn_80249250(NamedStateArray*,const NamedStateArray*);
extern "C" void fn_8024906C(NamedStateOwner*self,Handle_801F7F10&target){
 assignNamedState(target,NamedStateCopy(fn_801B550C(lbl_801E9D24.manager,NamedStateHash(lbl_802AEAF8),self->name)));
 NamedStateObject*object=resolveNamedState(NamedStateOwned(target));
 NamedStateObject* data=resolveNamedState(target);
 data->values.x=self->values.x;data->values.y=self->values.y;data->values.z=self->values.z;data->values.w=self->values.w;
 object->key=self->key;
 fn_802495A0(&object->array30,&self->array30);
 fn_80249250(&object->array24,&self->array24);
}
