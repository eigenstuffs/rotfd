/* fn_80083FF0: pushes the actor along the forward axis of its first child.
 * Resolves the actor's child 0 handle (virtual slot 0x9C), rotates the
 * forward axis (0,0,1) by the child's 3x3 basis (+0x30), normalizes it with
 * the raw frsqrte estimate, scales it by 5 and adds it to the actor
 * acceleration (+0x358), then advances the actor (fn_80092DAC).
 *
 * Matching notes: the original wrote Vec3(0,0,1)*rotation and
 * acceleration+=d*5.0f with pooled literals lbl_80378AD0 (0.0f),
 * lbl_80378ADC (1.0f) and lbl_80378AF4 (5.0f). Literal constants are
 * re-materialized at each use, so:
 * - each of the six 0.0 and three 1.0 uses in forwardAxis is a different
 *   read form of its label (no CSE temp; the back end merges them into one
 *   lfs each, like the literal);
 * - the 5.0 scale is read through a const reference once per component,
 *   after that component's acceleration load (a by-value float would be a
 *   variable defined before the first acceleration load and colours
 *   differently). The back end merges the three sda21 loads into one, and
 *   the separate px/py/pz products keep fmuls+fadds (no fmadds). */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3&operator+=(const Vec3&v){x+=v.x;y+=v.y;z+=v.z;return*this;}
 Vec3 operator*(float a)const{return Vec3(x*a,y*a,z*a);}
 void addScaled(const Vec3&v,const float&s){float px=v.x*s;x+=px;float py=v.y*s;y+=py;float pz=v.z*s;z+=pz;}
 float lengthSquared()const{return x*x+y*y+z*z;}
 void normalize(){float inverse=reciprocalSqrt(lengthSquared());x*=inverse;y*=inverse;z*=inverse;}};
struct Matrix{float m[3][3];};
inline Vec3 operator*(const Vec3&v,const Matrix&mm){Vec3 r;r.x=mm.m[0][0]*v.x+mm.m[1][0]*v.y+mm.m[2][0]*v.z;r.y=mm.m[0][1]*v.x+mm.m[1][1]*v.y+mm.m[2][1]*v.z;r.z=mm.m[0][2]*v.x+mm.m[1][2]*v.y+mm.m[2][2]*v.z;return r;}
struct Body{char unknown00[0x30];Matrix rotation;};
struct Prefix{char unknown00[8];};
struct Actor:Prefix{
virtual void v08();
virtual void v0C();
virtual void v10();
virtual void v14();
virtual void v18();
virtual void v1C();
virtual void v20();
virtual void v24();
virtual void v28();
virtual void v2C();
virtual void v30();
virtual void v34();
virtual void v38();
virtual void v3C();
virtual void v40();
virtual void v44();
virtual void v48();
virtual void v4C();
virtual void v50();
virtual void v54();
virtual void v58();
virtual void v5C();
virtual void v60();
virtual void v64();
virtual void v68();
virtual void v6C();
virtual void v70();
virtual void v74();
virtual void v78();
virtual void v7C();
virtual void v80();
virtual void v84();
virtual void v88();
virtual void v8C();
virtual void v90();
virtual void v94();
virtual void v98();
virtual const Handle_801F7F10*getChild(int);
char unknown0C[0x358-0xC];Vec3 acceleration;};
struct Owner{char unknown00[8];Actor*actor;};
extern "C"{extern const float lbl_80378AD0,lbl_80378ADC,lbl_80378AF4;}
extern "C"{void fn_80092DAC(Actor*,float);}
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline Vec3 forwardAxis(const Matrix&mm){Vec3 r;r.x=mm.m[0][0]*lbl_80378AD0+mm.m[1][0]**(const float*)&lbl_80378AD0+mm.m[2][0]*lbl_80378ADC;r.y=mm.m[0][1]**(const float*)(unsigned long)&lbl_80378AD0+mm.m[1][1]**(const float*)(long)&lbl_80378AD0+mm.m[2][1]**(const float*)&lbl_80378ADC;r.z=mm.m[0][2]**(const float*)(unsigned int)&lbl_80378AD0+mm.m[1][2]**(const float*)(int)&lbl_80378AD0+mm.m[2][2]**(const float*)(unsigned long)&lbl_80378ADC;return r;}
extern "C" void fn_80083FF0(Owner*self,float dt){
 Body*b=(Body*)resolve(*self->actor->getChild(0));
 Vec3 d=forwardAxis(b->rotation);
 d.normalize();
 Actor*a=self->actor;
 a->acceleration.addScaled(d,lbl_80378AF4);
 fn_80092DAC(self->actor,dt);
}
