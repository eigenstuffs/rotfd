extern const float lbl_8037B20C;

void fn_80235EBC(void *object,int mode) {if(*(signed char *)((char *)object+0x5d))return;*(float *)((char *)object+0x88)=lbl_8037B20C;*((unsigned char *)object+0x5d)=1;*(int *)((char *)object+0xa8)=mode;if(*(int *)((char *)object+0xa8)!=1)*(int *)((char *)object+0xa4)=0;}
