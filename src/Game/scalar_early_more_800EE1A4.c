/* Original array and scalar routines with private observed layouts.
 * See docs/notes/game-scalar-early-more.md. */

extern const float lbl_80379864;

extern const unsigned char lbl_802C9318[];

extern const unsigned char lbl_802C967C[];

extern void fn_80090084(void *object);

void *fn_800EE1A4(void *object,unsigned int arg4) {fn_80090084(object);*(const void * *)((char *)object+0)=lbl_802C967C;*(unsigned int *)((char *)object+8)=0;*(unsigned int *)((char *)object+12)=0;*(unsigned int *)((char *)object+8)=arg4;*(const void * *)((char *)object+0)=lbl_802C9318;*(float *)((char *)object+16)=lbl_80379864;*(unsigned char *)((char *)object+4)=1;return object;}
