struct BufferRecordBitmapStorage {unsigned int a,b;};
struct BufferRecordBitmap:BufferRecordBitmapStorage {virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    void* indices;void*colors;void*levels[6];int resource,width,height,unknown38;unsigned char type,unknown3D,format,unknown3F,count,flags;char unknown42[2];void*extra;};
struct BufferRecordDeviceStorage {char pad[0x278];};
struct BufferRecordDevice:BufferRecordDeviceStorage {virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3C();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4C();
    virtual void s50();
    virtual void s54();
    virtual void s58();
    virtual void s5C();
    virtual void s60();
    virtual void s64();
    virtual void s68();
    virtual void s6C();
    virtual void s70();
    virtual void s74();
    virtual void s78();
    virtual void s7C();
    virtual void s80();
    virtual void s84();
    virtual void s88();
    virtual void s8C();
    virtual void s90();
    virtual void s94();
    virtual void s98();
    virtual void s9C();
    virtual void sA0();
    virtual void sA4();
    virtual void sA8(int);};
extern "C" {extern char __vt__15Bitmap_802EBEE0[],__vt__17Resource_802E9E20[],lbl_801EF5C8[];extern struct {char pad[0x114];BufferRecordDevice*device;}lbl_801E9D24;void fn_801EF610(void*,void*);void __dt__12BaseObject_ZFv(void*,int);}
static inline void releaseLevels(BufferRecordBitmap* self)
{
    for (int i = 0; i < self->count; i++) {
        if (self->levels[i])
            fn_801EF610(lbl_801EF5C8, self->levels[i]);
    }
}

extern "C" void fn_80238D28(BufferRecordBitmap* self)
{
    int i;
    self->flags = 0;
    self->flags &= ~3;
    self->flags |= 4;
    self->indices = 0;
    self->colors = 0;
    self->width = 0;
    self->height = 0;
    self->unknown3D = 0;
    self->resource = -1;
    self->unknown3F = 0;
    for (i = 0; i < 6; i++)
        self->levels[i] = 0;
    self->count = 0;
    self->unknown38 = 0;
    self->extra = 0;
    self->format = 3;
}

extern "C" BufferRecordBitmap* fn_80238D98(BufferRecordBitmap* self, short deleting)
{
    if (self) {
        *(void**)((char*)self + 8) = __vt__15Bitmap_802EBEE0;
        if (lbl_801E9D24.device && self->resource != -1)
            lbl_801E9D24.device->sA8(self->resource);
        if (self->indices)
            fn_801EF610(lbl_801EF5C8, self->indices);
        if (self->colors)
            fn_801EF610(lbl_801EF5C8, self->colors);
        releaseLevels(self);
        self->s18();
        if (self->extra)
            fn_801EF610(lbl_801EF5C8, self->extra);
        if (self) {
            *(void**)((char*)self + 8) = __vt__17Resource_802E9E20;
            __dt__12BaseObject_ZFv(self, 0);
        }
        if (deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
