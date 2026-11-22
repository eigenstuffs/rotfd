typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};~Handle_801F7F10();};
struct NestedEHHandle1:Handle_801F7F10{};struct NestedEHHandle2:NestedEHHandle1{};
extern "C"{extern char lbl_801EF5C8[],lbl_8028F698[];void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);extern const float lbl_80378514;}
struct Array_80039AEC{int count,capacity;NestedEHHandle2*data;Array_80039AEC():count(0),capacity(0),data(0){}~Array_80039AEC(){if(data){for(int i=0;i<count;++i)data[i].~NestedEHHandle2();if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(NestedEHHandle2));data=0;}data=0;}}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Node{char unknown00[0x130];Handle_801F7F10 target;};
struct Entry{Node*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{int count,capacity;Entry*entries;};
struct Service{char unknown00[0x860];int count;};struct Context{char unknown00[8];Handle_801F7F10*handle;};
extern "C"struct Globals{char unknown00[0x110];Service*service;char unknown114[4];Manager*manager;Context*context;}lbl_801E9D24;
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline Word resolveWord(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?(Word)m->entries[index].object:0;}
extern "C"{int fn_8026A128(Node*,Array_80039AEC*,int);void fn_802073E8(Node*,int,Node*,float);}
extern "C"int fn_8003F5F4(){if(lbl_801E9D24.service->count<1)return 0;Array_80039AEC handles;fn_8026A128((Node*)resolveWord(*lbl_801E9D24.context->handle),&handles,14);if(handles.count!=1)return 0;Node*target=(Node*)resolveWord(resolve(handles.data[0])->target);fn_802073E8(target,0x8F,(Node*)resolveWord(resolve(handles.data[0])->target),lbl_80378514);return 1;}
