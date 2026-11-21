#ifndef GAME_MOVIE_DECODER_INTERFRAME_H
#define GAME_MOVIE_DECODER_INTERFRAME_H
#include "Game/movie_decoder_frame.h"
struct MovieDecoderInterframeHeader {
    unsigned char scale,mode,byte02,byte03,byte04,byte05,unknown06[2];
    unsigned int offsets[17];
};
typedef char MovieDecoderInterframeHeaderSize[(sizeof(MovieDecoderInterframeHeader)==0x4C)?1:-1];
typedef char MovieDecoderInterframeOffsetsOffset[((unsigned int)&((MovieDecoderInterframeHeader*)0)->offsets==8)?1:-1];
extern "C" {
void fn_80295A04(MovieDecoderPrefix*,MovieDecoderInterframeHeader*,unsigned char*,unsigned char*,unsigned char*);
void fn_80294B78(MovieDecoderPrefix*,unsigned char*,unsigned char*,unsigned char*);
}
#endif
