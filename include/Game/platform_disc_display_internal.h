#ifndef GAME_PLATFORM_DISC_DISPLAY_INTERNAL_H
#define GAME_PLATFORM_DISC_DISPLAY_INTERNAL_H
#include "Game/platform_disc_wait_internal.h"

struct DiscDisplayGame : DiscWaitGame {
    char unknown27C[0x1C];
    unsigned short width;
    char unknown29A[2];
    unsigned short height;
};
typedef float DiscDisplayMtx[3][4];
typedef float DiscDisplayMtx44[4][4];
extern "C" {
 extern const float lbl_8037B968,lbl_8037B96C,lbl_8037B970,lbl_8037B974,lbl_8037B978;
 extern const char lbl_8037B988[3];
 extern char lbl_80373120[],lbl_802F1700[];
 extern u32 lbl_80378178;
 void MTXOrtho(DiscDisplayMtx44,float,float,float,float,float,float);
 void GXSetProjection(const float(*)[4],int);
 void fn_800F6D0C(DiscDisplayMtx);
 void GXLoadPosMtxImm(const float(*)[4],u32);
 void GXSetCurrentMtx(u32);
 void GXSetZMode(int,int,int);
 void GXSetNumChans(unsigned char);
 void GXSetNumTevStages(unsigned char);
 void GXSetTevOp(int,int);
 void GXSetTevOrder(int,int,int,int);
 void GXInitTexObj(void*,void*,unsigned short,unsigned short,int,int,int,unsigned char);
 void GXInitTexObjLOD(void*,int,int,float,float,float,unsigned char,unsigned char,int);
 void GXLoadTexObj(void*,int);
 void fn_800F6E34(DiscDisplayMtx,float,float,float);
 void GXLoadTexMtxImm(const float(*)[4],u32,int);
 void GXSetNumTexGens(unsigned char);
 void GXSetTexCoordGen2(int,int,int,u32,int,u32);
 void GXSetBlendMode(int,int,int,int);
 void fn_8028E8E8(int,int,int,const char*);
 void fn_8028EA98(int);
}
typedef char CheckDiscDisplayGame[sizeof(DiscDisplayGame)==0x2A0?1:-1];
#endif
