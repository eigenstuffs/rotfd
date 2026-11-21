/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-fn-handle-cleanup-eh.md. */
extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
struct Handle_801F7F10 {
    unsigned int word;
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
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" char __vt__15Object_800C421C[];
extern "C" {
    extern char __vt__13Manipulator_Z[],__vt__24ManipulatorDraw_802BC9D0[];
    void __dt__11Activable_ZFv(void*,int);
}
struct Root {
    char opaque00[8];
    void*vtable;
    ~Root() {
        vtable=__vt__13Manipulator_Z;
        __dt__11Activable_ZFv(this,0);
    }
};
struct Draw:Root {
    ~Draw() {
        vtable=__vt__24ManipulatorDraw_802BC9D0;
    }
};
struct Handle_800723F4 {
    unsigned int word;
    ~Handle_800723F4();
};
struct FixedHandles {
    Handle_800723F4 data[3];
};
struct Object_800C421C:Draw {
    char unknown0C[0x34];
    Handle_800723F4 handles40[3];
    ~Object_800C421C();
    static void operator delete(void*p)throw() {
        dispose(p);
    }
};
Object_800C421C::~Object_800C421C() {
    vtable=__vt__15Object_800C421C;
}
