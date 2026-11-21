/* fn_800CCA34: actor-controller move/facing dispatch on the component at
   +0x318. State 2 forwards the three points, index and delta to fn_800A91D4
   and to the component controller (fn_8007DCF8, virtual slot 0x18). State 3
   calls the empty hook fn_8009AEA4 with the same arguments, then turns the
   actor toward its stored direction (0x390): the current yaw comes from the
   resolved entity basis applied to the forward axis (0,0,1), both yaws become
   rotations about the up axis and the slerp (fn_8008D420) by rate (0x39C) *
   delta is passed with the second point to the facing slot 0xC0. Otherwise
   the second point goes to slot 0xBC. Same body shape as fn_8009D4F4
   (owner_yaw_toward_direction_8009D4F4.cpp); the pooled labels
   lbl_803796B0/B4/C0 are externs with front-end CSE disabled. */
struct Handle{signed int generation:8;signed int index:24;};
struct Vec3{
 float x,y,z;
 Vec3(){}
 Vec3(float ax,float ay,float az):x(ax),y(ay),z(az){}
 Vec3(const Vec3&o):x(o.x),y(o.y),z(o.z){}
};
extern "C"{float fn_80285124(float,float);float fn_8028506C(float);float fn_80284FA8(float);}
extern "C" const float lbl_803796B0; /* 0.0f */
extern "C" const float lbl_803796B4; /* 0.5f */
extern "C" const float lbl_803796C0; /* 1.0f */
struct Rotation{
 float w,x,y,z;
 Rotation(){}
 Rotation(float ax,float ay,float az,float half){w=fn_8028506C(half);float s=fn_80284FA8(half);x=ax*s;y=ay*s;z=az*s;}
};
struct Matrix{
 float m[9];
 Vec3 transform(float x,float y,float z)const{Vec3 o;o.x=m[0]*x+m[3]*y+m[6]*z;o.y=m[1]*x+m[4]*y+m[7]*z;o.z=m[2]*x+m[5]*y+m[8]*z;return o;}
};
struct Entity{char unknown00[0x30];Matrix basis;};
struct Entry{Entity*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct Manager{char unknown00[8];Entry*entries;};
extern "C"{extern struct{char unknown00[0x118];Manager*manager;}lbl_801E9D24;}
inline Entity*resolve(const Handle&h){int index=h.index;Manager*m=lbl_801E9D24.manager;Entry*e=&m->entries[index];int generation=e->getGeneration();if(generation==h.generation)return e->object;return 0;}
struct Controller{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void update(const Vec3*,const Vec3*,const Vec3*,int,float);};
struct Storage{char unknown00[8];};
struct Owner:Storage{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
 virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
 virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
 virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
 virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();
 virtual const Handle*getHandle(int);
 virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();
 virtual void setPosition(const Vec3*,int);
 virtual void setFacing(const Vec3*,const Rotation*,int);
 char unknown0C[0x318-0xC];char component[0x78];Vec3 direction;float rate;
};
extern "C"{Rotation fn_8008D420(const Rotation&,const Rotation&,float);
signed char fn_8007D604(void*,int);Controller*fn_8007DCF8(void*);
void fn_800A91D4(Owner*,const Vec3*,const Vec3*,const Vec3*,int,float);
void fn_8009AEA4(Owner*,const Vec3*,const Vec3*,const Vec3*,int,float);}
#pragma opt_common_subs off
extern "C" void fn_800CCA34(Owner*self,const Vec3*first,const Vec3*second,const Vec3*third,int index,float delta){
 if(fn_8007D604(self->component,2)){
  fn_800A91D4(self,first,second,third,index,delta);
  fn_8007DCF8(self->component)->update(first,second,third,index,delta);
 }else if(fn_8007D604(self->component,3)){
 fn_8009AEA4(self,first,second,third,index,delta);
 Vec3 dir=self->direction;
 Vec3 forward=resolve(*self->getHandle(0))->basis.transform(lbl_803796B0,lbl_803796B0,lbl_803796C0);
 float wanted=fn_80285124(dir.x,dir.z);
 float current=fn_80285124(forward.x,forward.z);
 float wantedHalf;
 float t=self->rate*delta;
 wantedHalf=wanted*lbl_803796B4;
 Rotation target(lbl_803796B0,lbl_803796C0,lbl_803796B0,wantedHalf);
 float currentHalf=current*lbl_803796B4;
 Rotation from(lbl_803796B0,lbl_803796C0,lbl_803796B0,currentHalf);
 Rotation r=fn_8008D420(from,target,t);
 self->setFacing(second,&r,0);
 }else self->setPosition(second,0);
}
#pragma opt_common_subs reset
