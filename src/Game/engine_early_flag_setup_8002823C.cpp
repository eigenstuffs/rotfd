extern "C" {
    void fn_8002AE88(void*);
}

struct View {
    char unknown00[0x38];
    unsigned long long field38;
};

extern "C" void fn_8002823C(View* self) {
    fn_8002AE88(self);
    self->field38 |= 0x0000000400000000ULL;
}
