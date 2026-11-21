/* auto_03_801C17DC_text: seven physics-node methods (0x801C17DC..0x801C2B54).
 *  - fn_801C17DC / fn_801C18F0: after the base save/restore call
 *    (fn_801BE6F4 / fn_801BE900) resolve the record handle at
 *    records[index]+0x48, ask it (slot 0x9C) for a related handle and move one
 *    state flag of that object into the other (0x4000 <-> 0x40000).
 *  - fn_801C1A04: contact callback; if mode bit 0x2000000000 is set, query the
 *    colliders touching the node's sphere (fn_80268918, 64-record buffer) and
 *    when nothing is touched detach, clear the mode bit and send event 61 with
 *    (float)index; then dispatch the two contact virtuals (0x134 / 0x130).
 *  - fn_801C1CB4: swept sphere move with up to "remaining length" sliding
 *    (fn_80268FE8 sweep, 0.707 floor/ceiling classification, 0.01 push-out,
 *    reflection of the remaining direction).
 *  - fn_801C234C / fn_801C2520: same flag transfer for the handles at +0x1B0
 *    and +0x1AC (fn_801C2520 also advances the timer at +0x1B4).
 *  - fn_801C2714: ground probe (fn_80269230 ray straight down in steps).
 * fn_801C1A04 and fn_801C1CB4 use real literals: their private .sdata2
 * (1.0f, pad, int->float bias, 0.0f, 1e-6f, 0.707f, 0.01f, 2.0f) is the
 * original pool 0x8037A368..0x8037A38C of this translation unit.
 * fn_801C2714 belongs to the next pool (0x8037A390..) and reads extern labels. */
typedef unsigned long Word;
typedef unsigned long long u64;
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
inline void*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return m->entries[index].object;return 0;}
inline void*resolveEntry(const Handle&h){Entry*e=lbl_801E9D24.manager->entries+h.bits.index;if(e->tag==h.bits.tag)return e->object;return 0;}
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
struct Prefix{char unknown00[8];};
extern "C" const struct ZeroVec4{float x,y,z,w;}game_vec4_zero;

/* ---- flag transfer (fn_801C17DC, fn_801C18F0, fn_801C234C, fn_801C2520) ---- */
namespace flagnode{
struct Target{
    char unknown00[0x120];Word flags;
    /* separate read form keeps the test from being CSE'd with the update */
    bool testFlag(Word mask)const{return(*(const Word*)&flags&mask)!=0;}
    void orFlag(Word mask,bool on){flags=flags|(on?mask:0);}
    void clearFlag(Word mask){flags&=~mask;}
};
struct Owner:Prefix{
    virtual void s08();virtual void s0C();virtual void s10();virtual void s14();
    virtual void s18();virtual void s1C();virtual void s20();virtual void s24();
    virtual void s28();virtual void s2C();virtual void s30();virtual void s34();
    virtual void s38();virtual void s3C();virtual void s40();virtual void s44();
    virtual void s48();virtual void s4C();virtual void s50();virtual void s54();
    virtual void s58();virtual void s5C();virtual void s60();virtual void s64();
    virtual void s68();virtual void s6C();virtual void s70();virtual void s74();
    virtual void s78();virtual void s7C();virtual void s80();virtual void s84();
    virtual void s88();virtual void s8C();virtual void s90();virtual void s94();
    virtual void s98();virtual Handle*related(int);
};
struct Record{char unknown00[0x48];Handle handle;char unknown4C[0x5C];};
struct Self{char unknown00[0x188];Record*records;char unknown18C[0x20];Handle owner;Handle child;float time;};
}
extern "C"{
void fn_801BE6F4(flagnode::Self*,int);
void fn_801BE900(flagnode::Self*,int,float);
void*fn_801F7EB8(const Handle*);
}
extern "C" void fn_801C17DC(flagnode::Self*self,int index){
    using namespace flagnode;
    fn_801BE6F4(self,index);
    Owner*owner=(Owner*)resolveEntry(self->records[index].handle);
    if(owner){Target*t=(Target*)resolveEntry(*owner->related(0));
        t->orFlag(0x40000,t->testFlag(0x4000));
        t->clearFlag(0x4000);}
}
extern "C" void fn_801C18F0(flagnode::Self*self,int index,float f){
    using namespace flagnode;
    fn_801BE900(self,index,f);
    Owner*owner=(Owner*)resolveEntry(self->records[index].handle);
    if(owner){Target*t=(Target*)resolveEntry(*owner->related(0));
        t->orFlag(0x4000,t->testFlag(0x40000));
        t->clearFlag(0x40000);}
}

