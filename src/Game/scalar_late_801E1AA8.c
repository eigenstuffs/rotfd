/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-late.md. */
extern float lbl_8033E738[4];extern const float lbl_8037A58C;

void fn_801E1AA8(void) {lbl_8033E738[0]=lbl_8037A58C;lbl_8033E738[1]=lbl_8037A58C;lbl_8033E738[2]=lbl_8037A58C;lbl_8033E738[3]=lbl_8037A58C;}

/* Preserve the original startup table entry at 0x80299944. */
__declspec(section ".ctors")
static void (*const scalar_global_init_reference)(void) = fn_801E1AA8;
