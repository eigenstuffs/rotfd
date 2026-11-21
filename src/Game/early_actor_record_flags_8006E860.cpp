extern "C" {extern char lbl_801EF5C8[],lbl_8028F698[];void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);}
struct Handle_801F7F10 {union{unsigned long value;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct CopyHandleLayer1_8006E860:Handle_801F7F10 {CopyHandleLayer1_8006E860(){value=0;}~CopyHandleLayer1_8006E860(){}};
struct CopyHandleLayer2_8006E860:CopyHandleLayer1_8006E860 {CopyHandleLayer2_8006E860(){value=0;}~CopyHandleLayer2_8006E860(){}};
struct CopyHandleLayer3_8006E860:CopyHandleLayer2_8006E860 {CopyHandleLayer3_8006E860(){value=0;}~CopyHandleLayer3_8006E860(){}};
struct Handle_80025BF4:CopyHandleLayer3_8006E860 {Handle_80025BF4(){value=0;}~Handle_80025BF4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct DispatchActor_8006E860;struct DispatchResource_8006E860;
struct DispatchEntry_8006E860 {DispatchActor_8006E860*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct DispatchManager_8006E860 {int count,capacity;DispatchEntry_8006E860*entries;};
struct DispatchResourceEntry_8006E860 {DispatchResource_8006E860*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getGeneration()const{return tag;}};
struct DispatchResourceManager_8006E860 {int count,capacity;DispatchResourceEntry_8006E860*entries;};
struct DispatchContext_8006E860 {char unknown00[0x118];DispatchManager_8006E860*manager;};
extern "C" {extern DispatchContext_8006E860 lbl_801E9D24;void fn_801F86C8(DispatchManager_8006E860*,const Handle_801F7F10*,int);}
struct Handle_80025B74:Handle_80025BF4 {Handle_80025B74(const Handle_80025B74&v){value=v.value;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_80025B74(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct RecordHandleLayer1_8006E860:Handle_801F7F10 {~RecordHandleLayer1_8006E860(){}};
struct RecordHandleLayer2_8006E860:RecordHandleLayer1_8006E860 {~RecordHandleLayer2_8006E860(){}};
struct RecordBase_8006E860 {int key;RecordHandleLayer2_8006E860 handle;float a,b,c,d;~RecordBase_8006E860(){}};
struct Record_8006E860:RecordBase_8006E860 {~Record_8006E860(){}};
struct Array_80025634 {int count,capacity;Record_8006E860*data;Array_80025634(const Array_80025634&);~Array_80025634(){if(data){for(int i=0;i<count;++i)data[i].~Record_8006E860();if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(Record_8006E860));data=0;}data=0;}}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct DispatchResource_8006E860 {char unknown00[0x4C];Array_80025634 array;char unknown58[0xC8];unsigned long flags;};
struct DispatchActor_8006E860 {char unknown00[0x16C];Handle_801F7F10 handle;};
struct OwnerPrefix_8006E860 {char unknown00[4];};
struct Owner_8006E860:OwnerPrefix_8006E860 {
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual const Handle_80025B74&getHandle28();};
inline DispatchActor_8006E860*resolveActor(const Handle_801F7F10&h){DispatchEntry_8006E860*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline DispatchResource_8006E860*resolveResource(const Handle_801F7F10&h){DispatchResourceManager_8006E860*m=(DispatchResourceManager_8006E860*)lbl_801E9D24.manager;DispatchResourceEntry_8006E860*e=&m->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
extern "C"void fn_8006E860(Owner_8006E860*self,signed char enabled){if(enabled){Array_80025634 records(resolveResource(resolveActor(Handle_80025B74(self->getHandle28()))->handle)->array);int index;for(short i=0;(index=i)<records.count;++i)resolveResource(records.data[index].handle)->flags|=0x40000;}else{Array_80025634 records(resolveResource(resolveActor(Handle_80025B74(self->getHandle28()))->handle)->array);int index;for(short i=0;(index=i)<records.count;++i)resolveResource(records.data[index].handle)->flags&=~(unsigned long)0x40000;}}
