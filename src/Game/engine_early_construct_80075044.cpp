/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-construct.md. */
extern "C" {
    void fn_80090084(void*);
    extern char lbl_802B8184[];
    extern char lbl_802B819C[];
}

struct View {
    void* field00;
    char unknown04[0x4];
    unsigned int field08;
};

extern "C" View* fn_80075044(View* self, unsigned int value1) {
    fn_80090084(self);
    self->field00 = lbl_802B819C;
    self->field08 = 0;
    self->field08 = value1;
    self->field00 = lbl_802B8184;
    return self;
}
