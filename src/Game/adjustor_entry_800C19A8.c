/* Adjustor entry points for a secondary base subobject at +0x318.
 * The original bytes are MWCC C++ this-adjusting thunks (subi r3; b target)
 * emitted with a complete vtable; those vtables are still hand-written ABI
 * views that reference these entries by C name.  GC/1.3.2 has no sibling-call
 * optimisation, so this C view is built with GC/3.0a3, which emits the
 * identical eight-byte tail call. */
extern void fn_800C14A8(void *self);
void fn_800C19A8(char *self) { fn_800C14A8(self - 0x318); }
extern void fn_800C18EC(void *self);
void fn_800C19B0(char *self) { fn_800C18EC(self - 0x318); }
