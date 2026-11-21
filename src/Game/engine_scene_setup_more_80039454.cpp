/* Original scene setup and enum controls; see docs/notes/game-engine-scene-setup-more.md. */
extern "C"{void __ct__24CallbackControl_802ECC00Fv(void*);extern char lbl_802B29D0[],lbl_802B230C[];}
struct View{char opaque00[8];void*vptr08;char opaque0C[0x2C];unsigned long long flags38;char opaque40[0x46];unsigned short field86;char byte88;char opaque89[3];unsigned long words8C[20];unsigned long fieldDC;};
extern "C" View*fn_80039454(View*self){__ct__24CallbackControl_802ECC00Fv(self);self->vptr08=lbl_802B29D0;self->field86=1;self->flags38&=0xFFFFFFFFFFFFFFFBULL;self->flags38|=0x20000000ULL;self->flags38|=0x80000000000ULL;self->vptr08=lbl_802B230C;self->byte88=0;self->fieldDC=0;for(int i=0;i<20;i++)self->words8C[i]=0;return self;}
