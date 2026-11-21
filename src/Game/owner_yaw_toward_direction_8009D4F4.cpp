/* fn_8009D4F4: turns the owner toward its stored direction (0x39C) after
   calling the empty leaf fn_8009AEA4. Same shape as fn_80098CD0: the current
   yaw comes from the resolved entity basis applied to the forward axis, both
   yaws become rotations about the up axis, and the slerp by rate (0x3B8) *
   delta is passed with the caller's position pointer (no copy) to the
   facing slot 0xC0. Shared pooled labels lbl_80378DA8/DB0/DBC are externs;
   front-end CSE is disabled as in fn_80098CD0. */
struct Handle{signed int generation:8;signed int index:24;};
struct Vec3{
 float x,y,z;
 Vec3(){}
 Vec3(float ax,float ay,float az):x(ax),y(ay),z(az){}
 Vec3(const Vec3&o):x(o.x),y(o.y),z(o.z){}
};
extern "C"{float fn_80285124(float,float);float fn_8028506C(float);float fn_80284FA8(float);void fn_8009AEA4(void);}
extern "C" const float lbl_80378DA8; /* 0.0f */
extern "C" const float lbl_80378DB0; /* 0.5f */
extern "C" const float lbl_80378DBC; /* 1.0f */
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
struct Storage{char unknown00[8];};
struct Owner:Storage{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
 virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
 virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
 virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
 virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();
 virtual const Handle*getHandle(int);
 virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();virtual void slotBC();
 virtual void setFacing(const Vec3*,const Rotation*,int);
 char unknown0C[0x39C-0xC];Vec3 direction;char unknown3A8[0x3B8-0x3A8];float rate;
};
extern "C"{Rotation fn_8008D420(const Rotation&,const Rotation&,float);}
#pragma opt_common_subs off
extern "C" void fn_8009D4F4(Owner*self,const Vec3*first,const Vec3*second,float delta){
 fn_8009AEA4();
 Vec3 dir=self->direction;
 Vec3 forward=resolve(*self->getHandle(0))->basis.transform(lbl_80378DA8,lbl_80378DA8,lbl_80378DBC);
 float wanted=fn_80285124(dir.x,dir.z);
 float current=fn_80285124(forward.x,forward.z);
 float wantedHalf;
 float t=self->rate*delta;
 wantedHalf=wanted*lbl_80378DB0;
 Rotation target(lbl_80378DA8,lbl_80378DBC,lbl_80378DA8,wantedHalf);
 float currentHalf=current*lbl_80378DB0;
 Rotation from(lbl_80378DA8,lbl_80378DBC,lbl_80378DA8,currentHalf);
 Rotation r=fn_8008D420(from,target,t);
 self->setFacing(second,&r,0);
}
#pragma opt_common_subs reset
