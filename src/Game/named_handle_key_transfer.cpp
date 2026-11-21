/* Look up a named resource, retain its handle, and transfer the owner key. */
struct Handle_801F7F10 {
 union { unsigned long value; struct {signed int generation:8; signed int index:24;} bits; };
 Handle_801F7F10(); ~Handle_801F7F10();
};
struct NamedKeyHash {unsigned long value; NamedKeyHash(const char*);};
struct NamedKeyObject {char unknown00[0xC];unsigned long key;};
struct NamedKeyEntry {NamedKeyObject*object;unsigned long key,unknown08;signed char generation;char unknown0D[3];};
struct NamedKeyManager {int count,capacity;NamedKeyEntry*entries;};
extern "C" {
 extern struct {char unknown00[0x118];NamedKeyManager*manager;}lbl_801E9D24;
 extern const char lbl_802AEAE8[];
 unsigned long fn_801F948C(void*,const char*);
 void fn_801F86C8(NamedKeyManager*,const Handle_801F7F10*,short);
 Handle_801F7F10 fn_801B550C(NamedKeyManager*,const NamedKeyHash&,const NamedKeyHash&);
}
inline NamedKeyHash::NamedKeyHash(const char* s){value=fn_801F948C(this,s);}
struct NamedKeyZero1:Handle_801F7F10 {NamedKeyZero1(){value=0;}};
struct NamedKeyCopy:NamedKeyZero1 {NamedKeyCopy(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct NamedKeyZero2:NamedKeyZero1 {NamedKeyZero2(){value=0;}};
struct NamedKeyZero3:NamedKeyZero2 {NamedKeyZero3(){value=0;}};
struct NamedKeyOwned:NamedKeyZero3 {NamedKeyOwned(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct NamedKeyOwner {NamedKeyHash name;char unknown04[8];unsigned long key;};
inline void assignNamedKey(Handle_801F7F10&target,const NamedKeyCopy&source){fn_801F86C8(lbl_801E9D24.manager,&target,-1);target.value=source.value;fn_801F86C8(lbl_801E9D24.manager,&source,1);}
inline NamedKeyObject* resolveNamedKey(const Handle_801F7F10&h){NamedKeyEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->generation==h.bits.generation)return entry->object;return 0;}
extern "C" void fn_80248610(NamedKeyOwner*self,Handle_801F7F10&target){
 assignNamedKey(target,NamedKeyCopy(fn_801B550C(lbl_801E9D24.manager,NamedKeyHash(lbl_802AEAE8),self->name)));
 NamedKeyObject*object=resolveNamedKey(NamedKeyOwned(target));
 object->key=self->key;
}
