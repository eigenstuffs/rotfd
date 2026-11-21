// Reconstructed RTC resource command from the original GSQE78 instructions.
typedef unsigned long u32;
struct Handle_801F7F10 {
    Handle_801F7F10();
    ~Handle_801F7F10();
    u32 value;
};
struct ManagerStorage { char unknown[0x24]; };
struct Manager : ManagerStorage {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual Handle_801F7F10 find(const char*);
};
struct Groups;
struct ConsoleArguments {
    char unknown[0x860]; int argc;
    u32 unknown864; const char* arg1;
    u32 unknown86C; const char* arg3; const char* arg4;
    char unknown878[0x8BC - 0x878]; float arg2Value;
};
struct RTCGlobals {
    char unknown[0x110]; ConsoleArguments* console;
    u32 unknown114; Manager* manager;
    char unknown11C[0x20]; Groups* groups;
};
extern "C" RTCGlobals lbl_801E9D24;
struct NameHash { u32 value; NameHash(const char*); };
struct NameType { u32 value; NameType(const NameHash& source) : value(source.value) {} };
extern "C" {
u32 fn_801F948C(void*, const char*);
void fn_801F86C8(Manager*, const void*, short);
Handle_801F7F10 fn_801B5054(Manager*, const NameHash&, const NameType&);
u32 fn_801F7EB8(const void*);
int fn_801FE99C(Groups*, const void*);
void fn_80206F14(Groups*, int, int, const void*, const NameType&);
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
extern const char lbl_8037A918[6], lbl_8037A920[5];
extern const char lbl_802AD958[], lbl_802AD964[];
}
inline NameHash::NameHash(const char* name) { value = fn_801F948C(this, name); }
struct RTCZeroHandle : Handle_801F7F10 { RTCZeroHandle() { value = 0; } };
struct RTCOwnedHandle : RTCZeroHandle {
    RTCOwnedHandle(const Handle_801F7F10& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
extern "C" signed char fn_80203B10() {
    if (lbl_801E9D24.console->argc < 4)
        return 0;
    RTCOwnedHandle found(fn_801B5054(lbl_801E9D24.manager,
        NameHash(lbl_801E9D24.console->arg1), NameType(NameHash(lbl_8037A918))));
    if (!fn_801F7EB8(&found))
        return 0;
    int selection = (int)lbl_801E9D24.console->arg2Value;
    char name[128];
    strcpy(name, lbl_8037A920);
    strcat(name, lbl_801E9D24.console->arg3);
    strcat(name, lbl_802AD958);
    RTCOwnedHandle resource(lbl_801E9D24.manager->find(name));
    if (!fn_801F7EB8(&resource))
        return 0;
    int group = fn_801FE99C(lbl_801E9D24.groups, &found);
    if (group < 0)
        return 0;
    if (lbl_801E9D24.console->argc == 5)
        fn_80206F14(lbl_801E9D24.groups, group, selection - 1, &resource,
                   NameType(NameHash(lbl_801E9D24.console->arg4)));
    else
        fn_80206F14(lbl_801E9D24.groups, group, selection - 1, &resource,
                   NameType(NameHash(lbl_802AD964)));
    return 1;
}
