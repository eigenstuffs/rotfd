#include "Game/movie_decoder_interframe.h"
static inline void initReader(unsigned char*reader,unsigned int*data)
{
    unsigned int bits=*data;
    *(unsigned int*)(reader+4)=bits;
    if(bits==0)*(unsigned int**)reader=0;
    else *(unsigned int**)reader=data+1;
    *(int*)(reader+12)=-1;
}
extern "C" void fn_80295A04(MovieDecoderPrefix*decoder,MovieDecoderInterframeHeader*frame,unsigned char*output,unsigned char*previous,unsigned char*other)
{
    unsigned char*workspace=(unsigned char*)decoder->workspace;
    workspace[0x6CD0]=frame->mode;
    workspace[0x6CD1]=frame->scale;
    workspace[0x6CD2]=frame->byte02;
    workspace[0x6CD4]=frame->byte03;
    workspace[0x6CD3]=frame->byte04;
    workspace[0x6CD5]=frame->byte05;
    unsigned char*payload=(unsigned char*)frame+0x4C;
    initReader((workspace+0x618C),(unsigned int*)(payload+frame->offsets[0]));
    initReader((workspace+0x61B4),(unsigned int*)(payload+frame->offsets[1]));
    initReader((workspace+0x61A0),(unsigned int*)(payload+frame->offsets[2]));
    initReader((workspace+0x61C8),(unsigned int*)(payload+frame->offsets[3]));
    initReader((workspace+0x60D8),(unsigned int*)(payload+frame->offsets[4]));
    initReader((workspace+0x6150),(unsigned int*)(payload+frame->offsets[5]));
    initReader((workspace+0x61DC),(unsigned int*)(payload+frame->offsets[6]));
    initReader((workspace+0x60EC),(unsigned int*)(payload+frame->offsets[7]));
    initReader((workspace+0x6164),(unsigned int*)(payload+frame->offsets[8]));
    initReader((workspace+0x61EC),(unsigned int*)(payload+frame->offsets[9]));
    initReader((workspace+0x6100),(unsigned int*)(payload+frame->offsets[10]));
    initReader((workspace+0x6178),(unsigned int*)(payload+frame->offsets[11]));
    initReader((workspace+0x61FC),(unsigned int*)(payload+frame->offsets[12]));
    initReader((workspace+0x620C),(unsigned int*)(payload+frame->offsets[13]));
    initReader((workspace+0x6220),(unsigned int*)(payload+frame->offsets[14]));
    initReader((workspace+0x6248),(unsigned int*)(payload+frame->offsets[15]));
    initReader((workspace+0x6234),(unsigned int*)(payload+frame->offsets[16]));
    {
        unsigned int*buffer=*(unsigned int**)(workspace+0x619C);
        lbl_80378180=0;
        lbl_80378184=0;
        buffer[0]=256;
        MovieDecoderBitReader*reader=(MovieDecoderBitReader*)(workspace+0x618C);
        if(reader->bits!=0)buffer[1]=(short)fn_80291004(buffer,reader);
        else buffer[1]=0;
    }
    {
        unsigned int*buffer=*(unsigned int**)(workspace+0x61C4);
        lbl_80378180=0;
        lbl_80378184=0;
        buffer[0]=256;
        MovieDecoderBitReader*reader=(MovieDecoderBitReader*)(workspace+0x61B4);
        if(reader->bits!=0)buffer[1]=(short)fn_80291004(buffer,reader);
        else buffer[1]=0;
    }
    {
        int scale=frame->scale;
        unsigned int*buffer=*(unsigned int**)(workspace+0x60E8);
        lbl_80378180=1;
        lbl_80378184=scale;
        buffer[0]=256;
        MovieDecoderBitReader*reader=(MovieDecoderBitReader*)(workspace+0x60D8);
        if(reader->bits!=0)buffer[1]=(short)fn_80291004(buffer,reader);
        else buffer[1]=0;
    }
    {
        unsigned int*buffer=*(unsigned int**)(workspace+0x6160);
        lbl_80378180=0;
        lbl_80378184=2;
        buffer[0]=256;
        MovieDecoderBitReader*reader=(MovieDecoderBitReader*)(workspace+0x6150);
        if(reader->bits!=0)buffer[1]=(short)fn_80291004(buffer,reader);
        else buffer[1]=0;
    }
    {
        unsigned int*buffer=*(unsigned int**)(workspace+0x621C);
        lbl_80378180=1;
        lbl_80378184=0;
        buffer[0]=256;
        MovieDecoderBitReader*reader=(MovieDecoderBitReader*)(workspace+0x620C);
        if(reader->bits!=0)buffer[1]=(short)fn_80291004(buffer,reader);
        else buffer[1]=0;
    }
    {
        unsigned int*buffer=*(unsigned int**)(workspace+0x6258);
        lbl_80378180=0;
        lbl_80378184=0;
        buffer[0]=256;
        MovieDecoderBitReader*reader=(MovieDecoderBitReader*)(workspace+0x6248);
        if(reader->bits!=0)buffer[1]=(short)fn_80291004(buffer,reader);
        else buffer[1]=0;
    }
    *(int*)(workspace+0x6CC8)=127<<frame->scale;
    *(int*)(workspace+0x6CCC)=-128<<frame->scale;
    fn_80294B78(decoder,output,previous,other);
}
