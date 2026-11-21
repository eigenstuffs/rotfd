/* Original leaf operations. Provisional names and text-only ownership.
 * See docs/notes/game-leaf-continuation.md. */

float fn_800949BC(const void *object) { return *(const float *)((const char *)object + (892)); }

void fn_800949C4(void *object, float value) { *(float *)((char *)object + (892)) = value; }

void fn_800949CC(void) { }
