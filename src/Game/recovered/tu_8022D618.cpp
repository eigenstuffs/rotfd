/* Merged translation unit (see REPORT.md).  .sdata2 0x8037B188 (1e-6f) is a
 * named constant defined first (hidden in a namespace so that its users keep a
 * variable load); every other float is a compiler-pooled literal in first-use order. */
/* A literal passed through an inline parameter keeps its operand position
 * (a literal written directly in a product is canonicalised to the left). */
inline float fmul2(float a,float b){return a*b;}
namespace pool_head {
extern "C" {
extern const float lbl_8037B188 = 9.999999974752427e-07f;
}
}
/* ---- Game/owner_related_scaled_transform_8022D618.cpp ---- */
namespace owner_related_scaled_transform_8022D618 {
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
extern "C"{extern struct{char unknown00[0x118];RelatedScaleManager*manager;char unknown11C[0x18];RelatedScalePool*pool;}lbl_801E9D24;void fn_801F2124(const RelatedScaleBasis*,RelatedScaleBasis*);RelatedScaleQuat*fn_801F20F4(RelatedScaleQuat*,const RelatedScaleBasis*);void fn_801F1BB0(RelatedScaleQuat*,const RelatedScaleQuat*);void fn_801F230C(const RelatedScaleMatrix*,RelatedScaleMatrix*);void fn_8023CD38(void*,const RelatedScalePoint*,const RelatedScaleQuat*,const float*);void fn_8023CEC4(void*,float);void fn_8023CFE4(void*,const RelatedScalePoint*,float);}
inline float fastSqrt(register float x){register float r;asm{frsqrte f4,x
fres r,f4}return r;}
inline char*resolveRelatedScale(const RelatedScaleHandle&h){int index=h.index;RelatedScaleManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return m->entries[index].object;return 0;}
inline void refreshRelatedScaleInverse(RelatedScaleObject*object){if(object->flags&0x20){object->inverse=&lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active][object->index];fn_801F230C(object->matrix,object->inverse);object->flags&=~0x20;}}
inline float lengthRelatedScale(float x,float y,float z){float sq=x*x+y*y+z*z;float r=0.0f;if(sq!=r)r=fastSqrt(sq);return r;}
inline float scaleRelatedScale(const RelatedScaleMatrix&m){return lengthRelatedScale(m.m[0],m.m[4],m.m[8]);}
extern "C" void fn_8022D618(RelatedScaleOwner*self,const RelatedScalePoint*point,const RelatedScaleQuat*rotation,int index,float value){RelatedScaleObject*object=(RelatedScaleObject*)resolveRelatedScale(*self->getHandle(index));RelatedScaleOwner*related=(RelatedScaleOwner*)resolveRelatedScale(self->related);RelatedScaleObject*primary=(RelatedScaleObject*)resolveRelatedScale(*related->getHandle(0));refreshRelatedScaleInverse(primary);const RelatedScaleMatrix&inverse=*primary->inverse;if(primary->flags&0x40){fn_801F2124(&primary->rotation,&primary->basis);primary->flags&=~0x40;}RelatedScaleQuat composed;fn_801F20F4(&composed,&primary->basis);fn_801F1BB0(&composed,rotation);const RelatedScaleMatrix&m=inverse;const RelatedScalePoint&v=*point;float Y=m.m[1]*v.x+m.m[5]*v.y+m.m[9]*v.z+m.m[13];float X=m.m[0]*v.x+m.m[4]*v.y+m.m[8]*v.z+m.m[12];float Z=m.m[2]*v.x+m.m[6]*v.y+m.m[10]*v.z+m.m[14];RelatedScalePoint transformed(X,Y,Z);float scaled=value*lengthRelatedScale(m.m[0],m.m[4],m.m[8]);fn_8023CD38(object,&transformed,&composed,&scaled);}
extern "C" void fn_8022D888(RelatedScaleOwner*self,int index,float value){RelatedScaleObject*object=(RelatedScaleObject*)resolveRelatedScale(*self->getHandle(index));RelatedScaleOwner*related=(RelatedScaleOwner*)resolveRelatedScale(self->related);RelatedScaleObject*primary=(RelatedScaleObject*)resolveRelatedScale(*related->getHandle(0));refreshRelatedScaleInverse(primary);fn_8023CEC4(object,value*scaleRelatedScale(*primary->inverse));}
extern "C" void fn_8022DA44(RelatedScaleOwner*self,const RelatedScalePoint*point,int index,float value){RelatedScaleObject*object=(RelatedScaleObject*)resolveRelatedScale(*self->getHandle(index));RelatedScaleOwner*related=(RelatedScaleOwner*)resolveRelatedScale(self->related);RelatedScaleObject*primary=(RelatedScaleObject*)resolveRelatedScale(*related->getHandle(0));refreshRelatedScaleInverse(primary);const RelatedScaleMatrix&m=*primary->inverse;const RelatedScalePoint&v=*point;float Y=m.m[1]*v.x+m.m[5]*v.y+m.m[9]*v.z+m.m[13];float X=m.m[0]*v.x+m.m[4]*v.y+m.m[8]*v.z+m.m[12];float Z=m.m[2]*v.x+m.m[6]*v.y+m.m[10]*v.z+m.m[14];RelatedScalePoint transformed(X,Y,Z);fn_8023CFE4(object,&transformed,value*lengthRelatedScale(m.m[0],m.m[4],m.m[8]));}

}

/* ---- Game/owner_related_transform_apply.cpp ---- */
namespace owner_related_transform_apply {
struct RelatedTransformApplyHandle{signed int generation:8;signed int index:24;};struct RelatedTransformApplyPoint{float x,y,z;RelatedTransformApplyPoint(){}RelatedTransformApplyPoint(float a,float b,float c):x(a),y(b),z(c){}};struct RelatedTransformApplyQuat{float x,y,z,w;};struct RelatedTransformApplyBasis{float v[9];};struct RelatedTransformApplyMatrix{float m[16];};
struct RelatedTransformApplyStorage{char unknown00[8];};struct RelatedTransformApplyOwner:RelatedTransformApplyStorage{
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
virtual const RelatedTransformApplyHandle*getHandle(int);
char unknown0C[0x19C];RelatedTransformApplyHandle related;};
struct RelatedTransformApplyObject{char unknown00[0xC];RelatedTransformApplyHandle owner;char unknown10[0x20];RelatedTransformApplyBasis rotation,basis;char unknown78[0xA8];unsigned long flags;RelatedTransformApplyMatrix*matrix,*inverse;short unknown12C,index;};
struct RelatedTransformApplyEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};struct RelatedTransformApplyManager{char unknown00[8];RelatedTransformApplyEntry*entries;};struct RelatedTransformApplyPool{RelatedTransformApplyMatrix*pages[6];unsigned char active;};extern "C"{extern struct{char unknown00[0x118];RelatedTransformApplyManager*manager;char unknown11C[0x18];RelatedTransformApplyPool*pool;}lbl_801E9D24;void fn_801F2124(const RelatedTransformApplyBasis*,RelatedTransformApplyBasis*);RelatedTransformApplyQuat*fn_801F20F4(RelatedTransformApplyQuat*,const RelatedTransformApplyBasis*);void fn_801F1BB0(RelatedTransformApplyQuat*,const RelatedTransformApplyQuat*);void fn_801F230C(const RelatedTransformApplyMatrix*,RelatedTransformApplyMatrix*);void fn_8023D120(void*,const RelatedTransformApplyPoint*,const RelatedTransformApplyQuat*);void fn_8023D100(void*,const RelatedTransformApplyPoint*);unsigned long fn_801F7EB8(const void*);}
inline char*resolveRelatedTransformApply(const RelatedTransformApplyHandle&h){int index=h.index;RelatedTransformApplyManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return m->entries[index].object;return 0;}
inline void refreshRelatedTransformApplyInverse(RelatedTransformApplyObject*object){if(object->flags&0x20){object->inverse=&lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active][object->index];fn_801F230C(object->matrix,object->inverse);object->flags&=~0x20;}}
inline RelatedTransformApplyPoint transformRelatedTransformApply(const RelatedTransformApplyMatrix&m,const RelatedTransformApplyPoint&v){float Y=m.m[1]*v.x+m.m[5]*v.y+m.m[9]*v.z+m.m[13];float X=m.m[0]*v.x+m.m[4]*v.y+m.m[8]*v.z+m.m[12];float Z=m.m[2]*v.x+m.m[6]*v.y+m.m[10]*v.z+m.m[14];return RelatedTransformApplyPoint(X,Y,Z);}
extern "C" void fn_8022DC80(RelatedTransformApplyOwner*self,const RelatedTransformApplyPoint*point,const RelatedTransformApplyQuat*rotation,int index){RelatedTransformApplyObject*object=(RelatedTransformApplyObject*)resolveRelatedTransformApply(*self->getHandle(index));RelatedTransformApplyOwner*related=(RelatedTransformApplyOwner*)resolveRelatedTransformApply(self->related);RelatedTransformApplyObject*primary=(RelatedTransformApplyObject*)resolveRelatedTransformApply(*related->getHandle(0));if(primary->flags&0x40){fn_801F2124(&primary->rotation,&primary->basis);primary->flags&=~0x40;}RelatedTransformApplyQuat composed;fn_801F20F4(&composed,&primary->basis);fn_801F1BB0(&composed,rotation);refreshRelatedTransformApplyInverse(primary);RelatedTransformApplyPoint transformed=transformRelatedTransformApply(*primary->inverse,*point);fn_8023D120(object,&transformed,&composed);}

}

