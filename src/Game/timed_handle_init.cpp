struct TimedHandleBits {
    union {
        unsigned long value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct TimedHandleOwner {
    TimedHandleBits handle;
    unsigned long unknown04, unknown08;
    float first, second;
};
extern "C" {
void* __ct__15Handle_801F7F10Fv(void*);
void* __dt__15Handle_801F7F10Fv(void*, short);
void fn_801F7914(void*, const void*);
extern const float lbl_8037B5A0, lbl_8037B5A4;
}
extern "C" TimedHandleOwner* fn_802617F8(TimedHandleOwner* self)
{
    __ct__15Handle_801F7F10Fv(&self->handle);
    TimedHandleBits empty;
    empty.bits.index = 0;
    empty.bits.generation = 0;
    fn_801F7914(&self->handle, &empty);
    __dt__15Handle_801F7F10Fv(&empty, -1);
    self->unknown04 = 0;
    self->unknown08 = 0;
    self->first = lbl_8037B5A0;
    self->second = lbl_8037B5A4;
    return self;
}
