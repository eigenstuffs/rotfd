struct TokenStopPrefix{char unknown00[0x7C];};
struct TokenStopManager:TokenStopPrefix{
virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void slot16();virtual void stop(const char*);
};
struct TokenStopContext{char unknown00[0x110];void*diagnostics;char unknown114[0x44];TokenStopManager*manager;};
struct TokenStopActor{char unknown00[0x108];int selection;char unknown10C[0x1EA];unsigned char enabled;};
extern "C"{extern TokenStopContext lbl_801E9D24;extern const char lbl_8029B240[];extern const char lbl_8029ACA8[][20];void fn_801FA014(void*,const char*,...);}
extern "C" void fn_80057294(TokenStopActor*self){
 self->enabled=0;
 if(self->selection!=-1){
  fn_801FA014(lbl_801E9D24.diagnostics,lbl_8029B240,lbl_8029ACA8[self->selection]);
  lbl_801E9D24.manager->stop(lbl_8029ACA8[self->selection]);
  self->selection=-1;
 }
}
