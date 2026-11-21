/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-agent-routes.md. */
typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
extern "C" char lbl_802B6774[];
struct Object_80021108 {
    u32 unknown00[2];
    void*vtable;
    ~Object_80021108();
};
struct Agent_80064744:Object_80021108 {
    ~Agent_80064744();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Agent_80064744::~Agent_80064744() {
    vtable=lbl_802B6774;
}
