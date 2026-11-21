/* Player registration ("Registering SpongeBob"): binds the player owner
   handle, registers the actor with the scene, applies configuration flags,
   and stores the reach between the body's two bounding spheres at +0x430.
   The body lookups reload the handle bits on every use (local reference in
   the lookup inline); the square root is the engine frsqrte/fres estimate. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
struct Config{char unknown00[0xF0];int modeF0;int stateF4;char unknownF8[8];int value100;int value104;char unknown108[0x2ED-0x108];signed char flag2ED;};
struct State{char unknown00[0x15058];Config*config;};
struct Flags{char unknown00[0x408];Word flags;};
struct Status{char unknown00[0x2D];char active;};
struct Globals{char unknown00[0x110];void*logger;char unknown114[4];Manager*manager;char unknown11C[8];State*state;char unknown128[0x158-0x128];Flags*flags;char unknown15C[8];Status*status;};
extern "C"{
extern Globals lbl_801E9D24;extern char lbl_801EF5C8[];extern const char lbl_8029AA08[];
extern const float lbl_80378528;extern const int lbl_80378598;
void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);void fn_801FA014(void*,const char*,...);
}
struct Zero1_4024C:Handle_801F7F10{Zero1_4024C(){word=0;}~Zero1_4024C(){}};
struct Zero2_4024C:Zero1_4024C{Zero2_4024C(){word=0;}~Zero2_4024C(){}};
struct Zero3_4024C:Zero2_4024C{Zero3_4024C(){word=0;}~Zero3_4024C(){}};
struct Handle_80025BF4:Zero3_4024C{Handle_80025BF4(){word=0;}~Handle_80025BF4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80025B74:Handle_80025BF4{Handle_80025B74(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80025B74(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};

struct Vec3{
    float x,y,z;
    Vec3(){}
    Vec3(const Vec3&o):x(o.x),y(o.y),z(o.z){}
    float distance(const Vec3&o)const{
        float dz=z-o.z;float dy=y-o.y;float dx=x-o.x;
        register float sq=dx*dx+dy*dy+dz*dz;
        register float r=lbl_80378528;
        if(sq!=r){
            asm{frsqrte f4,sq}
            asm{fres r,f4}
        }
        return r;
    }
};
struct Sphere{Vec3 center;float radius;};
struct Node{char unknown00[0x74];Sphere*bounds74;Sphere*bounds78;char unknown7C[0x168-0x7C];Handle_801F7F10 body168;char unknown16C[0x318-0x16C];char events318[0x430-0x318];float reach430;};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline Node*resolveBody(const Handle_801F7F10&handle){const Handle_801F7F10&h=handle;int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}

struct Prefix{Word unknown00;Handle_801F7F10 self04;};
struct Owner:Prefix{
virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();
virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void v38();virtual void v3C();virtual void v40();virtual void v44();
virtual void v48();virtual void v4C();virtual void v50();virtual void v54();virtual void v58();virtual void v5C();virtual void v60();virtual void v64();
virtual void v68();virtual void v6C();virtual void v70();virtual void v74();virtual void v78();virtual void v7C();virtual void v80();virtual void v84();
virtual void v88();virtual void v8C();virtual void v90();virtual void v94();virtual void v98();virtual void v9C();virtual void vA0();virtual void vA4();
virtual void vA8();virtual void vAC();virtual void vB0();virtual void vB4();virtual int index();virtual void vBC();
char unknown0C[0x64-0xC];char position64[12];Handle_801F7F10 handle70;char unknown74[0x80-0x74];Handle_801F7F10 owner80;int mode84;char unknown88[0x9C-0x88];char flag9C;};
extern "C"{
void fn_802002A4(Node*,int,const void*,const Handle_80025B74&);void fn_802603A0(State*,int,Owner*,float);void fn_80057100(Config*,int);
void fn_80090500(Node*,Owner*);void fn_80094804(Node*);void fn_80056434(Config*,int);void fn_8007D6A0(void*,int);void fn_8004065C(Owner*);
}

extern "C" void fn_8004024C(Owner*self,const Handle_801F7F10&h){
    fn_801FA014(lbl_801E9D24.logger,lbl_8029AA08);
    fn_801F86C8(lbl_801E9D24.manager,&self->owner80,-1);self->owner80.word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);
    self->index();
    const Handle_801F7F10&original=self->handle70;
    fn_802002A4(resolve(h),self->index(),self->position64,Handle_80025B74(original));
    self->vB4();
    Flags*flags=lbl_801E9D24.flags;
    if(lbl_801E9D24.state->config->flag2ED)flags->flags|=2;else flags->flags&=~2;
    lbl_801E9D24.status->active=1;
    Config*config=lbl_801E9D24.state->config;
    fn_802603A0(lbl_801E9D24.state,0x57,self,config->value100);
    fn_80057100(config,-1);
    Node*const node=resolve(self->handle70);
    fn_80090500(node,self);
    fn_80094804(node);
    if(config->modeF0==5&&config->stateF4==2)fn_80056434(config,lbl_80378598);
    self->mode84=config->value104;
    if(self->mode84==1){self->flag9C=1;fn_8007D6A0(node->events318,0x22);}
    fn_8007D6A0(node->events318,0x34);
    Vec3 inner(resolveBody(node->body168)->bounds74->center);
    Vec3 outer(resolveBody(node->body168)->bounds78->center);
    float gap=outer.distance(inner);
    float innerRadius=resolveBody(node->body168)->bounds74->radius;
    node->reach430=innerRadius+(gap+resolveBody(node->body168)->bounds78->radius);
    self->vBC();
    fn_8004065C(self);
}
