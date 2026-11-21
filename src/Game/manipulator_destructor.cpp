// Destructor ABI view: the native table is retained in its original later owner.
// The complete native-interface probe is preserved in scratch/game_manipulator_destructor.
typedef unsigned long u32;
extern "C" {
extern char __vt__13Manipulator_Z[], lbl_801EF5C8[];
void fn_801EF610(void*, void*);
}
struct Activable_Z {
    u32 unknown0, identity;
    void* vtable;
    u32 prev, next, mode;
    signed char active;
    char pad[3];
    ~Activable_Z();
};
struct Manipulator_Z : Activable_Z {
    float accumulated;
    ~Manipulator_Z();
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};
Manipulator_Z::~Manipulator_Z() {
    vtable = __vt__13Manipulator_Z;
}
typedef char CheckManipulatorSize[sizeof(Manipulator_Z) == 0x20 ? 1 : -1];
