struct PushHandle { unsigned long value; };
struct PushHandleArray { int count, capacity; PushHandle* data; };
extern "C" {
extern char lbl_8028F698[];
extern struct { char unknown00[0x118]; void* manager; } lbl_801E9D24;
void* fn_8028FAF4(void*, void*, unsigned long, unsigned long);
void* fn_8028FF24(void*, unsigned long);
void fn_8028FD50(void*, void*, unsigned long);
void* __ct__15Handle_801F7F10Fv(void*);
void fn_801F86C8(void*, const void*, int);
}
extern "C" void fn_80263650(PushHandleArray* self, const PushHandle* value)
{
    if (self->count + 1 > self->capacity) {
        int capacity = self->capacity + 32;
        if (capacity != 0) {
            if (self->data)
                self->data = (PushHandle*)fn_8028FAF4(lbl_8028F698, self->data,
                    self->capacity * sizeof(PushHandle), capacity * sizeof(PushHandle));
            else
                self->data = (PushHandle*)fn_8028FF24(lbl_8028F698, capacity * sizeof(PushHandle));
        } else if (self->data) {
            fn_8028FD50(lbl_8028F698, self->data, self->capacity * sizeof(PushHandle));
            self->data = 0;
        }
        self->capacity += 32;
    }
    PushHandle* slot = &self->data[self->count++];
    if (slot) {
        __ct__15Handle_801F7F10Fv(slot);
        slot->value = 0;
        slot->value = value->value;
        fn_801F86C8(lbl_801E9D24.manager, value, 1);
    }
}
