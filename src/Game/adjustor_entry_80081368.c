/* Adjustor entry points for a secondary base subobject at +0x318.
 * The original bytes are MWCC C++ this-adjusting thunks (subi r3; b target)
 * emitted with a complete vtable; those vtables are still hand-written ABI
 * views that reference these entries by C name.  GC/1.3.2 has no sibling-call
 * optimisation, so this C view is built with GC/3.0a3, which emits the
 * identical eight-byte tail call. */
extern void configureCallbacks__15CProjectileMoveFv(void *self);
void fn_80081368(char *self) { configureCallbacks__15CProjectileMoveFv(self - 0x318); }
extern void __dt__15CProjectileMoveFv(void *self, int flags);
void fn_80081370(char *self, int flags) { __dt__15CProjectileMoveFv(self - 0x318, flags); }
