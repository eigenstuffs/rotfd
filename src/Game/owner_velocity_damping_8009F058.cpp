/* Velocity integration step of a resource-action agent (same class and
   field views as owner_acceleration_update_8009f9a4.cpp).  Unless the
   resource resolved from virtual getHandle(0) carries flag 0x10000, the
   velocity is refreshed through virtual updateVelocity(delta) when the blend
   at 0x350 is nonzero; then, unless fn_8021F23C holds the agent, the
   acceleration at 0x358 is added to the velocity at 0x144 and the horizontal
   X/Z components are damped by 0.9 (lbl_80378E2C).

   lbl_80378E2C is referenced only by this function (the original used a
   pooled 0.9f literal).  The literal is loaded once, at its first use, after
   the acceleration loads, which fixes the FPR order (constant in f0).  A
   plain double use of the extern is merged by front-end CSE into an earlier
   temporary and reorders the registers; reading the second use through a
   pointer keeps the extern label and reproduces the literal's code. */

typedef unsigned long Word;

struct Handle { union { Word value; struct { signed int tag : 8, index : 24; } bits; }; };
struct Resource { char unknown00[0x58]; Handle owner; char unknown5C[0xC4]; unsigned int flags; };
struct Entry { Resource* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct Manager { int count, capacity; Entry* entries; };
extern "C" struct Global { char unknown00[0x118]; Manager* manager; } lbl_801E9D24;

inline Resource* resolve(const Handle& h)
{
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    if (e->tag == h.bits.tag) return e->object;
    return 0;
}

struct Prefix { char unknown00[8]; };
struct Agent : Prefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual const Handle* getHandle(int);   /* vtable +0x9C */
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void slot77();
    virtual void slot78();
    virtual void slot79();
    virtual void slot80();
    virtual void slot81();
    virtual void slot82();
    virtual void slot83();
    virtual void slot84();
    virtual void slot85();
    virtual void slot86();
    virtual void slot87();
    virtual void slot88();
    virtual void slot89();
    virtual void slot90();
    virtual void slot91();
    virtual void slot92();
    virtual void slot93();
    virtual void slot94();
    virtual void slot95();
    virtual void slot96();
    virtual void slot97();
    virtual void slot98();
    virtual void slot99();
    virtual void slot100();
    virtual void slot101();
    virtual void slot102();
    virtual void updateVelocity(float);     /* vtable +0x1A4 */
    char unknown0C[0x144 - 0xC];
    float velocityX, velocityY, velocityZ;  /* 0x144 */
    char unknown150[0x350 - 0x150];
    float blend;                            /* 0x350 */
    float magnitude;                        /* 0x354 */
    float accelX, accelY, accelZ;           /* 0x358 */
};

extern "C" {
signed char fn_8021F23C(Agent*);
extern const float lbl_80378DD8; /* 0.0f, shared */
extern const float lbl_80378E2C; /* 0.9f */
}

extern "C" void slot198__11CScriptMoveFf(Agent* self, float delta)
{
    if (!(resolve(*self->getHandle(0))->flags & 0x10000)) {
        if (lbl_80378DD8 != self->blend) self->updateVelocity(delta);
        if (!fn_8021F23C(self)) {
            float x = self->velocityX;
            float y = self->velocityY;
            float z = self->velocityZ;
            x += self->accelX;
            y += self->accelY;
            z += self->accelZ;
            x *= lbl_80378E2C;
            z *= *(const float*)&lbl_80378E2C;
            self->velocityX = x;
            self->velocityY = y;
            self->velocityZ = z;
        }
    }
}
