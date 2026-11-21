// Memory-layout report (heap/stack/arena) console helpers.
// fn_801EC5DC is the out-of-line report routine; fn_801EC490 is the console command whose
// body is an inlined copy of the same report with a fixed (non-null) title string, so its
// locals are coloured like inlined-callee temporaries.  reportMemory() reproduces that
// inlined copy (the original passes a string literal from the TU string pool, which the
// (u32)-cast pool-base idiom used here cannot fold through the null check).
// _db_stack_end is the ldscript alias of _stack_addr (dtk names both relocations _stack_addr).
typedef unsigned long u32;
struct Heap { char unknown00[0x14]; u32 word14, word18, word1C; };
extern "C" {
extern char __start[], _stack_addr[], _stack_end[], _db_stack_addr[], _db_stack_end[];
extern const char platform_type_registry_End_Frame_required_a_SoftReset[];
extern Heap lbl_801EF5C8;
extern __declspec(section ".sdata2") const char lbl_8037A624[], lbl_8037A628[];
extern const float lbl_8037A630;
void* OSGetArenaLo(void);
void* OSGetArenaHi(void);
void OSReport(const char*, ...);
}

static inline void reportMemory(void)
{
    u32 dbStart; u32 stackStart;
    const char* strings = (const char*)(u32)platform_type_registry_End_Frame_required_a_SoftReset;
    u32 codeStart = (u32)__start;
    u32 arenaLo = (u32)OSGetArenaLo();
    u32 arenaHi = (u32)OSGetArenaHi();
    stackStart = (u32)_stack_end;
    u32 used = lbl_801EF5C8.word18 - lbl_801EF5C8.word14 - lbl_801EF5C8.word1C;
    u32 stackEnd = (u32)_stack_addr;
    u32 dbEnd = (u32)_db_stack_addr;
    dbStart = (u32)_db_stack_end;
    u32 codeEnd = stackStart - 1;
    OSReport(lbl_8037A624);
    OSReport(lbl_8037A628, strings + 0x3C0);
    OSReport(strings + 0x3D8);
    OSReport(strings + 0x414, codeStart, codeEnd - 1, (codeEnd - codeStart) >> 10);
    OSReport(strings + 0x43C, stackStart, stackEnd, (stackEnd - stackStart) >> 10);
    OSReport(strings + 0x464, dbStart, dbEnd, (dbEnd - dbStart) >> 10);
    OSReport(strings + 0x48C, arenaLo, arenaHi, (arenaHi - arenaLo) >> 10, (float)used / lbl_8037A630);
    OSReport(lbl_8037A624);
}

extern "C" int fn_801EC490(void)
{
    reportMemory();
    return 1;
}

extern "C" void fn_801EC5DC(const char* title)
{
    u32 arenaSize, used, codeEnd, codeStart, arenaLo;
    const char* strings = (const char*)(u32)platform_type_registry_End_Frame_required_a_SoftReset;
    codeStart = (u32)__start;
    arenaLo = (u32)OSGetArenaLo();
    u32 arenaHi = (u32)OSGetArenaHi();
    arenaSize = arenaHi - arenaLo;
    used = lbl_801EF5C8.word18 - lbl_801EF5C8.word14 - lbl_801EF5C8.word1C;
    codeEnd = (u32)_stack_end - 1;
    u32 stackEnd = (u32)_stack_addr;
    u32 dbEnd = (u32)_db_stack_addr;
    u32 dbStart = (u32)_db_stack_end;
    OSReport(lbl_8037A624);
    OSReport(lbl_8037A628, title ? title : strings + 0x4C0);
    OSReport(strings + 0x3D8);
    OSReport(strings + 0x414, codeStart, codeEnd - 1, (codeEnd - codeStart) >> 10);
    OSReport(strings + 0x43C, (u32)_stack_end, stackEnd, (stackEnd - (u32)_stack_end) >> 10);
    OSReport(strings + 0x464, dbStart, dbEnd, (dbEnd - dbStart) >> 10);
    OSReport(strings + 0x48C, arenaLo, arenaHi, arenaSize >> 10, (float)used / lbl_8037A630);
    OSReport(lbl_8037A624);
}
