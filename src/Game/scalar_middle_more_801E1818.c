/* Original engine setup and record routines with private observed layouts.
 * See docs/notes/game-scalar-middle-more.md. */

extern void fn_801E2E94(void *,int,int,int,int);

extern float lbl_80377FA8;

extern const float lbl_8037A590;

int fn_801E1818(void *object,int a,int b) {*(int *)((char *)object+0x218)=a;*(int *)((char *)object+0x21c)=b;fn_801E2E94((char *)object+0x1c8,0,0,a,b);*(void **)((char *)object+0x210)=object;lbl_80377FA8=lbl_8037A590;return 1;}
