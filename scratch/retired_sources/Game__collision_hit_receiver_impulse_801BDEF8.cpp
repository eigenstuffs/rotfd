/* fn_801BDEF8: ask the owner (vtable slot 0x88) for its bounding sphere,
   collect the colliders touching it (fn_80268918), and when the first hit's
   owner has state flag 0x80 forward the sphere and a speed-derived strength
   (20 * max(distance(a, b), radius)) to that owner's linked receiver
   (vtable slot 0x44). */
typedef unsigned long Word;
extern "C" const float lbl_8037A2E8,lbl_8037A2F8,lbl_8037A300,lbl_8037A304;
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
inline void*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return m->entries[index].object;return 0;}
struct Vec3{float x,y,z;
float distance(const Vec3&o)const{float dy=y-o.y;float dx=x-o.x;float dz=z-o.z;float sq=dx*dx+dy*dy+dz*dz;float r=lbl_8037A2F8;if(sq!=r)r=fastSqrt(sq);return r;}};
struct Sphere{Vec3 center;float radius;Sphere(const Vec3&c,float r){center.x=c.x;center.y=c.y;center.z=c.z;radius=r;}};
struct Prefix{char unknown00[8];};
struct Owner;
struct Collider{char unknown00[0x130];Handle owner;Owner*getOwner()const{return (Owner*)resolve(owner);}};
struct Collected{char unknown00[0x1C];Collider*collider;char unknown20[8];~Collected(){}};
struct Results{Word storage[0xA00];int count;Results():count(0){}~Results(){for(int i=0;i<count;++i)reinterpret_cast<Collected*>(storage)[i].~Collected();}
Collected&at(int i){return reinterpret_cast<Collected*>(storage)[i];}};
struct Receiver:Prefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44(const Sphere*,float,float);
};
struct Owner{char unknown00[0x38];unsigned long long flags;char unknown40[0x24];Handle receiver;Receiver*getReceiver()const{return (Receiver*)resolve(receiver);}};
struct Self:Prefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();
virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();
virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
virtual signed char slot88(Sphere*,int,int);
};
extern "C"{
extern Vec3 game_vec4_zero;
int fn_80268918(void*,const Sphere*,Results*,unsigned long long,unsigned long long);
float fn_800AA52C(float,float); /* max */
}
extern "C" void fn_801BDEF8(Self*self,void*world,const Vec3*a,const Vec3*b,int index){
    Sphere sphere(game_vec4_zero,lbl_8037A2E8);
    if(!self->slot88(&sphere,4,index))return;
    float dist=a->distance(*b);
    Results results;
    if((signed char)fn_80268918(world,&sphere,&results,0x00002E0000000000ULL,0x0000000200000000ULL)){
        Owner*owner=results.at(0).collider->getOwner();
        if(!owner||!(owner->flags&0x80))return;
        Receiver*receiver=owner->getReceiver();
        float larger=fn_800AA52C(dist,sphere.radius);
        receiver->slot44(&sphere,lbl_8037A300*larger,lbl_8037A304);
    }
}
