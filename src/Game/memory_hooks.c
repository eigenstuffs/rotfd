/* MSL backing hooks into the game's allocator. Field names are inferred. */
extern struct {
    unsigned char reserved_00[0x10];
    void *arena_hi, *arena_lo;
    unsigned int reserved_18;
    unsigned int limit_1c;
} lbl_801EF5C8;
extern struct {
    unsigned char reserved_00[0x110];
    void *reporter_110;
} lbl_801E9D24;
extern const char lbl_802AD450[];
extern void fn_801EF610(void *,void *);
extern unsigned char *fn_801EF860(void *,unsigned int,unsigned int);
extern void fn_801FA014(void *,const char *,...);
void __sys_free(void *memory)
{
    fn_801EF610(&lbl_801EF5C8,memory);
}
void *__sys_alloc(int size)
{
    unsigned int available = lbl_801EF5C8.limit_1c;
    if(size + 32 > available) {
        fn_801FA014(lbl_801E9D24.reporter_110,lbl_802AD450,size,32,available);
        for(;;) {}
    }
    return fn_801EF860(&lbl_801EF5C8,size,32) + 12;
}

unsigned int fn_801EFCBC(unsigned int a,unsigned int b)
{
    if(a<b) b=a;
    return b;
}
extern void *OSGetArenaLo(void);
extern void *OSGetArenaHi(void);
extern void fn_801EFAC4(void *);
extern void fn_801EFA7C(void *,int);
extern void *__register_global_object(void *,void *,void *);
extern unsigned char lbl_80340AB0[16];
void fn_801EFCD0(void)
{
    lbl_801EF5C8.arena_lo=OSGetArenaLo();
    lbl_801EF5C8.arena_hi=OSGetArenaHi();
    fn_801EFAC4(&lbl_801EF5C8);
    __register_global_object(&lbl_801EF5C8,fn_801EFA7C,lbl_80340AB0);
}
__declspec(section ".ctors")
static void *const memory_manager_init_reference=fn_801EFCD0;
