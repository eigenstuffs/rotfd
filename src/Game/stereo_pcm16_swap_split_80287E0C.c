/* Split interleaved little-endian 16-bit stereo PCM into separate
 * big-endian left/right sample buffers.
 *
 * source holds size bytes of L/R sample pairs; each output channel receives
 * size / 4 samples. The first argument is the calling stream owner, which the
 * routine returns unchanged (callers ignore it).
 *
 * This object only matches with the old CodeWarrior compiler at -O1 with
 * debugging information enabled (GC/1.0 - GC/1.2.5n, "-O1 -sym on").
 * Without debug information the peephole pass moves the final
 * "out += 2" between the loop compare and its branch, and GC/1.3 or later
 * always does so. Level 3 and above strength-reduce the indexed stores. */

void *fn_80287E0C(void *owner, unsigned char *source, unsigned short *left,
                  unsigned short *right, unsigned long size)
{
    unsigned long out;
    unsigned long in;

    __dcbt(source, 0);
    in = 0;
    out = 0;
    if (in == size)
        return owner;
    do {
        *(unsigned short *)((char *)left + out) = __lhbrx(source, in);
        in += 2;
        *(unsigned short *)((char *)right + out) = __lhbrx(source, in);
        in += 2;
        out += 2;
    } while (in < size);
    return owner;
}
