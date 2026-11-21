// Bounded four-byte native handle result. The slot resolver retains its
// owner and index as typed inputs while the selected handle is copied by value.
struct AvailableHandleIndex{int value;AvailableHandleIndex(int v):value(v){}operator const int&()const{return value;}};
typedef unsigned long Word;
struct Handle_801F7F10 {union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct AvailableHandleNode;
struct AvailableHandleEntry{AvailableHandleNode*object;char opaque4[8];signed char tag;char opaqueD[3];bool matchesTag(signed char t)const{return tag==t;}};
struct AvailableHandleEntries{AvailableHandleEntry*p;AvailableHandleEntry&operator[](int i)const{return p[i];}};
struct AvailableHandleManager{int count,capacity;AvailableHandleEntries entries;};
struct AvailableHandleGlobals{char opaque[0x118];AvailableHandleManager*manager;};
extern "C"{extern AvailableHandleGlobals lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(AvailableHandleManager*,const Handle_801F7F10*,short);AvailableHandleNode*fn_801F7EB8(const Handle_801F7F10*);signed char fn_80255618(AvailableHandleNode*);}
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{Handle_80020834(){word=0;}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct AvailableHandleResult_80059AA4:Handle_80020834{AvailableHandleResult_80059AA4(){word=0;}AvailableHandleResult_80059AA4(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~AvailableHandleResult_80059AA4(){}};
struct AvailableHandleOwner{char opaque[0x28C];Handle_801F7F10 slots[10];};
extern "C"void fn_80059BA8(AvailableHandleOwner*);
inline AvailableHandleNode*resolveAvailableHandleSlot_80059AA4(AvailableHandleOwner*self,int i){AvailableHandleManager*m=lbl_801E9D24.manager;const AvailableHandleIndex index(self->slots[i].bits.index);signed char tag=self->slots[i].bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
extern "C" AvailableHandleResult_80059AA4 fn_80059AA4(AvailableHandleOwner*self){if(!fn_801F7EB8(&self->slots[0]))fn_80059BA8(self);for(int i=0;i<10;i++){if(fn_80255618(resolveAvailableHandleSlot_80059AA4(self,i)))return AvailableHandleResult_80059AA4(self->slots[i]);}return AvailableHandleResult_80059AA4();}
