/* Original short control delegates; see docs/notes/game-short-control-delegates.md. */
struct Object;struct Record{char opaque00[0x9C];signed char active;};struct Control{char opaque00[8];Object*object;Record*record;};extern "C"void fn_80094804(Object*);extern "C"void fn_8008A0A0(Control*self){fn_80094804(self->object);self->record->active=0;}