/* ---- Game/owner_related_position_apply.cpp ---- */
namespace owner_related_position_apply {
struct RelatedPositionApplyHandle{signed int generation:8;signed int index:24;};struct RelatedPositionApplyPoint{float x,y,z;RelatedPositionApplyPoint(){}RelatedPositionApplyPoint(float a,float b,float c):x(a),y(b),z(c){}};struct RelatedPositionApplyQuat{float x,y,z,w;};struct RelatedPositionApplyBasis{float v[9];};struct RelatedPositionApplyMatrix{float m[16];};
struct RelatedPositionApplyStorage{char unknown00[8];};struct RelatedPositionApplyOwner:RelatedPositionApplyStorage{
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
virtual const RelatedPositionApplyHandle*getHandle(int);
char unknown0C[0x19C];RelatedPositionApplyHandle related;};
struct RelatedPositionApplyObject{char unknown00[0xC];RelatedPositionApplyHandle owner;char unknown10[0x20];RelatedPositionApplyBasis rotation,basis;char unknown78[0xA8];unsigned long flags;RelatedPositionApplyMatrix*matrix,*inverse;short unknown12C,index;const RelatedPositionApplyHandle&getOwner()const{return owner;}};
struct RelatedPositionApplyEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};struct RelatedPositionApplyManager{char unknown00[8];RelatedPositionApplyEntry*entries;};struct RelatedPositionApplyPool{RelatedPositionApplyMatrix*pages[6];unsigned char active;};extern "C"{extern struct{char unknown00[0x118];RelatedPositionApplyManager*manager;char unknown11C[0x18];RelatedPositionApplyPool*pool;}lbl_801E9D24;void fn_801F2124(const RelatedPositionApplyBasis*,RelatedPositionApplyBasis*);RelatedPositionApplyQuat*fn_801F20F4(RelatedPositionApplyQuat*,const RelatedPositionApplyBasis*);void fn_801F1BB0(RelatedPositionApplyQuat*,const RelatedPositionApplyQuat*);void fn_801F230C(const RelatedPositionApplyMatrix*,RelatedPositionApplyMatrix*);void fn_8023D120(void*,const RelatedPositionApplyPoint*,const RelatedPositionApplyQuat*);void fn_8023D100(void*,const RelatedPositionApplyPoint*);unsigned long fn_801F7EB8(const void*);}
inline char*resolveRelatedPositionApply(const RelatedPositionApplyHandle&h){int index=h.index;RelatedPositionApplyManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return m->entries[index].object;return 0;}
inline void refreshRelatedPositionApplyInverse(RelatedPositionApplyObject*object){if(object->flags&0x20){object->inverse=&lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active][object->index];fn_801F230C(object->matrix,object->inverse);object->flags&=~0x20;}}
inline RelatedPositionApplyPoint transformRelatedPositionApply(const RelatedPositionApplyMatrix&m,const RelatedPositionApplyPoint&v){float Y=m.m[1]*v.x+m.m[5]*v.y+m.m[9]*v.z+m.m[13];float X=m.m[0]*v.x+m.m[4]*v.y+m.m[8]*v.z+m.m[12];float Z=m.m[2]*v.x+m.m[6]*v.y+m.m[10]*v.z+m.m[14];return RelatedPositionApplyPoint(X,Y,Z);}
extern "C" void fn_8022DEB0(RelatedPositionApplyOwner*self,const RelatedPositionApplyPoint*point,int index){RelatedPositionApplyObject*object=(RelatedPositionApplyObject*)resolveRelatedPositionApply(*self->getHandle(index));RelatedPositionApplyOwner*related=(RelatedPositionApplyOwner*)resolveRelatedPositionApply(self->related);RelatedPositionApplyObject*primary=(RelatedPositionApplyObject*)resolveRelatedPositionApply(*related->getHandle(0));if(fn_801F7EB8(&object->owner)&&((RelatedPositionApplyObject*)resolveRelatedPositionApply(object->getOwner()))->flags&4)((RelatedPositionApplyObject*)resolveRelatedPositionApply(object->getOwner()))->flags&=~4;refreshRelatedPositionApplyInverse(primary);RelatedPositionApplyPoint transformed=transformRelatedPositionApply(*primary->inverse,*point);fn_8023D100(object,&transformed);}

}

/* ---- Game/owner_composed_orientation.cpp ---- */
namespace owner_composed_orientation {
struct PropertyHandle{signed int generation:8;signed int index:24;};
struct PropertyStorage{char unknown00[8];};
struct PropertyOwner:PropertyStorage{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const PropertyHandle*getHandle(int);virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();virtual void slotBC();virtual void slotC0();virtual void slotC4();virtual void slotC8();virtual void slotCC();virtual void slotD0();virtual void reset(int);char unknown0C[0x174];char state[0x28];PropertyHandle related;};
struct PropertyEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct PropertyManager{char unknown00[8];PropertyEntry*entries;};
extern "C"{extern struct{char unknown00[0x118];PropertyManager*manager;}lbl_801E9D24;}
static inline char*resolveProperty(const PropertyHandle&h){int index=h.index;PropertyManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return m->entries[index].object;return 0;}
struct OrientationMatrix{float m[9];};extern "C"{void fn_801F2170(OrientationMatrix*,const void*,const void*);void fn_801F20F4(void*,const OrientationMatrix*);}
extern "C" void fn_8022E158(void*out,PropertyOwner*self,int index){char*object=resolveProperty(*self->getHandle(index));PropertyOwner*related=(PropertyOwner*)resolveProperty(self->related);const PropertyHandle&handle=*related->getHandle(0);OrientationMatrix matrix;fn_801F2170(&matrix,resolveProperty(handle)+0x30,object+0x30);fn_801F20F4(out,&matrix);}

}

/* ---- Game/owner_relative_scale_get_8022E2AC.cpp ---- */
namespace owner_relative_scale_get_8022E2AC {
/* X-axis scale of the indexed object's matrix relative to the related
   owner's primary object (fn_8022E2AC): the product of the two matrices
   (fn_801F1080, returned by value from an inline helper, which gives the
   original 64-byte copy) and the length of its first column.  Same
   fastSqrt helper as owner_position_distance_80066DA4.cpp; same flags as
   owner_relative_position_get.cpp. */
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
inline float lengthRelativeScale(float x,float y,float z){float sq=x*x+y*y+z*z;float r=0.0f;if(sq!=r)r=fastSqrt(sq);return r;}
inline RelativeScaleMatrix multiplyRelativeScale(const RelativeScaleMatrix&a,const RelativeScaleMatrix&b){RelativeScaleMatrix r;fn_801F1080(&a,&b,&r);return r;}
extern "C" float fn_8022E2AC(RelativeScaleOwner*self,int index){char*object=resolveRelativeScale(*self->getHandle(index));RelativeScaleOwner*related=(RelativeScaleOwner*)resolveRelativeScale(self->related);char*primary=resolveRelativeScale(*related->getHandle(0));RelativeScaleMatrix m=multiplyRelativeScale(**(RelativeScaleMatrix**)(primary+0x124),**(RelativeScaleMatrix**)(object+0x124));return lengthRelativeScale(m.m[0],m.m[4],m.m[8]);}

}

