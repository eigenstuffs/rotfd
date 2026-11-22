typedef unsigned long Word;
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct NodePrefix{Word unknown00,unknown04;};
struct Node:NodePrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40(int);virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const Handle*slot9C(int);char unknown0C[0x14];Handle member20;char unknown24[0x4C];Handle actor;char unknown74[0x3C];Handle*child;char unknownB4[0x6C];Word flags;char unknown124[0x88];Handle nested;};
struct Entry{Node*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Related{char unknown00[0x1C];Handle*handle;};
extern "C"struct Globals{char unknown00[0x118];Manager*manager;char unknown11C[0x20];Related*related;}lbl_801E9D24;
extern "C"{void*fn_801F7EB8(const Handle*);void fn_80057E40(void*);}
inline Node*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline Node*actor(){const Handle&h=resolve(*resolve(*lbl_801E9D24.related->handle)->child)->actor;if(fn_801F7EB8(&h))return resolve(h);return 0;}
extern "C"void fn_8005AD94(void*self){if(fn_801F7EB8(&actor()->nested)){Node*owner=resolve(actor()->nested);resolve(resolve(*owner->slot9C(0))->member20)->slot40(-1);resolve(*owner->slot9C(0))->flags|=0x10000UL;fn_80057E40(self);}}
