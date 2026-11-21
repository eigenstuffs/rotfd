#ifndef GAME_MOVIE_DECODER_RECORD_H
#define GAME_MOVIE_DECODER_RECORD_H
#include "Game/movie_decoder_layout.h"
struct MovieDecoderPlane {
    unsigned char unknown00[8];
    unsigned short blocksWidth,blocksHeight,paddedWidth,paddedHeight;
    unsigned short word10,word12,word14,word16;
    unsigned int word18,rowBytes,rowBytesPlus4,word24;
    unsigned short width,height;
    int pixels;
    unsigned char horizontalShift,verticalShift,horizontalScale,verticalScale,scale;
    unsigned char unknown35[3];
};
typedef char MovieDecoderPlaneSize[(sizeof(MovieDecoderPlane)==0x38)?1:-1];
typedef char MovieDecoderPlaneWidthOffset[((unsigned int)&((MovieDecoderPlane*)0)->width==0x28)?1:-1];
typedef char MovieDecoderPlaneShiftOffset[((unsigned int)&((MovieDecoderPlane*)0)->horizontalShift==0x30)?1:-1];
extern "C" void fn_80290EE8(MovieDecoderPrefix*,int,unsigned char,unsigned char);
#endif
