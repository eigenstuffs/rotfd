/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-container-variants.md. */
typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_8028F698[],lbl_802EC720[],__vt__23ContainerLayer_80044168[];
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
        vtable=__vt__23ContainerLayer_80044168;
    }
};
extern "C" char lbl_802B4B50[];
struct InlineAgent:Layer {
    char unknown60[0x10];
    ~InlineAgent() {
        vtable=lbl_802B4B50;
    }
};
extern "C" char __vt__15Object_80071358[];
struct Object_80071358:Layer {
    ~Object_80071358();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_80071358::~Object_80071358() {
    vtable=__vt__15Object_80071358;
}
