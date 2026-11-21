/* auto_03_80293158_text retry2 (best: 94.858% .text; final.cpp unchanged).
 * Flags: GC/1.2.5, -inline auto,level=2 (as movie_intra_basis_dc_decode_80291334).
 * Findings: the 80291334-style readBit/treeOf/decodeHuff shapes give the
 * original frame sizes (eliminated inline copies keep stack slots); the
 * reader block at 0x60D8 is dcValues[3], dcRuns[3], acValues[3],
 * basisCounts[2], basisRuns[2] (State layout of 80291334); fn_80294598 shows
 * the TU declared outer locals at function top in order (callee-saved
 * registers are handed out from r31 in declaration order). */
struct MovieDecoderBitReader {
    unsigned int* data;
    unsigned int bits;
    unsigned int word08;
    int position;
    unsigned int* buffer;
};
struct MovieDecoderHuffmanTree {
    int word00;
    int root;
    int child[2][512];
};
struct MovieDecoderPlane {
    unsigned char unknown00[8];
    unsigned short blocksWidth, blocksHeight, paddedWidth, paddedHeight;
    unsigned short blockIndex[4];
    unsigned int blockOffset[4];
    unsigned short width, height;
    int pixels;
    unsigned char horizontalShift, verticalShift, horizontalScale, verticalScale, count;
    unsigned char unknown35[3];
};
struct MovieDecoderStream {
    unsigned char* data;
    unsigned char unknown04[0xC];
};
struct MovieDecoderPrefix {
    struct MovieDecoderContext* workspace;
    unsigned short width, height;
    unsigned char horizontalMode, verticalMode;
};
struct MovieDecoderContext {
    MovieDecoderPlane planes[3];
    unsigned char unknownA8[0x60D8 - 0xA8];
    MovieDecoderBitReader dcValues[3];
    MovieDecoderBitReader dcRuns[3];
    MovieDecoderBitReader acValues[3];
    MovieDecoderBitReader basisCounts[2];
    MovieDecoderBitReader basisRuns[2];
    MovieDecoderStream streams[3];
    MovieDecoderBitReader readers2[4];
    unsigned char unknown625C[4];
    unsigned char transposed;
    unsigned char unknown6261[0x6CC8 - 0x6261];
    int high, low;
    unsigned char shift, shift2, bitsA[2], bitsB[2];
};
struct MovieOutputRecord {
    int run;
    int word04;
    unsigned char* source;
    unsigned char* cursor;
    unsigned char* first;
    unsigned char* out;
    unsigned char* ref;
    unsigned char* second;
    unsigned char* third;
    unsigned short horizontal;
    unsigned short unknown26;
    int rowBytes;
    int horizontalScale;
    int paddedBytes;
};

static inline void readBit(MovieDecoderBitReader* reader, unsigned int& result)
{
    int position = reader->position;
    unsigned int value;
    if (position < 0) {
        unsigned int* data = reader->data;
        position = 31;
        reader->data = data + 1;
        value = *data;
        reader->word08 = value;
    } else {
        value = reader->word08;
    }
    unsigned int word = value;
    value = (value >> position) & 1;
    reader->position = position - 1;
    result = value;
}

static inline unsigned int readBitValue(MovieDecoderBitReader* reader)
{
    int position = reader->position;
    unsigned int value;
    if (position < 0) {
        unsigned int* data = reader->data;
        position = 31;
        reader->data = data + 1;
        value = *data;
        reader->word08 = value;
    } else {
        value = reader->word08;
    }
    unsigned int result = value >> position;
    reader->position = position - 1;
    result &= 1;
    return result;
}

static inline MovieDecoderHuffmanTree* treeOf(MovieDecoderBitReader* reader)
{
    return (MovieDecoderHuffmanTree*)reader->buffer;
}

static inline int readSymbol(MovieDecoderBitReader* reader)
{
    MovieDecoderHuffmanTree* table = treeOf(reader);
    int symbol = table->root;
    while (symbol >= 256)
        symbol = table->child[readBitValue(reader)][symbol];
    return table->child[0][symbol];
}


