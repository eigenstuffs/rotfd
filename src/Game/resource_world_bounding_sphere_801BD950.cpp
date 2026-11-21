/* fn_801BD950: compute a world-space bounding sphere for the owner's object.
   Resource type 5 selects one of several local spheres by kind (0/1: scaled
   by the matrix x-axis length and translated, 4: transformed by
   fn_80099A00, 2: translated only, 3: fn_8024673C); other resource types
   transform the resource bounds at +0xC unless kind is 3. Returns 1 when a
   sphere was written. */
extern "C" const float lbl_8037A2F8;
inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
struct Handle{signed int tag:8;signed int index:24;};
struct Vec3{float x,y,z;
Vec3(){}
Vec3(float ax,float ay,float az):x(ax),y(ay),z(az){}
Vec3(const Vec3&o):x(o.x),y(o.y),z(o.z){}
void operator*=(float s){x*=s;y*=s;z*=s;}
void operator+=(const Vec3&o){x+=o.x;y+=o.y;z+=o.z;}
float length()const{float sq=x*x+y*y+z*z;float r=lbl_8037A2F8;if(sq!=r)r=fastSqrt(sq);return r;}
};
struct Sphere{Vec3 center;float radius;
Sphere&operator=(const Sphere&o){center.x=o.center.x;center.y=o.center.y;center.z=o.center.z;radius=o.radius;return *this;}};
struct Matrix{float m[16];
Vec3 column0()const{return Vec3(m[0],m[4],m[8]);}
const Vec3&position()const{return *(const Vec3*)&m[12];}
Vec3 translation()const{return Vec3(m[12],m[13],m[14]);}
};
struct Prefix{char unknown00[8];};
struct Owner:Prefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();
virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();
virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();
virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();
virtual void slot98();virtual const Handle*getHandle(int);
};
struct Resource{char unknown00[0xC];Sphere bounds;char unknown1C[0x6C-0x1C];unsigned short type;char unknown6E[0x74-0x6E];
Sphere*sphere74;Sphere*sphere78;char unknown7C[0x90-0x7C];Sphere*sphere90;char unknown94[0xA8-0x94];Sphere*sphereA8;};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
extern "C"{extern struct{char unknown00[0x118];Manager*manager;}lbl_801E9D24;}
inline void*resolve(const Handle&h){int index=h.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.tag)return m->entries[index].object;return 0;}
struct Object{char unknown00[0x1C];Handle resource;char unknown20[0x124-0x20];Matrix*matrix;
Resource*getResource()const{return static_cast<Resource*>(resolve(resource));}};
extern "C"{Sphere fn_80099A00(const Matrix*,const Sphere*);signed char fn_8024673C(Resource*,Object*,Sphere*);}
extern "C" int fn_801BD950(Owner*self,Sphere*out,unsigned short kind,int index){
    Object*object=static_cast<Object*>(resolve(*self->getHandle(index)));
    Resource*resource=object->getResource();
    Matrix*matrix=object->matrix;
    float scale=matrix->column0().length();
    Vec3 translation=matrix->position();
    if(resource->type==5){
        if(kind==0){
            if(resource->sphere74){*out=*resource->sphere74;out->center*=scale;out->center+=translation;out->radius*=scale;return 1;}
        }else if(kind==1){
            if(resource->sphere78){*out=*resource->sphere78;out->center*=scale;out->center+=translation;out->radius*=scale;return 1;}
        }else if(kind==4){
            if(resource->sphereA8){*out=fn_80099A00(matrix,resource->sphereA8);return 1;}
        }else if(kind==2){
            if(resource->sphere90){*out=*resource->sphere90;out->center+=object->matrix->translation();return 1;}
        }else if(kind==3){
            if(fn_8024673C(resource,object,out))return 1;
        }
        return 0;
    }
    if(kind==3)return 0;
    *out=fn_80099A00(matrix,&resource->bounds);
    return 1;
}
