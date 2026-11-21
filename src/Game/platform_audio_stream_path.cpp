#include "Game/platform_audio_update_internal.h"
extern "C" {
extern const char lbl_8037B8C8[5];
void fn_801F2A4C(const char*,char*);char*strcat(char*,const char*);
void fn_8028A88C(void*,const char*,int);
void fn_8028701C(PlatformAudioUpdateOwner*self,const char*name,int mode){if(name){char path[128];fn_801F2A4C(name,path);strcat(path,lbl_8037B8C8);fn_8028A88C(self->secondary,path,mode);}}
}
