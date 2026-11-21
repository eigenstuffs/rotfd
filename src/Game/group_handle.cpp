// Reconstructed typed-handle specialization. Original class names are unknown.
typedef unsigned long u32;
extern "C" {
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
}

struct Handle_801F7F10 {
    Handle_801F7F10();
    ~Handle_801F7F10();
    u32 value;
};

// The observed initialization and destruction retain three type layers.
struct GroupHandleLayer1 : Handle_801F7F10 {
    GroupHandleLayer1() { value = 0; }
    ~GroupHandleLayer1() {}
};
struct GroupHandleLayer2 : GroupHandleLayer1 {
    GroupHandleLayer2() { value = 0; }
    ~GroupHandleLayer2() {}
};
struct Handle_801FFE58 : GroupHandleLayer2 {
    Handle_801FFE58();
    ~Handle_801FFE58();
    static void operator delete(void* memory) {
        fn_801EF610(lbl_801EF5C8, memory);
    }
};

Handle_801FFE58::Handle_801FFE58() { value = 0; }
Handle_801FFE58::~Handle_801FFE58() {}
