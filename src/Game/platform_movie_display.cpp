#include "Game/platform_movie_display_internal.h"
static inline void fill(u32*first,u32*last,u32 value)
{
    for (; first<last;first++)*first=value;
}
extern "C" void* fn_8028D8BC(void*)
{
    char* base=lbl_8036E9D0;
    MovieDisplayGlobals*globals=(MovieDisplayGlobals*)&lbl_801E9D24;
    MovieDecodeMode*mode;
    int frames=0;
    mode=&lbl_8037814C;
    while(1){
        OSWaitSemaphore(base+0x4630);
        switch(mode->format){
        case 0x10: {
            u32*temp=lbl_80378110;
            lbl_80378110=lbl_8037810C;
            lbl_8037810C=temp;
            fn_802954D0(base+0x4700,lbl_80378154,lbl_80378108,temp);
            temp=lbl_80378108;
            lbl_80378108=lbl_8037810C;
            lbl_8037810C=temp;
            break;
        }
        case 0x20: {
            u32*temp=lbl_8037810C;
            u32*other=lbl_80378110;
            lbl_80378110=temp;
            lbl_8037810C=other;
            fn_802959E0(base+0x4700,lbl_80378154,lbl_80378108,lbl_80378110);
            temp=lbl_80378108;
            lbl_80378108=lbl_8037810C;
            lbl_8037810C=temp;
            break;
        }
        case 0x30:
            fn_80295A04(base+0x4700,lbl_80378154,lbl_80378108,lbl_80378110,lbl_8037810C);
            break;
        }
        OSSignalSemaphore(base+0x463C);
        if(mode->format!=0x30){
            lbl_803780F8=lbl_80378128[lbl_803780FC];
            lbl_803780FC=1-lbl_803780FC;
        }
        int index=lbl_803780FC;
        u32*framebuffer=lbl_803780F8;
        lbl_80378114=lbl_80378108;
        if(((int*)lbl_803780F0)[index]){
            fill(framebuffer,(u32*)((char*)framebuffer+lbl_80378104),(u32)0x00800080);
            DCFlushRangeNoSync(framebuffer,lbl_80378104);
            lbl_803780F0[index]=0;
        }
        MovieVideoModePrefix*video=(MovieVideoModePrefix*)lbl_80378120;
        lbl_80378100=video->width*((video->height-lbl_8037811C)>>1)*2+((video->width-lbl_80378118)&~1UL);
        fn_8028DB38((char*)framebuffer+lbl_80378100,lbl_80378114,lbl_80378118,lbl_8037811C);
        lbl_803780E8=0;
        if(frames==4){
            globals->platform->black=0;
            GXSetColorUpdate(0);
            VISetBlack(0);
        }
        lbl_80378158++;
        frames++;
        if(lbl_80378158!=6){
            PPCSync();
            VISetNextFrameBuffer(framebuffer);
            lbl_80378114=0;
            VIFlush();
        }else{
            lbl_80378158=0;
        }
        MovieFrameCallback*callback=globals->callback;
        callback->tick(lbl_8037B91C);
    }
}
