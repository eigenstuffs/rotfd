/* Record state handler: update the record owner's flags depending on whether the scene's
 * current Handle (node+0x7C) matches one of the node's partner Handles (0x80/0x84/0x88). */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct Entry{Node*object;char gap04[8];signed char tag;char gap0D[3];signed char getTag()const{return tag;}};
struct Manager{char gap00[8];Entry*entries;};
struct Scene;
struct ServicePrefix{char opaque00[0x30];};
struct Service:ServicePrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual signed char slot64(int);};
extern "C" struct Context{char gap00[0x118];Manager*manager;char gap11C[8];Scene*scene;char gap128[0x168-0x128];Service*service168;}lbl_801E9D24;
extern "C"{void fn_801F86C8(Manager*,const Handle_801F7F10*,short);void fn_8007D7F4(void*,int);void fn_8007D6A0(void*,int);signed char fn_8007D604(void*,int);}
struct ZeroLayer:Handle_801F7F10{ZeroLayer(){word=0;}~ZeroLayer(){}};
struct Handle_80020834:ZeroLayer{Handle_80020834(){word=0;}~Handle_80020834(){}};
struct Handle_8003E120:Handle_80020834{Handle_8003E120();Handle_8003E120(const Handle_8003E120&v){word=v.word;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_8003E120(){}};
extern "C" Handle_8003E120 fn_800BCEF8(const Scene*);
struct Node{char gap00[0x7C];Handle_801F7F10 h7C,h80,h84,h88;};
struct View;
struct Owner{char gap00[8];char*object08;View*record0C;};
inline Node*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;int index=h.bits.index;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline bool same(const Handle_801F7F10&a,const Handle_801F7F10&b){Node*l=resolve(a);return l==resolve(b);}

extern "C" void fn_800E9BAC(Owner*self){
    Handle_8003E120 handle(fn_800BCEF8(lbl_801E9D24.scene));
    unsigned char r=same(resolve(handle)->h7C,resolve(handle)->h88);
    if(!r)r=same(resolve(handle)->h7C,resolve(handle)->h84);
    if(!r)r=same(resolve(handle)->h7C,resolve(handle)->h80);
    signed char related=r;
    if(!related){fn_8007D7F4(self->object08+0x20,23);return;}
    if(lbl_801E9D24.service168->slot64(0)){
        fn_8007D6A0(self->object08+0x20,22);
        fn_8007D7F4(self->object08+0x20,23);
    }
}
