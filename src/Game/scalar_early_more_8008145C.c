extern const float lbl_80378AD0;

extern const unsigned char lbl_802B9294[];

extern const unsigned char lbl_802B92B0[];

extern void fn_80090084(void *object);

void *fn_8008145C(void *object,unsigned int arg4,unsigned int arg5) {fn_80090084(object);*(const void * *)((char *)object+0)=lbl_802B92B0;*(unsigned int *)((char *)object+8)=0;*(unsigned int *)((char *)object+12)=0;*(unsigned int *)((char *)object+8)=arg4;*(unsigned int *)((char *)object+12)=arg5;*(const void * *)((char *)object+0)=lbl_802B9294;*(float *)((char *)object+64)=lbl_80378AD0;*(unsigned char *)((char *)object+4)=1;return object;}
