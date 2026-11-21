/* Original scalar operation with private observed layouts.
 * See docs/notes/game-scalar-late.md. */


unsigned int *fn_8027269C(void *object) {if(*(void **)((char *)object+0x9f0)&&*(int *)((char *)object+0x9fc)<*(int *)((char *)object+0x9f8)){++*(int *)((char *)object+0x9fc);return *(unsigned int **)((char *)object+0x9f0)+(*(int *)((char *)object+0x9fc)-1);}return 0;}
