extern const unsigned char lbl_802C939C[];

extern const unsigned char lbl_802C967C[];

extern void fn_80090084(void *object);

void *fn_800ED2B4(void *object,unsigned int arg4) {fn_80090084(object);*(const void * *)((char *)object+0)=lbl_802C967C;*(unsigned int *)((char *)object+8)=0;*(unsigned int *)((char *)object+12)=0;*(unsigned int *)((char *)object+8)=arg4;*(const void * *)((char *)object+0)=lbl_802C939C;*(unsigned char *)((char *)object+4)=1;return object;}
