#include "Game/movie_decoder_layout.h"
extern "C" void fn_80294FB4()
{
    fn_80290B88();
}

extern "C" void fn_80294FD4(MovieDecoderPrefix*decoder,const MovieDecoderDimensions*info)
{
    decoder->width=info->width;
    decoder->height=info->height;
    decoder->horizontalMode=info->horizontalMode;
    decoder->verticalMode=info->verticalMode;
}
extern "C" int fn_80294FF8(const MovieDecoderPrefix*decoder)
{
    int width=decoder->width/4;
    int chromaWidth=decoder->horizontalMode==2?width>>1:width;
    int height=decoder->height/4;
    int chromaHeight=decoder->verticalMode==2?height>>1:height;
    return ((width+2)*(height+2)+((chromaWidth+2)*(chromaHeight+2))*2)*2+0x6CD8;
}
