// Bounded retained-handle assignment; the input reference is non-const.
typedef unsigned long RetainedAssignWord;
struct Handle_801F7F10 {
    RetainedAssignWord word;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct RetainedAssignManager;
struct RetainedAssignContext {
    char unknown00[0x118];
    RetainedAssignManager* manager;
};
extern "C" {
extern RetainedAssignContext lbl_801E9D24;
extern char lbl_801EF5C8[];
void fn_801F86C8(RetainedAssignManager*, const Handle_801F7F10*, short);
void fn_801EF610(void*, void*);
}
struct RetainedAssignZero_80094920 : Handle_801F7F10 {
    RetainedAssignZero_80094920() { word = 0; }
    ~RetainedAssignZero_80094920() {}
    static void operator delete(void* p) throw() {
        fn_801EF610(lbl_801EF5C8, p);
    }
};
struct RetainedAssignLayer_80094920 : RetainedAssignZero_80094920 {
    RetainedAssignLayer_80094920() { word = 0; }
    ~RetainedAssignLayer_80094920() {}
    static void operator delete(void* p) throw() {
        fn_801EF610(lbl_801EF5C8, p);
    }
};
struct Handle_8002D518 : RetainedAssignLayer_80094920 {
    Handle_8002D518() { word = 0; }
    ~Handle_8002D518() {}
    static void operator delete(void* p) throw() {
        fn_801EF610(lbl_801EF5C8, p);
    }
};
struct Handle_8002D49C : Handle_8002D518 {
    Handle_8002D49C(Handle_801F7F10& value) {
        word = value.word;
        fn_801F86C8(lbl_801E9D24.manager, &value, 1);
    }
    ~Handle_8002D49C() {}
    static void operator delete(void* p) throw() {
        fn_801EF610(lbl_801EF5C8, p);
    }
};
struct RetainedAssignOwner {
    char unknown00[0x348];
    Handle_801F7F10 handle;
};
extern "C" void slot144__10CActorMoveFv(RetainedAssignOwner* self,
                           Handle_801F7F10& value) {
    Handle_8002D49C retained(value);
    fn_801F86C8(lbl_801E9D24.manager, &self->handle, -1);
    self->handle.word = retained.word;
    fn_801F86C8(lbl_801E9D24.manager, &retained, 1);
}
