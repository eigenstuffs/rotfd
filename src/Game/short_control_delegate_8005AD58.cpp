/* Original short control delegates; see docs/notes/game-short-control-delegates.md. */
struct Handle;struct Array{int count,capacity;Handle*elements;};struct Control{char opaque00[0x280];Array array;};extern "C"void fn_80059D58(Control*);extern "C"const Array*fn_8005AD58(Control*self){if(!self->array.count)fn_80059D58(self);return &self->array;}
