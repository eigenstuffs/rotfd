struct BufferRecordHandle {
    unsigned int value;
};
struct BufferRecordState {
    void* active;
    char unknown04[0xE];
    unsigned short flags;
    char unknown14[0x60];
};
struct BufferRecordOwner {
    unsigned int unknown00, unknown04;
    void* vptr;
    char unknown0C[0x14];
    struct BufferRecordState states[4];
    struct BufferRecordHandle first, second, target0, target1;
};
typedef char BufferRecordStateSize[sizeof(struct BufferRecordState) == 0x74 ? 1 : -1];

extern void __ct__13Manipulator_ZFv(void*);
extern char lbl_802EBDE0[];
extern void fn_802358AC(void*);
extern void fn_80231ABC(void*);
extern void __construct_array(void*, void (*)(void*), void (*)(void*), int, int);
extern void __ct__15Handle_801F7F10Fv(struct BufferRecordHandle*);

// Each observed typed constructor layer clears the packed handle word.
static inline void initializeHandle1(struct BufferRecordHandle* handle)
{
    __ct__15Handle_801F7F10Fv(handle);
    handle->value = 0;
}
static inline void initializeHandle2(struct BufferRecordHandle* handle)
{
    initializeHandle1(handle);
    handle->value = 0;
}
static inline void initializeHandle3(struct BufferRecordHandle* handle)
{
    initializeHandle2(handle);
    handle->value = 0;
}

struct BufferRecordOwner* fn_8023576C(struct BufferRecordOwner* self)
{
    int i;
    __ct__13Manipulator_ZFv(self);
    self->vptr = lbl_802EBDE0;
    __construct_array(self->states, fn_802358AC, fn_80231ABC, 0x74, 4);
    {
        struct BufferRecordHandle* handle = &self->first;
        initializeHandle3(handle);
    }
    {
        struct BufferRecordHandle* handle = &self->second;
        initializeHandle2(handle);
    }
    {
        struct BufferRecordHandle* handle = &self->target0;
        initializeHandle3(handle);
    }
    {
        struct BufferRecordHandle* handle = &self->target1;
        initializeHandle1(handle);
    }
    for (i = 0; i < 4; i++) {
        self->states[i].active = 0;
        self->states[i].flags = i ? 0x400 : 0;
    }
    return self;
}
