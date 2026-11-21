/* Checked actor and named resource setup; verified private layout views.
 * See docs/notes/game-early-actor-resource-setup.md. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct NodePrefix{Word unknown00,unknown04;};
struct Node:NodePrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40(int);virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const Handle_801F7F10*slot9C(int);char unknown0C[0x58];Handle_801F7F10 member64;char unknown68[8];Handle_801F7F10 actor;char unknown74[0x3C];Handle_801F7F10*child;char unknownB4[0x13C];Handle_801F7F10 member1F0;};
struct Entry{Node*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Related{char unknown00[0x1C];Handle_801F7F10*handle;};
extern "C"struct Globals{char unknown00[0x118];Manager*manager;char unknown11C[0x20];Related*related;}lbl_801E9D24;
extern "C"{void*fn_801F7EB8(const Handle_801F7F10*);void fn_801F86C8(Manager*,const Handle_801F7F10*,short);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];Word fn_801F948C(void*,const char*);extern const char lbl_8037975C[5];}
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline Node*actor(){const Handle_801F7F10&h=resolve(*resolve(*lbl_801E9D24.related->handle)->child)->actor;if(fn_801F7EB8(&h))return resolve(h);return 0;}
struct Handle_8002B67C:Handle_801F7F10{Handle_8002B67C(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002B67C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Return_800E079C:Handle_801F7F10{Return_800E079C();~Return_800E079C(){}};
struct Name{Word word;Name(const char*s){word=fn_801F948C(this,s);}};
extern "C"Return_800E079C fn_8024BDA0(Node*,const Name&);
inline Node*relatedChild(){const Handle_801F7F10&original=*lbl_801E9D24.related->handle;Handle_8002B67C h(original);if(fn_801F7EB8(&h)){const Handle_801F7F10&child=*resolve(h)->child;if(fn_801F7EB8(&child))return resolve(child);}return 0;}
struct Owner{char unknown00[0x10];Node*resource;Node*target;Node*actor;};
extern "C"void fn_800E079C(Owner*self){self->actor=actor();Node*resource=resolve(resolve(relatedChild()->member64)->member1F0);Name name(lbl_8037975C);self->resource=resolve(fn_8024BDA0(resource,name));self->target=resolve(*self->actor->slot9C(0));}
