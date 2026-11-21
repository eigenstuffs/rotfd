/* fn_801C109C (swept sphere move, leftover of node_flag_forward_801C0F34).
 * PARTIAL 99.859%: only FPR colouring in the slide-reflection block differs
 * (original dir.x/y -> f8/f7, normal.x/y -> f5/f3; candidate swapped pairs). */
/* Two physics-node overrides from one original TU (vtables in
 * menu_object_native_method_tables_802EB240):
 *  - fn_801C0F34 forwards to the base handler fn_801BDEF8 while moving the
 *    resolved target's 0x40000 flag into 0x4000 (restored afterwards).
 *  - fn_801C109C is the swept sphere move: unless flag 0x40000 selects the
 *    base mover fn_801BE4D0, it takes the collision sphere, applies the
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
typedef unsigned long long u64;
extern "C" const float lbl_8037A354,lbl_8037A360,lbl_8037A364;
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
struct Vec3{float x,y,z;
    Vec3(){}
    Vec3(float a,float b,float c):x(a),y(b),z(c){}

    Vec3 operator-(const Vec3&v)const{return Vec3(x-v.x,y-v.y,z-v.z);}
    Vec3 operator+(const Vec3&v)const{return Vec3(x+v.x,y+v.y,z+v.z);}
    Vec3 operator*(float s)const{return Vec3(x*s,y*s,z*s);}
    Vec3&operator+=(const Vec3&v){x+=v.x;y+=v.y;z+=v.z;return *this;}
    Vec3&operator-=(const Vec3&v){x-=v.x;y-=v.y;z-=v.z;return *this;}
    const Vec3&get()const{return *this;}
    float dot(const Vec3&v)const{return x*v.x+y*v.y+z*v.z;}
    float length()const{float sq=x*x+y*y+z*z;float r=lbl_8037A354;if(sq!=r)r=fastSqrt(sq);return r;}
};
struct Sphere{Vec3 center;float radius;Sphere(const Vec3&c,float r):center(c),radius(r){}};
struct Result{Vec3 point;float unknown0C;Vec3 normal;float unknown1C;u64 unknown20;unsigned long unknown28,unknown2C;void*object;void*material;unsigned long unknown38;signed char active;char unknown3D[3];unsigned long type;unsigned long unknown44;
    Result(){active=0;object=0;material=0;unknown38=0;unknown2C=0;unknown28=0;}};
struct Prefix{unsigned long unknown00,unknown04;};
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
    virtual signed char s8C(int);
    virtual void s90();virtual void s94();virtual void s98();virtual void s9C();
    virtual void sA0();virtual void sA4();virtual void sA8();virtual void sAC();
    virtual void sB0();virtual void sB4();virtual void sB8();virtual void sBC();
    virtual void sC0();virtual void sC4();virtual void sC8();virtual void sCC();
    virtual void sD0();virtual void sD4();virtual void sD8();
    virtual void setContact(u64,int);
    virtual void sE0();virtual void sE4();
    virtual u64 getFlags(int);
    virtual void sEC();virtual void sF0();virtual void sF4();virtual void sF8();virtual void sFC();
    virtual void place(void*,const Vec3*,const Vec3*,Vec3*,int,float);
    virtual void s104();virtual void s108();
    virtual Vec3 move(void*,const Vec3*,Sphere*,int,int,int,int);
    virtual void s110();virtual void s114();virtual void s118();virtual void s11C();
    virtual void s120();virtual void s124();virtual void s128();virtual void s12C();
    virtual signed char slide(Result*,Vec3*,Vec3*,int);
};
extern "C"{
    extern const Vec3 game_vec4_zero;
    extern const float lbl_8037A350,lbl_8037A354,lbl_8037A358,lbl_8037A35C,lbl_8037A360,lbl_8037A364;
    void fn_801BE4D0(Self*,void*,const Vec3*,Vec3*,int,int,int,float);
    signed char fn_80268FE8(void*,const Vec3&,const Vec3&,Result*,u64,u64,float);
}
extern "C" void fn_801C109C(Self*self,void*world,const Vec3*from,Vec3*to,float f,int p4,int p5,int which){
    float lo;
    u64 flags=self->getFlags(which);
    if(flags&0x40000){
        fn_801BE4D0(self,world,from,to,p4,p5,which,f);
        return;
    }
    Sphere sphere(game_vec4_zero,lbl_8037A350);
    if(!(flags&0x600)||!self->getSphere(&sphere,0,which)){
        self->place(world,from,from,to,which,f);
        return;
    }
    sphere.center-=*from;
    Vec3 delta=self->move(world,from,&sphere,p5,p4,which,1);
    Vec3 target=*from+delta;
    Vec3 start=target;
    *to+=delta;
    Vec3 end=*to;
    Vec3 d=end-start;
    float len=d.length();
    float remaining=len;
    if(len==*(const float*)&lbl_8037A354)return;
    float inv=lbl_8037A350/len;
    Vec3 dir=d*inv;
    Result hit;
    u64 maskA=0;
    u64 maskB=8;
    if(flags&0x400)maskA=0x1E400000002ULL;
    if(flags&0x200)maskA|=0x8E0000000000ULL;
    if(!(flags&0x200))maskB=0xF00000000008ULL;
    lo=-lbl_8037A358;
    int count=0;
    while(fn_80268FE8(world,start+sphere.center,end+sphere.center,&hit,maskA,maskB,sphere.radius)){
        if(++count>6)break;
        if(hit.normal.y<lo)self->setContact(0x10000000000ULL,which);
        else if(hit.normal.y>lbl_8037A358)self->setContact(0x48000000000ULL,which);
        else self->setContact(0x20000000000ULL,which);
        hit.point-=sphere.center;
        *to=hit.point+hit.normal*(*(const float*)&lbl_8037A35C);
        self->contact(&hit,to,which);
        if(self->slide(&hit,&dir,to,which))break;
        remaining-=(*to-start).get().length();
        float dot=dir.dot(hit.normal);
        Vec3 n(hit.normal.x,hit.normal.y,hit.normal.z);
        Vec3 v(dir.x,dir.y,dir.z);
        if(dot<lbl_8037A360)
            dir=v-n*(lbl_8037A364*dot);
        else
            dir=v;
        start=*to;
        end=start+dir*remaining;
    }
    if(self->s8C(which)){
        self->place(world,from,&target,to,which,f);
        self->move(world,to,&sphere,p5,p4,which,0);
    }
}
