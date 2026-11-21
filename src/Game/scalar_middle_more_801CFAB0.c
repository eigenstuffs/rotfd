/* Original engine setup and record routines with private observed layouts.
 * See docs/notes/game-scalar-middle-more.md. */

extern void fn_80243F28(void *);

extern const char lbl_802EA498[];

void *fn_801CFAB0(void *object) {fn_80243F28(object);*(void **)((char *)object+8)=(void *)lbl_802EA498;*(unsigned int *)((char *)object+0x74)=0;*(unsigned int *)((char *)object+0x78)=0;*(unsigned int *)((char *)object+0x7c)=0;*(unsigned int *)((char *)object+0x80)=0;*(unsigned int *)((char *)object+0x84)=0;*(unsigned int *)((char *)object+0x88)=0;return object;}
