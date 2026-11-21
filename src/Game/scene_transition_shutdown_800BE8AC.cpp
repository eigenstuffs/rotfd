/* Scene shutdown: logs the exit, restores saved audio/screen state, writes the
 * pending save when allowed, closes the open scene and resets the scene
 * transition globals shared with fn_800BE2CC. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();Handle_801F7F10(int){bits.index=0;bits.tag=0;}~Handle_801F7F10();};
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Handle_80020478:Handle_801F7F10{~Handle_80020478(){}};
struct Handle_80020834:Handle_80020478{~Handle_80020834(){}};
struct Handle_8003E120:Handle_80020834{~Handle_8003E120(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8003F47C:Handle_8001FF78{Handle_8003F47C(){word=0;}~Handle_8003F47C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Node{char unknown00[0x7C];Handle_801F7F10 related;};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
struct OwnerPrefix{char unknown00[0x230];signed char active;char unknown231[0x278-0x231];};
struct Owner:OwnerPrefix{
virtual void s08();virtual void s0C();virtual void s10();virtual void s14();virtual void detach();virtual void stop();
virtual void s20();virtual void s24();virtual void s28();virtual void s2C();virtual void s30();virtual void s34();
virtual void s38();virtual void s3C();virtual void s40();virtual void s44();virtual void s48();virtual void s4C();
virtual void s50();virtual void s54();virtual void s58();virtual void s5C();virtual void s60();virtual void s64();
virtual void s68();virtual void clear(const Handle_8003F47C&);};
struct EndPrefix{char unknown00[8];};
struct End:EndPrefix{virtual void s08();virtual void s0C();virtual void s10();virtual void s14();virtual void s18();virtual void s1C();virtual void finish();};
struct ModePrefix{char unknown00[0x7C];};
struct Mode:ModePrefix{
virtual void s08();virtual void s0C();virtual void s10();virtual void s14();virtual void s18();virtual void s1C();
virtual void s20();virtual void s24();virtual void s28();virtual void s2C();virtual void s30();virtual void s34();
virtual void s38();virtual void s3C();virtual void s40();virtual void s44();virtual void s48();virtual void s4C();
virtual void s50();virtual void s54();virtual void s58();virtual void s5C();virtual void s60();virtual void s64();
virtual void finish();};
struct Scene{char unknown00[0x15048];signed char pending,saved;char unknown1504A[2];int mode;char unknown15050[8];void*actor;void*unused;void*audio;void*events;};
extern "C" struct Context{char unknown00[0x110];void*log;Owner*owner;Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x30];Mode*mode;End*end;}lbl_801E9D24;
extern "C"{
extern const char agent_type_registry_CMsgBoxManipulator[];
extern Word lbl_80378168,lbl_803777A4;
extern signed char lbl_803777A0,lbl_803777A8,lbl_80377788,lbl_80377FC1,lbl_803777A1,lbl_803777A2;
extern int lbl_803754B8;
void fn_801FA014(void*,const char*,...);void fn_800C2700(void*);void fn_800C2540(void*);
Handle_8003E120 fn_800BCEF8(Scene*);void fn_80057100(void*,int);void fn_801EBB9C();}
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline unsigned char operator==(const Handle_801F7F10&a,const Handle_801F7F10&b){Node*x=resolve(a);return x==resolve(b);}
extern "C" void fn_800BE8AC(const char*name){
 Word pool=(Word)agent_type_registry_CMsgBoxManipulator;
 fn_801FA014(lbl_801E9D24.log,(const char*)(pool+0x1044),name);
 fn_801FA014(lbl_801E9D24.log,(const char*)(pool+0x1058),lbl_80378168);
 if(lbl_803777A0){
  fn_800C2700(lbl_801E9D24.scene->events);
  if(lbl_803777A8)fn_800C2540(lbl_801E9D24.scene->audio);
  unsigned char allowed=lbl_801E9D24.scene->mode>0;
  (allowed=allowed?resolve(fn_800BCEF8(lbl_801E9D24.scene))->related==Handle_801F7F10(0):allowed)||(allowed=(bool)lbl_80377788);
  if(allowed){
   if(lbl_801E9D24.scene->saved)fn_801FA014(lbl_801E9D24.log,(const char*)(pool+0x1074));
   if(lbl_801E9D24.scene->pending&&!lbl_801E9D24.scene->saved){
    fn_80057100(lbl_801E9D24.scene->actor,-1);lbl_801E9D24.scene->pending=0;
    fn_801FA014(lbl_801E9D24.log,(const char*)(pool+0x1098));
   }
  }
  lbl_801E9D24.mode->finish();
  Owner*owner=lbl_801E9D24.owner;
  if(owner){Handle_8003F47C empty;owner->clear(empty);if(owner->active)owner->stop();owner->detach();fn_801EBB9C();}
  if(lbl_801E9D24.end)lbl_801E9D24.end->finish();
 }
 lbl_803777A0=0;lbl_80377FC1=0;lbl_803777A1=0;lbl_803777A2=0;lbl_803777A4=0;lbl_803754B8=-1;
}
