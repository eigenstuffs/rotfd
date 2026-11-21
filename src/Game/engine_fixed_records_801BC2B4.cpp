/* Original fixed-capacity engine record routines.
 * See docs/notes/game-engine-fixed-records.md. */
typedef unsigned int u32;
inline void*operator new(unsigned long,void*p) {
    return p;
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
    extern const Vec3_801BC2B4 game_vec4_zero;
    extern const float lbl_8037A2A0;
}
struct Sphere_801BC2B4 {
    Vec3_801BC2B4 point;
    float radius;
    Sphere_801BC2B4():point(game_vec4_zero),radius(lbl_8037A2A0) {
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
    void fn_801BBDC8(Owner_801BC2B4*,int,float);
    void fn_8024C338(void*);
}
extern "C" void fn_801BC2B4(Owner_801BC2B4*self,float delta) {
    for(int i=0; i<self->count; ++i) {
        if(((Item_801BC2B4*)self->items)[i].object->flags&0x2000)fn_801BBDC8(self,i,delta);
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
