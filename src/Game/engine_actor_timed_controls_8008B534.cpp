/* Original actor timed callback controls; see docs/notes/game-engine-actor-timed-controls.md. */
struct Actor {
    char opaque00[0x30];
    unsigned long long flags30;
    char opaque38[0x318 - 0x38];
    char component318[0x406 - 0x318];
    signed char enabled406;
    char opaque407[5];
    signed char enabled40C;
};
struct Owner {
    char opaque00[8];
    Actor* actor08;
    void* control0C;
    char opaque10[0x30];
    int state40, phase44;
    unsigned char input48;
    signed char armed49;
    char opaque4A[2];
    float elapsed4C, timestamp50, duration54;
};
extern "C" {
    signed char fn_8007D604(void*, int);
    signed char fn_8007D6A0(void*, int);
    int fn_80092844(Actor*);
    void fn_800B7214(void*, int, unsigned char*, int);
    extern const float lbl_80378AD0, lbl_80378ADC, lbl_80378B10, lbl_80378B60;
    extern struct Global { char opaque00[0x164]; void* service164; } lbl_801E9D24;
}
extern "C" void fn_8008B534(Owner* self, float delta) {
    self->elapsed4C += delta;
    if (fn_8007D604(self->actor08->component318, 0x28) ||
        fn_8007D604(self->actor08->component318, 0x29) ||
        fn_8007D604(self->actor08->component318, 0x18) ||
        fn_8007D604(self->actor08->component318, 0x19) ||
        fn_8007D604(self->actor08->component318, 0x1A) ||
        fn_8007D604(self->actor08->component318, 0x1C) ||
        fn_8007D604(self->actor08->component318, 0x31) ||
        fn_8007D604(self->actor08->component318, 0x32) ||
        fn_8007D604(self->actor08->component318, 0x33) ||
        fn_8007D604(self->actor08->component318, 6)) return;
    fn_800B7214(lbl_801E9D24.service164, 3, &self->input48, 0);
    if (self->input48 && self->actor08->enabled406 &&
        (fn_8007D604(self->actor08->component318, 9) ||
         fn_8007D604(self->actor08->component318, 10) ||
         fn_8007D604(self->actor08->component318, 0x13) ||
         fn_8007D604(self->actor08->component318, 0xC))) {
        fn_8007D6A0(self->actor08->component318, 0x26);
        return;
    }
    if (self->input48 && fn_8007D604(self->actor08->component318, 0xD)) {
        fn_8007D6A0(self->actor08->component318, 0x27);
        return;
    }
    if (fn_8007D604(self->actor08->component318, 0x26)) return;
    if (fn_8007D604(self->actor08->component318, 0x27)) return;
    if (!self->input48 && self->armed49) self->armed49 = 0;
    if (self->input48 && !self->armed49 && self->state40 < 3) {
        if (self->state40 == 0) self->timestamp50 = self->elapsed4C;
        ++self->state40;
        self->armed49 = 1;
        if (self->state40 == 1) {
            fn_8007D6A0(self->actor08->component318, 0xE);
            self->phase44 = 1;
        }
    }
    if (self->timestamp50 > lbl_80378AD0) {
        self->duration54 = self->elapsed4C - self->timestamp50;
        if ((self->duration54 > lbl_80378ADC && self->state40 == 1) ||
            (self->duration54 > lbl_80378B10 && self->state40 == 2) ||
            self->duration54 > lbl_80378B60 || self->actor08->enabled40C) {
            self->state40 = 0;
            self->phase44 = 0;
            self->timestamp50 = lbl_80378AD0;
            self->duration54 = lbl_80378AD0;
            self->armed49 = 0;
            self->actor08->flags30 &= ~0x80000000ULL;
            fn_8007D6A0(self->actor08->component318, fn_80092844(self->actor08));
        }
    }
}
