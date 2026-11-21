/* Reflects the actor's velocity (+0x15C) about its contact normal (+0x1B8),
 * damps the result per axis into +0x144, then notifies the python event
 * monitor. Needs -opt nocse (the velocity copy stays in its own registers). */
struct Vec3{float x,y,z;Vec3(){}Vec3(float xx,float yy,float zz):x(xx),y(yy),z(zz){}
 Vec3 operator*(float s)const{return Vec3(x*s,y*s,z*s);}
 Vec3 operator-(const Vec3&o)const{return Vec3(x-o.x,y-o.y,z-o.z);}
 float dot(const Vec3&o)const{return x*o.x+y*o.y+z*o.z;}};
struct Actor{char unknown00[0x144];Vec3 result;char unknown150[0xC];Vec3 velocity;char unknown168[0x50];Vec3 normal;char unknown1C4[0x15C];int key320;};
struct Owner{char unknown00[8];Actor*actor;};
struct Monitor{char unknown00[0x130];void*first;void*second;};
extern "C"{extern Monitor*lbl_803776B8;extern const float lbl_80378B10,lbl_80378AE4,lbl_80378B14;void fn_8006803C(Monitor*,int);}
extern "C" void fn_80085958(Owner*self){
 Actor*actor=self->actor;
 Vec3 velocity(actor->velocity);
 Vec3 reflected=velocity-actor->normal*(lbl_80378B10*velocity.dot(actor->normal));
 reflected.x*=lbl_80378AE4;
 reflected.y*=lbl_80378B14;
 reflected.z*=lbl_80378AE4;
 actor->result=reflected;
 if(lbl_803776B8&&lbl_803776B8->first)fn_8006803C(lbl_803776B8,self->actor->key320);
}