/* ---- contact callback (fn_801C1A04) ---- */
namespace contact{
struct Vec3{float x,y,z;
    Vec3&operator+=(const Vec3&v){x+=v.x;y+=v.y;z+=v.z;return *this;}
    Vec3&operator-=(const Vec3&v){x-=v.x;y-=v.y;z-=v.z;return *this;}
};
struct Sphere{Vec3 center;float radius;Sphere(const Vec3&c,float r){center.x=c.x;center.y=c.y;center.z=c.z;radius=r;}};
struct Collected{char unknown00[0xA0];~Collected(){}};
struct Results{Word storage[0xA00];int count;Results():count(0){}~Results(){for(int i=0;i<count;++i)reinterpret_cast<Collected*>(storage)[i].~Collected();}};
struct Self:Prefix{
    virtual void s08();virtual void s0C();virtual void s10();virtual void s14();
    virtual void s18();virtual void s1C();virtual void s20();virtual void s24();
    virtual void s28();virtual void s2C();virtual void s30();virtual void s34();
    virtual void s38();virtual void s3C();virtual void s40();virtual void s44();
    virtual void s48();virtual void s4C();virtual void s50();virtual void s54();
    virtual void s58();virtual void s5C();virtual void s60();virtual void s64();
    virtual void s68();virtual void s6C();virtual void s70();virtual void s74();
    virtual void s78();virtual void s7C();virtual void s80();virtual void s84();
    virtual signed char getSphere(Sphere*,int,int);
    virtual void s8C();virtual void s90();virtual void s94();virtual void s98();
    virtual Handle*detach(int);
    virtual void sA0();virtual void sA4();virtual void sA8();virtual void sAC();
    virtual void sB0();virtual void sB4();virtual void sB8();virtual void sBC();
    virtual void sC0();virtual void sC4();virtual void sC8();virtual void sCC();
    virtual void sD0();virtual void sD4();virtual void sD8();virtual void sDC();
    virtual void clearMode(u64,int);
    virtual void sE4();virtual void sE8();virtual void sEC();virtual void sF0();virtual void sF4();virtual void sF8();virtual void sFC();
    virtual void s100();virtual void s104();virtual void s108();virtual void s10C();
    virtual void s110();virtual void s114();virtual void s118();virtual void s11C();
    virtual void s120();virtual void s124();virtual void s128();virtual void s12C();
    virtual void contactB(void*,const Vec3*,const Vec3*);
    virtual void contactA(void*,const Vec3*,const Vec3*);
    char unknown0C[0x18];Handle handle;char unknown28[8];u64 mode;
};
}
extern "C"{
void fn_801BE188(contact::Self*,void*,const contact::Vec3*,const contact::Vec3*,const contact::Vec3*,int);
signed char fn_80268918(void*,const contact::Sphere*,contact::Results*,u64,u64);
void fn_802073E8(void*,int,void*,float);
}
extern "C" void fn_801C1A04(contact::Self*self,void*world,const contact::Vec3*a,const contact::Vec3*b,const contact::Vec3*c,int index){
    using namespace contact;
    fn_801BE188(self,world,a,b,c,index);
    u64 flags=self->mode;
    if(flags&0x0000002000000000ULL){
        Sphere sphere(*(const Vec3*)&game_vec4_zero,1.0f);
        Results results;
        if(self->getSphere(&sphere,0,index)){
            sphere.center-=*a;
            sphere.center+=*c;
            if(!fn_80268918(world,&sphere,&results,0x00008E0400000002ULL,8ULL)){
                /* the detached object is resolved but unused; its context
                   address stays live across clearMode (r23) */
                void*detached=resolve(*self->detach(index));
                self->clearMode(0x0000002000000000ULL,index);
                fn_802073E8(self,0x3D,resolve(self->handle),(float)index);
            }
        }
    }
    if(flags&0x80000ULL)self->contactA(world,a,c);
    if(flags&0x80000000ULL)self->contactB(world,b,c);
}

