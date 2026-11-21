/* Camera offset update (fn_800788C4). The camera's target (handle +0x24)
   gives its node (virtual slot 0x9C); the local offset at 0xD8 is rotated by
   the node's 3x3 rows at +0x30 into the desired direction. Unless the camera
   is held (0x10C, or the E9/E8/CC hold state), the offset vector at 0x100
   eases toward that direction (fn_8007D4B4, base lbl_80378A28); a held camera
   in mode 0 eases only the height component (fn_8007D45C). Mode 1 eases
   with base lbl_80378A30. Modes 2 and 3 apply the pending yaw delta (0x114)
   around the vertical axis and the pending pitch delta (0x110, fn_80078660),
   then renormalize the offset about the height (0xDC) to the distance
   (0xE0); other modes place the offset at the stored yaw (0xD4). Finally
   the view camera (scene record of 0x20, child handle 0x1C, counted handle
   copy with extab cleanup __dt__15Handle_80027614Fv) gets its position at
   0x124 set to the context position (fn_80076D98) plus the offset.

   The direction components are computed into locals and returned as a
   temporary (transform), which orders the three multiply chains and their
   stores as in the original. The yaw delta is assigned inside the zero
   test and the rotation for it is written out in place: that keeps the zero
   load first and allocates the zero/length in f31 and the delta/angle in
   f30, whereas the shared rotateYaw helper (used for the stored yaw) gives
   the opposite assignment, as in the original second block. The engine
   square roots are the minimal inline asm helpers (fastSqrt: frsqrte f4 +
   fres; reciprocalSqrt: bare frsqrte) used by the other camera units. */
typedef unsigned long Word;

inline float reciprocalSqrt(register float value)
{
    register float result;
    asm { frsqrte result, value }
    return result;
}

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

