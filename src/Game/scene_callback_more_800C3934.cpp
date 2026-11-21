#include "Game/scene_callbacks_more.h"

extern "C" void fn_800C3934(SceneCallbacksMore::Owner*self,int value,const int*key,void*arg,int selection,const char*first,const char*second){self->value24=value;int copy=*key;const char*name=fn_800C1B0C(self->child,&copy);if(name){if(first){char text[1024];if(second)sprintf(text,lbl_8037957C,name,first,second);else sprintf(text,lbl_80379584,name,first);fn_800C2CB8(self,text,arg);}else fn_800C2CB8(self,name,arg);}else fn_800C2CB8(self,lbl_802A2364,arg);self->value30=selection;self->ready=1;}
