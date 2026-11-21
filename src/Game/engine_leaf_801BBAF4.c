/* Original indexed records, engine setup and allocation-header routines.
 * See docs/notes/game-engine-leaf.md. */

static inline int append(void *object) {if(*(int *)((char *)object+0xb90)>=8)return 7;++*(int *)((char *)object+0xb90);return *(int *)((char *)object+0xb90)-1;}

void fn_801BBAF4(void *object,const float *a,const float *b,float f1,float f2,float f3,float f4,float f5) {if(*((signed char *)object+0x18)){int index=append(object);char *out=(char *)object+index*44;*(float *)(out+0xa30)=a[0];*(float *)(out+0xa34)=a[1];*(float *)(out+0xa38)=a[2];*(float *)(out+0xa3c)=b[0];*(float *)(out+0xa40)=b[1];*(float *)(out+0xa44)=b[2];*(float *)(out+0xa48)=f1;*(float *)(out+0xa4c)=f2;*(float *)(out+0xa50)=f3;*(float *)(out+0xa54)=f4;*(float *)(out+0xa58)=f5;}}
