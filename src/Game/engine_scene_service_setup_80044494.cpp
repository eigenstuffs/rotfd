/* Original scene service setup and callback guard; see docs/notes/game-engine-scene-service-setup.md. */
struct Prefix{char opaque00[8];};struct Owner:Prefix{virtual void v08();virtual void v0C();virtual void v10();virtual void v14();virtual void v18();virtual void v1C();virtual void v20();virtual void v24();virtual void v28(int);char opaque0C[0x2C];unsigned long long flags38;char opaque40[0x28];signed char active68;};
extern "C"{extern const float lbl_80378560;void fn_802073E8(Owner*,int,Owner*,float);}
extern "C" void fn_80044494(Owner*self){if((self->flags38&0x40000ULL)||self->active68)return;self->active68=1;self->v28(0);fn_802073E8(self,0x8F,self,lbl_80378560);}
