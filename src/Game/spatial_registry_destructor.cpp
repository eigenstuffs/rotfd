#include "Game/spatial_registry_destructor.h"

// Remove both registry bindings before destroying the owned arrays and bases.
extern "C" RegistryObject* fn_8024D160(RegistryObject* self, short deleting) {
    if (self) {
        self->table = lbl_802EC310;
        Word key = getKey(self->key);
        if (lbl_801E9D24.first) fn_801F5CA4(lbl_801E9D24.first, self, &key);
        if (lbl_801E9D24.second) fn_801F5CA4(lbl_801E9D24.second, self, &key);
        self->records.~RegistryArray<EmptyRecord>();
        self->handles.~RegistryArray<SpatialRegistryHandle3>();
        fn_8024D3AC(self->inner, -1);
        fn_80243E90(self, 0);
        if (deleting > 0) fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