/* ---- Game/owner_relative_position_get.cpp ---- */
namespace owner_relative_position_get {
struct RelativePositionHandle{signed int generation:8;signed int index:24;};
struct RelativePositionStorage{char unknown00[8];};
struct RelativePositionOwner:RelativePositionStorage{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const RelativePositionHandle*getHandle(int);virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();virtual void slotBC();virtual void slotC0();virtual void slotC4();virtual void slotC8();virtual void slotCC();virtual void slotD0();virtual void reset(int);char unknown0C[0x174];char state[0x28];RelativePositionHandle related;};
struct RelativePositionEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct RelativePositionManager{char unknown00[8];RelativePositionEntry*entries;};
extern "C"{extern struct{char unknown00[0x118];RelativePositionManager*manager;}lbl_801E9D24;}
static inline char*resolveRelativePosition(const RelativePositionHandle&h){int index=h.index;RelativePositionManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return m->entries[index].object;return 0;}
struct RelativePositionPoint{float x,y,z;RelativePositionPoint(){}RelativePositionPoint(float a,float b,float c):x(a),y(b),z(c){}};struct RelativePositionMatrix{float m[16];};
extern "C" RelativePositionPoint fn_8022E488(RelativePositionOwner*self,int index){char*object=resolveRelativePosition(*self->getHandle(index));RelativePositionOwner*related=(RelativePositionOwner*)resolveRelativePosition(self->related);char*primary=resolveRelativePosition(*related->getHandle(0));RelativePositionMatrix*m=*(RelativePositionMatrix**)(primary+0x124);RelativePositionMatrix*v=*(RelativePositionMatrix**)(object+0x124);float z=v->m[14],y=v->m[13],x=v->m[12];float X=m->m[0]*x+m->m[4]*y+m->m[8]*z+m->m[12];float Y=m->m[1]*x+m->m[5]*y+m->m[9]*z+m->m[13];float Z=m->m[2]*x+m->m[6]*y+m->m[10]*z+m->m[14];return RelativePositionPoint(X,Y,Z);}

}

/* ---- Game/scalar_late_8022E63C.c ---- */
namespace scalar_late_8022E63C {
extern "C" {
/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-late.md. */
struct Handle {signed int tag:8; signed int index:24;};struct Entry {void *object;char pad[8];signed char tag;char tail[3];};struct Manager {char pad[8];struct Entry *entries;};extern struct {char pad[0x118];struct Manager *manager;} lbl_801E9D24;static inline void *resolve(const struct Handle *h) {struct Entry *entry=&lbl_801E9D24.manager->entries[h->index];if(entry->tag==h->tag)return entry->object;return 0;}

void *fn_8022E63C(const void *object) {return (char *)resolve((const struct Handle *)((const char *)object+0x1a8))+0x16c;}

}

}

/* ---- part_8022E68C ---- */
namespace part_8022E68C {
/* fn_8022E68C: per-record body update: spin the record's orientation about
   the axis perpendicular to its velocity, then run the two fade timers. */
extern "C" {
extern const float lbl_8037B188; /* 1e-6f */
 /* 0.0f */
float fn_8028506C(float);
float fn_80284FA8(float);
float fn_800AA53C(float, float);
}
inline float fastSqrt(register float x){register float r;asm{frsqrte f4,x
 fres r,f4}return r;}
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3 operator*(float a) const { return Vec3(x * a, y * a, z * a); }
    Vec3& operator*=(float a) { x *= a; y *= a; z *= a; return *this; }
    float lengthSquared() const { return x * x + y * y + z * z; }
    float length() const { float sq = lengthSquared(); float r = 0.0f; if (sq != r) r = fastSqrt(sq); return r; }
    Vec3(float b, float c) : y(b), z(c) {}
    Vec3 crossYZ(const Vec3& v) const { return Vec3(z * v.x - x * v.z, x * v.y - y * v.x); }
    Vec3 cross(const Vec3& v) const { return Vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }
};
struct Quat {
    float w, x, y, z;
    Quat() {}
    Quat(float a, const Vec3& v) : w(a), x(v.x), y(v.y), z(v.z) {}
    void setAxisAngle(const Vec3& axis, float half, const Vec3& up, const Vec3& v) {
        float c = fn_8028506C(half);
        float s = fn_80284FA8(half);
        float tx, ty, tz;
        w = c;
        tz = axis.z; tz *= s; z = tz;
        ty = axis.y; ty *= s; y = ty;
        tx = up.z*v.y; tx = up.y*v.z - tx; x = tx*s;

    }
};
extern "C" void fn_801F1BB0(Quat*, const Quat*);
struct RawHandle { signed int tag : 8; signed int index : 24; };
struct Entry { void* object; int unknown04, unknown08; signed char tag; char unknown0D[3]; };
struct Manager { char unknown00[8]; Entry* entries; };
extern "C" struct { char unknown00[0x118]; Manager* manager; } lbl_801E9D24;
inline void* resolve(const RawHandle& h)
{
    Entry* e = &lbl_801E9D24.manager->entries[h.index];
    if (e->tag == h.tag) return e->object;
    return 0;
}
extern "C" void fn_8023C31C(void*, int);
struct BodyRecord {
    Vec3 velocity;
    Vec3 previous;
    char unknown18[4];
    float fadeTime1C;
    float fadeTime20;
    char unknown24[0x38 - 0x24];
    unsigned long long flags;
    RawHandle handle40;
    char unknown44[0xA8 - 0x44];
};
struct BodySystemBase { char unknown000[8]; };
struct BodySystem : BodySystemBase {
    virtual void method00();
    virtual void method01();
    virtual void method02();
    virtual void method03();
    virtual void method04();
    virtual void method05();
    virtual void method06();
    virtual void method07();
    virtual void method08();
    virtual void method09();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16();
    virtual void method17();
    virtual void method18();
    virtual void method19();
    virtual void method20();
    virtual void method21();
    virtual void method22();
    virtual void method23();
    virtual void method24();
    virtual void method25();
    virtual void method26();
    virtual void method27();
    virtual void method28();
    virtual void method29();
    virtual void method30();
    virtual void method31();
    virtual void method32();
    virtual void method33();
    virtual void method34();
    virtual void method35();
    virtual void method36();
    virtual void method37();
    virtual void method38();
    virtual void method39();
    virtual void method40();
    virtual void method41();
    virtual void method42();
    virtual void method43();
    virtual void method44();
    virtual void method45();
    virtual void method46();
    virtual void method47();
    virtual void method48();
    virtual void method49();
    virtual void method50();
    virtual void method51();
    virtual void method52();
    virtual void method53();
    virtual void method54();
    virtual void method55();
    virtual void method56();
    virtual void method57();
    virtual void method58();
    virtual void method59();
    virtual void method60();
    virtual void method61();
    virtual void method62();
    virtual void method63();
    virtual void method64();
    virtual void method65();
    virtual void method66();
    virtual void method67();
    virtual void method68();
    virtual void method69();
    virtual void method70();
    virtual void method71();
    virtual void method72();
    virtual void remove(int index);
    char unknown00C[0x188 - 0xC];
    BodyRecord* records;
    char unknown18C[0x1B4 - 0x18C];
    float* alpha;
    char unknown1B8[0x1D8 - 0x1B8];
    Quat* orientations;
    char unknown1DC[0x1E4 - 0x1DC];
    float* fade;
    float clock;
};

