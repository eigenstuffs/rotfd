#include "Game/engine_card_file_read.h"
#include "Game/card_crc32_table.h"
typedef unsigned int Word;
typedef unsigned char Byte;
struct CardFileReadPrefix {
    char unknown00[0x30];
}
;
struct CardFileReadView:CardFileReadPrefix {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void adjustLength(int*);
    char unknown34[0x324];
    char mutex[24];
    char unknown370[0x48];
    Word sectorSize;
    int memorySize,channel;
    char unknown3C4[0x44];
    void*workArea;
    char unknown40C[8];
    Word bytes414;
    char unknown418[4];
    Word bytes41C;
}
;
struct CardReadFileInfo {
    int channel,fileNo,offset,length;
    unsigned short block;
}
;
struct CardReadStatus {
    char name[32];
    Word length;
    char unknown24[0x4C];
}
;
extern "C" {
    extern char lbl_80341038[],lbl_801EF5C8[];
extern const char lbl_802AF158[];
    extern signed char lbl_80377FC9[1],lbl_80377FC0[1];
    extern struct {
        char unknown00[0x110];
        void*log;
    }
    lbl_801E9D24;
    int OSResumeThread(void*);
    int OSSuspendThread(void*);
    void OSLockMutex(void*);
    void OSUnlockMutex(void*);
    int OSGetResetSwitchState();
    void fn_801FA014(void*,const char*,...);
    int fn_80277918(CardFileReadView*,int);
    int CARDProbeEx(int,int*,Word*);
    int CARDUnmount(int);
    int CARDOpen(int,const char*,CardReadFileInfo*);
    int CARDClose(CardReadFileInfo*);
    int CARDGetStatus(int,int,CardReadStatus*);
    int CARDRead(CardReadFileInfo*,void*,int,int);
    void fn_801EF610(void*,void*);
    void*fn_801EFA1C(void*,Word,const char*,const char*,int,Word);
    void*memcpy(void*,const void*,Word);
}
static inline Word cardReadChecksum(const signed char*data,Word length){
    Word sum=~0U;
    if(data&&length){
        do{
            sum=(sum>>8)^lbl_802ED780[(Byte)(*data++^sum)];
        }
        while(--length);
    }
    return sum^~0U;
}
extern "C" int fn_80278788(CardFileReadView*self,const char*name,void*output,int length){
    const char*messages=lbl_802AF158;
    OSResumeThread(lbl_80341038);
    OSLockMutex(self->mutex);
    int result=fn_80277918(self,0);
    if(result==0||result==1){
        int probe=-1;
        while(probe==-1)probe=CARDProbeEx(self->channel,&self->memorySize,&self->sectorSize);
        result=probe?0:1;
    }
    CARDUnmount(self->channel);
    if(self->workArea){
        fn_801EF610(lbl_801EF5C8,self->workArea);
        self->workArea=0;
    }
    if(result==0){
        OSUnlockMutex(self->mutex);
        OSSuspendThread(lbl_80341038);
        return 1;
    }
    CardReadFileInfo file;
    CardReadStatus stat;
    if(fn_80277918(self,1)==0){
        int attempts=0;
        lbl_80377FC9[0]=OSGetResetSwitchState();
        do{
            result=CARDOpen(self->channel,name,&file);
            ++attempts;
            if(!OSGetResetSwitchState()&&lbl_80377FC9[0]){
                fn_801FA014(lbl_801E9D24.log,messages+0xF4);
                lbl_80377FC0[0]=1;
            }
            lbl_80377FC9[0]=OSGetResetSwitchState();
            if(lbl_80377FC9[0])fn_801FA014(lbl_801E9D24.log,messages+0x114);
        }
        while(result==-1&&attempts<1000);
        if(attempts>=1000)fn_801FA014(lbl_801E9D24.log,messages+0x134);
        if(result==0){
            int adjusted=length;
            self->adjustLength(&adjusted);
            int attempts=0;
            lbl_80377FC9[0]=OSGetResetSwitchState();
            int status;
            do{
                status=CARDGetStatus(self->channel,file.fileNo,&stat);
                ++attempts;
                if(!OSGetResetSwitchState()&&lbl_80377FC9[0]){
                    fn_801FA014(lbl_801E9D24.log,messages+0xF4);
                    lbl_80377FC0[0]=1;
                }
                lbl_80377FC9[0]=OSGetResetSwitchState();
                if(lbl_80377FC9[0])fn_801FA014(lbl_801E9D24.log,messages+0x114);
            }
            while(status==-1&&attempts<1000);
            if(attempts>=1000)fn_801FA014(lbl_801E9D24.log,messages+0x134);
            int actual=status==0?stat.length:file.length;
            if(actual!=adjusted)result=19;
            else{
                signed char*buffer=(signed char*)fn_801EFA1C(lbl_801EF5C8,adjusted,messages+0x4C,messages+0x5C,0x1A1,32);
                if(buffer){
                    int attempts=0;
                    lbl_80377FC9[0]=OSGetResetSwitchState();
                    do{
                        result=CARDRead(&file,buffer,adjusted,0);
                        ++attempts;
                        if(!OSGetResetSwitchState()&&lbl_80377FC9[0]){
                            fn_801FA014(lbl_801E9D24.log,messages+0xF4);
                            lbl_80377FC0[0]=1;
                        }
                        lbl_80377FC9[0]=OSGetResetSwitchState();
                        if(lbl_80377FC9[0])fn_801FA014(lbl_801E9D24.log,messages+0x114);
                    }
                    while(result==-1&&attempts<1000);
                    if(attempts>=1000)fn_801FA014(lbl_801E9D24.log,messages+0x134);
                    if(result==0){
                        Word check=*(Word*)(buffer+adjusted-4);
                        if(check!=cardReadChecksum(buffer,adjusted-4))result=19;
                        else{
                            memcpy(output,(const void*)(self->bytes414+self->bytes41C+0x40+(Word)buffer),length);
                            result=0;
                        }
                    }
                    else result=7;
                    fn_801EF610(lbl_801EF5C8,buffer);
                }
                else result=13;
            }
        }
        CARDClose(&file);
    }
    else result=5;
    CARDUnmount(self->channel);
    if(self->workArea){
        fn_801EF610(lbl_801EF5C8,self->workArea);
        self->workArea=0;
    }
    OSUnlockMutex(self->mutex);
    OSSuspendThread(lbl_80341038);
    return result;
}

typedef char CardReadFileInfoSize[sizeof(CardReadFileInfo) == 20 ? 1 : -1];
typedef char CardReadStatusSize[sizeof(CardReadStatus) == 112 ? 1 : -1];
typedef char CardFileReadViewSize[sizeof(CardFileReadView) == 0x420 ? 1 : -1];
