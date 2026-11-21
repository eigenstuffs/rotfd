/* Original engine setup and record routines with private observed layouts.
 * See docs/notes/game-scalar-middle-more.md. */

extern void *memcpy(void *,const void *,unsigned int);

void *fn_801D8458(void *object,void *node,void *out) {return memcpy(out,*(char **)((char *)object+0xe8)+*(int *)((char *)node+0x8c)*192,192);}

extern void fn_801D8068(void *,void *,void *,void *);

void fn_801D8494(void *object,void *a,void *b) {fn_801D8068(object,a,b,*(void **)((char *)object+0x7c));}

void *fn_801D84B8(void *object,void *node,void *out) {return memcpy(out,*(char **)((char *)object+0xe8)+*(int *)((char *)node+0x8c)*192,192);}

extern void __construct_array(void *,void (*)(void *),void (*)(void *),unsigned int,unsigned int);

extern void __ct__16Vector3_801D5330Fv(void *);

extern void fn_801F0C68(void *,void *,int);

void fn_801D84F4(void *object,void *node,void *out) {float vectors[16][3];__construct_array(vectors,__ct__16Vector3_801D5330Fv,0,12,16);memcpy(vectors,*(char **)((char *)object+0xe8)+*(int *)((char *)node+0x8c)*192,192);fn_801F0C68(out,vectors,16);}
