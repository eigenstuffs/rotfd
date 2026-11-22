// Native lifetime view; opaque gaps and original virtual tables remain external.
typedef unsigned long u32;
extern "C" {
extern char __vt__12ObjectMove_Z[],__vt__13Manipulator_Z[],lbl_801EF5C8[],lbl_8028F698[];
void fn_801EF610(void*,void*);
void fn_8028FD50(void*,void*,int);
void __dt__11Activable_ZFv(void*,int);
}
struct Handle_801F7F10 {u32 value;~Handle_801F7F10();};
struct ObjectsBaseHandle1:Handle_801F7F10 {};
struct ObjectsBaseHandle2:ObjectsBaseHandle1 {};
struct ObjectsBaseHandle3:ObjectsBaseHandle2 {};
template<int N>struct BaseDtorElement {char unknown[N];~BaseDtorElement(){}};
template<class T>struct BaseDtorArray {
    int count,capacity;T*data;
    ~BaseDtorArray(){if(data){for(int i=0;i<count;++i)data[i].~T();if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}data=0;}}
};
struct ObjectsBaseRoot {
    u32 unknown00[2];void*vtable;char unknown0C[0x20-0xC];
    ~ObjectsBaseRoot(){vtable=__vt__13Manipulator_Z;__dt__11Activable_ZFv(this,0);}
};
struct ObjectMove_Z:ObjectsBaseRoot {
    ObjectsBaseHandle2 handle20,handle24;
    ObjectsBaseHandle3 handle28;
    char unknown2C[0x38-0x2C];
    BaseDtorArray<BaseDtorElement<12> > array38;
    BaseDtorArray<BaseDtorElement<16> > array44;
    BaseDtorArray<BaseDtorElement<12> > array50;
    BaseDtorArray<ObjectsBaseHandle2> array5C;
    ObjectsBaseHandle2 handle68;
    BaseDtorArray<BaseDtorElement<40> > array6C;
    u32 unknown78;
    char unknown7C[0x12C-0x7C];
    ObjectsBaseHandle2 handle12C;
    char unknown130[0x168-0x130];
    ~ObjectMove_Z();
    static void operator delete(void*memory)throw(){fn_801EF610(lbl_801EF5C8,memory);}
};
typedef char CheckObjectsBaseDtorRoot[sizeof(ObjectsBaseRoot)==0x20?1:-1];
typedef char CheckObjectsBaseDtor[sizeof(ObjectMove_Z)==0x168?1:-1];

ObjectMove_Z::~ObjectMove_Z(){vtable=__vt__12ObjectMove_Z;}
