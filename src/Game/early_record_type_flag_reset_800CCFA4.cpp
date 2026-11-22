extern "C" {extern char lbl_801EF5C8[],lbl_8028F698[];void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);}
struct Handle_801F7F10 {union{unsigned long value;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct CopyHandleLayer1_800CCFA4:Handle_801F7F10 {CopyHandleLayer1_800CCFA4(){value=0;}~CopyHandleLayer1_800CCFA4(){}};
struct CopyHandleLayer2_800CCFA4:CopyHandleLayer1_800CCFA4 {CopyHandleLayer2_800CCFA4(){value=0;}~CopyHandleLayer2_800CCFA4(){}};
struct CopyHandleLayer3_800CCFA4:CopyHandleLayer2_800CCFA4 {CopyHandleLayer3_800CCFA4(){value=0;}~CopyHandleLayer3_800CCFA4(){}};
struct Handle_80025BF4:CopyHandleLayer3_800CCFA4 {Handle_80025BF4(){value=0;}~Handle_80025BF4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct DispatchActor_800CCFA4;struct DispatchResource_800CCFA4;
struct DispatchEntry_800CCFA4 {DispatchActor_800CCFA4*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct DispatchManager_800CCFA4 {int count,capacity;DispatchEntry_800CCFA4*entries;};
struct DispatchResourceEntry_800CCFA4 {DispatchResource_800CCFA4*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getGeneration()const{return tag;}};
struct DispatchResourceManager_800CCFA4 {int count,capacity;DispatchResourceEntry_800CCFA4*entries;};
struct DispatchContext_800CCFA4 {char unknown00[0x118];DispatchManager_800CCFA4*manager;};
extern "C" {extern DispatchContext_800CCFA4 lbl_801E9D24;void fn_801F86C8(DispatchManager_800CCFA4*,const Handle_801F7F10*,int);}
struct Handle_80025B74:Handle_80025BF4 {Handle_80025B74(const Handle_80025B74&v){value=v.value;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_80025B74(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct RecordHandleLayer1_800CCFA4:Handle_801F7F10 {~RecordHandleLayer1_800CCFA4(){}};
struct RecordHandleLayer2_800CCFA4:RecordHandleLayer1_800CCFA4 {~RecordHandleLayer2_800CCFA4(){}};
struct RecordBase_800CCFA4 {int key;RecordHandleLayer2_800CCFA4 handle;float a,b,c,d;~RecordBase_800CCFA4(){}};
struct Record_800CCFA4:RecordBase_800CCFA4 {~Record_800CCFA4(){}};
struct Array_80025634 {int count,capacity;Record_800CCFA4*data;Array_80025634(const Array_80025634&);~Array_80025634(){if(data){for(int i=0;i<count;++i)data[i].~Record_800CCFA4();if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(Record_800CCFA4));data=0;}data=0;}}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct DispatchResource_800CCFA4 {char unknown00[0x2C];Handle_801F7F10 child;char unknown30[0x1C];Array_80025634 array;char unknown58[0xC8];unsigned long flags;};
struct DispatchActor_800CCFA4 {char unknown00[0x30];unsigned long long flags;char unknown38[0x134];Handle_801F7F10 handle;};
struct Owner{char unknown00[0x58];Handle_801F7F10 handle;char unknown5C[0x14];Handle_80025B74 actor;char unknown74[0x16];short type;};
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){value=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8002BA20:Handle_8001FF78{Handle_8002BA20(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002BA20(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
inline DispatchActor_800CCFA4*resolveActor(const Handle_801F7F10&h){DispatchEntry_800CCFA4*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline DispatchResource_800CCFA4*resolveResource(const Handle_801F7F10&h){DispatchResourceManager_800CCFA4*m=(DispatchResourceManager_800CCFA4*)lbl_801E9D24.manager;DispatchResourceEntry_800CCFA4*e=&m->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
extern "C"{extern const char lbl_803796D8[2],lbl_803796DC[2],lbl_803796E0[2],lbl_803796E4[2],lbl_802A2A10[10];void fn_8002B824(Owner*,const Handle_801F7F10&);const char*fn_8025318C(DispatchResource_800CCFA4*,unsigned long*);int strcmp(const char*,const char*);void*fn_801F7EB8(const Handle_801F7F10*);}
extern "C"void fn_800CCFA4(Owner*self,const Handle_801F7F10&argument){
 const Handle_80025B74&original=self->actor;
 Array_80025634 records(resolveResource(resolveActor(Handle_80025B74(original))->handle)->array);
 int recordIndex;for(short i=0;(recordIndex=i)<records.count;++i)resolveResource(records.data[recordIndex].handle)->flags|=0x40000;
 fn_8002B824(self,argument);
 Handle_8002BA20 related(resolveResource(self->handle)->child);
 if(fn_801F7EB8(&related)){
 unsigned long key;const char*name=fn_8025318C(resolveResource(related),&key);
 if(strcmp(name,lbl_803796D8)==0)self->type=5;
 else if(strcmp(name,lbl_803796DC)==0)self->type=4;
 else if(strcmp(name,lbl_803796E0)==0)self->type=3;
 else if(strcmp(name,lbl_803796E4)==0)self->type=2;
 else if(strcmp(name,lbl_802A2A10)==0){resolveResource(self->handle)->flags&=~0x40000;self->type=1;}
 else self->type=1;
 }
 resolveResource(self->handle)->flags|=0x10000;
 resolveResource(self->handle)->flags&=~0x40000;
 resolveActor(self->actor)->flags&=~0x400ULL;
}
