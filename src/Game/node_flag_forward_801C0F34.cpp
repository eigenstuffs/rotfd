/* Two physics-node overrides from one original TU (vtables in
 * menu_object_native_method_tables_802EB240):
 *  - fn_801C0F34 forwards to the base handler slot104__12ObjectMove_ZFv while moving the
 *    resolved target's 0x40000 flag into 0x4000 (restored afterwards).
 *  - fn_801C109C is the swept sphere move: unless flag 0x40000 selects the
 *    base mover slot4C__12ObjectMove_ZFv, it takes the collision sphere, applies the
 *    proposed move, then slides along up to six contacts (fn_80268FE8 sweep,
 *    0.707 floor/ceiling classification, 0.01 push-out, reflection of the
 *    remaining direction).
 * The first handle resolve in fn_801C0F34 is written out in the body (an
 * inline helper call allocates its offset register differently); the flag
 * read uses a second read form so it is not CSE'd with the update. */
typedef unsigned long Word;
struct Handle{signed int tag:8,index:24;};
struct NodeBase{char unknown00[8];};
struct Node:NodeBase{
    virtual void s08();virtual void s0C();virtual void s10();virtual void s14();
    virtual void s18();virtual void s1C();virtual void s20();virtual void s24();
    virtual void s28();virtual void s2C();virtual void s30();virtual void s34();
    virtual void s38();virtual void s3C();virtual void s40();virtual void s44();
    virtual void s48();virtual void s4C();virtual void s50();virtual void s54();
    virtual void s58();virtual void s5C();virtual void s60();virtual void s64();
    virtual void s68();virtual void s6C();virtual void s70();virtual void s74();
    virtual void s78();virtual void s7C();virtual void s80();virtual void s84();
    virtual void s88();virtual void s8C();virtual void s90();virtual void s94();
    virtual void s98();virtual const Handle&getHandle(int);
    char unknown0C[0x114];
    Word flags;
};
struct Entry{Node*object;char unknown04[8];signed char tag;char pad[3];
    signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
inline Node*resolve(const Handle&h){int index=h.index;Manager*m=lbl_801E9D24.manager;
    int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct State{char unknown00[0x44];Handle handle;char unknown48[0x60];};
struct Owner{char unknown00[0x188];State*states;};
extern "C" void slot104__12ObjectMove_ZFv(Owner*,void*,void*,void*,int);
extern "C" void fn_801C0F34(Owner*self,void*a,void*b,void*c,int index){
    const Handle&h=self->states[index].handle;
    int i=h.index;
    Manager*m=lbl_801E9D24.manager;
    int tag=m->entries[i].getTag();
    Node*node=tag==h.tag?m->entries[i].object:0;
    Node*target;
    if(node){
        target=resolve(node->getHandle(0));
        target->flags=target->flags|((*(const Word*)&target->flags&0x40000)?0x4000:0);
        target->flags&=~0x40000;
    }
    slot104__12ObjectMove_ZFv(self,a,b,c,index);
    if(node){
        target->flags=target->flags|((*(const Word*)&target->flags&0x4000)?0x40000:0);
        target->flags&=~0x4000;
    }
}
