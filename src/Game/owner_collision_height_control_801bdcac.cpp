#include "Game/owner_collision_height_control_801bdcac.h"

typedef unsigned int CollisionHeightWord;
typedef unsigned long long CollisionHeightFlags;

struct CollisionHeightPoint_801BDCAC {
    float x, y, z;
    CollisionHeightPoint_801BDCAC() {}
    CollisionHeightPoint_801BDCAC(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct CollisionHeightRay_801BDCAC {
    CollisionHeightPoint_801BDCAC origin;
    float length;
    CollisionHeightPoint_801BDCAC direction;
    float unknown1C;
    CollisionHeightRay_801BDCAC(const CollisionHeightPoint_801BDCAC& o,
                              const CollisionHeightPoint_801BDCAC& d, float l)
        : origin(o), direction(d) { length = l; }
};

struct CollisionHeightResult_801BDCAC {
    CollisionHeightPoint_801BDCAC point;
    char unknown0C[0x28 - 12];
    CollisionHeightFlags flags;
    CollisionHeightWord object, other, extra;
    signed char hit;
    char unknown3D[3];
    CollisionHeightWord end;
    CollisionHeightResult_801BDCAC() {
        hit = 0;
        object = 0;
        other = 0;
        extra = 0;
        flags = 0;
    }
};

// Partial virtual view: the original vptr follows eight bytes of base storage.
struct CollisionHeightStorage_801BDCAC { CollisionHeightWord unknown00, unknown04; };
struct CollisionHeightOwner_801BDCAC : CollisionHeightStorage_801BDCAC {
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
    virtual void contact(CollisionHeightResult_801BDCAC*,CollisionHeightPoint_801BDCAC*,int);
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual float radius();
    virtual float height(int);
    virtual void setHeight(float,int);
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
    virtual void clearFlags(CollisionHeightFlags,int);
    virtual signed char hasFlags(CollisionHeightFlags,int);

};

extern "C" {
signed char fn_80269230(void*, const CollisionHeightRay_801BDCAC&,
                       CollisionHeightResult_801BDCAC*, CollisionHeightFlags,
                       CollisionHeightFlags);
extern const float lbl_8037A2F0, lbl_8037A2F8, lbl_8037A2FC;
double __fabs(double);
}

extern "C" void fn_801BDCAC(CollisionHeightOwner_801BDCAC* self, void* world,
                            CollisionHeightPoint_801BDCAC* position, int index)
{
    CollisionHeightPoint_801BDCAC origin = *position;
    float radius = self->radius();
    CollisionHeightResult_801BDCAC result;
    origin.y += radius;
    if (fn_80269230(world,
                   CollisionHeightRay_801BDCAC(origin,
                       CollisionHeightPoint_801BDCAC(lbl_8037A2F8, lbl_8037A2FC,
                                                    lbl_8037A2F8), radius),
                   &result, 8, 0)) {
        self->contact(&result, position, index);
    } else if (self->hasFlags(0x2000000000000ULL, index)) {
        float distance = self->height(index);
        origin.y = radius + distance;
        distance = (float)__fabs(origin.y - position->y);
        if (distance > lbl_8037A2F0) {
            if (fn_80269230(world,
                           CollisionHeightRay_801BDCAC(origin,
                               CollisionHeightPoint_801BDCAC(lbl_8037A2F8,
                                   lbl_8037A2FC, lbl_8037A2F8), distance),
                           &result, 8, 0)) {
                self->setHeight(result.point.y - position->y, index);
            } else {
                self->clearFlags(0x2000000000000ULL, index);
                self->setHeight(lbl_8037A2F8, index);
            }
        }
    }
}
