typedef unsigned int u32;
inline void*operator new(unsigned long,void*p) {
    return p;
}
struct Vec3_801BA988 {
    float x,y,z;
    Vec3_801BA988() {
    }
    Vec3_801BA988(const Vec3_801BA988&v) {
        x=v.x;
        y=v.y;
        z=v.z;
    }
    void operator=(const Vec3_801BA988&v) {
        x=v.x;
        y=v.y;
        z=v.z;
    }
};
extern "C" {
    extern const Vec3_801BA988 game_vec4_zero;
    extern const float lbl_8037A278;
}
struct Sphere_801BA988 {
    Vec3_801BA988 point;
    float radius;
    Sphere_801BA988():point(game_vec4_zero),radius(lbl_8037A278) {
    }
    void operator=(const Sphere_801BA988&s) {
        point=s.point;
        radius=s.radius;
    }
};
struct Record_801BA988 {
    Sphere_801BA988 sphere;
    float weight,extra;
    Record_801BA988() {
    }
    ~Record_801BA988() {
    }
};
template<class T,int N>struct FixedArray_801BA988 {
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
struct Owner_801BA988 {
    char unknown[0x18];
    signed char enabled;
    char unknown19[0x850-0x19];
    FixedArray_801BA988<Record_801BA988,8>records;
};
extern "C" void fn_801BA988(Owner_801BA988*self,const Sphere_801BA988*sphere,float weight,float multiplier) {
    if(self->enabled) {
        int i=self->records.add();
        self->records.data[i].sphere=*sphere;
        self->records.data[i].weight=weight;
        self->records.data[i].extra=multiplier*sphere->radius;
    }
}