extern "C" int fn_8022E68C(BodySystem* self, int index, float dt)
{
    BodyRecord* record = &self->records[index];
    if (record->flags & 0x100000ULL) {
        Vec3 v = record->velocity;
        float length = v.length();
        if (length > lbl_8037B188) {
            v *= 1.0f / length;
            Quat q;
            const Vec3& up = Vec3(0.0f, 1.0f, 0.0f); Vec3 axis = up.crossYZ(v);
            float angle = fmul2(dt, 1.3962634f);
            float half = fmul2(angle, 0.5f);
            q.setAxisAngle(axis, half, up, v);
            fn_801F1BB0(&q, &self->orientations[index]);
            self->orientations[index] = q;
        }
    }
    if (record->flags & 0x200000ULL) {
        if (record->fadeTime20 > lbl_8037B188) {
            float t = fn_800AA53C(self->clock, record->fadeTime20) / record->fadeTime20;
            float a = (1.0f - t) * self->alpha[index];
            if (a < 0.001f) {
                self->remove(index);
                return 0;
            }
            self->fade[index] = a;
        }
    }
    if (record->flags & 0x400000ULL) {
        if (record->fadeTime1C > lbl_8037B188) {
            float a = 1.0f - fn_800AA53C(self->clock, record->fadeTime1C) / record->fadeTime1C;
            if (a < 0.001f) {
                self->remove(index);
                return 0;
            }
            fn_8023C31C(resolve(record->handle40), 1);
        }
    }
    return 1;
}

}

/* ---- Game/owner_record_property_dispatch.cpp ---- */
namespace owner_record_property_dispatch {
struct RecordPropertyHandle{signed int generation:8;signed int index:24;};struct RecordPropertyPoint{float x,y,z;};struct RecordPropertyRotation{float w,x,y,z;};struct RecordPropertyItem{char unknown00[0x38];unsigned long long flags;char unknown40[0x68];};struct RecordPropertyStorage{char unknown00[8];};struct RecordPropertyOwner:RecordPropertyStorage{
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
virtual const RecordPropertyHandle*getHandle(int);
virtual void slotA0();
virtual void slotA4();
virtual void slotA8();
virtual void slotAC();
virtual void slotB0();
virtual void slotB4();
virtual void slotB8();
virtual void setPosition(const RecordPropertyPoint*,int);
virtual void setTransform(const RecordPropertyPoint*,const RecordPropertyRotation*,int);
virtual void setPositionScale(const RecordPropertyPoint*,int,float);
virtual void setTransformScale(const RecordPropertyPoint*,const RecordPropertyRotation*,int,float);
char unknown0C[0x17C];RecordPropertyItem*records;char unknown18C[0x1C];RecordPropertyHandle related;char unknown1AC[0x2C];RecordPropertyRotation*rotations;char unknown1DC[8];float*scales;};
struct RecordPropertyEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};struct RecordPropertyManager{char unknown00[8];RecordPropertyEntry*entries;};extern "C"{extern struct{char unknown00[0x118];RecordPropertyManager*manager;}lbl_801E9D24;void fn_8023D400(void*,int);}
inline char*resolveRecordProperty(const RecordPropertyHandle&h){int index=h.index;RecordPropertyManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return m->entries[index].object;return 0;}
extern "C" void fn_8022E9D8(RecordPropertyOwner*self,const RecordPropertyPoint*first,const RecordPropertyPoint*point,const RecordPropertyPoint*third,int index,float delta){if(self->records[index].flags&0x100000ULL){if(self->records[index].flags&0x200000ULL)self->setTransformScale(point,&self->rotations[index],index,self->scales[index]);else self->setTransform(point,&self->rotations[index],index);}else if(self->records[index].flags&0x200000ULL)self->setPositionScale(point,index,self->scales[index]);else self->setPosition(point,index);RecordPropertyOwner*related=(RecordPropertyOwner*)resolveRecordProperty(self->related);fn_8023D400(resolveRecordProperty(*related->getHandle(0)),0x10);}

}

/* ---- Game/owner_conditional_notify.cpp ---- */
namespace owner_conditional_notify {
struct PropertyHandle{signed int generation:8;signed int index:24;};
struct PropertyStorage{char unknown00[8];};
struct PropertyOwner:PropertyStorage{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const PropertyHandle*getHandle(int);virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();virtual void slotBC();virtual void slotC0();virtual void slotC4();virtual void slotC8();virtual void slotCC();virtual void slotD0();virtual void slotD4();virtual void slotD8();virtual void slotDC();virtual void slotE0();virtual void slotE4();virtual void slotE8();virtual void slotEC();virtual void slotF0();virtual void slotF4();virtual void slotF8();virtual void slotFC();virtual void slot100();virtual void slot104();virtual void slot108();virtual void slot10C();virtual void slot110();virtual void slot114();virtual void slot118();virtual void slot11C();virtual void slot120();virtual void slot124();virtual void slot128();virtual void notify(int);};
struct PropertyEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct PropertyManager{char unknown00[8];PropertyEntry*entries;};
extern "C"{extern struct{char unknown00[0x118];PropertyManager*manager;}lbl_801E9D24;}
static inline char*resolveProperty(const PropertyHandle&h){PropertyEntry*e=&lbl_801E9D24.manager->entries[h.index];if(e->generation==h.generation)return e->object;return 0;}
extern "C" signed char fn_80230740(void*,const void*,const void*,const void*);
extern "C" signed char fn_8022EBAC(PropertyOwner*self,const void*first,const void*second,const void*third,int index){signed char result=fn_80230740(self,first,second,third);if(result)self->notify(index);return result;}

}

/* ---- Game/engine_small_owner_8022EC14.cpp ---- */
namespace engine_small_owner_8022EC14 {
#include "Game/engine_small_owner_forwarders.h"
extern "C" void fn_8022EC14(SmallOwnerDispatch*self,const void*value){self->slot12C(value);}

}
/* ---- Game/owner_playback_reset.cpp ---- */
namespace owner_playback_reset {
struct PropertyHandle{signed int generation:8;signed int index:24;};
struct PropertyStorage{char unknown00[8];};
struct PropertyOwner:PropertyStorage{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const PropertyHandle*getHandle(int);virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();virtual void slotBC();virtual void slotC0();virtual void slotC4();virtual void slotC8();virtual void slotCC();virtual void slotD0();virtual void reset(int);char unknown0C[0x174];char state[0x28];PropertyHandle related;};
struct PropertyEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct PropertyManager{char unknown00[8];PropertyEntry*entries;};
extern "C"{extern struct{char unknown00[0x118];PropertyManager*manager;}lbl_801E9D24;}
static inline char*resolveProperty(const PropertyHandle&h){int index=h.index;PropertyManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return m->entries[index].object;return 0;}
extern "C"{void fn_8024A430(void*,void*,int);void fn_80209DF8(void*,int);}
extern "C" void fn_8022EC40(PropertyOwner*self,int index){char*object=resolveProperty(*self->getHandle(index));*(unsigned long*)(object+0x120)&=~0x80000UL;char*related=resolveProperty(self->related);char*player=resolveProperty(*(PropertyHandle*)(related+0x16C));fn_8024A430(player,object,1);self->reset(index);fn_80209DF8(self->state,index);}

}

/* ---- Game/owner_record_respawn_8022ED80.cpp ---- */
/* fn_8022ED80: detaches the related object's anchor, then re-spawns one retained
   record per selected item around it (random yaw/pitch/distance offsets). */
