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

static inline int neighbourValue(const unsigned char* info, int value)
{
    if (info[1] & 0x77)
        return value;
    return info[0];
}

extern "C" void fn_80294598(MovieDecoderContext* context, MovieOutputRecord* records)
{
    int i;
    unsigned char* source;
    int width;
    int pitch;
    unsigned short* list;
    unsigned int* offsets;
    int count;
    int j;
    int unused;
    MovieDecoderPlane* planes = context->planes;
    MovieOutputRecord* record = records;
    MovieDecoderPlane* plane = planes;
    for (i = 0; i < 3; i++) {
        source = record->source;
        list = plane->blockIndex;
        width = plane->width;
        offsets = plane->blockOffset;
        pitch = plane->paddedWidth;
        count = plane->count;
        for (j = 0; j < count; j++) {
            unsigned short index = *list++;
            unsigned char* info = source + index * 2;
            unsigned char* output = record->out + *offsets++;
            unsigned char type = info[1] & 15;
            int kind = type;
            unsigned char value = info[0];
            if ((unsigned char)kind == 0) {
                int up = neighbourValue(source + (index - pitch) * 2, value);
                int left = neighbourValue(info - 2, value);
                int right = neighbourValue(info + 2, value);
                int down = neighbourValue(source + (index + pitch) * 2, value);
                fn_80291B88(output, width, value, up, down, left, right);
            } else if ((unsigned char)kind == 8) {
                unsigned char* row = output;
                row[3] = value;
                row[2] = value;
                row[1] = value;
                row[0] = value;
                row += width;
                row[3] = value;
                row[2] = value;
                row[1] = value;
                row[0] = value;
                row += width;
                row[3] = value;
                row[2] = value;
                row[1] = value;
                row[0] = value;
                row += width;
                row[3] = value;
                row[2] = value;
                row[1] = value;
                row[0] = value;
            } else {
                fn_80291D20((MovieDecoderContext*)planes, output, width, value, type, i);
            }
        }
        record++;
        plane++;
    }
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

