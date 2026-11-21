/* Scene resource transition and retained native handles.
 * See docs/notes/game-scene-resource-transition.md. */
typedef unsigned long Word;
struct Handle_801F7F10 {union{Word word;struct{signed long tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct TransitionZero1_31328:Handle_801F7F10{TransitionZero1_31328(){word=0;}~TransitionZero1_31328(){}};struct TransitionZero2_31328:TransitionZero1_31328{TransitionZero2_31328(){word=0;}~TransitionZero2_31328(){}};struct TransitionZero3_31328:TransitionZero2_31328{TransitionZero3_31328(){word=0;}~TransitionZero3_31328(){}};
struct Handle_8002DE2C:TransitionZero3_31328 {Handle_8002DE2C(){word=0;}~Handle_8002DE2C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8002B67C:Handle_801F7F10{~Handle_8002B67C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Node{char unknown00[0xDC];int count;Word unknownE0;void*value;};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{int count,capacity;Entry*entries;};
struct SoundPrefix{char unknown00[0x1C];};struct Sound:SoundPrefix{virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void s8();virtual void s9();virtual void s10();virtual void s11();virtual void reset(int,int,int);};
struct ModePrefix{char unknown00[0x7C];};struct Mode:ModePrefix{virtual void s0();virtual void s1();virtual void s2();virtual void s3();virtual void s4();virtual void s5();virtual void s6();virtual void s7();virtual void s8();virtual void reset(int);virtual void s10();virtual void s11();virtual void s12();virtual void s13();virtual void s14();virtual void s15();virtual void s16();virtual void s17();virtual void s18();virtual void s19();virtual void s20();virtual void s21();virtual void s22();virtual void s23();virtual void finish();};
struct UI{};struct SceneOwner{char unknown00[0x60];Handle_801F7F10 handle60;};struct Scene{char unknown00[0x15058];SceneOwner*owner;};
extern "C" struct Context{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x154-0x128];Sound*sound;Mode*mode;char unknown15C[8];UI*ui;}lbl_801E9D24;
struct Owner{char unknown00[0x60];Handle_801F7F10 handle60;int selected,mode;char unknown6C[0x7C-0x6C];Handle_801F7F10 handle7C;char unknown80[0x94-0x80];unsigned char active;};
extern "C" {void fn_800B720C(UI*,int);void fn_8025ECD8(Owner*,int);void fn_800B6C84(UI*,int,Word);extern Word lbl_803777B0;extern int lbl_803777B8;Handle_8002B67C fn_800312D4(Owner*);void fn_80030A08(Owner*,const Handle_8002DE2C&,int);Node*fn_801F7EB8(const Handle_801F7F10*);void fn_800A7798(Node*);void fn_80057100(SceneOwner*,int);void fn_80208C24();void fn_80201F94(Node*,void*);}
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;const Entry*entries=lbl_801E9D24.manager->entries;int tag=entries[index].getTag();return tag==h.bits.tag?entries[index].object:0;}
extern "C" int fn_80031328(Owner*self){
 lbl_801E9D24.sound->reset(0,0,0);fn_800B720C(lbl_801E9D24.ui,0);fn_8025ECD8(self,13);
 for(int i=0;i<resolve(fn_800312D4(self))->count;++i)if(i!=self->selected)fn_800B6C84(lbl_801E9D24.ui,i,lbl_803777B0);
 if(self->mode==lbl_803777B8){fn_80030A08(self,Handle_8002DE2C(),0);fn_800B6C84(lbl_801E9D24.ui,0,lbl_803777B8);}else if(fn_801F7EB8(&self->handle7C))fn_80030A08(self,Handle_8002DE2C(),0);
 fn_800A7798(resolve(lbl_801E9D24.scene->owner->handle60));lbl_801E9D24.mode->finish();lbl_801E9D24.mode->reset(0);fn_80057100(lbl_801E9D24.scene->owner,-1);fn_80208C24();self->active=0;
 void*value=resolve(fn_800312D4(self))->value;fn_80201F94(resolve(fn_800312D4(self)),value);return 1;
}
