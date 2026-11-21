#include "Game/word_array_owner_internal.h"
#include "Game/cache_record_array_destroy.h"

extern "C" {
extern char lbl_802ED458[];
}
struct WordOwnerView {
    char unknown00[8];
    void* table;
    char unknown0C[0x24];
    OwnedWordArray first, second;
};

extern "C" WordOwnerView* fn_8026FD10(WordOwnerView* self, int deleting)
{
    if (self) {
        self->table = lbl_802ED458;
        if (&self->second)
            self->second.clear();
        if (&self->first)
            self->first.clear();
        fn_801D87AC((CacheRecordDestroyOwner*)self, 0);
        if ((short)deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
