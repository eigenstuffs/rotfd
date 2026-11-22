// DamageVolume lifetime and configuration, including both consumers of its native 1.0f literal.
typedef unsigned long u32;
extern "C" {extern const char lbl_802C14FC[];extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Agent_80044118 {
 u32 unknown[2];const void*vtable;char unknown0C[0x70-12];
 Agent_80044118();~Agent_80044118();
 static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
struct Agent_800C92D4:Agent_80044118 {
 unsigned char kind;char unknown71[3];float magnitude;unsigned char mode,active;char unknown7A[6];
 Agent_800C92D4();~Agent_800C92D4();
};
typedef char DamageVolumeExtent[(sizeof(Agent_800C92D4)==0x80)?1:-1];
Agent_800C92D4::Agent_800C92D4(){vtable=lbl_802C14FC;magnitude=1.0f;active=0;}
Agent_800C92D4::~Agent_800C92D4(){vtable=lbl_802C14FC;}
// DamageVolume initialization, base update delegation, and numeric configuration.
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

void fn_800C939C(DamageVolume* self) {
    fn_80044380(self);
    self->reset(0, 0);
}
void fn_800C93E4(DamageVolume* self) {
    fn_80044428(self);
}
void fn_800C9404(DamageVolume* self) {
    fn_800443B4(self);
    self->kind = (unsigned char)fn_8025E268(self, 2);
    if (self->kind > 5 || self->kind < 1) self->kind = 1;
    self->magnitude = fn_8025E268(self, 3);
    if (self->magnitude < 1.0f) self->magnitude = 1.0f;
    self->mode = (unsigned char)fn_8025E268(self, 4);
}
}

/* Former original data .sdata2 0x80379644..0x80379650, appended to the unit it follows (its section starts 8-aligned only together with this one). */
#pragma explicit_zero_data on
#pragma force_active on
extern "C" __declspec(section ".sdata2") const float lbl_80379644 = -1612.0f;
extern "C" __declspec(section ".sdata2") const char lbl_80379648[] = "Agent_Z";

#pragma force_active reset