extern "C" {
float fn_80285124(float, float);
float fn_8028506C(float);
float fn_80284FA8(float);
extern const float lbl_8037899C, lbl_803789E8, lbl_803789EC, lbl_80378A28, lbl_80378A2C, lbl_80378A30;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3 operator+(const Vec3& o) const { return Vec3(x + o.x, y + o.y, z + o.z); }
    Vec3& operator=(const Vec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    void operator*=(float s) { x *= s; y *= s; z *= s; }
    float lengthSquared() const { return x * x + y * y + z * z; }
    Vec3& normalize()
    {
        float inv = reciprocalSqrt(lengthSquared());
        x *= inv;
        y *= inv;
        z *= inv;
        return *this;
    }
    float flatLength(float flatY) const
    {
        float dx = x;
        float dz = z;
        float sq = dx * dx + flatY + dz * dz;
        float r = flatY;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
    void rotateYaw(float degrees)
    {
        float len = flatLength(lbl_8037899C);
        float yaw = *(const float*)&lbl_8037899C;
        if (yaw != z || yaw != x) yaw = lbl_803789EC * fn_80285124(z, x);
        yaw += degrees;
        float rad = lbl_803789E8 * yaw;
        x = len * fn_8028506C(rad);
        z = len * fn_80284FA8(rad);
    }
};

struct QueryHandle {
    union {
        unsigned long value;
        struct {
            signed int tag : 8;
            signed int index : 24;
        } bits;
    };
};

struct QueryPrefix {
    char unknown00[8];
};

struct QueryNode : QueryPrefix {
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
    virtual const QueryHandle* getNodeHandle(int);
    char unknown0C[0x24];
    float matrix[3][3];
    Vec3 transform(const Vec3& v) const
    {
        float x = matrix[0][0] * v.x + matrix[1][0] * v.y + matrix[2][0] * v.z;
        float y = matrix[0][1] * v.x + matrix[1][1] * v.y + matrix[2][1] * v.z;
        float z = matrix[0][2] * v.x + matrix[1][2] * v.y + matrix[2][2] * v.z;
        return Vec3(x, y, z);
    }
};

struct QueryEntry {
    QueryNode* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};

struct QueryManager {
    int count, capacity;
    QueryEntry* entries;
};

struct CameraIndex {
    int value;
    CameraIndex(int v) : value(v) {}
    operator const int&() const { return value; }
};
struct Handle_801F7F10 {
    union {
        Word word;
        struct {
            signed int tag : 8, index : 24;
        } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct ViewNode {
    char unknown00[0x1C];
    Handle_801F7F10 child;
};
struct ViewCamera {
    char unknown00[0x124];
    Vec3 position;
};
struct Entry {
    void* object;
    Word unknown04, unknown08;
    signed char tag;
    char unknown0D[3];
    bool matchesTag(signed char t) const { return tag == t; }
};
struct EntryArray {
    Entry* p;
    Entry& operator[](int i) const { return p[i]; }
};
struct Manager {
    int count, capacity;
    EntryArray entries;
};
struct SceneRecord {
    char unknown00[0x14];
    Handle_801F7F10 handle;
    char unknown18[0x34];
};
extern "C" struct Globals {
    char unknown00[0x114];
    SceneRecord* records;
    Manager* manager;
} lbl_801E9D24;
extern "C" {
void fn_801F86C8(Manager*, const Handle_801F7F10*, short);
void fn_801EF610(void*, void*);
extern char lbl_801EF5C8[];
}
struct HandleZero : Handle_801F7F10 {
    HandleZero() { word = 0; }
    ~HandleZero() {}
};
struct Handle_80027614 : HandleZero {
    Handle_80027614() { word = 0; }
    ~Handle_80027614() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};
struct CameraHandle : Handle_80027614 {
    CameraHandle(const Handle_801F7F10& h)
    {
        word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    ~CameraHandle() {}
};
inline void* resolve(const Handle_801F7F10& h)
{
    Manager* m = lbl_801E9D24.manager;
    const CameraIndex index(h.bits.index);
    const signed char tag = h.bits.tag;
    if (m->entries[index].matchesTag(tag)) return m->entries[index].object;
    return 0;
}
inline ViewCamera* copyResolve(const Handle_801F7F10& h)
{
    CameraHandle held(h);
    return (ViewCamera*)resolve(held);
}

inline QueryNode* resolveQuery(const QueryHandle& h)
{
    QueryEntry* entry = &((QueryManager*)lbl_801E9D24.manager)->entries[h.bits.index];
    if (entry->tag == h.bits.tag)
        return entry->object;
    return 0;
}

struct Camera {
    char unknown00[0x20];
    int viewIndex;
    QueryHandle target;
    char unknown28[0xA4];
    float holdTime;
    int mode;
    float yaw;
    Vec3 local;
    char unknownE4[4];
    signed char flagE8;
    signed char stateE9;
    char unknownEA[0x16];
    Vec3 offset;
    signed char flag10C;
    char unknown10D[3];
    float pitchDelta;
    float yawDelta;
};

extern "C" {
void fn_8007D4B4(const Vec3*, const Vec3*, Vec3*, float, float);
void fn_8007D45C(const float*, const float*, float*, float, float);
void fn_80078660(Camera*, float, signed char);
void fn_80076D98(Camera*, Vec3*);
}

extern "C" void fn_800788C4(Camera* self, float dt)
{
    QueryNode* node = resolveQuery(*resolveQuery(self->target)->getNodeHandle(0));
    Vec3 dir = node->transform(self->local);
    if (!self->flag10C && !(self->stateE9 == 1 && !self->flagE8 && self->holdTime > lbl_8037899C)) {
        fn_8007D4B4(&self->offset, &dir, &self->offset, lbl_80378A28, dt);
    } else if (self->mode == 0) {
        fn_8007D45C(&self->offset.y, &dir.y, &self->offset.y, lbl_80378A2C, dt);
    }
    if (self->mode == 1) {
        fn_8007D4B4(&self->offset, &dir, &self->offset, lbl_80378A30, dt);
    }
    if (self->mode == 2 || self->mode == 3) {
        float delta;
        if (lbl_8037899C != (delta = self->yawDelta)) {
            float len = self->offset.flatLength(lbl_8037899C);
            float yaw = *(const float*)&lbl_8037899C;
            if (yaw != self->offset.z || yaw != self->offset.x)
                yaw = lbl_803789EC * fn_80285124(self->offset.z, self->offset.x);
            yaw += delta;
            float rad = lbl_803789E8 * yaw;
            self->offset.x = len * fn_8028506C(rad);
            self->offset.z = len * fn_80284FA8(rad);
        }
        if (lbl_8037899C != self->pitchDelta) fn_80078660(self, self->pitchDelta, 1);
        self->offset.y -= self->local.y;
        self->offset.normalize();
        self->offset *= self->local.z;
        self->offset.y += self->local.y;
    } else {
        self->offset.rotateYaw(self->yaw);
    }
    ViewNode* view = (ViewNode*)resolve(lbl_801E9D24.records[self->viewIndex].handle);
    const Handle_801F7F10& input = view->child;
    ViewCamera* camera = copyResolve(input);
    Vec3 pos;
    fn_80076D98(self, &pos);
    camera->position = self->offset + pos;
}
