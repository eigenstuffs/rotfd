/* Early actor contact friction step (fn_800822D0).
 * Builds the net force (+0x358, plus -1 * mass (+0x354) on y while flag bit
 * 0x8000000000 is set), takes its component along the contact normal
 * (+0x1B8) as the pressure, and projects the velocity (+0x15C) onto the
 * contact plane. When the tangential speed squared exceeds the threshold at
 * +0x368, the unit tangent scaled by 10 * pressure is added to the force.
 * Below 0.1 the actor record (+0x318) gets the state from fn_80092844; then
 * the actor's update virtual (slot 0x198) runs with the frame delta.
 *
 * Matching notes: the tangent length squared is written out per component
 * (lengthSquared() changes the FPR colouring order), and common subexpression
 * elimination is off for this function (the velocity loads stay temporaries).
 * The engine's fast normalize uses the raw frsqrte estimate (no frsp), which
 * no compiler built-in emits, so the math helper is the established minimal
 * inline asm statement. */
typedef unsigned long Word;
extern "C" {extern const float lbl_80378D58,lbl_80378AD0,lbl_80378AD4,lbl_80378AE4;}
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return*this;}
 Vec3 operator*(float a)const{return Vec3(x*a,y*a,z*a);}
 Vec3 operator-(const Vec3&o)const{return Vec3(x-o.x,y-o.y,z-o.z);}
 Vec3&operator+=(const Vec3&v){x+=v.x;y+=v.y;z+=v.z;return*this;}
 Vec3&operator*=(float a){x*=a;y*=a;z*=a;return*this;}
 float dot(const Vec3&o)const{return x*o.x+y*o.y+z*o.z;}
 float lengthSquared()const{return x*x+y*y+z*z;}
 void normalize(){if(lbl_80378AD0!=lengthSquared()){float inverse=reciprocalSqrt(lengthSquared());x*=inverse;y*=inverse;z*=inverse;}}};
struct Record{char opaque;};
struct Prefix{Word unknown00,unknown04;};
struct Actor:Prefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void v34();virtual void v38();virtual void v3C();virtual void v40();virtual void v44();virtual void v48();virtual void v4C();virtual void v50();virtual void v54();virtual void v58();virtual void v5C();virtual void v60();virtual void v64();virtual void v68();virtual void v6C();virtual void v70();virtual void v74();virtual void v78();virtual void v7C();virtual void v80();virtual void v84();virtual void v88();virtual void v8C();virtual void v90();virtual void v94();virtual void v98();virtual void v9C();virtual void vA0();virtual void vA4();virtual void vA8();virtual void vAC();virtual void vB0();virtual void vB4();virtual void vB8();virtual void vBC();virtual void vC0();virtual void vC4();virtual void vC8();virtual void vCC();virtual void vD0();virtual void vD4();virtual void vD8();virtual void vDC();virtual void vE0();virtual void vE4();virtual void vE8();virtual void vEC();virtual void vF0();virtual void vF4();virtual void vF8();virtual void vFC();virtual void v100();virtual void v104();virtual void v108();virtual void v10C();virtual void v110();virtual void v114();virtual void v118();virtual void v11C();virtual void v120();virtual void v124();virtual void v128();virtual void v12C();virtual void v130();virtual void v134();virtual void v138();virtual void v13C();virtual void v140();virtual void v144();virtual void v148();virtual void v14C();virtual void v150();virtual void v154();virtual void v158();virtual void v15C();virtual void v160();virtual void v164();virtual void v168();virtual void v16C();virtual void v170();virtual void v174();virtual void v178();virtual void v17C();virtual void v180();virtual void v184();virtual void v188();virtual void v18C();virtual void v190();virtual void v194();
 virtual void update(float);
 char unknown0C[0x24];unsigned long long flags;char unknown38[0x124];Vec3 velocity;char unknown168[0x50];Vec3 normal;
 char unknown1C4[0x154];Record record;char unknown319[0x3B];float mass;Vec3 force;char unknown364[4];float threshold;};
struct Owner{Word unknown00,unknown04;Actor*actor;};
extern "C" {int fn_80092844(Actor*);void fn_8007D6A0(Record*,int);}
#pragma opt_common_subs off
extern "C" void fn_800822D0(Owner*self,float delta){
 Actor*actor=self->actor;
 Vec3 normal=actor->normal;
 Vec3 force=actor->force;
 if(actor->flags&0x8000000000ULL){float gravity=lbl_80378D58*actor->mass;force.y+=gravity;}
 float pressure=normal.dot(force);
 Vec3 tangent=actor->velocity-normal*normal.dot(actor->velocity);
 float speedSq=tangent.x*tangent.x+tangent.y*tangent.y+tangent.z*tangent.z;
 if(speedSq>actor->threshold){
  tangent.normalize();
  tangent*=lbl_80378AD4*pressure;
  actor->force+=tangent;
 }
 if(speedSq<lbl_80378AE4)fn_8007D6A0(&self->actor->record,fn_80092844(self->actor));
 self->actor->update(delta);
}
#pragma opt_common_subs reset
