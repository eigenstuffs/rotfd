#include "Game/platform_owner_completion.h"

extern "C" void fn_8028DD18(CompletionOwner*self){CompletionObject*owner=resolve(self->owner);if(owner->flags&8){{CompletionZero3 zero;fn_8023D66C(owner,lbl_801E9D24.resource->propagationHandle,zero);}owner->flags&=~8;int count=self->count;for(int i=0;i<count;++i){CompletionObject*item=resolve(self->items[i]);CompletionObject*type=resolve(item->classHandle);if(type&&type->type==5)fn_801CBC64(resolve(item->related),item);}}}
