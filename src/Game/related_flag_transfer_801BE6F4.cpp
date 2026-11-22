/* slot50__12ObjectMove_ZFv, slot48__12ObjectMove_ZFv (exact run 0x801BE6F4..0x801BEB0C); originally (tail of the 0x801BCB78.. translation
   unit; constants are that TU's pooled literals, reached through extern labels). */
typedef unsigned long Word;
typedef unsigned long long Wide;
extern "C" const float lbl_8037A2E8, lbl_8037A2F8, lbl_8037A2FC, lbl_8037A308;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct ReturnedHandle:Handle_801F7F10{~ReturnedHandle(){}};
struct Vec3{float x,y,z;
Vec3(){}
Vec3(float a,float b,float c):x(a),y(b),z(c){}
Vec3 operator-(const Vec3&o)const{float rz=z-o.z;float ry=y-o.y;float rx=x-o.x;return Vec3(rx,ry,rz);}
Vec3 operator+(const Vec3&o)const{return Vec3(x+o.x,y+o.y,z+o.z);}
};
struct Sphere{Vec3 center;float radius;Sphere(const Vec3&c,float r){center.x=c.x;center.y=c.y;center.z=c.z;radius=r;}};
struct Ray{Vec3 origin;float length;Vec3 direction;float unknown1C;
Ray(const Vec3&o,const Vec3&d,float l):origin(o),direction(d){length=l;}};
struct Result{Vec3 point;char unknown0C[0x28-12];Wide flags;Word object,other,extra;signed char hit;char unknown3D[3];Word end;
Result(){hit=0;object=0;other=0;extra=0;flags=0;}};
struct Prefix{char unknown00[8];};
struct Target{char unknown00[0x120];Word flags;
bool testFlag(Word mask)const{return(*(const Word*)&flags&mask)!=0;}
void orFlag(Word mask,bool on){flags=flags|(on?mask:0);}
void clearFlag(Word mask){flags&=~mask;}
};
struct Owner:Prefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();
virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();
virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
virtual signed char slot88(Sphere*,int,int);virtual void slot8C();virtual void slot90();virtual void slot94();
virtual void slot98();virtual Handle_801F7F10*slot9C(int);virtual void slotA0();virtual void slotA4();
virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();
virtual void slotB8();virtual void slotBC();virtual void slotC0();virtual void slotC4();
virtual void slotC8();virtual void slotCC();virtual void slotD0();virtual void slotD4();
virtual void slotD8();virtual void slotDC();virtual void slotE0();virtual signed char slotE4(Wide,int);
virtual void slotE8();virtual void slotEC();virtual void slotF0();virtual void slotF4();
virtual void slotF8();virtual void slotFC();virtual void slot100(void*,const Vec3*,const Vec3*,Vec3*,int,float);
char unknown0C[0x5C];Handle_801F7F10 related;
};
struct Entry{void*object;Word unknown04,unknown08;signed char tag;char pad[3];};
struct Manager{char unknown00[8];Entry*entries;};
struct Global{char unknown00[0x118];Manager*manager;};
extern "C" Global lbl_801E9D24;
inline void*resolve(const Handle_801F7F10&h){Entry*e=lbl_801E9D24.manager->entries+h.bits.index;if(e->tag==h.bits.tag)return e->object;return 0;}
extern "C"{
extern Vec3 game_vec4_zero;
signed char fn_80269230(void*,const Ray&,Result*,Wide,Wide);
ReturnedHandle fn_801BE46C(Owner*);
}

extern "C" void slot50__12ObjectMove_ZFv(Owner*self,int index){
    Target*t=(Target*)resolve(*self->slot9C(index));
    t->orFlag(0x40000,t->testFlag(0x4000));t->clearFlag(0x4000);
    t=(Target*)resolve(self->related);
    if(t){t->orFlag(0x40000,t->testFlag(0x4000));t->clearFlag(0x4000);}
    Owner*linked=(Owner*)resolve(fn_801BE46C(self));
    if(linked){t=(Target*)resolve(*linked->slot9C(0));
    t->orFlag(0x40000,t->testFlag(0x4000));t->clearFlag(0x4000);}
}

extern "C" void slot48__12ObjectMove_ZFv(Owner*self,int index){
    Target*t=(Target*)resolve(*self->slot9C(index));
    t->orFlag(0x4000,t->testFlag(0x40000));t->clearFlag(0x40000);
    t=(Target*)resolve(self->related);
    if(t){t->orFlag(0x4000,t->testFlag(0x40000));t->clearFlag(0x40000);}
    Owner*linked=(Owner*)resolve(fn_801BE46C(self));
    if(linked){t=(Target*)resolve(*linked->slot9C(0));
    t->orFlag(0x4000,t->testFlag(0x40000));t->clearFlag(0x40000);}
}
