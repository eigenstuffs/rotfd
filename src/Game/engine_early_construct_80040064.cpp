/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-construct.md. */
extern "C" {
    void __ct__14Agent_8002B5F4Fv(void*);
    extern char lbl_802B3168[];
}

struct View {
    char unknown00[0x8];
    void* field08;
    char unknown0C[0x84];
    unsigned int field90;
    unsigned int field94;
    unsigned int field98;
    unsigned char field9C;
};

extern "C" View* fn_80040064(View* self) {
    __ct__14Agent_8002B5F4Fv(self);
    self->field08 = lbl_802B3168;
    self->field90 = 0;
    self->field94 = 0;
    self->field98 = 0;
    self->field9C = 0;
    self->field90 = 42;
    return self;
}
