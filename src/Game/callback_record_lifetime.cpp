// Observed prefix of the native callback record; backing data remains external.
struct CallbackRecordPrefix {
    char unknown0[8];
    void* table;
    void* storage;
    int length;
};

extern "C" {
void __ct__12BaseObject_ZFv(void*);
void __dt__12BaseObject_ZFv(void*, int);
void fn_801EF610(void*, void*);
extern char lbl_801EF5C8[];
extern char lbl_802EC3B8[];
extern char __vt__17Resource_802E9E20[];
}

inline CallbackRecordPrefix* constructCallbackRecordResource(CallbackRecordPrefix* self) {
    __ct__12BaseObject_ZFv(self);
    self->table = __vt__17Resource_802E9E20;
    return self;
}

inline void destroyCallbackRecordResource(CallbackRecordPrefix* self) {
    if (self) {
        self->table = __vt__17Resource_802E9E20;
        __dt__12BaseObject_ZFv(self, 0);
    }
}

extern "C" CallbackRecordPrefix* fn_80253388(CallbackRecordPrefix* self, int flag) {
    if (self) {
        self->table = lbl_802EC3B8;
        if (self->storage) {
            fn_801EF610(lbl_801EF5C8, self->storage);
            self->length = 0;
        }
        destroyCallbackRecordResource(self);
        if ((short)flag > 0) {
            fn_801EF610(lbl_801EF5C8, self);
        }
    }
    return self;
}

extern "C" CallbackRecordPrefix* fn_80253428(CallbackRecordPrefix* self) {
    constructCallbackRecordResource(self);
    self->table = lbl_802EC3B8;
    self->storage = 0;
    self->length = 0;
    return self;
}
