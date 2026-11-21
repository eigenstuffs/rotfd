#ifndef GAME_MOVIE_DECODER_SYMBOL_H
#define GAME_MOVIE_DECODER_SYMBOL_H
#include "Game/movie_decoder_frame.h"
struct MovieDecoderHuffmanTree {
    int word00;
    int root;
    int child[2][512];
};
typedef char MovieDecoderHuffmanTreeSize[sizeof(MovieDecoderHuffmanTree) == 0x1008 ? 1 : -1];
typedef char MovieDecoderHuffmanChildOffset[((unsigned int)&((MovieDecoderHuffmanTree*)0)->child == 8) ? 1 : -1];
extern "C" int fn_80291774(MovieDecoderBitReader*);
#endif
