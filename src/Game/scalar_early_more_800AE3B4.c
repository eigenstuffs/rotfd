extern const unsigned char lbl_802BD500[];

extern const unsigned char lbl_802BD518[];

extern void fn_80090084(void *object);

void *fn_800AE3B4(void *object,unsigned int arg4) {fn_80090084(object);*(const void * *)((char *)object+0)=lbl_802BD518;*(unsigned int *)((char *)object+8)=0;*(unsigned int *)((char *)object+8)=arg4;*(const void * *)((char *)object+0)=lbl_802BD500;*(unsigned char *)((char *)object+4)=1;return object;}
