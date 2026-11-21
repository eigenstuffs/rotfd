#ifndef GAME_MOVIE_DPCM_DECODE_H
#define GAME_MOVIE_DPCM_DECODE_H
extern "C" {
#include "Game/movie_dpcm_tables.h"
}
struct MovieDpcmChannel {
    unsigned char* input;
    short* output;
    short sample;
    unsigned char unknown0A;
    unsigned char index;
    unsigned int word0C;
    short* begin;
    short* end;
};
typedef char MovieDpcmChannelSize[sizeof(MovieDpcmChannel) == 24 ? 1 : -1];
extern "C" void fn_80295FAC(unsigned char*, short*, int, unsigned int,
                            unsigned int, MovieDpcmChannel*);
#endif
