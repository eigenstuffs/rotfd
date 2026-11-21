#include "Game/engine_bitmap_convert.h"

typedef char BitmapConvertObjectSize[(sizeof(BitmapConvertObject) == 0x40) ? 1 : -1];

extern "C" BitmapConvertWord* fn_80237CA0(BitmapConvertObject* self) {
    BitmapConvertWord* result = (BitmapConvertWord*)fn_801EFA1C(
        lbl_801EF5C8, self->width * self->height * 4,
        lbl_802AEA60, lbl_802AEA70, 0x244, 4);
    switch (self->format) {
    case 1: {
        BitmapConvertByte* out = (BitmapConvertByte*)result;
        for (int i = 0; i < self->width * self->height / 2; ++i) {
            BitmapConvertByte value = self->data[i];
            BitmapConvertByte high = value >> 4, low = value & 15;
            out[0] = self->palette[high * 4];
            out[1] = self->palette[high * 4 + 1];
            out[2] = self->palette[high * 4 + 2];
            out[3] = self->palette[high * 4 + 3];
            out[4] = self->palette[low * 4];
            out[5] = self->palette[low * 4 + 1];
            out[6] = self->palette[low * 4 + 2];
            out[7] = self->palette[low * 4 + 3];
            out += 8;
        }
        break;
    }
    case 2: {
        BitmapConvertByte* in = self->data;
        int a, b, g, r;
        for (unsigned int by = 0; by < self->height / 4; ++by) {
            for (unsigned int bx = 0; bx < self->width / 8; ++bx) {
                for (int y = 0; y < 4; ++y) {
                    for (int x = 0; x < 8; ++x) {
                        BitmapConvertByte index = *in++;
                        if (self->paletteFormat == 3) {
                            BitmapConvertByte* p = self->palette + index * 4;
                            r = p[0]; g = p[1]; b = p[2]; a = p[3];
                        } else if (self->paletteFormat == 2) {
                            BitmapConvertHalf value = ((BitmapConvertHalf*)self->palette)[index];
                            r = (value >> 8) & 0xF8;
                            g = (value >> 3) & 0xFC;
                            b = (value << 3) & 0xF8;
                            a = 255;
                        } else if (self->paletteFormat == 1) {
                            BitmapConvertHalf value = ((BitmapConvertHalf*)self->palette)[index];
                            r = (value >> 4) & 0xF0;
                            g = value & 0xF0;
                            b = (value << 4) & 0xF0;
                            a = (value >> 7) & 0xE0;
                        }
                        result[x + bx * 8 + self->width * (y + by * 4)] =
                            (BitmapConvertWord(BitmapConvertByte(r)) << 16) +
                            (BitmapConvertWord(BitmapConvertByte(g)) << 8) +
                            BitmapConvertByte(b) +
                            (BitmapConvertWord(BitmapConvertByte(a)) << 24);
                    }
                }
            }
        }
        break;
    }
    case 7: {
        BitmapConvertHalf* in = (BitmapConvertHalf*)self->data;
        BitmapConvertByte* out = (BitmapConvertByte*)result;
        for (int i = 0; i < self->width * self->height; ++i) {
            out[0] = (*in >> 7) & 0xF8;
            out[1] = (*in >> 2) & 0xF8;
            out[2] = (*in << 3) & 0xF8;
            out[3] = ((*in >> 15) & 1) * 255;
            ++in;
            out += 4;
        }
        break;
    }
    case 8: {
        BitmapConvertHalf* in = (BitmapConvertHalf*)self->data;
        BitmapConvertByte* out = (BitmapConvertByte*)result;
        for (int i = 0; i < self->width * self->height; ++i) {
            out[0] = (*in >> 8) & 0xF8;
            out[1] = (*in >> 3) & 0xFC;
            out[2] = (*in << 3) & 0xF8;
            out[3] = 255;
            ++in;
            out += 4;
        }
        break;
    }
    case 10: {
        BitmapConvertHalf* in = (BitmapConvertHalf*)self->data;
        BitmapConvertByte* out = (BitmapConvertByte*)result;
        for (int i = 0; i < self->width * self->height; ++i) {
            out[0] = (*in >> 4) & 0xF0;
            out[1] = *in & 0xF0;
            out[2] = (*in << 4) & 0xF0;
            out[3] = (*in >> 8) & 0xF0;
            ++in;
            out += 4;
        }
        break;
    }
    case 13: {
        BitmapConvertByte* in = self->data;
        BitmapConvertByte* out = (BitmapConvertByte*)result;
        for (int i = 0; i < self->width * self->height; ++i) {
            out[0] = in[0]; out[1] = in[1]; out[2] = in[2];
            out[3] = 255;
            in += 3;
            out += 4;
        }
        break;
    }
    case 12: {
        BitmapConvertWord* in = (BitmapConvertWord*)self->data;
        BitmapConvertWord* out = result;
        for (int i = 0; i < self->width * self->height; ++i) {
            *out++ = *in;
            ++in;
        }
        break;
    }
    }
    return result;
}

extern "C" BitmapConvertWord fn_802380D0(BitmapConvertObject* source, BitmapConvertWord index) {
    BitmapConvertByte c0, c1, c2, c3;
    BitmapConvertByte format = source->paletteFormat;
    if (format == 3) {
        BitmapConvertByte* b = source->palette;
        BitmapConvertWord n = index << 2;
        c0 = b[n]; c1 = b[n + 1]; c2 = b[n + 2]; c3 = b[n + 3];
    } else if (format == 2) {
        unsigned short value = ((BitmapConvertHalf*)source->palette)[index];
        c0 = (value >> 8) & 0xf8;
        c1 = (value >> 3) & 0xfc;
        c2 = (value & 0x1f) << 3;
        c3 = 0xff;
    } else if (format == 1) {
        unsigned short value = ((BitmapConvertHalf*)source->palette)[index];
        c0 = (value >> 4) & 0xf0;
        c1 = value & 0xf0;
        c2 = (value & 0xf) << 4;
        c3 = (value >> 7) & 0xe0;
    }
    return (c0 << 16) + (c1 << 8) + c2 + (c3 << 24);
}
