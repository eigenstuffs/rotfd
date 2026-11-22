typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();static void operator delete(void*p)throw();};
struct Node;struct Entry{Node*object;char gap04[8];signed char tag;char gap0D[3];signed char getTag()const{return tag;}};struct Manager{char gap00[8];Entry*entries;};
struct Scene{char gap00[0x1504C];int mode;};struct Lists{char gap00[0x1C8];};
extern "C"struct Context{char gap00[0x114];Lists*lists;Manager*manager;char gap11C[8];Scene*scene;char gap128[0x3C];void*service;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const void*,int);void*__dt__15Handle_801F7F10Fv(void*,short);}
inline void Handle_801F7F10::operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct RecordZero_800C2540:Handle_801F7F10{RecordZero_800C2540(){word=0;}~RecordZero_800C2540(){}};
struct Handle_80021BCC:RecordZero_800C2540{Handle_80021BCC(){word=0;}~Handle_80021BCC(){}};
struct Handle_8002F6B0:Handle_80021BCC{Handle_8002F6B0(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002F6B0(){}};
template<int D>struct ReturnLayer_800C2540:ReturnLayer_800C2540<D-1>{~ReturnLayer_800C2540(){}};template<>struct ReturnLayer_800C2540<1>:Handle_801F7F10{~ReturnLayer_800C2540(){}};
struct Handle_8003E120:ReturnLayer_800C2540<2>{~Handle_8003E120(){}};
struct NullHandle_800C2540{union{Word word;struct{signed int tag:8,index:24;}bits;};NullHandle_800C2540(){bits.index=0;bits.tag=0;}~NullHandle_800C2540(){__dt__15Handle_801F7F10Fv(this,-1);}};
struct Node{char gap00[0x7C];Handle_801F7F10 related;};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline Node*resolve(const NullHandle_800C2540&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline signed char same(const Handle_801F7F10&a,const NullHandle_800C2540&b){Node*left=resolve(a);return left==resolve(b);}
struct Record{char gap00[4];Handle_801F7F10 handle;char gap08[0x10];signed char flag18;char gap19[0xF];unsigned char active;};
extern "C"{Handle_8003E120 fn_800BCEF8(Scene*);void fn_800B720C(void*,int);void fn_801E2074(void*,const Handle_8002F6B0&,int);void fn_801E1F3C(void*,const Handle_8002F6B0&);void fn_80213A18(Record*);void fn_802139D8(Record*);}

extern "C" void fn_800C2540(Record*self){if(!self->flag18){if(same(resolve(fn_800BCEF8(lbl_801E9D24.scene))->related,NullHandle_800C2540()))fn_800B720C(lbl_801E9D24.service,1);{const Handle_801F7F10&original=self->handle;fn_801E2074((char*)lbl_801E9D24.lists+0x1C8,Handle_8002F6B0(original),1);}fn_80213A18(self);self->active=1;}}
