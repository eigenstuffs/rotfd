typedef unsigned long u32;
struct Handle{u32 word;};struct Object{char opaque00[0x58];Handle source58;char opaque5C[4];Handle target60;float value64;};
extern "C"{extern struct Context{char opaque00[0x118];void*manager118;}lbl_801E9D24;void fn_801F86C8(void*,const Handle*,short);float fn_8025E268(Object*,int);}
extern "C" void fn_8004EB04(Object*self){const Handle&source=self->source58;fn_801F86C8(lbl_801E9D24.manager118,&self->target60,-1);self->target60.word=source.word;fn_801F86C8(lbl_801E9D24.manager118,&source,1);self->value64=fn_8025E268(self,0);}
