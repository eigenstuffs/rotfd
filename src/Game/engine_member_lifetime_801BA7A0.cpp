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
struct ObjectsRoot_801BA7A0:Activable_Z{
    float scalar;
    ~ObjectsRoot_801BA7A0(){
        vtable=__vt__13Manipulator_Z;
    }
}
;
struct DynamicAnimBase_801BA7A0:ObjectsRoot_801BA7A0{
    float scalar20;
    ~DynamicAnimBase_801BA7A0(){
        vtable=lbl_802E9F48;
    }
}
;
template<int N>struct Element_801BA7A0{
    char data[N];
    ~Element_801BA7A0(){
    }
}
;
template<class T,int N>struct FixedArray_801BA7A0{
    char storage[N*sizeof(T)];
    int count;
    ~FixedArray_801BA7A0(){
        for(int i=0;
        i<count;
        i++)((T*)storage)[i].~T();
    }
}
;
extern "C" {
    extern char lbl_802E9EA0[];
}
struct FixedAnim_801BA7A0:DynamicAnimBase_801BA7A0{
    FixedArray_801BA7A0<Element_801BA7A0<0x68>,16> first;
    FixedArray_801BA7A0<Element_801BA7A0<4>,16> second;
    FixedArray_801BA7A0<Element_801BA7A0<44>,8> third;
    FixedArray_801BA7A0<Element_801BA7A0<24>,8> fourth;
    ~FixedAnim_801BA7A0();
    static void operator delete(void*p){
        fn_801EF610(lbl_801EF5C8,p);
    }
}
;
FixedAnim_801BA7A0::~FixedAnim_801BA7A0(){
    vtable=lbl_802E9EA0;
}
