#include "Game/render_position_cache_zero.h"

// The original processes whole cache lines, including the final partial line.
extern "C" void fn_80280158(float* buffer, int count)
{
    count *= 3;
    do {
        __dcbz(buffer, 0);
        count -= 8;
        buffer += 8;
    } while (count > 0);
}
