typedef unsigned long Word;
typedef unsigned long long Flags;
struct Control{char opaque00[0x30];Flags flags;};
extern "C" void slot34__13ObjectThrow_ZFv(Control*);
extern "C" void slot34__16CSBPants_BRKMoveFv(Control*self){slot34__13ObjectThrow_ZFv(self);self->flags&=0xFFFFFFFF7E0001FFULL;self->flags|=0x2000ULL;}
