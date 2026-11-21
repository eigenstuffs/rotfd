/* Message 0xA9 name command: format the scene actor name with the packed tag and number, store it and play it through the service. */
typedef unsigned long Word;
struct Handle_801F7F10{Word word;Handle_801F7F10();~Handle_801F7F10();};
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct NameZero_CF30:Handle_801F7F10{NameZero_CF30(){word=0;}};
struct Handle_80020B90:NameZero_CF30{Handle_80020B90(){word=0;}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ServicePrefix{char unknown00[0x7C];};
struct Service:ServicePrefix{
 virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void play(const char*,int,const Handle_80020B90&,const Handle_80020B90&);
};
struct ActorHandle{signed int tag:8,index:24;};
struct Actor{char unknown00[0x68];ActorHandle handle;};
struct Named{char unknown00[0x128];char name[1];};
struct Entry{Named*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];};
struct Manager{char unknown00[8];Entry*entries;};
struct Scene{char unknown00[0x15058];Actor*current15058;};
struct Globals{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene124;char unknown128[0x158-0x128];Service*service158;};
extern "C"{extern Globals lbl_801E9D24;extern char lbl_8029A700[17];extern char lbl_803784C4[5],lbl_803784CC[2],lbl_803784D0[5];extern const float lbl_803784C0;
char*strcpy(char*,const char*);char*strcat(char*,const char*);int sprintf(char*,const char*,...);void fn_802073E8(void*,int,void*,float);}
inline Named*resolve(const ActorHandle&h){Entry*e=&lbl_801E9D24.manager->entries[h.index];return e->tag==h.tag?e->object:0;}
struct Message{int type;Word value;};
struct Owner{char unknown00[0x70];char text[1];};
extern "C" void fn_8003CF30(Owner*self,Message*msg,signed char skip){
 if(msg->type==0xA9&&!skip){
  char buffer[256];char number[8];char tag[3];
  strcpy(buffer,lbl_8029A700);
  Word v=msg->value;int hi=(int)v>>16;
  tag[2]=0;tag[0]=(hi>>8)&0xFF;tag[1]=hi;
  sprintf(number,lbl_803784C4,v&0xFFFF);
  strcat(buffer,resolve(lbl_801E9D24.scene124->current15058->handle)->name);
  strcat(buffer,lbl_803784CC);strcat(buffer,tag);strcat(buffer,number);strcat(buffer,lbl_803784D0);
  strcpy(self->text,buffer);
  {Handle_80020B90 first,second;lbl_801E9D24.service158->play(buffer,0,first,second);}
 }
 fn_802073E8(self,msg->type,self,lbl_803784C0);
}
