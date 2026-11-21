/* Original indexed records, engine setup and allocation-header routines.
 * See docs/notes/game-engine-leaf.md. */

extern const char lbl_801EF5C8[];

extern void fn_801EF610(const void *,void *);

extern const char lbl_8028F698[];

extern void fn_8028F8F0(const void *,void *,unsigned int);

void *fn_801EB634(void *object,short release) {if(object){if(*(void **)object)fn_8028F8F0(lbl_8028F698,*(void **)object,*(unsigned int *)((char *)object+4));*(unsigned int *)object=0;*(unsigned int *)((char *)object+4)=0;*(unsigned int *)((char *)object+8)=0;if(release>0)fn_801EF610(lbl_801EF5C8,object);}return object;}
