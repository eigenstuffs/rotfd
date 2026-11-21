/* fn_80229098: owner motion target change (paired with fn_80229728, which
   calls it to release the previous target). If the current target handle at
   +0x1AC is valid, it is cleared, both objects get event 0x32
   (fn_802073E8), the old target's suspended state bits are remapped
   (0x8/0x20/0x10 -> 0x2000/0x1000/0x8000), its controller (fn_801BE46C,
   when +0x28 is valid) and this owner are notified with empty handles, and
   the old target's own motion target is cleared. If the new handle is
   valid, the new target's attached handle (virtual 0x9C) is reparented to its
   root (fn_8021FD9C) when its parent has state bit 0x200, the suspended bits
   are mapped back, its motion target becomes this owner's identity (+0x04)
   and the delay at +0x1B4 is reset. Finally +0x1AC is assigned the new handle.
   Matching notes: the flag remaps are inline helpers (their saved copy of the
   flags lands in the original registers); the attached handle is resolved
   with a const index/tag lookup so the index and tag stay shared with the
   re-resolve; the identity reference is bound before the retained copy. */
struct Handle_801F7F10 {
    union {
        unsigned long value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct Entry {
    char* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
    bool matchesTag(signed char t) const { return generation == t; }
};
struct Manager { char unknown00[8]; Entry* entries; };
extern "C" {
extern struct { char unknown00[0x118]; Manager* manager; } lbl_801E9D24;
void fn_801F86C8(void*, const void*, int);
void* fn_801F7EB8(const void*);
}
inline char* resolve(const Handle_801F7F10& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int generation = m->entries[index].getGeneration();
    if (generation == h.bits.generation) return m->entries[index].object;
    return 0;
}
inline char* resolveTagged(const Handle_801F7F10& h)
{
    Manager* m = lbl_801E9D24.manager;
    const int i(h.bits.index);
    const signed char tag(h.bits.generation);
    if (m->entries[i].matchesTag(tag)) return m->entries[i].object;
    return 0;
}
struct Handle1 : Handle_801F7F10 { Handle1() { value = 0; } };
struct Handle2 : Handle1 { Handle2() { value = 0; } };
struct Handle3 : Handle2 { Handle3() { value = 0; } };
struct Handle4 : Handle3 { Handle4() { value = 0; } };
struct Copy3 : Handle3 {
    Copy3(const Handle_801F7F10& input)
    {
        value = input.value;
        fn_801F86C8(lbl_801E9D24.manager, &input, 1);
    }
};
inline void assign(Handle_801F7F10& dest, const Handle_801F7F10& input)
{
    fn_801F86C8(lbl_801E9D24.manager, &dest, -1);
    dest.value = input.value;
    fn_801F86C8(lbl_801E9D24.manager, &input, 1);
}
inline signed char valid(const Handle_801F7F10& h) { return fn_801F7EB8(&h) != 0; }

struct Storage { char unknown00[4]; Handle_801F7F10 identity; };
struct Owner : Storage {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54();
    virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74();
    virtual void slot78(); virtual void slot7C(); virtual void slot80(); virtual void slot84();
    virtual void slot88(); virtual void slot8C(); virtual void slot90(); virtual void slot94();
    virtual void slot98(); virtual const Handle_801F7F10* getHandle(int);
    char unknown0C[0x18];
    Handle_801F7F10 related24, controller28;
    char unknown2C[4];
    unsigned long long flags;
    char unknown38[0x174];
    Handle_801F7F10 target;
    char unknown1B0[4];
    float delay;
};
struct ChainNode { char unknown00[0xC]; Handle_801F7F10 parent; };
struct StateNode { char unknown00[0x120]; unsigned long flags; };
extern "C" {
extern const float lbl_8037B174, lbl_8037B178;
void fn_802073E8(void*, int, void*, float);
Handle1 fn_801BE46C(Owner*);
void fn_80038098(void*, const Handle_801F7F10*);
void fn_80229728(void*, const Handle_801F7F10*);
const Handle_801F7F10* fn_80240F28(void*);
void fn_8021FD9C(Owner*, const Handle_801F7F10*, void*, int);
}

inline void suspendFlags(Owner* o)
{
    o->flags &= ~0xB000ULL;
    unsigned long long f = o->flags;
    o->flags |= (f & 0x8ULL) ? 0x2000ULL : 0ULL;
    o->flags |= (f & 0x20ULL) ? 0x1000ULL : 0ULL;
    o->flags |= (f & 0x10ULL) ? 0x8000ULL : 0ULL;
}
inline void resumeFlags(Owner* o)
{
    o->flags &= ~0x38ULL;
    unsigned long long f = o->flags;
    o->flags |= (f & 0x2000ULL) ? 0x8ULL : 0ULL;
    o->flags |= (f & 0x1000ULL) ? 0x20ULL : 0ULL;
    o->flags |= (f & 0x8000ULL) ? 0x10ULL : 0ULL;
}

extern "C" void fn_80229098(Owner* self, const Handle_801F7F10& input)
{
    if (fn_801F7EB8(&self->target)) {
        Owner* target = (Owner*)resolve(self->target);
        {
            Handle4 empty;
            assign(self->target, empty);
        }
        fn_802073E8(resolve(target->related24), 0x32, resolve(self->related24), lbl_8037B174);
        suspendFlags(target);
        if (valid(self->controller28) != 0) fn_80038098(resolve(fn_801BE46C(self)), &Handle3());
        fn_80038098(self, &Handle3());
        fn_80229728(target, &Handle4());
    }
    if (fn_801F7EB8(&input)) {
        const Handle_801F7F10* handle = ((Owner*)resolve(input))->getHandle(0);
        if (((StateNode*)resolve(((ChainNode*)resolveTagged(*handle))->parent))->flags & 0x200)
            fn_8021FD9C(self, handle, resolve(*fn_80240F28(resolveTagged(*handle))), 1);
        Owner* other = (Owner*)resolve(input);
        resumeFlags(other);
        const Handle_801F7F10& identity = self->identity;
        fn_80229728(other, &Copy3(identity));
        self->delay = lbl_8037B178;
    }
    assign(self->target, input);
}
