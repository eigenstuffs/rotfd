typedef unsigned long U32;
extern "C" {
    extern char lbl_8028F698[],lbl_801EF5C8[];
    void fn_8028FD50(void*,void*,int);
    void fn_801EF610(void*,void*);
    void fn_80243E90(void*,int);
}
template<int N>struct Element_801C426C{
    char data[N];
    ~Element_801C426C(){
    }
}
;
template<class T>struct Pool_801C426C{
    int count,capacity;
    T*data;
    ~Pool_801C426C(){
        if(data){
            for(int i=0;
            i<count;
            i++)data[i].~T();
            if(data){
                fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));
                data=0;
            }
            data=0;
        }
    }
}
;
struct Handle_801F7F10{
    U32 word;
    ~Handle_801F7F10();
}
;
struct Handle0_801C426C:Handle_801F7F10{
    ~Handle0_801C426C(){
    }
}
;
struct Handle1_801C426C:Handle0_801C426C{
    ~Handle1_801C426C(){
    }
}
;
struct Handle2_801C426C:Handle1_801C426C{
    ~Handle2_801C426C(){
    }
}
;
struct Handle3_801C426C:Handle2_801C426C{
    ~Handle3_801C426C(){
    }
}
;
extern "C" {
    extern char lbl_802E9FF8[],__vt__24ManipulatorDraw_802BC9D0[],__vt__13Manipulator_Z[];
}
struct Activable_Z{
    U32 words[2];
    void*vtable;
    char tail[0x10];
    ~Activable_Z();
}
;
struct ObjectsRoot_801C426C:Activable_Z{
    float scalar;
    ~ObjectsRoot_801C426C(){
        vtable=__vt__13Manipulator_Z;
    }
}
;
struct ManipulatorDraw_801C426C:ObjectsRoot_801C426C{
    ~ManipulatorDraw_801C426C(){
        vtable=__vt__24ManipulatorDraw_802BC9D0;
    }
}
;
struct Record_801C426C{
    char pad[16];
    Handle1_801C426C first,second,third;
    ~Record_801C426C(){
    }
}
;
struct HandleDraw_801C426C:ManipulatorDraw_801C426C{
    Pool_801C426C<Handle2_801C426C> first;
    Pool_801C426C<Handle1_801C426C> second;
    Pool_801C426C<Record_801C426C> third;
    Handle1_801C426C a,b;
    Handle3_801C426C c;
    Handle1_801C426C d;
    ~HandleDraw_801C426C();
    static void operator delete(void*p){
        fn_801EF610(lbl_801EF5C8,p);
    }
}
;
HandleDraw_801C426C::~HandleDraw_801C426C(){
    vtable=lbl_802E9FF8;
}
