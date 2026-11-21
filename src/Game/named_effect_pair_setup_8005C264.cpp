/* Create the two named effect Handles (lbl_8029B510/lbl_8029B524 under the
 * object resolved from the incoming Handle) once, storing the resolved effects
 * in lbl_80377694[0] and [1]. Class shapes follow named_handle_list_setup_80059D58.
 * Requires GC/1.3: GC/1.3.2 schedules the input-Handle resolve differently. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct Entry{Node*object;char opaque4[8];signed char tag;char opaqueD[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Globals{char opaque[0x118];Manager*manager;};
extern "C"{extern Globals lbl_801E9D24;extern char lbl_801EF5C8[];extern const char lbl_8029B510[],lbl_8029B524[];extern Node*lbl_80377694[2];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const void*,int);Word fn_801F948C(void*,const char*);void*fn_801F7EB8(const Handle_801F7F10*);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(){word=0;}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{Handle_80020834(){word=0;}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80024844:Handle_80020834{Handle_80024844(){word=0;}Handle_80024844(const Handle_80020834&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80024844(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
 Handle_80024844&operator=(const Handle_80024844&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};
struct Name { Word word; Name(const char*text) { word=fn_801F948C(this,text); } };
extern "C" Handle_80020834 fn_801FCF20(Node*,const Name&,Name,const Handle_80020B90&);
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return m->entries[index].object;return 0;}
extern "C" void fn_8005C264(void*,const Handle_801F7F10&input){
    if(!lbl_80377694[0]){
        Node*parent;
        Handle_80024844 effect(fn_801FCF20((parent=resolve(input),parent),Name(lbl_8029B510),Name(lbl_8029B524),Handle_80020B90()));
        if(fn_801F7EB8(&effect)){
            lbl_80377694[0]=resolve(effect);
            effect=Handle_80024844(fn_801FCF20((parent=resolve(input),parent),Name(lbl_8029B510),Name(lbl_8029B524),Handle_80020B90()));
            lbl_80377694[1]=resolve(effect);
        }
    }
}
