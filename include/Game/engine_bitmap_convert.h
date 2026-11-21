#ifndef GAME_ENGINE_BITMAP_CONVERT_H
#define GAME_ENGINE_BITMAP_CONVERT_H

/* Partial storage view for the retained bitmap conversion entry. */
typedef unsigned char BitmapConvertByte;
typedef unsigned short BitmapConvertHalf;
typedef unsigned long BitmapConvertWord;

struct BitmapConvertObject {
    char unknown00[12];
    BitmapConvertByte* data;
    BitmapConvertByte* palette;
    char unknown14[28];
    int width, height;
    BitmapConvertWord unknown38;
    BitmapConvertByte format, unknown3D, paletteFormat;
};

extern "C" {
extern char lbl_801EF5C8[], lbl_802AEA60[], lbl_802AEA70[];
void* fn_801EFA1C(void*, int, const char*, const char*, int, int);
BitmapConvertWord* fn_80237CA0(BitmapConvertObject*);
BitmapConvertWord fn_802380D0(BitmapConvertObject*, BitmapConvertWord);
}

#endif
