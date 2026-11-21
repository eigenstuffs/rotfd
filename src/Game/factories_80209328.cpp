#include "Game/stream_file_construction_view.h"
inline void *operator new(unsigned long,void *p) { return p; }
// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802AE024[];
extern const char lbl_802AE048[];
extern const char lbl_802AE058[];
void *__ct__33InGameObjectsManipulator_802128A0Fv(void *);

// StreamFile_Z.h:70; allocation size 0x13C.
void *fn_80209328()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x13C, lbl_802AE024,
                              lbl_802AE048, 70, 4);
    object = new(object) StreamFileInit_801C9210;
    return object;
}

// InGameObjectsManipulator_Z.h:35; allocation size 0x24.
void *fn_80209380()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x24, lbl_802AE024,
                              lbl_802AE058, 35, 4);
    if (object)
        object = __ct__33InGameObjectsManipulator_802128A0Fv(object);
    return object;
}
}
