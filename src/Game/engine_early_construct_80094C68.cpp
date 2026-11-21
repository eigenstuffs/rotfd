/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-construct.md. */
extern "C" {
    void fn_80090084(void*);
    extern char lbl_802B9678[];
    extern char lbl_802B96F4[];
}

struct View {
    void* field00;
    char unknown04[0x4];
    unsigned int field08;
    unsigned int field0C;
};

extern "C" View* fn_80094C68(View* self, unsigned int value1, unsigned int value2) {
    fn_80090084(self);
    self->field00 = lbl_802B96F4;
    self->field08 = value1;
    self->field0C = value2;
    self->field00 = lbl_802B9678;
    return self;
}
