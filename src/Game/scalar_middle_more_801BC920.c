/* Original engine setup and record routines with private observed layouts.
 * See docs/notes/game-scalar-middle-more.md. */

extern signed char slot1C__12BaseObject_ZFv(void *);

signed char fn_801BC920(void *object) {return !!slot1C__12BaseObject_ZFv(object);}

extern void slot18__11Activable_ZFv(void *);

extern void fn_80213920(void *,int);

void fn_801BC954(void *object) {slot18__11Activable_ZFv(object);fn_80213920(object,5);}
