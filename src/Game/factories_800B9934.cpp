// Recovered allocation-and-construction factory fragment.
// Original header strings identify each registration; full TU ownership is unknown.
// Constructors, diagnostic strings and allocator storage remain external.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802A0E78[];
extern const char lbl_802A0EE4[];
extern const char lbl_802A0EFC[];
void *__ct__14Agent_80021260Fv(void *);
void *fn_80024E0C(void *);

// Game_Breakable_Agents.h:24; allocation size 0xC0.
void *fn_800B9934()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0xC0, lbl_802A0E78,
                              lbl_802A0EE4, 24, 4);
    if (object)
        object = __ct__14Agent_80021260Fv(object);
    return object;
}

// HookAgent.h:26; allocation size 0x88.
void *fn_800B998C()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x88, lbl_802A0E78,
                              lbl_802A0EFC, 26, 4);
    if (object)
        object = fn_80024E0C(object);
    return object;
}
}
