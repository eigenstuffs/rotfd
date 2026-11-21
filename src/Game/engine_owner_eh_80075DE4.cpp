/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-owner-eh.md. */
typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802EBE80[],lbl_802EBE28[],__vt__13Manipulator_Z[];
    void fn_801EF610(void*,void*);
    void __dt__11Activable_ZFv(void*,int);
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
struct Table {
    char unknown00[0x4C];
    void(*notify)(void*);
};
struct Root {
    u32 unknown00[2];
    Table*vtable;
    char unknown0C[0x18];
    ~Root() {
        vtable=(Table*)__vt__13Manipulator_Z;
        __dt__11Activable_ZFv(this,0);
    }
};
struct Object_80075DE4:Root {
    H5 handle24;
    H1 handle28;
    ~Object_80075DE4();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_80075DE4::~Object_80075DE4() {
    vtable=(Table*)lbl_802EBE28;
}
