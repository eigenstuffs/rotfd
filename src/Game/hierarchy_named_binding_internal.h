#ifndef ROTFD_HIERARCHY_NAMED_BINDING_INTERNAL_H
#define ROTFD_HIERARCHY_NAMED_BINDING_INTERNAL_H
// Private views for the named-object binding command.
typedef unsigned long u32;
struct ConsoleArguments {
    char unknown[0x860]; int argc; u32 unknown864; const char* arg1;
    u32 unknown86C; const char* arg3;
    char unknown874[0x8A6 - 0x874]; signed char arg2IsNumeric;
    char unknown8A7[0x8BC - 0x8A7]; float arg2Value, arg3Value, arg4Value;
};
struct Object;
struct Handle {union {u32 value;struct {signed int generation:8;signed int index:24;}bits;};};
struct Entry {Object*object;u32 unused[2];signed char generation;char pad[3];};
struct Manager {u32 unused[2];Entry*entries;};
struct HandleList {int count,capacity;Handle*data;};
struct Groups {char unknown[0x14];HandleList entries;};
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

extern "C" {
void fn_801FED04(Groups*,int);
signed char fn_801FEADC(Groups*,const CommandOwnedHandle&,int,int*);
void fn_80201A14(Object*,int);
void fn_80201B14(Object*,int);
u32 fn_80200CBC(Object*,int,signed char);
}
static inline Object*resolve(const Handle&h){Entry*e=lbl_801E9D24.manager->entries+h.bits.index;return e->generation==h.bits.generation?e->object:0;}
extern "C" { void fn_80200EEC(Object*,int,const NameType&,int); void fn_802017D8(Object*,int,const NameType&,int); }
#endif
