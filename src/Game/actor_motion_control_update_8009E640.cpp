/* Actor motion control update (slot40__11CScriptMoveFPC4Vec3PC4Vec3PC4Vec3if), called through the forwarding
   callbacks slot40__11CSimpleMoveFPC4Vec3PC4Vec3PC4Vec3if / slot40__11CMediumMoveFPC4Vec3PC4Vec3PC4Vec3if / slot40__12CComplexMoveFPC4Vec3PC4Vec3PC4Vec3if as
   (agent, previous position, next position, delta).

   Resolves the agent's actor (+0x24) and asks the frontend (lbl_803776B8,
   slot 0x14) for its controller. A copy of the resource handle from virtual
   query(0) (slot 0x9C) is held for the whole function (its destructor is the
   only cleanup action, so the extab record lists the two native handle
   destructors __dt__15Handle_80020B90Fv / __dt__15Handle_8001FF78Fv).

   Without an active controller: when the resource is not frozen (0x10000),
   the owner is in mode 1 and not specially pinned, the planar distance from
   fn_8009F518 sets or clears resource state 0x40000; in mode 1 a pending
   blend or a moved position raises agent flag 0x400 and restores the target
   blend, otherwise clears it. With a controller the controller item selected
   by the owner index can pin the agent in place (setPosition, slot 0xBC).

   Finally, unless fn_8009FC1C reports a block, the current direction yaw and
   the resource's forward axis yaw ((0,0,1) through the basis at +0x30) become
   rotations about the up axis and the slerp (fn_8008D420) by scale*delta is
   applied with slotC0__12ObjectMove_ZFv; otherwise slotBC__12ObjectMove_ZFv just moves the agent.

   Constants are the original TU's pooled literals, now the shared labels
   lbl_80378DD8 (0.0f), lbl_80378DDC (1.0f), lbl_80378DE0, lbl_80378E18
   (0.5f). The forward axis reads its first zero through a pointer so that use
   stays separate from the other zero reads, as the separately loaded literal
   was (fixes the f5/f6/f7 assignment). The first half angle is declared
   before the slerp fraction but assigned after it (as in the matched
   slot40__14CJellyfishMoveFPC4Vec3PC4Vec3PC4Vec3if), which fixes the f28/f29 assignment and the f0/f1 assignment
   of the 0.5 constant and the rate. */
struct Handle_801F7F10 {
    union {
        unsigned long value;
        struct {
            signed int tag : 8, index : 24;
        } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};

struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) : x(a), y(b), z(c) {}
};

struct Resource {
    char unknown00[0x30];
    float matrix[9];
    char unknown54[0xCC];
    unsigned long state;
};

struct Owner : Resource {
    char unknown124[0xC0];
    char mode;
    char unknown1E5[7];
    signed char index;
    char special;
};

struct OwnerPrefix {
    char unknown00[0x38];
    unsigned long long flags;
    char unknown40[0x95];
    unsigned char active;
};

struct Entry {
    Resource* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    signed char getTag() const { return tag; }
};

struct Manager {
    int count, capacity;
    Entry* entries;
};

struct Context {
    char unknown00[0x118];
    Manager* manager;
};

extern "C" {
extern Context lbl_801E9D24;
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
void fn_801F86C8(Manager*, const Handle_801F7F10*, int);
extern const float lbl_80378DD8, lbl_80378DDC, lbl_80378DE0, lbl_80378E18;
float fn_8028506C(float);
float fn_80284FA8(float);
float fn_80285124(float, float);
}

struct Handle_8001FF78 : Handle_801F7F10 {
    Handle_8001FF78() { value = 0; }
    ~Handle_8001FF78() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};

