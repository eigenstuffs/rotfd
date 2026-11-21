/* Movie decoder: recursive Huffman tree reader.
 *
 * A set bit introduces an internal node: the next free node index is taken
 * and its two children are read recursively.  A clear bit introduces a leaf
 * whose eight-bit symbol is optionally sign-folded (lbl_80378180) and scaled
 * (lbl_80378184) before it is stored in child[0][symbol].
 *
 * The original compiler inlined this recursive function into itself once
 * (the nested copy calls the out-of-line byte reader fn_802912D0 instead of
 * inlining it); that first nested level is written out explicitly here. */
struct BitReader {
    unsigned int* data;
    unsigned int bits;
    unsigned int word08;
    int position;
};

struct Tree {
    int pos;
    int root;
    int child[2][512];
};

extern "C" {
extern int lbl_80378180;
extern int lbl_80378184;
short fn_802912D0(BitReader*);
short fn_80291004(Tree*, BitReader*);
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
    /* Unused copy: its eliminated slot reproduces the original frame size. */
    unsigned int word = value;
    value = (value >> position) & 1;
    reader->position = position - 1;
    return value;
}

static inline unsigned int readByte(BitReader* reader)
{
    unsigned int result;
    int left = reader->position;
    if (left >= 7) {
        result = reader->word08;
        result >>= left - 7;
        left -= 8;
    } else {
        result = reader->word08;
        result <<= 7 - left;
        reader->word08 = *reader->data++;
        result |= reader->word08 >> (left + 25);
        left += 24;
    }
    reader->position = left;
    result &= 0xFF;
    return result;
}

static inline void storeLeaf(Tree* tree, short byte)
{
    short symbol = byte;
    if (lbl_80378180 != 0 && byte > 0x7F)
        symbol -= 0x100;
    symbol <<= lbl_80378184;
    tree->child[0][byte] = symbol;
}

extern "C" short fn_80291004(Tree* tree, BitReader* reader)
{
    short byte;
    if (readBit(reader)) {
        int pos = tree->pos++;
        short value;
        if (readBit(reader)) {
            int node = tree->pos++;
            tree->child[0][node] = fn_80291004(tree, reader);
            tree->child[1][node] = fn_80291004(tree, reader);
            value = node;
        } else {
            byte = fn_802912D0(reader);
            storeLeaf(tree, byte);
            value = byte;
        }
        tree->child[0][pos] = value;
        if (readBit(reader)) {
            int node = tree->pos++;
            tree->child[0][node] = fn_80291004(tree, reader);
            tree->child[1][node] = fn_80291004(tree, reader);
            value = node;
        } else {
            byte = fn_802912D0(reader);
            storeLeaf(tree, byte);
            value = byte;
        }
        tree->child[1][pos] = value;
        return pos;
    }
    byte = readByte(reader);
    storeLeaf(tree, byte);
    return byte;
}
