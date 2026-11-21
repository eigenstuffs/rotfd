#ifndef ROTFD_HIERARCHY_COMMANDS_INTERNAL_H
#define ROTFD_HIERARCHY_COMMANDS_INTERNAL_H
// Private layouts for the recovered hierarchy commands at 80204000 and 80204184.
typedef unsigned long u32;
struct ConsoleArguments {
    char unknown[0x860]; int argc; u32 unknown864; const char* arg1;
    char unknown86C[0x8A6 - 0x86C]; signed char arg2IsNumeric;
    char unknown8A7[0x8BC - 0x8A7]; float arg2Value, arg3Value;
};
struct Manager;
struct Groups;
struct CommandGlobals {
    char unknown[0x110]; ConsoleArguments* console;
    u32 unknown114; Manager* manager;
    char unknown11C[0x20]; Groups* groups;
};
extern "C" CommandGlobals lbl_801E9D24;
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
int fn_801FE99C(Groups*, const void*);
void fn_80206E9C(Groups*, int, int, int);
void fn_80206F90(Groups*, int, int);
extern const char lbl_8037A918[6];
}
inline NameHash::NameHash(const char* name) { value = fn_801F948C(this, name); }
struct CommandZeroHandle : Handle_801F7F10 { CommandZeroHandle() { value = 0; } };
struct CommandOwnedHandle : CommandZeroHandle {
    CommandOwnedHandle(const Handle_801F7F10& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};

#endif
