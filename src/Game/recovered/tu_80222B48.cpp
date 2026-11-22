/* Merged TU: .text 0x80222B48-0x80224888, .sdata2 0x8037B0E0-0x8037B118.
   GC/1.3.2 -O4,p -fp_contract on -use_lmw_stmw on, exceptions/RTTI off.
   .sdata2: 0x8037B0E0-0x8037B0EC named (head), 0x8037B0F0-0x8037B104 pooled literals of
   fn_8022352C (2, 3, -2, 6, 0.001, 0.6; fn_80224294 reuses the 2.0f entry),
   0x8037B108-0x8037B110 named (defined after fn_8022352C). */
typedef unsigned long Word;
struct Handle_801F7F10{union{unsigned long value;Word word;struct{signed int generation:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
extern "C" { extern const float lbl_8037B0E0, lbl_8037B0E4, lbl_8037B0E8, lbl_8037B0EC; }
namespace pool_head { extern "C" {
extern const float lbl_8037B0E0 = 0.0f;
extern const float lbl_8037B0E4 = 1.0f;
extern const float lbl_8037B0E8 = -1612.0f;
extern const float lbl_8037B0EC = 0.5f;
} }
namespace p_flagged {
struct FlagDispatchPoint{float x,y,z;};struct FlagDispatchOwner{char unknown00[0x24];Handle_801F7F10 second;char unknown28[8];unsigned long long flags;char unknown38[0x180];FlagDispatchPoint axis;};
struct FlagDispatchObject{char unknown00[4];Handle_801F7F10 handle4;char unknown08[0x128];Handle_801F7F10 parent;};struct FlagDispatchInput{char unknown00[0x28];unsigned long long flags;FlagDispatchObject*object;};
struct FlagDispatchEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};struct FlagDispatchManager{char unknown00[8];FlagDispatchEntry*entries;};extern "C"{extern struct{char unknown00[0x118];FlagDispatchManager*manager;void*service;}lbl_801E9D24;void fn_801F86C8(void*,const void*,int);extern const float lbl_8037B0E0,lbl_8037B0E4,lbl_8037B0E8;int fn_80227C30(FlagDispatchOwner*,const FlagDispatchInput*);void fn_802073E8(void*,int,void*,float);void fn_8026B440(void*,const void*);}
inline unsigned long resolveFlagDispatch(const Handle_801F7F10&h){int index=h.bits.index;FlagDispatchManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.bits.generation)return (unsigned long)m->entries[index].object;return 0;}
struct FlagDispatchZero:Handle_801F7F10{FlagDispatchZero(){value=0;}};struct FlagDispatchCopy:FlagDispatchZero{FlagDispatchCopy(const Handle_801F7F10&input){value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}};
extern "C" int fn_80222B48(FlagDispatchOwner*self,const FlagDispatchInput*input){int result=fn_80227C30(self,input);if(input->flags&0x10ULL){self->flags|=0x4000000000000ULL;self->axis.x=lbl_8037B0E0;self->axis.y=lbl_8037B0E4;self->axis.z=lbl_8037B0E0;char*parent=(char*)resolveFlagDispatch(input->object->parent);if(parent)fn_802073E8(parent,0x41,(void*)resolveFlagDispatch(self->second),lbl_8037B0E8);}if(input->flags&0x80ULL){FlagDispatchCopy copy(input->object->handle4);fn_8026B440(lbl_801E9D24.service,&copy);}return result;}

}
namespace p_facing {
struct PropertyHandle{unsigned long value;};struct FacingPoint{float x,y,z;};struct FacingRotation{float w,x,y,z;};
struct PropertyStorage{char unknown00[8];};
struct PropertyOwner:PropertyStorage{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const PropertyHandle*getHandle(int);virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();virtual void slotBC();virtual void setFacing(const FacingPoint*,const FacingRotation*,int);virtual void slotC4();virtual void slotC8();virtual void slotCC();virtual void slotD0();virtual void reset(int);char unknown0C[0x24];unsigned long long flags;char unknown38[0x178];PropertyHandle related;};
extern "C"{extern const float lbl_8037B0EC,lbl_8037B0E0,lbl_8037B0E4;float fn_80285124(float,float);float fn_8028506C(float);float fn_80284FA8(float);void fn_8022993C(PropertyOwner*,const FacingPoint*,const FacingPoint*,const FacingPoint*,int,float);unsigned int fn_801F7EB8(const void*);void fn_8021F990(PropertyOwner*,const FacingPoint*,int);signed char fn_8021F23C(PropertyOwner*);}
extern "C" void fn_80222CFC(PropertyOwner*self,const FacingPoint*first,const FacingPoint*second,const FacingPoint*third,int index,float delta){if(self->flags&0x800000000ULL){fn_8022993C(self,first,second,third,index,delta);}else if(fn_801F7EB8(&self->related)){fn_8021F990(self,first,0);}else if(fn_8021F23C(self)){fn_8021F990(self,second,0);}else{float angle=fn_80285124(third->x-second->x,third->z-second->z);angle*=lbl_8037B0EC;FacingRotation rotation;rotation.w=fn_8028506C(angle);float sine=fn_80284FA8(angle);rotation.x=lbl_8037B0E0*sine;rotation.y=lbl_8037B0E4*sine;rotation.z=lbl_8037B0E0*sine;self->setFacing(second,&rotation,0);}}

}
namespace p_small {
extern "C" void fn_80229A78(void*,float);
extern "C" void fn_80222E44(void*self,float delta){fn_80229A78(self,delta);}

}
namespace p_transform {
struct TransformHandle{signed int generation:8;signed int index:24;};
struct TransformPoint{float x,y,z;const TransformPoint&get()const{return *this;}TransformPoint(){}TransformPoint(float a,float b,float c):x(a),y(b),z(c){}TransformPoint(const TransformPoint&v):x(v.x),y(v.y),z(v.z){}};struct TransformRotation{float x,y,z,w;};struct TransformBasis{float values[9];};struct TransformMatrix{float m[16];};
struct TransformSelf{char unknown00[0x1AC];TransformHandle secondary;char unknown1B0[0x48];TransformHandle related;};struct TransformStorage{char unknown00[8];};struct TransformOwner:TransformStorage{
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
virtual const TransformHandle*getHandle(int);
virtual void slotA0();
virtual void slotA4();
virtual void slotA8();
virtual void slotAC();
virtual void slotB0();
virtual void slotB4();
virtual void slotB8();
virtual void slotBC();
virtual void setTransform(const TransformPoint*,const TransformRotation*,int);
};
struct TransformObject{char unknown00[0x20];TransformHandle parent;char unknown24[4];TransformHandle*items;char unknown2C[4];TransformBasis rotation;char unknown54[0xD0];TransformMatrix*matrix;};
struct TransformEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};struct TransformManager{char unknown00[8];TransformEntry*entries;};struct TransformSelection{char unknown00[0x18];int index;int getIndex()const{return index;}};struct TransformSelector{char unknown00[0x94];TransformSelection*selection;};extern "C"{extern struct{char unknown00[0x118];TransformManager*manager;char unknown11C[0x28];TransformSelector*selector;}lbl_801E9D24;void fn_8023DE28(void*);void fn_801F2170(TransformBasis*,const void*,const void*);void fn_801F20F4(void*,const TransformBasis*);void fn_8021F8F4(void*,const TransformPoint*,const TransformRotation*,int);unsigned long fn_801F7EB8(const void*);void fn_8022352C(void*,const TransformPoint*,const TransformRotation*);}
inline unsigned long resolveTransform(const TransformHandle&h){int index=h.index;TransformManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return (unsigned long)m->entries[index].object;return 0;}
inline TransformPoint transformTranslation(const TransformMatrix&m,const TransformMatrix&v){float z=v.m[14];float y=v.m[13];float x=v.m[12];TransformPoint out;out.x=m.m[0]*x+m.m[4]*y+m.m[8]*z+m.m[12];out.y=m.m[1]*x+m.m[5]*y+m.m[9]*z+m.m[13];out.z=m.m[2]*x+m.m[6]*y+m.m[10]*z+m.m[14];return out.get();}
inline void forwardTransform(void*self,TransformPoint point,const TransformRotation*rotation){fn_8021F8F4(self,&point,rotation,0);}
extern "C" void fn_80222E64(TransformSelf*self,const TransformPoint*point,const TransformRotation*rotation){TransformOwner*related=(TransformOwner*)resolveTransform(self->related);if(related){related->setTransform(point,rotation,0);TransformObject*object=(TransformObject*)resolveTransform(*related->getHandle(0));fn_8023DE28(object);TransformObject*parent=(TransformObject*)resolveTransform(object->parent);TransformObject*node=(TransformObject*)resolveTransform(parent->items[0]);TransformObject*target=(TransformObject*)resolveTransform(node->items[lbl_801E9D24.selector->selection->getIndex()]);TransformBasis basis;fn_801F2170(&basis,&object->rotation,&target->rotation);TransformRotation composed;fn_801F20F4(&composed,&basis);forwardTransform(self,transformTranslation(*object->matrix,*target->matrix),&composed);}else fn_8021F8F4(self,point,rotation,0);if(fn_801F7EB8(&self->secondary))fn_8022352C(self,point,rotation);}

}
namespace p_position {
struct TransformHandle{signed int generation:8;signed int index:24;};
struct TransformPoint{float x,y,z;const TransformPoint&get()const{return *this;}TransformPoint(){}TransformPoint(float a,float b,float c):x(a),y(b),z(c){}TransformPoint(const TransformPoint&v):x(v.x),y(v.y),z(v.z){}};struct TransformRotation{float x,y,z,w;};struct TransformBasis{float values[9];};struct TransformMatrix{float m[16];};
struct TransformSelf;struct TransformStorage{char unknown00[8];};struct TransformOwner:TransformStorage{
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
virtual const TransformHandle*getHandle(int);
virtual void slotA0();
virtual void slotA4();
virtual void slotA8();
virtual void slotAC();
virtual void slotB0();
virtual void slotB4();
virtual void slotB8();
virtual void setPosition(const TransformPoint*,int);
virtual void setTransform(const TransformPoint*,const TransformRotation*,int);
};
struct TransformSelf:TransformOwner{char unknown0C[0x1A0];TransformHandle secondary;char unknown1B0[0x48];TransformHandle related;};
struct TransformObject{char unknown00[0x20];TransformHandle parent;char unknown24[4];TransformHandle*items;char unknown2C[4];TransformBasis rotation;char unknown54[0xD0];TransformMatrix*matrix;};
struct TransformEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};struct TransformManager{char unknown00[8];TransformEntry*entries;};struct TransformSelection{char unknown00[0x18];int index;int getIndex()const{return index;}};struct TransformSelector{char unknown00[0x94];TransformSelection*selection;};extern "C"{extern struct{char unknown00[0x118];TransformManager*manager;char unknown11C[0x28];TransformSelector*selector;}lbl_801E9D24;void fn_8023DE28(void*);void fn_801F2170(TransformBasis*,const void*,const void*);TransformRotation*fn_801F20F4(TransformRotation*,const TransformBasis*);void fn_8021F990(void*,const TransformPoint*,int);void fn_8021F8F4(void*,const TransformPoint*,const TransformRotation*,int);unsigned long fn_801F7EB8(const void*);void fn_8022352C(void*,const TransformPoint*,const TransformRotation*);}
inline unsigned long resolveTransform(const TransformHandle&h){int index=h.index;TransformManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.generation)return (unsigned long)m->entries[index].object;return 0;}
inline TransformPoint transformTranslation(const TransformMatrix&m,const TransformMatrix&v){float z=v.m[14];float y=v.m[13];float x=v.m[12];TransformPoint out;out.x=m.m[0]*x+m.m[4]*y+m.m[8]*z+m.m[12];out.y=m.m[1]*x+m.m[5]*y+m.m[9]*z+m.m[13];out.z=m.m[2]*x+m.m[6]*y+m.m[10]*z+m.m[14];return out.get();}
inline void forwardSecondary(void*self,const TransformPoint*point,const TransformBasis*matrix){TransformRotation rotation;fn_8022352C(self,point,fn_801F20F4(&rotation,matrix));}
inline void forwardPosition(void*self,TransformPoint point){fn_8021F990(self,&point,0);}
extern "C" void fn_8022312C(TransformSelf*self,const TransformPoint*point){TransformOwner*related=(TransformOwner*)resolveTransform(self->related);if(related){related->setPosition(point,0);TransformObject*object=(TransformObject*)resolveTransform(*related->getHandle(0));fn_8023DE28(object);TransformObject*parent=(TransformObject*)resolveTransform(object->parent);TransformObject*node=(TransformObject*)resolveTransform(parent->items[0]);TransformObject*target=(TransformObject*)resolveTransform(node->items[lbl_801E9D24.selector->selection->getIndex()]);forwardPosition(self,transformTranslation(*object->matrix,*target->matrix));}else fn_8021F990(self,point,0);if(fn_801F7EB8(&self->secondary))forwardSecondary(self,point,&((TransformObject*)resolveTransform(*self->getHandle(0)))->rotation);}

}
namespace p_conditional {
struct PropertyHandle{signed int generation:8;signed int index:24;};
struct ConditionalPoint{float x,y,z;ConditionalPoint(float X,float Y,float Z):x(X),y(Y),z(Z){} ConditionalPoint(const ConditionalPoint&v):x(v.x),y(v.y),z(v.z){}};
struct PropertyStorage{char unknown00[8];};
struct PropertyOwner:PropertyStorage{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const PropertyHandle*getHandle(int);virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual ConditionalPoint getPosition(int);char unknown0C[0x1EC];PropertyHandle related;};
struct PropertyEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct PropertyManager{char unknown00[8];PropertyEntry*entries;};
extern "C"{extern struct{char unknown00[0x118];PropertyManager*manager;}lbl_801E9D24;}
static inline char*resolveProperty(const PropertyHandle&h){PropertyEntry*e=&lbl_801E9D24.manager->entries[h.index];if(e->generation==h.generation)return e->object;return 0;}
extern "C"{void*fn_801F7EB8(const PropertyHandle*);ConditionalPoint fn_8021FB5C(PropertyOwner*,int);}
inline signed char conditionalValid(const PropertyHandle&h){return fn_801F7EB8(&h)!=0;}
extern "C" ConditionalPoint fn_80223448(PropertyOwner*self){return conditionalValid(self->related)?((PropertyOwner*)resolveProperty(self->related))->getPosition(0):fn_8021FB5C(self,0);}

}
namespace p_follow {
/* auto_03_8022352C_text: fn_8022352C, owner follows its related owner along a
   cubic (Hermite) path toward animator bone 9, then pushes the composed
   position/rotation into the related owner's node and recurses down the
   related chain.  GC/1.3.2 -O4,p -fp_contract on, exceptions off.
   Status: EXACT-MOD-POOL.  The two pool refs are float literals that must be
   literals (2.0f = lbl_8037B0F0, 0.6f = lbl_8037B104): with an extern the
   frontend gives operator*(float)'s parameter its own temp, with a pool
   literal it substitutes the expression and the backend CSEs it, which is
   what the original's FPR colouring needs.  The unit therefore has to own
   those two .sdata2 words (or the integrator maps them).  The weak inline
   handle destructors it emits need report_strip_weak (as for
   actor_handle_counter_control_80087D04.cpp).
   Load-bearing details: resolve() written as if/return (ternary form changes
   GPR numbering); the animator pointer lives in a one-member struct box
   (named local -> wrong level, r29 instead of r20); Quat = {w, Vec3 v} and
   conj.v = -conj.v; spline step through mul() free helper so its temps are
   not `this`; position += for the late blend; the zero literal read in two
   forms in the hermite set-up so it is backend- not frontend-CSE'd; the
   HandleCopy argument goes through getRelated() so &related is materialised
   before the base ctor call; Deleting3/4 layers carry operator delete (stores
   through the saved this register). */
typedef unsigned long long Flags;

extern "C" {
extern const float lbl_8037B0E0, lbl_8037B0E4, lbl_8037B0E8, lbl_8037B0EC;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    Vec3& operator+=(const Vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
};

inline Vec3 mul(const Vec3& v, float s) { return Vec3(v.x * s, v.y * s, v.z * s); }

struct Quat {
    float w;
    Vec3 v;
    Quat() {}
    Quat(const Quat& q) : w(q.w), v(q.v) {}
    Quat& operator=(const Quat& q) { w = q.w; v = q.v; return *this; }
};

struct Matrix {
    float m[16];
    const Vec3& getPosition() const { return *(const Vec3*)&m[12]; }
};

struct Basis {
    float m[9];
};


struct Entry {
    void* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct Manager {
    int count, capacity;
    Entry* entries;
};
struct Context {
    char unknown00[0x118];
    Manager* manager;
};

extern "C" {
extern Context lbl_801E9D24;
void fn_801F86C8(Manager*, const Handle_801F7F10*, short);
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
}

inline void* resolve(const Handle_801F7F10& h)
{
    int i = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int generation = m->entries[i].getGeneration();
    if (generation == h.bits.generation) return m->entries[i].object;
    return 0;
}

struct Zero1_8022352C : Handle_801F7F10 { Zero1_8022352C() { word = 0; } ~Zero1_8022352C() {} };
struct Zero2_8022352C : Zero1_8022352C { Zero2_8022352C() { word = 0; } ~Zero2_8022352C() {} };
struct Zero3_8022352C : Zero2_8022352C { Zero3_8022352C() { word = 0; } ~Zero3_8022352C() {} };
struct Zero4_8022352C : Zero3_8022352C { Zero4_8022352C() { word = 0; } ~Zero4_8022352C() {} };
struct Deleting3_8022352C : Zero2_8022352C {
    Deleting3_8022352C() { word = 0; }
    ~Deleting3_8022352C() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};
struct Deleting4_8022352C : Deleting3_8022352C {
    Deleting4_8022352C() { word = 0; }
    ~Deleting4_8022352C() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};
struct HandleCopy_8022352C : Deleting4_8022352C {
    HandleCopy_8022352C(const Handle_801F7F10& h)
    {
        word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    ~HandleCopy_8022352C() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};
struct OwnerHandle_8022352C : Handle_801F7F10 {
    OwnerHandle_8022352C& operator=(const Handle_801F7F10& h)
    {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
};

struct Node {
    char unknown00[0x30];
    Basis basis;
    char unknown54[0x124 - 0x54];
    Matrix* matrix;
};

struct Animator {
    char unknown00[8];
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void attach(void*);
};

struct Owner {
    char unknown00[8];
    virtual void slot08();
    virtual void slot0C();
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
    virtual const Handle_801F7F10& getHandle(int);
    char unknown0C[0x24 - 0x0C];
    Handle_801F7F10 owner;
    char unknown28[0x30 - 0x28];
    Flags flags;
    char unknown38[0x16C - 0x38];
    Handle_801F7F10 animator;
    char unknown170[0x188 - 0x170];
    Quat rotationA;
    Quat rotationB;
    float blend;
    OwnerHandle_8022352C related;
    char unknown1B0[4];
    float time;
    char unknown1B8[0x264 - 0x1B8];
    Quat startRotation;
    Quat yawRotation;
    Vec3 start;
    Vec3 end;
    Vec3 a;
    Vec3 b;
    Vec3 c;
    Vec3 d;
    const Handle_801F7F10& getRelated() const { return related; }
};

extern "C" {
void fn_801F25E8(Matrix*, const Vec3&, const Quat&, const Vec3&);
signed char fn_8024BFB4(Animator*, int, Matrix*);
void fn_8024BEA8(Animator*, int, Quat*);
void fn_802073E8(void*, int, void*, float);
void fn_801F230C(const Matrix*, Matrix*);
Matrix* fn_801F2788(Matrix*, const Matrix*);
Quat* fn_801F20F4(Quat*, const Basis*);
void fn_801F1BB0(Quat*, const Quat*);
Vec3 fn_801F1B1C(const Quat&, const Vec3&);
float fn_80285124(float, float);
float fn_8028506C(float);
float fn_80284FA8(float);
float fn_800AA53C(float, float);
Vec3 fn_801AFFBC(const Vec3&, float);
Quat fn_8008D420(const Quat&, const Quat&, float);
void fn_801F1080(const Matrix*, const Matrix*, Matrix*);
void fn_8023D120(Node*, const Vec3*, const Quat*);
void fn_8023DE28(Node*);
signed char fn_8021F308(Owner*);
void fn_8022352C(Owner* self, const Vec3* point, const Quat* rotation);
}

inline void notify(Owner* from, int code, Owner* to)
{
    fn_802073E8(resolve(from->owner), code, resolve(to->owner), lbl_8037B0E8);
}

inline Matrix operator*(const Matrix& a, const Matrix& b)
{
    Matrix r;
    fn_801F1080(&a, &b, &r);
    return r;
}

extern "C" void fn_8022352C(Owner* self, const Vec3* point, const Quat* rotation)
{
    Owner* related = (Owner*)resolve(self->related);
    if (related) {
        Matrix local;
        fn_801F25E8(&local, *point, *rotation, Vec3(lbl_8037B0E4, lbl_8037B0E4, lbl_8037B0E4));
        struct { Animator* p; } box;
        box.p = (Animator*)resolve(self->animator);
        box.p->attach(resolve(self->getHandle(0)));
        Matrix bone;
        if (!fn_8024BFB4(box.p, 9, &bone)) {
            self->related = Zero4_8022352C();
            return;
        }
        Quat boneRotation;
        fn_8024BEA8(box.p, 9, &boneRotation);
        Vec3 target(bone.getPosition());
        Node* node = (Node*)resolve(related->getHandle(0));
        if (self->time < lbl_8037B0E0) {
            notify(related, 0x31, self);
            notify(self, 0x33, related);
            self->start = target;
            Matrix inverse;
            fn_801F230C(&local, &inverse);
            fn_801F2788(&inverse, node->matrix);
            Quat conj(*rotation);
            conj.v = -conj.v;
            Quat nodeRotation;
            fn_801F20F4(&nodeRotation, &node->basis);
            fn_801F1BB0(&conj, &nodeRotation);
            self->end = inverse.getPosition();
            self->startRotation = conj;
            Vec3 forward = fn_801F1B1C(self->startRotation, Vec3((*(const float*)&lbl_8037B0E0), lbl_8037B0E0, lbl_8037B0E4));
            float angle = fn_80285124(forward.x, forward.z);
            float half = angle * lbl_8037B0EC;
            float cosine = fn_8028506C(half);
            float sine = fn_80284FA8(half);
            self->yawRotation.w = cosine;
            self->yawRotation.v.x = lbl_8037B0E0 * sine;
            self->yawRotation.v.y = lbl_8037B0E4 * sine;
            self->yawRotation.v.z = lbl_8037B0E0 * sine;
            self->a = self->end * 2.0f - self->start * 2.0f + Vec3((*(const float*)&lbl_8037B0E0), 3.0f, lbl_8037B0E0) + Vec3(lbl_8037B0E0, -2.0f, lbl_8037B0E0);
            self->b = -self->end * 3.0f + self->start * 3.0f - Vec3((*(const float*)&lbl_8037B0E0), 6.0f, lbl_8037B0E0) - Vec3(lbl_8037B0E0, -2.0f, lbl_8037B0E0);
            self->c = Vec3(lbl_8037B0E0, 3.0f, lbl_8037B0E0);
            self->d = self->end;
            self->time = lbl_8037B0E0;
        }
        float t = fn_800AA53C(self->time, 0.001f) / 0.001f;
        Vec3 position = target;
        if (self->time < 0.001f) {
            position = self->d + mul(self->c + mul(self->b + fn_801AFFBC(self->a, t), t), t);
            if (t > 0.6f) {
                position += (target - self->start) * (t - 0.6f);
            }
        }
        Quat rotationQ = self->startRotation;
        Quat boneQ = boneRotation;
        if (related->flags & 0x20000ULL) {
            rotationQ = fn_8008D420(rotationQ, boneQ, t);
        } else {
            rotationQ = fn_8008D420(rotationQ, self->yawRotation, t);
        }
        Matrix pose;
        fn_801F25E8(&pose, position, rotationQ, Vec3(lbl_8037B0E4, lbl_8037B0E4, lbl_8037B0E4));
        Matrix world = local * pose;
        Quat worldRotation(*rotation);
        fn_801F1BB0(&worldRotation, &rotationQ);
        Vec3 worldPosition(world.m[12], world.m[13], world.m[14]);
        related->rotationA = worldRotation;
        related->rotationB = worldRotation;
        related->blend = lbl_8037B0E0;
        fn_8023D120(node, &worldPosition, &worldRotation);
        fn_8023DE28(node);
        if (self->time > 0.001f && !(related->flags & 0x400000000ULL)) {
            related->flags |= 0x400000000ULL;
            notify(self, 0x34, related);
        }
        if (fn_8021F308(related)) {
            Owner* next = (Owner*)resolve(HandleCopy_8022352C(self->getRelated()));
            if (resolve(next->related)) fn_8022352C(next, &worldPosition, &worldRotation);
        }
    }
}

}
extern "C" { extern const float lbl_8037B108, lbl_8037B10C, lbl_8037B110; }
namespace pool_tail { extern "C" {
extern const float lbl_8037B108 = -1.0f;
extern const float lbl_8037B10C = 0.01f;
extern const float lbl_8037B110[2] = {10.0f, 0.0f};
} }
namespace p_origin {
struct RelatedOriginPoint{float x,y,z;RelatedOriginPoint&operator=(const RelatedOriginPoint&v){x=v.x;y=v.y;z=v.z;return *this;}};struct RelatedOriginMatrix{float values[16];};struct RelatedOriginSelf{char unknown00[0x1F8];Handle_801F7F10 related;char unknown1FC[0xC];RelatedOriginPoint origin;};
struct RelatedOriginObject{char unknown00[0x20];Handle_801F7F10 parent;Handle_801F7F10&getParent(){return parent;}};
struct RelatedOriginStorage{char unknown00[8];};struct RelatedOriginOwner:RelatedOriginStorage{
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
virtual const Handle_801F7F10*getHandle(int);
};
struct RelatedOriginEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];};struct RelatedOriginManager{char unknown00[8];RelatedOriginEntry*entries;};extern "C"{extern struct{char unknown00[0x118];RelatedOriginManager*manager;}lbl_801E9D24;void fn_801F86C8(void*,const void*,int);unsigned long fn_801F7EB8(const void*);void fn_8024BFB4(void*,int,RelatedOriginMatrix*);extern const RelatedOriginPoint game_vec3_zero;}
inline char*resolveRelatedOrigin(const Handle_801F7F10&h){RelatedOriginEntry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->generation==h.bits.generation)return e->object;return 0;}
struct RelatedOriginHandle1:Handle_801F7F10{RelatedOriginHandle1(){value=0;}};struct RelatedOriginHandle2:RelatedOriginHandle1{RelatedOriginHandle2(){value=0;}};struct RelatedOriginCopy2:RelatedOriginHandle2{RelatedOriginCopy2(const Handle_801F7F10&input){value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}};
inline void assignRelatedOrigin(Handle_801F7F10&dest,const Handle_801F7F10&input){fn_801F86C8(lbl_801E9D24.manager,&dest,-1);dest.value=input.value;fn_801F86C8(lbl_801E9D24.manager,&input,1);}
inline void setRelatedOrigin(RelatedOriginPoint&point,float x,float y,float z){point.x=x;point.y=y;point.z=z;}
extern "C" void fn_80224038(RelatedOriginSelf*self,const Handle_801F7F10*input){assignRelatedOrigin(self->related,*input);if(fn_801F7EB8(&self->related)){RelatedOriginOwner*owner=(RelatedOriginOwner*)resolveRelatedOrigin(self->related);char*primary=resolveRelatedOrigin(*owner->getHandle(0));char*object=resolveRelatedOrigin(RelatedOriginCopy2(((RelatedOriginObject*)primary)->getParent()));RelatedOriginCopy2 copy(**(Handle_801F7F10**)(object+0x28));RelatedOriginMatrix matrix;fn_8024BFB4(resolveRelatedOrigin(copy),6,&matrix);float y=matrix.values[13];float z=matrix.values[14];float x=matrix.values[12];setRelatedOrigin(self->origin,x,y,z);}else self->origin=game_vec3_zero;}

}
namespace p_ground {
/* fn_80224294: place an owner on the ground below its first handle's raised
 position (initial cast, then a 10-unit down ray), face it toward the
 orientation handle (yaw quaternion) and notify the context.
 Pooled-literal emulation: the 0.0f label uses distinct read forms per use in
 the initial-cast and down-ray blocks.
 The orientation target is copied into a by-value Vec3 and self-assigned
 (target=target): the second definition stops the optimizer forwarding the
 z,y,x-ordered loads into the call arguments, so target.z is numbered first
 and the f2/f3 colouring before fn_80285124 matches. */
typedef unsigned long long Flags;
struct Vec3 {float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3(const Vec3&v):x(v.x),y(v.y),z(v.z){}Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return *this;}Vec3 operator+(const Vec3&v)const{return Vec3(x+v.x,y+v.y,z+v.z);}Vec3 operator-(const Vec3&v)const{return Vec3(x-v.x,y-v.y,z-v.z);}};
struct Vec4:Vec3 {float w;Vec4(const Vec3&v,float f):Vec3(v),w(f){}};
struct Quat {float w,x,y,z;Quat(const Quat&q):w(q.w),x(q.x),y(q.y),z(q.z){}Quat(float a,float b,float c,float d):w(a),x(b),y(c),z(d){}Quat&operator=(const Quat&q){w=q.w;x=q.x;y=q.y;z=q.z;return *this;}};
struct Ray {Vec3 origin;float length;Vec3 direction;float unknown1C;Ray(){}};
struct Hit {Vec3 point;char unknown0C[0x28-12];Flags flags;void*object;void*other;void*extra;signed char hit;char unknown3D[3];Word end;Hit(){hit=0;object=0;other=0;extra=0;flags=0;}};
struct Actor;
struct Handle {signed int generation:8,index:24;};
struct Entry {Actor*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct Manager {int count,capacity;Entry*entries;};
struct Context {char unknown00[0x118];Manager*manager;};
extern "C" {extern Context lbl_801E9D24;}
inline Actor*resolve(const Handle&h){int i=h.index;Manager*m=lbl_801E9D24.manager;int generation=m->entries[i].getGeneration();return generation==h.generation?m->entries[i].object:0;}
extern "C" {extern const float lbl_8037B0E0,lbl_8037B10C;}
inline Word resolveNotify(const Handle&h){int i=h.index;Manager*m=lbl_801E9D24.manager;int g=m->entries[i].getGeneration();return g==h.generation?(Word)m->entries[i].object:0;}
struct Geometry {char unknown00[0x30];Vec3 position;Vec3 getPosition()const{return Vec3(position.x,position.y,position.z);}Vec3 getRaisedPosition()const{return getPosition()+Vec3(lbl_8037B0E0,lbl_8037B10C,lbl_8037B0E0);}};
struct Actor {char unknown00[0x20];Handle owner;char unknown24[12];Handle child;char unknown34[0x120-0x34];Word flags;Geometry*geometry;signed char initialCast(const Vec3&,Hit*,const Vec4&);signed char downCast(const Vec3&,Hit*);};
struct Prefix {Word unknown00,unknown04;};
struct Owner:Prefix {
virtual void slot08();
virtual void slot0C();
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
virtual void applyHandle(const Handle&);
virtual signed char getPoint(Vec4&,int,int);
virtual void slot8C();
virtual void slot90();
virtual void slot94();
virtual void slot98();
virtual const Handle&getHandle(int);
virtual void slotA0();
virtual void slotA4();
virtual void slotA8();
virtual void slotAC();
virtual void slotB0();
virtual void slotB4();
virtual void slotB8();
virtual void slotBC();
virtual void setTransform(const Vec3&,const Quat&,int);
virtual void slotC4();
virtual void slotC8();
virtual void slotCC();
virtual void slotD0();
virtual void slotD4();
virtual void slotD8();
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
virtual void notify(Actor*,const Vec3&,const Vec3&,int,int);
void notifyHandle(const Handle&h,const Vec3&p){notify((Actor*)resolveNotify(h),p,p,0,1);}
virtual void slot10C();
virtual void slot110();
virtual void slot114();
virtual void slot118();
virtual void slot11C();
virtual void slot120();
virtual void slot124();
virtual void slot128();
virtual void slot12C();
virtual void slot130();
virtual void slot134();
virtual void slot138();
virtual void slot13C();
virtual void slot140();
virtual void slot144();
virtual void setPosition(const Vec3&);
char unknown0C[0x30-0xC];Flags flags;
};
extern "C" {Word fn_801F7EB8(const Handle*);float fn_80285124(float,float);float fn_8028506C(float);float fn_80284FA8(float);signed char fn_80268FE8(Actor*,const Vec3&,const Vec3&,Hit*,Flags,Flags,float);signed char fn_80269230(Actor*,const Ray&,Hit*,Flags,Flags);void fn_801CBDE4(Actor*,Actor*,void*,float);void fn_8023DE28(Actor*);extern const Vec3 game_vec4_zero;extern const Quat game_quat_identity;extern const float lbl_8037B0E0,lbl_8037B0E4,lbl_8037B0EC,lbl_8037B108,lbl_8037B10C,lbl_8037B110;}
inline signed char Actor::initialCast(const Vec3&p,Hit*h,const Vec4&point){return fn_80268FE8(this,p,p-Vec3(*(const float*)&lbl_8037B0E0,2.0f,lbl_8037B0E0),h,0xFFFFEFFBFFFFFFFFULL,0,point.w);}
inline signed char Actor::downCast(const Vec3&p,Hit*h){Ray ray;float k=2.0f;ray.origin=Vec3(p.x+lbl_8037B0E0,p.y+k,p.z+*(const float*)&lbl_8037B0E0);ray.direction=Vec3(*(const float*)(unsigned long)&lbl_8037B0E0,lbl_8037B108,*(const float*)(long)&lbl_8037B0E0);ray.length=lbl_8037B110;return fn_80269230(this,ray,h,0xAULL,0x400000000ULL);}
extern "C" void fn_80224294(Owner*self,const Handle&first,const Handle&orientation,const Handle&context){
 if(!fn_801F7EB8(&first)||!fn_801F7EB8(&context))return;
 Actor*actor=resolve(self->getHandle(0));
 Geometry*geometry=resolve(first)->geometry;
 Vec3 start=geometry->getPosition()+Vec3(lbl_8037B0E0,lbl_8037B10C,lbl_8037B0E0);
 Vec3 current=start;
 Quat q=game_quat_identity;
 if(fn_801F7EB8(&orientation)){
  Vec3 target=resolve(orientation)->geometry->getPosition();target=target;
  float dx=target.x-start.x;float dz=target.z-start.z;float angle=fn_80285124(dx,dz);angle*=lbl_8037B0EC;
  float cosine=fn_8028506C(angle);
  float sine=fn_80284FA8(angle);
  q=Quat(cosine,lbl_8037B0E0*sine,lbl_8037B0E4*sine,lbl_8037B0E0*sine);
 }
 Hit hit;
 actor->flags&=~0x40000UL;
 Vec4 point(game_vec4_zero,lbl_8037B0E4);
 signed char have=self->getPoint(point,0,0);
 if(have&&resolve(context)->initialCast(start,&hit,point))current=hit.point;
 if(resolve(context)->downCast(current,&hit)){
  fn_801CBDE4(resolve(actor->owner),actor,hit.object,lbl_8037B0E0);
  if(!have)current=hit.point;
 }
 actor->flags|=0x40000UL;
 self->setPosition(current);
 self->setTransform(current,q,0);
 fn_8023DE28(resolve(resolve(context)->child));
 self->applyHandle(self->getHandle(0));
 if(self->flags&0x1000ULL)self->notifyHandle(context,current);
}

}
