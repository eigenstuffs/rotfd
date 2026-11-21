#include "recovered/w3_8_movie.h"
static inline void rbA(MovieDecoderBitReader* reader, int& result)
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
    reader->position = position - 1;
    result = (value >> position) & 1;
}
static inline void rbB(MovieDecoderBitReader* reader, int& result)
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
    result = value >> position;
    reader->position = position - 1;
    result &= 1;
}
static inline void decodeRun(MovieDecoderBitReader* reader, int& run)
{
    int value;
    run = 0;
    do {
        value = fn_80291774(reader);
        run += value;
    } while (value >= 255);
}

extern "C" void fn_80294748(MovieDecoderPrefix* prefix, MovieOutputRecord* records)
{
    MovieDecoderContext* workspace = prefix->workspace;
    MovieDecoderContext* ctx = workspace;
    MovieOutputRecord* record2;
    MovieOutputRecord* record1;
    int option;
    int mode;
    int x;
    int y;
    int unused0, unused1, unused2, unused3, unused4, unused5, unused6, unused7, unused8;
    int runA;
    int runB;
    int i;
    unsigned short* list;
    int j;
    if (workspace->readers2[2].data) {
        rbA(&ctx->readers2[2], mode);
        decodeRun(&ctx->readers2[2], runA);
    }
    if (ctx->readers2[3].data) {
        int bit;
        readBitI(&ctx->readers2[3], bit);
        option = bit << 1;
rbB(&ctx->readers2[3], bit);
        option |= bit;
        decodeRun(&ctx->readers2[3], runB);
    }
    record1 = records + 1;
    record2 = records + 2;
    for (y = 0; y < prefix->height; y += 8) {
        records->out = records->first;
        record1->out = record1->first;
        record2->out = record2->first;
        for (x = 0; x < prefix->width; x += 8) {
            if (runB == 0) {
                int bit;
                readBitI(&ctx->readers2[3], bit);
                option = lbl_802AFB80[bit][option];
                decodeRun(&ctx->readers2[3], runB);
            }
            runB--;
            if (option == 0) {
                MovieOutputRecord* record = records;
                MovieDecoderPlane* plane = ctx->planes;
                MovieDecoderContext* base = ctx; for (i = 0; i < 3; i++) {
                    int count = plane->count;
                    MovieDecoderBitReader* reader = base->dcValues;
                    list = plane->blockIndex;
                    for (j = 0; j < count; j++) {
                        unsigned short index = *list++;
                        record->source[index * 2] = record->word04 += decodeSum(reader, ctx->low, ctx->high);
                    }
                    record++;
                    plane++;
                    base = (MovieDecoderContext*)((char*)base + 20);
                }
                fn_80293158(ctx, records, 0, option);
            } else {
                records[0].word04 = 0x7f;
                records[1].word04 = 0x7f;
                records[2].word04 = 0x7f;
                if (runA == 0) {
                    mode ^= 1;
                    decodeRun(&ctx->readers2[2], runA);
                }
                runA--;
                fn_80293158(ctx, records, mode, option);
            }
            advanceColumn(records);
            advanceColumn(record1);
            advanceColumn(record2);
        }
        advanceRow(records);
        advanceRow(record1);
        advanceRow(record2);
    }
}

/* fn_80294B78 matching notes: the second motion component (motionB) carries two load/store-back pairs,
   `*count = bits` and a rewrite of reader->position with its own value. Both pairs survive until the final
   (post register allocation) peephole, which deletes the stores (store of a value just loaded from the same
   address). While present they (1) keep `shifted` live past the bits load so it gets one more interference
   edge and is coloured with the named locals (r26), (2) give the bits load scheduling priority over the table
   load, and (3) keep the reader/position value live across the block so symbol/limit colour as r17/r18. */