typedef unsigned long u32;
struct Manager;struct Selector;
struct Context{char unknown00[0x118];Manager*manager;char unknown11C[0x28];Selector*selector;};
extern "C"{extern Context lbl_801E9D24;}
struct Handle_801F7F10{
    union{u32 value;struct{signed int generation:8;signed int index:24;}bits;};
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct ZeroHandle1:Handle_801F7F10{ZeroHandle1(){value=0;}~ZeroHandle1(){}};
struct ZeroHandle2:ZeroHandle1{ZeroHandle2(){value=0;}~ZeroHandle2(){}};
struct ZeroHandle3:ZeroHandle2{ZeroHandle3(){value=0;}~ZeroHandle3(){}};
struct Entry{void*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct Manager{int count,capacity;Entry*entries;};
struct Selector{char unknown00[0x94];int*selection;const int&operator[](int index)const{return selection[index];}};
inline void*resolveOrNull(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();void*r=0;if(generation==h.bits.generation)r=m->entries[index].object;return r;}
inline void*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.bits.generation)return m->entries[index].object;return 0;}

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
extern "C"{
extern const char lbl_8037B1A0[6]="HIDE_";
extern const char lbl_8037B1A8[6]="SHOW_";
float fn_80285124(float,float);
float fn_8028506C(float);
float fn_80284FA8(float);
float fn_801F1200();
}
struct Vec3{
 float x,y,z;
 Vec3(){}
 Vec3(float a,float b,float c):x(a),y(b),z(c){}
 Vec3(const Vec3&v):x(v.x),y(v.y),z(v.z){}
 Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return*this;}
 Vec3 operator*(float s)const{return Vec3(x*s,y*s,z*s);}
 Vec3&operator+=(const Vec3&v){x+=v.x;y+=v.y;z+=v.z;return*this;}
 float lengthXZ()const{float sq=x*x+z*z;float r=0.0f;if(sq!=r)r=fastSqrt(sq);return r;}
 float lengthSq()const{return x*x+y*y+z*z;}
 float length()const{float sq=lengthSq();float r=0.0f;if(sq!=r)r=fastSqrt(sq);return r;}
};
struct Quat{
 float w;Vec3 v;
 Quat(){}
 Quat(float angle,float x,float y,float z){float half=fmul2(angle,0.5f);w=fn_8028506C(half);float s=fn_80284FA8(half);v=Vec3(x*s,y*s,z*s);}
 Quat&operator=(const Quat&q){w=q.w;v.x=q.v.x;v.y=q.v.y;v.z=q.v.z;return*this;}
};
struct Matrix{float m[16];Vec3 column(int i)const{return Vec3(m[i],m[i+4],m[i+8]);}};
struct Basis{float m[9];};
extern "C"{
void fn_801F1080(const Matrix*,const Matrix*,Matrix*);
void fn_801F2170(Basis*,const void*,const void*);
Quat fn_801F20F4(const Basis*);
Vec3 fn_801F1B1C(const Quat*,const Vec3*);
}
inline Vec3 operator*(const Quat&q,const Vec3&v){return fn_801F1B1C(&q,&v);}
inline Matrix relative(const Matrix*a,const Matrix*b){Matrix r;fn_801F1080(a,b,&r);return r;}

struct BitNativeCtorPoint{float x,y,z;};
struct BitParameterRecord{
 char unknown00[0x38];unsigned long long token38;char unknown40[0x68];
 BitParameterRecord(const Handle_801F7F10&,const Handle_801F7F10&,const Handle_801F7F10&,const Handle_801F7F10&,const BitNativeCtorPoint&,unsigned long long,float,float);
};
/* The native constructor and destructor carry different invented class names;
   this private view derives the destructor owner from the constructor owner so a
   local record calls both original symbols (destructor flag -1). */
struct Record_80209EA0:BitParameterRecord{
 Record_80209EA0(const Handle_801F7F10&h44,const Handle_801F7F10&h48,const Handle_801F7F10&h4C,const Handle_801F7F10&h40,const BitNativeCtorPoint&point,unsigned long long token,float a,float b):BitParameterRecord(h44,h48,h4C,h40,point,token,a,b){}
 Record_80209EA0(const Handle_801F7F10&,unsigned long long);
 ~Record_80209EA0();
};
struct SpawnRecord{Vec3 velocity;Vec3 spin;float unknown18,phase1C,phase20,speed24,unknown28,range2C,range30;char unknown34[0x74];};
typedef char SpawnRecordSize[sizeof(SpawnRecord)==0xA8?1:-1];

struct ManipulatorPrefix{unsigned long unknown00[2];};
struct Manipulator_Z:ManipulatorPrefix{
 Manipulator_Z();virtual ~Manipulator_Z();
 virtual void slot0C(unsigned long);virtual void slot10();virtual void slot14();virtual void slot18();virtual signed char slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C(float);virtual void slot30();virtual void slot34();virtual void slot38(float)=0;virtual void slot3C();
 char unknown0C[0x20-0x0C];
};
struct Node{char unknown00[0x30];Basis orientation;char unknown54[0x120-0x54];u32 flags;Matrix*matrix;};
struct RelatedObject:Manipulator_Z{
 virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();
 virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();
 virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();
 virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();
 virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();
 virtual void slot90();virtual void slot94();virtual void slot98();
 virtual Handle_801F7F10*anchor(int);
 virtual void slotA0();virtual void slotA4();virtual void slotA8();
 virtual void setMode(int,int);
 char unknown20[8];Handle_801F7F10*items;Handle_801F7F10&getItem(int i){return items[i];}char unknown2C[4];unsigned long long flags;char unknown38[0x16C-0x38];Handle_801F7F10 related;
};
template<class T>struct Array{int count,capacity;T*data;T&operator[](int i){return data[i];}};
struct Borrowed{RelatedObject*value;Borrowed(RelatedObject*p):value(p){}operator RelatedObject*()const{return value;}RelatedObject*operator->()const{return value;}};
struct BitRecordOwner{int count,capacity;SpawnRecord*records;char unknown0C[0x18];};
struct SpawnOwner:Manipulator_Z{
 virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();
 virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();
 virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();
 virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();
 virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();
 virtual void slot90();virtual void slot94();virtual void slot98();virtual void slot9C();
 virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();
 virtual void slotB0();virtual void slotB4();virtual void slotB8();virtual void slotBC();
 virtual void slotC0();virtual void slotC4();virtual void slotC8();virtual void slotCC();
 virtual void slotD0();virtual void startRecord(int);
 char unknown20[0x10];unsigned long long token;char unknown38[0x180-0x38];BitRecordOwner records;u32 unknown1A4;Handle_801F7F10 related;Array<float>scales;char unknown1B8[0x18];Array<Quat>rotations;Array<float>baseScales;float elapsed;
};
struct SpawnParams{float speed00,speed04,size08,unknown0C,distanceMin,distanceMax,pitchMin,pitchMax,phase20,phase24,range28,range2C;Vec3 origin;Vec3 extent;};
extern "C"{
int fn_8024A094(void*,const char*,int);
int fn_8024A120(void*,const char*,int);
int fn_802257EC(BitRecordOwner*,const Record_80209EA0*);
void fn_8021FE84(RelatedObject*,Handle_801F7F10*,int);
void fn_8021FD9C(void*,const Handle_801F7F10*,void*,signed char);
const Handle_801F7F10*fn_80240F28(void*);
}

extern "C" void fn_8022ED80(SpawnOwner*self,const Vec3*origin,const SpawnParams*params){
 RelatedObject*related=(RelatedObject*)resolve(self->related);
 Handle_801F7F10*anchor=related->anchor(0);
 related->setMode(0xC0000,0);
 related->flags&=~0x81FFFE00ULL;
 fn_8021FE84(related,anchor,0x42);
 fn_8021FD9C(self,anchor,resolve(*fn_80240F28(resolve(*anchor))),1);
 RelatedObject*owner=(RelatedObject*)resolve(self->related);
 Borrowed object((RelatedObject*)resolve(owner->related));
 int count=fn_8024A094(object,lbl_8037B1A0,1);
 fn_8024A120(object,lbl_8037B1A8,1);
 ZeroHandle3 none;
 Node*base=(Node*)resolveOrNull(*anchor);
 float radius=params->extent.lengthXZ();
 for(int i=0;i<count;++i){
  Handle_801F7F10&item=object->getItem((*lbl_801E9D24.selector)[i+0x1C]);
  Node*node=(Node*)resolve(item);
  node->flags&=~0x80000UL;
  Matrix m=relative(base->matrix,node->matrix);
  float x=m.m[12],z=m.m[14];
  Basis basis;fn_801F2170(&basis,&base->orientation,&node->orientation);
  self->rotations[i]=fn_801F20F4(&basis);
  self->baseScales[i]=self->scales[i]=m.column(0).length();
  float yaw=fn_80285124(x-origin->x,z-origin->z);float jitterYaw=fn_801F1200();float jitterScale=0.17453292f;yaw+=jitterYaw*jitterScale;
  float distance=params->distanceMin+(params->distanceMax-params->distanceMin)*fn_801F1200();
  float pitch=params->pitchMin+(params->pitchMax-params->pitchMin)*fn_801F1200();
  Quat qp(pitch,1.0f,0.0f,0.0f);
  Quat qy(yaw,0.0f,1.0f,0.0f);
  Vec3 position=qy*(qp*Vec3(0.0f,0.0f,distance));
  position+=qy*(qp*Vec3(0.0f,0.0f,radius));
  int index;
  {
   Record_80209EA0 record(none,none,none,item,(const BitNativeCtorPoint&)position,self->token,params->size08,0.8f);
   index=fn_802257EC(&self->records,&record);
  }
  self->startRecord(index);
  SpawnRecord*rec=&self->records.records[index];
  rec->spin=Vec3(0.0f,params->speed00,0.0f);
  rec->speed24=params->speed04;
  rec->range2C=params->range28;rec->range30=params->range2C;
  float jitter=0.5f*fn_801F1200();
  rec->phase1C=params->phase24+jitter;
  rec->phase20=params->phase20+jitter;
 }
 self->elapsed=0.0f;
}

