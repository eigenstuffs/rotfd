extern const float lbl_8037899C,lbl_803789C0;

void fn_8007622C(void *object,float amount,float rate) {if(lbl_8037899C==rate){*((unsigned char *)object+0x180)=0;*(float *)((char *)object+0x184)=lbl_8037899C;*(float *)((char *)object+0x188)=lbl_8037899C;*(float *)((char *)object+0x18c)=lbl_8037899C;}else{*((unsigned char *)object+0x180)=1;*(float *)((char *)object+0x184)=rate;*(float *)((char *)object+0x188)=lbl_803789C0*amount;}}
