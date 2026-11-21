/* Scene callback event selector with handle-specific mode transition (fn_80031D68).
 * Shares the callback dispatch shape of fn_8003387C. The member-pointer records
 * at lbl_802B1918+0x80 (0x802B1998) and the compiler switch table that follows
 * them (0x802B19D4) are original data of this translation unit. */
typedef unsigned long Word;
struct MemberPointer { Word a, b, c; };
struct Callback { char unknown00[0x28]; unsigned short flags; short index; };
struct Handle { union { Word value; struct { signed int tag : 8, index : 24; } bits; }; };
struct Handle_801F7F10 {
    signed int tag : 8, index : 24;
    Handle_801F7F10() { index = 0; tag = 0; }
    ~Handle_801F7F10();
};
struct NameHash {
    Word value;
    NameHash(const char*);
    bool operator==(const NameHash& o) const { return value == o.value; }
};
struct Mode { char unknown00[0x80]; NameHash name; };
struct Node {
    char unknown00[0x28]; short index28; char unknown2A[0x16]; Mode** modes;
    char unknown44[0x2C]; Handle current; char unknown74[8]; Handle target;
};
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
struct Scene { char unknown00[0x15058]; Node* owner; };
struct ModeControlPrefix { char unknown00[0x7C]; };
struct ModeControl : ModeControlPrefix {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14(); virtual void v18();
    virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void reset(int);
};
extern "C" struct Context {
    char unknown00[0x118]; Manager* manager; char unknown11C[8]; Scene* scene;
    char unknown128[0x30]; ModeControl* mode;
} lbl_801E9D24;
inline Node* resolve(const Handle& h) {
    signed char tag = h.bits.tag;
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    signed char entryTag = m->entries[index].getTag();
    return entryTag == tag ? m->entries[index].object : 0;
}
inline bool equal(const Handle& left, const Handle& right) { Node* first = resolve(left); return first == resolve(right); }
inline Node* resolve(const Handle_801F7F10& h) {
    int index = h.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.tag ? m->entries[index].object : 0;
}
inline bool equal(const Handle_801F7F10& left, const Handle& right) { Node* first = resolve(left); return first == resolve(right); }
extern "C" { Word fn_801F948C(void*, const char*); extern const char lbl_8029A318[]; }
inline NameHash::NameHash(const char* name) { value = fn_801F948C(this, name); }
extern "C" {
extern const struct SelectorPool { char unknown00[0x80]; MemberPointer entries[5]; } lbl_802B1918;
extern Word lbl_8037808C, lbl_80378090;
extern int lbl_80378094;
extern signed char lbl_80377788;
extern const char lbl_8029A354[];
void fn_8025EF34(Node*, MemberPointer, int);
void fn_8025EEB4(Node*, MemberPointer);
void fn_8025EB70(Node*, MemberPointer);
Callback* fn_8025F074(Node*, MemberPointer);
void fn_8025F4F4(Callback*, int, const char*);
void fn_8025F658(Callback*, int);
void fn_8025F694(Callback*, Word);
void fn_8025F620(Callback*, Word);
signed char fn_8025E9FC(Node*, int);
void fn_80059340(Node*, int);
void fn_80057100(Node*, int);
signed char fn_800B3F10(Node*);
void fn_8021D26C(Node*);
}
inline bool isMode(Node* n, const NameHash& h) { return n->modes[n->index28]->name == h; }

extern "C" MemberPointer lbl_802B1998[5] = { {0, 0x74, 8}, {0, 0x74, 8}, {0, 0x74, 8}, {0, 0x74, 8}, {0, 0x74, 8} };

extern "C" int fn_80031D68(Node* self, int event, Callback* callback) {
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
    if (event == 8 || event == 7) fn_8025F4F4(callback, 13, lbl_8029A354);
    if (event == 11 && callback->index == -1) return 1;
    fn_8025F658(callback, lbl_80378090);
    int action;
    if (event >= 14) action = event + callback->index * 2;
    else action = event;
    switch (action) {
    case 7: fn_8025F694(callback, lbl_8037808C);
    case 8: break;
    case 14: result = fn_8025E9FC(self, 0x58); break;
    case 15:
        if (equal(self->current, self->target)) {
            if (fn_800B3F10(resolve(self->target))) {
                fn_80059340(lbl_801E9D24.scene->owner, 0x29);
                for (int i = 0; i < 5; i++) { if (!fn_800B3F10(resolve(self->target))) break; }
            } else fn_80059340(lbl_801E9D24.scene->owner, 0x27);
        } else if (!lbl_80377788) {
            if (!equal(Handle_801F7F10(), self->target)) {
                fn_8021D26C(resolve(self->target));
                int mode = 15;
                if (isMode(resolve(self->target), NameHash(lbl_8029A318))) mode ^= 8;
                lbl_801E9D24.mode->reset(mode);
                if (isMode(resolve(self->target), NameHash(lbl_8029A318))) fn_80057100(lbl_801E9D24.scene->owner, -1);
                fn_80059340(lbl_801E9D24.scene->owner, 0x29);
            }
        }
        break;
    default: result = 2; break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}
