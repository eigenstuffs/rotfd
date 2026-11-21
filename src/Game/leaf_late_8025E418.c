/* Original leaf operations. Provisional names and text-only ownership.
 * See docs/notes/game-leaf-late-continuation.md. */

extern unsigned int lbl_80378080;

unsigned int fn_8025E418(void) { return lbl_80378080; }

void fn_8025E420(void *object, unsigned int value) { lbl_80378080 = value; }
