/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

extern float lbl_802F40F8[3];

extern const float lbl_80378240,lbl_8037824C;

void fn_80024DB4(void) {lbl_802F40F8[0]=lbl_80378240;lbl_802F40F8[1]=lbl_8037824C;lbl_802F40F8[2]=lbl_80378240;}

__declspec(section ".ctors")
static void (*const scalar_global_init_reference)(void) = fn_80024DB4;
