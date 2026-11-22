extern const unsigned char lbl_802B84BC[];

extern const unsigned char lbl_802B852C[];

extern void fn_80090084(void *object);

void *fn_80080AD4(void *object,unsigned int arg4) {fn_80090084(object);*(const void * *)((char *)object+0)=lbl_802B852C;*(unsigned int *)((char *)object+8)=0;*(unsigned int *)((char *)object+8)=arg4;*(const void * *)((char *)object+0)=lbl_802B84BC;*(unsigned char *)((char *)object+4)=1;return object;}
