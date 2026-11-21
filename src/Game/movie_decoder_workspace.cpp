#include "Game/movie_decoder_workspace.h"
#define PTR(o) (*(unsigned char**)(workspace+(o)))
#define HALF(o) (*(unsigned short*)(workspace+(o)))
extern "C" void fn_8029506C(MovieDecoderPrefix*decoder,unsigned char*workspace)
{
    decoder->workspace=workspace;
    fn_80290EE8(decoder,0,1,1);
    fn_80290EE8(decoder,1,decoder->horizontalMode,decoder->verticalMode);
    fn_80290EE8(decoder,2,decoder->horizontalMode,decoder->verticalMode);
    unsigned char wide=(unsigned int)decoder->width>=(unsigned int)decoder->height;
    workspace[0x6260]=wide;
    if(wide){HALF(0x625C)=0x46;HALF(0x625E)=0x26;}
    else{HALF(0x625C)=0x26;HALF(0x625E)=0x46;}
    PTR(0x61B0)=workspace+0x30C0;
    PTR(0x619C)=workspace+0x30C0;
    PTR(0x61D8)=workspace+0x10B0;
    PTR(0x61C4)=workspace+0x10B0;
    PTR(0x6110)=workspace+0xA8;
    PTR(0x60FC)=workspace+0xA8;
    PTR(0x60E8)=workspace+0xA8;
    PTR(0x614C)=workspace+0x10B0;
    PTR(0x6138)=workspace+0x10B0;
    PTR(0x6124)=workspace+0x10B0;
    PTR(0x6188)=workspace+0x20B8;
    PTR(0x6174)=workspace+0x20B8;
    PTR(0x6160)=workspace+0x20B8;
    PTR(0x6230)=workspace+0x40C8;
    PTR(0x621C)=workspace+0x40C8;
    PTR(0x6258)=workspace+0x50D0;
    PTR(0x6244)=workspace+0x50D0;
    MovieDecoderPlane*plane=(MovieDecoderPlane*)workspace;
    unsigned char*buffer=workspace+0x6CD8;
    for(int i=0;i<3;i++,plane++){
        *(unsigned char**)plane->unknown00=buffer;
        *(unsigned char**)(plane->unknown00+4)=buffer+plane->paddedWidth*2+2;
        buffer+=plane->paddedWidth*plane->paddedHeight*2;
        unsigned char*cursor=*(unsigned char**)plane->unknown00;
        int count=plane->paddedWidth;
        for(;count>0;count--){
            cursor[0]=0x7F;cursor[1]=0xFF;cursor+=2;
        }
        cursor=buffer;
        count=plane->paddedWidth;
        for(;count>0;count--){
            cursor[-2]=0x7F;cursor[-1]=0xFF;cursor-=2;
        }
        cursor=*(unsigned char**)plane->unknown00+plane->paddedWidth*2;
        count=plane->paddedHeight-2;
        for(;count>0;count--){
            cursor[0]=0x7F;cursor[1]=0xFF;cursor+=plane->paddedWidth*2;
        }
        cursor=*(unsigned char**)plane->unknown00+plane->paddedWidth*4-2;
        count=plane->paddedHeight-2;
        for(;count>0;count--){
            cursor[0]=0x7F;cursor[1]=0xFF;cursor+=plane->paddedWidth*2;
        }
    }
}
