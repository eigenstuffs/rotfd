/* Original short control delegates; see docs/notes/game-short-control-delegates.md. */
struct Object;struct Control{char opaque00[0xC];Object*object;};extern "C"void fn_80025418(Object*,void*);extern "C"void fn_800261BC(Control*self){fn_80025418(self->object,0);}
