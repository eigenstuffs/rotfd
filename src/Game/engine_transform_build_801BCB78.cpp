/* Original transformed query result builder.
 * See docs/notes/game-engine-transform-build.md. */
typedef unsigned int u32;
typedef unsigned long long u64;
struct Vec3_801BCB78 {
    float x,y,z;
    Vec3_801BCB78() {
    }
    Vec3_801BCB78(float a,float b,float c):x(a),y(b),z(c) {
    }
    void operator=(const Vec3_801BCB78&v) {
        x=v.x;
        y=v.y;
        z=v.z;
    }
    Vec3_801BCB78 operator+(const Vec3_801BCB78&v)const {
        return Vec3_801BCB78(x+v.x,y+v.y,z+v.z);
    }
};
struct Vec2_801BCB78 {
    float x,y;
};
struct Matrix_801BCB78 {
    float a[16];
    Vec3_801BCB78 transform(const Vec3_801BCB78&v)const {
        Vec3_801BCB78 r;
        r.x=a[0]*v.x+a[4]*v.y+a[8]*v.z+a[12];
        r.y=a[1]*v.x+a[5]*v.y+a[9]*v.z+a[13];
        r.z=a[2]*v.x+a[6]*v.y+a[10]*v.z+a[14];
        return r;
    }
};
struct MatrixCache_801BCB78 {
    Matrix_801BCB78*arrays[6];
    unsigned char active;
};
struct Globals_801BCB78 {
    char unknown[0x134];
    MatrixCache_801BCB78*cache;
};
extern "C" Globals_801BCB78 lbl_801E9D24;
extern "C" {
    void fn_801F230C(const Matrix_801BCB78*,Matrix_801BCB78*);
    extern const float lbl_8037A2D8;
}
struct Object_801BCB78 {
    char unknown[0x120];
    u32 flags;
    Matrix_801BCB78*matrix,*cached;
    char unknown12C[2];
    short index;
    Matrix_801BCB78*getMatrix() {
        if(flags&0x20) {
            cached=lbl_801E9D24.cache->arrays[lbl_801E9D24.cache->active]+index;
            fn_801F230C(matrix,cached);
            flags&=~0x20;
        }
        return cached;
    }
};
struct Input_801BCB78 {
    Vec3_801BCB78 point;
    char unknownC[0x10];
    void*pointer1C;
    Vec2_801BCB78 coordinates;
    u64 flags;
    Object_801BCB78*object;
    void*pointer34,*pointer38;
};
struct Result_801BCB78 {
    Object_801BCB78*object;
    Vec3_801BCB78 point,unknown10,transformed,offsetPoint;
    void*pointer34;
    Vec2_801BCB78 coordinates;
    u64 flags;
    void*pointer48,*pointer4C;
    float value;
};
extern "C" Result_801BCB78*fn_801BCB78(Result_801BCB78*self,const Input_801BCB78*input,const Vec3_801BCB78*offset) {
    self->object=input->object;
    self->pointer48=input->pointer34;
    self->pointer4C=input->pointer38;
    self->point=input->point;
    self->pointer34=input->pointer1C;
    self->coordinates.x=input->coordinates.x;
    self->coordinates.y=input->coordinates.y;
    self->flags=input->flags;
    Matrix_801BCB78*matrix=self->object->getMatrix();
    self->transformed=matrix->transform(self->point);
    self->offsetPoint=matrix->transform(self->point+*offset);
    self->value=lbl_8037A2D8;
    return self;
}
