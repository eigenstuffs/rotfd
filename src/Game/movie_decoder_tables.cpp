#include "Game/movie_decoder_tables.h"
unsigned char lbl_80373140[512];
int lbl_80373340[16];
int lbl_80373380[512];

extern "C" void fn_80290B88()
{
    int i=0;
    for(int value=-128;value<384;i++,value++){
        unsigned char result;
        if(value<0)result=0;
        else if(value>255)result=255;
        else result=(unsigned char)value;
        lbl_80373140[i]=result;
    }
    lbl_80373340[0]=0;
    for(int i=1;i<16;i++)
        lbl_80373340[i]=(4096/(i<<4))<<4;
    lbl_80373380[0]=0;
    for(int i=1;i<512;i++)
        lbl_80373380[i]=4096/i;
}
