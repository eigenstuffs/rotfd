/* Original delegate; partial views documented in docs/notes/game-small-delegates-20261011b.md. */
struct Owner{unsigned long word;unsigned short token;};
extern "C"struct Globals{char unknown00[0x144];void*manager;}lbl_801E9D24;
extern "C"unsigned short fn_801F4F8C(void*,Owner*);
extern "C"void fn_801AE1DC(Owner*self){self->token=fn_801F4F8C(lbl_801E9D24.manager,self);}
