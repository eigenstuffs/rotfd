#include "Game/movie_decoder_symbol.h"

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

extern "C" int fn_80291774(MovieDecoderBitReader* reader)
{
    MovieDecoderHuffmanTree* table = (MovieDecoderHuffmanTree*)reader->buffer;
    int symbol = table->root;
    while (symbol >= 256) {
        unsigned int bit;
        readBit(reader, bit);
        symbol = table->child[bit][symbol];
    }
    return table->child[0][symbol];
}
