#include "Game/audio_system_start.h"

typedef unsigned int u32;
struct Voice;
struct AudioPrefix {char unknown00[0x7C];};
struct AudioSystemOwner:AudioPrefix {
    virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
    virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
    virtual void slot28();virtual void slot2C();virtual void setLevel(float);virtual void slot34();virtual void setBalance(float);
    char unknown80[0x388];
    u32 flags408;
    int unknown40C;
    char*voices410;
    char unknown414[0xC];
    char pool420[4];
};
struct Globals {char unknown00[0x110];void*console;};
extern "C" {
extern Globals lbl_801E9D24;
extern const char lbl_802AF448[];
extern float lbl_8035E758[];
extern const float lbl_8037B898,lbl_8037B89C,lbl_8037B8A0,lbl_8037B8AC,lbl_8037B8D0,lbl_8037B8D4;
signed char fn_8023BAF0(AudioSystemOwner*);
float fn_80284DB4(float);
void AIInit(void*);
void AXInit();
void MIXInit();
void fn_80287B50();
void fn_80287B88(Voice*);
void AXRegisterCallback(void(*)());
Voice*AXAcquireVoice(u32,void(*)(Voice*),u32);
void MIXInitChannel(Voice*,u32,u32,int,int,int,int,u32);
void fn_8028AC20(void*);
u32 OSGetSoundMode();
void AXSetMode(u32);
u32 AXGetMaxDspCycles();
void fn_801FA014(void*,const char*,...);
}
static inline void fillAudioTable()
{
    float phase=lbl_8037B898;
    float scale=lbl_8037B8AC;
    float step=lbl_8037B8D0;
    for(int i=0;i<128;++i){
        lbl_8035E758[i]=scale*fn_80284DB4(phase);
        phase+=step;
    }
}
extern "C" int fn_802877DC(AudioSystemOwner*self)
{
    const char*strings=lbl_802AF448;
    if(!fn_8023BAF0(self))return 0;
    fillAudioTable();
    AIInit(0);
    AXInit();
    MIXInit();
    AXRegisterCallback(fn_80287B50);
    for(int i=0;i<32;++i){
        *(Voice**)(self->voices410+i*40+36)=AXAcquireVoice(30,fn_80287B88,0);
        Voice*voice=*(Voice**)(self->voices410+i*40+36);
        if(!voice)return -1;
        MIXInitChannel(voice,0,0,-904,-904,64,127,0);
        *(float*)(self->voices410+i*40)=lbl_8037B898;
        *(float*)(self->voices410+i*40+4)=lbl_8037B898;
        *(float*)(self->voices410+i*40+8)=lbl_8037B898;
        *(float*)(self->voices410+i*40+12)=lbl_8037B89C;
        *(u32*)(self->voices410+i*40+16)=0;
        *(float*)(self->voices410+i*40+20)=lbl_8037B898;
        *(float*)(self->voices410+i*40+24)=lbl_8037B8A0;
    }
    fn_8028AC20(self->pool420);
    self->setLevel(lbl_8037B89C);
    self->setBalance(lbl_8037B89C);
    u32 mode=OSGetSoundMode();
    AXSetMode(0);
    float cycles=AXGetMaxDspCycles();
    fn_801FA014(lbl_801E9D24.console,strings+0x60,(float)cycles/lbl_8037B8D4);
    if(mode==0){
        fn_801FA014(lbl_801E9D24.console,strings+0x7C);
        self->flags408|=2;
    }else{
        fn_801FA014(lbl_801E9D24.console,strings+0x94);
        self->flags408&=~2;
    }
    return 1;
}

typedef char AudioSystemOwnerFlagsOffset[((unsigned int)&((AudioSystemOwner*)0)->flags408==0x408)?1:-1];
typedef char AudioSystemOwnerVoicesOffset[((unsigned int)&((AudioSystemOwner*)0)->voices410==0x410)?1:-1];
typedef char AudioSystemOwnerPoolOffset[((unsigned int)&((AudioSystemOwner*)0)->pool420==0x420)?1:-1];
