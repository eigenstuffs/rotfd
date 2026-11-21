#include "Game/movie_decoder_record.h"
extern "C" void fn_80290EE8(MovieDecoderPrefix*decoder,int index,unsigned char horizontal,unsigned char vertical)
{
    MovieDecoderPlane*plane=(MovieDecoderPlane*)decoder->workspace+index;
    plane->horizontalShift=horizontal==2?1:0;
    plane->width=decoder->width>>plane->horizontalShift;
    plane->verticalShift=vertical==2?1:0;
    plane->height=decoder->height>>plane->verticalShift;
    plane->pixels=plane->width*plane->height;
    plane->horizontalScale=2>>plane->horizontalShift;
    plane->verticalScale=2>>plane->verticalShift;
    plane->scale=plane->horizontalScale*plane->verticalScale;
    plane->blocksWidth=decoder->width/(horizontal*4);
    plane->blocksHeight=decoder->height/(vertical*4);
    plane->paddedWidth=plane->blocksWidth+2;
    plane->paddedHeight=plane->blocksHeight+2;
    plane->word10=0;
    plane->word16=1;
    unsigned short paddedWidth=plane->paddedWidth;
    plane->word12=paddedWidth;
    plane->word14=paddedWidth+1;
    plane->word18=0;
    plane->word24=4;
    unsigned int rowBytes=plane->width*4;
    plane->rowBytes=rowBytes;
    plane->rowBytesPlus4=rowBytes+4;
}
