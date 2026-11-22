struct Owner{unsigned long word;unsigned short token;};
extern "C"struct Globals{char unknown00[0x144];void*manager;}lbl_801E9D24;
extern "C"unsigned short fn_801F4AC8(void*,Owner*);
extern "C"void fn_801ADF18(Owner*self){self->token=fn_801F4AC8(lbl_801E9D24.manager,self);}
