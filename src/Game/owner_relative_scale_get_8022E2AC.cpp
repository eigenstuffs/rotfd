/* X-axis scale of the indexed object's matrix relative to the related
   owner's primary object (fn_8022E2AC): the product of the two matrices
   (fn_801F1080, returned by value from an inline helper, which gives the
   original 64-byte copy) and the length of its first column.  Same
   fastSqrt helper as owner_position_distance_80066DA4.cpp; same flags as
   owner_relative_position_get.cpp. */
#pragma fp_contract on
extern "C" const float lbl_8037B18C;
inline float fastSqrt(register float x){register float r;asm{frsqrte f4,x
fres r,f4}return r;}
struct RelativeScaleHandle{signed int generation:8;signed int index:24;};
struct RelativeScaleStorage{char unknown00[8];};
struct RelativeScaleOwner:RelativeScaleStorage{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const RelativeScaleHandle*getHandle(int);char unknown0C[0x19C];RelativeScaleHandle related;};
struct RelativeScaleEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct RelativeScaleManager{char unknown00[8];RelativeScaleEntry*entries;};
extern "C"{extern struct{char unknown00[0x118];RelativeScaleManager*manager;}lbl_801E9D24;}
static inline char*resolveRelativeScale(const RelativeScaleHandle&h){int index=h.index;RelativeScaleManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return m->entries[index].object;return 0;}
struct RelativeScaleMatrix{float m[16];};
extern "C" void fn_801F1080(const RelativeScaleMatrix*,const RelativeScaleMatrix*,RelativeScaleMatrix*);
inline float lengthRelativeScale(float x,float y,float z){float sq=x*x+y*y+z*z;float r=lbl_8037B18C;if(sq!=r)r=fastSqrt(sq);return r;}
inline RelativeScaleMatrix multiplyRelativeScale(const RelativeScaleMatrix&a,const RelativeScaleMatrix&b){RelativeScaleMatrix r;fn_801F1080(&a,&b,&r);return r;}
extern "C" float fn_8022E2AC(RelativeScaleOwner*self,int index){char*object=resolveRelativeScale(*self->getHandle(index));RelativeScaleOwner*related=(RelativeScaleOwner*)resolveRelativeScale(self->related);char*primary=resolveRelativeScale(*related->getHandle(0));RelativeScaleMatrix m=multiplyRelativeScale(**(RelativeScaleMatrix**)(primary+0x124),**(RelativeScaleMatrix**)(object+0x124));return lengthRelativeScale(m.m[0],m.m[4],m.m[8]);}
