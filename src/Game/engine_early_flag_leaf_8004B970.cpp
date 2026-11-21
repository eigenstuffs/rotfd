/* Original engine flag setup fragments with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-flag-leaf.md. */
struct View{char unknown00[0x38];unsigned long long flags;};
extern "C" void fn_8004B970(View*self){self->flags|=0x40000000ULL;}
