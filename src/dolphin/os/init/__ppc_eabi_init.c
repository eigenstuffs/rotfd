__declspec(section ".ctors") extern void (*_ctors[])(void);
extern void PPCHalt(void);
static void __init_cpp(void);
extern void __OSPSInit(void);
extern void __OSCacheInit(void);

#pragma section code_type ".init"
/* clang-format off */
asm void __init_hardware(void)
{
    nofralloc
    mfmsr r0
    ori r0, r0, 0x2000
    mtmsr r0
    mflr r31
    bl __OSPSInit
    bl __OSCacheInit
    mtlr r31
    blr
}

asm void __flush_cache(register void* address, register unsigned int size)
{
    nofralloc
    lis r5, 0xFFFF
    ori r5, r5, 0xFFF1
    and r5, r5, r3
    subf r3, r5, r3
    add r4, r4, r3
rept:
    dcbst r0, r5
    sync
    icbi r0, r5
    addic r5, r5, 8
    subic. r4, r4, 8
    bge rept
    isync
    blr
}
/* clang-format on */
#pragma section code_type

void __init_user(void)
{
    __init_cpp();
}

static void __init_cpp(void)
{
    void (**constructor)(void);
    for (constructor = _ctors; *constructor; constructor++) {
        (*constructor)();
    }
}

void _ExitProcess(void)
{
    PPCHalt();
}
