/* Draw a string with the 8x8 debug font (DEMOPuts-style): one GX quad per
   printable character, texture cells offset by the font shift lbl_80378178,
   with newlines advancing y by 8. Used by the disc error screen fn_8028EA98. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef signed short s16;
typedef signed long s32;
typedef float f32;

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
    s16 s16;
    s32 s32;
    f32 f32;
} PPCWGPipe;

volatile PPCWGPipe GXWGFifo : 0xCC008000;

void GXClearVtxDesc(void);
void GXSetVtxDesc(int attr, int type);
void GXSetVtxAttrFmt(int fmt, int attr, int cnt, int type, unsigned char frac);
void GXBegin(int type, int fmt, unsigned short count);
extern s32 lbl_80378178;

static inline void GXPosition3s16(const s16 x, const s16 y, const s16 z)
{
    GXWGFifo.s16 = x;
    GXWGFifo.s16 = y;
    GXWGFifo.s16 = z;
}

static inline void GXTexCoord2s16(const s16 s, const s16 t)
{
    GXWGFifo.s16 = s;
    GXWGFifo.s16 = t;
}

static inline void GXEnd(void) {}

void fn_8028E8E8(s16 x, s16 y, s16 z, char* string)
{
    char* str;
    s32 s;
    s32 t;
    s32 c;
    s32 w;
    s32 len;
    s32 i;

    str = string;
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(13, 1);
    GXSetVtxAttrFmt(0, 9, 1, 3, 0);
    GXSetVtxAttrFmt(0, 13, 1, 3, 1);
    len = 0;
    while (1) {
        c = *str++;
        if (' ' <= c && c <= 0x7F) {
            len++;
        } else {
            if (len > 0) {
                GXBegin(0x80, 0, len * 4);
                for (i = 0; i < len; i++) {
                    w = string[i] - ' ';
                    s = lbl_80378178 + ((w % 8) * 16);
                    t = lbl_80378178 + ((w / 8) * 16);
                    GXPosition3s16(x + (i * 8), y, z);
                    GXTexCoord2s16(s, t);
                    GXPosition3s16(x + (i * 8) + 8, y, z);
                    GXTexCoord2s16(s + 16, t);
                    GXPosition3s16(x + (i * 8) + 8, y + 8, z);
                    GXTexCoord2s16(s + 16, t + 16);
                    GXPosition3s16(x + (i * 8), y + 8, z);
                    GXTexCoord2s16(s, t + 16);
                }
                GXEnd();
                len = 0;
            }
            string = str;
            if (c == '\n') {
                y += 8;
            } else {
                break;
            }
        }
    }
}
