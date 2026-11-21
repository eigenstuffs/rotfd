// DamageVolume initialization and base update delegation.
struct DamagePrefix { unsigned long unknown[2]; };
struct DamageVolume : DamagePrefix {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void reset(int, int);
    char unknown0C[0x70 - 0x0C];
    unsigned char kind;
    char unknown71[3];
    float magnitude;
    unsigned char mode;
};
extern "C" {
void fn_80044380(DamageVolume*);
void fn_80044428(DamageVolume*);
void fn_800443B4(DamageVolume*);
float fn_8025E268(DamageVolume*, int);
extern const float lbl_80379640;
void fn_800C939C(DamageVolume* self) {
    fn_80044380(self);
    self->reset(0, 0);
}
void fn_800C93E4(DamageVolume* self) {
    fn_80044428(self);
}
}
