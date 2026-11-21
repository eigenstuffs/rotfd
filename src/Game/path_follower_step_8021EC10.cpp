/* fn_8021EC10: path follower step. Evaluates the curve (or cubic fallback) position,
 * the facing direction (normalized delta or slerped rotation applied to +Z), advances
 * time and fires event 0x29 or the finish virtual. Same compiler flags as neighbours. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word value;struct{signed int generation:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct PathEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct PathManager{char unknown00[8];PathEntry*entries;};
extern "C"{extern struct{char unknown00[0x118];PathManager*manager;}lbl_801E9D24;}
extern "C" void fn_801F86C8(PathManager*,const void*,short);
extern "C" Word fn_801F7EB8(const Handle_801F7F10*);
inline char*resolvePath(const Handle_801F7F10&h){int index=h.bits.index;PathManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();return generation==h.bits.generation?m->entries[index].object:0;}
struct PathHandle1:Handle_801F7F10{PathHandle1(){value=0;}~PathHandle1(){}};
struct PathHandle2:PathHandle1{PathHandle2(){value=0;}~PathHandle2(){}};
struct PathHandle3:PathHandle2{PathHandle3(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~PathHandle3(){}};

inline float reciprocalSqrt(register float value)
{
    register float result;
    asm { frsqrte result, value }
    return result;
}
struct Vec3{
 float x,y,z;
 Vec3(){}
 Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3 operator+(const Vec3&v)const{return Vec3(x+v.x,y+v.y,z+v.z);}
 Vec3 operator-(const Vec3&v)const{return Vec3(x-v.x,y-v.y,z-v.z);}
 Vec3 operator*(float s)const{return Vec3(x*s,y*s,z*s);}
 Vec3&operator-=(const Vec3&v){x-=v.x;y-=v.y;z-=v.z;return*this;}
 Vec3&normalize(){float s=reciprocalSqrt(x*x+y*y+z*z);x*=s;y*=s;z*=s;return*this;}
};
struct Quat{
 float w;Vec3 v;
 Quat(){}
 Quat&operator=(const Quat&q){w=q.w;v.x=q.v.x;v.y=q.v.y;v.z=q.v.z;return*this;}
};
struct PathObject{char unknown00[0x1C];Handle_801F7F10 curve;};
struct PathOwnerStorage{char unknown00[8];};
struct PathOwner:PathOwnerStorage{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
 virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
 virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
 virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
 virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();
 virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
 virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();
 virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
 virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();
 virtual void slot98();virtual void slot9C();virtual void slotA0();virtual void slotA4();
 virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();
 virtual void slotB8();virtual void slotBC();virtual void slotC0();virtual void slotC4();
 virtual void slotC8();virtual void slotCC();virtual void slotD0();virtual void slotD4();
 virtual void slotD8();virtual void slotDC();virtual void slotE0();virtual void slotE4();
 virtual void slotE8();virtual void slotEC();virtual void slotF0();virtual void slotF4();
 virtual void slotF8();virtual void finish();
 char unknown0C[0x24-0xC];
 Handle_801F7F10 handle24;
 char unknown28[8];
 unsigned long long flags;
 char unknown38[0xD4-0x38];
 Vec3 cubic,quadratic,linear,constant;
 float scale;
 float angle;
 Quat from,to;
 Handle_801F7F10 path;
 Vec3 offset;
 float duration;
 float time;
};
extern "C"{
extern const float lbl_8037B070,lbl_8037B074,lbl_8037B078,lbl_8037B07C,lbl_8037B080;
float fn_8024DA4C(char*,const Handle_801F7F10*,Vec3*,float);
int fn_8024D9FC(char*,float);
float fn_8024D4E8(const Vec3*,const Vec3*,const Vec3*,const Vec3*,float);
void fn_801AFFBC(Vec3*,const Vec3*,float);
float fn_800AA53C(float,float);
float fn_80284FA8(float);
void fn_801F1B1C(Vec3*,const Quat*,const Vec3*);
void fn_802073E8(void*,int,void*,float);
}
inline void forward(Vec3*out,const Quat&q){Vec3 axis(lbl_8037B080,lbl_8037B080,lbl_8037B078);Vec3 r;fn_801F1B1C(&r,&q,&axis);*out=r;}
extern "C" float fn_8021EC10(PathOwner*self,const Vec3*origin,Vec3*position,Vec3*direction,float delta){
 Quat rotation;
 float t=self->time/self->duration;
 signed char done=0;
 if(t>=lbl_8037B078){t=lbl_8037B07C;done=1;}
 else if(t<lbl_8037B070)t=lbl_8037B070;
 float result;
 if(fn_801F7EB8(&self->path)){
  char*curve=resolvePath(PathHandle3(((PathObject*)resolvePath(self->path))->curve));
  result=fn_8024DA4C(curve,&self->path,position,t);
  signed char wrap=(self->flags&0x20000000ULL)?1:0;
  if(wrap){
   *position-=self->offset*(lbl_8037B078-fn_800AA53C(self->time,lbl_8037B078));
  }else if(self->flags&0x10000000ULL){
   *position-=self->offset;
  }
  if(!(self->flags&0x40000000ULL)&&fn_8024D9FC(curve,t)){
   self->flags|=0x40000000ULL;
   fn_802073E8(self,0x2A,resolvePath(self->handle24),lbl_8037B074);
  }
 }else{
  Vec3 cubic;
  fn_801AFFBC(&cubic,&self->cubic,t);
  Vec3 p=self->quadratic+cubic;
  p=p*t;
  p=self->linear+p;
  p=p*t;
  *position=self->constant+p;
  result=fn_8024D4E8(&self->cubic,&self->quadratic,&self->linear,&self->constant,t);
 }
 if(self->flags&0x04000000ULL){
  *direction=(*position-*origin).normalize();
 }else{
  if(self->angle!=lbl_8037B080){
   float u=lbl_8037B078-t;
   float a=fn_80284FA8(u*self->angle);
   float b=fn_80284FA8(t*self->angle);
   rotation.v=(self->from.v*a+self->to.v*b)*self->scale;
   rotation.w=self->scale*(self->from.w*a+self->to.w*b);
  }else rotation=self->from;
  forward(direction,rotation);
 }
 self->time+=delta;
 if(done)self->finish();
 else fn_802073E8(self,0x29,resolvePath(self->handle24),result);
 return result;
}
