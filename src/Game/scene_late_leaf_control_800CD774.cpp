#include "Game/scene_late_leaf_controls.h"

extern "C" FactoryPyObject*fn_800CD774(SceneLateLeaf::Binding*self,const char*name){for(SceneLateLeaf::Property*p=self->properties;p;p=p->next){if(strcmp(p->name,name)==0)return p->get();}PyErr_SetString(PyExc_NameError,lbl_802A2AC8);return 0;}
