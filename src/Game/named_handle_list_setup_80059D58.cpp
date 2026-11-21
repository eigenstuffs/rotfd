/* Create eight named Handles under the related root object and append each
 * valid result to the owner's growable Handle list at 280/284/288.
 * Names are addressed inside the existing lbl_8029ACA8 string pool; the
 * original strings, creation code and typed destructors remain external.
 * Every name, the context Handle, the returned Handle and the retained copy
 * are full-expression temporaries, which reproduces the native frame layout.
 * The parent object is sequenced with a comma expression so that it is
 * resolved after the context Handle and before the two Names, as observed.
 */
typedef unsigned long Word;
inline void*operator new(unsigned long,void*p){return p;}
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Object;
struct Entry{Object*object;char opaque4[8];signed char tag;char opaqueD[3];};
struct Manager{int count,capacity;Entry*entries;};
struct Related{char opaque[0x1C];Handle_801F7F10*handle;};
struct Globals{char opaque[0x118];Manager*manager;char opaque11C[0x20];Related*related;};
extern "C"{extern Globals lbl_801E9D24;extern char lbl_801EF5C8[],lbl_8028F698[];extern const char lbl_8029ACA8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const void*,int);Word fn_801F948C(void*,const char*);void*fn_801F7EB8(const Handle_801F7F10*);void fn_8028FD50(void*,void*,int);void*fn_8028FAF4(void*,void*,int,int);void*fn_8028FF24(void*,int);}
struct Handle_8002B67C:Handle_801F7F10{Handle_8002B67C(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002B67C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(){word=0;}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{Handle_80020834(){word=0;}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80024844:Handle_80020834{Handle_80024844(){word=0;}Handle_80024844(const Handle_80020834&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80024844(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
 Handle_80024844&operator=(const Handle_80024844&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};
struct Name { Word word; Name(const char*text) { word=fn_801F948C(this,text); } };
extern "C" Handle_80020834 fn_801FCF20(Object*,const Name&,Name,const Handle_80020B90&);
inline Object*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct Owner{char opaque[0x280];int count,capacity;Handle_80024844*handles;
 void resize(int n){if(n){if(handles)handles=(Handle_80024844*)fn_8028FAF4(lbl_8028F698,handles,capacity*4,n*4);else handles=(Handle_80024844*)fn_8028FF24(lbl_8028F698,n*4);}else if(handles){fn_8028FD50(lbl_8028F698,handles,capacity*4);handles=0;}}
 void append(const Handle_80020834&h){if(count+1>capacity){resize(capacity+8);capacity+=8;}new(handles+count++)Handle_80024844(h);}
};
#define CREATE_NAMED(OFF) \
    {Object*parent;h=Handle_80024844(fn_801FCF20((parent=resolve(root),parent),Name(strings+OFF),Name(strings+0x644),Handle_80020B90()));} \
    if(fn_801F7EB8(&h))self->append(h);
extern "C" int fn_80059D58(Owner*self){
    const char*strings=lbl_8029ACA8;
    Handle_8002B67C root(*lbl_801E9D24.related->handle);
    Handle_80024844 h;
    CREATE_NAMED(0x77c)
    CREATE_NAMED(0x77c)
    CREATE_NAMED(0x79c)
    CREATE_NAMED(0x7ac)
    CREATE_NAMED(0x7bc)
    CREATE_NAMED(0x7cc)
    CREATE_NAMED(0x7ec)
    CREATE_NAMED(0x804)
    return 1;
}
