#include "game_curve_load.h"

extern "C" void fn_801B17F0(Curve<ReferenceKey> *curve, unsigned char **cursor)
{
    int i;
    *cursor = fn_801E9F40(curve, *cursor, 2);
    int count;
    *cursor = fn_801E9F40(&count, *cursor, 4);
    curve->keys.resize(count);
    Registry *registry = &lbl_801E9D24;
    for (i = 0; i < count; ++i) {
        fn_801B41B8(registry->descriptor, &curve->keys.data[i].reference, cursor);
        *cursor = fn_801E9F40(&curve->keys.data[i], *cursor, 2);
    }
}
