/* Original indexed records, engine setup and allocation-header routines.
 * See docs/notes/game-engine-leaf.md. */

extern const float lbl_8037A2A4;

static inline void put3(float *out,float x,float y,float z) {out[0]=x;out[1]=y;out[2]=z;}

struct Record {char pad[0x94];};

static inline void reset_record(struct Record *record) {
char *p=(char *)record;
*(float *)(p+0x7c)=lbl_8037A2A4;*(float *)(p+0x80)=lbl_8037A2A4;
*(float *)(p+0x20)=lbl_8037A2A4;*(float *)(p+0x24)=lbl_8037A2A4;*(float *)(p+0x28)=lbl_8037A2A4;
*(float *)(p+4)=*(float *)(p+0x2c);*(float *)(p+8)=*(float *)(p+0x30);*(float *)(p+0xc)=*(float *)(p+0x34);*(float *)(p+0x10)=*(float *)(p+0x38);
put3((float *)(p+8),-*(float *)(p+8),-*(float *)(p+0xc),-*(float *)(p+0x10));
}

void fn_801BC7DC(void *object) {struct Record *records=(struct Record *)((char *)object+0x24);int i;for(i=0;i<16;++i)reset_record(&records[i]);}
