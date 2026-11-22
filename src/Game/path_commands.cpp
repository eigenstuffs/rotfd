// Reconstructed from the GSQE78 executable; names describe observed behavior.
typedef unsigned long u32;

struct Console {
    char unknown[0x860];
    int argc;
    char* argv[16];
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
    virtual void load(const char*, const char*);
    char unknown28[0xc8 - 0x28];
    signed char write, read;
};

struct Globals {
    u32 unknown0;
    char path[128], project[128];
    char unknown104[8];
    u32 flags;
    Console* console;
    u32 unknown114;
    Manager* manager;
    char unknown11C[0x190 - 0x11C];
    char base[128];
    signed char remap;
};

extern "C" {
extern Globals lbl_801E9D24;
int fn_801F4520(const char*, const char*);
void fn_801F459C(char*);
void fn_801FA014(Console*, const char*, ...);
void fn_801BA54C(const char*, char*, const char*);
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
u32 strlen(const char*);
extern const char lbl_8037A968[] = "Read";
extern const char lbl_8037A970[] = "Write";
extern const char lbl_8037A978[] = "\\";
extern const char lbl_802ADCC8[] = "Invalid Parameters";
extern const char lbl_802ADCDC[] = "Parameter Error...";
}

extern "C" u32 fn_802076DC()
{
    if (lbl_801E9D24.console->argc != 2) {
        fn_801FA014(lbl_801E9D24.console, lbl_802ADCC8);
        return 0;
    }
    if (lbl_801E9D24.flags & 0x800)
        return 1;
    char temp[128];
    strcpy(temp, lbl_801E9D24.base);
    strcat(temp, lbl_8037A978);
    fn_801BA54C(lbl_801E9D24.console->argv[1], lbl_801E9D24.path, temp);
    char* path = lbl_801E9D24.path;
    fn_801F459C(path);
    int length = strlen(path);
    int last = length - 1;
    if (length != 0 && (signed char)path[last] == '\\')
        path[last] = 0;
    return 1;
}

extern "C" u32 fn_8020766C()
{
    if (lbl_801E9D24.console->argc != 2) {
        fn_801FA014(lbl_801E9D24.console, lbl_802ADCDC);
        return 0;
    }
    strcpy(lbl_801E9D24.project, lbl_801E9D24.console->argv[1]);
    fn_801F459C(lbl_801E9D24.project);
    return 1;
}

extern "C" u32 fn_802075AC()
{
    if (lbl_801E9D24.console->argc < 2) {
        fn_801FA014(lbl_801E9D24.console, lbl_802ADCC8);
        return 0;
    }
    char temp[128], path[128];
    strcpy(temp, lbl_801E9D24.base);
    strcat(temp, lbl_8037A978);
    fn_801BA54C(lbl_801E9D24.console->argv[1], path, temp);
    Manager* manager = lbl_801E9D24.manager;
    manager->load(lbl_801E9D24.console->argc == 3 ?
                      lbl_801E9D24.console->argv[2] : 0, path);
    return 1;
}

extern "C" u32 fn_802074F4()
{
    if (lbl_801E9D24.console->argc < 2)
        return 0;
    if (fn_801F4520(lbl_801E9D24.console->argv[1], lbl_8037A968) != 0 &&
        fn_801F4520(lbl_801E9D24.console->argv[1], lbl_8037A970) != 0)
        return 0;
    bool equal = fn_801F4520(lbl_801E9D24.console->argv[1], lbl_8037A968) == 0;
    Manager* manager = lbl_801E9D24.manager;
    manager->read = equal;
    manager->write = !manager->read;
    return 1;
}

/* Former original/path_prefix data 0x8037A97C..0x8037A980 (.sdata2), referenced as part of this unit; it starts mid-line (not 8-aligned), so it can only follow the data above. The zero alignment bytes before it (padding/path_commands.s) are now internal alignment of this unit. */
#pragma explicit_zero_data on
#pragma force_active on
extern "C" __declspec(section ".sdata2") const char lbl_8037A97C[] = "DB:";

#pragma force_active reset
