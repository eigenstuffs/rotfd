/* Original indexed records, engine setup and allocation-header routines.
 * See docs/notes/game-engine-leaf.md. */

extern void fn_801EDB54(void *);

extern void fn_801EDD8C(void *);

void fn_801ED9FC(void *object) {if(*(unsigned short *)((char *)object+0xbc)&1){fn_801EDB54(object);fn_801EDD8C(object);*(unsigned short *)((char *)object+0xbc)|=256;*(unsigned short *)((char *)object+0xbc)^=5;}}

void fn_801EDA54(void *object) {if(*(unsigned short *)((char *)object+0xbc)&1){fn_801EDB54(object);fn_801EDD8C(object);*(unsigned short *)((char *)object+0xbc)|=32;*(unsigned short *)((char *)object+0xbc)^=5;}}
