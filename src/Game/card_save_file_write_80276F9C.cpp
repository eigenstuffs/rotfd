// Memory-card save write: create the file, assemble and checksum the image,
// write it asynchronously and update the banner/icon status.
typedef unsigned int Word;
typedef unsigned short Half;
typedef unsigned char Byte;
struct CardWritePrefix {
    char unknown00[0x30];
};
struct CardIconRecord {
    Word format;
    Word speed;
    const char* name;
};
struct CardWriteView : CardWritePrefix {
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
    char unknown34[0x38C];
    int channel;
    char unknown3C4[0x54];
    Word bannerFormat418;
    char unknown41C[8];
    Word count424;
    CardIconRecord records428[8];
    char unknown488[0x40];
    Word iconAnim4C8;
};
struct CardWriteFileInfo {
    int channel, fileNo, offset, length;
    Half block, padding;
};
struct CardWriteStatus {
    char fileName[32];
    Word length;
    Word time;
    Byte gameName[4];
    Byte company[2];
    Byte bannerFormat;
    Byte padding;
    Word iconAddr;
    Half iconFormat;
    Half iconSpeed;
    Word commentAddr;
    Word offsetBanner;
    Word offsetBannerTlut;
    Word offsetIcon[8];
    Word offsetIconTlut;
    Word offsetData;
};
extern "C" {
extern char lbl_801EF5C8[];
extern const char lbl_802AF158[];
extern unsigned int lbl_802ED780[256];
extern signed char lbl_80377FC9[1], lbl_80377FC0[1];
extern signed char lbl_80377510;
extern signed char lbl_803780C8;
extern int lbl_803780CC;
extern struct { char unknown00[0x110]; void* log; } lbl_801E9D24;
int OSGetResetSwitchState();
void fn_801FA014(void*, const char*, ...);
int CARDCreate(int, const char*, Word, CardWriteFileInfo*);
int CARDClose(CardWriteFileInfo*);
int CARDWriteAsync(CardWriteFileInfo*, const void*, int, int, void (*)(int, int));
int CARDGetStatus(int, int, CardWriteStatus*);
int CARDSetStatus(int, int, CardWriteStatus*);
void fn_80277390(int, int);
void fn_802773A0(CardWriteView*, const void*, int, void*);
void fn_801EF610(void*, void*);
void* fn_801EFA1C(void*, Word, const char*, const char*, int, Word);
void* memset(void*, int, Word);
}
static inline Word cardWriteChecksum(const signed char* data, Word length) {
    Word sum = ~0U;
    if (data && length) {
        do {
            sum = (sum >> 8) ^ lbl_802ED780[(Byte)(*data++ ^ sum)];
        } while (--length);
    }
    return sum ^ ~0U;
}
static inline int writeStatus(int written) {
    switch (written) {
    case 0:
        return 0;
    case -3:
        return 1;
    case -4: // needed: makes the compare tree test -3 first
    default:
        return 5;
    }
}
static inline int updateStatus(CardWriteView* self, int fileNo, int status) {
    CardWriteStatus stat;
    if (CARDGetStatus(self->channel, fileNo, &stat) == 0) {
        stat.bannerFormat = (Byte)((stat.bannerFormat & ~3) | self->bannerFormat418);
        stat.commentAddr = 0;
        stat.bannerFormat = (Byte)((stat.bannerFormat & ~4) | self->iconAnim4C8);
        stat.iconAddr = 0x40;
        for (Word i = 0; i < self->count424; ++i) {
            stat.iconFormat = (Half)((stat.iconFormat & ~(3 << (2 * i))) | (self->records428[i].format << (2 * i)));
            stat.iconSpeed = (Half)((stat.iconSpeed & ~(3 << (2 * i))) | (self->records428[i].speed << (2 * i)));
        }
        CARDSetStatus(self->channel, fileNo, &stat);
    }
    return status;
}
extern "C" int fn_80276F9C(CardWriteView* self, const char* name, const void* data, int length) {
    const char* messages = lbl_802AF158;
    int written;
    int attempts;
    int result;
    signed char* buffer;
    int adjusted = length;
    CardWriteFileInfo file;
    self->adjustLength(&adjusted);
    file.length = adjusted;
    attempts = 0;
    lbl_80377FC9[0] = OSGetResetSwitchState();
    do {
        result = CARDCreate(self->channel, name, adjusted, &file);
        ++attempts;
        if (!OSGetResetSwitchState() && lbl_80377FC9[0]) {
            fn_801FA014(lbl_801E9D24.log, messages + 0xF4);
            lbl_80377FC0[0] = 1;
        }
        lbl_80377FC9[0] = OSGetResetSwitchState();
        if (lbl_80377FC9[0])
            fn_801FA014(lbl_801E9D24.log, messages + 0x114);
    } while (result == -1 && attempts < 1000);
    if (attempts >= 1000)
        fn_801FA014(lbl_801E9D24.log, messages + 0x134);
    switch (result) {
    case 0:
        break;
    case -3:
        return 1;
    case -8:
        fn_801FA014(lbl_801E9D24.log, messages + 0x14C);
        return 13;
    case -9:
        fn_801FA014(lbl_801E9D24.log, messages + 0x160);
        return 13;
    case -5: // needed: fifth case makes the compiler emit the jump table
    default:
        return 6;
    }
    buffer = (signed char*)fn_801EFA1C(lbl_801EF5C8, adjusted, messages + 0x4C, messages + 0x5C, 0x517, 32);
    if (!buffer) {
        CARDClose(&file);
        return 13;
    }
    memset(buffer, 0, adjusted);
    fn_802773A0(self, data, length, buffer);
    *(Word*)(buffer + adjusted - 4) = cardWriteChecksum(buffer, adjusted - 4);
    lbl_80377510 = 0;
    fn_801FA014(lbl_801E9D24.log, messages + 0x178);
    lbl_803780C8 = 0;
    CARDWriteAsync(&file, buffer, adjusted, 0, fn_80277390);
    lbl_80377FC9[0] = OSGetResetSwitchState();
    for (;;) {
        if (lbl_803780C8)
            break;
        if (!OSGetResetSwitchState() && lbl_80377FC9[0]) {
            fn_801FA014(lbl_801E9D24.log, messages + 0xF4);
            lbl_80377FC0[0] = 1;
        }
        lbl_80377FC9[0] = OSGetResetSwitchState();
        if (lbl_80377FC9[0])
            fn_801FA014(lbl_801E9D24.log, messages + 0x114);
    }
    written = lbl_803780CC;
    fn_801FA014(lbl_801E9D24.log, messages + 0x18C);
    CARDClose(&file);
    fn_801EF610(lbl_801EF5C8, buffer);
    lbl_80377510 = 1;
    return updateStatus(self, file.fileNo, writeStatus(written));
}
