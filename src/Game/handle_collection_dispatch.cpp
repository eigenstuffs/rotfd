#include "Game/handle_member_dispatch_internal.h"

extern "C" signed char slot1C__12BaseObject_ZFv(void*);
struct CollectionView { char unknown00[12]; Array handles; };

extern "C" signed char fn_8026464C(CollectionView* self)
{
    if (!slot1C__12BaseObject_ZFv(self))
        return 0;
    for (int i = 0; i < self->handles.count; ++i) {
        if (fn_801F7EB8(&self->handles[i]))
            ((DispatchVirtual*)fn_801F7EB8(&self->handles[i]))->slot1C();
    }
    return 1;
}
