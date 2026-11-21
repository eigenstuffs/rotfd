/* Original engine lifetime and record routines.
* See docs/notes/game-engine-member-lifetime.md. */
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
