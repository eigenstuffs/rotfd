// Bounded lookup of the selected object and its related owner. The inline
// query keeps the copied handle alive through the native validity checks.
struct EarlyGetterObject;
struct Handle_801F7F10{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct EarlyGetterEntry{EarlyGetterObject*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct EarlyGetterManager{int count,capacity;EarlyGetterEntry*entries;};
struct EarlyGetterSelection{char unknown00[0x1C];Handle_801F7F10*current;};
struct EarlyGetterContext{char unknown00[0x118];EarlyGetterManager*manager;char unknown11C[0x20];EarlyGetterSelection*selection;};
extern "C" {extern EarlyGetterContext lbl_801E9D24;void fn_801F86C8(EarlyGetterManager*,const Handle_801F7F10*,short);EarlyGetterObject*fn_801F7EB8(const Handle_801F7F10*);}
extern "C" {extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Handle_8002B67C:Handle_801F7F10{static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}Handle_8002B67C(const Handle_801F7F10&handle){value=handle.value;fn_801F86C8(lbl_801E9D24.manager,&handle,1);}~Handle_8002B67C(){}};
struct EarlyGetterObject{char unknown00[0xB0];Handle_801F7F10*owner;};
inline EarlyGetterObject*resolveEarlyGetter(const Handle_801F7F10&handle){EarlyGetterEntry*entry=&lbl_801E9D24.manager->entries[handle.bits.index];if(entry->tag==handle.bits.tag)return entry->object;return 0;}

inline void*getCurrentOwner_8005E9A0(){Handle_8002B67C handle(*lbl_801E9D24.selection->current);if(fn_801F7EB8(&handle)){Handle_801F7F10*owner=resolveEarlyGetter(handle)->owner;if(fn_801F7EB8(owner))return resolveEarlyGetter(*owner);}return 0;}
extern "C" void*fn_8005E9A0(){return getCurrentOwner_8005E9A0();}
