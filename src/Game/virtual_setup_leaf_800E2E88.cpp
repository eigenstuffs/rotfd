typedef unsigned long Word;
typedef unsigned long long Flags;
struct Control{char opaque00[0x30];Flags flags;};
extern "C" void fn_8022A160(Control*);
extern "C" void slot18__16CSBPants_BRKMoveFv(Control*self){fn_8022A160(self);self->flags&=0xFFFFFFFF7E0001FFULL;self->flags|=0x2000ULL;}
