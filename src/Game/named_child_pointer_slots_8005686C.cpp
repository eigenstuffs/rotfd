/* Create five named child Handles under the related root object and store
 * each resolved child pointer in the owner's pointer table at 0x2C8.
 * The root Handle copy, the returned Handle and the retained copy follow the
 * same Handle class shapes as the neighbouring named-handle setup units.
 * The parent object is sequenced with a comma expression so that it is
 * resolved after the context Handle and before the two Keys, as observed.
 * The empty Key is copied into the by-value argument slot (dead 0x10 store).
 */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager{char unknown00[8];Entry*entries;};
struct Service{char unknown00[0x1C];Handle_801F7F10*handle;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;char unknown11C[0x20];Service*service;}lbl_801E9D24;
extern "C"{void fn_801F86C8(Manager*,const Handle_801F7F10*,int);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];Word fn_801F948C(void*,const char*);extern const char lbl_8029B1FC[];}
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_80020478{Handle_80020B90(){word=0;}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{Handle_80020834(const Handle_80020834&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8002B67C:Handle_801F7F10{Handle_8002B67C(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002B67C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Key{Word word;Key(){word=0;}Key(const char*s){word=fn_801F948C(this,s);}};
extern "C" Handle_80020834 fn_801FCF20(Node*,const Key&,Key,const Handle_80020B90&);
inline Node*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct Owner{char unknown00[0x2C8];Node**slots;};
extern "C" void fn_8005686C(Owner*self){
    for(int i=0;i<5;++i){
        Handle_8002B67C root(*lbl_801E9D24.service->handle);
        Node*parent;
        Handle_80020834 child(fn_801FCF20((parent=resolve(root),parent),Key(lbl_8029B1FC),Key(),Handle_80020B90()));
        self->slots[i]=resolve(child);
    }
}
