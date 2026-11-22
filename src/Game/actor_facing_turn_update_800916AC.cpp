/* slot40__14CSpongeBobMoveFPC4Vec3PC4Vec3PC4Vec3if: actor facing update (controller move hook, same argument list as
   the forwarding slot40__16CCollectableMoveFPC4Vec3PC4Vec3PC4Vec3if: a, position, target, d, delta).

   - Control states 6/0x31/0x32/0x2F: face along the current planar forward axis
     (basis * (0,0,1) with y cleared, normalized), i.e. a yaw quaternion about
     lbl_802F4148 handed to the actor's virtual slot 0xC0.
   - States 0x16/0x33/0x38/0x39: forward to the controller's slot 0x18.
   - Otherwise, when the global settings (+0x164) are not disabled, aim the
     stored direction (+0x3C0) from the position to the target and face it; a
     pending snap flag (+0x448) instead applies the scene camera rotation.
   - With disabled settings, blend the facing toward the settings direction
     (+0x30/+0x38): the stored direction is lerped and renormalized, the yaw
     error (+0x3D0) is wrapped in degrees (fn_80075854), the turn speed (+0x3D8)
     ramps up and the facing is slerped (fn_8008D420); a small residual yaw
     clears the turn speed and snaps to the target yaw.

   Matching notes: lbl_80378BAC (0.0f) and lbl_80378BE8 (1.0f) were pooled
   literals of the original TU (the forward axis was basis.transform(0,0,1)
   with y = 0, so y*y folded to the constant).  Each literal use was its own
   load that the back end merged; a repeated extern read becomes a front-end
   common subexpression and shifts the f3/f4/f5 assignment.  The six zero uses
   of the forward axis therefore use six distinct read forms (plain, pointer,
   and the unsigned long/long/unsigned int/int address casts), the unit factor
   arrives as an inline parameter, and the zero of the lerped goal is read in
   the expression itself (not stored to a local first).  The integer-cast forms
   are used only before the first call: reused after a call they become a
   common address kept in a callee-saved register. */
struct Handle{signed int tag:8;signed int index:24;};
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
struct Vec3{
 float x,y,z;
 Vec3(){}
 Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return *this;}
 Vec3 operator*(float s)const{return Vec3(x*s,y*s,z*s);}
 Vec3 operator+(const Vec3&v)const{return Vec3(x+v.x,y+v.y,z+v.z);}
 Vec3&operator*=(float s){x*=s;y*=s;z*=s;return *this;}
 float lengthSquared()const{return x*x+y*y+z*z;}
};
struct Quat{float w;Vec3 v;};
extern "C"{
extern const float lbl_80378BAC; /* 0.0f */
extern const float lbl_80378BE8; /* 1.0f */
extern const float lbl_80378BEC; /* 0.5f */
extern const float lbl_80378BF0; /* 57.295776f (rad -> deg) */
extern const float lbl_80378BF4; /* 0.017453292f (deg -> rad) */
extern const float lbl_80378BF8; /* 1/180 */
extern const float lbl_80378BFC; /* 0.03141593f */
extern const float lbl_80378C00; /* 0.333f */
extern const float lbl_80378C04; /* 0.0001f */
extern const float lbl_80378BD8; /* 10.0f */
extern const float lbl_80378BC4; /* 2.0f */
extern const Vec3 lbl_802F4148;  /* yaw axis */
float fn_80285124(float,float);
float fn_8028506C(float);
float fn_80284FA8(float);
void fn_80075854(float*);
void fn_801F1AAC(Quat*);
Quat fn_8008D420(const Quat&,const Quat&,float);
}
struct Controller{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();
 virtual void move(void*,const Vec3*,const Vec3*,void*,float);};
struct Matrix{float m[9];};
struct Node{char unknown00[0x30];Matrix basis;};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
struct Camera{char unknown00[0x2D0];Vec3 position;Quat rotation;};
struct Scene{char unknown00[0x15058];Camera*camera;};
struct Settings{char unknown00[0x2E];signed char disabled;char unknown2F;float targetX;char unknown34[4];float targetZ;char unknown3C[0xC];float rate;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x3C];Settings*settings;}lbl_801E9D24;
inline Node*resolve(const Handle&h){int index=h.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct Prefix{char unknown00[8];};
struct Owner:Prefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
 virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
 virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
 virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
 virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();
 virtual const Handle*getHandle(int);
 virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();virtual void slotBC();
 virtual void setTransform(const Vec3*,const Quat*,int);
 char unknown0C[0x144-0xC];Vec3 velocity;char unknown150[0x318-0x150];char controller[0x3C0-0x318];
 Vec3 direction;char unknown3CC[4];float turn;char unknown3D4[4];float turnSpeed;char unknown3DC[0x448-0x3DC];signed char snap;
};
extern "C"{signed char fn_8007D604(void*,int);Controller*fn_8007DCF8(void*);}
/* basis * (0, 0, z) without the (dead) y row; each zero factor is its own read. */
inline Vec3 forwardTransform(const Matrix&basis,float z){
 const float*m=basis.m;
 Vec3 r;
 r.x=m[0]*lbl_80378BAC+m[3]**(const float*)&lbl_80378BAC+m[6]*z;
 r.z=m[2]**(const float*)(unsigned long)&lbl_80378BAC+m[5]**(const float*)(long)&lbl_80378BAC+m[8]*z;
 return r;
}
/* Forward axis of the actor's frame projected onto the ground plane, normalized
   (y = 0, so y*y is the constant 0). */