extern "C" {
unsigned int fn_80291734(MovieDecoderBitReader*);
int fn_80291774(MovieDecoderBitReader*);
void fn_80292AC8(unsigned char*, int, const unsigned char*, int);
void fn_80292B64(unsigned char*, int, const unsigned char*, int);
void fn_80292D00(unsigned char*, int, const unsigned char*, int);
void fn_80292EAC(unsigned char*, int, const unsigned char*, int);
int fn_80293FA0(MovieDecoderContext*, unsigned char*, int*, unsigned char*, int, int);
void fn_80293574(MovieDecoderContext*, unsigned char*, unsigned char*, int, unsigned char, unsigned char*, int, int, int, int);
void fn_80291B88(unsigned char*, int, int, int, int, int, int);
void fn_80291D20(MovieDecoderContext*, unsigned char*, int, int, int, int);
void fn_80293158(MovieDecoderContext*, MovieOutputRecord*, int, int);
void fn_80292950(MovieDecoderPlane*, MovieOutputRecord*, unsigned char*, unsigned char*, unsigned char*);
void fn_802929DC(MovieDecoderContext*, MovieOutputRecord*, int, int);
void fn_802943D0(MovieDecoderContext*, MovieOutputRecord*, int, int);
void fn_80294598(MovieDecoderContext*, MovieOutputRecord*);
void fn_80294748(struct MovieDecoderPrefix*, MovieOutputRecord*);
extern const int lbl_802AFB80[2][3];
}
struct MovieDecoderTables {
    unsigned char clamp[512];
    int scale[16];
    int reciprocal[512];
};
extern "C" MovieDecoderTables lbl_80373140;

static inline int readSymbolCall(MovieDecoderBitReader* reader)
{
    MovieDecoderHuffmanTree* table = (MovieDecoderHuffmanTree*)reader->buffer;
    int symbol = table->root;
    while (symbol >= 256)
        symbol = table->child[fn_80291734(reader)][symbol];
    return table->child[0][symbol];
}

static inline int decodeBounded(MovieDecoderBitReader* reader, int min, int max)
{
    int sum = 0;
    int value;
    do {
        value = readSymbolCall(reader);
        sum += value;
    } while (min >= value || value >= max);
    return sum;
}


static inline unsigned int readBitCopy(MovieDecoderBitReader* reader)
{
    int position = reader->position;
    unsigned int value;
    if (position < 0) {
        unsigned int* data = reader->data;
        position = 31;
        reader->data = data + 1;
        value = *data;
        reader->word08 = value;
    } else {
        value = reader->word08;
    }
    unsigned int word = value;
    value = (value >> position) & 1;
    reader->position = position - 1;
    return value;
}

static inline int readSymbolA(MovieDecoderBitReader* reader)
{
    MovieDecoderHuffmanTree* table = (MovieDecoderHuffmanTree*)reader->buffer;
    int symbol = table->root;
    while (symbol >= 256)
        symbol = table->child[readBitValue(reader)][symbol];
    return table->child[0][symbol];
}

static inline int readSymbolB(MovieDecoderBitReader* reader)
{
    MovieDecoderHuffmanTree* table = (MovieDecoderHuffmanTree*)reader->buffer;
    int symbol = table->root;
    while (symbol >= 256)
        symbol = table->child[readBitCopy(reader)][symbol];
    return table->child[0][symbol];
}

static inline int readSymbolC(MovieDecoderBitReader* reader)
{
    MovieDecoderHuffmanTree* table = treeOf(reader);
    int symbol = table->root;
    while (symbol >= 256)
        symbol = table->child[readBitCopy(reader)][symbol];
    return table->child[0][symbol];
}

extern "C" int lbl_80373340[16];
static inline int readSymbolIdx(MovieDecoderContext* ctx, int idx)
{
    MovieDecoderBitReader* reader = &ctx->acValues[idx];
    MovieDecoderHuffmanTree* table = treeOf(&ctx->acValues[idx]);
    int symbol = table->root;

    while (symbol >= 256)
        symbol = table->child[readBitValue(reader)][symbol];
    return table->child[0][symbol];
}

