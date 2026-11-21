#include "Game/platform_audio_internal.h"
extern "C" {
void fn_802077B4(const char*,char*,char*,char*,char*);
char*strcat(char*,const char*);
void fn_801F459C(char*);
signed char fn_8028A6DC(void*,const char*);
int fn_80289968(void*,const char*);
void fn_80286CD8(PlatformAudioOwner*self,const char*name){
 char path[128];char extension[16];
 fn_802077B4(name,0,0,path,extension);strcat(path,extension);fn_801F459C(path);fn_8028A6DC(self->secondary,path);
}
void fn_80286D38(PlatformAudioOwner*self,const char*name){
 char path[128];char extension[16];
 fn_802077B4(name,0,0,path,extension);strcat(path,extension);fn_801F459C(path);if(fn_80289968(self->secondary,path))return;
}
}
