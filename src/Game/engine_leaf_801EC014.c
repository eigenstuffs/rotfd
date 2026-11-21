/* Original indexed records, engine setup and allocation-header routines.
 * See docs/notes/game-engine-leaf.md. */

extern void *OSGetArenaHi(void);

extern unsigned int *lbl_80377FB0;

unsigned int fn_801EC014(void) {lbl_80377FB0=(unsigned int *)((char *)OSGetArenaHi()-0xfa00);return *lbl_80377FB0;}
