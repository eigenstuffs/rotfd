#include "Game/platform_disc_display_internal.h"

// Fixed array extents preserve the original message alignment and terminators.
extern "C" const char lbl_802AF908[24]="An error has occurred.";
static const char message_18[20]="Turn the power off";
static const char message_2C[16]="and refer to";
static const char message_3C[24]="the Nintendo GameCube";
static const char message_54[20]="Instruction Booklet";
static const char message_68[28]="for further instructions.";
static const char message_84[36]="The Game Disc could not be read.";
static const char message_A8[12]="Please read";
static const char message_B4[24]="for more information.";
static const char message_CC[28]="Please insert the SpongeBob";
static const char message_E8[28]="SquarePants Revenge of the";
static const char message_104[28]="Flying Dutchman Game Disc.";
static const char message_120[24]="The Disc Cover is open.";
static const char message_138[36]="If you want to continue the game,";
static const char message_15C[32]="please close the Disc Cover.";

// Draw the fallback disc error screen when no application callback is installed.
extern "C" void fn_8028EA98(int event)
{
    DiscDisplayGame*game=reinterpret_cast<DiscDisplayGame*>(lbl_801E9D24.game);
    game->slot18();
        fn_801EBB9C();
    DiscWaitHandle empty;
    lbl_801E9D24.game->setPicture(empty);
    DiscDisplayMtx position;
        DiscDisplayMtx44 projection;
        DiscDisplayMtx texMtx;
    DiscDisplayGame*dimensions=reinterpret_cast<DiscDisplayGame*>(lbl_801E9D24.game);
    MTXOrtho(projection,lbl_8037B968,float(int((unsigned short)(u32(dimensions->height)>>1))),lbl_8037B968,float(int((unsigned short)(u32(dimensions->width)>>1))),lbl_8037B968,lbl_8037B978);
    GXSetProjection(projection,1);
    fn_800F6D0C(position);
        GXLoadPosMtxImm(position,0);
        GXSetCurrentMtx(0);
    GXSetZMode(1,7,1);
        GXSetNumChans(0);
        GXSetNumTevStages(1);
        GXSetTevOp(0,3);
        GXSetTevOrder(0,0,0,255);
    GXInitTexObj(lbl_80373120,lbl_802F1700,64,96,0,0,0,0);
    GXInitTexObjLOD(lbl_80373120,0,0,lbl_8037B968,lbl_8037B968,lbl_8037B968,0,0,0);
    lbl_80378178=0;
        GXLoadTexObj(lbl_80373120,0);
    fn_800F6E34(texMtx,lbl_8037B96C,lbl_8037B970,lbl_8037B974);
        GXLoadTexMtxImm(texMtx,30,1);
    GXSetNumTexGens(1);
        GXSetTexCoordGen2(0,1,4,30,0,125);
        GXSetBlendMode(1,1,0,0);
        switch (event) {
        case 0:
        fn_8028E8E8(30,90,0,message_120);
        fn_8028E8E8(30,105,0,message_138);
        fn_8028E8E8(30,120,0,message_15C);
        break;
        case 1:
        fn_8028E8E8(30,90,0,message_CC);
        fn_8028E8E8(30,105,0,message_E8);
        fn_8028E8E8(30,120,0,message_104);
        break;
        case 2:
        fn_8028E8E8(30,90,0,message_CC);
        fn_8028E8E8(30,105,0,message_E8);
        fn_8028E8E8(30,120,0,message_104);
        break;
        case 3:
        fn_8028E8E8(30,75,0,message_84);
        fn_8028E8E8(30,90,0,message_A8);
        fn_8028E8E8(30,105,0,message_3C);
        fn_8028E8E8(200,100,0,lbl_8037B988);
        fn_8028E8E8(30,120,0,message_54);
        fn_8028E8E8(30,135,0,message_B4);
        break;
        case 4:
        fn_8028E8E8(30,75,0,lbl_802AF908);
        fn_8028E8E8(30,90,0,message_18);
        fn_8028E8E8(30,105,0,message_2C);
        fn_8028E8E8(30,120,0,message_3C);
        fn_8028E8E8(200,115,0,lbl_8037B988);
        fn_8028E8E8(30,135,0,message_54);
        fn_8028E8E8(30,150,0,message_68);
        game->slot1C();
        while (1) {}
    }
    game->slot1C();
}
