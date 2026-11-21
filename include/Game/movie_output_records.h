#ifndef GAME_MOVIE_OUTPUT_RECORDS_H
#define GAME_MOVIE_OUTPUT_RECORDS_H

#include "Game/movie_decoder_record.h"

struct MovieOutputRecord {
    int word00;
    int word04;
    unsigned char* source;
    unsigned char* cursor;
    unsigned char* first;
    unsigned char unknown14[8];
    unsigned char* second;
    unsigned char* third;
    unsigned short horizontal;
    unsigned short unknown26;
    int rowBytes;
    int horizontalScale;
    int paddedBytes;
};

typedef char MovieOutputRecordSize[(sizeof(MovieOutputRecord) == 0x34) ? 1 : -1];
typedef char MovieOutputRecordHorizontalOffset[
    ((unsigned int)&((MovieOutputRecord*)0)->horizontal == 0x24) ? 1 : -1];
typedef char MovieOutputRecordPaddedBytesOffset[
    ((unsigned int)&((MovieOutputRecord*)0)->paddedBytes == 0x30) ? 1 : -1];

extern "C" void fn_80292950(MovieDecoderPlane*, MovieOutputRecord*,
    unsigned char*, unsigned char*, unsigned char*);

#endif
