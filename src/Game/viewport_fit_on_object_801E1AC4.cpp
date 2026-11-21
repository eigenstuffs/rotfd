/* Viewport FitOnObject: finds the named child of the viewport's scene root
 * (handle +0x10), takes its world bounding sphere (local sphere of the bound
 * object, transformed by fn_80099A00) and moves the camera (handle +0x14) along
 * its current view direction so that it sits lbl_8037A59C + radius in front of
 * the sphere centre (fn_8023D100).  "Object Not Found..." is logged otherwise. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Console;
struct Context{char unknown00[0x110];Console*console;char unknown114[4];Manager*manager;};
struct Vec3{float x,y,z;Vec3(){}Vec3(const Vec3&v){x=v.x;y=v.y;z=v.z;}Vec3(float ax,float ay,float az){x=ax;y=ay;z=az;}
 void operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;}
 Vec3 operator-(const Vec3&v)const{return Vec3(x-v.x,y-v.y,z-v.z);}
 Vec3 operator*(float s)const{return Vec3(x*s,y*s,z*s);}
 void operator*=(float s){x*=s;y*=s;z*=s;}
 float lengthSquared()const{return x*x+y*y+z*z;}};
extern "C"{
extern Context lbl_801E9D24;
extern const Vec3 game_vec4_zero;
extern const float lbl_8037A598,lbl_8037A59C;
extern const char lbl_802ACE98[];
void fn_801F86C8(Manager*,const void*,int);
void*fn_801F7EB8(const Handle_801F7F10*);
void fn_801FA014(Console*,const char*,...);
}
struct Sphere{Vec3 point;float radius;Sphere():point(game_vec4_zero),radius(lbl_8037A598){}
 void operator=(const Sphere&s){point=s.point;radius=s.radius;}};
template<class T>inline T*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return (T*)m->entries[index].object;return 0;}
struct Zero1:Handle_801F7F10{Zero1(){word=0;}~Zero1(){}};
struct Ref:Zero1{
 Ref(){word=0;}
 Ref(const Ref&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 Ref(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 ~Ref(){}
};
struct Child:Ref{
 Child(){word=0;}
 Child(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 ~Child(){}
};
struct Name{Word word;};
struct Matrix;
struct Bounds{char unknown00[0xC];Sphere sphere;};
struct Object{char unknown00[0x1C];Handle_801F7F10 bounds;char unknown20[0x104];Matrix*matrix;};
struct Target{char unknown00[0x124];Vec3 position;};
struct Camera{char unknown00[0x1C];Handle_801F7F10 target;char unknown20[0x98];Vec3 position;};
struct Root;
struct Viewport{char unknown00[0x10];Handle_801F7F10 root,camera;};
extern "C"{Ref fn_8026A494(Root*,const Name&);Sphere fn_80099A00(const Matrix*,const Sphere*);void fn_8023D100(Camera*,const Vec3*);}
inline float reciprocalSqrt(register float value){register float result;asm{frsqrte result,value}return result;}
extern "C" void fn_801E1AC4(Viewport*self,Name name){
 if(!fn_801F7EB8(&self->camera))return;
 if(!fn_801F7EB8(&self->root))return;
 Ref object(fn_8026A494(resolve<Root>(self->root),name));
 if(!fn_801F7EB8(&object)){fn_801FA014(lbl_801E9D24.console,lbl_802ACE98);return;}
 Sphere sphere;
 if(fn_801F7EB8(&resolve<Object>(object)->bounds))sphere=resolve<Bounds>(resolve<Object>(object)->bounds)->sphere;
 sphere=fn_80099A00(resolve<Object>(object)->matrix,&sphere);
 Target*target=resolve<Target>(Child(resolve<Camera>(self->camera)->target));
 Camera*camera=resolve<Camera>(self->camera);
 float tx=target->position.x,ty=target->position.y,tz=target->position.z;
 Vec3 direction(tx-camera->position.x,ty-camera->position.y,tz-camera->position.z);
 float inverse=reciprocalSqrt(direction.lengthSquared());
 float distance=lbl_8037A59C+sphere.radius;
 direction*=inverse;
 Vec3 position=sphere.point-direction*distance;
 fn_8023D100(resolve<Camera>(self->camera),&position);
}
