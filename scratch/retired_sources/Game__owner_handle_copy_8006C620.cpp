/* Copy a supplied owner handle into a scene-root slot.
 * The two derived destructors resolve to the existing strong handle owners.
 */
typedef unsigned long u32;

struct Handle_801F7F10 {
    u32 word;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct Manager;
struct Scene {
    char unknown00[0x15058];
    void* receiver;
};
struct Context {
    char unknown00[0x118];
    Manager* manager;
    char unknown11C[8];
    Scene* scene;
};
extern "C" {
extern Context lbl_801E9D24;
void fn_801F86C8(Manager*, const Handle_801F7F10*, short);
void fn_80058CB8(void*, short, const Handle_801F7F10*);
void fn_801EF610(void*, void*);
extern char lbl_801EF5C8[];
}

static inline void copy(Handle_801F7F10& out, Manager* manager,
                        const Handle_801F7F10& value)
{
    out.word = value.word;
    fn_801F86C8(manager, &value, 1);
}

struct Handle_80020478 : Handle_801F7F10 {
    Handle_80020478() { word = 0; }
    ~Handle_80020478() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};
struct Handle_80020834 : Handle_80020478 {
    Handle_80020834(const Handle_801F7F10& value)
    {
        copy(*this, lbl_801E9D24.manager, value);
    }
    ~Handle_80020834() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};
struct Owner {
    u32 unknown00;
    Handle_801F7F10 handle04;
};

extern "C" void fn_8006C620(void*, int value, const Owner* owner)
{
    const Handle_801F7F10& original = owner->handle04;
    Handle_80020834 handle(original);
    fn_80058CB8(lbl_801E9D24.scene->receiver, (short)value, &handle);
}
