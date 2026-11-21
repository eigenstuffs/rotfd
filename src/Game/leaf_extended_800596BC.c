/* Original scalar operations; provisional text-only ownership.
 * See docs/notes/game-leaf-extended.md. */


void fn_800596BC(void *object, unsigned int index, unsigned int *first, unsigned int *second) { *first = *(unsigned int *)((char *)*(void **)((char *)object + 0xec) + (index << 4) + 12); *second = *(unsigned int *)((char *)*(void **)((char *)object + 0xec) + (index << 4) + 8); }
