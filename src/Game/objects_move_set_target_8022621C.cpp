/* ObjectsMove virtual slot 0x40 (fn_8022621C).
   Measures the distance from the current point to the new target with the
   engine square-root helper, then forwards the target and record index to
   the owner's virtual slot 0xBC (fn_8022675C). The distance is never used:
   the compiler drops the inline-asm square root and its branch but keeps the
   squared-length computation, the compare against zero, and the reservation
   of f4 by the helper (hence dx/dy land in f5/f6). */
extern "C" const float lbl_8037B11C;

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

struct MovePoint_8022621C {
    float x, y, z;
    float distance(const MovePoint_8022621C& o) const
    {
        float dz = z - o.z;
        float dy = y - o.y;
        float dx = x - o.x;
        float sq = dx * dx + dy * dy + dz * dz;
        float r = lbl_8037B11C;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

// Partial owner view: its virtual pointer follows eight bytes of base storage.
struct MoveStorage_8022621C { char unknown00[8]; };
struct MoveOwner_8022621C : MoveStorage_8022621C {
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
    virtual void setTarget(const MovePoint_8022621C* target, int index);
};

extern "C" void fn_8022621C(MoveOwner_8022621C* self, const MovePoint_8022621C* from,
                            const MovePoint_8022621C* to, void* unused, int index)
{
    float distance = to->distance(*from);
    self->setTarget(to, index);
}
