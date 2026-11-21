/* Original context-derived vector output; see docs/notes/game-motion-scalar-ease.md. */
/* Motion input and controlled direction update; see docs/notes/game-early-motion-input-update.md. */
struct Handle{union{unsigned long value;struct{signed int tag:8,index:24;}bits;};};struct Vec3{float x,y,z;};
struct Actor{char unknown0[0x318];char controller;};struct Entry{Actor*object;char unknown4[8];signed char tag;char unknownD[3];signed char getTag()const{return tag;}};struct Manager{int count,capacity;Entry*entries;};
extern "C"struct Global{char unknown0[0x118];Manager*manager;char unknown11C[0x164-0x11C];void*settings;}lbl_801E9D24;
inline Actor*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct Self{char unknown0[0x24];Handle actor;char unknown28[0xCC-0x28];float timerCC;int kind;char unknownD4[4];Vec3 direction;char unknownE4[4];signed char flagE8,flagE9;char unknownEA[6];float timerF0;Vec3 target;char unknown100[0xC];signed char changed;char unknown10D[3];float amount;char unknown114[0x130-0x114];signed char flag130,flag131;char unknown132[0x175-0x132];signed char activated;char unknown176[0x1D0-0x176];float minimum,maximum;char unknown1D8[5];signed char enabled;char unknown1DE[0x21C-0x1DE];float height;char unknown220[0xC];float elapsed;};
extern "C"{signed char fn_80075F50(Self*);signed char fn_8007D604(void*,int);float fn_80079C34(Self*);void fn_800792A0(Self*,float);extern const float lbl_803789D4,lbl_803789F8,lbl_803789C8,lbl_803789F4,lbl_803789FC;}
extern "C" void fn_80077A48(Self*self,float delta) {
 if(self->kind==0) {
  if(fn_80075F50(self)==1)self->flag131=0;
  if(!self->flag131) {
   float amount=fn_80079C34(self);
   float rate=lbl_803789D4;
   if(fn_8007D604(&resolve(self->actor)->controller,0x29))rate=lbl_803789F8;
   if(amount>lbl_803789C8) { float step=-rate*delta;if(amount+step>lbl_803789C8)amount+=step;else amount=lbl_803789C8; }
   else if(amount<=lbl_803789C8) { float step=rate*delta;if(amount+step<lbl_803789C8)amount+=step;else amount=lbl_803789C8; }
   fn_800792A0(self,amount);
  } else if(self->elapsed>=lbl_803789F4) {
   if(fn_80079C34(self)<lbl_803789FC)fn_800792A0(self,lbl_803789FC);
  }
 }
}
