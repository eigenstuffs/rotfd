/* Read eight bits from the observed MSB-first word cursor.
 * remaining names the highest unread bit in the cached word. */
struct BitReader_802912D0 {
    unsigned int* cursor;
    char unknown04[4];
    unsigned int cached;
    int remaining;

    unsigned int read(int bits)
    {
        int left = remaining;
        unsigned int result;
        if (left >= bits - 1) {
            result = cached;
            result >>= left - (bits - 1);
            left -= bits;
        } else {
            result = cached;
            result <<= (bits - 1) - left;
            cached = *cursor++;
            result |= cached >> (left + 33 - bits);
            left += 32 - bits;
        }
        remaining = left;
        result &= (1u << bits) - 1;
        return result;
    }
};
extern "C" short fn_802912D0(BitReader_802912D0* self)
{
    return self->read(8);
}
typedef char BitReaderSizeCheck[sizeof(BitReader_802912D0) == 16 ? 1 : -1];
