/* Original delegate; partial views described in docs/notes/game-small-delegates-20261011.md. */
struct Owner{char unknown0[0x3C];unsigned long handle;};
extern "C" void fn_801F6AF8(void*);
extern "C" void fn_801AE21C(Owner*self){fn_801F6AF8(&self->handle);}