/* a declaration here makes mwcc emit fn_8022ED80 before the next function */
struct EmitOrderAnchor_8022ED80;
/* ---- Game/engine_small_owner_8022F474.cpp ---- */
namespace engine_small_owner_8022EC14 {
extern "C" void fn_8022F474(void*self,const void*value){fn_8022ED80(self,(const char*)value+0x30,value);}

}
/* ---- Game/recovered/record_population_prefix_8022F49C.cpp ---- */
namespace record_population_prefix_8022F49C {
struct Handle { signed int tag:8; signed int index:24; };
struct Vec3 { float x, y, z; Vec3() {} Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {} };
struct Sphere { Vec3 center; float radius; };
struct Node;
struct Entry { Node* object; int unknown04, unknown08; signed char tag; char unknown0D[3]; };
struct Manager { char unknown00[8]; Entry* entries; };
struct Context { char unknown00[0x118]; Manager* manager; };
struct NodeStorage { char unknown00[8]; };
struct Node : NodeStorage {
    virtual void s08(); virtual void s0C(); virtual void s10(); virtual void s14();
    virtual void s18(); virtual void s1C(); virtual void s20(); virtual void s24();
    virtual void s28(); virtual void s2C(); virtual void s30(); virtual void s34();
    virtual void s38(); virtual void s3C(); virtual void s40(); virtual void s44();
    virtual void s48(); virtual void s4C(); virtual void s50(); virtual void s54();
    virtual void s58(); virtual void s5C(); virtual void s60(); virtual void s64();
    virtual void s68(); virtual void s6C(); virtual void s70(); virtual void s74();
    virtual void s78(); virtual void s7C(); virtual void s80(); virtual void s84();
    virtual void s88(); virtual void s8C(); virtual void s90(); virtual void s94();
    virtual void s98();
    virtual Handle* s9C(int);
    char unknown0C[0x68];
    void* field74;
    char unknown78[0xAC];
    void* field124;
    char unknown128[0x40];
    Handle handle168;
    char unknown16C[0x3C];
    Handle handle1A8;
};
extern "C" {
extern Context lbl_801E9D24;
Sphere fn_80099A00(void*, void*);
void fn_8022ED80(Node*, Vec3*, int);
}
struct EntryB { Node* object; int unknown04, unknown08; signed char tag; char unknown0D[3]; };
struct ManagerB { char unknown00[8]; EntryB* entries; };
static inline Node* resolve(const Handle& h)
{
    int index = h.index; signed char tag = h.tag;
    Entry* e = &(*(Entry**)((char*)lbl_801E9D24.manager + 8))[index];
    if (e->tag == tag) return e->object;
    return 0;
}
static inline Node* resolveB(const Handle& h)
{
    int index = h.index; signed char tag = h.tag;
    EntryB* e = &((ManagerB*)lbl_801E9D24.manager)->entries[index];
    if (e->tag == tag) return e->object;
    return 0;
}
static inline Node* resolveC(const Handle& h)
{
    EntryB* e = &((ManagerB*)lbl_801E9D24.manager)->entries[h.index];
    signed char tag = h.tag;
    if (e->tag == tag) return e->object;
    return 0;
}
extern "C" void fn_8022F49C(Node* self, int arg)
{
    void* p = resolveB(resolve(self->handle1A8)->handle168)->field74;
    if (p) {
        Sphere s = fn_80099A00(resolveB(*resolveC(self->handle1A8)->s9C(0))->field124, p);
        Vec3 v = s.center;
        fn_8022ED80(self, &v, arg);
    }
}

}

/* ---- Game/owner_record_population_8022F624.cpp ---- */
namespace owner_record_population_8022F624 {
// Populate retained records and their scale/property arrays from selected handles.
struct PopulateSelector;struct Manager;struct PopulateContext{char unknown00[0x118];Manager*manager;char unknown11C[0x28];PopulateSelector*selector;};extern "C"{extern PopulateContext lbl_801E9D24;void fn_801F86C8(Manager*,const void*,short);}

extern "C" {extern char lbl_8028F698[];void*fn_8028FAF4(void*,void*,unsigned long,unsigned long);void*fn_8028FF24(void*,unsigned long);void fn_8028FD50(void*,void*,unsigned long);}
struct BitRecordWords {int count,capacity;unsigned long*words;
 void reserve(int n){if(n){if(words)words=(unsigned long*)fn_8028FAF4(lbl_8028F698,words,capacity*4,n*4);else words=(unsigned long*)fn_8028FF24(lbl_8028F698,n*4);}else if(words){fn_8028FD50(lbl_8028F698,words,capacity*4);words=0;}capacity=n;}
 void resize(int n){if(n>count){reserve(n);for(int i=count;i<n;++i){}count=n;}else if(n<count){for(int i=count-1;i>=n;--i){}reserve(n);count=n;}}
};
struct BitRecordOwner {int count,capacity;char*records;BitRecordWords storage;int size,initialized,used;
 void setSize(int n){size=n;if(n&&((n>>5)+1)>storage.count)storage.resize((size>>5)+1);}
 void setBit(int i){storage.words[i>>5]|=1UL<<(i&31);}
};
struct PopulateOwner:Manipulator_Z{
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
virtual void slot9C();
virtual void slotA0();
virtual void slotA4();
virtual void slotA8();
virtual void slotAC();
virtual void slotB0();
virtual void slotB4();
virtual void slotB8();
virtual void slotBC();
virtual void slotC0();
virtual void slotC4();
virtual void slotC8();
virtual void slotCC();
virtual void slotD0();
virtual void slotD4();
virtual void finishRecord(int);
virtual void slotDC();
virtual void slotE0();
virtual void slotE4();
virtual void slotE8();
virtual void slotEC();
virtual void slotF0();
virtual void slotF4();
virtual void slotF8();
virtual void slotFC();
virtual void slot100();
virtual void slot104();
virtual void slot108();
virtual void slot10C();
virtual void slot110();
virtual void slot114();
virtual void slot118();
virtual void slot11C();
virtual void reserve(int);
char unknown20[0x160];BitRecordOwner records;u32 unknown1A4;Handle_801F7F10 related;char unknown1AC[0x14];float*scales;char unknown1C4[8];unsigned long*properties;float&getScale(int i){return scales[i];}unsigned long&getProperty(int i){return properties[i];}};
struct PopulateObject:Manipulator_Z{char unknown20[8];Handle_801F7F10*items;char unknown2C[0x140];Handle_801F7F10 related;};
struct BorrowedPopulateObject{PopulateObject*value;BorrowedPopulateObject(PopulateObject*p):value(p){}operator PopulateObject*()const{return value;}PopulateObject*operator->()const{return value;}};
struct PopulateEntry{void*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};struct Manager{int count,capacity;PopulateEntry*entries;};struct PopulateSelector{char unknown00[0x94];int*selection;const int&operator[](int index)const{return selection[index];}};extern "C"{extern const char lbl_8037B1A0[6];int fn_8024A120(void*,const char*,int);int fn_802257EC(BitRecordOwner*,const Record_80209EA0*);float fn_8023BE00(void*,int);int fn_8024BCA4(void*,const Handle_801F7F10*);int fn_8024A800(void*,int);void fn_802279A0(void*);}
inline void*resolvePopulate(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.bits.generation)return m->entries[index].object;return 0;}
struct PopulateHandle1:Handle_801F7F10{PopulateHandle1(){value=0;}};struct PopulateCopy1:PopulateHandle1{PopulateCopy1(const Handle_801F7F10&input){value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}};
inline void assignPopulate(Handle_801F7F10&dest,const Handle_801F7F10&input){fn_801F86C8(lbl_801E9D24.manager,&dest,-1);dest.value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}
extern "C" void fn_8022F624(PopulateOwner* self, const Handle_801F7F10* input) {
    assignPopulate(self->related, *input);
    PopulateObject* related = static_cast<PopulateObject*>(resolvePopulate(self->related));
    BorrowedPopulateObject object(
        static_cast<PopulateObject*>(resolvePopulate(related->related)));
    int count = fn_8024A120(object, lbl_8037B1A0, 1);
    self->reserve(count);
    for (int i = 0; i < count; ++i) {
        PopulateCopy1 copy(object->items[(*lbl_801E9D24.selector)[i + 0x1C]]);
        int index;
        {
            Record_80209EA0 record(copy, 0ULL);
            index = fn_802257EC(&self->records, &record);
        }
        self->getScale(index) = fn_8023BE00(resolvePopulate(copy), 0);
        self->getProperty(index) = fn_8024A800(object, fn_8024BCA4(object, &copy));
        self->finishRecord(index);
    }
    fn_802279A0(self);
}

