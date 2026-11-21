#include "Game/controller_poll_internal.h"
#include "Game/service_interface_tables.h"
#include "Game/platform_native_interface_tables.h"

extern "C" {
extern char lbl_801E9D24[], lbl_802AF120[];
extern char lbl_8028F698[], lbl_801EF5C8[];
void fn_801FA014(void*, const char*, ...);
int __PADDisableRecalibration(int);
void fn_8028FD50(void*, void*, unsigned long);
void fn_801EF610(void*, void*);
}
struct StatusInitView { char unknown00[0x70]; signed char enabled; char flags[8]; };

extern "C" signed char fn_80276754(StatusInitView* self) {
    self->enabled = 1;
    fn_801FA014(*(void**)(lbl_801E9D24 + 0x110), lbl_802AF120);
    for (int i = 0; i < 8; ++i) self->flags[i] = 0;
    __PADDisableRecalibration(0);
    return 1;
}

struct StorageArray {
    int count, capacity;
    PollRecord* data;
    void clear() {
        if (data) {
            for (int i = 0; i < count; ++i) data[i].~PollRecord();
            if (data) {
                fn_8028FD50(lbl_8028F698, data, capacity * sizeof(PollRecord));
                data = 0;
            }
            data = 0;
        }
    }
};
struct StorageView { StorageArray first, second; int unknown18; void* table; };
struct StorageVirtualBase { char unknown00[0x1C]; };
struct StorageVirtual : StorageVirtualBase {
    virtual void slot08();
    virtual void shutdown();
};

extern "C" StorageView* fn_802767D0(StorageView* self, int deleting) {
    if (self) {
        self->table = &lbl_802ED6F8;
        ((StorageVirtual*)self)->shutdown();
        if (self) {
            self->table = &lbl_802ED740;
            if (&self->second) self->second.clear();
            if (self) self->first.clear();
        }
        if ((short)deleting > 0) fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
