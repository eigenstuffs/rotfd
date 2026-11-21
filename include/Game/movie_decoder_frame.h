#ifndef GAME_MOVIE_DECODER_FRAME_H
#define GAME_MOVIE_DECODER_FRAME_H
#include "Game/movie_decoder_record.h"
struct MovieDecoderBitReader {
    unsigned int*data;
    unsigned int bits;
    unsigned int word08;
    int position;
    unsigned int*buffer;
};
struct MovieDecoderFrameHeader {
    unsigned char scale,mode;
    unsigned short unknown02;
    unsigned short width,height;
    unsigned int offsets[16];
};
typedef char MovieDecoderBitReaderSize[(sizeof(MovieDecoderBitReader)==20)?1:-1];
typedef char MovieDecoderBitReaderBufferOffset[((unsigned int)&((MovieDecoderBitReader*)0)->buffer==16)?1:-1];
typedef char MovieDecoderFrameHeaderSize[(sizeof(MovieDecoderFrameHeader)==0x48)?1:-1];
typedef char MovieDecoderFrameOffsetsOffset[((unsigned int)&((MovieDecoderFrameHeader*)0)->offsets==8)?1:-1];
extern "C" {
void fn_802954D0(MovieDecoderPrefix*,MovieDecoderFrameHeader*,unsigned char*,void*);
int fn_80291004(unsigned int*,MovieDecoderBitReader*);
void fn_80291334(unsigned char*);
void fn_802915F8(unsigned char*);
void fn_802917E4(unsigned char*,unsigned short,unsigned short);
void fn_80292860(unsigned char*,int,unsigned char*);
extern int lbl_80378180,lbl_80378184;
}
#endif
