#include "world_curve_arrays_internal.h"

// The inherited virtual reset hook has no observed state transition.
void CurveRecordBase_802E9E08::reset() {}

typedef char CheckCurveRecordBaseSize[sizeof(CurveRecordBase_802E9E08)==0xC?1:-1];
