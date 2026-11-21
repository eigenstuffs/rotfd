/* VoiceOverData::Update (fn_800ACB3C): advance the selected voice-over
 * record's text timer, start its RTC once, start its speech stream once,
 * and when both text and sound are finished, end the record and follow
 * its successor.  Strings are addressed through the pooled base
 * lbl_8029EFC0 (+0x68 "Context Hack", +0x78 RTC error, +0xA0 speech path,
 * +0xB4/+0xFC Update diagnostics); the TU-local sdata2 strings "\\"
 * (lbl_803790BC) and ".DSP" (lbl_803790C0) and the 0.0f pool entry
 * lbl_803790A8 stay external. */
typedef unsigned long Word;

struct Handle{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};

struct Prefix{char unknown00[8];};
struct Record_8007D604{int word;};
struct Object:Prefix{
 virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void stop(int);virtual void destroy(int);virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23();virtual void slot24();virtual void slot25();virtual void slot26();virtual void slot27();virtual void slot28();virtual void slot29();virtual void slot30();virtual void slot31();virtual void slot32();virtual void slot33();virtual void slot34();virtual void slot35();virtual void slot36();virtual const Handle&getHandle(int);
 char unknown0C[0x14];Handle handle20;char unknown24[0x4C];Handle handle70;char unknown74[0x30];Handle*rtcOwner;char unknownA8[8];Handle*related;char unknownB4[0x1C];int rtcCount;char unknownD4[0x244];Record_8007D604 record;
};
struct Entry{Object*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}Object*get(int expected)const{int current=getTag();return current==expected?object:0;}};
struct Manager{int count,capacity;Entry*entries;};
struct SceneOwner{char unknown00[0x60];Handle handle;};
struct Scene{char unknown00[0x15058];SceneOwner*owner;};
struct Related{char unknown00[0x1C];Handle*handle;};
struct DevicePrefix{char unknown00[0x7C];};
struct Device:DevicePrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void play(const char*,int,const Handle_801F7F10&,const Handle_801F7F10&);virtual void set(void*);virtual signed char isPlaying(const char*);};
struct Slot{int key;};
struct Service{char unknown00[0x1C];Slot*current;const int&get(int index){return current[index].key;}};
struct Context{char unknown00[0x110];void*logger;char unknown114[4];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x14];Related*related;char unknown140[0x18];Device*device;char unknown15C[8];Service*service;};
struct Vec3{float x,y,z;};
struct State{char unknown00[0xD0];int mode;char unknownD4[0x138];Vec3 vector;char unknown218[0x10];int status;};

struct AllocName{char text[0x10];};
struct Strings{
 AllocName anonymous;char unknown10[0x58];char contextHack[0x10];char rtcMissing[0x28];char speechPath[0x14];char finished[0x48];char line404[0x20];char unknown11C[0x10];char header[0xC];
};

struct VORecord{int key,next,rtc,count,index;signed char first,second,letterbox;char unknown17;Vec3 start,end;float time,remaining;char*text;char sound[0xC];Word talker,listener;int talkerAnim,listenerAnim;};
typedef char CheckVORecord[sizeof(VORecord)==0x58?1:-1];
struct VoiceOverData{char unknown00[0x14];int count,capacity;VORecord*records;int selected,previous;char path[0x100];char language[0x20];char unknown148[4];float time;Handle target;signed char ended;
 VORecord*search(int key){for(int i=0;i<count;++i)if(records[i].key==key)return &records[i];return 0;}
 VORecord*find(int key){if(key>-1)return search(key);return 0;}
};

extern "C"{
 extern Context lbl_801E9D24;
 extern const Strings lbl_8029EFC0;
 extern const float lbl_803790A8;
 extern const char lbl_803790BC[2],lbl_803790C0[5];
 extern int lbl_803777AC,lbl_803777CC,lbl_803777B0;
 extern Vec3 game_vec3_zero;
 void fn_801FA014(void*,const char*,...);
 void fn_801F86C8(Manager*,const void*,int);
 Word fn_801F7EB8(const Handle*);
 void fn_800B6C84(Service*,int,int);
 void fn_80206B44(Object*,int,int);
 int sprintf(char*,const char*,...);
 Word strlen(const char*);
 char*strcpy(char*,const char*);
 char*strcat(char*,const char*);
 void fn_800AD54C(VoiceOverData*);
 void fn_800AC2B4(VoiceOverData*,int);
 void fn_800A64E0(Object*,int);
 signed char fn_8007D604(Record_8007D604*,int);
 int fn_80092844(Object*);
 void fn_8007D6A0(Record_8007D604*,int);
 void fn_8002C130();
 void fn_80057100(SceneOwner*,int);
 State*fn_8007D074();
 void fn_8007705C(State*);
}

