#include "Game/early_resource_token_loop_views.h"
extern "C" void fn_800B026C(const char*name){
 for(int i=0;i<400;++i){lbl_802F9FC8[i].text[0]=0;lbl_802F9FC8[i].flags=0;}
 Handle_8001FF04 h(lbl_801E9D24.manager->load(name));
 if(!fn_801F7EB8(&h))return;
 ResourceTokenReader*r=&resolveResourceToken(h)->reader;
 char token[256];int i=0;fn_801F3168(r,token,0);
 while(!fn_801F2E04(r)){
  if(strncmp(token,lbl_80379188,2)){
   if(!strcmp(token,lbl_803791E0)){lbl_802F9FC8[i++].flags|=1;}
   else if(!strcmp(token,lbl_803791E8)){strcpy(lbl_802F9FC8[i++].text,lbl_803791C8);}
   else{ResourceTokenRecord*record=&lbl_802F9FC8[i++];strncpy(record->text,token,128);record->text[127]=0;}
  }
  fn_801F3168(r,token,0);
 }
}
