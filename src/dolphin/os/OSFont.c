typedef unsigned short u16;
volatile u16 __VIRegs[59] : 0xCC002000;
#define VI_DTV_STAT 55
#define VI_NTSC 0
#define VI_PAL 1
#define VI_MPAL 2
#define VI_DEBUG 3
#define VI_DEBUG_PAL 4
#define VI_EURGB60 5
#define OS_FONT_ENCODE_ANSI 0
#define OS_FONT_ENCODE_SJIS 1
#define OSPhysicalToCached(addr) ((void *)((unsigned long)(addr) + 0x80000000))

unsigned short OSGetFontEncode(void) {
    static u16 fontEncode = 0xFFFF;
    if (fontEncode <= 1) {
        return fontEncode;
    }
    switch (*(int*)OSPhysicalToCached(0xCC)) {
    case VI_NTSC:
        fontEncode = (__VIRegs[VI_DTV_STAT] & 2) ? OS_FONT_ENCODE_SJIS : OS_FONT_ENCODE_ANSI;
        break;

    case VI_PAL:
    case VI_MPAL:
    case VI_DEBUG:
    case VI_DEBUG_PAL:
    case VI_EURGB60:
    default:
        fontEncode = OS_FONT_ENCODE_ANSI;
    }

    return fontEncode;
}

