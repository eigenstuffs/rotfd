/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

void fn_800596F4(void *object,const int *packed,short *high,short *low) {*low=(short)*packed;*high=(short)(*packed>>16);}
