#include "Game/movie_output_records.h"

extern "C" void fn_80292950(MovieDecoderPlane* plane, MovieOutputRecord* record,
    unsigned char* first, unsigned char* second, unsigned char* third)
{
    for (int i = 0; i < 3; i++) {
        record->word00 = 0;
        record->word04 = 127;
        record->first = first;
        record->second = second;
        record->third = third;
        unsigned char* source = *(unsigned char**)((unsigned char*)plane + 4);
        record->source = source;
        record->cursor = source;
        record->horizontal = 8 >> plane->horizontalShift;
        record->rowBytes = (8 >> plane->verticalShift) * plane->width;
        record->horizontalScale = plane->horizontalScale;
        record->paddedBytes = plane->paddedWidth * plane->verticalScale;
        record++;
        first += plane->pixels;
        second += plane->pixels;
        third += plane->pixels;
        plane++;
    }
}
