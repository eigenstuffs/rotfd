extern "C" {
extern char lbl_801EF5C8[];
extern char lbl_802EDCA8[];
void fn_801EF610(void*, void*);
void* fn_801C9C00(void*, int);
}

struct TableBaseView {
    int unknown00, unknown04;
    void* table;
};

extern "C" TableBaseView* fn_8027937C(TableBaseView* self, int deleting)
{
    if (self) {
        self->table = lbl_802EDCA8;
        fn_801C9C00(self, 0);
        if ((short)deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
