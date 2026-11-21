#include "Game/movie_decoder_bit.h"

static inline void readBit(MovieDecoderBitReader* reader, unsigned int& result)
{
    int position = reader->position;
    unsigned int value;
    if (position < 0) {
        unsigned int* data = reader->data;
        position = 31;
        reader->data = data + 1;
        value = *data;
        reader->word08 = value;
    } else {
        value = reader->word08;
    }
    result = value >> position;
    reader->position = position - 1;
    result &= 1;
}

extern "C" unsigned int fn_80291734(MovieDecoderBitReader* reader)
{
    unsigned int result;
    readBit(reader, result);
    return (unsigned char)result;
}
