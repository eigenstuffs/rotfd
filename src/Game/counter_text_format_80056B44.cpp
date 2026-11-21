/* Format a named HUD counter (patties, sand dollars, jellies, pants, both
 * scores, timer) into the shared 0x44-byte text buffer and return it.
 * Private layout views by observed offset; the counter names are addressed
 * through the original packed string region at 8029ACA8 (base +0x528..0x578),
 * the format strings are the existing sized .sdata2 labels. */
typedef unsigned long u32;

struct Handle_801F7F10 {
    union { u32 word; struct { signed int tag : 8, index : 24; } bits; };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct Entry { void* object; u32 opaque04, opaque08; signed char generation; char opaque0D[3]; };
struct Manager { char opaque00[8]; Entry* entries; };
struct Service { char opaque00[0x1C]; Handle_801F7F10* state1C; };
extern "C" struct Global {
    char opaque00[0x118]; Manager* manager118;
    char opaque11C[0x20]; Service* service13C;
} lbl_801E9D24;

extern "C" {
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
void fn_801F86C8(void*, const Handle_801F7F10*, int);
u32 fn_801F948C(void*, const char*);
u32 fn_801F7EB8(const Handle_801F7F10*);
int sprintf(char*, const char*, ...);
extern const struct CounterNames {
    char opaque000[0x528];
    char patty[0xC];      /* PATTY_COUNT */
    char jelly[0xC];      /* JELLY_COUNT */
    char sandDollar[0x20];/* SAND_DOLLAR_COUNT */
    char pants[0xC];      /* PANTS_COUNT */
    char scoreMe[0xC];    /* SCORE_ME */
    char scoreYou[0xC];   /* SCORE_YOU */
} lbl_8029ACA8;
extern const char lbl_803785C0[5], lbl_803785C8[3], lbl_803785CC[6], lbl_803785D4[7],
    lbl_803785DC[6], lbl_803785E4[3];
extern char lbl_802F4154[];
extern short lbl_8037757A, lbl_80377578;
}

struct Key {
    u32 word;
    Key(const char* s) { word = fn_801F948C(this, s); }
    bool operator==(const Key& o) const { return word == o.word; }
};
extern "C" void fn_800A6234(void*, signed char, Key);

struct Handle_8002B67C : Handle_801F7F10 {
    Handle_8002B67C(const Handle_801F7F10& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager118, &h, 1); }
    ~Handle_8002B67C() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};

inline void* resolve(const Handle_801F7F10& h)
{
    Entry* e = &lbl_801E9D24.manager118->entries[h.bits.index];
    return e->generation == h.bits.tag ? e->object : 0;
}

struct PantsHolder { char opaque00[0x84]; int count84; };
struct PantsLink { char opaque00[0xB0]; Handle_801F7F10* holderB0; };
inline PantsHolder* pantsHolder()
{
    Handle_8002B67C h(*lbl_801E9D24.service13C->state1C);
    if (fn_801F7EB8(&h)) {
        Handle_801F7F10* p = ((PantsLink*)resolve(h))->holderB0;
        if (fn_801F7EB8(p))
            return (PantsHolder*)resolve(*p);
    }
    return 0;
}

struct ScoreFlag { char opaque00[0xC]; signed char enabled; };
struct ScoreState { char opaque00[0x1F8]; ScoreFlag* flag1F8; };
struct ScorePrefix { char opaque00[4]; };
struct ScoreSource : ScorePrefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual ScoreState* state();
};
struct TimerSource { char opaque00[4]; float time; };
extern "C" { extern ScoreSource* lbl_803776B8; extern TimerSource* lbl_803776BC; }

struct CounterItem { char unknown00[8]; int patties, jellies, sandDollars; char unknown14[12]; };
struct CounterGroup {
    int count, peakPatties, peakJellies, peakSandDollars;
    char unknown10[0x1C]; CounterItem* items; char unknown30[0x64];
};
struct CounterOwner {
    char unknown00[0x60]; Handle_801F7F10 handle;
    char unknown64[0x8C]; int group, item;
    char unknownF8[0x40]; CounterGroup* groups; int patties, jellies, sandDollars;
    /* long keeps the original unfolded -1 sentinel compare */
    int groupPeakJellies(long g = -1) { if (g == -1) g = group; return groups[g].peakJellies; }
};

extern "C" char* fn_80056B44(CounterOwner* self, const Key& key)
{
    const CounterNames& names = lbl_8029ACA8;
    lbl_802F4154[0] = 0;
    if (key == Key(names.patty)) {
        int sum = 0;
        for (int i = 0; i < self->groups[self->group].count; i++)
            sum += self->groups[self->group].items[i].patties;
        sprintf(lbl_802F4154, lbl_803785C0, sum);
    } else if (key == Key(names.sandDollar)) {
        sprintf(lbl_802F4154, lbl_803785C0, self->sandDollars);
    } else if (key == Key(names.jelly)) {
        sprintf(lbl_802F4154, lbl_803785C0, self->groupPeakJellies());
    } else if (key == Key(names.pants)) {
        if (pantsHolder())
            sprintf(lbl_802F4154, lbl_803785C8, pantsHolder()->count84);
    } else if (key == Key(names.scoreMe)) {
        if (lbl_803776B8) {
            ScoreFlag* f = lbl_803776B8->state()->flag1F8;
            if (f && f->enabled) {
                void* target = resolve(self->handle);
                fn_800A6234(target, 0, key);
                sprintf(lbl_802F4154, lbl_803785CC, (unsigned short)lbl_8037757A);
            }
        }
    } else if (key == Key(names.scoreYou)) {
        if (lbl_803776B8) {
            ScoreFlag* f = lbl_803776B8->state()->flag1F8;
            if (f && f->enabled) {
                void* target = resolve(self->handle);
                fn_800A6234(target, 0, key);
                sprintf(lbl_802F4154, lbl_803785D4, (unsigned short)lbl_80377578);
            }
        }
    } else if (key == Key(lbl_803785DC)) {
        if (lbl_803776BC) {
            void* target = resolve(self->handle);
            fn_800A6234(target, 0, key);
            sprintf(lbl_802F4154, lbl_803785E4, (int)lbl_803776BC->time);
        }
    }
    return lbl_802F4154;
}
