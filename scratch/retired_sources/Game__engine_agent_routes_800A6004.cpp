/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-agent-routes.md. */
typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
extern "C" {
    extern char __vt__24ManipulatorDraw_802BC9D0[],__vt__13Manipulator_Z[];
    void __dt__11Activable_ZFv(void*,int);
}
struct Root_800A6004 {
    u32 unknown00[2];
    void*vtable;
    ~Root_800A6004() {
        vtable=__vt__13Manipulator_Z;
        __dt__11Activable_ZFv(this,0);
    }
};
struct ManipulatorDraw_802BC9D0:Root_800A6004 {
    ~ManipulatorDraw_802BC9D0();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
ManipulatorDraw_802BC9D0::~ManipulatorDraw_802BC9D0() {
    vtable=__vt__24ManipulatorDraw_802BC9D0;
}
