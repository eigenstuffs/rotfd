/* Original scene Handle collection and filtering; see docs/notes/game-engine-scene-handle-collect.md. */
typedef unsigned long u32;
struct Handle_801F7F10{union{u32 word;struct{signed int tag:8,index:24;}bits;};~Handle_801F7F10();};
struct NestedEHHandle1:Handle_801F7F10{};struct NestedEHHandle2:NestedEHHandle1{};
extern "C"{extern char lbl_801EF5C8[],lbl_8028F698[];void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);}
struct Array_80039AEC{int count,capacity;NestedEHHandle2*data;Array_80039AEC():count(0),capacity(0),data(0){}~Array_80039AEC(){if(data){for(int i=0;i<count;++i)data[i].~NestedEHHandle2();if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(NestedEHHandle2));data=0;}data=0;}}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Node{char opaque00[0xC];Handle_801F7F10 next0C;char opaque10[0x110];u32 flags120;};
struct Entry{Node*object;u32 opaque04,opaque08;signed char generation;char opaque0D[3];};struct Manager{char opaque00[8];Entry*entries;};
struct Service{char opaque00[0x1C];Handle_801F7F10*state1C;};
extern "C" struct Global{char opaque00[0x118];Manager*manager118;char opaque11C[0x20];Service*service13C;}lbl_801E9D24;
inline Node*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager118->entries[h.bits.index];return e->generation==h.bits.tag?e->object:0;}
inline Node*resolveAlternate(const Handle_801F7F10&h){struct ByteRegistry{char opaque00[8];char*entries;};Entry*e=(Entry*)(((ByteRegistry*)lbl_801E9D24.manager118)->entries+h.bits.index*16);return e->generation==h.bits.tag?e->object:0;}
struct Owner{char opaque00[0x8C];Node*objects8C[20];int countDC;};
extern "C"{signed char fn_8025E9FC(Owner*,int);int fn_8026A128(Node*,Array_80039AEC*,int);}
extern "C" void fn_800398B8(Owner*self){fn_8025E9FC(self,0xE1);if(fn_8025E9FC(self,0x51)||fn_8025E9FC(self,0x52)){self->countDC=0;Array_80039AEC handles;int count=fn_8026A128(resolveAlternate(resolve(*lbl_801E9D24.service13C->state1C)->next0C),&handles,5);for(int i=0;i<count;++i){if(resolve(handles.data[i])->flags120&0x02000000){self->objects8C[self->countDC]=resolveAlternate(handles.data[i]);self->countDC++;}}}}