/* ---- swept sphere move (fn_801C1CB4) ---- */
namespace sweep{
struct Vec3{float x,y,z;
    Vec3(){}
    /* user-declared: the implicit operator= defers this function's emission
       past fn_801C2520; it also makes `dir=dir` below a real self-copy */
    Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return *this;}
    Vec3(float a,float b,float c):x(a),y(b),z(c){}
    Vec3 operator-(const Vec3&v)const{return Vec3(x-v.x,y-v.y,z-v.z);}
    Vec3 operator+(const Vec3&v)const{return Vec3(x+v.x,y+v.y,z+v.z);}
    Vec3 operator*(float s)const{return Vec3(x*s,y*s,z*s);}
    Vec3&operator+=(const Vec3&v){x+=v.x;y+=v.y;z+=v.z;return *this;}
    Vec3&operator-=(const Vec3&v){x-=v.x;y-=v.y;z-=v.z;return *this;}
    const Vec3&get()const{return *this;}
    float dot(const Vec3&v)const{return x*v.x+y*v.y+z*v.z;}
    float length()const{float sq=x*x+y*y+z*z;float r=0.0f;if(sq!=r)r=fastSqrt(sq);return r;}
};
struct Sphere{Vec3 center;float radius;Sphere(const Vec3&c,float r):center(c),radius(r){}};
struct Result{Vec3 point;float unknown0C;Vec3 normal;float unknown1C;u64 unknown20;Word unknown28,unknown2C;void*object;void*material;Word unknown38;signed char active;char unknown3D[3];Word type;Word unknown44;
    Result(){active=0;object=0;material=0;unknown38=0;unknown2C=0;unknown28=0;}};
struct Self:Prefix{
    virtual void s08();virtual void s0C();virtual void s10();virtual void s14();
    virtual void s18();virtual void s1C();virtual void s20();virtual void s24();
    virtual void s28();virtual void s2C();virtual void s30();virtual void s34();
    virtual void s38();virtual void s3C();virtual void s40();virtual void s44();
    virtual void s48();virtual void s4C();virtual void s50();virtual void s54();
    virtual void s58();
    virtual void contact(Result*,Vec3*,int);
    virtual void s60();virtual void s64();virtual void s68();virtual void s6C();
    virtual void s70();virtual void s74();virtual void s78();virtual void s7C();
    virtual void s80();virtual void s84();
    virtual signed char getSphere(Sphere*,int,int);
    virtual void s8C();virtual void s90();virtual void s94();virtual void s98();
    virtual void s9C();
    virtual void sA0();virtual void sA4();virtual void sA8();virtual void sAC();
    virtual void sB0();virtual void sB4();virtual void sB8();virtual void sBC();
    virtual void sC0();virtual void sC4();virtual void sC8();virtual void sCC();
    virtual void sD0();virtual void sD4();virtual void sD8();
    virtual void setContact(u64,int);
    virtual void sE0();virtual void sE4();virtual void sE8();virtual void sEC();
    virtual void sF0();virtual void sF4();virtual void sF8();virtual void sFC();
    virtual void place(void*,const Vec3*,const Vec3*,Vec3*,int,float);
    virtual void s104();virtual void s108();
    virtual Vec3 move(void*,const Vec3*,Sphere*,int,int,int,int);
    virtual void s110();virtual void s114();virtual void s118();virtual void s11C();
    virtual void s120();virtual void s124();
    virtual signed char slide(Result*,Vec3*,Vec3*,int);
    virtual void s12C();virtual void s130();virtual void s134();
    virtual void adjust(Vec3*,int,float);
    char unknown0C[0x24];u64 mode;
};
}
extern "C" signed char fn_80268FE8(void*,const sweep::Vec3*,const sweep::Vec3*,sweep::Result*,u64,u64,float);
extern "C" void fn_801C1CB4(sweep::Self*self,void*world,const sweep::Vec3*from,sweep::Vec3*to,int p4,int p5,int which,float f){
    using namespace sweep;
    float lo;
    u64 flags=self->mode;
    if(!(flags&0x600)){
        self->place(world,from,to,to,which,f);
        return;
    }
    Sphere sphere(*(const Vec3*)&game_vec4_zero,1.0f);
    if(!self->getSphere(&sphere,0,which))return;
    sphere.center-=*from;
    Vec3 delta=self->move(world,from,&sphere,p5,p4,which,1);
    self->adjust(&delta,which,f);
    Vec3 target=*from+delta;
    Vec3 start=*from+delta; /* recomputed (CSE'd): keeps delta.x in f5 */
    *to+=delta;
    Vec3 end=*to;
    Vec3 d=end-start;
    float len=d.length();
    float remaining=len;
    if(len>1e-6f){
        float inv=1.0f/len;
        Vec3 dir=d*inv;
        Result hit;
        u64 maskA=0x1E000000002ULL;
        u64 maskB=8;
        if(flags&0x800)maskA=0x1E400000002ULL;
        if(flags&0x200)maskA|=0x8E0000000000ULL;
        if(!(flags&0x200))maskB=0xF00000000008ULL;
        start+=sphere.center;
        end+=sphere.center;
        float k=0.707f;lo=-k; /* negated at run time; pool holds only 0.707f */
        while(fn_80268FE8(world,&start,&end,&hit,maskA,maskB,sphere.radius)&&remaining>1e-6f){
            if(hit.normal.y<lo)self->setContact(0x10000000000ULL,which);
            else if(hit.normal.y>0.707f)self->setContact(0x48000000000ULL,which);
            else self->setContact(0x20000000000ULL,which);
            hit.point-=sphere.center;
            *to=hit.point+hit.normal*0.01f;
            self->contact(&hit,to,which);
            if(self->slide(&hit,&dir,to,which))break;
            float dist=(*to-start).get().length();
            if(dist<1e-6f)dist=1e-6f;
            remaining-=dist;
            float dot=dir.dot(hit.normal);
            if(dot<1e-6f)
                dir=dir-hit.normal*(2.0f*dot);
            else
                dir=dir; /* self-copy: original stores dir in both arms */
            start=*to;
            end=start+dir*remaining;
        }
    }
    self->move(world,to,&sphere,p5,p4,which,0);
    self->place(world,from,&target,to,which,f);
}

