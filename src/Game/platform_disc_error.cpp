#include "Game/platform_disc_error_internal.h"
extern "C" void fn_8028F4D8(void*,int,signed char retryable){
 int event=-1;
 switch(lbl_80378168){case 5:event=0;break;case 4:event=1;break;case 6:event=2;break;case 11:event=3;break;case -1:event=4;break;}
 fn_801FA014(reinterpret_cast<DiscErrorGlobals*>(&lbl_801E9D24)->logger,lbl_802AFB30);
 VISetBlack(0);VIFlush();VIWaitForRetrace();
 if(lbl_80377F90&&lbl_80378160)lbl_80378160(event);
 else{lbl_8037816E=1;fn_8028EA98(event);}
 fn_801FA014(reinterpret_cast<DiscErrorGlobals*>(&lbl_801E9D24)->logger,lbl_802AFB40,lbl_8037816E);
 if(!retryable){
  u32 start=OSGetTick();
  do{
   reinterpret_cast<DiscErrorGlobals*>(&lbl_801E9D24)->input->update(lbl_8037B98C);
   if(reinterpret_cast<DiscErrorGlobals*>(&lbl_801E9D24)->input->query(11))break;
   fn_801EBB9C();
  }while((OSGetTick()-start)/((*reinterpret_cast<volatile u32*>(0x800000F8)>>2)/1000)<1500);
  VISetBlack(1);VIFlush();VIWaitForRetrace();GXDrawDone();GXAbortFrame();LCDisable();OSResetSystem(1,0,0);
 }
}
