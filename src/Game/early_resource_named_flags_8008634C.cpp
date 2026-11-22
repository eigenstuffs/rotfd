typedef unsigned long Word;
extern "C"{extern char lbl_801EF5C8[],lbl_8028F698[],lbl_8029D6D4[],lbl_80378B34[];void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);Word fn_801F948C(void*,const char*);}
struct Handle_801F7F10{union{Word value;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct FlagHandle1_80086958:Handle_801F7F10{~FlagHandle1_80086958(){}};
struct FlagHandle2_80086958:FlagHandle1_80086958{~FlagHandle2_80086958(){}};
struct FlagRecordBase_80086958{int key;FlagHandle2_80086958 handle;float a,b,c,d;~FlagRecordBase_80086958(){}};
struct FlagRecord_80086958:FlagRecordBase_80086958{~FlagRecord_80086958(){}};
struct Array_80025634{int count,capacity;FlagRecord_80086958*data;Array_80025634(const Array_80025634&);~Array_80025634(){if(data){for(int i=0;i<count;++i)data[i].~FlagRecord_80086958();if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(FlagRecord_80086958));data=0;}data=0;}}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Name{Word value;Name(const char*s){value=fn_801F948C(this,s);}bool operator==(const Name&n)const{return value==n.value;}};
struct ArrayResource{char unknown0[0x4C];Array_80025634 array;};
struct NamedResource{Name name;};
struct FlaggedResource{char unknown0[0x120];Word flags;};
struct ArrayEntry{ArrayResource*object;char unknown4[8];signed char tag;char unknownD[3];signed char getTag()const{return tag;}};
struct NameEntry{NamedResource*object;char unknown4[8];signed char tag;char unknownD[3];};
struct FlagEntry{FlaggedResource*object;char unknown4[8];signed char tag;char unknownD[3];};
struct ArrayManager{int count,capacity;ArrayEntry*entries;};
struct NameManager{int count,capacity;NameEntry*entries;};
struct FlagManager{int count,capacity;FlagEntry*entries;};
struct ServicePrefix{char unknown0[0x1C];};
struct Service:ServicePrefix{
virtual void unknown08();
virtual void unknown0C();
virtual void unknown10();
virtual void unknown14();
virtual void unknown18();
virtual void unknown1C();
virtual void unknown20();
virtual void unknown24();
virtual void unknown28();
virtual void unknown2C();
virtual void unknown30();
virtual void unknown34();
virtual void action(int,int,int);
};
struct Globals{char unknown0[0x118];union{ArrayManager*manager;NameManager*nameManager;};char unknown11C[0x38];Service*service;};
extern "C"Globals lbl_801E9D24;
inline ArrayResource*resolveArray(const Handle_801F7F10&h){int index=h.bits.index;ArrayManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline NamedResource*resolveName(const Handle_801F7F10&h){NameEntry*e=&lbl_801E9D24.nameManager->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
inline FlaggedResource*resolveFlags(const Handle_801F7F10&h){FlagEntry*e=&((FlagManager*)lbl_801E9D24.nameManager)->entries[h.bits.index];return e->tag==h.bits.tag?e->object:0;}
struct Actor{char unknown0[0x30];unsigned long long flags;char unknown38[0x16C-0x38];Handle_801F7F10 array;char unknown170[0x320-0x170];int key;};
struct ControllerPrefix{char unknown0[8];};
struct Controller:ControllerPrefix{
virtual void unknown08();
virtual void unknown0C();
virtual void unknown10();
virtual void unknown14();
virtual void unknown18();
virtual void unknown1C();
virtual void unknown20();
virtual void unknown24();
virtual void unknown28();
virtual void unknown2C();
virtual void unknown30();
virtual void unknown34();
virtual void unknown38();
virtual void unknown3C();
virtual void unknown40();
virtual void unknown44();
virtual void unknown48();
virtual void unknown4C();
virtual void unknown50();
virtual void unknown54();
virtual void unknown58();
virtual void unknown5C();
virtual void unknown60();
virtual void unknown64();
virtual void select(int);char unknownC[0x88-0xC];signed char selected;
};
struct Owner{char unknown0[8];Actor*actor;Controller*controller;char unknown10[0x30];signed char enabled,previous;};
struct Monitor{char unknown0[0x130];void*first;};
extern "C"{extern Monitor*lbl_803776B8;void fn_8006803C(Monitor*,int);void fn_8025795C(Controller*,int,int);void fn_80257828(Controller*,int,int,int);}
extern "C"void fn_8008634C(Owner*self){Array_80025634 records(resolveArray(self->actor->array)->array);int index;for(short i=0;(index=i)<records.count;++i)if(resolveName(records.data[index].handle)->name==Name(lbl_8029D6D4))resolveFlags(records.data[index].handle)->flags|=0x40000;self->controller->select(0x83);fn_8025795C(self->controller,0x20,0);lbl_801E9D24.service->action(0,0x80,0);if(lbl_803776B8&&lbl_803776B8->first)fn_8006803C(lbl_803776B8,self->actor->key);}
