#include "Game/engine_owner_lists_destructor.h"

typedef char OwnerListsHandleSize[(sizeof(OwnerListsHandle4) == 4) ? 1 : -1];
typedef char OwnerListsArraySize[(sizeof(OwnerListsArray<OwnerListsElement<4> >) == 12) ? 1 : -1];
typedef char OwnerListsObjectSize[(sizeof(OwnerListsObject) == 0x1E8) ? 1 : -1];

extern "C" OwnerListsObject* fn_8022D2B0(OwnerListsObject* self, short deleting) {
    if (self) {
        self->table = __vt__12ObjectsBreak;
        self->fifth.~OwnerListsArray<OwnerListsElement<4> >();
        self->fourth.~OwnerListsArray<OwnerListsElement<16> >();
        self->third.~OwnerListsArray<OwnerListsElement<4> >();
        self->second.~OwnerListsArray<OwnerListsElement<4> >();
        self->first.~OwnerListsArray<OwnerListsElement<4> >();
        self->handle.~OwnerListsHandle4();
        if (self) {
            self->table = __vt__13ObjectsBounce;
            __dt__11ObjectsMoveFv(self, 0);
        }
        if (deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
