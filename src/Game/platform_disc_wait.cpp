#include "Game/platform_disc_poll_internal.h"
extern "C" int fn_8028EF84(void*self){
 const char*strings=lbl_802AF908;
 DiscWaitGlobals*globals=&lbl_801E9D24;
 int status;
 int success=1;
 int lastError=0;
 signed char reading=1,finished=0,ownsError=0;
 char name[32];DiscWaitFileInfo fileInfo;
 while(1){
  status=lbl_80378168=DVDGetDriveStatus();fn_801EBB9C();
  switch(status){
   case 4:case 5:case 6:case 11:
    while(lbl_8037816C&&!ownsError)OSYieldThread();
    lbl_8037816C=1;ownsError=1;fn_8028F4D8(self,(lastError=status),1);break;
   case -1:
    while(lbl_8037816C&&!ownsError)OSYieldThread();
    lbl_8037816C=1;ownsError=1;fn_8028F4D8(self,(lastError=status),0);success=0;break;
   case 0:if(reading)finished=1;break;
  }
  if(status!=1)reading=0;
  if(status!=0&&status!=-1)continue;
  reading=1;
  if(!finished){
   fn_801FA014(globals->logger,strings+0x17C);
   strcpy(name,strings+0x19C);
   if(DVDOpen(name,&fileInfo))DVDReadAsyncPrio(&fileInfo,lbl_80373100,16,0,0,2);
   else fn_801FA014(globals->logger,strings+0x1A8,name);
   continue;
  }
  break;
 }
 if(lbl_8037816E){
  fn_801FA014(globals->logger,strings+0x1B8);
  lbl_8037816E=0;
  DiscWaitGame*game=lbl_801E9D24.game;
  game->slot18();fn_801EBB9C();
  DiscWaitHandle empty;
  lbl_801E9D24.game->setPicture(empty);
  game->slot1C();
  fn_801FA014(globals->logger,strings+0x1E8);
  lbl_801E9D24.game->slot10();
  lbl_801E9D24.game->resize(640,448);
 }
 if(lastError&&lbl_80378164){
  int event=-1;
  switch(lastError){
   case 5:event=0;break;
   case 4:event=1;break;
   case 6:event=2;break;
   case 11:event=3;break;
   case -1:event=4;break;
  }
  if(lbl_80377F90&&lbl_80378164)lbl_80378164(event);
  lbl_8037816C=0;
 }
 lbl_8037816D=0;
 return success;
}

extern "C" const char lbl_802AFB08[];
extern "C" int fn_8028F29C(void*self){
 int status;
 int success=1;
 if(!lbl_80378174){lbl_80378170=0;lbl_80378174=1;}
 if(!lbl_80378176){lbl_80378175=0;lbl_80378176=1;}
 signed char repeat=1,hadError=0,ownsError=0;
 while(repeat){
  status=lbl_80378168=DVDGetDriveStatus();
  switch(status){
   case 4:case 5:case 6:case 11:
    while(lbl_8037816C&&!ownsError)OSYieldThread();
    lbl_80378170=status;lbl_8037816C=1;ownsError=1;fn_8028F4D8(self,status,1);lbl_80378175=1;break;
   case -1:
    while(lbl_8037816C&&!ownsError)OSYieldThread();
    lbl_80378170=status;lbl_8037816C=1;ownsError=1;fn_8028F4D8(self,status,0);lbl_80378175=1;success=0;break;
  }
  if(lbl_80378175){repeat=1;hadError=1;}else repeat=0;
  if(status==0&&lbl_80378175){
   lbl_80378175=0;
   int event=-1;
   switch(lbl_80378170){
    case 5:event=0;break;case 4:event=1;break;case 6:event=2;break;case 11:event=3;break;case -1:event=4;break;
   }
   if(lbl_80377F90&&lbl_80378164)lbl_80378164(event);
  }
 }
 if(hadError)fn_801FA014(lbl_801E9D24.logger,lbl_802AFB08);
 lbl_8037816C=0;
 return success;
}
