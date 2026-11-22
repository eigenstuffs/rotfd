#include "recovered/w3_8_movie.h"



static inline void copyA(unsigned char* row, int width, unsigned int* data)
{
    unsigned int w0 = data[0];
    unsigned int w1 = data[1];
    unsigned int w2 = data[2];
    unsigned int w3 = data[3];
    *(unsigned int*)row = w0;
    row += width;
    *(unsigned int*)row = w1;
    row += width;
    *(unsigned int*)row = w2;
    row += width;
    *(unsigned int*)row = w3;
}
static inline void copyB(unsigned char* row, unsigned int* data, int width)
{
    unsigned int w0 = data[0];
    unsigned int w1 = data[1];
    unsigned int w2 = data[2];
    unsigned int w3 = data[3];
    *(unsigned int*)row = w0;
    row += width;
    *(unsigned int*)row = w1;
    row += width;
    *(unsigned int*)row = w2;
    row += width;
    *(unsigned int*)row = w3;
}
// count == 6: raw 4x4 copy from the stream
static inline void copyStreamBlock(MovieDecoderContext* ctx, int idx, unsigned char* row, int width)
{
    MovieDecoderStream* stream = &ctx->streams[idx];
    unsigned int* data = (unsigned int*)stream->data;
    unsigned int w0 = data[0];
    unsigned int w1 = data[1];
    unsigned int w2 = data[2];
    unsigned int w3 = data[3];
    *(unsigned int*)row = w0;
    row += width;
    *(unsigned int*)row = w1;
    row += width;
    *(unsigned int*)row = w2;
    row += width;
    *(unsigned int*)row = w3;
    stream->data = (unsigned char*)(data + 4);
}
static inline void accumulateBlocks(MovieDecoderContext* ctx, int* s, unsigned char n, int stride, int idx, int dead0, int dead1)
{
    int acc;
    unsigned char smp[16];
    s[0] = s[1] = s[2] = s[3] = s[4] = s[5] = s[6] = s[7] = s[8] = s[9] = s[10] = s[11] = s[12] = s[13] = s[14] = s[15] = acc = 0;
    dead0 = 0; // assigned dead parameters keep their stack words (target 0x1c/0x20)
    dead1 = 0;
    while (n--) {
        int w = fn_80292258(ctx, smp, &acc, &ctx->transposed + 1, stride, idx);
        s[0] += w * smp[0];
        s[1] += w * smp[1];
        s[2] += w * smp[2];
        s[3] += w * smp[3];
        s[4] += w * smp[4];
        s[5] += w * smp[5];
        s[6] += w * smp[6];
        s[7] += w * smp[7];
        s[8] += w * smp[8];
        s[9] += w * smp[9];
        s[10] += w * smp[10];
        s[11] += w * smp[11];
        s[12] += w * smp[12];
        s[13] += w * smp[13];
        s[14] += w * smp[14];
        s[15] += w * smp[15];
    }
}
extern "C" void fn_80291D20(MovieDecoderContext* ctx, unsigned char* out, int stride,
    unsigned char dc, unsigned char count, int idx)
{
    int shift;
    int base;
    int s[16];
    int unused; // dead stack word above s (target 0x90)
    if (count == 6) {
        copyStreamBlock(ctx, idx, out, stride);
        return;
    }
    shift = ctx->shift;
    base = dc << shift;
    if (count == 1) {
        int st = *(unsigned short*)ctx->unknown625C;
        unsigned char smp[16];
        int acc = 0;
        int w = fn_80292258(ctx, smp, &acc, &ctx->transposed + 1, st, idx);
        s[0] = w * smp[0];
        s[1] = w * smp[1];
        s[2] = w * smp[2];
        s[3] = w * smp[3];
        s[4] = w * smp[4];
        s[5] = w * smp[5];
        s[6] = w * smp[6];
        s[7] = w * smp[7];
        s[8] = w * smp[8];
        s[9] = w * smp[9];
        s[10] = w * smp[10];
        s[11] = w * smp[11];
        s[12] = w * smp[12];
        s[13] = w * smp[13];
        s[14] = w * smp[14];
        s[15] = w * smp[15];
        base -= (s[0] + s[1] + s[2] + s[3] + s[4] + s[5] + s[6] + s[7] + s[8] + s[9] + s[10] + s[11] + s[12] + s[13] + s[14] + s[15]) >> 4;
    } else {
        accumulateBlocks(ctx, s, count, *(unsigned short*)ctx->unknown625C, idx, 0, 0);
        base -= (s[0] + s[1] + s[2] + s[3] + s[4] + s[5] + s[6] + s[7] + s[8] + s[9] + s[10] + s[11] + s[12] + s[13] + s[14] + s[15]) >> 4;
    }
    {
        unsigned char* clamp = lbl_80373140.clamp + 128;
        out[0] = clamp[(s[0] + base) >> shift];
        out[1] = clamp[(s[1] + base) >> shift];
        out[2] = clamp[(s[2] + base) >> shift];
        out[3] = clamp[(s[3] + base) >> shift];
        out += stride;
        out[0] = clamp[(s[4] + base) >> shift];
        out[1] = clamp[(s[5] + base) >> shift];
        out[2] = clamp[(s[6] + base) >> shift];
        out[3] = clamp[(s[7] + base) >> shift];
        out += stride;
        out[0] = clamp[(s[8] + base) >> shift];
        out[1] = clamp[(s[9] + base) >> shift];
        out[2] = clamp[(s[10] + base) >> shift];
        out[3] = clamp[(s[11] + base) >> shift];
        out += stride;
        out[0] = clamp[(s[12] + base) >> shift];
        out[1] = clamp[(s[13] + base) >> shift];
        out[2] = clamp[(s[14] + base) >> shift];
        out[3] = clamp[(s[15] + base) >> shift];
    }
}

