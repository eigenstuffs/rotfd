// w18: fn_80293574 takes its block count as an int here (the shared header and
// the matched callers declare it unsigned char; C linkage, same register), so
// the header prototype is renamed out of the way for this file only.
#define fn_80293574 fn_80293574_header_proto
#include "recovered/w3_8_movie.h"
#undef fn_80293574

extern "C" void fn_80293158(MovieDecoderContext* ctx, MovieOutputRecord* records, int mode, int option)
{
    unsigned char* source;
    unsigned char flag = (option << 5) | (mode << 4);
    if (mode == 1) {
        int count; unsigned short* list; int i; int j;
        MovieDecoderPlane* plane = ctx->planes;
        MovieOutputRecord* record = records;
        for (i = 0; i < 3; i++) {
            count = plane->count;
            list = plane->blockIndex;
            source = record->source;
            for (j = 0; j < count; j++)
                source[*list++ * 2 + 1] = flag;
            record++;
            plane++;
        }
    } else {
        unsigned short* list; unsigned char* source0; MovieDecoderBitReader* values; MovieDecoderBitReader* runs; int count; int j;
        count = ctx->planes[0].count;
        source0 = records[0].source;
        values = &ctx->basisCounts[0];
        runs = &ctx->basisRuns[0];
        list = ctx->planes[0].blockIndex;
        for (j = 0; j < count; j++) {
            int index = *list++;
            if (records[0].run == 0) {
                short v = readSymbol(values);
                if (v == 0) {
                    source0[index * 2 + 1] = flag;
                    records[0].run = readSymbol(runs);
                } else {
                    source0[index * 2 + 1] = flag | v;
                }
            } else {
                source0[index * 2 + 1] = flag;
                records[0].run--;
            }
        }
        {
        unsigned short* list; MovieDecoderBitReader* values; MovieDecoderBitReader* runs; unsigned char* source1; unsigned char* source2; int count; MovieDecoderPlane* plane; int j;
        plane = &ctx->planes[1];
        source1 = records[1].source;
        count = plane->count;
        source2 = records[2].source;
        values = &ctx->basisCounts[1];
        runs = &ctx->basisRuns[1];
        list = plane->blockIndex;
        for (j = 0; j < count; j++) {
            int index = *list++;
            if (records[1].run == 0) {
                short v = readSymbol(values);
                if (v == 0) {
                    source1[index * 2 + 1] = flag;
                    source2[index * 2 + 1] = flag;
                    records[1].run = readSymbol(runs);
                } else {
                    source1[(index = index * 2) + 1] = flag | (v & 15);
                    source2[index + 1] = flag | ((v >> 4) & 15);
                    
                }
            } else {
                source1[index * 2 + 1] = flag;
                source2[index * 2 + 1] = flag;
                records[1].run--;
            }
        }
        }
    }
}

static inline void predictA(unsigned char* output, int outputStride, unsigned char* source, int inputStride, int horizontal, int vertical)
{
    if (vertical) {
        if (horizontal)
            fn_80292EAC(output, outputStride, source, inputStride);
        else
            fn_80292D00(output, outputStride, source, inputStride);
    } else {
        if (horizontal)
            fn_80292B64(output, outputStride, source, inputStride);
        else
            fn_80292AC8(output, outputStride, source, inputStride);
    }
}


static inline int readDc2(MovieDecoderContext* ctx, int idx)
{
    MovieDecoderBitReader* reader = &ctx->dcValues[idx];
    MovieDecoderHuffmanTree* table = (MovieDecoderHuffmanTree*)ctx->dcValues[idx].buffer;
    int symbol = table->root;
    while (symbol >= 256)
        symbol = table->child[fn_80291734(reader)][symbol];
    return table->child[0][symbol];
}
static inline int decodeDc2(MovieDecoderContext* ctx, int idx, int min, int max)
{
    int sum = 0;
    int value;
    do {
        value = readDc2(ctx, idx);
        sum += value;
    } while (min >= value || value >= max);
    return sum;
}
#define DIFF(k) v = pred[k] - mean; d[k] = v; if (v < min) min = v; else if (v > max) max = v;

extern "C" void fn_80293574(MovieDecoderContext* ctx, unsigned char* out, unsigned char* source, int stride,
    int count, unsigned char* base, int baseStride, int idx, int horizontal, int vertical)
{
    MovieDecoderTables* tables = &lbl_80373140;
    int x; // declared first: its dead slot sits above s (target 0xfc)
    int s[16];
    unsigned char pred[16];
    int d[16];
    int dc;
    int mean;
    int max;
    int min;
    int scale;
    int i;
    int v;
    if ((unsigned char)--count == 1) {
        unsigned char smp[16];
        int acc = 0;
        int unused; // dead stack word between acc and the else-branch smp (target 0x54)
        int w = fn_80293FA0(ctx, smp, &acc, base, baseStride, idx);
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
        dc = (s[0] + s[1] + s[2] + s[3] + s[4] + s[5] + s[6] + s[7] + s[8] + s[9] + s[10] + s[11] + s[12] + s[13] + s[14] + s[15]) >> 4;
    } else {
        unsigned char smp[16];
        int acc;
        acc = 0;
        s[0] = s[1] = s[2] = s[3] = s[4] = s[5] = s[6] = s[7] = s[8] = s[9] = s[10] = s[11] = s[12] = s[13] = s[14] = s[15] = 0;
        while ((unsigned char)count--) {
            int w = fn_80293FA0(ctx, smp, &acc, base, baseStride, idx);
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
        dc = (s[0] + s[1] + s[2] + s[3] + s[4] + s[5] + s[6] + s[7] + s[8] + s[9] + s[10] + s[11] + s[12] + s[13] + s[14] + s[15]) >> 4;
    }
    predictA(pred, 4, source, stride, horizontal, vertical);
    mean = (pred[0] + pred[1] + pred[2] + pred[3] + pred[4] + pred[5] + pred[6] + pred[7] + pred[8] + pred[9] + pred[10] + pred[11] + pred[12] + pred[13] + pred[14] + pred[15] + 8) >> 4;
    min = count = pred[0] - mean;
    d[0] = min;
    max = min;
    DIFF(1) DIFF(2) DIFF(3) DIFF(4) DIFF(5) DIFF(6) DIFF(7) DIFF(8)
    DIFF(9) DIFF(10) DIFF(11) DIFF(12) DIFF(13) DIFF(14) DIFF(15)
    {
        int shift = ctx->shift;
        dc = ((decodeDc2(ctx, idx, ctx->low, ctx->high) >> ctx->shift2) << shift) - dc;
        scale = tables->reciprocal[max - min] * (decodeDc2(ctx, idx, ctx->low, ctx->high) >> ctx->shift2);
        for (i = 0; i < 16; i += 8) {
            s[i] += dc + scale * d[i];
            s[i + 1] += dc + scale * d[i + 1];
            s[i + 2] += dc + scale * d[i + 2];
            s[i + 3] += dc + scale * d[i + 3];
            s[i + 4] += dc + scale * d[i + 4];
            s[i + 5] += dc + scale * d[i + 5];
            s[i + 6] += dc + scale * d[i + 6];
            s[i + 7] += dc + scale * d[i + 7];
        }
        {
            unsigned char* p = pred;
            int k = 0;
            int y;
            for (y = 0; y < 4; y++) {
                out[0] = tables->clamp[p[0] + (s[k] >> shift) + 128];
                for (x = 1; x < 4; x++)
                    out[x] = tables->clamp[p[x] + (s[k + x] >> shift) + 128];
                out += stride;
                p += 4;
                k += 4;
            }
        }
    }
}
