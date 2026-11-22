/* Adjustor entry points for a secondary base subobject at +0x1F8.
 * The original bytes are MWCC C++ this-adjusting thunks (subi r3; b target)
 * emitted with a complete vtable; those vtables are still hand-written ABI
 * views that reference these entries by C name.  GC/1.3.2 has no sibling-call
 * optimisation, so this C view is built with GC/3.0a3, which emits the
 * identical eight-byte tail call. */
extern void fn_800AF58C(void *self);
void fn_800AFCB0(char *self) { fn_800AF58C(self - 0x1F8); }
extern void __dt__15Object_800AF348Fv(void *self, int flags);
void fn_800AFCB8(char *self, int flags) { __dt__15Object_800AF348Fv(self - 0x1F8, flags); }
