// Native destructor using the observed vptr field; the complete virtual interface stays external.
extern "C" {
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
extern char __vt__13ObjectsBounce[];
}
struct ObjectsMove {
    unsigned long unknown00[2];
    void* vtable;
    char unknown0C[0x1A8 - 0xC];
    ~ObjectsMove();
};
struct ObjectsBounce : ObjectsMove {
    ~ObjectsBounce();
    static void operator delete(void* memory) {
        fn_801EF610(lbl_801EF5C8, memory);
    }
};
ObjectsBounce::~ObjectsBounce() { vtable = __vt__13ObjectsBounce; }
