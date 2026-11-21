/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-middle.md. */


void fn_801C9E10(void *object,short index) {(*(unsigned int **)((char *)object+0x10))[index>>5]&=~(1U<<(index&31));}
