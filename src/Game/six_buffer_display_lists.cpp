#include "Game/six_buffer_display_lists.h"

typedef unsigned long Word;
typedef unsigned char Byte;
struct SixDisplayListBuffer {void* data;Word capacity;Word used;};
struct SixDisplayListOwner {char unknown00[0x88];signed char flag;char pad89[3];float uv[8];SixDisplayListBuffer buffers[6];};
extern "C" {
extern char lbl_8028F698[];
extern const float lbl_8037B6C8,lbl_8037B6CC;
void*fn_8028FACC(void*,Word);
void DCInvalidateRange(void*,Word);
void DCStoreRange(void*,Word);
void GXBeginDisplayList(void*,Word);
void GXResetWriteGatherPipe();
void GXBegin(int,int,unsigned short);
Word GXEndDisplayList();
}
static inline void writeVertex(Byte position,Byte texcoord)
{
    *(volatile Byte*)0xCC008000=position;
    *(volatile Byte*)0xCC008000=texcoord;
}
static inline void buildFace(SixDisplayListBuffer& buffer,Byte a,Byte b,Byte c,Byte d,Byte e,Byte f,Byte g,Byte h)
{
    DCInvalidateRange(buffer.data,buffer.capacity);
    GXBeginDisplayList(buffer.data,buffer.capacity);
    GXResetWriteGatherPipe();
    GXBegin(0x98,3,4);
    writeVertex(a,b);
    writeVertex(c,d);
    writeVertex(e,f);
    writeVertex(g,h);
    buffer.used=GXEndDisplayList();
    DCStoreRange(buffer.data,buffer.capacity);
}
extern "C" void fn_802715C8(SixDisplayListOwner*self)
{
    if(self->flag){
        self->uv[0]=lbl_8037B6C8;self->uv[1]=lbl_8037B6C8;
        self->uv[2]=lbl_8037B6CC;self->uv[3]=lbl_8037B6C8;
        self->uv[4]=lbl_8037B6C8;self->uv[5]=lbl_8037B6CC;
        self->uv[6]=lbl_8037B6CC;self->uv[7]=lbl_8037B6CC;
    }
    for(int i=0;i<6;++i){
        self->buffers[i].capacity=64;
        self->buffers[i].data=fn_8028FACC(lbl_8028F698,self->buffers[i].capacity);
    }
    buildFace(self->buffers[0],0,1,3,0,1,3,2,2);
    buildFace(self->buffers[1],4,3,5,1,7,2,6,0);
    buildFace(self->buffers[2],2,3,6,1,1,2,5,0);
    buildFace(self->buffers[3],0,2,1,3,4,0,5,1);
    buildFace(self->buffers[4],3,3,7,1,2,2,6,0);
    buildFace(self->buffers[5],0,3,4,1,3,2,7,0);
}
