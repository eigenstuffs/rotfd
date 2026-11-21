/* Retained MSL random generator, adapted from doldecomp/melee
 * src/MSL/rand.c at ae5898ee0dfda41b34fdf846f7d680a33e14779d.
 * Original text: 0x80127C6C..0x80127C8C.
 * Provenance: reference/melee-msl/PROVENANCE.md.
 */

static unsigned long int next = 1;

int rand(void)
{
    next = next * 1103515245 + 12345;
    return ((next >> 16) & 0x7FFF);
}

