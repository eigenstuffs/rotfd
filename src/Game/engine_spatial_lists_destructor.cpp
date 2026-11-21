#include "Game/engine_spatial_lists_destructor.h"

typedef char SpatialListsRecordSize[(sizeof(SpatialListsRecord) == 24) ? 1 : -1];
typedef char SpatialListsNumbersSize[(sizeof(SpatialListsNumbers) == 12) ? 1 : -1];
typedef char SpatialListsObjectSize[(sizeof(SpatialListsObject) == 0x7C) ? 1 : -1];

extern "C" SpatialListsObject* fn_8024C8CC(SpatialListsObject* self, short deleting) {
    if (self) {
        self->table = __vt__23SpatialBinding_802EC2C0;
        if (lbl_801E9D24.manager && self->index >= 0)
            fn_801AD8D4(lbl_801E9D24.manager, self->index);
        self->array70.~SpatialListsArray<SpatialListsNumbers>();
        self->array64.~SpatialListsArray<SpatialListsHandle3>();
        self->array58.~SpatialListsArray<SpatialListsRecord>();
        self->array4C.~SpatialListsArray<SpatialListsRecord>();
        self->array40.~SpatialListsArray<SpatialListsRecord>();
        self->array30.~SpatialListsArray<SpatialListsHandle2>();
        self->handle.~SpatialListsHandle2();
        self->array20.~SpatialListsArray<SpatialListsHandle2>();
        if (self) {
            self->table = __vt__20SpatialBase_802EC118;
            if (self) {
                self->table = __vt__17Resource_802E9E20;
                __dt__12BaseObject_ZFv(self, 0);
            }
        }
        if (deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
