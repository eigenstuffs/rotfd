extern const float lbl_80379048;

extern const unsigned char lbl_802BCEF0[];

extern const unsigned char lbl_802BCF9C[];

extern void fn_80090084(void *object);

void *fn_800AB804(void *object,unsigned int arg4) {fn_80090084(object);*(const void * *)((char *)object+0)=lbl_802BCF9C;*(unsigned int *)((char *)object+8)=0;*(unsigned int *)((char *)object+12)=0;*(float *)((char *)object+16)=lbl_80379048;*(unsigned int *)((char *)object+8)=arg4;*(const void * *)((char *)object+0)=lbl_802BCEF0;*(unsigned char *)((char *)object+20)=0;*(unsigned char *)((char *)object+4)=1;return object;}
