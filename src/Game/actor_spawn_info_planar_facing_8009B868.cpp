/* Actor spawn-info setup (fn_8009B868): runs the base setup fn_80222B48, maps
   the spawn info's 64-bit flag bits (+0x28) onto the actor flags (+0x30), and
   when the info selects a planar facing (0x800000000000 with any of
   0xE0000000000, or 0x10000000000 with any of 0xE000000000) and the info
   object's owner (+0x130) has flag 0x1000000 or the object word +0x120 has
   0x200000, marks the actor's handle +0x24 target (flags38 |= 0x40000000000)
   and stores the XZ unit direction from the info object's geometry position to
   the actor node's (virtual slot 0x9C handle) geometry position at +0x384
   (sqrt-normalized with default (0, 1e-5), then refined by a bare
   reciprocal-square-root estimate; y cleared). Returns the base result.

   Matching notes: the planar zero lbl_80378D5C is a pooled literal of the
   original unit (owned by actor_collision_events_8009AEA8.cpp); each use reads
   a distinct form so the loads stay separate as with the literal. The z
   difference starts from the origin component (dz = origin.z; dz = target.z -
   dz), which numbers the origin load before the target load and gives the
   original f0/f2 assignment. fastSqrt/reciprocalSqrt are the shared engine
   inline asm math helpers. */
#pragma fp_contract on
typedef unsigned long Word;
struct Vec3 { float x, y, z; };
struct Handle { signed int tag : 8; signed int index : 24; };
struct Geometry { char unknown00[0x30]; Vec3 position; };
struct Prefix { Word unknown00, unknown04; };
struct Node : Prefix {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54();
    virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74();
    virtual void slot78(); virtual void slot7C(); virtual void slot80(); virtual void slot84();
    virtual void slot88(); virtual void slot8C(); virtual void slot90(); virtual void slot94();
    virtual void slot98();
    virtual const Handle* getHandle(int);
    char unknown0C[0x24 - 0xC];
    Handle handle24;
    char unknown28[0x30 - 0x28];
    unsigned long long flags30;
    unsigned long long flags38;
    char unknown40[0x120 - 0x40];
    Word flags120;
    Geometry* geometry;
    char unknown128[0x130 - 0x128];
    Handle owner130;
    char unknown134[0x384 - 0x134];
    Vec3 direction;
};
struct Info { char unknown00[0x28]; unsigned long long flags; Node* object; };
struct Entry { Node* object; Word unknown04, unknown08; signed char generation; char unknown0D[3]; signed char getTag() const { return generation; } };
struct Manager { int count, capacity; Entry* entries; };
extern "C" { extern struct { char unknown00[0x118]; Manager* manager; } lbl_801E9D24; }
inline Node* resolve(const Handle& h) {
    int index = h.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.tag ? m->entries[index].object : 0;
}
extern "C" {
extern const float lbl_80378D5C; /* 0.0f */
extern const float lbl_80378D60; /* 1.0f */
extern const float lbl_80378D88; /* 1e-5f */
int fn_80222B48(Node*, Info*);
}
inline float fastSqrt(register float x) {
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}
inline float reciprocalSqrt(register float x) {
    register float r = *(const float*)(unsigned long)&lbl_80378D5C;
    if (x != r) { asm { frsqrte r, x } }
    return r;
}
inline float length2(float x, float z) {
    float sq = x * x + z * z;
    float r = lbl_80378D5C;
    if (sq != r) r = fastSqrt(sq);
    return r;
}
extern "C" int fn_8009B868(Node* self, Info* info) {
    int result = fn_80222B48(self, info);
    if (info->flags & 0x4000ULL) self->flags30 |= 0x0100000000000000ULL;
    if (info->flags & 0x800ULL) self->flags30 |= 0x0040000000000000ULL;
    if (info->flags & 0x1000ULL) self->flags30 |= 0x0080000000000000ULL;
    if (info->flags & 0x2000ULL) self->flags30 |= 0x00C0000000000000ULL;
    if (info->flags & 0x8000ULL) self->flags30 |= 0x0200000000000000ULL;
    if (info->flags & 0x10000ULL) self->flags30 |= 0x0400000000000000ULL;
    if (info->flags & 0x40000ULL) self->flags30 |= 0x2000000000000000ULL;
    if (info->flags & 0x80000ULL) self->flags30 |= 0x4000000000000000ULL;
    if (info->flags & 0x100000ULL) self->flags30 |= 0x8000000000000000ULL;
    signed char planar = 0;
    if ((info->flags & 0x0000800000000000ULL) && (info->flags & 0x00000E0000000000ULL)) planar = 1;
    if ((info->flags & 0x0000010000000000ULL) && (info->flags & 0x000000E000000000ULL)) planar = 1;
    if (planar) {
        Node* object = info->object;
        Node* owner = resolve(object->owner130);
        if ((owner && (owner->flags38 & 0x1000000ULL)) || (object->flags120 & 0x200000)) {
            resolve(self->handle24)->flags38 |= 0x40000000000ULL;
            Vec3& target = resolve(*self->getHandle(0))->geometry->position;
            Vec3& origin = info->object->geometry->position;
            float dz = origin.z;
            dz = target.z - dz;
            float dx = target.x - origin.x;
            float length = length2(dx, dz);
            float x = *(const float*)&lbl_80378D5C, z;
            if (x != length) {
                float inverse = lbl_80378D60 / length;
                x = dx * inverse;
                z = dz * inverse;
            } else {
                z = lbl_80378D88;
            }
            float sq2 = x * x + z * z;
            float scale = reciprocalSqrt(sq2);
            x *= scale;
            z *= scale;
            self->direction.x = x;
            self->direction.y = *(const float*)(int)&lbl_80378D5C;
            self->direction.z = z;
        }
    }
    if (info->flags & 0x10ULL) self->flags30 |= 0x0004000000000000ULL;
    return result;
}