struct Handle_8002B67C:Handle_801F7F10{Handle_8002B67C(const Handle&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002B67C(){}};
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(){word=0;}~Handle_80020B90(){}};

inline Object*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
/* The owned RTC-manager handle is resolved twice in a row; reading the
 * handle tag into a local before indexing the entry (and comparing it in an
 * Entry helper) gives the CSE'd tag/entry pair the original r4/r5 colouring. */
inline Object*resolve(const Handle_801F7F10&h){int tag=h.bits.tag;return lbl_801E9D24.manager->entries[h.bits.index].get(tag);}
inline Object*optional(const Handle&h){return fn_801F7EB8(&h)?resolve(h):0;}

extern "C" void fn_800ACB3C(VoiceOverData*self,float dt){
 const Strings*const strings=&lbl_8029EFC0;
 VORecord*record=self->find(self->selected);
 signed char textDone=0,soundDone=0;
 if(!record)return;
 if(record->letterbox||record->rtc>=0){
  if(lbl_801E9D24.service->get(0)!=lbl_803777AC){fn_800B6C84(lbl_801E9D24.service,0,lbl_803777AC);fn_801FA014(lbl_801E9D24.logger,strings->contextHack);}
 }
 self->time-=dt;
 if(record->count>0&&record->index>=0){
  record->remaining-=dt;
  if(record->remaining<=lbl_803790A8){
   record->remaining=record->time;
   record->index++;
   record->first=1;
   if(record->index>=record->count){record->index=-1;textDone=1;record->first=0;}
  }
 }else textDone=1;
 if(record->second&&record->rtc>=0){
  record->second=0;
  Handle_8002B67C owner(*lbl_801E9D24.related->handle);
  int rtc=record->rtc;
  if(rtc<=resolve(owner)->rtcCount){
   fn_80206B44(resolve(owner),rtc-1,0);
   self->ended=0;self->previous=rtc-1;
   resolve(resolve(resolve(*resolve(*lbl_801E9D24.related->handle)->rtcOwner)->getHandle(0))->handle20)->stop(-1);
  }else{char text[0x48];sprintf(text,strings->rtcMissing,rtc);}
 }
 if(record->first){
  record->first=0;
  if(record->index>=0&&strlen(record->sound)){
   strcpy(self->path,strings->speechPath);strcat(self->path,self->language);strcat(self->path,lbl_803790BC);strcat(self->path,record->sound);strcat(self->path,lbl_803790C0);
   lbl_801E9D24.device->play(self->path,0,Handle_80020B90(),Handle_80020B90());
  }
 }
 if(strlen(self->path)){if(!lbl_801E9D24.device->isPlaying(self->path))soundDone=1;}else soundDone=1;
 if(textDone&&soundDone){
  fn_801FA014(lbl_801E9D24.logger,strings->finished,textDone,soundDone);
  if(self->ended){fn_800AD54C(self);self->selected=-1;if(record->next>-1)fn_800AC2B4(self,record->next);}
  else if(record->next>-1){fn_801FA014(lbl_801E9D24.logger,strings->line404);fn_800AD54C(self);fn_800AC2B4(self,record->next);}
  if(self->selected==-1){self->previous=-1;if(record->letterbox)fn_800A64E0(resolve(lbl_801E9D24.scene->owner->handle),0);
   if(lbl_801E9D24.service->get(0)!=lbl_803777CC){fn_800B6C84(lbl_801E9D24.service,0,lbl_803777B0);Object*actor=optional(resolve(*resolve(*lbl_801E9D24.related->handle)->related)->handle70);if(!fn_8007D604(&actor->record,0x28)&&!fn_8007D604(&actor->record,0x29)&&!fn_8007D604(&actor->record,0x2F)&&!fn_8007D604(&actor->record,5)){State*state=fn_8007D074();if(state->mode!=1&&state->mode!=2){if(record->key<0x238C){int key=fn_80092844(actor);fn_8007D6A0(&actor->record,key);};resolve(resolve(actor->getHandle(0))->handle20)->destroy(-1);}}}
   fn_8002C130();fn_80057100(lbl_801E9D24.scene->owner,-1);if(fn_8007D074()->status!=1){State*state=fn_8007D074();if(state->mode==4){fn_8007705C(state);state->vector=game_vec3_zero;}}
  }
 }
}
