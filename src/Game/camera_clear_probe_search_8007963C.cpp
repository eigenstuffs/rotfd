/* Camera clear-probe search (fn_8007963C): with the service handle held,
   steps an angle offset (lbl_803789C8, alternating sign, widened each pair
   up to lbl_803789DC) and casts two masked segment queries (fn_80269818)
   from the camera point at 0xF4 at the given radius: one along the pitch
   (90 - pitch of the negated camera query vector, plus the offset; the
   horizontal factor is sqrt|1 - sin^2| through the MSL Newton square root
   on the shared doubles lbl_80378A10/18/20) at the current heading, and one
   horizontal along the cached heading plus offset at the target's height.
   The first clear offset of each is written to *outA / *outB with the
   found flags set; the horizontal probe is skipped (after logging "Camera
   spin stop") when the camera pitch exceeds lbl_80378A4C. The degree-to-
   radian scale is an inline helper (it fixes the f25 heading register in
   the second probe), and the horizontal factor scales the cosine and sine
   in place. */
typedef unsigned long Word;
struct Handle_801F7F10 { union { Word word; struct { signed int tag : 8, index : 24; } bits; }; Handle_801F7F10(); ~Handle_801F7F10(); };
struct Node;
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
struct Service { char unknown00[8]; const Handle_801F7F10* handle; };
struct Context { char unknown00[0x110]; void* logger; char unknown114[4]; Manager* manager; Service* service; };
extern "C" {
extern Context lbl_801E9D24;
extern char lbl_801EF5C8[];
extern const char lbl_8029CCE8[];
void fn_801EF610(void*, void*);
void fn_801F86C8(Manager*, const Handle_801F7F10*, int);
void fn_801F9D68(void*, const char*, ...);
extern const float lbl_8037899C, lbl_80378A48, lbl_803789A8, lbl_803789C8, lbl_803789EC, lbl_803789A0, lbl_80378A4C, lbl_803789E8, lbl_803789DC;
extern const double lbl_80378A10, lbl_80378A18, lbl_80378A20;
extern int __float_nan[], __float_huge[];
double __frsqrte(double);
float fn_80285124(float, float);
float fn_8028506C(float);
float fn_80284FA8(float);
}
struct Handle_8001FF78 : Handle_801F7F10 { Handle_8001FF78() { word = 0; } ~Handle_8001FF78() {} static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); } };
struct Handle_80020C04 : Handle_8001FF78 { Handle_80020C04(const Handle_801F7F10& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); } ~Handle_80020C04() {} static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); } };

inline float fastSqrt(register float x)
{
    register float r;
    asm { frsqrte f4, x
          fres r, f4 }
    return r;
}

inline double squareRoot(double x)
{
    if (x > lbl_80378A10) {
        double guess = __frsqrte(x);
        guess = lbl_80378A18 * guess * (lbl_80378A20 - guess * guess * x);
        guess = lbl_80378A18 * guess * (lbl_80378A20 - guess * guess * x);
        guess = lbl_80378A18 * guess * (lbl_80378A20 - guess * guess * x);
        guess = lbl_80378A18 * guess * (lbl_80378A20 - guess * guess * x);
        return x * guess;
    } else if (lbl_80378A10 == x)
        return lbl_80378A10;
    else if (x != lbl_80378A10)
        return *(float*)__float_nan;
    return *(float*)__float_huge;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    Vec3& operator=(const Vec3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    Vec3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    float length() const
    {
        float sq = x * x + y * y + z * z;
        float r = lbl_8037899C;
        if (sq != r) r = fastSqrt(sq);
        return r;
    }
};

struct Ray {
    Vec3 origin;
    float length;
    Vec3 direction;
    float unknown1C;
    Ray(const Vec3& from, const Vec3& to) : origin(from), direction(to - from)
    {
        length = direction.length();
        if (length > lbl_80378A48) direction *= lbl_803789A8 / length;
    }
};

struct HitResult {
    char unknown00[0x28];
    int value28, value2C, value30, value34, value38;
    signed char flag3C;
    unsigned long long mask40;
    HitResult() { flag3C = 0; value30 = 0; value34 = 0; value38 = 0; value2C = 0; value28 = 0; }
};

struct Node { char unknown00[4]; };

template <class T> inline T* resolve(const Handle_801F7F10& h)
{
    Entry* entry = &lbl_801E9D24.manager->entries[h.bits.index];
    if (entry->tag == h.bits.tag) return (T*)entry->object;
    return 0;
}

struct Camera {
    char unknown00[0xF4];
    Vec3 current;
};

extern "C" {
void fn_80078550(Camera*, Vec3*);
float fn_800785E0(Camera*);
float fn_80079024(Camera*);
signed char fn_80269818(Node*, const Ray*, HitResult*, unsigned long long, unsigned long long);
}

inline float toRadians(float degrees) { return lbl_803789E8 * degrees; }

extern "C" void fn_8007963C(Camera* self, const Vec3* target, float* outA, float* outB, signed char* foundA, signed char* foundB, float radius)
{
    float pitch;
    *foundA = 0;
    *foundB = 0;
    float step = lbl_803789C8;
    Handle_80020C04 held(*lbl_801E9D24.service->handle);
    Vec3 v;
    fn_80078550(self, &v);
    v = -v;
    float y = v.y;
    v.y = lbl_8037899C;
    float horizontal = v.length();
    float angle = *(const float*)&lbl_8037899C;
    if (angle != y || angle != horizontal) angle = lbl_803789EC * fn_80285124(y, horizontal);
    pitch = lbl_803789A0 - angle;
    signed char stop = 0;
    float yaw;
    if (fn_800785E0(self) > lbl_80378A4C) {
        fn_801F9D68(lbl_801E9D24.logger, lbl_8029CCE8);
        stop = 1;
    } else {
        yaw = lbl_803789A0 + fn_80079024(self);
    }
    HitResult hit;
    int i = 0;
    do {
        if (!*foundA) {
            float s = fn_80284FA8(toRadians(pitch + step));
            float c2 = lbl_803789A8 - s * s;
            if (c2 < lbl_8037899C) c2 = -c2;
            float c = squareRoot(c2);
            float yawDeg = fn_80079024(self);
            float h = toRadians(lbl_803789A0 + yawDeg);
            float ch = fn_8028506C(h);
            float sh = fn_80284FA8(h);
            ch *= c;
            sh *= c;
            Vec3 to;
            to.x = ch * radius + self->current.x;
            to.y = s * radius + self->current.y;
            to.z = sh * radius + self->current.z;
            Ray ray(self->current, to);
            if (!fn_80269818(resolve<Node>(held), &ray, &hit, 0x00008FE000000004ULL, 0ULL)) {
                *foundA = 1;
                *outA = step;
            }
        }
        if (!stop && !*foundB) {
            float h = toRadians(yaw + step);
            float ch = fn_8028506C(h);
            float sh = fn_80284FA8(h);
            Vec3 to;
            to.x = ch * radius + self->current.x;
            to.z = sh * radius + self->current.z;
            to.y = target->y;
            Ray ray(self->current, to);
            if (!fn_80269818(resolve<Node>(held), &ray, &hit, 0x00008FE000000004ULL, 0ULL)) {
                *foundB = 1;
                *outB = step;
            }
        }
        if ((i & 1) || *foundA || *foundB) {
            if (*foundA || *foundB) return;
        }
        i++;
        step = -step;
        if (!(i & 1)) {
            step += lbl_803789C8;
            if (step > lbl_803789DC) return;
        }
    } while (true);
}
