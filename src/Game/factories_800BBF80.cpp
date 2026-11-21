// Recovered allocation-and-construction factory fragment.
// Original header strings identify each registration; full TU ownership is unknown.
// Constructors, diagnostic strings and allocator storage remain external.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802A0E78[];
extern const char lbl_802A11D4[];
void *__ct__14Agent_80052520Fv(void *);

// GlobalAgent.h:79; allocation size 0x320.
void *fn_800BBF80()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x320, lbl_802A0E78,
                              lbl_802A11D4, 79, 4);
    if (object)
        object = __ct__14Agent_80052520Fv(object);
    return object;
}
}
