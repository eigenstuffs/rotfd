/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-early-setup-more.md. */
extern "C"{extern char lbl_802B4ECC[];extern unsigned int lbl_80377694[2];void __ct__14Agent_8002B5F4Fv(void*);}
struct View{char unknown00[8];void*vtable;char unknown0C[0x84];unsigned int field90,field94;};
extern "C"View*fn_8005BFC4(View*self){__ct__14Agent_8002B5F4Fv(self);self->vtable=lbl_802B4ECC;self->field90=-1;self->field94=-1;lbl_80377694[0]=0;lbl_80377694[1]=0;return self;}
