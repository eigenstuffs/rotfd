typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{int count,capacity;Entry*entries;};struct GroupService{char unknown00[8];Handle_801F7F10*state;};extern "C"struct Context{char unknown00[0x118];Manager*manager;GroupService*groups;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);unsigned int fn_801F7EB8(const Handle_801F7F10*);extern const float lbl_80378420,lbl_8037845C;}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80027528:Handle_8001FF78{Handle_80027528(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80027528(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct NodePrefix{char unknown00[4];Handle_801F7F10 self;};
struct Node:NodePrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void reset40(int);Handle_801F7F10 child0C;char unknown10[0x10];Handle_801F7F10 child20;char unknown24[0xFC];Word flags120;char unknown124[0x2F1];unsigned char active415;};
struct Self{char unknown00[0x58];Handle_801F7F10 related58;char unknown5C[0x14];Handle_801F7F10 state70;};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
extern "C"{const Handle_801F7F10&fn_80268080(Node*,const Handle_80020B90&);void fn_801EDAAC(Node*,float,float,float);void fn_8025795C(Self*,int,int);}
extern "C"void fn_800389C8(Self*self){
 const Handle_801F7F10&original=self->related58;Handle_80020B90 parent(original);
 const Handle_801F7F10&oldSource=resolve(parent)->child20;Handle_80027528 previous(oldSource);
 resolve(parent)->flags120&=~0x40000UL;resolve(parent)->flags120|=0x10000UL;
 if(fn_801F7EB8(&previous))resolve(previous)->reset40(-1);
 const Handle_801F7F10&childSource=resolve(self->related58)->child0C;Handle_80020B90 current(childSource);
 if(fn_801F7EB8(&current)&&resolve(current)->flags120&0x80)fn_801EDAAC(resolve(fn_80268080(resolve(*lbl_801E9D24.groups->state),current)),lbl_80378420,lbl_80378420,lbl_8037845C);
 resolve(self->state70)->active415=0;fn_8025795C(self,1,0);
}
