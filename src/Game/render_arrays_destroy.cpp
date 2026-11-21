extern "C" {
extern char lbl_802ED624[];
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
void* fn_801E1870(void*, int);
void fn_801EB634(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
}

struct RenderArrayView {
    char unknown00[0x278];
    void* table;
    char unknown27C[0x138];
    char small[36], large[1536];
    void* last;
};
struct RenderArrayVirtualBase { char unknown00[0x278]; };
struct RenderArrayVirtual : RenderArrayVirtualBase {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
};

extern "C" RenderArrayView* fn_80275990(RenderArrayView* self, int deleting)
{
    if (self) {
        self->table = lbl_802ED624;
        ((RenderArrayVirtual*)self)->slot10();
        self->last = 0;
        __destroy_arr(self->large, fn_801EB634, 12, 128);
        __destroy_arr(self->small, fn_801EB634, 12, 3);
        fn_801E1870(self, 0);
        if ((short)deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
