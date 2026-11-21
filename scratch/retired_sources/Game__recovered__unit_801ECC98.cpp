// auto_03_801ECC98_text: animation track event dispatch (fn_801ECC98), path sampling with look-ahead
// orientation (fn_801ED050), per-frame timer action dispatch (fn_801ED468).
// fn_801ECC98 and fn_801ED050 are EXACT-MOD-POOL. fn_801ED050 uses float literals (the original
// reloads its pooled literals; .sdata2 0x8037A648..0x8037A668 is this TU pool): 0.0f=lbl_8037A648,
// 1/60=lbl_8037A64C, 1e-6=lbl_8037A650, 1.0f=lbl_8037A660. Its normalize computes the length through
// dot(v, v) (two references to the same Vec3), which keeps the reloads after the frsqrte asm.
typedef unsigned long Word;
struct Handle {
    union {
        Word word;
        struct { signed int generation : 8, index : 24; } bits;
    };
};
struct Entry {
    void* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct Manager {
    char unknown00[8];
    Entry* entries;
};
struct Collector;
struct Service;
struct Global {
    char unknown00[0x118];
    Manager* manager;
    char unknown11C[0x144 - 0x11C];
    Collector* collector;
    char unknown148[0x158 - 0x148];
    Service* service;
    char unknown15C[0x170 - 0x15C];
    void* fallback;
};
extern "C" Global lbl_801E9D24;

struct Timer {
    char unknown00[0xbc];
    unsigned short flags;
    char unknownBE[2];
    float current, limit, previous;
};
struct Event {
    Handle handle;
    Word type;
};
struct Key {
    short time;
    char unknown02[2];
    int count;
    char unknown08[4];
    Event* events;
};
struct Track {
    long adjustment;
    int count;
    Word target;
    Key* keys;
};

struct Vec3 { float x, y, z; Vec3() {} Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {} };
struct Quat;
struct Matrix {
    float m[16];
    void transform(Vec3& v) const
    {
        float x = m[12] + (m[0] * v.x + m[4] * v.y + m[8] * v.z);
        float z = m[14] + (m[2] * v.x + m[6] * v.y + m[10] * v.z);
        float y = m[13] + (m[1] * v.x + m[5] * v.y + m[9] * v.z);
        v.x = x; v.y = y; v.z = z;
    }
    Vec3 apply(const Vec3& v) const
    {
        Vec3 r;
        r.x = m[12] + (m[0] * v.x + m[4] * v.y + m[8] * v.z);
        r.y = m[13] + (m[1] * v.x + m[5] * v.y + m[9] * v.z);
        r.z = m[14] + (m[2] * v.x + m[6] * v.y + m[10] * v.z);
        return r;
    }
};
struct Curve {
    char unknown00[0x6e];
    unsigned short flags;
};
struct Owner {
    char unknown00[0x1c];
    Handle curve;
    char unknown20[0x124 - 0x20];
    Matrix* matrix;
};
struct PathKey {
    short time;
    char unknown02[2];
    Handle owner;
    Vec3 mask;
    signed char lookAhead;
    char unknown15[3];
    float lead;
};
struct Path {
    long unknown00;
    int count;
    Word unknown08;
    PathKey* keys;
};
extern "C" {
extern const float lbl_8037A648;
extern const float lbl_8037A64C;
extern const float lbl_8037A650;
void fn_801EDB54(Timer*, float);
void fn_801EDD8C(Timer*);
extern const float lbl_8037A660;
float fn_8024DD38(Curve*, float, Vec3*);
float fn_8024DB7C(Curve*, float, Vec3*);
void fn_801F14E0(const Vec3*, const Vec3*, Quat*);
inline float frsqrte(register float x){register float r;asm{frsqrte r,x}return r;}
inline float dot(const Vec3& a,const Vec3& b){return a.x*b.x+a.y*b.y+a.z*b.z;}
inline void normalize(Vec3& v){float s=frsqrte(dot(v,v));v.x*=s;v.y*=s;v.z*=s;}
}

template <class T> inline T* resolve(const Handle& handle) {
    int index = handle.bits.index;
    Manager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    if (generation == handle.bits.generation)
        return (T*)manager->entries[index].object;
    return 0;
}
inline Timer* resolveTimer(const Handle& handle) {
    int index = handle.bits.index;
    Manager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    if (generation == handle.bits.generation)
        return (Timer*)manager->entries[index].object;
    return 0;
}
extern "C" signed char fn_801ECC98(Track* track, Timer* target, float from, float to, float period)
{
    Timer* timer;
    Event* event;
    Key* key;
    int first;
    int k;
    int last;
    int j;
    int n;
    int i;
    first = -1;
    last = -1;
    if (to < from) {
        if (fn_801ECC98(track, target, from, period, period))
            fn_801ECC98(track, target, lbl_8037A648, to, period);
    } else {
        n = track->count;
        for (i = 0; i < n; i++) {
            if (lbl_8037A64C * track->keys[i].time >= from) {
                first = i;
                break;
            }
        }
        for (i = n - 1; i >= 0; i--) {
            if (*(const float*)&lbl_8037A64C * track->keys[i].time <= to) {
                last = i;
                break;
            }
        }
        if (last >= 0 && first >= 0) {
            for (k = first; k <= last; k++) {
                for (j = 0; j < (key = &track->keys[k])->count; j++) {
                    event = &key->events[j];
                    timer = resolveTimer(event->handle);
                    if (event->type == 1) {
                        float excess = to - lbl_8037A64C * key->time;
                        if ((!(signed char)(timer->flags & 1)
                             && (timer->flags & 0x28) != 0x28)
                            || (timer->flags & 0x38) == 0x28) {
                            timer->flags |= 7;
                            timer->flags &= ~0x20;
                            if (timer->flags & 0x100)
                                timer->flags ^= 0x100;
                            else {
                                timer->flags &= ~0x80;
                                timer->limit = lbl_8037A648;
                                timer->current = lbl_8037A648;
                                fn_801EDB54(timer, excess);
                            }
                        }
                    } else if (event->type == 0) {
                        float elapsed = lbl_8037A64C * key->time - from;
                        if (timer->flags & 1) {
                            fn_801EDB54(timer, elapsed);
                            fn_801EDD8C(timer);
                            timer->flags |= 0x20;
                            timer->flags ^= 5;
                        }
                        if (timer == target)
                            return 0;
                    } else if (event->type == 2) {
                        float elapsed = lbl_8037A650 + (lbl_8037A64C * key->time - from);
                        if (timer->flags & 1) {
                            fn_801EDB54(timer, elapsed);
                            fn_801EDD8C(timer);
                            timer->flags |= 0x100;
                            timer->flags ^= 5;
                        }
                        if (timer == target)
                            return 0;
                    }
                }
            }
        }
    }
    return 1;
}

#pragma fp_contract on
extern "C" signed char fn_801ED050(Path* path, Vec3* position, Quat* rotation, signed char forward, float time, float duration)
{
    int n = path->count;
    int i = 0;
    while (i < n && 0.016666668f * path->keys[i].time < time)
        i++;
    if (--i < 0)
        i = n - 1;
    PathKey* key = &path->keys[i];
    Owner* owner = resolve<Owner>(key->owner);
    Curve* curve = resolve<Curve>(owner->curve);
    fn_8024DD38(curve, time / duration, position);
    *position = owner->matrix->apply(*position);
    if (path->keys[i].lookAhead && path->keys[i].lead > 0.0f) {
        float t = (forward ? time + path->keys[i].lead : time - path->keys[i].lead) / duration;
        Vec3 ahead;
        if ((t >= 1.0f || t < 0.000001f) && !(curve->flags & 0x100)) {
            fn_8024DB7C(curve, t, &ahead);
        } else {
            while (t > 1.0f) t -= 1.0f;
            while (t < 0.000001f) t += 1.0f;
            fn_8024DD38(curve, t, &ahead);
        }
        ahead = owner->matrix->apply(ahead);
        Vec3 dir(ahead.x - position->x, ahead.y - position->y, ahead.z - position->z);
        normalize(dir);
        {
            const Vec3& mask = path->keys[i].mask;
            if (0.0f != mask.x) dir.x = 0.0f;
            if (0.0f != mask.y) dir.y = 0.0f;
            if (0.0f != mask.z) dir.z = 1.0f;
        }
        normalize(dir);
        Vec3 up;
        up.x = 0.0f; up.y = 1.0f; up.z = 0.0f;
        fn_801F14E0(&dir, &up, rotation);
        return 1;
    }
    return 0;
}

#pragma fp_contract off

// ---- fn_801ED468: per-frame timer action dispatch ----
struct Handle_801F7F10 {
    union {
        Word word;
        struct { signed int generation : 8, index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
extern "C" {
void fn_801F86C8(Manager*, const Handle_801F7F10*, int);
Word fn_801F7EB8(const Handle_801F7F10*);
}
struct Handle_8001FF78 : Handle_801F7F10 { Handle_8001FF78() { word = 0; } ~Handle_8001FF78() {} };
struct Handle_80020C04 : Handle_8001FF78 {
    Handle_80020C04(const Handle_801F7F10& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); }
    ~Handle_80020C04() {}
};
struct Handle_80020B90 : Handle_8001FF78 { Handle_80020B90() { word = 0; } ~Handle_80020B90() {} };
struct ServicePrefix { char opaque00[0x7C]; };
struct Service : ServicePrefix {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C(); virtual void v40();
    virtual void v44(); virtual void v48(); virtual void v4C(); virtual void v50();
    virtual void dispatch(const void*, int, const Handle_80020B90&, const Handle_80020B90&);
    virtual void play(const void*, const Handle_80020B90&, float);
};
struct Work { int type; Word value; char unknown08[0x2C - 8]; };
struct Collector { char unknown00[0xD8]; Work* records; int unknownDC; int count; };
struct ActionList { long unknown00; int count; void* data; int unknown0C; };
struct ActTimer {
    char unknown00[0x20];
    Handle_80020B90 owner;
    float period;
    char unknown28[0xA8 - 0x28];
    ActionList actions;
    char unknownB8[0xC0 - 0xB8];
    float current, limit, previous;
};
struct Kind { char unknown00[0x6C]; unsigned short type; };
struct LinkA { char unknown00[0xA8]; signed char enabled; };
struct LinkB { char unknown00[0x80]; signed char enabled; };
struct Sound { char unknown00[0x0C]; unsigned char flags; };
struct Actor { char unknown00[0x38]; unsigned long long flags; char unknown40[0x64 - 0x40]; Handle anim; };
struct OwnerLink { char unknown00[0x130]; Handle target; };
struct Node { char unknown00[0x1C]; Handle link; };
extern "C" {
short fn_801F72E4(ActionList*, Work*, int*, short, float, float, float);
Handle_801F7F10 fn_801F8114(Manager*, Word);
void fn_8023297C(void*, const Handle_801F7F10&, int, char);
void fn_8023D8D8(Node*);
void fn_80255588(Actor*);
void fn_80255678(Actor*);
void fn_802550CC(Actor*, const Handle_801F7F10&);
void fn_802073E8(ActTimer*, int, void*, float);
extern const float lbl_8037A660, lbl_8037A664;
}

inline void setActive(Actor* t, signed char on) { if (on) fn_80255588(t); else fn_80255678(t); }
inline int classify(Kind* link, LinkA*& a, LinkB*& b, LinkB*& c) {
    if (!link) return -1;
    int kind = link->type;
    if (kind == 12) a = (LinkA*)link;
    else if (kind == 13) b = (LinkB*)link;
    else if (kind == 16) c = (LinkB*)link;
    return kind;
}
extern "C" void fn_801ED468(ActTimer* self, Node* node)
{
    if (self->actions.count) {
        Work* records = lbl_801E9D24.collector->records;
        int i = lbl_801E9D24.collector->count;
        fn_801F72E4(&self->actions, records, &lbl_801E9D24.collector->count, 0, self->previous, self->current, self->period);
        int end = lbl_801E9D24.collector->count;
        if (i != end) {
            LinkA* a = 0;
            Work* record = &records[i];
            LinkB* b = 0;
            LinkB* c = 0;
            int kind = classify(resolve<Kind>(node->link), a, b, c);
            Actor* target = resolve<Actor>(resolve<OwnerLink>(*(const Handle*)&self->owner)->target);
            for (; i < end; i++, record++) {
                if (record->type == 14) {
                    Handle_80020C04 h(fn_801F8114(lbl_801E9D24.manager, record->value));
                    lbl_801E9D24.service->dispatch(&h, 15, self->owner, Handle_80020B90());
                } else if (record->type == 15) {
                    Handle_80020C04 h(fn_801F8114(lbl_801E9D24.manager, record->value));
                    if (fn_801F7EB8(&h)) {
                        if (resolve<Sound>(*(const Handle*)&h)->flags & 2)
                            lbl_801E9D24.service->play(&h, self->owner, lbl_8037A660);
                        else
                            lbl_801E9D24.service->play(&h, self->owner, lbl_8037A664);
                    }
                } else if (record->type == 23) {
                    if (target && (target->flags & 0x80) != 0) {
                        void* anim = resolve<void>(target->anim);
                        fn_8023297C(anim, Handle_80020C04(fn_801F8114(lbl_801E9D24.manager, record->value)), 0, 1);
                    }
                } else if (record->type == 24) {
                    bool on = record->value != 0;
                    if (a) {
                        a->enabled = on;
                        fn_8023D8D8(node);
                    } else if (b) {
                        b->enabled = on;
                        fn_8023D8D8(node);
                    } else if (c) {
                        c->enabled = on;
                    } else if (kind == 18 && target) {
                        setActive(target, on);
                    }
                } else if (record->type == 25) {
                    if (kind == 18 && target) {
                        Handle_80020C04 h(fn_801F8114(lbl_801E9D24.manager, record->value));
                        fn_802550CC(target, h);
                    }
                }
                if (target)
                    fn_802073E8(self, record->type, target, i);
                else if (lbl_801E9D24.fallback)
                    fn_802073E8(self, record->type, lbl_801E9D24.fallback, i);
            }
        }
    }
}
