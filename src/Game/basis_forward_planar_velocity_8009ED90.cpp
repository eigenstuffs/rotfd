/* Planar velocity from the resource basis (fn_8009ED90), called as
   (agent, direction, delta) by the motion-control actions (see
   include/Game/owner_motion_control_views.h); the direction and delta
   arguments are unused here.

   Unless the resource resolved from virtual getHandle(0) (slot 0x9C) is
   frozen (state bit 0x10000), resolves it again, rotates the forward axis
   (0, 0, 1) by its 3x3 basis at +0x30 and stores the X/Z components scaled by
   the agent's speed (+0x36C) into the velocity at +0x144. The velocity is
   assigned as a whole vector that keeps its own y; the y self-copy is
   removed by the optimizer but its presence fixes the scheduling of the
   m[6]/m[8] loads after both partial sums.

   The zero and one are the original TU's pooled literals, now the shared
   labels lbl_80378DD8 (0.0f) and lbl_80378DDC (1.0f). The z component's
   first zero is read through a pointer so that use stays separate from the
   other zero reads, as the separately loaded literal was (fixes the f3/f4
   assignment). */
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
};

struct BasisMotionHandle {
    union {
        unsigned long value;
        struct {
            signed int tag : 8;
            signed int index : 24;
        } bits;
    };
};

struct BasisMotionResource {
    char unknown00[0x30];
    float matrix[9]; /* 0x30 */
    char unknown54[0xCC];
    unsigned int flags; /* 0x120 */
};

struct BasisMotionEntry {
    BasisMotionResource* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};

struct BasisMotionManager {
    int count, capacity;
    BasisMotionEntry* entries;
};

struct BasisMotionContext {
    char unknown00[0x118];
    BasisMotionManager* manager;
};

extern "C" BasisMotionContext lbl_801E9D24;

inline BasisMotionResource* resolveBasisMotion(const BasisMotionHandle& handle)
{
    BasisMotionEntry* entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    if (entry->tag == handle.bits.tag)
        return entry->object;
    return 0;
}

struct BasisMotionPrefix {
    char unknown00[8];
};

struct BasisMotionAgent : BasisMotionPrefix {
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
    virtual const BasisMotionHandle* getHandle(int); /* vtable +0x9C */
    char unknown0C[0x138];
    Vec3 velocity; /* 0x144 */
    char unknown150[0x21C];
    float speed; /* 0x36C */
};

extern "C" const float lbl_80378DD8; /* 0.0f */
extern "C" const float lbl_80378DDC; /* 1.0f */

extern "C" void fn_8009ED90(BasisMotionAgent* self, const Vec3& direction, float delta)
{
    if (!(resolveBasisMotion(*self->getHandle(0))->flags & 0x10000)) {
        BasisMotionResource* object = resolveBasisMotion(*self->getHandle(0));
        float x = object->matrix[0] * lbl_80378DD8 + object->matrix[3] * lbl_80378DD8 +
                  object->matrix[6] * lbl_80378DDC;
        float z = object->matrix[2] * *(const float*)&lbl_80378DD8 + object->matrix[5] * lbl_80378DD8 +
                  object->matrix[8] * lbl_80378DDC;
        float speed = self->speed;
        self->velocity = Vec3(x * speed, self->velocity.y, z * speed);
    }
}