extern "C" void fn_801C234C(flagnode::Self*self,int index){
    using namespace flagnode;
    fn_801BE6F4(self,index);
    Owner*owner=(Owner*)resolveEntry(self->child);
    if(owner){Target*t=(Target*)resolveEntry(*owner->related(0));
        t->orFlag(0x40000,t->testFlag(0x4000));
        t->clearFlag(0x4000);}
    if(fn_801F7EB8(&self->owner)){Owner*o=(Owner*)resolveEntry(self->owner);Target*t=(Target*)resolveEntry(*o->related(0));
        t->orFlag(0x40000,t->testFlag(0x4000));
        t->clearFlag(0x4000);}
}
extern "C" void fn_801C2520(flagnode::Self*self,int index,float f){
    using namespace flagnode;
    fn_801BE900(self,index,f);
    Owner*owner=(Owner*)resolveEntry(self->child);
    if(owner){Target*t=(Target*)resolveEntry(*owner->related(0));
        t->orFlag(0x4000,t->testFlag(0x40000));
        t->clearFlag(0x40000);}
    if(fn_801F7EB8(&self->owner)){Owner*o=(Owner*)resolveEntry(self->owner);Target*t=(Target*)resolveEntry(*o->related(0));
        t->orFlag(0x4000,t->testFlag(0x40000));
        t->clearFlag(0x40000);
        self->time+=f;}
}

