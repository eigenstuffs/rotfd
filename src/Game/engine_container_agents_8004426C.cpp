typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_8028F698[],lbl_802B0330[],lbl_802EC810[],lbl_802ECA18[],lbl_802B4B50[],__vt__23ContainerLayer_80044168[],lbl_802EC720[];
    void fn_801EF610(void*,void*);
    void fn_8028FD50(void*,void*,int);
    void fn_80020FE8(void*,int);
}
struct Handle_801F7F10 {
    u32 word;
    ~Handle_801F7F10();
};
struct H1_8004426C:Handle_801F7F10 {
};
struct H2_8004426C:H1_8004426C {
};
struct H3_8004426C:H2_8004426C {
};
struct H4_8004426C:H3_8004426C {
};
struct H5_8004426C:H4_8004426C {
};
struct H6_8004426C:H5_8004426C {
};
struct Element_8004426C {
    u32 word;
    ~Element_8004426C() {
    }
};
struct Array_8004426C {
    int count,capacity;
    Element_8004426C*data;
    ~Array_8004426C() {
        if(data) {
            for(int i=0; i<count; i++)data[i].~Element_8004426C();
            if(data) {
                fn_8028FD50(lbl_8028F698,data,capacity*sizeof(Element_8004426C));
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
struct Base_8004426C:Object_8025F0D8 {
    Array_8004426C array48;
    u32 unknown54;
    H2_8004426C handle58;
    u32 unknown5C;
    ~Base_8004426C() {
        vtable=lbl_802EC720;
    }
};
struct Layer_8004426C:Base_8004426C {
    ~Layer_8004426C() {
        vtable=__vt__23ContainerLayer_80044168;
    }
};
struct Agent_80044118:Layer_8004426C {
    ~Agent_80044118();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Agent_80044118::~Agent_80044118() {
    vtable=lbl_802B4B50;
}
