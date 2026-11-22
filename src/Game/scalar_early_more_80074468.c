extern const float lbl_80378958;

extern const unsigned char lbl_802B7F58[];

extern const unsigned char lbl_802B7F74[];

extern void fn_80090084(void *object);

void *fn_80074468(void *object,unsigned int arg4) {fn_80090084(object);*(const void * *)((char *)object+0)=lbl_802B7F74;*(unsigned int *)((char *)object+8)=0;*(unsigned int *)((char *)object+8)=arg4;*(const void * *)((char *)object+0)=lbl_802B7F58;*(float *)((char *)object+12)=lbl_80378958;*(float *)((char *)object+16)=lbl_80378958;*(unsigned char *)((char *)object+4)=1;return object;}
