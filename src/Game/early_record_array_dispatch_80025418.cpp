extern "C" {extern char lbl_801EF5C8[],lbl_8028F698[];void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);}
struct Handle_801F7F10 {union{unsigned long value;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct CopyHandleLayer1_80025418:Handle_801F7F10 {CopyHandleLayer1_80025418(){value=0;}~CopyHandleLayer1_80025418(){}};
struct CopyHandleLayer2_80025418:CopyHandleLayer1_80025418 {CopyHandleLayer2_80025418(){value=0;}~CopyHandleLayer2_80025418(){}};
struct CopyHandleLayer3_80025418:CopyHandleLayer2_80025418 {CopyHandleLayer3_80025418(){value=0;}~CopyHandleLayer3_80025418(){}};
struct Handle_80025BF4:CopyHandleLayer3_80025418 {Handle_80025BF4(){value=0;}~Handle_80025BF4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct DispatchActor_80025418;struct DispatchResource_80025418;
struct DispatchEntry_80025418 {DispatchActor_80025418*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct DispatchManager_80025418 {int count,capacity;DispatchEntry_80025418*entries;};
struct DispatchResourceEntry_80025418 {DispatchResource_80025418*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getGeneration()const{return tag;}};
struct DispatchResourceManager_80025418 {int count,capacity;DispatchResourceEntry_80025418*entries;};
struct DispatchContext_80025418 {char unknown00[0x118];DispatchManager_80025418*manager;};
extern "C" {extern DispatchContext_80025418 lbl_801E9D24;void fn_801F86C8(DispatchManager_80025418*,const Handle_801F7F10*,int);}
struct Handle_80025B74:Handle_80025BF4 {Handle_80025B74(const Handle_80025B74&v){value=v.value;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_80025B74(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct RecordHandleLayer1_80025418:Handle_801F7F10 {~RecordHandleLayer1_80025418(){}};
struct RecordHandleLayer2_80025418:RecordHandleLayer1_80025418 {~RecordHandleLayer2_80025418(){}};
struct RecordBase_80025418 {int key;RecordHandleLayer2_80025418 handle;float a,b,c,d;~RecordBase_80025418(){}};
struct Record_80025418:RecordBase_80025418 {~Record_80025418(){}};
struct Array_80025634 {int count,capacity;Record_80025418*data;Array_80025634(const Array_80025634&);~Array_80025634(){if(data){for(int i=0;i<count;++i)data[i].~Record_80025418();if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(Record_80025418));data=0;}data=0;}}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct DispatchResource_80025418 {char unknown00[0x4C];Array_80025634 array;char unknown58[0xC8];unsigned long flags;};
struct DispatchActor_80025418 {char unknown00[0x16C];Handle_801F7F10 handle;};
struct DispatchOwnerPrefix_80025418 {char unknown00[8];};
struct DispatchOwner_80025418:DispatchOwnerPrefix_80025418 {
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void apply(void*);char unknown0C[0x64];Handle_80025B74 handle;};
typedef char DispatchOwnerSize_80025418[sizeof(DispatchOwner_80025418)==0x74?1:-1];
inline DispatchActor_80025418*resolveActor_80025418(const Handle_801F7F10&h){DispatchEntry_80025418*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline DispatchResource_80025418*resolveResource_80025418(const Handle_801F7F10&h){DispatchResourceManager_80025418*m=(DispatchResourceManager_80025418*)lbl_801E9D24.manager;DispatchResourceEntry_80025418*e=&m->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
extern "C" void fn_80025418(DispatchOwner_80025418*self,void*argument){
 const Handle_80025B74&original=self->handle;
 Array_80025634 records(resolveResource_80025418(resolveActor_80025418(Handle_80025B74(original))->handle)->array);
 int recordIndex;for(short i=0;(recordIndex=i)<records.count;++i)resolveResource_80025418(records.data[recordIndex].handle)->flags|=0x40000;
 self->apply(argument);
}
