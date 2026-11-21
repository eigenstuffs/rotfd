/* BlendCurve_801AE2D0_Actor transform curve blend setup. For each of the position, rotation and
 * scale curves that the target curve set animates, rebuild this set's curve as
 * two keys: the actor's current value at frame 0 and the target's first key at
 * floor(duration * 60 + 0.5) frames; otherwise empty the curve. Rotation keys
 * are then fixed up by fn_801AF1A8. Key and array shapes follow
 * include/game_curve_load.h and the packed-key encoders at 0x801B1094..0x801B13C4. */
typedef unsigned long size_t;

inline void *operator new(size_t, void *p) { return p; }

struct BlendCurve_801AE2D0_Allocator { char reserved[16]; };

extern "C" {
extern BlendCurve_801AE2D0_Allocator lbl_8028F698;
extern const float lbl_8037A1D0, lbl_8037A1D4, lbl_8037A1D8, lbl_8037A1DC;
void *fn_8028FAF4(BlendCurve_801AE2D0_Allocator *, void *, int, int);
void *fn_8028FF24(BlendCurve_801AE2D0_Allocator *, int);
void fn_8028FD50(BlendCurve_801AE2D0_Allocator *, void *, int);
}

struct BlendCurve_801AE2D0_Vec3 {
    float x, y, z;
    BlendCurve_801AE2D0_Vec3() {}
    BlendCurve_801AE2D0_Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    BlendCurve_801AE2D0_Vec3(const BlendCurve_801AE2D0_Vec3 &v) : x(v.x), y(v.y), z(v.z) {}
    BlendCurve_801AE2D0_Vec3 operator-(const BlendCurve_801AE2D0_Vec3 &v) const { return BlendCurve_801AE2D0_Vec3(x - v.x, y - v.y, z - v.z); }
    BlendCurve_801AE2D0_Vec3 operator-() const { return BlendCurve_801AE2D0_Vec3(-x, -y, -z); }
};

struct BlendCurve_801AE2D0_Quat {
    float w, x, y, z;
};

extern "C" const BlendCurve_801AE2D0_Vec3 game_vec3_zero;

struct BlendCurve_801AE2D0_PackedQuat {
    short x, y, z, w;
};

inline int floorToInt_801AE2D0(float x)
{
    if (x < lbl_8037A1DC)
        return (int)(x - lbl_8037A1D0);
    return (int)x;
}

struct BlendCurve_801AE2D0_VecKey;
extern "C" void fn_801B12DC(BlendCurve_801AE2D0_VecKey *, const BlendCurve_801AE2D0_Vec3 *, const BlendCurve_801AE2D0_Vec3 *, const BlendCurve_801AE2D0_Vec3 *);
struct BlendCurve_801AE2D0_VecKey {
    short time;
    short valueX, valueY, valueZ;
    short inX, inY, inZ;
    short outX, outY, outZ;

    BlendCurve_801AE2D0_VecKey() : time(0) {}
    ~BlendCurve_801AE2D0_VecKey() {}
    BlendCurve_801AE2D0_VecKey(short t, const BlendCurve_801AE2D0_Vec3 &v, const BlendCurve_801AE2D0_Vec3 &in, const BlendCurve_801AE2D0_Vec3 &out) : time(0)
    {
        time = t;
        fn_801B12DC(this, &v, &in, &out);
    }
    BlendCurve_801AE2D0_VecKey(float seconds, const BlendCurve_801AE2D0_Vec3 &v, const BlendCurve_801AE2D0_Vec3 &in, const BlendCurve_801AE2D0_Vec3 &out) : time(0)
    {
        time = floorToInt_801AE2D0(lbl_8037A1D8 * seconds + lbl_8037A1D4);
        fn_801B12DC(this, &v, &in, &out);
    }
};

struct BlendCurve_801AE2D0_QuatKey;
extern "C" void fn_801B115C(BlendCurve_801AE2D0_QuatKey *, const BlendCurve_801AE2D0_Quat *);
struct BlendCurve_801AE2D0_QuatKey {
    short time;
    BlendCurve_801AE2D0_PackedQuat value;
    float weight, unknown10;

    BlendCurve_801AE2D0_QuatKey() : time(0), weight(lbl_8037A1DC) {}
    BlendCurve_801AE2D0_QuatKey(short t, const BlendCurve_801AE2D0_Quat &q) : time(0)
    {
        time = t;
        fn_801B115C(this, &q);
        weight = lbl_8037A1DC;
    }
    BlendCurve_801AE2D0_QuatKey(float seconds, const BlendCurve_801AE2D0_Quat &q) : time(0)
    {
        time = floorToInt_801AE2D0(lbl_8037A1D8 * seconds + lbl_8037A1D4);
        fn_801B115C(this, &q);
        weight = lbl_8037A1DC;
    }
    ~BlendCurve_801AE2D0_QuatKey() {}
};

