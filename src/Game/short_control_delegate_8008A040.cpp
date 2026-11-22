struct Object;struct Control{char opaque00[8];Object*object;};extern "C"void fn_8009486C(Object*);extern "C"void fn_8008A040(Control*self){fn_8009486C(self->object);}
