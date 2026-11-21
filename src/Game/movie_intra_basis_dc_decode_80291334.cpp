/* Movie decoder intra-picture passes.
 *
 * fn_80291334 decodes the per-block basis counts: one Huffman-coded count
 * per luma block, and one count per chroma block pair (low nibble for the
 * first chroma plane, high nibble for the second), with zero counts
 * followed by a Huffman-coded run of further zero blocks.
 *
 * fn_802915F8 decodes the DC value of every block of the three planes as a
 * delta from the rounded average of the left and upper neighbours; deltas
 * are sums of bounded Huffman symbols (fn_80291774) and a zero delta is
 * followed by a run of further zero deltas.
 *
 * This translation unit was compiled with two levels of inlining: helpers
 * reached at the third level are the out-of-line fn_80291734 (bit) and
 * fn_80291774 (symbol) calls below. */
struct Tree {
    int pos;
    int root;
    int child[2][512];
};

struct BitReader {
    unsigned int* data;
    unsigned int bits;
    unsigned int word08;
    int position;
    Tree* tree;
};

struct Block {
    unsigned char value;
    unsigned char type;
};

struct Plane {
    unsigned int unknown00;
    Block* payload;
    unsigned short width;
    unsigned short height;
    unsigned short stride;
    unsigned char unknown0E[0x38 - 0x0E];
};

struct State {
    Plane planes[3];
    unsigned char unknownA8[0x60D8 - 0xA8];
    BitReader dcValues[3];
    BitReader dcRuns[3];
    unsigned char unknown6150[0x618C - 0x6150];
    BitReader basisCounts[2];
    BitReader basisRuns[2];
    unsigned char unknown61DC[0x6CC8 - 0x61DC];
    int dcMax;
    int dcMin;
};

typedef char StateDcValuesOffset[((unsigned int)&((State*)0)->dcValues == 0x60D8) ? 1 : -1];
typedef char StateBasisOffset[((unsigned int)&((State*)0)->basisCounts == 0x618C) ? 1 : -1];
typedef char StateDcMaxOffset[((unsigned int)&((State*)0)->dcMax == 0x6CC8) ? 1 : -1];

extern "C" {
unsigned int fn_80291734(BitReader*);
int fn_80291774(BitReader*);
void fn_80291334(State*);
void fn_802915F8(State*);
}

static inline unsigned int readBit(BitReader* reader)
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

static inline Tree* treeOf(BitReader* reader)
{
    return reader->tree;
}

static inline int decodeHuff(BitReader* reader)
{
    Tree* tree = treeOf(reader);
    int symbol = tree->root;
    while (symbol >= 256)
        symbol = tree->child[readBit(reader)][symbol];
    return tree->child[0][symbol];
}

/* Same decoder one inlining level deeper: the bit read stays a call. */
static inline int decodeHuffCall(BitReader* reader)
{
    Tree* tree = reader->tree;
    int symbol = tree->root;
    while (symbol >= 256)
        symbol = tree->child[fn_80291734(reader)][symbol];
    return tree->child[0][symbol];
}

static inline int decodeBounded(BitReader* reader, int min, int max)
{
    int sum = 0;
    int value;
    do {
        value = fn_80291774(reader);
        sum += value;
    } while (min >= value || value >= max);
    return sum;
}

static inline int decodeDelta(State* state, int plane, int* run)
{
    if (*run == 0) {
        int delta = decodeBounded(&state->dcValues[plane], state->dcMin, state->dcMax);
        if (delta == 0)
            *run = decodeHuffCall(&state->dcRuns[plane]);
        return delta;
    }
    --*run;
    return 0;
}

extern "C" void fn_80291334(State* state)
{
    short count;
    {
        Block* dst;
        int height;
        BitReader* counts;
        BitReader* runs;
        int width;
        int run;
        counts = &state->basisCounts[0];
        runs = &state->basisRuns[0];
        run = 0;
        dst = state->planes[0].payload;
        width = state->planes[0].width;
        height = state->planes[0].height;
        for (; height > 0; height--) {
            for (int x = width; x > 0; x--) {
                if (run == 0) {
                    count = decodeHuff(counts);
                    if (count == 0)
                        run = decodeHuff(runs);
                    dst->type = count;
                    dst++;
                } else {
                    dst->type = 0;
                    dst++;
                    run--;
                }
            }
            dst += 2;
        }
    }
    {
        int run;
        BitReader* counts;
        BitReader* runs;
        int height;
        Block* u;
        Block* v;
        int width;
        u = state->planes[1].payload;
        counts = &state->basisCounts[1];
        v = state->planes[2].payload;
        runs = &state->basisRuns[1];
        width = state->planes[1].width;
        height = state->planes[1].height;
        run = 0;
        for (; height > 0; height--) {
            for (int x = width; x > 0; x--) {
                if (run == 0) {
                    count = decodeHuff(counts);
                    if (count == 0)
                        run = decodeHuff(runs);
                    u->type = count & 0xF;
                    u++;
                    v->type = (count >> 4) & 0xF;
                    v++;
                } else {
                    u->type = 0;
                    run--;
                    u++;
                    v->type = 0;
                    v++;
                }
            }
            u += 2;
            v += 2;
        }
    }
}

extern "C" void fn_802915F8(State* state)
{
    for (int i = 0; i < 3; i++) {
        Block* dst;
        Block* above;
        int run;
        int left;
        int width;
        int x;
        int height;
        int stride;
        stride = state->planes[i].stride;
        width = state->planes[i].width;
        dst = state->planes[i].payload;
        height = state->planes[i].height;
        run = 0;
        for (; height > 0; height--) {
            left = (above = dst - stride)->value;
            for (x = width; x > 0; x--, dst++) {
                unsigned char value = left + decodeDelta(state, i, &run);
                int top = (++above)->value;
                left = (top + value + 1) >> 1;
                dst->value = value;
            }
            dst += 2;
        }
    }
}