/* ---- ground probe (fn_801C2714) ---- */
namespace probe{
struct Vec3{float x,y,z;
    Vec3(){}
    Vec3(float a,float b,float c):x(a),y(b),z(c){}
};
struct Sphere{Vec3 center;float radius;Sphere(const Vec3&c,float r):center(c),radius(r){}};
struct Ray{Vec3 origin;float length;Vec3 direction;float unknown1C;
    Ray(const Vec3&o,const Vec3&d,float l):origin(o),direction(d){length=l;}};
struct HitResult{Vec3 point;char unknown0C[0x28-12];u64 flags;void*object;Word other,extra;signed char hit;char unknown3D[3];Word end;
    HitResult(){hit=0;object=0;other=0;extra=0;flags=0;}};
struct Target{char unknown00[0x120];Word flags;};
struct Body:Prefix{
    virtual void s08();virtual void s0C();virtual void s10();virtual void s14();
    virtual void s18();virtual void s1C();virtual void s20();virtual void s24();
    virtual void s28();virtual void s2C();virtual void s30();virtual void s34();
    virtual void s38();virtual void s3C();virtual void s40();virtual void s44();
    virtual void land(Target*,const Vec3*,HitResult*,float);
    Word flags;
};
struct Container{char unknown00[0x6C];Handle*bodies;};
struct Record{char unknown00[0x28];float height;char unknown2C[0xC];u64 flags;Handle target;char unknown44[0x64];};
struct Self:Prefix{
    virtual void s08();virtual void s0C();virtual void s10();virtual void s14();
    virtual void s18();virtual void s1C();virtual void s20();virtual void s24();
    virtual void s28();virtual void s2C();virtual void s30();virtual void s34();
    virtual void s38();virtual void s3C();virtual void s40();virtual void s44();
    virtual void s48();virtual void s4C();virtual void s50();virtual void s54();
    virtual void s58();virtual void s5C();virtual void s60();virtual void s64();
    virtual void s68();virtual void s6C();virtual void s70();virtual void s74();
    virtual void s78();virtual void s7C();virtual void s80();virtual void s84();
    virtual signed char getSphere(Sphere*,int,int);
    virtual void s8C();
    virtual int s90(void*,int);
    virtual void s94();virtual void s98();virtual void s9C();
    virtual void sA0();virtual void sA4();virtual void sA8();virtual void sAC();
    virtual void sB0();virtual void sB4();virtual void sB8();virtual void sBC();
    virtual void sC0();virtual void sC4();virtual void sC8();virtual void sCC();
    virtual void sD0();virtual void sD4();virtual void sD8();virtual void sDC();
    virtual void sE0();virtual void sE4();
    virtual u64 getFlags(int);
    char unknown0C[0x17C];Record*records;char unknown18C[0x40];int*slots;
};
}
extern "C"{
    extern const float lbl_8037A390,lbl_8037A394,lbl_8037A398,lbl_8037A39C,lbl_8037A3A0,lbl_8037A3A4,lbl_8037A3A8,lbl_8037A3AC;
    Handle*fn_8022E63C(probe::Self*);
    signed char fn_80269230(void*,const probe::Ray&,probe::HitResult*,u64,u64);
}
extern "C" void fn_801C2714(probe::Self*self,void*world,int index){
    using namespace probe;
    int slot;Target*target;Record*rec;Body*body;
    if(self->s90(world,index)<0)return;
    u64 flags=self->getFlags(index);
    if(!(flags&0xA000))return;
    Sphere sphere(*(const Vec3*)&game_vec4_zero,lbl_8037A390);
    if(!self->getSphere(&sphere,3,index))return;
    rec=&self->records[index];
    target=(Target*)resolve(rec->target);
    slot=self->slots[index];
    Container*c=(Container*)resolve(*fn_8022E63C(self));
    body=(Body*)resolve(c->bodies[slot]);
    HitResult hit;
    sphere.center.y+=lbl_8037A394;
    Vec3 pos=sphere.center;
    float step=lbl_8037A394+rec->height;
    if(step<lbl_8037A398)step=lbl_8037A39C;
    else if(step>=lbl_8037A3A0)step=lbl_8037A3A4;
    float remaining=lbl_8037A3A0-step;
    while(remaining>lbl_8037A398&&!fn_80269230(world,Ray(sphere.center,Vec3(lbl_8037A3A8,lbl_8037A3AC,lbl_8037A3A8),step),&hit,0x0000876000000002ULL,0x0000000400000008ULL)){
        remaining-=step;
        sphere.center.y-=step;
        step=lbl_8037A390;
    }
    if(remaining>lbl_8037A398){
        rec->height=pos.y-hit.point.y;
        body->land(target,&pos,&hit,sphere.radius);
        if(!(flags&0x2000))target->flags&=~0x80000;
        if((flags&0x8000)&&(hit.flags&0x100))body->flags|=0x10;
        else body->flags&=~0x10;
    }else{
        target->flags&=~0x80000;
        body->flags&=~0x10;
    }
    if(flags&0x80)rec->flags&=~0xA000ULL;
}
