// Checked child activation and owner destructor (partial text split).
// The preceding bounding-sphere builder fn_80246E64 belongs to the same
// original unit but remains original code (99.4%: one FPR swap); see
// scratch/claude_match/auto_03_80246E64_text/final.cpp.
extern "C" const float lbl_8037B3DC; // 1.0f
extern "C" const float lbl_8037B3E0; // 0.0f
extern "C" const float lbl_8037B3E4; // 0.5f

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

struct SphereReturnPoint {
    float x, y, z;
    SphereReturnPoint() {}
    SphereReturnPoint(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    SphereReturnPoint(const SphereReturnPoint& p): x(p.x), y(p.y), z(p.z) {}
    SphereReturnPoint& operator=(const SphereReturnPoint& p)
    { x = p.x; y = p.y; z = p.z; return *this; }
    const SphereReturnPoint& get() const { return *this; }
    SphereReturnPoint operator-(const SphereReturnPoint& o) const { SphereReturnPoint r(x - o.x, y - o.y, z - o.z); return r.get(); }
    float length() const
    {
        SphereReturnPoint p(x * x, y * y, z * z);
        float sq = p.x + p.y + p.z;
        float r = lbl_8037B3E0;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};
struct SphereReturnValue {
    SphereReturnPoint point;
    float radius;
    SphereReturnValue() {}
    SphereReturnValue(const SphereReturnValue& s): point(s.point), radius(s.radius) {}
    SphereReturnValue& operator=(const SphereReturnValue& s)
    { point = s.point; radius = s.radius; return *this; }
};
struct SphereMatrix {
    float m[4][4];
    SphereReturnPoint transform(const SphereReturnPoint& v) const
    {
        SphereReturnPoint r;
        r.x = m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z + m[3][0];
        r.y = m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z + m[3][1];
        r.z = m[0][2] * v.x + m[1][2] * v.y + m[2][2] * v.z + m[3][2];
        return r;
    }
};


struct HandleIndex{const int value;HandleIndex(int v):value(v){}operator int()const{return value;}};
struct CheckedActivateHandle {signed int generation:8;signed int index:24;};
typedef unsigned long CheckedActivateWord;
struct RegistryBase;
struct RootStorage_80207414 {CheckedActivateWord unknown00;union{CheckedActivateWord identity;CheckedActivateHandle handle;};};
struct BaseObject_Z:RootStorage_80207414 {BaseObject_Z();virtual ~BaseObject_Z();virtual void slot0C(unsigned long);virtual void slot10();virtual void slot14();virtual void slot18();virtual signed char slot1C();};
struct CheckedActivateEntry {BaseObject_Z*object;CheckedActivateWord key;unsigned long unknown08;signed char generation;char unknown0D[3];bool matchesGeneration(signed char g)const{return generation==g;}BaseObject_Z*getObject()const{return object;}CheckedActivateWord getKey()const{return key;}};
struct CheckedActivateEntries{CheckedActivateEntry*p;CheckedActivateEntry&operator[](const HandleIndex&i)const{return p[i];}};
struct CheckedActivateManager {int count,capacity;CheckedActivateEntries entries;};
struct CheckedActivateOwner:BaseObject_Z {char unknown0C[0xB4];int count,capacity;CheckedActivateHandle*handles;};
extern "C" {
extern struct {char unknown00[0x118];CheckedActivateManager*manager;char unknown11C[0x28];RegistryBase*first;char unknown148[0x10];RegistryBase*second;}lbl_801E9D24;
void*fn_801F7EB8(const void*);
void fn_801F6624(RegistryBase*,const CheckedActivateWord*,const CheckedActivateWord*);
}
static inline BaseObject_Z*resolveCheckedActivate(const CheckedActivateHandle&h){CheckedActivateManager*m=lbl_801E9D24.manager;const HandleIndex index(h.index);signed char generation=h.generation;if(m->entries[index].matchesGeneration(generation))return m->entries[index].getObject();return 0;}
static inline CheckedActivateWord lookupCheckedActivate(const CheckedActivateHandle&h){CheckedActivateManager*m=lbl_801E9D24.manager;const HandleIndex index(h.index);signed char generation=h.generation;int valid=0;if(index<m->count&&generation==((signed char*)m->entries.p)[index*sizeof(CheckedActivateEntry)+12])valid=1;if(valid)return *(CheckedActivateWord*)((char*)m->entries.p+index*sizeof(CheckedActivateEntry)+4);return 0;}
extern "C" signed char fn_80246F94(CheckedActivateOwner*self){
 if(!self->BaseObject_Z::slot1C())return 0;
 for(int i=0;i<self->count;++i)if(fn_801F7EB8(&self->handles[i]))resolveCheckedActivate(self->handles[i])->slot1C();
 CheckedActivateWord key=lookupCheckedActivate(self->handle);
 if(lbl_801E9D24.first)fn_801F6624(lbl_801E9D24.first,&self->unknown00,&key);
 if(lbl_801E9D24.second)fn_801F6624(lbl_801E9D24.second,&self->unknown00,&key);
 return 1;
}

typedef char CheckedActivateHandleSize[sizeof(CheckedActivateHandle)==4?1:-1];
typedef char CheckedActivateRootSize[sizeof(BaseObject_Z)==12?1:-1];
typedef char CheckedActivateEntrySize[sizeof(CheckedActivateEntry)==16?1:-1];
typedef char CheckedActivateOwnerSize[sizeof(CheckedActivateOwner)==0xCC?1:-1];

extern "C" {
extern char lbl_802EC210[], lbl_801EF5C8[], lbl_8028F698[];
void fn_801EF610(void*, void*);
void fn_8028FD50(void*, void*, int);
void fn_801F5CA4(RegistryBase*, void*, const CheckedActivateWord*);
void fn_80243E90(void*, short);
}
struct Handle_801F7F10 { CheckedActivateWord word; ~Handle_801F7F10(); };
struct ReleaseHandle1 : Handle_801F7F10 { ~ReleaseHandle1() {} };
struct ReleaseHandle2 : ReleaseHandle1 { ~ReleaseHandle2() {} };
template<class T> struct ReleaseArray {
    int count, capacity;
    T* data;
    ~ReleaseArray() {
        if (data) {
            for (int i = 0; i < count; ++i) data[i].~T();
            if (data) {
                fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
                data = 0;
            }
            data = 0;
        }
    }
};
struct ReleaseOwner : RootStorage_80207414 {
    void* table;
    char unknown0C[0x68];
    void* buffers[16];
    char unknownB4[0xC];
    ReleaseArray<ReleaseHandle2> handles;
};
static inline void releaseBuffer(void* p) { if (p) fn_801EF610(lbl_801EF5C8, p); }
extern "C" ReleaseOwner* fn_80247128(ReleaseOwner* self, short deleting)
{
    if (self) {
        self->table = lbl_802EC210;
        releaseBuffer(self->buffers[0]);
        releaseBuffer(self->buffers[1]);
        releaseBuffer(self->buffers[2]);
        releaseBuffer(self->buffers[3]);
        releaseBuffer(self->buffers[4]);
        releaseBuffer(self->buffers[5]);
        releaseBuffer(self->buffers[6]);
        releaseBuffer(self->buffers[7]);
        releaseBuffer(self->buffers[8]);
        releaseBuffer(self->buffers[9]);
        releaseBuffer(self->buffers[10]);
        releaseBuffer(self->buffers[11]);
        releaseBuffer(self->buffers[12]);
        releaseBuffer(self->buffers[13]);
        releaseBuffer(self->buffers[14]);
        releaseBuffer(self->buffers[15]);
        CheckedActivateWord key = lookupCheckedActivate(self->handle);
        if (lbl_801E9D24.first) fn_801F5CA4(lbl_801E9D24.first, self, &key);
        if (lbl_801E9D24.second) fn_801F5CA4(lbl_801E9D24.second, self, &key);
        self->handles.~ReleaseArray<ReleaseHandle2>();
        fn_80243E90(self, 0);
        if (deleting > 0) fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
typedef char ReleaseOwnerSize[sizeof(ReleaseOwner) == 0xCC ? 1 : -1];
