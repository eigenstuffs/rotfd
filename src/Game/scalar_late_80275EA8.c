/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-late.md. */


unsigned int fn_80275EA8(const void *object,int index) { if(index>=0&&index<4)return *(unsigned int *)((char *)*(void *const *)((const char *)object+8)+(index<<6)+0x2c);return 1;}
