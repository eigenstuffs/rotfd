extern "C" {
    unsigned long fn_801F948C(void*, const char*);
    extern const char lbl_803794F8[8];
}
struct Name {
    unsigned long value;
    Name(const char* text) { value = fn_801F948C(this, text); }
};
struct View {
    unsigned long value;
    unsigned char field04;
};
extern "C" View* fn_800C19B8(View* self) {
    self->value = 0;
    self->value = Name(lbl_803794F8).value;
    self->field04 = 0;
    return self;
}
