#include "Game/scene_late_leaf_controls.h"

extern "C" void fn_800C4510(SceneLateLeaf::SmallOwner*self,SceneLateLeaf::Source*source){SceneLateLeaf::Large*target=source->target;if(fn_801F7EB8(&self->selected)&&!self->busy)target->slot25(&self->selected);}
