extern "C" {
    extern signed char lbl_80377FC9,lbl_80377FC0,lbl_803780C0,lbl_80377FC8,lbl_80377FC1;
    extern char lbl_801E9D24[],platform_type_registry_End_Frame_required_a_SoftReset[];
    int OSGetResetSwitchState();
    void VISetBlack(int);
    void VIFlush();
    void VIWaitForRetrace();
    void GXDrawDone();
    void GXAbortFrame();
    void LCDisable();
    void __PADDisableRecalibration(int);
    int DVDCheckDisk();
    void OSResetSystem(int,int,int);
    void fn_801FA014(void*,const char*,...);
}
struct ResetGlobals_801EBB9C {
    char unknown[0x110];
    void*logger;
};
extern "C" unsigned char fn_801EBB9C() {
    signed char state=OSGetResetSwitchState();
    if(lbl_80377FC9!=state||lbl_80377FC0) {
        if(!lbl_803780C0) {
            if(!state||(lbl_80377FC0&&!lbl_803780C0)) {
                fn_801FA014(((ResetGlobals_801EBB9C*)lbl_801E9D24)->logger,platform_type_registry_End_Frame_required_a_SoftReset);
                VISetBlack(1);
                VIFlush();
                VIWaitForRetrace();
                GXDrawDone();
                GXAbortFrame();
                LCDisable();
                __PADDisableRecalibration(0);
                if(!DVDCheckDisk()) {
                    VISetBlack(1);
                    OSResetSystem(1,0,0);
                }
                else {
                    VISetBlack(1);
                    OSResetSystem(0,0,0);
                }
            }
            lbl_80377FC9=state;
        }
    }
    if(lbl_80377FC9!=state&&!state&&lbl_803780C0)lbl_80377FC0=1;
    signed char result=lbl_80377FC8;
    lbl_80377FC8=0;
    return result;
}
