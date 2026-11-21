/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-container-agents.md. */
typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_8028F698[],lbl_802B0330[],lbl_802EC810[],lbl_802ECA18[],lbl_802B435C[],__vt__23ContainerLayer_80044168[],lbl_802EC720[];
    void fn_801EF610(void*,void*);
    void fn_8028FD50(void*,void*,int);
    void fn_80020FE8(void*,int);
}
struct Handle_801F7F10 {
    u32 word;
    ~Handle_801F7F10();
};
struct H1_8004E99C:Handle_801F7F10 {
};
struct H2_8004E99C:H1_8004E99C {
};
struct H3_8004E99C:H2_8004E99C {
};
struct H4_8004E99C:H3_8004E99C {
};
struct H5_8004E99C:H4_8004E99C {
};
struct H6_8004E99C:H5_8004E99C {
};
struct Element_8004E99C {
    u32 word;
    ~Element_8004E99C() {
    }
};
struct Array_8004E99C {
    int count,capacity;
    Element_8004E99C*data;
    ~Array_8004E99C() {
        if(data) {
            for(int i=0; i<count; i++)data[i].~Element_8004E99C();
            if(data) {
                fn_8028FD50(lbl_8028F698,data,capacity*sizeof(Element_8004E99C));
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
struct Base_8004E99C:Object_8025F0D8 {
    Array_8004E99C array48;
    u32 unknown54;
    H2_8004E99C handle58;
    u32 unknown5C;
    ~Base_8004E99C() {
        vtable=lbl_802EC720;
    }
};
struct Layer_8004E99C:Base_8004E99C {
    ~Layer_8004E99C() {
        vtable=__vt__23ContainerLayer_80044168;
    }
};
struct Agent_8004E90C:Layer_8004E99C {
    H2_8004E99C handle60;
    ~Agent_8004E90C();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Agent_8004E90C::~Agent_8004E90C() {
    vtable=lbl_802B435C;
}