inline Vec3 planarForward(Owner*self){
 const Matrix&m=resolve(*self->getHandle(0))->basis;
 Vec3 f=forwardTransform(m,lbl_80378BE8);
 f.y=*(const float*)(unsigned int)&lbl_80378BAC;
 float inv=reciprocalSqrt(f.x*f.x+*(const float*)(int)&lbl_80378BAC+f.z*f.z);
 f.x*=inv;f.y*=inv;f.z*=inv;
 return f;
}
extern "C" void slot40__14CSpongeBobMoveFPC4Vec3PC4Vec3PC4Vec3if(Owner*self,void*a,const Vec3*position,const Vec3*target,void*d,float delta){
 if(fn_8007D604(self->controller,6)||fn_8007D604(self->controller,0x31)||fn_8007D604(self->controller,0x32)||fn_8007D604(self->controller,0x2F)){
  Vec3 forward=planarForward(self);
  float yaw=fn_80285124(forward.x,forward.z);
  float half=yaw*lbl_80378BEC;
  float cosine=fn_8028506C(half);
  float sine=fn_80284FA8(half);
  Quat q;q.w=cosine;q.v=lbl_802F4148*sine;
  self->setTransform(position,&q,0);
 }else if(fn_8007D604(self->controller,0x16)){
  fn_8007DCF8(self->controller)->move(a,position,target,d,delta);
 }else if(fn_8007D604(self->controller,0x33)){
  fn_8007DCF8(self->controller)->move(a,position,target,d,delta);
 }else if(fn_8007D604(self->controller,0x38)){
  fn_8007DCF8(self->controller)->move(a,position,target,d,delta);
 }else if(fn_8007D604(self->controller,0x39)){
  fn_8007DCF8(self->controller)->move(a,position,target,d,delta);
 }else if(!lbl_801E9D24.settings->disabled){
  self->direction.x=target->x-position->x;
  self->direction.z=target->z-position->z;
  self->direction.y=lbl_80378BAC;
  float yaw=fn_80285124(self->direction.x,self->direction.z);
  float half=yaw*lbl_80378BEC;
  Quat q;q.w=fn_8028506C(half);q.v=lbl_802F4148*fn_80284FA8(half);
  if(self->snap==1){
   self->snap=0;
   Quat rotation=lbl_801E9D24.scene->camera->rotation;
   fn_801F1AAC(&rotation);
   self->setTransform(&lbl_801E9D24.scene->camera->position,&rotation,0);
  }else{
   self->setTransform(position,&q,0);
  }
 }else{
  Vec3 forward=planarForward(self);
  float yaw=fn_80285124(forward.x,forward.z);
  float half=yaw*lbl_80378BEC;
  float cosine=fn_8028506C(half);
  float sine=fn_80284FA8(half);
  Quat current;current.w=cosine;current.v=lbl_802F4148*sine;
  Vec3 goal;goal.x=lbl_801E9D24.settings->targetX;
  goal.z=lbl_801E9D24.settings->targetZ;
  float goalYaw=fn_80285124(goal.x,goal.z);
  self->turn=yaw-goalYaw;
  float goalHalf=goalYaw*lbl_80378BEC;
  float goalCosine=fn_8028506C(goalHalf);
  float goalSine=fn_80284FA8(goalHalf);
  Quat wanted;wanted.w=goalCosine;wanted.v=lbl_802F4148*goalSine;
  float remain=lbl_80378BE8-delta;
  self->direction=forward*remain+Vec3(goal.x*delta,lbl_80378BAC*delta,goal.z*delta);
  float inv=reciprocalSqrt(self->direction.lengthSquared());
  self->direction*=inv;
  float degrees=lbl_80378BF0*self->turn;
  fn_80075854(&degrees);
  self->turn=lbl_80378BF4*degrees;
  float error=__fabs(degrees);
  float blend=lbl_80378BE8-lbl_80378BF8*error;
  Quat result;
  if((float)__fabs(self->turn)>lbl_80378BFC){
   if(blend<=lbl_80378C00){
    float y=self->velocity.y;
    self->velocity.y=lbl_80378BAC;
    float sq=self->velocity.lengthSquared();
    if(lbl_80378BAC!=sq){float s=reciprocalSqrt(sq);self->velocity.x*=s;self->velocity.y*=s;self->velocity.z*=s;}
    self->velocity*=lbl_80378C04;
    self->velocity.y=y;
   }
   if(self->turnSpeed<lbl_80378BD8*delta)self->turnSpeed+=lbl_80378BC4*delta;
   else self->turnSpeed=lbl_80378BD8*delta;
   self->turnSpeed*=lbl_801E9D24.settings->rate;
   result=fn_8008D420(current,wanted,self->turnSpeed);
  }else{
   self->turnSpeed=lbl_80378BAC;
   result=wanted;
  }
  self->setTransform(position,&result,0);
 }
}
