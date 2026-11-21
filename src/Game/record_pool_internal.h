// Private native record and pool layouts reconstructed from GSQE78.
#ifndef ROTFD_RECORD_POOL_INTERNAL_H
#define ROTFD_RECORD_POOL_INTERNAL_H
typedef unsigned long u32;
struct Manager;
struct Globals { char unknown[0x118]; Manager* manager; };
extern "C" {
extern Globals lbl_801E9D24;
extern char lbl_801EF5C8[], lbl_8028F698[];
void fn_801EF610(void*, void*);
void fn_8028FD50(void*, void*, u32);
void fn_801F86C8(Manager*, const void*, short);
extern const float lbl_8037AA40, lbl_8037AA44;
}
struct Handle_801F7F10 {
    Handle_801F7F10();
    ~Handle_801F7F10();
    u32 value;
};
struct PoolHandle1 : Handle_801F7F10 { PoolHandle1(){ value=0; } ~PoolHandle1(){} };
struct PoolHandle2 : PoolHandle1 {
    PoolHandle2(){ value=0; }
    ~PoolHandle2(){}
    PoolHandle2& operator=(const PoolHandle2& other) {
        fn_801F86C8(lbl_801E9D24.manager,this,-1);
        value=other.value;
        fn_801F86C8(lbl_801E9D24.manager,&other,1);
        return *this;
    }
};
struct PoolHandle3 : PoolHandle2 {
    PoolHandle3(){ value=0; }
    ~PoolHandle3(){}
    PoolHandle3& operator=(const PoolHandle3& other) {
        fn_801F86C8(lbl_801E9D24.manager,this,-1);
        value=other.value;
        fn_801F86C8(lbl_801E9D24.manager,&other,1);
        return *this;
    }
};
struct Vector {
    float x,y,z;
    Vector& operator=(const Vector& v) {x=v.x;y=v.y;z=v.z;return *this;}
};
extern "C" const Vector game_vec3_zero;
struct Record_80209EA0 {
    Vector position,velocity;
    float field18;
    char unknown1c[8];
    float field24,field28;
    char unknown2c[0x14];
    PoolHandle2 handle40;
    PoolHandle3 handle44,handle48,handle4c;
    u32 field50;
    char unknown54[0x54];
    ~Record_80209EA0();
    static void operator delete(void* p){fn_801EF610(lbl_801EF5C8,p);}
};
struct BitSet_80207EE8 {
    int count,capacity;u32* data;int bits;
    ~BitSet_80207EE8();
};
template<class T>struct PoolStorage {
    int count,capacity;T* data;
    void releaseStorage() {
        if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}
    }
    ~PoolStorage(){if(data){releaseStorage();data=0;}}
};
struct RecordPool_80209D30:PoolStorage<Record_80209EA0> {
    BitSet_80207EE8 occupied;
    int limit,live;
    ~RecordPool_80209D30();
    static void operator delete(void* p){fn_801EF610(lbl_801EF5C8,p);}
};
extern "C" {
signed char fn_80209DF8(RecordPool_80209D30*,int);
void fn_80209F80(Record_80209EA0*);
}

typedef char RecordSizeCheck[sizeof(Record_80209EA0)==0xA8?1:-1];
typedef char RecordPoolSizeCheck[sizeof(RecordPool_80209D30)==0x24?1:-1];
#endif
