/* fn_800E5CAC: actor flag transition update for an effect owner.
 * While the actor's 0x80 flag is set (and the owner is idle, not locked and
 * event bit 0x4000 is clear) it looks up a named scene effect (alternate name
 * when requested), activates it, places it slightly offset from the actor
 * position and starts it. Otherwise it clears the active state and samples
 * record conditions 0x13/0xB. Event bit 0x08000000 toggles fn_800E5F3C, and
 * a pending owner forwards to fn_800E5610. */
typedef unsigned long Word;
extern "C" {
Word fn_801F948C(void*, const char*);
extern const char lbl_802AB104[], lbl_802AB118[];
extern const float lbl_803797C8, lbl_803797E8;
}
struct TransitionName {
    Word value;
    TransitionName(const char* s) { value = fn_801F948C(this, s); }
    TransitionName& operator=(const TransitionName& n) { value = n.value; return *this; }
};
struct Handle_801F7F10 {
    union { Word value; struct { signed int tag : 8, index : 24; } bits; };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct TransitionReturn : Handle_801F7F10 { TransitionReturn(); };
struct TransitionVector {
    float x, y, z;
    TransitionVector() {}
    TransitionVector(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    TransitionVector(const TransitionVector& o) : x(o.x), y(o.y), z(o.z) {}
    TransitionVector offset(const float& dx, const float& dy, const float& dz) const
    {
        return TransitionVector(x + dx, y + dy, z + dz);
    }
};
struct TransitionPrefix { char unknown00[8]; };
struct TransitionEffect : TransitionPrefix {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void activate(); /* 0x38 */
};
struct TransitionActor : TransitionPrefix {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54();
    virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74();
    virtual void slot78(); virtual void slot7C(); virtual void slot80(); virtual void slot84();
    virtual void slot88(); virtual void slot8C(); virtual void slot90(); virtual void slot94();
    virtual void slot98(); virtual void slot9C(); virtual void slotA0(); virtual void slotA4();
    virtual void slotA8(); virtual void slotAC();
    virtual TransitionVector position(int); /* 0xB0 */
    char unknown0C[0x24];
    unsigned long long flags; /* 0x30 */
    char unknown38[0x2E0];
    char record; /* 0x318 */
    char unknown319[0x11F];
    unsigned long long events; /* 0x438 */
};
struct TransitionEntry {
    TransitionEffect* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    signed char getTag() const { return tag; }
};
struct TransitionManager { char unknown00[8]; TransitionEntry* entries; };
struct TransitionScene { char unknown00[0x15058]; void* mode; };
struct TransitionContext {
    char unknown00[0x118];
    TransitionManager* manager;
    char unknown11C[8];
    TransitionScene* scene;
};
extern "C" TransitionContext lbl_801E9D24;
inline TransitionEffect* resolveTransition(const Handle_801F7F10& h)
{
    int index = h.bits.index;
    TransitionManager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}
struct TransitionOwner {
    char unknown00[8];
    TransitionActor* actor;
    char unknown0C[0x34];
    signed char active, alternate, locked, event, pending; /* 0x40..0x44 */
};
extern "C" {
TransitionReturn fn_80058778(void*, const TransitionName&, signed char);
void fn_80254BB4(TransitionEffect*, const TransitionVector&);
void fn_802554F4(TransitionEffect*);
signed char fn_8007D604(void*, int);
void fn_800E5F3C(TransitionOwner*);
void fn_800E5610(TransitionOwner*);
}
extern "C" void fn_800E5CAC(TransitionOwner* self)
{
    unsigned long long events = self->actor->events;
    if (self->actor->flags & 0x8000000000ULL) {
        if (!self->active && !self->locked && !(events & 0x4000ULL)) {
            TransitionName name(lbl_802AB104);
            if (self->alternate)
                name = TransitionName(lbl_802AB118);
            TransitionEffect* effect = resolveTransition(fn_80058778(lbl_801E9D24.scene->mode, name, 0));
            if (effect) {
                effect->activate();
                fn_80254BB4(effect, self->actor->position(0).offset(lbl_803797C8, lbl_803797E8,
                                                                    *(const float*)&lbl_803797C8));
                fn_802554F4(effect);
            }
        }
        self->active = 1;
        self->locked = 0;
        self->alternate = 0;
    } else {
        self->active = 0;
        if (!self->alternate)
            self->alternate = fn_8007D604(&self->actor->record, 0x13);
        if (fn_8007D604(&self->actor->record, 0xB))
            self->alternate = 0;
    }
    if ((events & 0x08000000ULL) && !self->event) {
        fn_800E5F3C(self);
        self->event = 1;
    } else if (!(events & 0x08000000ULL) && self->event) {
        self->event = 0;
    }
    if (self->pending)
        fn_800E5610(self);
}
