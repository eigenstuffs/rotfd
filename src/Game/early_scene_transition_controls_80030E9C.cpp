/* Scene transition selection and native Handle lifetimes.
 * See docs/notes/game-early-scene-transition-controls.md. */
typedef unsigned long Word;
struct Handle_801F7F10 {union{Word word;struct{signed long tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Handle_8002B67C:Handle_801F7F10{~Handle_8002B67C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Node{char unknown00[0xDC];int count;Word unknownE0;void*value;};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{int count,capacity;Entry*entries;};
struct SoundPrefix{char unknown00[0x1C];};struct Sound:SoundPrefix{virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void s8();virtual void s9();virtual void s10();virtual void s11();virtual void reset(int,int,int);};
struct ModePrefix{char unknown00[0x7C];};struct Mode:ModePrefix{virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void s8();virtual void reset(int);virtual void s10();virtual void s11();virtual void s12();virtual void s13();virtual void s14();virtual void s15();virtual void s16();virtual void s17();virtual void s18();virtual void s19();virtual void s20();virtual void s21();virtual void s22();virtual void finish();};
struct UI{};struct SceneOwner{char unknown00[0x60];Handle_801F7F10 handle60;char unknown64[0x210-0x64];short state210;};struct Scene{char unknown00[0x15058];SceneOwner*owner;};
extern "C" struct Context{char unknown00[0x114];void*module;Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x154-0x128];Sound*sound;Mode*mode;char unknown15C[8];UI*ui;}lbl_801E9D24;
struct OwnerPrefix{char unknown00[8];};struct Owner:OwnerPrefix{virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void event(int);char unknown0C[0x60-0xC];Handle_801F7F10 handle60;int selected,mode;Handle_801F7F10 handle6C;char unknown70[0x88-0x70];Handle_801F7F10 handle88,handle8C,handle90;unsigned char active;};
extern "C" {void fn_800B720C(UI*,int);void fn_800B6C84(UI*,int,Word);Handle_8002B67C fn_800312D4(Owner*);void fn_80030A08(Owner*,const Handle_801F7F10&,int);}
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;const Entry*entries=lbl_801E9D24.manager->entries;int tag=entries[index].getTag();return tag==h.bits.tag?entries[index].object:0;}

struct TransitionZero_30E9C:Handle_801F7F10{TransitionZero_30E9C(){word=0;}~TransitionZero_30E9C(){}};
struct Handle_80020C04:TransitionZero_30E9C{Handle_80020C04(){word=0;}~Handle_80020C04(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C"{extern Word lbl_803777B4;void fn_800B3318(int);void fn_800A7840(Node*);void fn_800A84D8(Node*);void fn_80057294(SceneOwner*);void fn_80208C7C();void fn_80201F10(Node*,void*);void fn_8003125C(void*,void*,const Handle_80020C04&);}
extern "C" int fn_80030E9C(Owner*self,int selected,int mode){
 SceneOwner*owner=lbl_801E9D24.scene->owner;
 fn_800B720C(lbl_801E9D24.ui,1);lbl_801E9D24.sound->reset(0,0,0);
 signed char reset=1;if(lbl_801E9D24.scene->owner->state210==1)reset=0;
 switch(mode){
 case 0:fn_80030A08(self,self->handle6C,selected);break;
 case 1:fn_80030A08(self,self->handle88,selected);break;
 case 2:fn_80030A08(self,self->handle8C,selected);break;
 case 3:fn_80030A08(self,self->handle90,selected);break;
 case 4:fn_80030A08(self,self->handle6C,selected);fn_800B3318(1);break;
 }
 for(int i=0;i<resolve(fn_800312D4(self))->count;++i)if(i!=selected)fn_800B6C84(lbl_801E9D24.ui,i,lbl_803777B4);
 self->event(13);fn_800A7840(resolve(owner->handle60));fn_800A84D8(resolve(owner->handle60));
 lbl_801E9D24.mode->finish();lbl_801E9D24.mode->reset(7);
 if(reset)fn_80057294(lbl_801E9D24.scene->owner);
 fn_80208C7C();self->active=1;
 void*value=resolve(fn_800312D4(self))->value;
 fn_80201F10(resolve(fn_800312D4(self)),value);
 fn_8003125C(lbl_801E9D24.module,value,Handle_80020C04());return 1;
}
