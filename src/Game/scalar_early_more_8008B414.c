#include "Game/costume_native_operation_records.h"
/* Original array and scalar routines with private observed layouts.
 * See docs/notes/game-scalar-early-more.md. */

extern const float lbl_80378AD0;



extern const unsigned char lbl_802B92B0[];

extern void fn_80090084(void *object);

void *fn_8008B414(void *object,unsigned int arg4,unsigned int arg5) {fn_80090084(object);*(const void * *)((char *)object+0)=lbl_802B92B0;*(unsigned int *)((char *)object+8)=0;*(unsigned int *)((char *)object+12)=0;*(unsigned int *)((char *)object+8)=arg4;*(unsigned int *)((char *)object+12)=arg5;*(const void * *)((char *)object+0)=&lbl_802B8A04;*(unsigned int *)((char *)object+64)=0;*(unsigned int *)((char *)object+68)=0;*(unsigned char *)((char *)object+72)=0;*(unsigned char *)((char *)object+73)=0;*(float *)((char *)object+76)=lbl_80378AD0;*(float *)((char *)object+80)=lbl_80378AD0;*(float *)((char *)object+84)=lbl_80378AD0;*(unsigned char *)((char *)object+4)=0;return object;}
