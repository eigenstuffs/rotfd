#include "Game/movie_block_dispatch.h"
#include "Game/movie_block_interpolation.h"

extern "C" void fn_802929DC(MovieDecoderPlane* planes, MovieOutputRecord* records,
    int xx, int yy)
{
    int x = xx;
    int y = yy;
    MovieOutputRecord* record = records;
    MovieDecoderPlane* plane = planes;
    for (int index = 0; index < 3; index++) {
        int scaledX = x >> plane->horizontalShift;
        int scaledY = y >> plane->verticalShift;
        int block = 0;
        int horizontal = scaledX & 1;
        int vertical = scaledY & 1;
        int* offsets = (int*)&plane->word18;
        int count = plane->scale;
        scaledX >>= 1;
        scaledY >>= 1;
        unsigned char* input = (scaledX + scaledY * plane->width)
            + *(unsigned char**)(record->unknown14 + 4);
        for (; block < count; block++) {
            int offset = *offsets++;
            int inputStride = plane->width;
            int outputStride = inputStride;
            unsigned char* output = *(unsigned char**)record->unknown14 + offset;
            unsigned char* source = input + offset;
            if (vertical) {
                if (horizontal) {
                    fn_80292EAC(output, outputStride, source, inputStride);
                } else {
                    fn_80292D00(output, outputStride, source, inputStride);
                }
            } else {
                if (horizontal) {
                    fn_80292B64(output, outputStride, source, inputStride);
                } else {
                    fn_80292AC8(output, outputStride, source, inputStride);
                }
            }
        }
        record++;
        plane++;
    }
}
