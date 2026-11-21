/* Scene transition and reset controls: closes the previous scene actor when the
 * state changes, logs the transition, saves audio/actor state on first entry,
 * sends the named scene event for the new state, and polls the reset switch and
 * the reset button chord. fn_800BE8AC resets the same globals on shutdown. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
extern "C"{void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];Word fn_801F7EB8(const Handle_801F7F10*);Word fn_801F948C(void*,const char*);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8003F47C:Handle_8001FF78{Handle_8003F47C(){word=0;}~Handle_8003F47C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Actor;
struct Entry{Actor*object;Word unknown04[2];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{Word unknown00[2];Entry*entries;};
/* One actor class serves both the current scene actor (+0x114) and the engine's
 * saved actor (+0x15058); the original reuses one local for both. */
struct ActorStorage{char unknown00[0x68];Handle_801F7F10 handle;char unknown6C[0x230-0x6C];signed char active;char unknown231[0x278-0x231];};
struct Actor:ActorStorage{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void close();virtual void pause();
virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();
virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
virtual void slot68();virtual void setTarget(const Handle_8003F47C&);
char unknown27C[0x2F6-0x27C];signed char pendingFlag;};
struct ScreenStorage{char unknown00[0x7C];};
struct Screen:ScreenStorage{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();
virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();
virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void clear();};
struct WidgetStorage{char unknown00[8];};
struct Widget:WidgetStorage{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void clear();};
struct InputStorage{char unknown00[0x1C];};
struct Input:InputStorage{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();
virtual void update(float);virtual signed char pressed(int);virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
virtual void reset(int,int,int);};
struct Audio{char unknown00[0x18];signed char state;};
struct Engine{char unknown00[0x15048];signed char pending,saved;char unknown1504A[0xE];Actor*actor;Word unknown1505C;Audio*audio;void*events;};
extern "C"struct Global{char unknown00[0x110];void*log;Actor*scene;Manager*manager;char unknown11C[8];Engine*engine;char unknown128[0x2C];Input*input;Screen*screen;Widget*widget;}lbl_801E9D24;
struct Key{Word word;Key(const char*s){word=fn_801F948C(this,s);}};
extern "C"{
extern const char agent_type_registry_CMsgBoxManipulator[];
extern int lbl_803754B8;
extern Word lbl_80378168,lbl_803777A4;
extern signed char lbl_803777A0,lbl_803777A1,lbl_803777A2,lbl_803777A8,lbl_80377FC1;
extern float lbl_803794D4;
void fn_801FA014(void*,const char*,...);void fn_802139D8(Audio*);void*fn_800AC260(Actor*);void fn_80057294(Actor*);
void fn_800C3934(void*,int,Key,int,int,int,int);void fn_800BEC04();int OSGetResetSwitchState();Word OSGetTick();void fn_801EBE14();}
inline Actor*resolve(const Handle_801F7F10&h){int i=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[i].getTag();return tag==h.bits.tag?m->entries[i].object:0;}
inline bool resetChordHeld(){return lbl_801E9D24.input->pressed(11)&&lbl_801E9D24.input->pressed(1)&&lbl_801E9D24.input->pressed(3);}
extern "C"void fn_800BE2CC(int state){
 Word pool=(Word)agent_type_registry_CMsgBoxManipulator;
 Actor*actor=lbl_801E9D24.scene;
 if(lbl_803754B8!=state&&actor){
  Handle_8003F47C target;actor->setTarget(target);
  if(actor->active)actor->pause();
  actor->close();
 }
 if(lbl_803754B8!=state){
  fn_801FA014(lbl_801E9D24.log,(const char*)(pool+0xF34),lbl_803754B8,state);
  fn_801FA014(lbl_801E9D24.log,(const char*)(pool+0xF5C),lbl_80378168);
 }
 if(!lbl_803777A0){
  lbl_80377FC1=1;fn_801FA014(lbl_801E9D24.log,(const char*)(pool+0xF7C));
  lbl_803777A8=lbl_801E9D24.engine->audio->state;fn_802139D8(lbl_801E9D24.engine->audio);
  if(lbl_801E9D24.widget)lbl_801E9D24.widget->clear();
  lbl_801E9D24.screen->clear();
  if(lbl_801E9D24.engine->actor){
   lbl_801E9D24.engine->pending=lbl_801E9D24.engine->actor->pendingFlag;
   actor=lbl_801E9D24.engine->actor;
   void*value=fn_801F7EB8(&actor->handle)?fn_800AC260(resolve(actor->handle)):0;
   lbl_801E9D24.engine->saved=value!=0;
   if(lbl_801E9D24.engine->pending){fn_80057294(lbl_801E9D24.engine->actor);fn_801FA014(lbl_801E9D24.log,(const char*)(pool+0xF88));}
   else fn_801FA014(lbl_801E9D24.log,(const char*)(pool+0xFB4));
  }
  lbl_801E9D24.input->reset(0,0,0);lbl_803777A0=1;
 }
 if(state!=lbl_803754B8){
  switch(state){
  case 0:fn_800C3934(lbl_801E9D24.engine->events,0,Key((const char*)(pool+0xFD4)),6,0,0,0);fn_800BEC04();break;
  case 1:fn_800C3934(lbl_801E9D24.engine->events,0,Key((const char*)(pool+0xFE8)),6,0,0,0);fn_800BEC04();break;
  case 2:fn_800C3934(lbl_801E9D24.engine->events,0,Key((const char*)(pool+0xFF8)),6,0,0,0);fn_800BEC04();break;
  case 3:fn_800C3934(lbl_801E9D24.engine->events,0,Key((const char*)(pool+0x100C)),6,0,0,0);fn_800BEC04();break;
  case 4:fn_800C3934(lbl_801E9D24.engine->events,0,Key((const char*)(pool+0x101C)),6,0,0,0);fn_800BEC04();for(;;){}
  default:fn_800C3934(lbl_801E9D24.engine->events,0,Key((const char*)(pool+0x102C)),6,0,0,0);fn_800BEC04();break;
  }
 }
 signed char reset=OSGetResetSwitchState();
 if(lbl_803777A1!=reset){if(!reset){lbl_803777A1=0;fn_801EBE14();}lbl_803777A1=reset;}
 lbl_801E9D24.input->update(lbl_803794D4);
 signed char held=resetChordHeld();
 if(held&&lbl_803777A2){
  if(!lbl_803777A4)lbl_803777A4=OSGetTick();
  else if((OSGetTick()-lbl_803777A4)/((*(Word*)0x800000F8/4)/1000)>500){lbl_803777A4=0;fn_801EBE14();}
 }else lbl_803777A4=0;
 lbl_803777A2=held;lbl_803754B8=state;fn_800BEC04();
}
