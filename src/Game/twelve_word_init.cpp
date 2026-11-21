extern "C"{extern char lbl_802ED240[];void*fn_80248864(void*);}
struct TwelveWordView{char unknown00[8];void*table;char unknown0C[0xE0];unsigned long words[12];};
extern "C" TwelveWordView*fn_8026E7C4(TwelveWordView*self){fn_80248864(self);self->table=lbl_802ED240;self->words[0]=0;self->words[1]=0;self->words[2]=0;self->words[3]=0;self->words[4]=0;self->words[5]=0;self->words[6]=0;self->words[7]=0;self->words[8]=0;self->words[9]=0;self->words[10]=0;self->words[11]=0;return self;}
