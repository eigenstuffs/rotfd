#include "Game/platform_audio_update_internal.h"
extern "C" float fn_800A8E8C(float,float,float);
extern "C" void fn_802897BC(void*,float);
extern "C" void fn_80289730(void*,float);
inline float attenuation(float level){if(level>lbl_8037B89C)return lbl_8037B898;else if(level<=lbl_8037B898)return lbl_8037B8A4;else return lbl_8037B8AC*fn_80284DB4(level);}
extern "C" void fn_80287454(PlatformAudioUpdateOwner*self,float level){self->field414=level;fn_800A8E8C(self->field414,lbl_8037B898,lbl_8037B89C);fn_802897BC(self->secondary,attenuation(self->field414));}
extern "C" void fn_802874D4(PlatformAudioUpdateOwner*self,float level){self->field418=level;fn_800A8E8C(self->field418,lbl_8037B898,lbl_8037B89C);fn_80289730(self->secondary,attenuation(self->field418));}
