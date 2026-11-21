/* Observed resource initializer; tables and scalar constants keep their
 * existing owners. The named flag value preserves the native update order. */
typedef unsigned short u16;
typedef unsigned long u32;
struct Record_8024E18C {
    char gap00[8];
    void* table;
    char gap0C[0x60];
    u16 kind;
    u16 flags;
    char gap70[4];
    u32 handles[6];
    char gap8C[0x10];
    float value;
};
extern "C" void fn_80243F28(Record_8024E18C*);
extern "C" char lbl_802EA558[0x58];
extern "C" const float lbl_8037B44C;
extern "C" Record_8024E18C* fn_8024E18C(Record_8024E18C* self) {
    fn_80243F28(self);
    self->table = lbl_802EA558;
    float initialValue = lbl_8037B44C;
    self->handles[0] = 0;
    self->handles[1] = 0;
    self->handles[2] = 0;
    self->handles[3] = 0;
    self->handles[4] = 0;
    self->handles[5] = 0;
    self->kind = 2;
    unsigned short enabledFlags = self->flags;
    enabledFlags |= 0x20;
    self->flags = enabledFlags;
    self->value = initialValue;
    return self;
}
typedef char CheckRecord_8024E18CSize[sizeof(Record_8024E18C)==0xA0?1:-1];
