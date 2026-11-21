extern "C"{extern char lbl_801E9D24[];
extern const char lbl_802AF24C[];extern signed char lbl_80377FC9[7],lbl_80377FC0;void VIWaitForRetrace();int OSGetResetSwitchState();void fn_801FA014(void*,const char*,...);}
extern "C" void fn_80279300(){for(;;){VIWaitForRetrace();if(!OSGetResetSwitchState()&&lbl_80377FC9[0]){fn_801FA014(*(void**)(lbl_801E9D24+0x110),lbl_802AF24C);lbl_80377FC0=1;}lbl_80377FC9[0]=OSGetResetSwitchState();}}
