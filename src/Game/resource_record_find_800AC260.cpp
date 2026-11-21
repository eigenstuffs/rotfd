/* Find the owner's selected 0x58-byte record by its leading signed key (fn_800AC260).
 * Matching notes: common-subexpression elimination is off for this function, and the
 * inlined lookup keeps its record pointer declared outside the loop; that keeps the
 * original `bne; b` exit and the key/offset/record register order (r4/r5/r6). */
typedef unsigned long Word;
struct Record{int key;Word unknown04;int index,count,current;signed char first,second,special;char unknown17[0x41];};
struct Owner{char unknown00[0x14];int count,capacity;Record*records;int current;char unknown24[0x128];float time;};
typedef char CheckRecordSize[sizeof(Record)==88?1:-1];
#pragma opt_common_subs off
inline Record*find(Owner*self,int key){Record*r;for(int i=0;i<self->count;++i){r=&self->records[i];if(key==r->key)return r;}return 0;}
extern "C" Record*fn_800AC260(Owner*self){if(self->current>-1)return find(self,self->current);return 0;}
#pragma opt_common_subs reset
