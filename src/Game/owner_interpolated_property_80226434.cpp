// Partial owner view: its virtual pointer follows eight bytes of base storage.
struct InterpolatedPropertyStorage_80226434 { char unknown00[8]; };
struct InterpolatedPropertyRecord_80226434;
struct InterpolatedPropertyOwner_80226434 : InterpolatedPropertyStorage_80226434 {
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
    virtual void slot8C();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
    virtual void slotA0();
    virtual void slotA4();
    virtual void slotA8();
    virtual void slotAC();
    virtual void slotB0();
    virtual void slotB4();
    virtual void slotB8();
    virtual void slotBC();
    virtual void slotC0();
    virtual void slotC4();
    virtual void slotC8();
    virtual void slotCC();
    virtual void slotD0();
    virtual void slotD4();
    virtual void slotD8();
    virtual void slotDC();
    virtual void clearFlags(unsigned long long mask, int index);

    char unknown0C[0x17C];
    InterpolatedPropertyRecord_80226434* records;
};

struct InterpolatedPropertyPoint_80226434 {
    float x, y, z;
    InterpolatedPropertyPoint_80226434(float a, float b, float c) : x(a), y(b), z(c) {}
    InterpolatedPropertyPoint_80226434 operator*(float t) const {
        return InterpolatedPropertyPoint_80226434(x * t, y * t, z * t);
    }
    InterpolatedPropertyPoint_80226434 operator+(const InterpolatedPropertyPoint_80226434& other) const {
        return InterpolatedPropertyPoint_80226434(x + other.x, y + other.y, z + other.z);
    }
};

struct InterpolatedPropertyRecord_80226434 {
    InterpolatedPropertyPoint_80226434 position;
    char unknown0C[0x9C];
};

extern "C" void fn_80226434(InterpolatedPropertyOwner_80226434* self,
                              const InterpolatedPropertyPoint_80226434* position,
                              InterpolatedPropertyPoint_80226434* out,
                              InterpolatedPropertyPoint_80226434* copy,
                              int index, float t) {
    self->clearFlags(0xFFFFFFC0000001C0ULL, index);
    const InterpolatedPropertyRecord_80226434& record = self->records[index];
    *out = *position + record.position * t;
    copy->x = out->x;
    copy->y = out->y;
    copy->z = out->z;
}
