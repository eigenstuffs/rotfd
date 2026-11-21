#include "Game/early_resource_token_loop_views.h"
extern "C" int fn_800A4F2C(void*self,const char*name){
 Handle_8001FF04 h(lbl_801E9D24.manager->load(name));
 if(!fn_801F7EB8(&h))return 0;
 ResourceTokenReader*r=&resolveResourceToken(h)->reader;
 char token[128];fn_801F372C(r,token);
 while(!fn_801F2E04(r)){if(!strcmp(token,lbl_80378EA8))fn_800A5080(self,r);fn_801F372C(r,token);}
 fn_800A6504(self,6);return 1;
}
