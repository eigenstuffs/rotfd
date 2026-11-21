// Recovered allocation-and-construction factory fragment.
// Original header strings identify each registration; full TU ownership is unknown.
// Constructors, diagnostic strings and allocator storage remain external.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802A0E78[];
extern const char lbl_802A119C[];
extern const char lbl_802A11B0[];
void *__ct__14Agent_8002B5F4Fv(void *);
void *fn_80040064(void *);

// SpongeBobAgent.h:33; allocation size 0xA0.
void *fn_800BBE74()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0xA0, lbl_802A0E78,
                              lbl_802A119C, 33, 4);
    if (object)
        object = fn_80040064(object);
    return object;
}

// ActorAgent.h:28; allocation size 0x90.
void *fn_800BBECC()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x90, lbl_802A0E78,
                              lbl_802A11B0, 28, 4);
    if (object)
        object = __ct__14Agent_8002B5F4Fv(object);
    return object;
}
}
