/* Original scalar operations; provisional text-only ownership.
 * See docs/notes/game-leaf-extended.md. */


void fn_80028090(void *object, unsigned long long mask) { *(unsigned long long *)((char *)object + 0x30) &= ~mask; }
