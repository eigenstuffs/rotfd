#include "Game/scene_callbacks_more.h"

extern "C" int fn_800CD6DC(SceneCallbacksMore::Binding*self,void*stream){fprintf(stream,lbl_802A2AB4);for(SceneCallbacksMore::Property*p=self->properties;p;p=p->next){fprintf(stream,lbl_803796F0,p->name);if(p->next)fprintf(stream,lbl_803796F4);}fprintf(stream,lbl_803796F8);return 0;}
