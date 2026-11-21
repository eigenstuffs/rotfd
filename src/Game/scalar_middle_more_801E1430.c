/* Original engine setup and record routines with private observed layouts.
 * See docs/notes/game-scalar-middle-more.md. */

extern void fn_801E1494(void *,int);

void fn_801E1430(void *object) {int i;for(i=0;i<*(signed char *)((char *)object+0x214);++i)fn_801E1494(object,i);fn_801E1494(object,6);}
