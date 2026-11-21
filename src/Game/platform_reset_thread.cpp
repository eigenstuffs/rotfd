typedef unsigned long u32;
struct ResetGlobals {unsigned char unknown[0x110];void*logger;};
extern "C" {
extern ResetGlobals lbl_801E9D24;
extern unsigned char lbl_8033E758[];
extern signed char lbl_80377FC0,lbl_80377FC8,lbl_80377FC9,lbl_803780C0;
extern const char platform_type_registry_End_Frame_required_a_SoftReset[];
int OSSuspendThread(void*);int OSResumeThread(void*);
void VIWaitForRetrace();int OSGetResetSwitchState();
void fn_801FA014(void*,const char*,...);
void VISetBlack(int);void VIFlush();void GXDrawDone();void GXAbortFrame();void LCDisable();
int __PADDisableRecalibration(int);int DVDCheckDisk();void OSResetSystem(int,u32,int);
void fn_801E9F8C(){OSSuspendThread(lbl_8033E758);}
void fn_801E9FB4(){OSResumeThread(lbl_8033E758);}
void fn_801E9FDC(){
    for(;;){
        VIWaitForRetrace();
        signed char pressed=OSGetResetSwitchState();
        if((lbl_80377FC9!=pressed||lbl_80377FC0)&&!lbl_803780C0){
            if(!pressed||(lbl_80377FC0&&!lbl_803780C0)){
                fn_801FA014(lbl_801E9D24.logger,platform_type_registry_End_Frame_required_a_SoftReset);
                VISetBlack(1);VIFlush();VIWaitForRetrace();GXDrawDone();GXAbortFrame();LCDisable();__PADDisableRecalibration(0);
                if(!DVDCheckDisk()){VISetBlack(1);OSResetSystem(1,0,0);}
                else {VISetBlack(1);OSResetSystem(0,0,0);}
            }
            lbl_80377FC9=pressed;
        }
        if(lbl_80377FC9!=pressed&&!pressed&&lbl_803780C0)lbl_80377FC0=1;
        lbl_80377FC8=0;
    }
}
}
