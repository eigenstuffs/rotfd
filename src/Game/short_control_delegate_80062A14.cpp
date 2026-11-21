/* Original short control delegates; see docs/notes/game-short-control-delegates.md. */
struct Object;struct Control{char opaque00[0x1F8];Object*object;};extern "C"void fn_80024C00(Object*);extern "C"void fn_80062A14(Control*self){if(self->object)fn_80024C00(self->object);}