typedef char CheckRecord[sizeof(Record_80209EA0)==0xA8?1:-1];
typedef char CheckHandle[sizeof(Handle_801F7F10)==4?1:-1];

typedef char CheckRoot[sizeof(Manipulator_Z)==0x20?1:-1];
typedef char CheckOwner[sizeof(PopulateOwner)==0x1D0?1:-1];
typedef char CheckObject[sizeof(PopulateObject)==0x170?1:-1];
typedef char CheckManager[sizeof(Manager)==0xC?1:-1];
typedef char CheckBorrowedObject[sizeof(BorrowedPopulateObject)==4?1:-1];

typedef char CheckRecordPool[sizeof(BitRecordOwner)==0x24?1:-1];

}
/* ---- Game/recovered/record_population_suffix_8022F868.cpp ---- */
namespace record_population_suffix_8022F868 {
struct Manager;
struct Context { char unknown00[0x118]; Manager* manager; };
extern "C" { extern Context lbl_801E9D24; void fn_801F86C8(Manager*, const void*, short); }
struct PodHandle { struct { signed int tag : 8; signed int index : 24; } bits; };
struct Handle1 : Handle_801F7F10 { Handle1() { value = 0; } ~Handle1() {} };
struct Handle2 : Handle1 { Handle2() { value = 0; } ~Handle2() {} };
struct HandleCopy : Handle2 {
    HandleCopy(const PodHandle& input) { value = *(const u32*)&input; fn_801F86C8(lbl_801E9D24.manager, &input, 1); }
    ~HandleCopy() {}
};
typedef PodHandle Handle;
struct Vec3 { float x, y, z; };
struct Sphere { float x, y, z, radius;
    Sphere() {}
    Sphere(const Sphere& o) : x(o.x), y(o.y), z(o.z), radius(o.radius) {}
    Sphere& operator=(const Sphere& o) { x = o.x; y = o.y; z = o.z; radius = o.radius; return *this; }
};
struct Matrix { float m[16]; };
struct Node;
struct Entry { Node* object; int unknown04, unknown08; signed char tag; char unknown0D[3]; };
struct Manager { char unknown00[8]; Entry* entries; };
struct NodeStorage { char unknown00[8]; };
struct Node : NodeStorage {
    virtual void s08(); virtual void s0C(); virtual void s10(); virtual void s14();
    virtual void s18(); virtual void s1C(); virtual void s20(); virtual void s24();
    virtual void s28(); virtual void s2C(); virtual void s30(); virtual void s34();
    virtual signed char s38(Node*, int, int);
    virtual Sphere* s3C();
    virtual void s40(); virtual void s44();
    virtual void s48(); virtual void s4C(); virtual void s50(); virtual void s54();
    virtual void s58(); virtual void s5C(); virtual void s60(); virtual void s64();
    virtual void s68(); virtual void s6C(); virtual void s70(); virtual void s74();
    virtual void s78(); virtual void s7C(); virtual void s80(); virtual void s84();
    virtual void s88(); virtual void s8C();
    virtual int s90();
    virtual int s94(int);
    virtual void s98();
    virtual Handle* s9C(int);
    char unknown0C[0x24];
    unsigned long long flags30;
    char unknown38[0x34];
    Handle* array6C;
    char unknown70[0x18];
    Handle* array88;
    char unknown8C[0x3C];
    Handle* fieldC8;
    char unknownCC[0x58];
    Matrix* field124;
    char unknown128[0x40];
    Handle handle168;
    Handle handle16C;
    char unknown170[0x38];
    Handle handle1A8;
    char unknown1AC[0x20];
    int* array1CC;
};
extern "C" {
Sphere fn_80099A00(const Matrix*, const Sphere*);
Sphere fn_801F0A20(const Sphere&, const Sphere&);
void fn_801F1080(const Matrix*, const Matrix*, Matrix*);
}
struct EntryB { Node* object; int unknown04, unknown08; signed char tag; char unknown0D[3]; };
struct ManagerB { char unknown00[8]; EntryB* entries; };
static inline Node* resolve(const Handle& h)
{
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    if (e->tag == h.bits.tag) return e->object;
    return 0;
}
static inline Node* resolveA(const Handle& h)
{
    int index = h.bits.index; signed char tag = h.bits.tag;
    Entry* e = &(*(Entry**)((char*)lbl_801E9D24.manager + 8))[index];
    if (e->tag == tag) return e->object;
    return 0;
}
static inline Node* resolveB(const Handle& h)
{
    int index = h.bits.index; signed char tag = h.bits.tag;
    EntryB* e = &((ManagerB*)lbl_801E9D24.manager)->entries[index];
    if (e->tag == tag) return e->object;
    return 0;
}
static inline Node* resolveC(const Handle& h)
{
    EntryB* e = &((ManagerB*)lbl_801E9D24.manager)->entries[h.bits.index];
    signed char tag = h.bits.tag;
    if (e->tag == tag) return e->object;
    return 0;
}
static inline Node* resolveD(const Handle& h)
{
    EntryB* e = &((ManagerB*)lbl_801E9D24.manager)->entries[h.bits.index];
    if (e->tag == h.bits.tag) return e->object;
    return 0;
}

/* first owner lookup: entries pointer and result share one variable (forces the
   entries reload at the next lookup, as in the original) */
static inline Node* resolveQ(const Handle& h){ int index=h.bits.index; signed char tag=h.bits.tag; void* r=lbl_801E9D24.manager->entries; Entry* e=(Entry*)r+index; if(e->tag==tag) r=e->object; else r=0; return (Node*)r; }
static inline Matrix product(const Matrix* a, const Matrix* b) { Matrix r; fn_801F1080(a, b, &r); return r; }
extern "C" int fn_8022F868(Node* self, Sphere* out)
{
    int i = self->s90();
    if (i < 0) return 0;
    Node* a = resolve(*(const Handle*)&(const Handle_801F7F10&)HandleCopy(*resolveD(resolve(self->handle1A8)->handle168)->fieldC8));
    Node* c = resolveB(resolveQ(self->handle1A8)->handle16C);
    Node* d = resolveB(*resolveC(self->handle1A8)->s9C(0));
    signed char first = 1;
    for (; i >= 0; i = self->s94(i)) {
        Node* n = resolve(*self->s9C(i));
        Matrix m = product(d->field124, n->field124);
        int k = self->array1CC[i];
        Node* child = resolveA(c->array6C[k]);
        if (first) {
            *out = fn_80099A00(&m, (Sphere*)((char*)resolve(a->array88[k]) + 0xC));
        } else {
            *out = fn_801F0A20(fn_80099A00(&m, (Sphere*)((char*)resolve(a->array88[k]) + 0xC)), *out);
        }
        if (self->flags30 & 0x2000) {
            if (child->s38(n, 0, 0)) {
                *out = fn_801F0A20(fn_80099A00(&m, child->s3C()), *out);
            }
        }
        first = 0;
    }
    return 1;
}

}
/* ---- Game/owner_indexed_property_reset.cpp ---- */
namespace owner_indexed_property_reset {
struct PropertyHandle{signed int generation:8;signed int index:24;};
struct PropertyStorage{char unknown00[8];};
struct PropertyOwner:PropertyStorage{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const PropertyHandle*getHandle(int);};
struct PropertyEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct PropertyManager{char unknown00[8];PropertyEntry*entries;};
extern "C"{extern struct{char unknown00[0x118];PropertyManager*manager;}lbl_801E9D24;}
static inline char*resolveProperty(const PropertyHandle&h){PropertyEntry*e=&lbl_801E9D24.manager->entries[h.index];if(e->generation==h.generation)return e->object;return 0;}
extern "C" {void fn_8023C31C(void*,float,int);void fn_80220260(void*,int);}
extern "C" void fn_8022FDBC(PropertyOwner*self,int index){char*object=resolveProperty(*self->getHandle(index));float*values=*(float**)((char*)self+0x1C0);fn_8023C31C(object,values[index],0);fn_80220260(self,index);}

}

