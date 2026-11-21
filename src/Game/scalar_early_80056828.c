/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

unsigned char fn_80056828(void *object) {unsigned char count=0;int i;for(i=0;i<8;++i)if(*(signed char *)((char *)*(void **)((char *)object+0x138)+i*0x94+0x2a)==1)++count;return count;}
