/* Scene option selectors and their mode-control helpers: one original source
 * file spanning 80032980..8003387C, with its member-pointer records and switch
 * tables in .data. Parts keep their local type views in separate namespaces. */
namespace option_selector_80032980 {
/* Scene callback event selector with option-menu handle transitions (fn_80032980).
 * Same dispatch shape as fn_80031D68/fn_8003387C. The member-pointer records at
 * lbl_802B1918+0x130 (0x802B1A48) and the two compiler switch tables that follow
 * (0x802B1A84 for the inlined fn_80031CB0 enum map, 0x802B1AA0 for the event
 * switch) are original data of this translation unit. Strings are addressed from
 * the translation unit string base lbl_8029A0C0. */
typedef unsigned long Word;
struct MemberPointer { Word a, b, c; };
struct Callback { char unknown00[0x28]; unsigned short flags; short index; };
struct Handle { union { Word value; struct { signed int tag : 8, index : 24; } bits; }; };
struct NameHash {
    Word value;
    NameHash(const char*);
    NameHash(const NameHash& o) : value(o.value) {}
    bool operator==(const NameHash& o) const { return value == o.value; }
};
struct Mode { char unknown00[0x80]; NameHash name; };
struct Node {
    char unknown00[0x28]; short index28; char unknown2A[0x16]; Mode** modes;
    char unknown44[0x2C]; Handle current; char unknown74[4]; Handle h78; Handle target;
    char unknown80[0xC]; Handle h8C; char unknown90[0xF8]; unsigned int kind188;
    void setKey(int key);
};
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
struct Owner { char unknown00[0x2EC]; signed char flag2EC; signed char flag2ED; };
struct Scene { char unknown00[0x15058]; Owner* owner; };
struct ServicePrefix { char unknown00[0x1C]; };
struct Service : ServicePrefix {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(int, int); virtual void v38(int, int, int);
};
struct ModeControlPrefix { char unknown00[0x7C]; };
struct ModeControl : ModeControlPrefix {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void reset(int);
    virtual void setA(float); virtual float getA(); virtual void setB(float); virtual float getB();
    char unknown80[0x408 - 0x80]; Word flags408;
    void setFlag(bool on) { if (on) flags408 |= 2; else flags408 &= ~2; }
};
extern "C" struct Context {
    char unknown00[0x118]; Manager* manager; char unknown11C[8]; Scene* scene;
    char unknown128[0x2C]; Service* service; ModeControl* mode;
} lbl_801E9D24;
inline Node* resolve(const Handle& h) {
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}
inline bool equal(const Handle& left, const Handle& right) { Node* first = resolve(left); return first == resolve(right); }
extern "C" { Word fn_801F948C(void*, const char*); extern const char lbl_8029A0C0[]; }
inline NameHash::NameHash(const char* name) { value = fn_801F948C(this, name); }
extern "C" {
extern const struct SelectorPool { char unknown00[0x130]; MemberPointer entries[5]; } lbl_802B1918;
extern Word lbl_8037808C, lbl_80378090;
extern int lbl_80378094;
extern int lbl_80377798;
extern const float lbl_80378410, lbl_80378388;
void fn_8025EF34(Node*, MemberPointer, int);
void fn_8025EEB4(Node*, MemberPointer);
void fn_8025EB70(Node*, MemberPointer);
Callback* fn_8025F074(Node*, MemberPointer);
void fn_8025F4F4(Callback*, int, const char*);
void fn_8025F658(Callback*, int);
void fn_8025F694(Callback*, Word);
void fn_8025F620(Callback*, Word);
signed char fn_8025E9FC(Node*, int);
void fn_80059340(Owner*, int);
void fn_800B3C68(Node*, int);
void fn_80033040(Node*);
void fn_80055C88(Owner*, signed char);
}
inline void Node::setKey(int key) { fn_800B3C68(this, key); }
/* Inlined body of fn_80031CB0; original case order reproduces its table and layout. */
inline unsigned int convertKey(unsigned int value) {
    switch (value) {
    case 0: value = 5; break;
    case 3: value = 0; break;
    case 6: value = 3; break;
    case 1: value = 6; break;
    case 2: value = 1; break;
    case 4: value = 2; break;
    case 5: value = 4; break;
    }
    return value;
}
inline const NameHash& modeName(Node* n) { return n->modes[n->index28]->name; }

extern "C" MemberPointer lbl_802B1A48[5] = { {0, 0x7C, 8}, {0, 0x7C, 8}, {0, 0x7C, 8}, {0, 0x7C, 8}, {0, 0x7C, 8} };

extern "C" int fn_80032980(Node* self, int event, Callback* callback) {
    const char* strings = lbl_8029A0C0;
    const SelectorPool* members = &lbl_802B1918;
    int result = 1;
    switch (event) {
    case 0: fn_8025EF34(self, members->entries[0], -1); return 1;
    case 1: fn_8025EEB4(self, members->entries[1]); return 1;
    case 2: fn_8025EB70(self, members->entries[2]); return 1;
    case 3:
        if (callback) return (signed char)((callback->flags >> 2) & 1);
        callback = fn_8025F074(self, members->entries[3]);
        if (callback) return (signed char)((callback->flags >> 2) & 1);
        return 0;
    case 4:
        if (callback) return (signed char)(callback->flags & 1);
        callback = fn_8025F074(self, members->entries[4]);
        if (callback) return (signed char)(callback->flags & 1);
        return 0;
    case 5: return 1;
    case 6: if (callback) return callback->index; return -9999;
    }
    lbl_8037808C = 0; lbl_80378090 = 0; lbl_80378094 = -1;
    if (event == 8 || event == 7) fn_8025F4F4(callback, 13, strings + 0x294);
    if (event == 11 && callback->index == -1) return 1;
    fn_8025F658(callback, lbl_80378090);
    int action;
    if (event >= 14) action = event + callback->index * 2;
    else action = event;
    switch (action) {
    case 7: fn_8025F694(callback, lbl_8037808C);
    case 8: break;
    case 14: result = fn_8025E9FC(self, 0x5B); break;
    case 15: {
        if (lbl_80377798 > 0) { if (--lbl_80377798 < 1) lbl_80377798 = 29; }
        NameHash name = modeName(resolve(self->target));
        if (equal(self->current, self->target)) {
            resolve(self->target)->setKey(convertKey(resolve(self->target)->kind188));
            fn_80059340(lbl_801E9D24.scene->owner, 0x29);
        } else if (equal(self->h78, self->target) || equal(self->h8C, self->target)) {
            if (name == NameHash(strings + 0x248)) {
                float value = lbl_801E9D24.mode->getA() - lbl_80378410;
                /* The re-read keeps the shared constant's load short-lived, as the
                 * original 0.0f literal did. */
                if (value < lbl_80378388) value = *(const float*)&lbl_80378388;
                else fn_80059340(lbl_801E9D24.scene->owner, 0x29);
                lbl_801E9D24.mode->setA(value);
            } else if (name == NameHash(strings + 0x258)) {
                float value = lbl_801E9D24.mode->getB() - lbl_80378410;
                if (value < lbl_80378388) value = *(const float*)&lbl_80378388;
                else fn_80059340(lbl_801E9D24.scene->owner, 0x29);
                lbl_801E9D24.mode->setB(value);
            } else if (name == NameHash(strings + 0x268)) {
                fn_80033040(self);
            } else if (name == NameHash(strings + 0x278)) {
                Owner* owner = lbl_801E9D24.scene->owner;
                signed char value = !owner->flag2ED;
                fn_80055C88(owner, value);
                lbl_801E9D24.mode->setFlag(value);
                fn_80059340(lbl_801E9D24.scene->owner, 0x29);
            }
        }
        break;
    }
    default: result = 2; break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}
}
extern "C" void fn_80033038(void) { }
extern "C" void fn_8003303C(void) { }
namespace scene_setup_80033040 {
/* Original scene setup and enum controls; see docs/notes/game-engine-scene-setup-more.md. */
struct Owner{};struct Target{char opaque00[0x2EC];signed char enabled2EC;};struct Scene{char opaque00[0x15058];Target*first15058;};struct Prefix{char opaque00[0x1C];};struct Service:Prefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28();virtual void v2C();virtual void v30();virtual void v34(int,int);virtual void v38(int,int,int);};
extern "C" struct Global{char opaque00[0x124];Scene*scene;char opaque128[0x2C];Service*service;}lbl_801E9D24;extern "C"{void fn_80059340(Target*,int);void fn_802073E8(Owner*,int,Owner*,float);extern const float lbl_80378414;}
extern "C" void fn_80033040(Owner*self){Target*t=lbl_801E9D24.scene->first15058;signed char enabled=!t->enabled2EC;t->enabled2EC=enabled;lbl_801E9D24.service->v34(0,enabled);fn_80059340(lbl_801E9D24.scene->first15058,0x29);lbl_801E9D24.service->v38(0,0,0);if(enabled)fn_802073E8(self,0xE0,self,lbl_80378414);else fn_802073E8(self,0xCF,self,lbl_80378414);}
}
extern "C" void fn_80033118(void) { }
namespace option_selector_8003311C {
/* Scene callback event selector with option-menu handle transitions (fn_8003311C).
 * Mirror of fn_80032980. The member-pointer records at lbl_802B1918+0x1A4
 * (0x802B1ABC) and the two compiler switch tables that follow (0x802B1AF8 for
 * the inlined fn_80031D0C enum map, 0x802B1B14 for the event switch) are
 * original data of this translation unit. Strings are addressed from
 * the translation unit string base lbl_8029A0C0. */
typedef unsigned long Word;
struct MemberPointer { Word a, b, c; };
struct Callback { char unknown00[0x28]; unsigned short flags; short index; };
struct Handle { union { Word value; struct { signed int tag : 8, index : 24; } bits; }; };
struct NameHash {
    Word value;
    NameHash(const char*);
    NameHash(const NameHash& o) : value(o.value) {}
    bool operator==(const NameHash& o) const { return value == o.value; }
};
struct Mode { char unknown00[0x80]; NameHash name; };
struct Node {
    char unknown00[0x28]; short index28; char unknown2A[0x16]; Mode** modes;
    char unknown44[0x2C]; Handle current; char unknown74[4]; Handle h78; Handle target;
    char unknown80[0xC]; Handle h8C; char unknown90[0xF8]; unsigned int kind188;
    void setKey(int key);
};
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
struct Owner { char unknown00[0x2EC]; signed char flag2EC; signed char flag2ED; };
struct Scene { char unknown00[0x15058]; Owner* owner; };
struct ServicePrefix { char unknown00[0x1C]; };
struct Service : ServicePrefix {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(int, int); virtual void v38(int, int, int);
};
struct ModeControlPrefix { char unknown00[0x7C]; };
struct ModeControl : ModeControlPrefix {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void reset(int);
    virtual void setA(float); virtual float getA(); virtual void setB(float); virtual float getB();
    char unknown80[0x408 - 0x80]; Word flags408;
    void setFlag(bool on) { if (on) flags408 |= 2; else flags408 &= ~2; }
};
extern "C" struct Context {
    char unknown00[0x118]; Manager* manager; char unknown11C[8]; Scene* scene;
    char unknown128[0x2C]; Service* service; ModeControl* mode;
} lbl_801E9D24;
inline Node* resolve(const Handle& h) {
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}
inline bool equal(const Handle& left, const Handle& right) { Node* first = resolve(left); return first == resolve(right); }
extern "C" { Word fn_801F948C(void*, const char*); extern const char lbl_8029A0C0[]; }
inline NameHash::NameHash(const char* name) { value = fn_801F948C(this, name); }
extern "C" {
extern const struct SelectorPool { char unknown00[0x1A4]; MemberPointer entries[5]; } lbl_802B1918;
extern Word lbl_8037808C, lbl_80378090;
extern int lbl_80378094;
extern int lbl_80377798;
extern const float lbl_80378410, lbl_8037838C, lbl_80378414;
void fn_8025EF34(Node*, MemberPointer, int);
void fn_8025EEB4(Node*, MemberPointer);
void fn_8025EB70(Node*, MemberPointer);
Callback* fn_8025F074(Node*, MemberPointer);
void fn_8025F4F4(Callback*, int, const char*);
void fn_8025F658(Callback*, int);
void fn_8025F694(Callback*, Word);
void fn_8025F620(Callback*, Word);
signed char fn_8025E9FC(Node*, int);
void fn_80059340(Owner*, int);
void fn_800B3C68(Node*, int);
void fn_802073E8(Node*, int, Node*, float);
void fn_80055C88(Owner*, signed char);
}
inline void Node::setKey(int key) { fn_800B3C68(this, key); }
/* Inlined body of fn_80031D0C; original case order reproduces its table and layout. */
inline unsigned int convertKey(unsigned int value) {
    switch (value) {
    case 0: value = 3; break;
    case 3: value = 6; break;
    case 6: value = 1; break;
    case 1: value = 2; break;
    case 2: value = 4; break;
    case 4: value = 5; break;
    case 5: value = 0; break;
    }
    return value;
}
/* Inlined body of fn_80033040 (defined between the two selectors). */
inline void toggle(Node* self) {
    Owner* t = lbl_801E9D24.scene->owner;
    signed char enabled = !t->flag2EC;
    t->flag2EC = enabled;
    lbl_801E9D24.service->v34(0, enabled);
    fn_80059340(lbl_801E9D24.scene->owner, 0x29);
    lbl_801E9D24.service->v38(0, 0, 0);
    if (enabled) fn_802073E8(self, 0xE0, self, lbl_80378414);
    else fn_802073E8(self, 0xCF, self, lbl_80378414);
}
inline const NameHash& modeName(Node* n) { return n->modes[n->index28]->name; }

extern "C" MemberPointer lbl_802B1ABC[5] = { {0, 0x80, 8}, {0, 0x80, 8}, {0, 0x80, 8}, {0, 0x80, 8}, {0, 0x80, 8} };

extern "C" int fn_8003311C(Node* self, int event, Callback* callback) {
    const char* strings = lbl_8029A0C0;
    const SelectorPool* members = &lbl_802B1918;
    int result = 1;
    switch (event) {
    case 0: fn_8025EF34(self, members->entries[0], -1); return 1;
    case 1: fn_8025EEB4(self, members->entries[1]); return 1;
    case 2: fn_8025EB70(self, members->entries[2]); return 1;
    case 3:
        if (callback) return (signed char)((callback->flags >> 2) & 1);
        callback = fn_8025F074(self, members->entries[3]);
        if (callback) return (signed char)((callback->flags >> 2) & 1);
        return 0;
    case 4:
        if (callback) return (signed char)(callback->flags & 1);
        callback = fn_8025F074(self, members->entries[4]);
        if (callback) return (signed char)(callback->flags & 1);
        return 0;
    case 5: return 1;
    case 6: if (callback) return callback->index; return -9999;
    }
    lbl_8037808C = 0; lbl_80378090 = 0; lbl_80378094 = -1;
    if (event == 8 || event == 7) fn_8025F4F4(callback, 13, strings + 0x294);
    if (event == 11 && callback->index == -1) return 1;
    fn_8025F658(callback, lbl_80378090);
    int action;
    if (event >= 14) action = event + callback->index * 2;
    else action = event;
    switch (action) {
    case 7: fn_8025F694(callback, lbl_8037808C);
    case 8: break;
    case 14: result = fn_8025E9FC(self, 0x5A); break;
    case 15: {
        if (lbl_80377798 > 0) { if (++lbl_80377798 > 29) lbl_80377798 = 1; }
        NameHash name = modeName(resolve(self->target));
        if (equal(self->current, self->target)) {
            resolve(self->target)->setKey(convertKey(resolve(self->target)->kind188));
            fn_80059340(lbl_801E9D24.scene->owner, 0x29);
        } else if (equal(self->h78, self->target) || equal(self->h8C, self->target)) {
            if (name == NameHash(strings + 0x248)) {
                float value = lbl_801E9D24.mode->getA();
                value += lbl_80378410;
                /* The re-read keeps the shared constant's load short-lived, as the
                 * original 1.0f literal did. */
                if (value > lbl_8037838C) value = *(const float*)&lbl_8037838C;
                else fn_80059340(lbl_801E9D24.scene->owner, 0x29);
                lbl_801E9D24.mode->setA(value);
            } else if (name == NameHash(strings + 0x258)) {
                float value = lbl_801E9D24.mode->getB();
                value += lbl_80378410;
                if (value > lbl_8037838C) value = *(const float*)&lbl_8037838C;
                else fn_80059340(lbl_801E9D24.scene->owner, 0x29);
                lbl_801E9D24.mode->setB(value);
            } else if (name == NameHash(strings + 0x268)) {
                toggle(self);
            } else if (name == NameHash(strings + 0x278)) {
                Owner* owner = lbl_801E9D24.scene->owner;
                signed char value = !owner->flag2ED;
                fn_80055C88(owner, value);
                lbl_801E9D24.mode->setFlag(value);
                fn_80059340(lbl_801E9D24.scene->owner, 0x29);
            }
        }
        break;
    }
    default: result = 2; break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}
}
