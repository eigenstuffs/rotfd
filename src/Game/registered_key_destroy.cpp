extern "C" {
extern char lbl_802ED2A0[];
extern char lbl_801EF5C8[];
extern char lbl_801E9D24[];
void fn_801EF610(void*, void*);
void* __dt__19CallbackRecordOwnerFv(void*, int);
void fn_8026E940(void*, const int*);
}
struct RegisteredKeyView {
    char unknown00[8];
    void* table;
    char unknown0C[0x28];
    int key;
};

extern "C" RegisteredKeyView* fn_8026E834(RegisteredKeyView* self, int deleting)
{
    if (self) {
        self->table = lbl_802ED2A0;
        void* registry = *(void**)(lbl_801E9D24 + 0x180);
        if (registry && self->key != -1) {
            int key = self->key;
            fn_8026E940(registry, &key);
        }
        self->key = -1;
        __dt__19CallbackRecordOwnerFv(self, 0);
        if ((short)deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
