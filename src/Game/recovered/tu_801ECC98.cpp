extern "C" double __fabs(double);
// auto_03_801ECC98_text: animation track event dispatch (fn_801ECC98), path sampling with look-ahead
// orientation (fn_801ED050), per-frame timer action dispatch (fn_801ED468).
// fn_801ECC98 and fn_801ED050 are EXACT-MOD-POOL. fn_801ED050 uses float literals (the original
// reloads its pooled literals; .sdata2 0x8037A648..0x8037A668 is this TU pool): 0.0f=0.0f,
// 1/60=(1.0f/60.0f), 1e-6=1e-6f, 1.0f=1.0f. Its normalize computes the length through
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
void fn_801EDB54(Timer*, float);
void fn_801EDD8C(Timer*);
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
#pragma fp_contract off
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
            fn_801ECC98(track, target, 0.0f, to, period);
    } else {
        n = track->count;
        for (i = 0; i < n; i++) {
            if ((1.0f/60.0f) * track->keys[i].time >= from) {
                first = i;
                break;
            }
        }
        for (i = n - 1; i >= 0; i--) {
            if ((1.0f/60.0f) * track->keys[i].time <= to) {
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
                        float excess = to - (1.0f/60.0f) * key->time;
                        if ((!(signed char)(timer->flags & 1)
                             && (timer->flags & 0x28) != 0x28)
                            || (timer->flags & 0x38) == 0x28) {
                            timer->flags |= 7;
                            timer->flags &= ~0x20;
                            if (timer->flags & 0x100)
                                timer->flags ^= 0x100;
                            else {
                                timer->flags &= ~0x80;
                                timer->limit = 0.0f;
                                timer->current = 0.0f;
                                fn_801EDB54(timer, excess);
                            }
                        }
                    } else if (event->type == 0) {
                        float elapsed = (1.0f/60.0f) * key->time - from;
                        if (timer->flags & 1) {
                            fn_801EDB54(timer, elapsed);
                            fn_801EDD8C(timer);
                            timer->flags |= 0x20;
                            timer->flags ^= 5;
                        }
                        if (timer == target)
                            return 0;
                    } else if (event->type == 2) {
                        float elapsed = 1e-6f + ((1.0f/60.0f) * key->time - from);
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
                            lbl_801E9D24.service->play(&h, self->owner, 1.0f);
                        else
                            lbl_801E9D24.service->play(&h, self->owner, -1.0f);
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

namespace leaf_801ED9FC {
extern "C" {
/* Original indexed records, engine setup and allocation-header routines.
 * See docs/notes/game-engine-leaf.md. */

extern void fn_801EDB54(void *);

extern void fn_801EDD8C(void *);

void fn_801ED9FC(void *object) {if(*(unsigned short *)((char *)object+0xbc)&1){fn_801EDB54(object);fn_801EDD8C(object);*(unsigned short *)((char *)object+0xbc)|=256;*(unsigned short *)((char *)object+0xbc)^=5;}}

void fn_801EDA54(void *object) {if(*(unsigned short *)((char *)object+0xbc)&1){fn_801EDB54(object);fn_801EDD8C(object);*(unsigned short *)((char *)object+0xbc)|=32;*(unsigned short *)((char *)object+0xbc)^=5;}}

}

}

namespace links_801EDAAC {
extern "C" {
/* Original engine lifetime and record routines.
* See docs/notes/game-engine-links.md. */
typedef struct Object{
    char pad[0xbc];
    unsigned short flags;
    char padbe[2];
    float valuec0,valuec4,valuec8;
}Object;
void fn_801EDAAC(Object*self,float first,float second,float third){
    if(((signed char)(self->flags&1)||((self->flags&0x28)==0x28))&&((self->flags&0x38)!=0x28))return;
    self->flags|=6;
    self->flags&=~0x20;
    if(self->flags&0x100){
        self->flags^=0x100;
        self->flags|=1;
        return;
    }if(third>=0.0f)self->valuec8=third;
    self->valuec0=second;
    self->valuec4=first;
    if(__fabs(self->valuec4)<=(double)1e-6f)self->flags|=1;
}

}

}

namespace timer_801EDB54 {
/* Timer advancement and callback dispatch through the observed partial view.
 * See docs/notes/game-engine-timer-dispatch.md. */
typedef unsigned long Word;

struct Handle_EDB54 {
    union {
        Word word;
        struct { signed int generation : 8, index : 24; } bits;
    };
};
struct Node_EDB54 {
    char unknown00[0x120];
    Word flags;
};
struct Entry_EDB54 {
    Node_EDB54* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct Manager_EDB54 {
    char unknown00[8];
    Entry_EDB54* entries;
};
extern "C" struct Global_EDB54 {
    char unknown00[0x118];
    Manager_EDB54* manager;
} lbl_801E9D24;

struct Callback_EDB54 {
    long adjustment, dispatch;
    Word target;
};
struct Timer_EDB54 {
    char unknown00[0x20];
    Handle_EDB54 owner;
    float period;
    char unknown28[0x50];
    Callback_EDB54 callback;
    char unknown84[0x38];
    unsigned short flags;
    char unknownBE[2];
    float current, limit, previous;
};

extern "C" {
void fn_801ECC98(Callback_EDB54*, Timer_EDB54*, float, float, float);
void fn_801ED468(Timer_EDB54*, Node_EDB54*);
void fn_801EDB54(Timer_EDB54*, float);
}

inline Node_EDB54* resolveOwnerEDB54(const Handle_EDB54& handle) {
    int index = handle.bits.index;
    Manager_EDB54* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    if (generation == handle.bits.generation)
        return manager->entries[index].object;
    return 0;
}

inline bool fne(float a, float b) { return a != b; }
extern "C" void fn_801EDB54(Timer_EDB54* self, float delta) {
    Node_EDB54* owner = resolveOwnerEDB54(self->owner);
    if (owner && !(owner->flags & 0x100000) && !(self->flags & 0x100)
        && (self->flags & 2)) {
        if (self->flags & 0x80) {
            self->current = self->previous + delta;
            if (self->current > self->period) {
                while (self->current > self->period)
                    self->current -= self->period;
            }
            return;
        }
        self->previous = self->current;
        self->flags |= 0x80;
        self->current += delta;
        if (fne(self->limit, 0.0f)) {
            if (self->current > self->limit) {
                self->previous = 0.0f;
                float excess = self->current - self->limit;
                if ((!(signed char)(self->flags & 1)
                     && (self->flags & 0x28) != 0x28)
                    || (self->flags & 0x38) == 0x28) {
                    self->flags |= 7;
                    self->flags &= ~0x20;
                    if (self->flags & 0x100)
                        self->flags ^= 0x100;
                    else {
                        self->flags &= ~0x80;
                        self->limit = 0.0f;
                        self->current = 0.0f;
                        fn_801EDB54(self, excess);
                    }
                }
            } else
                return;
        }
        if (self->current > self->period) {
            if (self->flags & 8) {
                self->flags |= 0x20;
                self->current = self->period;
            }
            while (self->current > self->period)
                self->current -= self->period;
        }
        if ((self->flags & 4) && self->callback.dispatch)
            fn_801ECC98(&self->callback, self, self->previous,
                       self->current, self->period);
        fn_801ED468(self, owner);
    }
}

}

namespace apply_801EDD8C {

/* fn_801EDD8C: sample the AnimFrame curves at the current time and apply them to the owner or its typed target. */
typedef unsigned long Word;
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3&operator+=(const Vec3&v){x+=v.x;y+=v.y;z+=v.z;return *this;}Vec3(const Vec3&v):x(v.x),y(v.y),z(v.z){}Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct Quat{float w,x,y,z;Quat(){}Quat(const Quat&q):w(q.w),x(q.x),y(q.y),z(q.z){}Quat&operator=(const Quat&q){w=q.w;x=q.x;y=q.y;z=q.z;return *this;}};
struct Matrix{float m[16];};
struct Basis{float v[9];};
struct Handle{signed int tag:8;signed int index:24;};
struct NodeStorage{char unknown00[8];};
struct Node:NodeStorage{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();
 virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34(const Vec3*);
};
struct Transform{char unknown00[0x30];Basis rotation,basis;char unknown78[0xA8];Word flags;Matrix*matrix,*inverse;short unknown12C,index;};
struct Owner{char unknown00[0xC];Handle transform;char unknown10[0xC];Handle target;char unknown20[0x98];Vec3 position;float unknownC4;Quat rotation;Vec3 scale;char unknownE4[0x3C];Word flags;};
struct TargetC:Node{char unknown0C[0x60];unsigned short type;char unknown6E[6];Quat rotation;char unknown84[0x18];Vec3 offset;char unknownA8[4];Vec3 position;};
struct TargetD:Node{char unknown0C[0x60];unsigned short type;char unknown6E[0x16];Vec3 position;Vec3 scale;Quat rotation;};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
struct Pool{Matrix*pages[6];unsigned char active;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;char unknown11C[0x18];Pool*pool;} lbl_801E9D24;
inline void*resolve(const Handle&h){int index=h.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct Curve{unsigned short flags,unknown02;int count,capacity;void*items;};
struct AnimFrame{char unknown00[0x20];Handle owner;float period;Curve position,rotation,scale,progress,path,events,offset,extra,action;char unknownB8[4];unsigned short flags;char unknownBE[2];float time;Owner*getOwner();};
extern "C"{
extern const Vec3 game_vec3_zero;
float fn_8028506C(float);float fn_80284FA8(float);
short fn_801B0C3C(Curve*,float*,bool*,short,float);
short fn_801AFFE4(Curve*,Vec3*,short,float);
short fn_801AF484(Curve*,Quat*,short,float);
short fn_801AFA0C(Curve*,Vec3*,short,float);
signed char fn_801ED050(Curve*,float,float,Vec3*,Quat*,bool);
void fn_801F230C(const Matrix*,Matrix*);
void fn_801F2124(const Basis*,Basis*);
void fn_801F1E78(Quat*,const Basis*);
void fn_801F1BB0(Quat*,const Quat*);
void fn_8023D400(Owner*,Word);
void fn_8023D648(Owner*);
void fn_801EDD8C(AnimFrame*);
}
inline void setAxisAngle(Quat&q,float ax,float ay,float az,float angle){float cs=fn_8028506C(angle);float sn=fn_80284FA8(angle);q.w=cs;float y=ay*sn;q.x=ax*sn;q.y=y;q.z=y;}
inline Owner*AnimFrame::getOwner(){return (Owner*)resolve(owner);}
inline void refreshInverse(Transform*t){if(t->flags&0x20){t->inverse=&lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active][t->index];fn_801F230C(t->matrix,t->inverse);t->flags&=~0x20;}}
inline void refreshBasis(Transform*t){if(t->flags&0x40){fn_801F2124(&t->rotation,&t->basis);t->flags&=~0x40;}}
inline Vec3 transformPoint(const Matrix&m,const Vec3&v){float X=m.m[0]*v.x+m.m[4]*v.y+m.m[8]*v.z+m.m[12];float Y=m.m[1]*v.x+m.m[5]*v.y+m.m[9]*v.z+m.m[13];float Z=m.m[2]*v.x+m.m[6]*v.y+m.m[10]*v.z+m.m[14];return Vec3(X,Y,Z);}

extern "C" void fn_801EDD8C(AnimFrame*self){
 self->flags&=~0x80;
 Transform*t;Owner*owner=self->getOwner();
 if(owner&&!(owner->flags&0x100000)){
  TargetC*c=0;TargetD*d=0;Node*e=0;
  Node*target=(Node*)resolve(owner->target);
  if(target){
   int type=((TargetC*)target)->type;
   if(type==0xC)c=(TargetC*)target;
   else if(type==0xD)d=(TargetD*)target;
   else if(type==0x10)e=target;
  }
  if((self->flags&3)==3){
   if(self->flags&0x20)self->flags&=~2;
   float progress=1.0f;
   Vec3 position=game_vec3_zero;
   Quat rotation;
   setAxisAngle(rotation,1.0f,0.0f,0.0f,0.0f);
   bool flag=1;
   Vec3 scale=game_vec3_zero;
   if(self->progress.count){
    fn_801B0C3C(&self->progress,&progress,&flag,1,self->time);
    if(progress>1.0f)progress=1.0f;
    if(progress<1e-6f)progress=0.0f;
   }
   if(c||d){
    signed char changed=0;
    if(self->position.count){
     fn_801AFFE4(&self->position,&position,1,self->time);
     if(c)c->position=position;else d->position=position;
     changed=1;
    }
    if(self->rotation.count){
     fn_801AF484(&self->rotation,&rotation,1,self->time);
     if(c)c->rotation=rotation;else d->rotation=rotation;
     changed=1;
    }
    if(d&&self->scale.count){
     fn_801AFFE4(&self->scale,&scale,1,self->time);
     d->scale=scale;
     changed=1;
    }
    if(self->path.count){
     Vec3 point;Quat turn;
     signed char turned=fn_801ED050(&self->path,progress*self->period,self->period,&point,&turn,flag);
     t=(Transform*)resolve(owner->transform);
     refreshInverse(t);
     position+=transformPoint(*t->inverse,point);
     if(c)c->position=position;else d->position=position;
     if(turned){
      t=(Transform*)resolve(owner->transform);
      refreshBasis(t);
      Quat q;fn_801F1E78(&q,&t->basis);fn_801F1BB0(&q,&turn);turn=q;
      if(self->rotation.count)fn_801F1BB0(&turn,&rotation);
      if(c)c->rotation=turn;else d->rotation=turn;
     }
     changed=1;
    }
    if(changed)fn_8023D400(owner,0x10);
   }else{
    signed char changed=0;
    if(self->position.count){
     fn_801AFFE4(&self->position,&position,1,self->time);
     owner->position=position;
     changed=1;
    }
    if(self->rotation.count){
     fn_801AF484(&self->rotation,&rotation,1,self->time);
     owner->rotation=rotation;
     changed=1;
    }
    if(self->scale.count){
     fn_801AFFE4(&self->scale,&scale,1,self->time);
     owner->scale=scale;
     changed=1;
    }
    if(self->path.count){
     Vec3 point;Quat turn;
     signed char turned=fn_801ED050(&self->path,progress*self->period,self->period,&point,&turn,flag);
     t=(Transform*)resolve(owner->transform);
     refreshInverse(t);
     position+=transformPoint(*t->inverse,point);
     owner->position=position;
     if(turned){
      t=(Transform*)resolve(owner->transform);
      refreshBasis(t);
      Quat q;fn_801F1E78(&q,&t->basis);fn_801F1BB0(&q,&turn);turn=q;
      if(self->rotation.count)fn_801F1BB0(&turn,&rotation);
      owner->rotation=turn;
     }
     changed=1;
    }
    if(changed)fn_8023D648(owner);
   }
   if(self->offset.count&&(c||d||e)){
    Vec3 offset;
    fn_801AFA0C(&self->offset,&offset,1,self->time);
    if(c)c->slot34(&offset);
    if(d)((Node*)d)->slot34(&offset);
    if(e)e->slot34(&offset);
   }
   if(self->extra.count&&c){
    Vec3 extra;
    fn_801AFA0C(&self->extra,&extra,1,self->time);
    if(c)c->offset=extra;
   }
  }
 }
}

}

namespace scalar_801EE760 {
extern "C" {
/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-late.md. */


void fn_801EE760(float *object, const float *source) { object[29]=source[0]; object[30]=source[1]; object[31]=source[2]; }

}

}

namespace reset_801EE77C {

typedef unsigned long Word;
struct Vec3{float x,y,z;Vec3(){}Vec3(float a,float b,float c):x(a),y(b),z(c){}Vec3&operator+=(const Vec3&v){x+=v.x;y+=v.y;z+=v.z;return *this;}Vec3(const Vec3&v):x(v.x),y(v.y),z(v.z){}Vec3&operator=(const Vec3&v){x=v.x;y=v.y;z=v.z;return *this;}};
struct Quat{float w,x,y,z;Quat(){}Quat(const Quat&q):w(q.w),x(q.x),y(q.y),z(q.z){}Quat&operator=(const Quat&q){w=q.w;x=q.x;y=q.y;z=q.z;return *this;}};
struct Matrix{float m[16];};
struct Basis{float v[9];};
struct Handle{signed int tag:8;signed int index:24;};
struct NodeStorage{char unknown00[8];};
struct Node:NodeStorage{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();
 virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34(const Vec3*);
};
struct Transform{char unknown00[0x30];Basis rotation,basis;char unknown78[0xA8];Word flags;Matrix*matrix,*inverse;short unknown12C,index;};
struct Owner{char unknown00[0xC];Handle transform;char unknown10[0xC];Handle target;char unknown20[0x98];Vec3 position;float unknownC4;Quat rotation;Vec3 scale;char unknownE4[0x3C];Word flags;};
struct TargetC:Node{char unknown0C[0x60];unsigned short type;char unknown6E[6];Quat rotation;char unknown84[0x18];Vec3 offset;char unknownA8[4];Vec3 position;};
struct TargetD:Node{char unknown0C[0x60];unsigned short type;char unknown6E[0x16];Vec3 position;Vec3 scale;Quat rotation;};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
struct Pool{Matrix*pages[6];unsigned char active;};
extern "C" struct Global{char unknown00[0x118];Manager*manager;char unknown11C[0x18];Pool*pool;} lbl_801E9D24;
inline void*resolve(const Handle&h){int index=h.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct Curve{unsigned short flags,unknown02;int count,capacity;void*items;};
struct AnimFrame{char unknown00[0x20];Handle owner;float period;Curve position,rotation,scale,progress,path,events,offset,extra,action;char unknownB8[4];unsigned short flags;char unknownBE[2];float time,limit;Owner*getOwner();};
extern "C"{
extern const Vec3 game_vec3_zero;
float fn_8028506C(float);float fn_80284FA8(float);
short fn_801B0C3C(Curve*,float*,bool*,short,float);
short fn_801AFFE4(Curve*,Vec3*,short,float);
short fn_801AF484(Curve*,Quat*,short,float);
short fn_801AFA0C(Curve*,Vec3*,short,float);
signed char fn_801ED050(Curve*,float,float,Vec3*,Quat*,bool);
void fn_801F230C(const Matrix*,Matrix*);
void fn_801F2124(const Basis*,Basis*);
void fn_801F1E78(Quat*,const Basis*);
void fn_801F1BB0(Quat*,const Quat*);
void fn_8023D400(Owner*,Word);
void fn_8023D648(Owner*);
void fn_801EE978(AnimFrame*);void fn_8023CA80(Owner*,Word,int);void fn_8023DE28(Owner*);
}
inline void setAxisAngle(Quat&q,float ax,float ay,float az,float angle){float cs=fn_8028506C(angle);float sn=fn_80284FA8(angle);q.w=cs;float y=ay*sn;q.x=ax*sn;q.y=y;q.z=y;}
inline Owner*AnimFrame::getOwner(){return (Owner*)resolve(owner);}
inline void refreshInverse(Transform*t){if(t->flags&0x20){t->inverse=&lbl_801E9D24.pool->pages[lbl_801E9D24.pool->active][t->index];fn_801F230C(t->matrix,t->inverse);t->flags&=~0x20;}}
inline void refreshBasis(Transform*t){if(t->flags&0x40){fn_801F2124(&t->rotation,&t->basis);t->flags&=~0x40;}}
inline Vec3 transformPoint(const Matrix&m,const Vec3&v){float X=m.m[0]*v.x+m.m[4]*v.y+m.m[8]*v.z+m.m[12];float Y=m.m[1]*v.x+m.m[5]*v.y+m.m[9]*v.z+m.m[13];float Z=m.m[2]*v.x+m.m[6]*v.y+m.m[10]*v.z+m.m[14];return Vec3(X,Y,Z);}


/* fn_801EE77C: activation of the frame owner handle, path-key targets, event-key targets and action curve. */
struct ActStorage{char unknown00[8];};
struct ActTarget:ActStorage{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual signed char slot1C();
};
struct ActHandle{signed int tag:8;signed int index:24;
 unsigned int isValid()const;ActTarget*get()const;ActTarget*operator->()const{return get();}
};
extern "C"{signed char slot1C__12BaseObject_ZFv(void*);unsigned int fn_801F7EB8(const ActHandle*);void fn_801F7154(void*);signed char fn_801EE77C(struct ActFrame*);}
inline unsigned int ActHandle::isValid()const{return fn_801F7EB8(this);}
inline ActTarget*ActHandle::get()const{int i=index;Manager*m=lbl_801E9D24.manager;int t=m->entries[i].getTag();return t==tag?(ActTarget*)m->entries[i].object:0;}
template<class T> struct ActArray{int count,capacity;T*items;T&operator[](int i){return items[i];}int size()const{return count;}};
struct ActPathKey{Word time;ActHandle target;char unknown08[20];};
struct ActEventTarget{ActHandle target;Word unknown04;};
struct ActEventKey{Word time;ActArray<ActEventTarget> targets;};
struct ActPathCurve{unsigned short flags,unknown02;ActArray<ActPathKey> keys;
 void activate(){for(int i=0;i<keys.size();i++){if(keys[i].target.isValid())keys[i].target->slot1C();}}
};
struct ActEventCurve{unsigned short flags,unknown02;ActArray<ActEventKey> keys;
 void activate(){for(int i=0;i<keys.count;i++){ActEventKey&k=keys.items[i];for(int j=0;j<k.targets.count;j++){ActHandle&h=k.targets.items[j].target;if(h.isValid())h->slot1C();}}}
};
struct ActFrame{
 char unknown00[0x20];ActHandle owner;char unknown24[0x44];
 ActPathCurve path;ActEventCurve events;char unknown88[0x20];char action[0x14];
 signed char activate(){
  if(!slot1C__12BaseObject_ZFv(this))return 0;
  if(owner.isValid())owner->slot1C();
  path.activate();
  events.activate();
  fn_801F7154(action);
  return 1;
 }
};
extern "C" signed char fn_801EE77C(ActFrame*self){return self->activate();}

/* fn_801EE978: reset the frame to time zero and apply every curve sample to the owner or its target. */
extern "C" void fn_801EE978(AnimFrame*self){
 Word dirty=0x200;Transform*t;
 Owner*owner=self->getOwner();
 {
  TargetC*c=0;TargetD*d=0;Node*e=0;
  Node*target=(Node*)resolve(owner->target);
  if(target){
   int type=((TargetC*)target)->type;
   if(type==0xC)c=(TargetC*)target;
   else if(type==0xD)d=(TargetD*)target;
   else if(type==0x10)e=target;
  }
  {
   self->time=0.0f;self->limit=0.0f;
   float progress=self->time;
   Vec3 position(0.0f,0.0f,0.0f);
   Vec3 scale;
   Quat rotation;
   setAxisAngle(rotation,1.0f,0.0f,0.0f,0.0f);
   bool flag=1;
   if(self->progress.count){
    fn_801B0C3C(&self->progress,&progress,&flag,1,self->time);
    if(progress>1.0f)progress=1.0f;
    if(progress<0.0f)progress=0.0f;
   }
   if(c||d){
    signed char changed=0;
    if(self->position.count){
     fn_801AFFE4(&self->position,&position,1,self->time);
     if(c)c->position=position;else d->position=position;
     changed=1;
    }
    if(self->rotation.count){
     fn_801AF484(&self->rotation,&rotation,1,self->time);
     if(c)c->rotation=rotation;else d->rotation=rotation;
     changed=1;
    }
    if(d&&self->scale.count){
     fn_801AFFE4(&self->scale,&scale,1,self->time);
     d->scale=scale;
     changed=1;
    }
    if(self->path.count){
     Vec3 point;Quat turn;
     signed char turned=fn_801ED050(&self->path,progress*self->period,self->period,&point,&turn,flag);
     t=(Transform*)resolve(owner->transform);
     refreshInverse(t);
     position+=transformPoint(*t->inverse,point);
     if(c)c->position=position;else d->position=position;
     if(turned){
      t=(Transform*)resolve(owner->transform);
      refreshBasis(t);
      Quat q;fn_801F1E78(&q,&t->basis);fn_801F1BB0(&q,&turn);turn=q;
      if(self->rotation.count)fn_801F1BB0(&turn,&rotation);
      if(c)c->rotation=turn;else d->rotation=turn;
     }
     changed=1;
    }
    if(changed)fn_8023D400(owner,0x10);
   }else{
    signed char changed=0;
    if(self->position.count){
     fn_801AFFE4(&self->position,&position,1,self->time);
     owner->position=position;
     changed=1;
    }
    if(self->rotation.count){
     fn_801AF484(&self->rotation,&rotation,1,self->time);
     dirty|=0x100;
     owner->rotation=rotation;
     changed=1;
    }
    if(self->scale.count){
     fn_801AFFE4(&self->scale,&scale,1,self->time);
     owner->scale=scale;
     changed=1;
    }
    if(self->path.count){
     Vec3 point;Quat turn;
     signed char turned=fn_801ED050(&self->path,progress*self->period,self->period,&point,&turn,flag);
     t=(Transform*)resolve(owner->transform);
     refreshInverse(t);
     position+=transformPoint(*t->inverse,point);
     owner->position=position;
     if(turned){
      t=(Transform*)resolve(owner->transform);
      refreshBasis(t);
      Quat q;fn_801F1E78(&q,&t->basis);fn_801F1BB0(&q,&turn);turn=q;
      if(self->rotation.count)fn_801F1BB0(&turn,&rotation);
      dirty|=0x100;
      owner->rotation=turn;
     }
     changed=1;
    }
    if(changed)fn_8023D648(owner);
   }
   if(self->offset.count&&(c||d||e)){
    Vec3 offset;
    fn_801AFA0C(&self->offset,&offset,1,self->time);
    if(c)c->slot34(&offset);
    if(d)((Node*)d)->slot34(&offset);
    if(e)e->slot34(&offset);
   }
   if(self->extra.count&&c){
    Vec3 extra;
    fn_801AFA0C(&self->extra,&extra,1,self->time);
    if(c)c->offset=extra;
   }
  }
 }
 fn_8023CA80((Owner*)resolve(self->owner),dirty,1);
 ((Owner*)resolve(self->owner))->flags|=0x80;
 ((Owner*)resolve(self->owner))->flags&=~0x100000;
 fn_8023DE28((Owner*)resolve(self->owner));
 self->flags&=~0x1A7;
 if(self->flags&0x40)self->flags|=7;
}

}

/* Native animation frame construction; see docs/notes/game-anim-frame-init.md. */
typedef unsigned long Word;
extern "C" {extern char lbl_802E9D98[];}
struct Manipulator_Z {Word unknown00[2];void*table;char unknown0C[0x20-0xC];Manipulator_Z();~Manipulator_Z();};
struct FrameInit1_EF438:Handle_801F7F10 {FrameInit1_EF438(){word=0;}~FrameInit1_EF438(){}};
struct FrameInit2_EF438:FrameInit1_EF438 {FrameInit2_EF438(int=0){word=0;}~FrameInit2_EF438(){}};
struct CurveBase_801B1088 {unsigned short flags,unknown;CurveBase_801B1088();~CurveBase_801B1088();};
struct FrameArray_EF438 {int count,capacity;void*data;FrameArray_EF438(){count=0;capacity=0;data=0;}};
struct FrameCurve_EF438:CurveBase_801B1088 {FrameArray_EF438 rows;FrameCurve_EF438(){}~FrameCurve_EF438(){}};
struct FrameCurve2_EF438:FrameCurve_EF438 {FrameCurve2_EF438(){flags=2;}~FrameCurve2_EF438(){}};
struct EmptyFrameArray_EF438 {int count,capacity;void*data;EmptyFrameArray_EF438(){}};
struct WorldActionCurve_801F7560:CurveBase_801B1088 {EmptyFrameArray_EF438 rows;WorldActionCurve_801F7560(){rows.count=0;rows.capacity=0;rows.data=0;}virtual~WorldActionCurve_801F7560();};
struct AnimFrame_801EF438:Manipulator_Z {FrameInit2_EF438 handle;Word unknown24;FrameCurve_EF438 a,b,c,d,e,f;FrameCurve2_EF438 g,h;WorldActionCurve_801F7560 action;short fieldBC;short unknownBE;float x,y,z;AnimFrame_801EF438();~AnimFrame_801EF438();};
AnimFrame_801EF438::AnimFrame_801EF438():handle((table=lbl_802E9D98,0)){fieldBC=0;x=0.0f;y=0.0f;z=0.0f;}
