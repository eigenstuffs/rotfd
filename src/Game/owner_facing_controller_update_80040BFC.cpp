/* fn_80040BFC: when the handle's object has flags38 bit 29, compares the
 * scene owner's facing towards the self actor's slot9C target with the
 * handle actor's slot9C target (fn_80058350) against lbl_80378538, then
 * drives the self actor controller states 0x17/0x1C and clears flags30
 * bit 31. The first two lookups of the parameter handle read the manager
 * first and the handle tag before its index (their index/tag are shared);
 * the facing argument uses an if/return lookup, which lets the owner move
 * into r3 before the lookup's branch. */
typedef unsigned long Word;
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct NodePrefix{Word unknown00,unknown04;};
struct Node:NodePrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40(int);virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const Handle*slot9C(int);char unknown0C[0x24];unsigned long long flags30,flags38;char unknown40[0x30];Handle actor;char unknown74[0x2A4];char controller[1];};
struct Entry{Node*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Scene{char unknown00[0x15058];Node*owner;};
extern "C"struct Globals{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;}lbl_801E9D24;
inline Node*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline Node*resolveChecked(const Handle&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
inline Node*resolveParam(const Handle&h){Manager*m=lbl_801E9D24.manager;signed char htag=h.bits.tag;int index=h.bits.index;signed char tag=m->entries[index].getTag();return tag==htag?m->entries[index].object:0;}
extern "C"{float fn_80058350(Node*,Node*,Node*);signed char fn_8007D604(void*,int);int fn_80092844(Node*);void fn_8007D6A0(void*,int);signed char fn_8025E9FC(Node*,int);extern const float lbl_80378538;}
extern "C"int fn_80040BFC(Node*self,const Handle&h){
    if((resolveParam(h)->flags38&0x20000000ULL)==0)return 0;
    Node*target=resolve(*resolve(resolveParam(h)->actor)->slot9C(0));
    Node*owner=lbl_801E9D24.scene->owner;
    if(fn_80058350(owner,resolveChecked(*resolve(self->actor)->slot9C(0)),target)>lbl_80378538){
        resolve(self->actor)->flags30&=~0x80000000ULL;
        if(fn_8007D604(resolve(self->actor)->controller,0x17)){
            int state=fn_80092844(resolve(self->actor));
            fn_8007D6A0(resolve(self->actor)->controller,state);
        }
        return 0;
    }
    if(fn_8007D604(resolve(self->actor)->controller,0x1C))return 0;
    if(!fn_8007D604(resolve(self->actor)->controller,0x17)){
        fn_8007D6A0(resolve(self->actor)->controller,0x17);
        return 0;
    }
    if(fn_8025E9FC(self,0xB)){
        resolve(self->actor)->flags30&=~0x80000000ULL;
        return 1;
    }
    return 0;
}
