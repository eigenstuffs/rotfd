// Uncredited near-match: two saved parameter registers differ from the original.
#include "record_constructor_internal.h"

Record_80209EA0::Record_80209EA0(const Handle_801F7F10& source,
                               u32 first, u32 second) {
    field50 = 0;
    fn_80209F80(this);
    handle40 = source;
    field3C = second;
    field38 = first;
}