struct Handle_80020B90 : Handle_8001FF78 {
    Handle_80020B90(const Handle_801F7F10& h)
    {
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    ~Handle_80020B90() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};

inline Resource* resolve(const Handle_801F7F10& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}

struct Point2 {
    float x, y;
};

/* Rotation by a half angle about an axis (w = cos, xyz = axis * sin). */
struct Quaternion {
    float w, x, y, z;
    Quaternion() {}
    Quaternion& operator=(const Quaternion& q)
    {
        w = q.w;
        x = q.x;
        y = q.y;
        z = q.z;
        return *this;
    }
    Quaternion(const Quaternion& q) : w(q.w), x(q.x), y(q.y), z(q.z) {}
    Quaternion(float ax, float ay, float az, float half)
    {
        w = fn_8028506C(half);
        float sine = fn_80284FA8(half);
        x = ax * sine;
        y = ay * sine;
        z = az * sine;
    }
};

struct ControllerItem {
    char unknown00[0x10];
    char active;
};

struct Controller {
    char unknown00[0xC];
    signed char active;
    char unknown0D[3];
    ControllerItem* items[1];
};

struct FrontendResult {
    char unknown00[0x1F8];
    Controller* controller;
};

struct FrontendPrefix {
    char unknown00[4];
};

struct Frontend : FrontendPrefix {
    virtual void slot8();
    virtual void slotC();
    virtual void slot10();
    virtual FrontendResult* get(); /* vtable +0x14 */
};

struct AgentPrefix {
    char unknown00[8];
};

struct Agent : AgentPrefix {
    virtual void slot8();
    virtual void slotC();
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
    virtual const Handle_801F7F10& query(int); /* vtable +0x9C */
    virtual void slotA0();
    virtual void slotA4();
    virtual void slotA8();
    virtual void slotAC();
    virtual void slotB0();
    virtual void slotB4();
    virtual void slotB8();
    virtual void setPosition(const Vec*, int); /* vtable +0xBC */
    char unknown0C[0x18];
    Handle_801F7F10 actor; /* 0x24 */
    char unknown28[8];
    unsigned long long flags; /* 0x30 */
    char unknown38[0x318];
    float blend; /* 0x350 */
    char unknown354[0x44];
    Vec position, direction; /* 0x398, 0x3A4 */
    char unknown3B0[0x10];
    float scale; /* 0x3C0 */
    char unknown3C4[0xE];
    char enabled; /* 0x3D2 */
    char unknown3D3[0xB];
    signed char blocked; /* 0x3DE */
    char unknown3DF[0xD];
    float targetBlend; /* 0x3EC */
};

extern "C" {
extern Frontend* lbl_803776B8;
float fn_8009F518(Agent*, Point2*);
int fn_8009FC1C(Agent*);
void slotBC__12ObjectMove_ZFv(Agent*, const Vec*, int);
void slotC0__12ObjectMove_ZFv(Agent*, const Vec*, const Quaternion*, int);
Quaternion fn_8008D420(const Quaternion&, const Quaternion&, float);
}

extern "C" void slot40__11CScriptMoveFPC4Vec3PC4Vec3PC4Vec3if(Agent* self, const Vec* previous, const Vec* next, float delta)
{
    Owner* owner = static_cast<Owner*>(resolve(self->actor));
    OwnerPrefix* ownerFlags = reinterpret_cast<OwnerPrefix*>(owner);
    Controller* controller = 0;
    if (lbl_803776B8)
        controller = lbl_803776B8->get()->controller;
    Handle_80020B90 h = self->query(0);
    if (!controller || !controller->active) {
        if (!(resolve(h)->state & 0x10000) && owner->mode == 1 &&
            (owner->special != 1 || !(ownerFlags->flags & 0x8000ULL))) {
            Point2 point;
            if (fn_8009F518(self, &point) < lbl_80378DE0)
                resolve(h)->state |= 0x40000;
            else
                resolve(h)->state &= ~0x40000;
        }
        if (owner->mode == 1) {
            if ((!(self->flags & 0x8000000000ULL) && lbl_80378DD8 != self->blend) ||
                (previous->x != next->x || previous->y != next->y || previous->z != next->z)) {
                self->flags |= 0x400ULL;
                self->blend = self->targetBlend;
            } else {
                self->flags &= ~0x400ULL;
                self->blend = lbl_80378DD8;
            }
        }
    } else {
        self->flags |= 0x400ULL;
        if (!(ownerFlags->flags & 0x8000000000ULL) && owner->index != -1) {
            if (controller->items[owner->index]->active == 1) {
                resolve(h)->state |= 0x40000;
                self->flags |= 0x200ULL;
                self->blend = lbl_80378DD8;
                self->setPosition(&self->position, 0);
                return;
            } else {
                resolve(h)->state &= ~0x40000;
            }
        } else if (!(resolve(h)->state & 0x10000)) {
            self->blend = self->targetBlend;
            resolve(h)->state |= 0x40000;
            self->flags |= 0x200ULL;
        }
    }
    if (!(resolve(self->query(0))->state & 0x10000) || !ownerFlags->active) {
        if (!(signed char)fn_8009FC1C(self) && !self->blocked && self->enabled == 1) {
            float x = self->direction.x, z = self->direction.z;
            Resource* resource = resolve(self->query(0));
            float tx = resource->matrix[0] * *(const float*)&lbl_80378DD8 +
                       resource->matrix[3] * lbl_80378DD8 + resource->matrix[6] * lbl_80378DDC;
            float tz = resource->matrix[2] * lbl_80378DD8 + resource->matrix[5] * lbl_80378DD8 +
                       resource->matrix[8] * lbl_80378DDC;
            float current = fn_80285124(x, z);
            float target = fn_80285124(tx, tz);
            float currentHalf;
            float fraction = self->scale * delta;
            currentHalf = current * lbl_80378E18;
            Quaternion first(lbl_80378DD8, lbl_80378DDC, lbl_80378DD8, currentHalf);
            float targetHalf = target * lbl_80378E18;
            Quaternion second(lbl_80378DD8, lbl_80378DDC, lbl_80378DD8, targetHalf);
            Quaternion result;
            result = fn_8008D420(second, first, fraction);
            slotC0__12ObjectMove_ZFv(self, next, &result, 0);
        } else {
            slotBC__12ObjectMove_ZFv(self, next, 0);
        }
    } else {
        slotBC__12ObjectMove_ZFv(self, next, 0);
    }
}
