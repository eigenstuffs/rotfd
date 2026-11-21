/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

extern short lbl_8037757A;

int fn_8006C4C0(void *object,int amount) {lbl_8037757A+=amount;if(lbl_8037757A<0)lbl_8037757A=0;return 1;}

extern short lbl_80377578;

int fn_8006C4E4(void *object,int amount) {lbl_80377578+=amount;if(lbl_80377578<0)lbl_80377578=0;return 1;}
