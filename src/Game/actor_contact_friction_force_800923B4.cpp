/* Actor contact friction force (slot190__14CSpongeBobMoveFv): companion of fn_800822D0 acting on the actor itself.
 * Adds gravity (lbl_80378D58 * mass) to the net force y while flag 0x8000000000 is set, takes the
 * pressure along the contact normal, and adds the unit velocity tangent scaled by pressure * +0x364
 * (and by speedSq / threshold below the +0x368 threshold) to the force at +0x358.
 * Matching notes: CSE is off for the function (as in fn_800822D0); the normal is copied through
 * y, x, z float locals, which fixes the FPR colouring of the normal components. */
typedef unsigned long Word;
extern "C" {extern const float lbl_80378D58,lbl_80378BAC;}
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return*this;}
 Vec3 operator*(float a)const{return Vec3(x*a,y*a,z*a);}
 Vec3 operator-(const Vec3&o)const{return Vec3(x-o.x,y-o.y,z-o.z);}
 Vec3&operator+=(const Vec3&v){x+=v.x;y+=v.y;z+=v.z;return*this;}
 Vec3&operator*=(float a){x*=a;y*=a;z*=a;return*this;}
 float dot(const Vec3&o)const{return x*o.x+y*o.y+z*o.z;}
 float lengthSquared()const{return x*x+y*y+z*z;}
 void normalize(){if(lbl_80378BAC!=lengthSquared()){float inverse=reciprocalSqrt(lengthSquared());x*=inverse;y*=inverse;z*=inverse;}}};
struct Actor{char unknown00[0x30];unsigned long long flags;char unknown38[0x124];Vec3 velocity;char unknown168[0x50];Vec3 normal;
 char unknown1C4[0x190];float mass;Vec3 force;float scale;float threshold;};
#pragma opt_common_subs off
extern "C" void slot190__14CSpongeBobMoveFv(Actor*actor){
 Vec3 force=actor->force;
 if(actor->flags&0x8000000000ULL){float gravity=lbl_80378D58*actor->mass;force.y+=gravity;}
 float ny=actor->normal.y;float nx=actor->normal.x;float nz=actor->normal.z;Vec3 normal(nx,ny,nz);
 float pressure=normal.dot(force);
 Vec3 tangent=actor->velocity-normal*normal.dot(actor->velocity);
 float speedSq=tangent.x*tangent.x+tangent.y*tangent.y+tangent.z*tangent.z;
 float threshold=actor->threshold;
 if(speedSq>threshold){
  tangent.normalize();
  tangent*=pressure*actor->scale;
  actor->force+=tangent;
 }else{
  float ratio=speedSq/threshold;
  tangent.normalize();
  tangent*=ratio*(pressure*actor->scale);
  actor->force+=tangent;
 }
}
#pragma opt_common_subs reset
