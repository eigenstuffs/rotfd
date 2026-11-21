/* Retain the first active mode resource, falling back to the first slot. */
struct HandleIndex{int value;HandleIndex(int v):value(v){}operator const int&()const{return value;}};
typedef unsigned long Word;
struct Handle_801F7F10{union{Word value;struct{signed int generation:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Entry{void*object;char unknown04[8];signed char generation;char unknown0D[3];bool matchesTag(signed char t)const{return generation==t;}};struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};struct Manager{int count,capacity;EntryArray entries;};struct Context{char unknown00[0x118];Manager*manager;};extern "C"{extern Context lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10&,short);void*fn_801F7EB8(Handle_801F7F10*);signed char fn_80255618(const void*);}
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){value=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{Handle_80020834(){value=0;}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80024844:Handle_80020834{Handle_80024844(){value=0;}Handle_80024844(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,h,1);}~Handle_80024844(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Mode{char unknown00[0x2B4];Handle_801F7F10 handles[5];};extern "C" void fn_8005848C(Mode*);
inline void*resolveMode(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;const HandleIndex index(h.bits.index);signed char tag=h.bits.generation;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
extern "C" Handle_80024844 fn_8005863C(Mode*self){if(!fn_801F7EB8(&self->handles[0]))fn_8005848C(self);int i;for(i=0;i<5;i++){if(fn_80255618(resolveMode(self->handles[i])))return Handle_80024844(self->handles[i]);}if(i==5)return Handle_80024844(self->handles[0]);return Handle_80024844();}
