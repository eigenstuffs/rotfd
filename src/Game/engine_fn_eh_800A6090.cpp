/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-fn-eh.md. */
typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_8028F698[];
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
extern "C" {
    extern char __vt__15Object_800A6090[],__vt__24ManipulatorDraw_802BC9D0[],__vt__13Manipulator_Z[];
    void __dt__11Activable_ZFv(void*,int);
    void fn_800A84D8(void*);
    void fn_800A7840(void*);
}
struct Context {
    char unknown00[0x114];
    void*manager114;
};
extern "C" Context lbl_801E9D24;
struct Root {
    u32 unknown00[2];
    void*vtable;
    char unknown0C[0x14-0xC];
    u32 unknown14;
    signed char active18;
    char unknown19[7];
    ~Root() {
        vtable=__vt__13Manipulator_Z;
        __dt__11Activable_ZFv(this,0);
    }
};
struct ManipulatorDraw:Root {
    ~ManipulatorDraw() {
        vtable=__vt__24ManipulatorDraw_802BC9D0;
    }
};
struct Element:H2 {
    char unknown04[0xD0];
    ~Element() {
    }
};
struct Pool {
    int size,capacity;
    Element*data;
    ~Pool() {
        if(data) {
            for(int i=0; i<size; i++)data[i].~Element();
            if(data) {
                fn_8028FD50(lbl_8028F698,data,capacity*sizeof(Element));
                data=0;
            }
            data=0;
        }
    }
};
struct Object_800A6090:ManipulatorDraw {
    Pool pool20;
    u32 unknown2C;
    H2 handle30,handle34;
    char unknown38[0x1980-0x38];
    H2 handle1980;
    ~Object_800A6090();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800A6090::~Object_800A6090() {
    vtable=__vt__15Object_800A6090;
    fn_800A84D8(this);
    if(lbl_801E9D24.manager114&&active18)fn_800A7840(this);
}
