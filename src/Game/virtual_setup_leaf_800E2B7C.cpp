typedef unsigned long Word;
typedef unsigned long long Flags;
struct Control{char opaque00[0x30];Flags flags;};
extern "C" void fn_80224A10(Control*);
extern "C" void slot18__12CSBPantsMoveFv(Control*self){fn_80224A10(self);self->flags&=0xFFFFFFFF7E0001FFULL;self->flags|=0x2400ULL;}
