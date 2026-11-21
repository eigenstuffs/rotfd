// Recovered allocation-and-construction factory fragment.
// Original header strings identify each registration; full TU ownership is unknown.
// Constructors, diagnostic strings and allocator storage remain external.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802A0E78[];
extern const char lbl_802A0E88[];
extern const char lbl_802A0E98[];
void *fn_800E133C(void *);
void *__ct__14Agent_800E3250Fv(void *);
void *__ct__14Agent_800E3798Fv(void *);

// SBPantsAgent.h:49; allocation size 0x88.
void *fn_800B9040()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x88, lbl_802A0E78,
                              lbl_802A0E88, 49, 4);
    if (object)
        object = __ct__14Agent_800E3798Fv(object);
    return object;
}

// SBPantsAgent.h:21; allocation size 0x78.
void *fn_800B9098()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x78, lbl_802A0E78,
                              lbl_802A0E88, 21, 4);
    if (object)
        object = __ct__14Agent_800E3250Fv(object);
    return object;
}

// WaterHelmetAgent.h:11; allocation size 0x78.
void *fn_800B90F0()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x78, lbl_802A0E78,
                              lbl_802A0E98, 11, 4);
    if (object)
        object = fn_800E133C(object);
    return object;
}
}
