/* Original engine setup and record routines with private observed layouts.
 * See docs/notes/game-scalar-middle-more.md. */

extern char *strcpy(char *,const char *);

void fn_801B4BB8(void *object,const char *name) {if(name)strcpy((char *)object+0x38,name);else *((char *)object+0x38)=0;}
