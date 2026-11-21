/* Two-target camera framing: derives a focus point from each selected resource
 * (lbl_803775C8 / lbl_803775CC), pulls the second one away horizontally, keeps a
 * cached side offset (cross(up, delta) normalized and scaled by the bounds radius)
 * and hands both points to the screen camera (fn_8006D174).
 * Observed field views only. */
typedef unsigned long Word;
struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
/* Second handle view: the fallback bounds lookup reads the owner handle through a
   distinct handle type, which keeps the compiler from reusing the earlier bitfield reads. */
struct OwnHandle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}
    Vec3&operator+=(const Vec3&v){x+=v.x;y+=v.y;z+=v.z;return*this;}
    Vec3&operator*=(float a){x*=a;y*=a;z*=a;return*this;}
    float lengthSquared()const{return x*x+y*y+z*z;}};
struct Sphere{Vec3 center;float radius;};
struct Transform{char unknown00[0x30];Vec3 position;Vec3 getPosition()const{return Vec3(position.x,position.y,position.z);}};
struct Node{char unknown00[0x74];Sphere*bounds74;Sphere*bounds78;char unknown7C[0xA8];Transform*transform;char unknown128[0x40];Handle child;};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
extern "C" struct Globals{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
struct Resource{char unknown00[0x58];Handle related;char unknown5C[0x14];Handle own;const OwnHandle&ownView()const{return*(const OwnHandle*)&own;}};
struct Current{char unknown00[0x118];Vec3 home;char unknown124[0xE8];Vec3 offset;};
extern "C"{extern Resource*lbl_803775C8,*lbl_803775CC;extern const float lbl_80378334,lbl_80378338,lbl_8037833C,lbl_80378340;extern Vec3 lbl_802F4148;extern Vec3 game_vec3_zero;
double __fabs(double);Current*fn_8007D074();void fn_8006D174(const Vec3*,const Vec3*);}
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
inline Node*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline Node*resolve(const OwnHandle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline bool pairEqual(float x,float y){bool result=false;if((float)__fabs(x)<lbl_8037833C){if((float)__fabs(y)<lbl_8037833C)result=true;}return result;}
inline signed char vecEqual(float x,float y,float z){signed char result=0;if(pairEqual(x,y)&&(float)__fabs(z)<lbl_8037833C)result=1;return result;}
extern "C" void fn_8002C31C(){
Resource*r;
if(lbl_803775C8!=(Resource*)-1)r=lbl_803775C8;
else{r=lbl_803775CC;if(r==(Resource*)-1)return;}
{
Vec3 target;
Vec3 pos=resolve(r->related)->transform->getPosition();
Sphere*s=resolve(resolve(r->own)->child)->bounds78;
if(!s)s=resolve(resolve(r->ownView())->child)->bounds74;
else pos.y-=lbl_80378334;
pos+=s->center;
Current*c=fn_8007D074();
if(lbl_803775C8!=(Resource*)-1&&lbl_803775CC!=(Resource*)-1){
Resource*o=lbl_803775CC;
target=resolve(o->related)->transform->getPosition();
Sphere*q=resolve(resolve(o->own)->child)->bounds78;
if(!q)q=resolve(resolve(o->ownView())->child)->bounds74;
target+=q->center;
float dx=pos.x-target.x,dy=pos.y-target.y,dz=pos.z-target.z;
target.z-=*(const float*)&lbl_80378338*(pos.z-target.z);target.x-=lbl_80378338*dx;
float ex=c->offset.x-game_vec3_zero.x;float ez=c->offset.z-game_vec3_zero.z;float ey=c->offset.y-game_vec3_zero.y;
if(vecEqual(ex,ey,ez)){
Vec3&up=lbl_802F4148;
Vec3 cr(up.y*dz-up.z*dy,up.z*dx-up.x*dz,up.x*dy-up.y*dx);
cr*=reciprocalSqrt(cr.lengthSquared());cr*=lbl_80378340+q->radius;c->offset=cr;
}
target+=c->offset;
}else{
target=c->home;
}
fn_8006D174(&target,&pos);
}
}
