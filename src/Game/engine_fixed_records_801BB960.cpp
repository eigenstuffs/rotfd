/* Original fixed-capacity engine record routines.
 * See docs/notes/game-engine-fixed-records.md. */
typedef unsigned int u32;
inline void*operator new(unsigned long,void*p) {
    return p;
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
    extern const float lbl_8037A2A0;
}
struct Sphere_801BB960 {
    Vec3_801BB960 point;
    float radius;
    Sphere_801BB960():point(game_vec4_zero),radius(lbl_8037A2A0) {
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
struct Matrix_801BB960 {
    float a[16];
};
struct MatrixCache_801BB960 {
    Matrix_801BB960*arrays[6];
    unsigned char active;
};
struct Globals_801BB960 {
    char unknown[0x134];
    MatrixCache_801BB960*cache;
};
extern "C" Globals_801BB960 lbl_801E9D24;
extern "C" {
    void fn_801F230C(const Matrix_801BB960*,Matrix_801BB960*);
    Sphere_801BB960 fn_80099A00(const Matrix_801BB960*,const Sphere_801BB960*);
}
struct Object_801BB960 {
    char unknown[0x120];
    u32 flags;
    Matrix_801BB960*matrix,*cached;
    char unknown12C[2];
    short index;
    Matrix_801BB960*getMatrix() {
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
