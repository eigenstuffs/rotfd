/* fn_800CC154: state update (vtable slot 6 of lbl_802C18A0) for the actor at
   +8. When the actor is nearly at rest (velocity length < lbl_80379698 = 0.5)
   and upright (y of the resolved entity basis applied to the up axis between
   0.95 and 1.5), it turns the actor toward its stored direction (0x390): the
   current yaw comes from the basis applied to the forward axis (0,0,1), both
   yaws become rotations about the up axis lbl_802F4148, and the slerp
   (fn_8008D420) by lbl_803796A4 (2.25) * delta is passed with the second
   point to the facing slot 0xC0. It then picks a new random direction
   (fn_800CCCEC) and switches the component at +0x318 to state 3.

   lbl_80379690 (0.0f) and lbl_80379694 (1.0f) were pooled literals of the
   original translation unit; the basis factors use distinct read forms per
   use (as in actor_related_yaw_transform_80084C50.cpp) so that no two of them
   share a front-end common subexpression, as with the literals. */
struct Handle{signed int generation:8;signed int index:24;};
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
extern "C" const float lbl_80379690; /* 0.0f */
extern "C" const float lbl_80379694; /* 1.0f */
extern "C" const float lbl_80379698; /* 0.5f */
extern "C" const float lbl_8037969C; /* 0.95f */
extern "C" const float lbl_803796A0; /* 1.5f */
extern "C" const float lbl_803796A4; /* 2.25f */
struct Vec3{
 float x,y,z;
 Vec3(){}
 Vec3(float ax,float ay,float az):x(ax),y(ay),z(az){}
 Vec3(const Vec3&o):x(o.x),y(o.y),z(o.z){}
 Vec3 operator*(float a)const{return Vec3(x*a,y*a,z*a);}
 float length()const{float sq=x*x+y*y+z*z;float r=lbl_80379690;if(sq!=r)r=fastSqrt(sq);return r;}
};
extern "C"{float fn_80285124(float,float);float fn_8028506C(float);float fn_80284FA8(float);}
extern "C" const Vec3 lbl_802F4148; /* up axis */
struct Rotation{
 float w,x,y,z;
 Rotation(){}
 Rotation(const Vec3&axis,float half){w=fn_8028506C(half);Vec3 v=axis*fn_80284FA8(half);x=v.x;y=v.y;z=v.z;}
};
struct Matrix{float m[9];};
struct Entity{char unknown00[0x30];Matrix basis;};
struct Entry{Entity*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct Manager{char unknown00[8];Entry*entries;};
extern "C"{extern struct{char unknown00[0x118];Manager*manager;}lbl_801E9D24;}
inline Entity*resolve(const Handle&h){int index=h.index;Manager*m=lbl_801E9D24.manager;Entry*e=&m->entries[index];int generation=e->getGeneration();if(generation==h.generation)return e->object;return 0;}
struct Storage{char unknown00[8];};
struct Actor:Storage{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
 virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
 virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
 virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
 virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();
 virtual const Handle*getHandle(int);
 virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();
 virtual void setPosition(const Vec3*,int);
 virtual void setFacing(const Vec3*,const Rotation*,int);
 char unknown0C[0x15C-0xC];Vec3 velocity;char unknown168[0x318-0x168];char component[0x78];Vec3 direction;
};
struct State{char unknown00[8];Actor*actor;};
extern "C"{Rotation fn_8008D420(const Rotation&,const Rotation&,float);
void fn_8007D6A0(void*,int);void fn_800CCCEC(Actor*);}
extern "C" void fn_800CC154(State*self,const Vec3*first,const Vec3*second,const Vec3*third,int index,float delta){
 float speed=self->actor->velocity.length();
 const Matrix&m=resolve(*self->actor->getHandle(0))->basis;
 float upY=m.m[1]*lbl_80379690+m.m[4]*lbl_80379694+m.m[7]**(const float*)&lbl_80379690;
 if(speed<lbl_80379698&&upY>lbl_8037969C&&upY<lbl_803796A0){
  Vec3 dir=self->actor->direction;
  const Matrix&n=resolve(*self->actor->getHandle(0))->basis;
  float fx=n.m[0]*lbl_80379690+n.m[3]**(const float*)&lbl_80379690+n.m[6]*lbl_80379694;
  float fz=n.m[2]**(const float*)(unsigned long)&lbl_80379690+n.m[5]**(const float*)(unsigned long)&lbl_80379690+n.m[8]**(const float*)&lbl_80379694;
  float wanted=fn_80285124(dir.x,dir.z);
  float current=fn_80285124(fx,fz);
  float wantedHalf=wanted*lbl_80379698;
  Rotation target(lbl_802F4148,wantedHalf);
  float currentHalf=current*lbl_80379698;
  Rotation from(lbl_802F4148,currentHalf);
  Rotation r=fn_8008D420(from,target,lbl_803796A4*delta);
  self->actor->setFacing(second,&r,0);
  fn_800CCCEC(self->actor);
  fn_8007D6A0(self->actor->component,3);
 }
}
