/* Original delegate; partial views described in docs/notes/game-small-delegates-20261011.md. */
struct Owner{char unknown0[0x3C];unsigned long action[4];};
extern "C" void fn_801F7154(void*);
extern "C" void fn_801AEFD0(Owner*self){fn_801F7154(&self->action);}
