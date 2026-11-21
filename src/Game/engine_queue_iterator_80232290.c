struct EngineIteratorHandle { unsigned int value; };
struct EngineIteratorState {
    void *active;
    float age, weight;
    char unknown0C[6];
    unsigned short flags;
    char unknown14[0x60];
};
struct EngineIteratorOwner {
    char unknown00[0x20];
    struct EngineIteratorState states[4];
    struct EngineIteratorHandle first, second;
};
typedef char EngineIteratorStateSize[(sizeof(struct EngineIteratorState) == 0x74) ? 1 : -1];

extern struct { char unknown00[0x118]; void *manager; } lbl_801E9D24;
extern void fn_801B353C(void *, int, int);
extern void fn_801F86C8(void *, const struct EngineIteratorHandle *, short);
extern void *fn_801F7EB8(struct EngineIteratorHandle *);
extern signed char fn_80232458(struct EngineIteratorOwner *);
extern void __ct__15Handle_801F7F10Fv(struct EngineIteratorHandle *);
extern void __dt__15Handle_801F7F10Fv(struct EngineIteratorHandle *, int);

static inline void engineIteratorAssign(struct EngineIteratorHandle *output,
                                         const struct EngineIteratorHandle *input) {
    fn_801F86C8(lbl_801E9D24.manager, output, -1);
    output->value = input->value;
    fn_801F86C8(lbl_801E9D24.manager, input, 1);
}

// The observed typed wrappers each clear the packed word after base construction.
static inline void engineIteratorInitializeTyped(struct EngineIteratorHandle *handle) {
    __ct__15Handle_801F7F10Fv(handle);
    handle->value = 0;
    handle->value = 0;
}

static inline void engineIteratorInitializeOwner(struct EngineIteratorHandle *handle) {
    engineIteratorInitializeTyped(handle);
    handle->value = 0;
}

void fn_80232290(void *self, int count) {
    fn_801B353C((char *)self + 0xC, count, 1);
}

void fn_802322B8(struct EngineIteratorOwner *self, float value) {
    int i;
    for (i = 0; i < 4; i++)
        self->states[i].age = value;
    for (i = 0; i < 4; i++) {
        self->states[i].flags &= ~6;
        self->states[i].flags |= 0x10;
    }
}

signed char fn_8023232C(struct EngineIteratorOwner *self,
                       const struct EngineIteratorHandle *source) {
    struct EngineIteratorHandle second, first;
    engineIteratorAssign(&self->second, source);
    if (fn_801F7EB8(&self->second) && fn_80232458(self))
        return 1;

    engineIteratorInitializeTyped(&second);
    engineIteratorAssign(&self->second, &second);
    __dt__15Handle_801F7F10Fv(&second, 0);
    engineIteratorInitializeOwner(&first);
    engineIteratorAssign(&self->first, &first);
    __dt__15Handle_801F7F10Fv(&first, 0);
    return 0;
}
