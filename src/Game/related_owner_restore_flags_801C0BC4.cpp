/* fn_801C0BC4 / fn_801C0CC8: after the base save/restore call, resolve the
   owner handle at +0x1F8, ask it (vtable slot 0x9C) for a related handle and
   move one state flag of that object into the other (0x4000 <-> 0x40000). */
struct Handle{union{unsigned long word;struct{signed int tag:8,index:24;}bits;};};
struct Prefix{char unknown00[8];};
struct Target{
char unknown00[0x120];unsigned long flags;
/* The original flag read is a separate load of the same word; a distinct
   read form keeps the compiler from CSEing it with the read-modify-write. */
bool testFlag(unsigned long mask)const{return(*(const unsigned long*)&flags&mask)!=0;}
void orFlag(unsigned long mask,bool on){flags=flags|(on?mask:0);}
void clearFlag(unsigned long mask){flags&=~mask;}
};
struct Owner:Prefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();
virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();
virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();
virtual void slot98();virtual Handle*slot9C(int);
};
struct Self{char unknown00[0x1F8];Handle owner;};
struct Entry{void*object;unsigned long unknown04,unknown08;signed char tag;char pad[3];};
struct Manager{char unknown00[8];Entry*entries;};
struct Global{char unknown00[0x118];Manager*manager;};
extern "C" Global lbl_801E9D24;
inline void*resolve(const Handle&h){Entry*e=lbl_801E9D24.manager->entries+h.bits.index;if(e->tag==h.bits.tag)return e->object;return 0;}
extern "C"{void fn_801C234C(Self*);void fn_801C2520(Self*);}
extern "C" void fn_801C0BC4(Self*self){
fn_801C234C(self);
Owner*owner=(Owner*)resolve(self->owner);
if(owner){Target*t=(Target*)resolve(*owner->slot9C(0));
t->orFlag(0x40000,t->testFlag(0x4000));
t->clearFlag(0x4000);}
}
extern "C" void fn_801C0CC8(Self*self){
fn_801C2520(self);
Owner*owner=(Owner*)resolve(self->owner);
if(owner){Target*t=(Target*)resolve(*owner->slot9C(0));
t->orFlag(0x4000,t->testFlag(0x40000));
t->clearFlag(0x40000);}
}
