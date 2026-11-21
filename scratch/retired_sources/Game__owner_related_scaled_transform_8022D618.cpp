/* Scaled transform setters on the related owner's primary object
   (fn_8022D618, fn_8022D888, fn_8022DA44).  Each resolves the indexed
   object and the related owner's primary object, refreshes the primary's
   cached inverse matrix, and forwards the value multiplied by the length of
   the inverse's first column (X-axis scale) to the object setter.
   The engine square root is the bare reciprocal of a reciprocal-square-root
   estimate (frsqrte into f4, then fres), written as the same minimal inline
   asm helper as owner_position_distance_80066DA4.cpp.
   The point transform must be written in the function body (an inline
   helper changes the float register coloring). Build with -fp_contract on
   and the -O4,p flags of owner_related_transform_apply.cpp. */
#pragma fp_contract on
struct RelatedScaleHandle{signed int generation:8;signed int index:24;};struct RelatedScalePoint{float x,y,z;RelatedScalePoint(){}RelatedScalePoint(float a,float b,float c):x(a),y(b),z(c){}};struct RelatedScaleQuat{float x,y,z,w;};struct RelatedScaleBasis{float v[9];};struct RelatedScaleMatrix{float m[16];};
struct RelatedScaleStorage{char unknown00[8];};struct RelatedScaleOwner:RelatedScaleStorage{
virtual void slot8();
virtual void slotC();
virtual void slot10();
virtual void slot14();
virtual void slot18();
virtual void slot1C();
virtual void slot20();
virtual void slot24();
virtual void slot28();
virtual void slot2C();
virtual void slot30();
virtual void slot34();
virtual void slot38();
virtual void slot3C();
virtual void slot40();
virtual void slot44();
virtual void slot48();
virtual void slot4C();
virtual void slot50();
virtual void slot54();
virtual void slot58();
virtual void slot5C();
virtual void slot60();
virtual void slot64();
virtual void slot68();
virtual void slot6C();
virtual void slot70();
virtual void slot74();
virtual void slot78();
virtual void slot7C();
virtual void slot80();
virtual void slot84();
virtual void slot88();
virtual void slot8C();
virtual void slot90();
virtual void slot94();
virtual void slot98();
virtual const RelatedScaleHandle*getHandle(int);
char unknown0C[0x19C];RelatedScaleHandle related;};
struct RelatedScaleObject{char unknown00[0xC];RelatedScaleHandle owner;char unknown10[0x20];RelatedScaleBasis rotation,basis;char unknown78[0xA8];unsigned long flags;RelatedScaleMatrix*matrix,*inverse;short unknown12C,index;};
struct RelatedScaleEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};struct RelatedScaleManager{char unknown00[8];RelatedScaleEntry*entries;};struct RelatedScalePool{RelatedScaleMatrix*pages[6];unsigned char active;};
extern "C"{extern struct{char unknown00[0x118];RelatedScaleManager*manager;char unknown11C[0x18];RelatedScalePool*pool;}lbl_801E9D24;extern const float lbl_8037B18C;void fn_801F2124(const RelatedScaleBasis*,RelatedScaleBasis*);RelatedScaleQuat*fn_801F20F4(RelatedScaleQuat*,const RelatedScaleBasis*);void fn_801F1BB0(RelatedScaleQuat*,const RelatedScaleQuat*);void fn_801F230C(const RelatedScaleMatrix*,RelatedScaleMatrix*);void fn_8023CD38(void*,const RelatedScalePoint*,const RelatedScaleQuat*,const float*);void fn_8023CEC4(void*,float);void fn_8023CFE4(void*,const RelatedScalePoint*,float);}
inline float fastSqrt(register float x){register float r;asm{frsqrte f4,x
fres r,f4}return r;}
inline char*resolveRelatedScale(const RelatedScaleHandle&h){int index=h.index;RelatedScaleManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return m->entries[index].object;return 0;}
inline void refreshRelatedScaleInverse(RelatedScaleObject*object){if(object->flags&0x20){object->inverse=&lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active][object->index];fn_801F230C(object->matrix,object->inverse);object->flags&=~0x20;}}
inline float lengthRelatedScale(float x,float y,float z){float sq=x*x+y*y+z*z;float r=lbl_8037B18C;if(sq!=r)r=fastSqrt(sq);return r;}
inline float scaleRelatedScale(const RelatedScaleMatrix&m){return lengthRelatedScale(m.m[0],m.m[4],m.m[8]);}
extern "C" void fn_8022D618(RelatedScaleOwner*self,const RelatedScalePoint*point,const RelatedScaleQuat*rotation,int index,float value){RelatedScaleObject*object=(RelatedScaleObject*)resolveRelatedScale(*self->getHandle(index));RelatedScaleOwner*related=(RelatedScaleOwner*)resolveRelatedScale(self->related);RelatedScaleObject*primary=(RelatedScaleObject*)resolveRelatedScale(*related->getHandle(0));refreshRelatedScaleInverse(primary);const RelatedScaleMatrix&inverse=*primary->inverse;if(primary->flags&0x40){fn_801F2124(&primary->rotation,&primary->basis);primary->flags&=~0x40;}RelatedScaleQuat composed;fn_801F20F4(&composed,&primary->basis);fn_801F1BB0(&composed,rotation);const RelatedScaleMatrix&m=inverse;const RelatedScalePoint&v=*point;float Y=m.m[1]*v.x+m.m[5]*v.y+m.m[9]*v.z+m.m[13];float X=m.m[0]*v.x+m.m[4]*v.y+m.m[8]*v.z+m.m[12];float Z=m.m[2]*v.x+m.m[6]*v.y+m.m[10]*v.z+m.m[14];RelatedScalePoint transformed(X,Y,Z);float scaled=value*lengthRelatedScale(m.m[0],m.m[4],m.m[8]);fn_8023CD38(object,&transformed,&composed,&scaled);}
extern "C" void fn_8022D888(RelatedScaleOwner*self,int index,float value){RelatedScaleObject*object=(RelatedScaleObject*)resolveRelatedScale(*self->getHandle(index));RelatedScaleOwner*related=(RelatedScaleOwner*)resolveRelatedScale(self->related);RelatedScaleObject*primary=(RelatedScaleObject*)resolveRelatedScale(*related->getHandle(0));refreshRelatedScaleInverse(primary);fn_8023CEC4(object,value*scaleRelatedScale(*primary->inverse));}
extern "C" void fn_8022DA44(RelatedScaleOwner*self,const RelatedScalePoint*point,int index,float value){RelatedScaleObject*object=(RelatedScaleObject*)resolveRelatedScale(*self->getHandle(index));RelatedScaleOwner*related=(RelatedScaleOwner*)resolveRelatedScale(self->related);RelatedScaleObject*primary=(RelatedScaleObject*)resolveRelatedScale(*related->getHandle(0));refreshRelatedScaleInverse(primary);const RelatedScaleMatrix&m=*primary->inverse;const RelatedScalePoint&v=*point;float Y=m.m[1]*v.x+m.m[5]*v.y+m.m[9]*v.z+m.m[13];float X=m.m[0]*v.x+m.m[4]*v.y+m.m[8]*v.z+m.m[12];float Z=m.m[2]*v.x+m.m[6]*v.y+m.m[10]*v.z+m.m[14];RelatedScalePoint transformed(X,Y,Z);fn_8023CFE4(object,&transformed,value*lengthRelatedScale(m.m[0],m.m[4],m.m[8]));}
