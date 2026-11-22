struct Object;struct Control{char opaque00[0x1F8];Object*object;};extern "C"void fn_80024BCC(Object*);extern "C"void fn_80062A40(Control*self){fn_80024BCC(self->object);}
