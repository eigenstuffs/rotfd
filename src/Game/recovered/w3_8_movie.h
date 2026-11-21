#ifndef W3_8_MOVIE_H
#define W3_8_MOVIE_H
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
    unsigned char unknown00[4];
    unsigned char* info;
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
void fn_80291D20(MovieDecoderContext*, unsigned char*, int, unsigned char, unsigned char, int);
int fn_80292258(MovieDecoderContext*, unsigned char*, int*, unsigned char*, int, int);
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


#endif
