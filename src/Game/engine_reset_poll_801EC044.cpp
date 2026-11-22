extern "C" {
    extern char lbl_801E9D24[],lbl_801EF5C8[],platform_type_registry_End_Frame_required_a_SoftReset[],lbl_802AD16C[],lbl_802AD1AC[],lbl_80340A90[];
    extern int*lbl_80377FB0;
    extern signed char lbl_80377FC8;
    char*OSGetArenaHi();
    void OSSetSaveRegion(void*,void*);
    void fn_801FA014(void*,const char*,...);
    void*memcpy(void*,const void*,unsigned long);
    void*memset(void*,int,unsigned long);
    char*strcpy(char*,const char*);
    int DVDOpen(const char*,void*);
    void fn_8028EEEC(void*,void*,void*,int,int);
    void fn_801EF610(void*,void*);
    void VISetBlack(int);
    void VIFlush();
    void VIWaitForRetrace();
    void GXDrawDone();
    void GXAbortFrame();
    void __PADDisableRecalibration(int);
    void LCDisable();
    int DVDCheckDisk();
    void OSResetSystem(int,int,int);
}
struct ResetGlobals_801EC044 {
    char unknown110[0x110];
    void*logger;
    char unknown114[0x44];
    void*owned158;
};
extern "C" int fn_801EC044(void*output,int size) {
    lbl_80377FB0=(int*)(OSGetArenaHi()-0xfa00);
    int stored=lbl_80377FB0[0];
    if(stored==0||(unsigned int)stored==0xdeadbeef) {
        fn_801FA014(((ResetGlobals_801EC044*)lbl_801E9D24)->logger,lbl_802AD16C);
        return 0;
    }
    fn_801FA014(((ResetGlobals_801EC044*)lbl_801E9D24)->logger,lbl_802AD1AC,size,stored);
    if(size>stored)memcpy(output,lbl_80377FB0+1,stored);
    else memcpy(output,lbl_80377FB0+1,size);
    return 1;
}