extern "C" int fn_80293FA0(MovieDecoderContext* ctx, unsigned char* out, int* acc,
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
#define PIXEL(k) v = (*p >> 4) & 15; out[k] = v; if (v > max) max = v; else if (v < min) min = v;
    p = row;
    v = (*p >> 4) & 15;
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
static inline void predictB(unsigned char* output, unsigned char* source, int stride, int horizontal, int vertical)
{
    int inputStride = stride;
    int outputStride = stride;
    predictA(output, outputStride, source, inputStride, horizontal, vertical);
}
static inline void predictC(unsigned char* output, unsigned char* source, int inputStride, int horizontal, int vertical)
{
    int outputStride = inputStride;
    predictA(output, outputStride, source, inputStride, horizontal, vertical);
}
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
static inline void copyC(unsigned char* row, int width, unsigned int* data)
{
    unsigned int w0 = data[0], w1 = data[1], w2 = data[2], w3 = data[3];
    *(unsigned int*)row = w0; *(unsigned int*)(row += width) = w1;
    *(unsigned int*)(row += width) = w2; *(unsigned int*)(row += width) = w3;
}
extern "C" void fn_802943D0(MovieDecoderContext* ctx, MovieOutputRecord* records, int x, int y)
{
    MovieDecoderStream* stream;
    MovieOutputRecord* record = records;
    MovieDecoderPlane* plane = ctx->planes;
    int i;
    int j;
    int horizontal;
    int vertical;
    unsigned char* input;
    unsigned short* list;
    unsigned int* offsets;
    unsigned char* base;
    int count;

    base = record->ref + ((x >> 1) - 32) + ((y >> 1) - 16) * ctx->planes[0].width;
    for (i = 0; i < 3; i++) {
        int scaledX = x >> plane->horizontalShift;
        int scaledY = y >> plane->verticalShift;
        list = plane->blockIndex;
        offsets = plane->blockOffset;
        horizontal = scaledX & 1;
        vertical = scaledY & 1;
        count = plane->count;
        scaledX >>= 1;
        scaledY >>= 1;
        input = (scaledX + scaledY * plane->width) + record->ref;
        stream = &ctx->streams[i];
        for (j = 0; j < count; j++) {
            unsigned short index = *list++;
            unsigned int offset = *offsets++;
            unsigned int type = record->source[index * 2 + 1] & 15;
            unsigned char* output = record->out + offset;
            if (type == 6) {
                unsigned int* data = (unsigned int*)stream->data;
                copyA(output, plane->width, data);
                stream->data = (unsigned char*)(data + 4);
            } else {
                unsigned char* source = input + offset;
                if (type == 0) {
                    predictC(output, source, plane->width, horizontal, vertical);
                } else {
                    fn_80293574(ctx, output, source, plane->width, type, base, ctx->planes[0].width, i,
                        horizontal, vertical);
                }
            }
        }
        record++;
        plane++;
    }
}

static inline int neighbourValue(const unsigned char* info, int value)
{
    if (info[1] & 0x77)
        return value;
    return info[0];
}


static inline int decodeSum(MovieDecoderBitReader* reader, int min, int max)
{
    int sum = 0;
    int value;
    do {
        value = fn_80291774(reader);
        sum += value;
    } while (min >= value || value >= max);
    return sum;
}

static inline void readBitI(MovieDecoderBitReader* reader, int& result)
{
    int position = reader->position;
    unsigned int value;
    if (position < 0) {
        unsigned int* data = reader->data;
        position = 31;
        reader->data = data + 1;
        value = *data;
        reader->word08 = value;
    } else {
        value = reader->word08;
    }
    unsigned int word = value;
    value = (value >> position) & 1;
    reader->position = position - 1;
    result = value;
}

static inline void advanceColumn(MovieOutputRecord* record)
{
    MovieOutputRecord* r = record;
    MovieOutputRecord* r2 = record;
    MovieOutputRecord* r3 = record;
    r->out += r->horizontal;
    r->source += r->horizontalScale * 2;
}

static inline void advanceRow(MovieOutputRecord* record)
{
    MovieOutputRecord* r = record;
    MovieOutputRecord* r2 = record;
    MovieOutputRecord* r3 = record;
    record->first += record->rowBytes;

    record->source = record->cursor += record->paddedBytes * 2;
}


static inline int readMotion(MovieDecoderBitReader* reader, int bits)
{
    MovieDecoderHuffmanTree* table = (MovieDecoderHuffmanTree*)reader->buffer;
    int symbol = table->root;
    while (symbol >= 256)
        symbol = table->child[fn_80291734(reader)][symbol];
    return table->child[0][symbol];
}

