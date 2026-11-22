typedef unsigned long Word;
typedef unsigned long long Flags;
struct Control{char opaque00[0x30];Flags flags;};
extern "C" void fn_80229EE0(Control*);
extern "C" void fn_800E2EE4(Control*self){fn_80229EE0(self);self->flags&=0xFFFFFFFF7E0001FFULL;self->flags|=0x2000ULL;}
