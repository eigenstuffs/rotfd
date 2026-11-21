/* Log, forward the target Handle, reset the actor's control byte, then create a
 * named Handle under the resolved target and keep its object at +0x88.
 * The target Handle is a non-const reference: with const& the compiler hoists
 * its loads above the temporary Handle_80020B90 zero stores (native keeps them
 * after). The comma expression sequences the parent resolve after the context
 * Handle and before the two Names (same idiom as named_handle_list_setup_80059D58).
 */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Object{char opaque[0x1F8];char control;};
struct Entry{Object*object;char opaque4[8];signed char tag;char opaqueD[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Globals{char opaque[0x110];void*logger;char opaque114[4];Manager*manager;};
extern "C"{extern Globals lbl_801E9D24;extern char lbl_801EF5C8[];extern const char lbl_8029CA48[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const void*,int);Word fn_801F948C(void*,const char*);void fn_801FA014(void*,const char*,...);void fn_8007D6A0(void*,int);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(){word=0;}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{Handle_80020834(){word=0;}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80024844:Handle_80020834{Handle_80024844(){word=0;}Handle_80024844(const Handle_80020834&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80024844(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Name { Word word; Name(const char*text) { word=fn_801F948C(this,text); } };
extern "C" Handle_80020834 fn_801FCF20(Object*,const Name&,Name,const Handle_80020B90&);
inline Object*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct ActorPrefix{char opaque[8];};
struct Actor:ActorPrefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void reset34();
 virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void event68(int);
 char opaque0C[0x70-0xC];Handle_801F7F10 actor;char opaque74[0x88-0x74];Object*target;
};
extern "C" void fn_8025A0A4(Actor*,const Handle_801F7F10&);
extern "C" void fn_80073BE0(Actor*self,Handle_801F7F10&handle){
    const char*strings=lbl_8029CA48;
    fn_801FA014(lbl_801E9D24.logger,strings+0x10);
    fn_8025A0A4(self,handle);
    fn_8007D6A0(&resolve(self->actor)->control,0);
    self->reset34();
    self->event68(0x87);
    Object*parent;
    Handle_80024844 h(fn_801FCF20((parent=resolve(handle),parent),Name(strings+0x28),Name(strings+0x44),Handle_80020B90()));
    self->target=resolve(h);
}
