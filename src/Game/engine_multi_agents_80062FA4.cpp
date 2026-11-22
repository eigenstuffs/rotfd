typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_8028F698[],lbl_802EC720[],lbl_802ED000[];
    void fn_801EF610(void*,void*);
    void fn_8028FD50(void*,void*,int);
}
struct Handle_801F7F10 {
    u32 word;
    ~Handle_801F7F10();
};
struct H1:Handle_801F7F10 {
};
struct H2:H1 {
};
struct H3:H2 {
};
struct H4:H3 {
};
struct H5:H4 {
};
struct H6:H5 {
};
struct Empty4 {
    u32 word;
    ~Empty4() {
    }
};
template<class T>struct Array {
    int count,capacity;
    T*data;
    ~Array() {
        if(data) {
            for(int i=0; i<count; i++)data[i].~T();
            if(data) {
                fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));
                data=0;
            }
            data=0;
        }
    }
};
struct Object_8025F0D8 {
    u32 unknown00[2];
    void*vtable;
    char unknownC[0x48-0xC];
    ~Object_8025F0D8();
};
struct Base:Object_8025F0D8 {
    Array<Empty4>array48;
    u32 unknown54;
    H2 handle58;
    u32 unknown5C;
    ~Base() {
        vtable=lbl_802EC720;
    }
};
struct Layer:Base {
    ~Layer() {
        vtable=lbl_802ED000;
    }
};
struct Object_8005E258 {
    u32 unknown00;
    void*secondaryVtable;
    char unknown08[0x160-8];
    ~Object_8005E258();
};
extern "C" char __vt__17CActorScriptAgent[];
struct Agent_8002B5F4 {
    u32 unknown00[2];
    void*vtable;
    char unknownC[0x90-0xC];
    ~Agent_8002B5F4();
};
struct CActorScriptAgent:Agent_8002B5F4,Object_8005E258 {
    u32 unknown1F0;
    H6 handle1F4;
    ~CActorScriptAgent();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
CActorScriptAgent::~CActorScriptAgent() {
    vtable=__vt__17CActorScriptAgent;
    secondaryVtable=__vt__17CActorScriptAgent+0xB4;
}