/* ---- Game/engine_owner_arrays_resize.cpp ---- */
inline void* operator new(unsigned long, void* address)
{
    return address;
}
namespace engine_owner_arrays_resize {
struct OwnerArraysResizeOwner;

typedef unsigned long ResizeWord;

extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, ResizeWord, ResizeWord);
void* fn_8028FF24(void*, ResizeWord);
void fn_8028FD50(void*, void*, ResizeWord);
void fn_80226AEC(void*, int);
}


struct OwnerResizeItem16 {
    ResizeWord words[4];
    OwnerResizeItem16() {}
    ~OwnerResizeItem16() {}
};

struct OwnerResizeItem4 {
    ResizeWord word;
    OwnerResizeItem4() {}
    ~OwnerResizeItem4() {}
};

template<class T> struct OwnerResizeArray {
    int count;
    int capacity;
    T* items;

    inline void storage(int size)
    {
        if (size) {
            if (items)
                items = (T*)fn_8028FAF4(lbl_8028F698, items,
                    capacity * sizeof(T), size * sizeof(T));
            else
                items = (T*)fn_8028FF24(lbl_8028F698, size * sizeof(T));
        } else if (items) {
            fn_8028FD50(lbl_8028F698, items, capacity * sizeof(T));
            items = 0;
        }
    }

    inline void resize(int size)
    {
        if (size > count) {
            storage(size);
            capacity = size;
            for (int i = count; i < size; ++i)
                new (&items[i]) T;
            count = size;
        } else if (size < count) {
            for (int i = count - 1; i >= size; --i)
                items[i].~T();
            storage(size);
            capacity = size;
            count = size;
        }
    }
};

struct OwnerArraysResizeOwner {
    char unknown00[0x1AC];
    OwnerResizeArray<OwnerResizeItem4> first;
    OwnerResizeArray<OwnerResizeItem4> second;
    OwnerResizeArray<OwnerResizeItem4> third;
    OwnerResizeArray<OwnerResizeItem16> fourth;
    OwnerResizeArray<OwnerResizeItem4> fifth;
};

extern "C" void fn_8022FE68(OwnerArraysResizeOwner* self, int size)
{
    fn_80226AEC(self, size);
    self->fourth.resize(size);
    self->fifth.resize(size);
    self->first.resize(size);
    self->second.resize(size);
    self->third.resize(size);
}

}
/* a declaration here makes mwcc emit fn_8022FE68 before the next function */
struct EmitOrderAnchor_8022FE68;
/* ---- Game/engine_small_owner_802304E0.cpp ---- */
namespace engine_small_owner_8022EC14 {
extern "C" void fn_802304E0(SmallOwnerAccumulation*self,float delta){self->time+=delta;fn_80226288(self,delta);}

}
/* ---- Game/owner_child_dispatch_8023050C.cpp ---- */
namespace owner_child_dispatch_8023050C {
// Original owner/child dispatch; typed lookup preserves the native member lifetimes.
struct ChildDispatchObject:Manipulator_Z {
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
    virtual const Handle_801F7F10& get(int);
    char unknown20[0x168-0x20];
    Handle_801F7F10 first,second;
};
struct ChildDispatchIndex {
    const int value;
    ChildDispatchIndex(int v):value(v) {
    }
    operator int()const {
        return value;
    }
};
struct ChildDispatchEntry {
    ChildDispatchObject*object;
    unsigned long key;
    int unknown08;
    signed char tag;
    char unknown0D[3];
    bool matchesTag(signed char t)const {
        return tag==t;
    }
    ChildDispatchObject*getObject()const {
        return object;
    }
};
struct ChildDispatchEntries {
    ChildDispatchEntry*p;
    ChildDispatchEntry&operator[](const ChildDispatchIndex&i)const {
        return p[i];
    }
};
struct ChildDispatchManager {
    int count,capacity;
    ChildDispatchEntries entries;
};
struct ChildDispatchContext {
    char unknown00[0x118];
    ChildDispatchManager*manager;
};
struct ChildDispatchOwner {
    char unknown00[0x1A8];
    Handle_801F7F10 handle;
};
extern "C" {
    extern ChildDispatchContext lbl_801E9D24;
    extern const char lbl_8037B1A0[6],lbl_8037B1A8[6];
    void fn_802279A0(ChildDispatchOwner*);
    int fn_8024A120(ChildDispatchObject*,const char*,int);
    int fn_8024A094(ChildDispatchObject*,const char*,int);
    void fn_80246314(ChildDispatchObject*,const Handle_801F7F10&);
} static inline ChildDispatchObject*resolveChild(const Handle_801F7F10&h) {
    ChildDispatchManager*m=lbl_801E9D24.manager;
    const ChildDispatchIndex i(h.bits.index);
    const signed char tag(h.bits.generation);
    if(m->entries[i].matchesTag(tag))return m->entries[i].getObject();
    return 0;
} extern "C" void fn_8023050C(ChildDispatchOwner*self) {
    fn_802279A0(self);
    resolveChild(self->handle)->slot34();
    ChildDispatchObject *second=resolveChild(resolveChild(self->handle)->second);
    ChildDispatchObject *first=resolveChild(resolveChild(self->handle)->first);
    fn_8024A120(second,lbl_8037B1A0,1);
    fn_8024A094(second,lbl_8037B1A8,1);
    fn_80246314(first,resolveChild(self->handle)->get(0));
} typedef char ChildDispatchHandleSize[(sizeof(Handle_801F7F10)==4)?1:-1];
typedef char ChildDispatchRootSize[(sizeof(Manipulator_Z)==0x20)?1:-1];
typedef char ChildDispatchEntrySize[(sizeof(ChildDispatchEntry)==16)?1:-1];
typedef char ChildDispatchNodeSize[(sizeof(ChildDispatchObject)==0x170)?1:-1];
typedef char ChildDispatchOwnerSize[(sizeof(ChildDispatchOwner)==0x1AC)?1:-1];

}

/* ---- Game/engine_owner_wrapper_80230700.c ---- */
namespace engine_owner_wrapper_80230700 {
extern "C" {
#include "Game/engine_owner_wrappers.h"

void fn_80230700(EngineOwnerWrapperFlags* self)
{
    fn_80230978(self);
    self->flags |= 0x302000ULL;
}

}

}
