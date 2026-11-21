extern "C" {
extern char lbl_802ED400[];
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
void* __dt__14NestedPairPoolFv(void*, int);
void* fn_8024D160(void*, int);
}
struct Member98View {
    char unknown00[8];
    void* table;
    char unknown0C[0x8C];
    char member[1];
};

extern "C" Member98View* fn_8026F0B4(Member98View* self, int deleting)
{
    if (self) {
        self->table = lbl_802ED400;
        __dt__14NestedPairPoolFv(self->member, -1);
        fn_8024D160(self, 0);
        if ((short)deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
