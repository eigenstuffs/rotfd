struct Scene{char unknown00[0x15058];void*root;};
extern "C" struct Global{char unknown00[0x124];Scene*scene;}lbl_801E9D24;
struct Actor{char unknown00[0x38];unsigned long long flags;signed char hasFlags(unsigned long long mask)const{if(flags&mask)return 1;return 0;}};
struct Self{char unknown00[4];virtual void slot08();virtual void slot0C();virtual void slot10();virtual void*slot14();};
extern "C"{extern const float lbl_80378804;void*fn_8005EE10(Actor*);void fn_80067D0C(void*,Actor*,unsigned char,unsigned char);int fn_800596E4(void*,unsigned char,unsigned char);void*fn_8005E9A0();void fn_802073E8(void*,int,void*,float);}
extern "C" void fn_8006C994(Self*self,Actor*actor,int a,int b){
 if(actor->hasFlags(0x10000000ULL)){
  fn_80067D0C(fn_8005EE10(actor),actor,a,b);
 }else if(actor->flags&0x2000000ULL){
  float v=fn_800596E4(lbl_801E9D24.scene->root,a,b);
  fn_802073E8(self->slot14(),0xC1,fn_8005E9A0(),v);
 }else{
  fn_802073E8(self->slot14(),0x86,actor,(unsigned char)b);
 }
 fn_802073E8(actor,0xAB,self->slot14(),lbl_80378804);
}
