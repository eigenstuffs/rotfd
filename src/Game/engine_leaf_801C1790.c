/* Original indexed records, engine setup and allocation-header routines.
 * See docs/notes/game-engine-leaf.md. */

void fn_801C1790(void *object,void *unused,unsigned long long mask,int index) {*(unsigned long long *)(*(char **)((char *)object+0x188)+index*168+0x38)|=mask;}

unsigned long long fn_801C17C0(void *object,int index) {return *(unsigned long long *)(*(char **)((char *)object+0x188)+index*168+0x38);}
