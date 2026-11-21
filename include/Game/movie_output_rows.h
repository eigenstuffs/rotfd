#ifndef GAME_MOVIE_OUTPUT_ROWS_H
#define GAME_MOVIE_OUTPUT_ROWS_H

#include "Game/movie_decoder_record.h"

struct MovieOutputRowState {
    int planeIndex;
    unsigned char* previous;
    unsigned char* current;
    unsigned char* next;
    unsigned char nextPair[2];
    unsigned char currentPair[2];
    unsigned char last;
    unsigned char unknown15[3];
};

typedef char MovieOutputRowStateSize[(sizeof(MovieOutputRowState) == 0x18) ? 1 : -1];
typedef char MovieOutputRowStateNextPairOffset[
    ((unsigned int)&((MovieOutputRowState*)0)->nextPair == 0x10) ? 1 : -1];
typedef char MovieOutputRowStateCurrentPairOffset[
    ((unsigned int)&((MovieOutputRowState*)0)->currentPair == 0x12) ? 1 : -1];

extern "C" {
void fn_80292648(unsigned char*, unsigned char*, int, MovieOutputRowState*);
void fn_8029278C(unsigned char*, unsigned char*, int, MovieOutputRowState*, int);
void fn_80292860(unsigned char*, int, unsigned char*);
}

#endif
