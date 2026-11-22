#include "Game/costume_native_operation_records.h"





extern const unsigned char lbl_802B92B0[];

extern void fn_80090084(void *object);

void *fn_8008A168(void *object,unsigned int arg4,unsigned int arg5) {fn_80090084(object);*(const void * *)((char *)object+0)=lbl_802B92B0;*(unsigned int *)((char *)object+8)=0;*(unsigned int *)((char *)object+12)=0;*(unsigned int *)((char *)object+8)=arg4;*(unsigned int *)((char *)object+12)=arg5;*(const void * *)((char *)object+0)=&lbl_802B8B10;*(const void * *)((char *)object+0)=&lbl_802B8AF0;*(unsigned char *)((char *)object+4)=0;return object;}
