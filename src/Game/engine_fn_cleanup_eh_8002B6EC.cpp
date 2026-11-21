/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-fn-cleanup-eh.md. */
extern "C" {
    extern char lbl_801EF5C8[],lbl_802B170C[];
    void fn_801EF610(void*,void*);
    void __dt__17LodAgent_802EC8A8Fv(void*,int);
}
struct Handle_801F7F10 {
    unsigned int word;
    ~Handle_801F7F10();
};
struct InlineHandle:Handle_801F7F10 {
};
struct Agent_8002B5F4 {
    char unknown00[8];
    void*vtable;
    char unknown0C[0x74];
    char handle80[4];
    ~Agent_8002B5F4();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Agent_8002B5F4::~Agent_8002B5F4() {
    vtable=lbl_802B170C;
    reinterpret_cast<InlineHandle*>(handle80)->~InlineHandle();
    __dt__17LodAgent_802EC8A8Fv(this,0);
}
