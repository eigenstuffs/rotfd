/* Actor action selection; see docs/notes/game-actor-action-flag-selection.md. */
typedef unsigned long Word;
typedef unsigned long long Flags;
extern "C" void fn_801F7CB4(void*,const void*);
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();Handle_801F7F10(const Handle_801F7F10&h){fn_801F7CB4(this,&h);}~Handle_801F7F10();};
struct Node{char unknown00[4];Handle_801F7F10 self4;char unknown08[0x30];Flags flags38;char unknown40[0x30];unsigned char value70;char unknown71[0x15];unsigned short value86;char unknown88[2];unsigned short value8A;char unknown8C[0x94];Word flags120;signed char hasFlags(Flags mask)const{signed char enabled=0;if(flags38&mask)enabled=1;return enabled;}};
struct Actor{char unknown00[0x28];Handle_801F7F10 target28;float value2C;char unknown30[0x54];int remaining84;};
struct ActionRecord{int next;Word word04,word08;unsigned char byte0C,byte0D;Word word10,word14,word18,word1C,word20;Node*object24;Word word28;Node*target2C;};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{int count,capacity;Entry*entries;};
struct Scene{char unknown00[0x60];Handle_801F7F10 resource60;};
struct World{char unknown00[0x15058];Scene*scene;};
extern "C"struct Context{char unknown00[0x118];Manager*manager;char unknown11C[8];World*world;}lbl_801E9D24;
struct Component{char unknown00[0x30];};struct Self{char unknown00[0x24];Handle_801F7F10 actor24;char unknown28[0x2F0];Component component318;Handle_801F7F10 event348;};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
extern "C"{signed char fn_8007D604(Component*,int);void fn_8007D6A0(Component*,int);signed char fn_8025E9FC(Actor*,int);void fn_80286058(Actor*,int);ActionRecord*fn_8025E50C(Actor*);const ActionRecord*fn_8025E4E0(Actor*,int);void fn_801F7914(Handle_801F7F10*,const Handle_801F7F10&);void fn_800596F4(Scene*,const int*,short*,short*);void fn_80056434(Scene*,int);Word fn_801F948C(void*,const char*);extern const char lbl_8029DC6C[];extern const float lbl_80378C20;void fn_802073E8(void*,int,Node*,float);}
struct Name{Word value;Name(const char*text){value=fn_801F948C(this,text);}Name(const Name&n){value=n.value;}};
inline Name makeName(const char*t){Name name(t);return name;}
extern "C"void fn_800A6234(Node*,signed char,const Name&);
inline Word resolveWord(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?(Word)m->entries[index].object:0;}
extern "C"void fn_80092E70(Self*self){
 Actor*actor=(Actor*)resolve(self->actor24);
 if(fn_8007D604(&self->component318,0x15)||fn_8007D604(&self->component318,0x2F)||fn_8007D604(&self->component318,0x36))return;
 short selected=0;
 if(fn_8025E9FC(actor,0x87))fn_80286058(actor,0x87);
 else if(fn_8025E9FC(actor,0x86)){
  signed char found=0;ActionRecord*record=fn_8025E50C(actor);
  for(;;){if(record->object24->flags120&0x2000000){fn_801F7914(&actor->target28,Handle_801F7F10(record->target2C->self4));found=1;break;}
   if(!record->next)break;*record=*fn_8025E4E0(actor,record->next);
  }
  if(!found)return;
 }else if(fn_8025E9FC(actor,0xC1)){
  int value=(int)actor->value2C;short unused;fn_800596F4(lbl_801E9D24.world->scene,&value,&unused,&selected);
 }else return;
 Node*target=resolve(actor->target28);
 if(target->hasFlags(0x2000000ULL)||(target->flags38&0x400000000000ULL))return;
 if((target->flags38&0x200000000000ULL))selected=target->value8A;
 else if((target->flags38&0x20000000ULL))selected=target->value86;
 else if((target->flags38&0x40000000ULL))selected=target->value70;
 actor->remaining84-=selected;fn_80056434(lbl_801E9D24.world->scene,actor->remaining84);
 Node*resource=resolve(lbl_801E9D24.world->scene->resource60);fn_800A6234(resource,0,makeName(lbl_8029DC6C));
 if(actor->remaining84<=0)fn_8007D6A0(&self->component318,0x2F);else{fn_8007D6A0(&self->component318,0x15);fn_8007D6A0(&self->component318,0x36);}
 if((target->flags38&0x10000000ULL))fn_802073E8(resolve(self->actor24),0xAB,target,lbl_80378C20);
 fn_802073E8(actor,0x65,(Node*)resolveWord(self->event348),lbl_80378C20);
}
