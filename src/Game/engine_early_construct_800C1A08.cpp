/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-construct.md. */
extern "C" {
    void __ct__12BaseObject_ZFv(void*);
    extern char lbl_802BF5F4[];
}

struct View {
    char unknown00[0x8];
    void* field08;
    unsigned int field0C;
    unsigned int field10;
    unsigned char field14;
};

extern "C" View* fn_800C1A08(View* self) {
    __ct__12BaseObject_ZFv(self);
    self->field08 = lbl_802BF5F4;
    self->field0C = 0;
    self->field10 = 0;
    self->field14 = 0;
    return self;
}
