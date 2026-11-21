// Menu transition scale/select TU: fn_8021B860, fn_8021BD28, fn_8021C030 and
// fn_8021C248 with its literal pool 0x8037AF98..0x8037AFD4. The last two were
// matched separately before (engine_menu_transition_scale.cpp and
// engine_menu_transition_slide.cpp, now retired) but share this pool, so they
// are one original translation unit.
// Menu child-scale and slide transitions (original translation unit with
// fn_8021C030 / fn_8021C248). fn_8021B860 eases the scale of each child of
// the selected group toward 0.2 (after the selection) or 1.0; fn_8021BD28
// starts a transition by name. The unit's own literals are the .sdata2 pool
// 0x8037AF98..0x8037AFCC: -4, 0, 0.2, 1e-6, 1, -1612, signed int->float
// bias, then 0.3, 8, 10/3, 80/3, -6.66666.
typedef unsigned long Word;
extern "C" double __fabs(double);

struct Handle_801F7F10 {
    union {
        Word word;
        struct { signed int generation : 8, index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct MenuTransitionResult : Handle_801F7F10 {};

inline int pairEqual(float x, float y) {
    int result = 0;
    double ax = __fabs(x);
    if ((float)ax < 1e-6f) {
        if ((float)__fabs(y) < 1e-6f) result = 1;
    }
    return result;
}

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vec3& operator=(const Vec3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
    Vec3 operator*(float f) const { return Vec3(x * f, y * f, z * f); }
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    signed char isZero() const {
        signed char result = 0;
        if (pairEqual(x, y) && (float)__fabs(z) < 1e-6f) result = 1;
        return result;
    }
    signed char equals(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z).isZero(); }
    void assign(float a, float b, float c) { x = a; y = b; z = c; }
    void add(float f) { assign(x + f, y + f, z + f); }
    void sub(float f) { assign(x - f, y - f, z - f); }
    void set(float f) { x = f; y = f; z = f; }
};

struct Prefix { Word unknown00, unknown04; };

struct Node : Prefix {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54();
    virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C();
    virtual int query(void*, void*);
    Handle_801F7F10 parent;
    Handle_801F7F10 child;
    Word unknown14;
    Handle_801F7F10 sibling;
    char unknown1C[0xB8 - 0x1C];
    Vec3 position;
    char unknownC4[0xD8 - 0xC4];
    Vec3 scale;
};

struct Entry {
    Node* object;
    Word unknown04, unknown08;
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct Manager { Word count, capacity; Entry* entries; };
struct Globals { char unknown00[0x118]; Manager* manager; };

struct Item { char unknown00[0x80]; Word key; };

struct MenuTransition : Prefix {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40();
    virtual void event(int);
    char unknown0C[0x18 - 0x0C];
    signed char quiet;
    char unknown19[0x20 - 0x19];
    Handle_801F7F10 owner;
    Handle_801F7F10 resource;
    short selected;
    char unknown2A[0x40 - 0x2A];
    Item** items;
    char unknown44[0x4C - 0x44];
    Handle_801F7F10 current, target;
    float elapsed;
    signed char mode, active, reverse;
    char unknown5B;
    Vec3 velocity;
    float angularVelocity, speed;
    int previous, running;
};

extern "C" {
    extern Globals lbl_801E9D24;
    extern const Vec3 game_vec3_zero;
    Word fn_801F948C(void*, const char*);
    void fn_801F86C8(Manager*, const void*, short);
    Word fn_801F7EB8(const void*);
    void fn_8023DE28(Node*);
    float fn_8023BE00(Node*, int);
    void fn_8023C31C(Node*, int, float);
    void fn_802073E8(void*, int, Node*, float);
}

struct MenuTransitionName {
    Word word;
    MenuTransitionName(const char* text) { word = fn_801F948C(this, text); }
};
extern "C" MenuTransitionResult fn_8026A494(Node*, const MenuTransitionName&);

inline Node* resolve(const Handle_801F7F10& h) {
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    if (e->generation == h.bits.generation) return e->object;
    return 0;
}
inline Node* resolveBytes(const Handle_801F7F10& h) {
    struct ByteManager { Word count, capacity; char* entries; };
    Entry* e = (Entry*)(((ByteManager*)lbl_801E9D24.manager)->entries + h.bits.index * 16);
    if (e->generation == h.bits.generation) return e->object;
    return 0;
}
inline void assign(Handle_801F7F10& to, const Handle_801F7F10& from) {
    fn_801F86C8(lbl_801E9D24.manager, &to, -1);
    to.word = from.word;
    fn_801F86C8(lbl_801E9D24.manager, &from, 1);
}

extern "C" void fn_8021B860(MenuTransition* self, float dt) {
    Node* source = resolve(self->resource);
    void* key = &self->items[self->selected]->key;
    int current = source->query(key, key);
    if (current != 65535) {
        if (self->previous == -1) {
            self->previous = current;
            self->running = 0;
        }
        Node* group = resolveBytes(self->current);
        if (group) {
            group = resolve(group->child);
            if (group) {
                group = resolve(group->child);
                if (group) {
                    if (current != self->previous) {
                        self->speed = -4.0f;
                        self->previous = current;
                        self->elapsed = 0.0f;
                        self->running = 1;
                    }
                    if (self->elapsed < 0.2f && self->running) {
                        Node* node = group;
                        while (node) {
                            if (node->position.x > (float)current) {
                                if (!node->scale.equals(Vec3(0.2f, 0.2f, 0.2f)))
                                    node->scale.add(dt * self->speed);
                            } else {
                                if (!node->scale.equals(Vec3(1.0f, 1.0f, 1.0f)))
                                    node->scale.sub(dt * self->speed);
                            }
                            node = resolve(node->sibling);
                        }
                        self->elapsed += dt;
                    } else {
                        Node* node = group;
                        while (node) {
                            if (node->position.x > (float)current)
                                node->scale.set(0.2f);
                            else
                                node->scale.set(1.0f);
                            node = resolve(node->sibling);
                        }
                        self->running = 1;
                        fn_802073E8(self, 0x2f, resolve(self->resource), -1612.0f);
                    }
                }
            }
        }
    }
}

extern "C" void fn_8021BD28(MenuTransition* self, const char* name, signed char mode, signed char reverse) {
    self->reverse = reverse;
    Node* owner = resolve(self->owner);
    assign(self->target, fn_8026A494(owner, MenuTransitionName(name)));
    Node* target = resolveBytes(self->target);
    Node* parent = resolve(target->parent);
    self->mode = mode;
    if (fn_801F7EB8(&self->current)) {
        switch (mode) {
        case 1: {
            self->angularVelocity = fn_8023BE00(parent, 0) / 0.3f;
            Vec3 offset(8.0f, 0.0f, 0.0f);
            if (reverse) {
                self->velocity = -offset * 3.3333333f;
                target->position = offset;
                fn_8023DE28(target);
            } else {
                self->velocity = offset * 3.3333333f;
                target->position = -offset;
                fn_8023DE28(target);
            }
            fn_8023C31C(target, 1, 0.0f);
            break;
        }
        case 2:
            fn_8023C31C(target, 1, fn_8023BE00(parent, 0));
            self->speed = -6.66666f;
            break;
        }
        self->active = 1;
        self->elapsed = 0.0f;
    } else {
        target->position = game_vec3_zero;
        fn_8023C31C(target, 1, fn_8023BE00(parent, 0));
        fn_8023DE28(target);
        assign(self->current, self->target);
        self->previous = -1;
        fn_8021B860(self, 0.0f);
    }
    if (!self->quiet) self->event(6);
}

// fn_8021C030 / fn_8021C248 (currently Game/engine_menu_transition_scale.cpp
// and Game/engine_menu_transition_slide.cpp) share this unit's literal pool;
// their own literals 0.15 and 100 follow at 0x8037AFCC..0x8037AFD4.
inline Node* resolveSelect(const Handle_801F7F10& h) {
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    return e->generation == h.bits.generation ? e->object : 0;
}
inline Node* resolveBytesSelect(const Handle_801F7F10& h) {
    struct ByteManager { int count, capacity; char* entries; };
    Entry* e = (Entry*)(((ByteManager*)lbl_801E9D24.manager)->entries + h.bits.index * 16);
    return e->generation == h.bits.generation ? e->object : 0;
}
inline Word resolveMessage(const Handle_801F7F10& h) {
    int index = h.bits.index;
    Manager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    if (generation == h.bits.generation) return (Word)manager->entries[index].object;
    return 0;
}
static inline void setPosition(Node* node, float x, float y, float z) {
    node->position.x = x; node->position.y = y; node->position.z = z;
}
static inline void setScale(Node* node, float x, float y, float z) {
    node->scale.x = x; node->scale.y = y; node->scale.z = z;
}

extern "C" void fn_8021C030(MenuTransition* self, float delta) {
    self->elapsed += delta;
    Node* target = resolveSelect(self->target);
    Node* current = resolveBytesSelect(self->current);
    float step = delta * self->speed;
    current->scale = current->scale + Vec3(step, step, step);
    if (self->elapsed > 0.15f) {
        if (self->speed < 0.0f) {
            self->speed = -self->speed;
            setPosition(current, 0.0f, 100.0f, 0.0f);
            setScale(current, 1.0f, 1.0f, 1.0f);
            fn_8023DE28(current);
            target->position = game_vec3_zero;
            setScale(target, 1e-6f, 1e-6f, 1e-6f);
            fn_8023DE28(target);
            assign(self->current, self->target);
            self->elapsed = 0.0f;
        } else {
            setScale(current, 1.0f, 1.0f, 1.0f);
            fn_8023DE28(current);
            fn_802073E8(self, 47, (Node*)resolveMessage(self->resource), -1612.0f);
            self->active = 0;
        }
    }
}

extern "C" void fn_8021C248(MenuTransition* self, float delta) {
    self->elapsed += delta;
    Node* target = resolveSelect(self->target);
    Node* current = resolveBytesSelect(self->current);
    Node* parent = resolveBytesSelect(target->parent);
    float x = self->velocity.x * delta, y = self->velocity.y * delta, z = self->velocity.z * delta;
    float angle = self->angularVelocity * delta;
    target->position = target->position + Vec3(x, y, z);
    fn_8023C31C(target, 1, angle + fn_8023BE00(target, 1));
    current->position = current->position + Vec3(x, y, z);
    fn_8023C31C(current, 1, fn_8023BE00(current, 1) - angle);
    if (self->elapsed > 0.3f) {
        current->position = Vec3(0.0f, 100.0f, 0.0f);
        target->position = game_vec3_zero;
        fn_8023C31C(target, 1, fn_8023BE00(parent, 0));
        assign(self->current, self->target);
        fn_802073E8(self, 47, (Node*)resolveMessage(self->resource), -1612.0f);
        self->active = 0;
    }
    fn_8023DE28(current);
    fn_8023DE28(target);
}
