/* Original small callback control operations; see docs/notes/game-engine-callback-small-controls.md. */
typedef unsigned long u32;
struct Prefix{u32 unknown00;};
struct Observer:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void*slot14();};
extern "C"{extern Observer*lbl_803776B8;extern float lbl_80378560;void fn_802073E8(void*,int,void*,float);}
extern "C" void fn_8004D974(void*self,int event){if(lbl_803776B8)fn_802073E8(self,event,lbl_803776B8->slot14(),lbl_80378560);}
