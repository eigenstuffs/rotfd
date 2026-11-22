// Merged TU: .text 0x801BB7CC-0x801BC99C, .rodata 0x802ACA48-0x802ACA78, .sdata2 0x8037A2A0-0x8037A2D8
// flags: -O4,p -Cpp_exceptions off -RTTI off -fp_contract on (GC/1.3.2)

// Literal 1.0f through an inline keeps fn_801BBB74's first-loop register order (was lbl_8037A2A0 by name).
static inline float onef() { return 1.0f; }

inline void*operator new(unsigned long,void*p) {
    return p;
}

// fn_801BBDC8: per-item spring/pendulum integration (same TU as fn_801BBB74).
typedef unsigned int u32;

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float reciprocalSqrt(register float value)
{
    register float result;
    asm { frsqrte result, value }
    return result;
}

extern "C" {
    double acos(double);
    double cos(double);
    double sin(double);
}

inline float safeSqrt_801BBB74(float sq)
{
    float r = 0.0f;
    if (sq != r) r = fastSqrt(sq);
    return r;
}

inline float safeSqrt2(float sq)
{
    float r = 0.0f;
    if (sq != r) r = fastSqrt(sq);
    return r;
}

inline float recip(float x) { return 1.0f / x; }

struct Vec3_801BBB74 {
    float x, y, z;
    Vec3_801BBB74() {}
    Vec3_801BBB74(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3_801BBB74 operator*(float s) const { return Vec3_801BBB74(x * s, y * s, z * s); }
    Vec3_801BBB74 operator/(float d) const { float inv = 1.0f / d; return Vec3_801BBB74(x * inv, y * inv, z * inv); }
    Vec3_801BBB74 mD(float s) const { float rz = z; rz *= s; return Vec3_801BBB74(x * s, y * s, rz); }
    void operator*=(float s) { x *= s; y *= s; z *= s; }
    const Vec3_801BBB74& self() const { return *this; }
    void set(const Vec3_801BBB74& v) { x = v.x; y = v.y; z = v.z; }
    void operator+=(const Vec3_801BBB74& v) { x += v.x; y += v.y; z += v.z; }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = 0.0f;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

inline Vec3_801BBB74 scale2(const Vec3_801BBB74& v, const float& g) { return Vec3_801BBB74(v.x * (0.8f * g), v.y * (0.8f * g), v.z * (0.8f * g)); }
inline Vec3_801BBB74 operator+(const Vec3_801BBB74& a, const Vec3_801BBB74& b) { return Vec3_801BBB74(a.x + b.x, a.y + b.y, a.z + b.z); }
inline Vec3_801BBB74 operator-(const Vec3_801BBB74& a, const Vec3_801BBB74& b) { return Vec3_801BBB74(a.x - b.x, a.y - b.y, a.z - b.z); }
inline Vec3_801BBB74 operator-(const Vec3_801BBB74& v) { Vec3_801BBB74 r; r.x = -v.x; r.y = -v.y; r.z = -v.z; return r; }

struct Quat_801BBB74;
extern "C" {
    void fn_801F1BB0(Quat_801BBB74*, const Quat_801BBB74*);
    Vec3_801BBB74 fn_801F1B1C(const Quat_801BBB74& q, const Vec3_801BBB74& v);
}
struct Quat_801BBB74 {
    float w, x, y, z;
    void operator*=(const Quat_801BBB74& q) { fn_801F1BB0(this, &q); }
    Quat_801BBB74() {}
    Quat_801BBB74(const Quat_801BBB74& q) { w = q.w; x = q.x; y = q.y; z = q.z; }
    void operator=(const Quat_801BBB74& q) { w = q.w; x = q.x; y = q.y; z = q.z; }
    void conjugate() { float nz = -z, ny = -y, nx = -x; x = nx; y = ny; z = nz; }
};

struct Matrix_801BBB74 {
    float a[16];
    float rotateX(const Vec3_801BBB74& v) const { return a[0] * v.x + a[4] * v.y + a[8] * v.z; }
    float rotateZ(const Vec3_801BBB74& v) const { return a[2] * v.x + a[6] * v.y + a[10] * v.z; }
    Vec3_801BBB74 getPos() const { return Vec3_801BBB74(a[12], a[13], a[14]); }
    Vec3_801BBB74 rotate(const Vec3_801BBB74& v) const
    {
        Vec3_801BBB74 r;
        r.x = a[0] * v.x + a[4] * v.y + a[8] * v.z;
        r.y = a[1] * v.x + a[5] * v.y + a[9] * v.z;
        r.z = a[2] * v.x + a[6] * v.y + a[10] * v.z;
        return r;
    }
};

struct MatrixCache_801BBB74 {
    Matrix_801BBB74* arrays[6];
    unsigned char active;
};

struct APManager_801BC408;
struct APResource_801BC408;
struct Globals_801BBB74 {
    char unknown[0x118];
    APManager_801BC408* manager;
    char unknown11C[0x18];
    MatrixCache_801BBB74* cache;
    char unknown138[0xC];
    APResource_801BC408* resource;
};

extern "C" Globals_801BBB74 lbl_801E9D24;

extern "C" {
    void fn_801F230C(const Matrix_801BBB74*, Matrix_801BBB74*);
}

struct Object_801BBB74 {
    char unknown[0xC8];
    Quat_801BBB74 rotation;
    char unknownD8[0x120 - 0xD8];
    u32 flags;
    Matrix_801BBB74 *matrix, *cached;
    char unknown12C[2];
    short index;
    Matrix_801BBB74* getMatrix()
    {
        if (flags & 0x20) {
            cached = lbl_801E9D24.cache->arrays[lbl_801E9D24.cache->active] + index;
            fn_801F230C(matrix, cached);
            flags &= ~0x20;
        }
        return cached;
    }
};

struct Item_801BBB74 {
    Object_801BBB74* object;
    Quat_801BBB74 quat;
    Vec3_801BBB74 prev;
    Vec3_801BBB74 vel;
    Quat_801BBB74 rest;
    const Vec3_801BBB74& setVel(const Vec3_801BBB74& v, const Vec3_801BBB74& delta)
    {
        vel = v;
        return delta;
    }
    char unknown3C[0x7C - 0x3C];
    float angVelX, angVelY;
    float spring;
    float accelGain;
    float gainZ, gainX;
};

struct Record_801BBB74 {
    Vec3_801BBB74 point;
    float radius;
    float weight, extra;
};

struct Cone_801BBB74 {
    Vec3_801BBB74 point;
    Vec3_801BBB74 dir;
    float weight;
    float maxDot;
    float minDot;
    float inner;
    float outer;
};

template<class T, int N> struct FixedArray_801BBB74 {
    T data[N];
    int count;
    T& at(const unsigned int& i) { return data[i]; }
};

struct Owner_801BBB74 {
    char unknown[0x20];
    float mass;
    Item_801BBB74 items[16];
    char unknown964[4];
    int itemCount;
    FixedArray_801BBB74<Record_801BBB74, 8> records;
    FixedArray_801BBB74<Cone_801BBB74, 8> cones;
};

extern "C" const Vec3_801BBB74 game_vec3_zero;

extern "C" Vec3_801BBB74 fn_801BBB74(Owner_801BBB74* self, Vec3_801BBB74 pos);




typedef unsigned long U32;
extern "C" {
    extern char lbl_802E9F48[],__vt__13Manipulator_Z[],lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
struct Activable_Z{
    U32 words[2];
    void*vtable;
    char tail[0x10];
    ~Activable_Z();
}
;
struct ObjectsRoot_801BB7CC:Activable_Z{
    float scalar;
    ~ObjectsRoot_801BB7CC(){
        vtable=__vt__13Manipulator_Z;
    }
}
;
struct DynamicAnimBase_801BB7CC:ObjectsRoot_801BB7CC{
    float scalar20;
    ~DynamicAnimBase_801BB7CC(){
        vtable=lbl_802E9F48;
    }
}
;
template<int N>struct Element_801BB7CC{
    char data[N];
    ~Element_801BB7CC(){
    }
}
;
template<class T,int N>struct FixedArray_801BB7CC{
    char storage[N*sizeof(T)];
    int count;
    ~FixedArray_801BB7CC(){
        for(int i=0;
        i<count;
        i++)((T*)storage)[i].~T();
    }
}
;
extern "C" {
    extern char lbl_802E9EF8[];
}
struct FixedAnim_801BB7CC:DynamicAnimBase_801BB7CC{
    FixedArray_801BB7CC<Element_801BB7CC<0x94>,16> first;
    int unknown968;
    FixedArray_801BB7CC<Element_801BB7CC<24>,8> second;
    FixedArray_801BB7CC<Element_801BB7CC<44>,8> third;
    ~FixedAnim_801BB7CC();
    static void operator delete(void*p){
        fn_801EF610(lbl_801EF5C8,p);
    }
}
;
FixedAnim_801BB7CC::~FixedAnim_801BB7CC(){
    vtable=lbl_802E9EF8;
}

extern "C" {
/* Object association used by the fixed sphere record owner. */
struct SphereRecordObject;
struct SphereRecordOwnerView {
    char unknown00[0xB94];
    struct SphereRecordObject* object;
};
void fn_801BB958(void* self, void* object)
{
    ((struct SphereRecordOwnerView*)self)->object = (struct SphereRecordObject*)object;
}
}



struct Vec3_801BB960 {
    float x,y,z;
    Vec3_801BB960() {
    }
    Vec3_801BB960(const Vec3_801BB960&v) {
        x=v.x;
        y=v.y;
        z=v.z;
    }
    void operator=(const Vec3_801BB960&v) {
        x=v.x;
        y=v.y;
        z=v.z;
    }
};
extern "C" {
    extern const Vec3_801BB960 game_vec4_zero;
}
struct Sphere_801BB960 {
    Vec3_801BB960 point;
    float radius;
    Sphere_801BB960():point(game_vec4_zero),radius(1.0f) {
    }
    void operator=(const Sphere_801BB960&s) {
        point=s.point;
        radius=s.radius;
    }
};
struct Record_801BB960 {
    Sphere_801BB960 sphere;
    float weight,extra;
    Record_801BB960() {
    }
    ~Record_801BB960() {
    }
};
template<class T,int N>struct FixedArray_801BB960 {
    T data[N];
    int count;
    int add() {
        if(count>=N) {
            new(&data[N-1])T;
            return N-1;
        }
        new(&data[count++])T;
        return count-1;
    }
    void resize(int n) {
        if(n>count) {
            for(int i=count; i<n; ++i)new(&data[i])T;
            count=n;
        }
        else if(n<count) {
            for(int i=count-1; i>=n; --i)data[i].~T();
            count=n;
        }
    }
};
extern "C" {
    Sphere_801BB960 fn_80099A00(const Matrix_801BBB74*,const Sphere_801BB960*);
}
struct Object_801BB960 {
    char unknown[0x120];
    u32 flags;
    Matrix_801BBB74*matrix,*cached;
    char unknown12C[2];
    short index;
    Matrix_801BBB74*getMatrix() {
        if(flags&0x20) {
            cached=lbl_801E9D24.cache->arrays[lbl_801E9D24.cache->active]+index;
            fn_801F230C(matrix,cached);
            flags&=~0x20;
        }
        return cached;
    }
};
struct Owner_801BB960 {
    char unknown[0x18];
    signed char enabled;
    char unknown19[0x96C-0x19];
    FixedArray_801BB960<Record_801BB960,8>records;
    char unknownA30[0xB94-0xA30];
    Object_801BB960*object;
};
extern "C" void fn_801BB960(Owner_801BB960*self,const Sphere_801BB960*sphere,float weight,float multiplier) {
    if(self->enabled) {
        int i=self->records.add();
        self->records.data[i].sphere=fn_80099A00(self->object->getMatrix(),sphere);
        self->records.data[i].weight=weight;
        self->records.data[i].extra=multiplier*sphere->radius;
    }
}

extern "C" {

static inline int append_801BBAF4(void *object) {if(*(int *)((char *)object+0xb90)>=8)return 7;++*(int *)((char *)object+0xb90);return *(int *)((char *)object+0xb90)-1;}

void fn_801BBAF4(void *object,const float *a,const float *b,float f1,float f2,float f3,float f4,float f5) {if(*((signed char *)object+0x18)){int index=append_801BBAF4(object);char *out=(char *)object+index*44;*(float *)(out+0xa30)=a[0];*(float *)(out+0xa34)=a[1];*(float *)(out+0xa38)=a[2];*(float *)(out+0xa3c)=b[0];*(float *)(out+0xa40)=b[1];*(float *)(out+0xa44)=b[2];*(float *)(out+0xa48)=f1;*(float *)(out+0xa4c)=f2;*(float *)(out+0xa50)=f3;*(float *)(out+0xa54)=f4;*(float *)(out+0xa58)=f5;}}
}

#pragma opt_common_subs off
extern "C" Vec3_801BBB74 fn_801BBB74(Owner_801BBB74* self, Vec3_801BBB74 pos)
{
    Vec3_801BBB74 sum = game_vec3_zero;
    for (int i = 0; i < self->cones.count; i++) {
        Cone_801BBB74& c = self->cones.at(i);
        Vec3_801BBB74 d = c.point - pos;
        float dist = d.length();
        if (dist > 0.000001f) {
        float inner = c.inner, outer = c.outer;
        if (dist < inner + outer) {
            Vec3_801BBB74 n = d;
            n *= onef() / dist;
            float dot = n.x * c.dir.x + n.y * c.dir.y + n.z * c.dir.z;
            float minDot = c.minDot;
            if (dot > minDot) {
                float scale = onef();
                if (dist > inner) scale = (dist - inner) / (outer - inner);
                if (dot < c.maxDot) scale *= (dot - minDot) / (c.maxDot - minDot);
                sum += n * (scale * c.weight);
            }
        }
        }
    }
    for (int i = 0; i < self->records.count; i++) {
        Record_801BBB74& r = self->records.at(i);
        Vec3_801BBB74 d = pos - r.point;
        float dist = d.length();
        if (dist > 0.000001f) {
        float radius = r.radius, extra = r.extra;
        if (dist < radius + extra) {
            float inv = 1.0f / dist;
            Vec3_801BBB74 n = d;
            n *= inv;
            if (dist < radius) {
                sum += n * r.weight;
            } else {
                float t = (dist - radius) / (extra - radius);
                sum += n * (t * r.weight);
            }
        }
        }
    }
    return sum;
}
#pragma opt_common_subs reset



struct Vec2_801BBDC8 {
    float x, y;
    Vec2_801BBDC8() {}
    Vec2_801BBDC8(float ax, float ay) : x(ax), y(ay) {}
    Vec2_801BBDC8 operator*(float s) const { return Vec2_801BBDC8(x * s, y * s); }
    Vec2_801BBDC8 operator+(const Vec2_801BBDC8& o) const { return Vec2_801BBDC8(x + o.x, y + o.y); }
    void operator+=(const Vec2_801BBDC8& o) { x += o.x; y += o.y; }
    void operator*=(float s) { x *= s; y *= s; }
};

extern "C" void fn_801BBDC8(Owner_801BBB74* self, int idx, float dt)
{
    Quat_801BBB74 dq;
    float sx, sz, px;
    Owner_801BBB74* base = (Owner_801BBB74*)((char*)self + idx * sizeof(Item_801BBB74));
#define it (base->items[0])
    Object_801BBB74* obj = it.object;
    Matrix_801BBB74* m = obj->getMatrix();
    Vec3_801BBB74 pos = obj->matrix->getPos();
    Vec3_801BBB74 localVel = m->rotate((pos - it.prev) / dt);
    it.prev = pos;
    Vec3_801BBB74 am = (it.setVel(localVel, localVel - it.vel) / dt).mD(1.0f / self->mass);
    float tx = it.gainX;
    float tz, dragX, dragY, k;
    k = 0.8f * it.accelGain;
    tx *= am.x * k;
    tz = it.gainZ * (am.z * k);
    dragX = -localVel.x * dt;
    dragY = -localVel.y * dt;
    dragX *= 150.0f;
    dragY *= 150.0f;
    tz += dragY;
    tx += dragX;
    Quat_801BBB74 q = it.rest;
    q *= it.quat;
    Vec3_801BBB74 push = fn_801BBB74(self, pos) * -1.0f;
    px = m->a[0] * push.x + m->a[4] * push.y + m->a[8] * push.z;
    float pz = m->a[2] * push.x + m->a[6] * push.y + m->a[10] * push.z;
    Vec3_801BBB74 up = fn_801F1B1C(q, Vec3_801BBB74(0.0f, 1.0f, 0.0f));
    sx = up.x;
    sz = up.z;
    float angle = acos(up.y);
    float s = 120.0f * it.spring;
    sx *= s;
    sz *= s;
    sx += px;
    sz += pz;
    tx += sx - 80.0f * it.angVelX;
    tz += sz - 80.0f * it.angVelY;
    it.angVelX += tx / 100.0f * dt;
    it.angVelY += tz / 100.0f * dt;
    float axisX = -it.angVelY;
    float axisY = 0.0f;
    float axisZ = it.angVelX;
    if (angle > 1.5707964f) {
        it.angVelX = 0.0f;
        it.angVelY = 0.0f;
        it.vel = Vec3_801BBB74(0.0f, 0.0f, 0.0f);
        it.quat = it.rest;
        it.quat.conjugate();
    } else {
        float sq = axisX * axisX + axisY * axisY + axisZ * axisZ;
        if (sq > 0.000001f) {
            float inv = reciprocalSqrt(sq);
            float nx = axisX * inv;
            float ny = axisY * inv;
            float nz = axisZ * inv;
            float half = 0.5f * safeSqrt2(sq);
            dq.w = cos(half);
            float sn = sin(half);
            dq.x = nx * sn;
            dq.y = ny * sn;
            dq.z = nz * sn;
        } else {
            dq.w = 1.0f - 0.25f * sq;
            dq.x = 0.5f * axisX;
            dq.y = axisY;
            dq.z = 0.5f * axisZ;
        }
        it.quat *= dq;
    }
    obj->rotation = it.quat;
}



struct Vec3_801BC2B4 {
    float x,y,z;
    Vec3_801BC2B4() {
    }
    Vec3_801BC2B4(const Vec3_801BC2B4&v) {
        x=v.x;
        y=v.y;
        z=v.z;
    }
    void operator=(const Vec3_801BC2B4&v) {
        x=v.x;
        y=v.y;
        z=v.z;
    }
};
extern "C" {
    
}
struct Sphere_801BC2B4 {
    Vec3_801BC2B4 point;
    float radius;
    Sphere_801BC2B4():point(*(const Vec3_801BC2B4*)&game_vec4_zero),radius(1.0f) {
    }
    void operator=(const Sphere_801BC2B4&s) {
        point=s.point;
        radius=s.radius;
    }
};
struct Record_801BC2B4 {
    Sphere_801BC2B4 sphere;
    float weight,extra;
    Record_801BC2B4() {
    }
    ~Record_801BC2B4() {
    }
};
template<class T,int N>struct FixedArray_801BC2B4 {
    char storage[N*sizeof(T)];
    int count;
    int add() {
        if(count>=N) {
            new(&((T*)storage)[N-1])T;
            return N-1;
        }
        new(&((T*)storage)[count++])T;
        return count-1;
    }
    void resize(int n) {
        if(n>count) {
            for(int i=count; i<n; ++i)new(&((T*)storage)[i])T;
        }
        else if(n<count) {
            for(int i=count-1; i>=n; --i)((T*)storage)[i].~T();
        }
        count=n;
    }
};
struct Object_801BC2B4 {
    char unknown[0x120];
    u32 flags;
};
struct Item_801BC2B4 {
    Object_801BC2B4*object;
    char unknown4[0x90];
};
struct Empty_801BC2B4 {
    char unknown[0x2C];
    Empty_801BC2B4() {
    }
    ~Empty_801BC2B4() {
    }
};
struct Owner_801BC2B4 {
    char unknown[0x24];
    char items[16*sizeof(Item_801BC2B4)];
    char unknown964[4];
    int count;
    FixedArray_801BC2B4<Record_801BC2B4,8>records;
    char unknownA30[0xB90-0xA30];
    int emptyCount;
    void*objectB94,*objectB98;
};
extern "C" {
    
    void fn_8024C338(void*);
}
#pragma opt_strength_reduction off
extern "C" void fn_801BC2B4(Owner_801BC2B4*self,float delta) {
    for(int i=0; i<self->count; ++i) {
        if(((Item_801BC2B4*)self->items)[i].object->flags&0x2000)fn_801BBDC8((Owner_801BBB74*)self,i,delta);
    }
    fn_8024C338(self->objectB98);
    if(0>self->emptyCount) {
        for(int i=self->emptyCount; i<0; ++i) {
        }
    }
    else if(0<self->emptyCount) {
        for(int i=self->emptyCount-1; i>=0; --i) {
        }
    }
    self->emptyCount=0;
    self->records.resize(0);
}
#pragma opt_strength_reduction reset

// Observed actor parameter records and three independent fixed-width script keys.
// The partial views below describe only fields accessed by fn_801BC408.
static const char dynamicXFilter_801BC408[16]="DYN_XFILTER";
static const char dynamicYFilter_801BC408[16]="DYN_YFILTER";
static const char dynamicTension_801BC408[16]="DYN_TENSION";
struct APVector_801BC408 {float x,y,z;void operator=(const APVector_801BC408&v){x=v.x;y=v.y;z=v.z;}void set(float a,float b,float c){x=a;y=b;z=c;}void negate(){set(-x,-y,-z);}};
struct APHandle_801BC408 {signed int generation:8;signed int index:24;};
struct APNested_801BC408 {char unknown00[0x30];APVector_801BC408 position;};
struct APObject_801BC408 {char unknown00[0x2C];APHandle_801BC408 parent;char unknown30[0x98];float x,y,z,w;char unknownD8[0x4C];APNested_801BC408*nested;};
struct APEntry_801BC408 {APObject_801BC408*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct APManager_801BC408 {char unknown00[8];APEntry_801BC408*entries;};
struct APResource_801BC408 {char unknown00[0x94];int*indices;int index(const int&i)const{return indices[i];}};
struct APContext_801BC408 {char unknown00[0x118];APManager_801BC408*manager;char unknown11C[0x28];APResource_801BC408*resource;};
struct APInput_801BC408 {char unknown00[0x28];APHandle_801BC408*handles;};
extern "C" {unsigned long strlen(const char*);int strncmp(const char*,const char*,unsigned long);int atoi(const char*);const char*fn_8025318C(APObject_801BC408*,int*);const char*fn_802530C8(APObject_801BC408*,int*);}
static inline APObject_801BC408*resolveAP_801BC408(const APHandle_801BC408&h){APEntry_801BC408*e=&lbl_801E9D24.manager->entries[h.index];if(e->generation==h.generation)return e->object;return 0;}

struct APRecord_801BC408 {APObject_801BC408*object;float x,y,z,w;APVector_801BC408 position,zero;float copyX;APVector_801BC408 inverse;char unknown3C[0x40];float a,b,c,d,e,f;APRecord_801BC408(){}~APRecord_801BC408(){}};
template<class T,int N>struct APFixed_801BC408 {T storage[N];int count;T&operator[](int i){return storage[i];}int append(){if(count>=N){new(&storage[N-1])T;return N-1;}new(&storage[count++])T;return count-1;}void resize(int n){if(n>count){for(int i=count;i<n;++i)new(&storage[i])T;}else if(n<count){for(int i=count-1;i>=n;--i)storage[i].~T();}count=n;}};
struct APOwner_801BC408 {char unknown00[0x20];float value;APFixed_801BC408<APRecord_801BC408,16>records;int found;char unknown96C[0x22C];APInput_801BC408*input;};
typedef char APRecordSize_801BC408[sizeof(APRecord_801BC408)==0x94?1:-1];
extern "C" void fn_801BC408(APOwner_801BC408*self,APInput_801BC408*input){
 self->found=0;self->records.resize(0);self->value=1.0f;self->input=input;
 if(self->input){for(int i=0;i<16;++i){APObject_801BC408*object=resolveAP_801BC408(self->input->handles[lbl_801E9D24.resource->index(i+12)]);if(object){
 int index=self->records.append();APRecord_801BC408&record=self->records[index];record.object=object;record.position.set(object->nested->position.x,object->nested->position.y,object->nested->position.z);
 record.x=object->x;record.y=object->y;record.z=object->z;record.w=object->w;
 record.copyX=record.x;record.inverse.x=record.y;record.inverse.y=record.z;record.inverse.z=record.w;record.inverse.negate();record.zero=*(const APVector_801BC408*)&game_vec3_zero;record.a=0.0f;record.b=0.0f;
 APObject_801BC408*parent=resolveAP_801BC408(object->parent);record.f=record.e=record.d=record.c=1.0f;
 if(parent){int length;const char*line=fn_8025318C(parent,&length);while(line){
 if(strncmp(line,dynamicXFilter_801BC408,strlen(dynamicXFilter_801BC408))==0){int n=atoi(line+strlen(dynamicXFilter_801BC408));if(n<0)n=0;if(n>100)n=100;record.e=(float)n/100.0f;}
 if(strncmp(line,dynamicYFilter_801BC408,strlen(dynamicYFilter_801BC408))==0){int n=atoi(line+strlen(dynamicYFilter_801BC408));if(n<0)n=0;if(n>100)n=100;record.f=(float)n/100.0f;}
 if(strncmp(line,dynamicTension_801BC408,strlen(dynamicTension_801BC408))==0){int n=atoi(line+strlen(dynamicXFilter_801BC408));if(n<0)n=0;if(n>100)n=100;record.c=(float)n/100.0f;}
 line=fn_802530C8(parent,&length);}}
 ++self->found;}}}
}

extern "C" {



static inline void put3_801BC7DC(float *out,float x,float y,float z) {out[0]=x;out[1]=y;out[2]=z;}

struct Record_801BC7DC {char pad[0x94];};

static inline void reset_record(struct Record_801BC7DC *record) {
char *p=(char *)record;
*(float *)(p+0x7c)=0.0f;*(float *)(p+0x80)=0.0f;
*(float *)(p+0x20)=0.0f;*(float *)(p+0x24)=0.0f;*(float *)(p+0x28)=0.0f;
*(float *)(p+4)=*(float *)(p+0x2c);*(float *)(p+8)=*(float *)(p+0x30);*(float *)(p+0xc)=*(float *)(p+0x34);*(float *)(p+0x10)=*(float *)(p+0x38);
put3_801BC7DC((float *)(p+8),-*(float *)(p+8),-*(float *)(p+0xc),-*(float *)(p+0x10));
}

void fn_801BC7DC(void *object) {struct Record_801BC7DC *records=(struct Record_801BC7DC *)((char *)object+0x24);int i;for(i=0;i<16;++i)reset_record(&records[i]);}
}

extern "C" {







extern void __dt__11Activable_ZFv(void *,int);

static inline void destroy_base(void *object) {if(object){*(void **)((char *)object+8)=(void *)__vt__13Manipulator_Z;__dt__11Activable_ZFv(object,0);}}

void *fn_801BC8A8(void *object,short release) {if(object){*(void **)((char *)object+8)=(void *)lbl_802E9F48;destroy_base(object);if(release>0)fn_801EF610(lbl_801EF5C8,object);}return object;}

extern signed char slot1C__12BaseObject_ZFv(void *);

signed char fn_801BC920(void *object) {return !!slot1C__12BaseObject_ZFv(object);}

extern void slot18__11Activable_ZFv(void *);

extern void fn_80213920(void *,int);

void fn_801BC954(void *object) {slot18__11Activable_ZFv(object);fn_80213920(object,5);}
/* Partial observed state: resetting the word at+78 reports success. */
struct ResetState { unsigned char unknown00[0x78]; unsigned int state; };
int fn_801BC98C(struct ResetState* self) { self->state=0; return 1; }
}
