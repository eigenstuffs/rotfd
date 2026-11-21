#include "Game/owner_target_action_views.h"
extern "C" int fn_8009FC1C(TargetActionAgent*self){if(!fn_8009FD38(self))return 0;const TargetActionHandle*result=fn_80268080(resolveGenericTargetAction(lbl_801E9D24.collection->items[0]),&resolveTargetAction(self->owner)->owner);int flag=resolveTargetAction(*result)->flagsBC&1;self->lookupFlag=flag;return flag;}
