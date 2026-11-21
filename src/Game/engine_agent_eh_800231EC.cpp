/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-agent-eh.md. */
typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802AFFCC[];
    void fn_801EF610(void*,void*);
}
struct Agent_80021260 {
    u32 unknown00[2];
    void*vtable;
    ~Agent_80021260();
};
struct Object_800231EC:Agent_80021260 {
    ~Object_800231EC();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800231EC::~Object_800231EC() {
    vtable=lbl_802AFFCC;
}
