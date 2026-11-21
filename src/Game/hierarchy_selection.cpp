// RemoveGame: remove the WORLD named by the sole console argument.
typedef unsigned long u32;
struct ConsoleArguments { char unknown[0x860]; int argc; u32 unknown864; const char* arg1; };
struct Manager;
struct Groups;
struct SelectionGlobals {
    char unknown[0x110]; ConsoleArguments* console;
    u32 unknown114; Manager* manager;
    char unknown11C[0x20]; Groups* groups;
};
extern "C" SelectionGlobals lbl_801E9D24;
struct Handle_801F7F10 {
    Handle_801F7F10();
    ~Handle_801F7F10();
    u32 value;
};
struct NameHash { u32 value; NameHash(const char*); };
struct NameType { u32 value; NameType(const NameHash& hash) : value(hash.value) {} };
extern "C" {
u32 fn_801F948C(void*, const char*);
void fn_801F86C8(Manager*, const void*, short);
Handle_801F7F10 fn_801B5054(Manager*, const NameHash&, const NameType&);
u32 fn_801F7EB8(const void*);
void fn_801FF24C(Groups*, const void*);
extern const char lbl_8037A918[6];
}
inline NameHash::NameHash(const char* name) { value = fn_801F948C(this, name); }
struct SelectionZeroHandle : Handle_801F7F10 { SelectionZeroHandle() { value = 0; } };
struct SelectionOwnedHandle : SelectionZeroHandle {
    SelectionOwnedHandle(const Handle_801F7F10& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
extern "C" signed char fn_802042EC() {
    if (lbl_801E9D24.console->argc != 2)
        return 0;
    SelectionOwnedHandle found(fn_801B5054(lbl_801E9D24.manager,
        NameHash(lbl_801E9D24.console->arg1), NameType(NameHash(lbl_8037A918))));
    if (!fn_801F7EB8(&found))
        return 0;
    fn_801FF24C(lbl_801E9D24.groups, &found);
    return 1;
}
