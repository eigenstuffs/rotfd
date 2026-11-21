/* Create and retain ten named property Handles, then dispatch each result.
 * This is a bounded C-entry reconstruction with observed four-byte Name and
 * Handle views. Names are initialized by set() before either field is read.
 * Original creation code, strings, manager storage and typed destructors remain
 * external. The original by-value Name ABI is represented by an explicit copy.
 */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Object;
struct Entry{Object*object;char opaque4[8];signed char tag;char opaqueD[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Related{char opaque[0x1C];Handle_801F7F10*handle;};
struct Globals{char opaque[0x118];Manager*manager;char opaque11C[0x20];Related*related;};
extern "C"{extern Globals lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const void*,int);Word fn_801F948C(void*,const char*);void fn_80255678(Object*);extern const char lbl_8029B40C[],lbl_8029B2EC[];}
struct SlotPrivateZero:Handle_801F7F10{SlotPrivateZero(){word=0;}~SlotPrivateZero(){}};
struct Handle_80020B90:SlotPrivateZero{Handle_80020B90(){word=0;}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{Handle_80020834(){word=0;}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80024844:Handle_80020834{Handle_80024844(const Handle_80020834&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80024844(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
 Handle_80024844&operator=(const Handle_80020834&h){Handle_80024844 copy(h);fn_801F86C8(lbl_801E9D24.manager,this,-1);word=copy.word;fn_801F86C8(lbl_801E9D24.manager,&copy,1);return*this;}
};
struct Name { Word word; void set(const char*text) { word=fn_801F948C(this,text); } };
// Native C-entry view. The third input is the address of a separate Name copy;
// callers that spell it as a C++ by-value Name use the same native ABI.
extern "C" Handle_80020834 fn_801FCF20(Object*,const Name&,Name*,const Handle_80020B90&);
inline Object*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct Owner{char opaque[0x28c];Handle_80024844 slots[10];};
extern "C" void fn_80059BA8(Owner*self) {
    for (int i=0;i<10;++i) {
        {
            Name first;
            Name copied;
            Name second;
            Handle_80020B90 out;
            Object*object=resolve(*lbl_801E9D24.related->handle);
            first.set(lbl_8029B40C);
            second.set(lbl_8029B2EC);
            copied=second;
            self->slots[i]=fn_801FCF20(object,first,&copied,out);
        }
        fn_80255678(resolve(self->slots[i]));
    }
}
