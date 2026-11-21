/* Original short control delegates; see docs/notes/game-short-control-delegates.md. */
struct Control{char opaque00[0xB8];int count;};extern "C"{void fn_80259258(Control*);void fn_80021624(Control*);}extern "C"void fn_8002134C(Control*self){fn_80259258(self);self->count=0;fn_80021624(self);}