static inline int loadCount(const unsigned char* p) { return *p; }
static inline void motionA(MovieDecoderContext* ctx, MovieDecoderBitReader* reader, int k, const unsigned char* count, int& acc)
{
    MovieDecoderHuffmanTree* table;
    int bits;
    int symbol;
    int limit;
    int value;
    int n;
    table = (MovieDecoderHuffmanTree*)ctx->readers2[k].buffer;
    bits = *count;
    symbol = table->root;
    limit = 1 << (bits + 5);
    while (symbol >= 256)
        symbol = table->child[fn_80291734(reader)][symbol];
    value = table->child[0][symbol] << bits;
    for (n = bits - 1; n >= 0; n--) {
        int bit;
        readBitI(&ctx->readers2[k], bit);
        value += bit << n;
    }
    acc += value;
    if (acc >= limit)
        acc -= limit * 2;
    else if (acc < -limit)
        acc += limit * 2;
}
static inline void motionB(MovieDecoderContext* ctx, MovieDecoderBitReader* reader, int k, unsigned char* count, int& acc)
{
    int limit;
    int symbol;
    MovieDecoderHuffmanTree* table;
    int bits;
    int value;
    int n;
    table = (MovieDecoderHuffmanTree*)ctx->readers2[k].buffer;
    bits = *count;
    *count = bits; /* store-back of the byte just loaded: deleted by the final peephole (see note above) */
    symbol = table->root;
    limit = 1 << (bits + 5);
    { int position = reader->position; *(unsigned int*)&reader->position = (unsigned int)position; } /* second store-back pair */
    while (symbol >= 256)
        symbol = table->child[fn_80291734(reader)][symbol];
    value = table->child[0][symbol] << bits;
    for (n = bits - 1; n >= 0; n--) {
        int bit;
        readBitI(&ctx->readers2[k], bit);
        value += bit << n;
    }
    acc += value;
    if (acc >= limit)
        acc -= limit * 2;
    else if (acc < -limit)
        acc += limit * 2;
}
extern "C" void fn_80294B78(MovieDecoderPrefix* prefix, unsigned char* out, unsigned char* previous, unsigned char* other)
{
    MovieOutputRecord records[3];
    int u0, u1, u2;
    MovieDecoderBitReader* reader0;
    MovieDecoderBitReader* reader1;
    int x2;
    int y2;
    unsigned char info;
    MovieDecoderContext* shifted;
    MovieDecoderContext* ctx = prefix->workspace;
    int dx;
    int dy;
    int last;
    int x;
    int y;
    unsigned char* first;

    fn_80292950(ctx->planes, records, out, previous, other);
    fn_80294748(prefix, records);
    first = out;
    records[0].first = first;
    records[0].cursor = records[0].source = ctx->planes[0].info;
    first += ctx->planes[0].pixels;
    records[1].first = first;
    records[1].cursor = records[1].source = ctx->planes[1].info;
    first += ctx->planes[1].pixels;
    records[2].first = first;
    records[2].cursor = records[2].source = ctx->planes[2].info;
    y = 0;
    y2 = y * 2;
    reader0 = &ctx->readers2[0];
    reader1 = &ctx->readers2[1];
    last = -1;
    for (; y < prefix->height; y2 += 16, y += 8) {
        records[0].out = records[0].first;
        records[1].out = records[1].first;
        records[2].out = records[2].first;
        for (x = 0, x2 = x * 2; x < prefix->width; x2 += 16, x += 8) {
            info = records[0].source[1];
            int ref = (info >> 5) & 3;
            if (ref == 0) {
                fn_80294598(ctx, records);
            } else {
                int which = ref - 1;
                if (which != last) {
                    last = which;
                    if (which == 0) {
                        records[0].ref = records[0].second;
                        records[1].ref = records[1].second;
                        records[2].ref = records[2].second;
                    } else {
                        records[0].ref = records[0].third;
                        records[1].ref = records[1].third;
                        records[2].ref = records[2].third;
                    }
                    dy = 0;
                    dx = 0;
                }
                shifted = (MovieDecoderContext*)((unsigned char*)ctx + last);
                motionA(ctx, reader0, 0, &shifted->bitsA[0], dx);
                motionB(ctx, reader1, 1, &shifted->bitsB[0], dy);
                if (!((info >> 4) & 1))
                    fn_802943D0(ctx, records, x2 + dx, y2 + dy);
                else
                    fn_802929DC(ctx, records, x2 + dx, y2 + dy);
            }
            advanceColumn(&records[0]);
            advanceColumn(&records[1]);
            advanceColumn(&records[2]);
        }
        advanceRow(&records[0]);
        advanceRow(&records[1]);
        advanceRow(&records[2]);
    }
}
