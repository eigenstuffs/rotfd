/* Effect-array activation; see docs/notes/game-early-effect-array-activate.md. */
struct Handle_801F7F10{union{unsigned long value;struct{signed int tag:8,index:24;}bits;};};
struct EffectPrefix{char unknown00[8];};
struct EffectNode:EffectPrefix{
virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void prepare();
};
struct EffectEntry{EffectNode*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct EffectManager{int count,capacity;EffectEntry*entries;};
extern "C" struct EffectContext{char unknown00[0x118];EffectManager*manager;}lbl_801E9D24;
inline EffectNode*resolve(const Handle_801F7F10&h){int index=h.bits.index;EffectManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct EffectOwner{char unknown00[0x48];Handle_801F7F10*handles;};
extern "C"{signed char fn_80255618(EffectNode*);void fn_802554F4(EffectNode*);void fn_80255678(EffectNode*);}

extern "C" void fn_800E5254(EffectOwner*self,int count){
 if(fn_80255618(resolve(self->handles[2]))){
  resolve(self->handles[6])->prepare();
  fn_802554F4(resolve(self->handles[6]));
 }
 int i;
 for(i=0;i<count;++i){
  if(fn_80255618(resolve(self->handles[i+2]))){
   resolve(self->handles[i+2])->prepare();
   fn_802554F4(resolve(self->handles[i+2]));
  }
 }
 for(;i<3;++i)fn_80255678(resolve(self->handles[i+2]));
}
