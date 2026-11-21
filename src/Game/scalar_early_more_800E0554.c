/* Original array and scalar routines with private observed layouts.
 * See docs/notes/game-scalar-early-more.md. */

extern const unsigned char lbl_802C8290[];

extern const unsigned char lbl_802C82AC[];

extern void fn_80090084(void *object);

void *fn_800E0554(void *object,unsigned int arg4,unsigned int arg5) {fn_80090084(object);*(const void * *)((char *)object+0)=lbl_802C82AC;*(unsigned int *)((char *)object+8)=arg4;*(unsigned int *)((char *)object+12)=arg5;*(const void * *)((char *)object+0)=lbl_802C8290;*(unsigned char *)((char *)object+4)=1;return object;}