template<class T> struct BlendCurve_801AE2D0_Array {
    int count, capacity;
    T *data;

    void resize_storage(int n)
    {
        if (n) {
            if (data)
                data = (T *)fn_8028FAF4(&lbl_8028F698, data,
                                        capacity * sizeof(T), n * sizeof(T));
            else
                data = (T *)fn_8028FF24(&lbl_8028F698, n * sizeof(T));
        } else if (data) {
            fn_8028FD50(&lbl_8028F698, data, capacity * sizeof(T));
            data = 0;
        }
        capacity = n;
    }

    void resize(int n)
    {
        int i;
        if (n > count) {
            resize_storage(n);
            for (i = count; i < n; ++i)
                new (&data[i]) T;
            count = n;
        } else if (n < count) {
            for (i = count - 1; i >= n; --i)
                data[i].~T();
            resize_storage(n);
            count = n;
        }
    }
};

template<class T> struct BlendCurve_801AE2D0_Curve {
    unsigned short mode;
    BlendCurve_801AE2D0_Array<T> keys;
};

struct BlendCurve_801AE2D0_Set {
    char unknown00[0xC];
    BlendCurve_801AE2D0_Curve<BlendCurve_801AE2D0_VecKey> position;
    BlendCurve_801AE2D0_Curve<BlendCurve_801AE2D0_QuatKey> rotation;
    BlendCurve_801AE2D0_Curve<BlendCurve_801AE2D0_VecKey> scale;
};

struct BlendCurve_801AE2D0_Actor {
    char unknown00[0xB8];
    BlendCurve_801AE2D0_Vec3 position;
    float unknownC4;
    BlendCurve_801AE2D0_Quat rotation;
    BlendCurve_801AE2D0_Vec3 scale;
};

extern "C" {
void fn_801B1264(const BlendCurve_801AE2D0_VecKey *, BlendCurve_801AE2D0_Vec3 *);
void fn_801B11EC(const BlendCurve_801AE2D0_VecKey *, BlendCurve_801AE2D0_Vec3 *);
void fn_801B1094(const BlendCurve_801AE2D0_QuatKey *, BlendCurve_801AE2D0_Quat *);
void fn_801AF1A8(BlendCurve_801AE2D0_Curve<BlendCurve_801AE2D0_QuatKey> *);
}

extern "C" void fn_801AE2D0(BlendCurve_801AE2D0_Set *self, BlendCurve_801AE2D0_Actor *actor, BlendCurve_801AE2D0_Set *other, float duration)
{
    if (other->position.keys.count) {
        self->position.keys.resize(2);
        BlendCurve_801AE2D0_Vec3 start = actor->position;
        BlendCurve_801AE2D0_Vec3 end;
        fn_801B1264(other->position.keys.data, &end);
        BlendCurve_801AE2D0_Vec3 delta = end - start;
        BlendCurve_801AE2D0_VecKey key0((short)0, start, game_vec3_zero, delta);
        self->position.keys.data[0] = key0;
        fn_801B1264(other->position.keys.data, &end);
        fn_801B11EC(other->position.keys.data, &delta);
        BlendCurve_801AE2D0_VecKey key1(duration, end, -delta, game_vec3_zero);
        self->position.keys.data[1] = key1;
    } else {
        self->position.keys.resize(0);
    }

    if (other->rotation.keys.count) {
        self->rotation.keys.resize(2);
        BlendCurve_801AE2D0_QuatKey key0((short)0, actor->rotation);
        self->rotation.keys.data[0] = key0;
        BlendCurve_801AE2D0_Quat end;
        fn_801B1094(other->rotation.keys.data, &end);
        BlendCurve_801AE2D0_QuatKey key1(duration, end);
        self->rotation.keys.data[1] = key1;
        fn_801AF1A8(&self->rotation);
    } else {
        self->rotation.keys.resize(0);
    }

    if (other->scale.keys.count) {
        self->scale.keys.resize(2);
        BlendCurve_801AE2D0_Vec3 start = actor->scale;
        BlendCurve_801AE2D0_Vec3 end;
        fn_801B1264(other->scale.keys.data, &end);
        BlendCurve_801AE2D0_Vec3 delta = end - start;
        BlendCurve_801AE2D0_VecKey key0((short)0, start, game_vec3_zero, delta);
        fn_801B1264(other->scale.keys.data, &end);
        fn_801B11EC(other->scale.keys.data, &delta);
        BlendCurve_801AE2D0_VecKey key1(duration, end, -delta, game_vec3_zero);
        self->scale.keys.data[0] = key0;
        self->scale.keys.data[1] = key1;
    } else {
        self->scale.keys.resize(0);
    }
}
