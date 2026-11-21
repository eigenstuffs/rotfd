typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node{char unknown00[0x70];Handle_801F7F10 controlled;char unknown74[0x3C];Handle_801F7F10*related;char unknownB4[0x264];char properties[1];};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{int count,capacity;Entry*entries;};
struct Mode{char unknown00[0x100];int state;};struct Message{char unknown00[0x620];Word key;};struct Scene{char unknown00[0x15058];Mode*first;char unknown1505C[4];Message*message;};
struct UI;struct Resource{char unknown00[0x1C];Handle_801F7F10*selected;};
extern "C"struct Context{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x14];Resource*resource;char unknown140[0x24];UI*ui;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);Word fn_801F7EB8(const Handle_801F7F10*);signed char fn_8025E9FC(void*,int);void fn_80286058(void*,int);void fn_80046D60(void*,int);extern Word lbl_803777C4,lbl_803777CC;void fn_800B6C84(UI*,int,Word);void fn_800C2700(Message*);void fn_8007D6A0(void*,int);}
struct Handle_80020478:Handle_801F7F10{Handle_80020478(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C"{void fn_800B6F70(UI*,Word,int,const Handle_80020478&);void fn_800B6DA8(UI*,Word,int,const Handle_80020478&);}
struct Name{Word word;Name(const char*);Name(const Name&n){word=n.word;}};extern "C"{Word fn_801F948C(Name*,const char*);extern const char lbl_8029AB24[];void fn_800C3934(Message*,void*,Name,int,int,int,int);}inline Name::Name(const char*s){word=fn_801F948C(this,s);}
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct Owner{Word unknown00;Handle_801F7F10 self;};
extern "C"void fn_80047470(Owner*self){
 if(fn_8025E9FC(self,0xD2)){fn_80286058(self,0xD2);fn_80046D60(self,0);}
 else if(fn_8025E9FC(self,0xD3)){fn_80286058(self,0xD3);fn_80046D60(self,1);}
 else if(fn_8025E9FC(self,0xD4)){fn_80286058(self,0xD4);fn_80046D60(self,2);}
 else if(fn_8025E9FC(self,0xD5)){fn_80286058(self,0xD5);fn_80046D60(self,5);}
 else if(fn_8025E9FC(self,0xC4)){
  if(lbl_801E9D24.scene->first->state==3){
   const Handle_801F7F10&source=self->self;fn_800B6F70(lbl_801E9D24.ui,lbl_803777C4,0,Handle_80020478(source));
   fn_800B6C84(lbl_801E9D24.ui,0,lbl_801E9D24.scene->message->key);
   fn_800C2700(lbl_801E9D24.scene->message);
   const Handle_801F7F10&controlled=resolve(*resolve(*lbl_801E9D24.resource->selected)->related)->controlled;
   Node*node=fn_801F7EB8(&controlled)?resolve(controlled):0;
   fn_8007D6A0(node->properties,0);
  }else{
   const Handle_801F7F10&source=self->self;fn_800B6F70(lbl_801E9D24.ui,lbl_803777C4,0,Handle_80020478(source));
   const Handle_801F7F10&original=self->self;fn_800B6DA8(lbl_801E9D24.ui,lbl_803777CC,0,Handle_80020478(original));
   fn_800B6C84(lbl_801E9D24.ui,0,lbl_803777CC);
   Message*message=lbl_801E9D24.scene->message;fn_800C3934(message,self,Name(Name(lbl_8029AB24)),6,0,0,0);
  }
 }
}
