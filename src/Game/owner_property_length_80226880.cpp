/* Length of the first basis column (m[0], m[4], m[8]) of the matrix held by
   an indexed property owner (fn_80226880). The engine square root is the bare
   reciprocal of a reciprocal-square-root estimate (frsqrte into f4, then
   fres, with no frsp), which no compiler built-in produces; it is written as
   the same minimal inline asm statement in the math helper as the matched
   src/Game/owner_position_distance_80066DA4.cpp. The zero is the shared
   lbl_8037B11C (0.0f) owned by Game/scalar_constant_8037B118.c. */
struct PropertyHandle{signed int generation:8;signed int index:24;};
struct PropertyStorage{char unknown00[8];};
struct PropertyOwner:PropertyStorage{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual const PropertyHandle*getHandle(int);};
struct PropertyEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];};
struct PropertyManager{char unknown00[8];PropertyEntry*entries;};
extern "C"{extern struct{char unknown00[0x118];PropertyManager*manager;}lbl_801E9D24;}
static inline char*resolveProperty(const PropertyHandle&h){PropertyEntry*e=&lbl_801E9D24.manager->entries[h.index];if(e->generation==h.generation)return e->object;return 0;}
extern "C" const float lbl_8037B11C;

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline float vectorLength(float x, float y, float z)
{
    float sq = x * x + y * y + z * z;
    float r = lbl_8037B11C;
    if (sq != r) r = fastSqrt(sq);
    return r;
}

extern "C" float fn_80226880(PropertyOwner* self, int index)
{
    char* object = resolveProperty(*self->getHandle(index));
    float* m = *(float**)(object + 0x124);
    return vectorLength(m[0], m[4], m[8]);
}
