extern const unsigned char lbl_802B9618[];

extern const unsigned char lbl_802B96F4[];

extern void fn_80090084(void *object);

void *fn_80094DDC(void *object,unsigned int arg4,unsigned int arg5) {fn_80090084(object);*(const void * *)((char *)object+0)=lbl_802B96F4;*(unsigned int *)((char *)object+8)=arg4;*(unsigned int *)((char *)object+12)=arg5;*(const void * *)((char *)object+0)=lbl_802B9618;*(unsigned char *)((char *)object+4)=1;return object;}
