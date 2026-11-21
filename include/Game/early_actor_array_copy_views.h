#ifndef GAME_EARLY_ACTOR_ARRAY_COPY_VIEWS_H
#define GAME_EARLY_ACTOR_ARRAY_COPY_VIEWS_H
extern "C" {extern char lbl_8028F698[],lbl_801EF5C8[];void*fn_8028FAF4(void*,void*,int,int);void*fn_8028FF24(void*,int);void fn_8028FD50(void*,void*,int);void fn_801EF610(void*,void*);}
inline void*operator new(unsigned long,void*p){return p;}
struct Handle_801F7F10{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct ArrayEntry;struct ArrayManager{int count,capacity;ArrayEntry*entries;};struct ArrayContext{char unknown00[0x118];ArrayManager*manager;};extern "C" ArrayContext lbl_801E9D24;extern "C" void fn_801F86C8(ArrayManager*,const Handle_801F7F10*,int);
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){value=0;}~Handle_8001FF78(){};static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ArrayRecordHandle:Handle_8001FF78{ArrayRecordHandle(const ArrayRecordHandle&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~ArrayRecordHandle(){}};
struct ArrayRecordBase{int key;ArrayRecordHandle handle;float a,b,c,d;ArrayRecordBase(const ArrayRecordBase&v):key(v.key),handle(v.handle),a(v.a),b(v.b),c(v.c),d(v.d){}~ArrayRecordBase(){}};
struct ArrayRecord:ArrayRecordBase{ArrayRecord(const ArrayRecord&v):ArrayRecordBase(v){}~ArrayRecord(){}};
struct Array_80025634;extern "C" void fn_80025898(Array_80025634*,int);
struct Array_80025634{int count,capacity;ArrayRecord*data;Array_80025634(const Array_80025634&);~Array_80025634(){if(data){for(int i=0;i<count;++i)data[i].~ArrayRecord();if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(ArrayRecord));data=0;}data=0;}}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
void grow(int n){if(capacity+n){if(data)data=(ArrayRecord*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(ArrayRecord),(capacity+n)*sizeof(ArrayRecord));else data=(ArrayRecord*)fn_8028FF24(lbl_8028F698,(capacity+n)*sizeof(ArrayRecord));}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(ArrayRecord));data=0;}capacity+=n;}
void append(const ArrayRecord&row){if(count+1>capacity)grow(32);new(&data[count++])ArrayRecord(row);}};
struct ArrayResource{char unknown00[0x4C];Array_80025634 array;char unknown58[0xC8];unsigned long flags;};struct ArrayEntry{ArrayResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
inline ArrayResource*resolveArray(const Handle_801F7F10&h){ArrayEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct ArrayActorRecord{char unknown00[8];int key;};struct ArrayActor{char unknown00[0x16C];Handle_801F7F10 handle;char unknown170[0x1A8];ArrayActorRecord record;char unknown324[0xE2];signed char enabled406,enabled407;};struct ArrayOwner{char unknown00[8];ArrayActor*actor;};struct ArrayMonitor{char unknown00[0x130];void*first,*second;};extern "C" {extern ArrayMonitor*lbl_803776B8;void fn_80068158(ArrayMonitor*,int);}
#endif
