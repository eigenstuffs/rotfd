/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-eh.md. */
typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_8028F698[],lbl_802B0330[],lbl_802EC810[],lbl_802ECA18[],lbl_802EC798[],lbl_802ED000[],lbl_802EC720[];
    void fn_801EF610(void*,void*);
    void fn_8028FD50(void*,void*,int);
    void fn_80020FE8(void*,int);
}
struct Handle_801F7F10 {
    u32 word;
    ~Handle_801F7F10();
};
struct H1_80021108:Handle_801F7F10 {
};
struct H2_80021108:H1_80021108 {
};
struct H3_80021108:H2_80021108 {
};
struct H4_80021108:H3_80021108 {
};
struct H5_80021108:H4_80021108 {
};
struct H6_80021108:H5_80021108 {
};
struct Element_80021108 {
    u32 word;
    ~Element_80021108() {
    }
};
struct Array_80021108 {
    int count,capacity;
    Element_80021108*data;
    ~Array_80021108() {
        if(data) {
            for(int i=0; i<count; i++)data[i].~Element_80021108();
            if(data) {
                fn_8028FD50(lbl_8028F698,data,capacity*sizeof(Element_80021108));
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
struct Base_80021108:Object_8025F0D8 {
    Array_80021108 array48;
    u32 unknown54;
    H2_80021108 handle58;
    u32 unknown5C;
    ~Base_80021108() {
        vtable=lbl_802EC720;
    }
};
struct Layer_80021108:Base_80021108 {
    ~Layer_80021108() {
        vtable=lbl_802ED000;
    }
};
struct Object_80021108:Layer_80021108 {
    H2_80021108 handle60;
    H3_80021108 handle64;
    char unknown68[8];
    ~Object_80021108();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_80021108::~Object_80021108() {
    vtable=lbl_802EC798;
}
