/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

extern const float lbl_80378F78,lbl_80378F94;

void fn_800A64E0(void *object,signed char mode) {if(mode){*((signed char *)object+0x3d)=mode;*(float *)((char *)object+0x40)=lbl_80378F78;}else *(float *)((char *)object+0x40)=lbl_80378F94;}
