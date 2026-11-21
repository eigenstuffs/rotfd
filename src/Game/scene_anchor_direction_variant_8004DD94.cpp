/* Scene anchor/target setup variant: caches the anchor position, normalizes the owner-to-target direction and reads seven parameters.
 * The fast normalize uses a minimal inline asm frsqrte (no frsp), which no compiler built-in emits. */
struct Handle{signed int tag:8;signed int index:24;};
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return*this;}Vec3 operator-(const Vec3&v)const{return Vec3(x-v.x,y-v.y,z-v.z);}Vec3&operator*=(float a){x*=a;y*=a;z*=a;return*this;}float lengthSquared()const{return x*x+y*y+z*z;}void normalize();};
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
struct Transform{char unknown00[0x30];Vec3 position;Vec3 positionByValue()const{return Vec3(position.x,position.y,position.z);}Vec3 positionCopy()const{Vec3 p;p.x=position.x;p.y=position.y;p.z=position.z;return p;}};
struct Entity{char unknown00[0x124];Transform*transform;};
struct ActorIndex{int value;ActorIndex(int v):value(v){}operator const int&()const{return value;}};
struct Entry{Entity*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};
struct Manager{int count,capacity;EntryArray entries;};
extern "C" struct Context{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
inline Entity*resolve(const Handle&h){Manager*m=lbl_801E9D24.manager;const ActorIndex index(h.index);const signed char tag=h.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
extern "C"{void fn_801F86C8(Manager*,const Handle*,int);}
struct RefHandle:Handle{void assign(const Handle&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);*(Handle*)this=h;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct Object{char unknown00[0x38];unsigned long long flags38;char unknown40[0x18];RefHandle owner;char unknown5C[0x14];RefHandle anchor;RefHandle target;Vec3 anchorPosition;Vec3 direction;float value90;unsigned char mode94,mode95,mode96;char unknown97;float value98,value9C,valueA0;};
extern "C"{extern const float lbl_80378570,lbl_80378578;const Handle*fn_8025E1D4(Object*,int);float fn_8025E268(Object*,int);unsigned long fn_801F7EB8(const Handle*);}
inline void Vec3::normalize(){if(lbl_80378570!=lengthSquared()){float inverse=reciprocalSqrt(lengthSquared());x*=inverse;y*=inverse;z*=inverse;}}
extern "C" void fn_8004DD94(Object*self){
 self->flags38|=0x40000000ULL;
 self->anchor.assign(*fn_8025E1D4(self,0));
 self->target.assign(*fn_8025E1D4(self,1));
 self->anchorPosition=resolve(self->anchor)->transform->positionByValue();
 if(fn_801F7EB8(&self->target))self->direction=resolve(self->target)->transform->positionCopy()-resolve(self->owner)->transform->positionByValue();
 self->direction.normalize();
 self->value90=fn_8025E268(self,0);
 self->mode94=(int)fn_8025E268(self,1);
 self->mode95=(int)fn_8025E268(self,2);
 self->mode96=(int)fn_8025E268(self,3);
 self->value98=fn_8025E268(self,4);
 self->value9C=fn_8025E268(self,5);
 self->valueA0=fn_8025E268(self,6);
}
