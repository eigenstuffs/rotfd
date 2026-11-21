/* Handle event gating and temporary flag query; verified private layout views.
 * See docs/notes/game-early-handle-event-gates.md. */
typedef unsigned long Word;
struct Manager;
extern "C"struct Globals{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
extern "C"{void fn_801F86C8(Manager*,const void*,short);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];}
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct EventGateCopy_80045D28:Handle_80020478{EventGateCopy_80045D28(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~EventGateCopy_80045D28(){}};
struct FlagNode{char unknown00[0x38];unsigned long long flags;};
struct Entry{FlagNode*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];};
struct Manager{int count,capacity;Entry*entries;};
struct OwnerPrefix{Word unknown00,unknown04;};
struct Owner:OwnerPrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();char unknown0C[0x1C];Handle_801F7F10 target;};
extern "C"signed char fn_8025E9FC(Owner*,int);
inline FlagNode*resolve(const Handle_801F7F10&h){int index=h.bits.index;signed char tag=h.bits.tag;Entry*e=lbl_801E9D24.manager->entries+index;return e->tag==tag?e->object:0;}
inline bool eligible(const Handle_801F7F10&h){return (resolve(h)->flags&0x20000000ULL)==0;}
extern "C"void fn_80045D28(Owner*self){if(fn_8025E9FC(self,0x8A)){if(eligible(EventGateCopy_80045D28(self->target)))self->slot84();self->slot7C();}else if(fn_8025E9FC(self,0x8B)){if(eligible(EventGateCopy_80045D28(self->target)))self->slot84();self->slot7C();}}
