#include "Game/scene_late_leaf_controls.h"

extern "C" int fn_800CD7E8(SceneLateLeaf::Binding*self,const char*name,FactoryPyObject*value){for(SceneLateLeaf::Property*p=self->properties;p;p=p->next){if(strcmp(p->name,name)==0)return p->set(value);}PyErr_SetString(PyExc_NameError,lbl_802A2AC8);return 1;}
