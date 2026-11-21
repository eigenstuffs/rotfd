/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-agent-routes.md. */
typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
extern "C" char lbl_802C9024[];
struct Agent_80044118 {
    u32 unknown00[2];
    void*vtable;
    ~Agent_80044118();
};
struct Agent_800E75B0:Agent_80044118 {
    ~Agent_800E75B0();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Agent_800E75B0::~Agent_800E75B0() {
    vtable=lbl_802C9024;
}
