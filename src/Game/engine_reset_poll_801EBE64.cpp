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
    unsigned int DVDOpen(const char*,void*);
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
struct ResetGlobals_801EBE64 {
    char unknown110[0x110];
    void*logger;
    char unknown114[0x44];
    void*owned158;
};
extern "C" void fn_801EBE64(const void*input,int size) {
    const char*strings=platform_type_registry_End_Frame_required_a_SoftReset;
    lbl_80377FB0=(int*)(OSGetArenaHi()-0xfa00);
    lbl_80377FB0[0]=size;
    if(size!=0&&(unsigned int)size!=0xdeadbeef)memcpy(lbl_80377FB0+1,input,size);
    else {
        fn_801FA014(((ResetGlobals_801EBE64*)lbl_801E9D24)->logger,strings+0x224);
        memset(lbl_80377FB0+1,0,0xf9fc);
    }
    fn_801FA014(((ResetGlobals_801EBE64*)lbl_801E9D24)->logger,strings+0x240,input,size);
    char path[32];
    char file[60];
    int request;
    strcpy(path,strings+0x260);
    if(DVDOpen(path,file))fn_8028EEEC(&request,file,lbl_80340A90,32,0);
    lbl_80377FC8=1;
    if(((ResetGlobals_801EBE64*)lbl_801E9D24)->owned158) {
        fn_801EF610(lbl_801EF5C8,((ResetGlobals_801EBE64*)lbl_801E9D24)->owned158);
        ((ResetGlobals_801EBE64*)lbl_801E9D24)->owned158=0;
    }
    VISetBlack(1);
    VIFlush();
    VIWaitForRetrace();
    GXDrawDone();
    GXAbortFrame();
    char*end=OSGetArenaHi();
    OSSetSaveRegion(OSGetArenaHi()-0xfa00,end-1);
    __PADDisableRecalibration(1);
    LCDisable();
    if(!DVDCheckDisk())OSResetSystem(0,0,0);
    else OSResetSystem(0,0,0);
}
