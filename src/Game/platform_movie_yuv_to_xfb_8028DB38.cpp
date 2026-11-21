typedef unsigned char u8;
typedef unsigned long u32;
extern "C" void DCFlushRangeNoSync(void*,u32);
static inline u32 pack(u8* u, u8* y, u8* v, int i)
{
    return ((u32)y[i*2]<<24)|((u32)u[i]<<16)|((u32)y[i*2+1]<<8)|v[i];
}
static inline void packLine(u32*output,u8*y,u8*u,u8*v)
{
    u32 a=pack(u,y,v,0);
    u32 b=pack(u,y,v,1);
    u32 c=pack(u,y,v,2);
    u32 d=pack(u,y,v,3);
    output[0]=a;output[1]=b;output[2]=c;output[3]=d;
}
extern "C" void fn_8028DB38(u8* dest, u8* input, u32 width, u32 height)
{
    u8* u=input+width*height;
    u8* v=u+(width>>1)*(height>>1);
    u8* y=input;
    u8* line=dest;
    int rows;
    for(rows=height>>1;rows>0;rows--){
        u8* end=line+(width>>1)*4;
        u32* cursor=(u32*)line;
        u8* yTop=y;
        y+=width;
        while((u8*)cursor<end){
            packLine(cursor,yTop,u,v);
            packLine((u32*)((u8*)cursor+0x500),y,u,v);
            yTop+=8;u+=4;v+=4;y+=8;cursor+=4;
        }
        DCFlushRangeNoSync(line,width*2);
        DCFlushRangeNoSync(line+0x500,width*2);
        line+=0xA00;
    }
}