extern "C" int fn_80292258(MovieDecoderContext* ctx, unsigned char* out, int* acc,
    unsigned char* base, int stride, int idx)
{
    unsigned short code = *ctx->streams[idx].data++ << 8;
    code |= *ctx->streams[idx].data++;
    int step;
    int rowStride;
    int min;
    unsigned char* p;
    int max;
    int v;
    unsigned char* row;
    if (ctx->transposed) {
        row = (code & 63) + ((code >> 6) & 31) * stride + base;
        step = 1 << ((code >> 11) & 1);
        rowStride = stride << ((code >> 12) & 1);
    } else {
        row = ((code >> 6) & 31) + (code & 63) * stride + base;
        step = 1 << ((code >> 12) & 1);
        rowStride = stride << ((code >> 11) & 1);
    }
#define PIXEL(k) v = *p & 255; out[k] = v; if (v > max) max = v; else if (v < min) min = v;
    p = row;
    v = *p & 255;
    out[0] = v;
    max = min = v;
    p += step;
    PIXEL(1)
    p += step;
    PIXEL(2)
    p += step;
    PIXEL(3)
    row += rowStride;
    p = row;
    PIXEL(4)
    p += step;
    PIXEL(5)
    p += step;
    PIXEL(6)
    p += step;
    PIXEL(7)
    row += rowStride;
    p = row;
    PIXEL(8)
    p += step;
    PIXEL(9)
    p += step;
    PIXEL(10)
    p += step;
    PIXEL(11)
    row += rowStride;
    p = row;
    PIXEL(12)
    p += step;
    PIXEL(13)
    p += step;
    PIXEL(14)
    p += step;
    PIXEL(15)
#undef PIXEL
    *acc += readSymbolIdx(ctx, idx);
    if (code & 0x8000)
        return (*acc + ((code >> 13) & 3)) * -lbl_80373340[max - min];
    return (*acc + ((code >> 13) & 3)) * lbl_80373340[max - min];
}

