// Private layout views for menu-player binding; offsets and C identities are verified.
// Only fn_80200EEC is retained. Generated inline backup destructors are uncredited.
typedef unsigned long MenuPlayerWord;
struct Handle_801F7F10{union{MenuPlayerWord word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct MenuPlayerNode;struct MenuPlayerEntry{MenuPlayerNode*object;MenuPlayerWord unknown04[2];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct MenuPlayerManager{MenuPlayerWord unknown00[2];MenuPlayerEntry*entries;};
extern "C"struct MenuPlayerGlobal{char unknown00[0x118];MenuPlayerManager*manager;char unknown11C[8];void*engine;char unknown128[0x24];void*factory;}lbl_801E9D24;
extern "C"{void fn_801F86C8(MenuPlayerManager*,const Handle_801F7F10*,int);MenuPlayerWord fn_801F7EB8(const Handle_801F7F10*);MenuPlayerWord fn_801F948C(void*,const char*);}
struct MenuPlayerZero0:Handle_801F7F10{MenuPlayerZero0(){}MenuPlayerZero0(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct MenuPlayerFirstZero:Handle_801F7F10{MenuPlayerFirstZero(){word=0;}};struct MenuPlayerZero1:MenuPlayerFirstZero{MenuPlayerZero1(){}MenuPlayerZero1(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}MenuPlayerZero1(const MenuPlayerZero1&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
template<int N>struct MenuPlayerZero:MenuPlayerZero<N-1>{MenuPlayerZero(){this->word=0;}};
template<>struct MenuPlayerZero<1>:Handle_801F7F10{MenuPlayerZero(){word=0;}};
struct MenuPlayerPlayerHandle:MenuPlayerZero<6>{MenuPlayerPlayerHandle(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}MenuPlayerPlayerHandle(const MenuPlayerPlayerHandle&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}MenuPlayerPlayerHandle&operator=(const MenuPlayerPlayerHandle&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}};
struct MenuPlayerSetupHandle:MenuPlayerZero<4>{MenuPlayerSetupHandle(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct MenuPlayerDefaultHandle:MenuPlayerZero<2>{};
struct MenuPlayerKey{MenuPlayerWord word;MenuPlayerKey(const char*s){word=fn_801F948C(this,s);}};
struct MenuPlayerNodePrefix{MenuPlayerWord unknown00[2];};
struct MenuPlayerNode:MenuPlayerNodePrefix{
 virtual void slot008();
 virtual void slot00C();
 virtual void slot010();
 virtual void slot014();
 virtual void slot018();
 virtual void slot01C();
 virtual void slot020();
 virtual void slot024();
 virtual void slot028();
 virtual void slot02C();
 virtual void slot030();
 virtual void slot034();
 virtual void slot038();
 virtual void setOwner(const Handle_801F7F10&);
 virtual void setContext(const Handle_801F7F10&);
 virtual void slot044();
 virtual void slot048();
 virtual void slot04C();
 virtual void slot050();
 virtual void slot054();
 virtual void slot058();
 virtual void slot05C();
 virtual void slot060();
 virtual void slot064();
 virtual void slot068();
 virtual void slot06C();
 virtual void slot070();
 virtual void slot074();
 virtual void slot078();
 virtual void slot07C();
 virtual void slot080();
 virtual void setPlayer(const Handle_801F7F10&);
 virtual void slot088();
 virtual void slot08C();
 virtual void slot090();
 virtual void setIndex(int);
 virtual void setMode(int);
 virtual void slot09C();
 virtual void slot0A0();
 virtual void enableIndex(int);
 virtual void slot0A8();
 virtual void slot0AC();
 virtual void slot0B0();
 virtual void slot0B4();
 virtual void slot0B8();
 virtual void slot0BC();
 virtual void slot0C0();
 virtual void slot0C4();
 virtual void slot0C8();
 virtual void slot0CC();
 virtual void slot0D0();
 virtual void slot0D4();
 virtual void slot0D8();
 virtual void slot0DC();
 virtual void slot0E0();
 virtual void slot0E4();
 virtual void slot0E8();
 virtual void slot0EC();
 virtual void slot0F0();
 virtual void slot0F4();
 virtual void slot0F8();
 virtual void slot0FC();
 virtual void slot100();
 virtual void slot104();
 virtual void slot108();
 virtual void slot10C();
 virtual void slot110();
 virtual void slot114();
 virtual void slot118();
 virtual void slot11C();
 virtual void slot120();
 virtual void slot124();
 virtual void slot128();
 virtual void slot12C();
 virtual void slot130();
 virtual void slot134();
 virtual void slot138();
 virtual void slot13C();
 virtual void slot140();
 virtual void setSlot(const Handle_801F7F10*);
 char unknown0C[0x10];Handle_801F7F10 context1C;char unknown20[0x10];Handle_801F7F10 parent30;char unknown34[0x30];char position64[12];Handle_801F7F10 handle70;
};
struct MenuPlayerOwner{MenuPlayerWord unknown00;Handle_801F7F10 context04;MenuPlayerWord unknown08;Handle_801F7F10 owner0C;char unknown10[0x88];Handle_801F7F10*slots98;char unknown9C[8];Handle_801F7F10*actorsA4;char unknownA8[8];Handle_801F7F10*playersB0;};
extern "C"{MenuPlayerZero0 fn_80263308(void*,const MenuPlayerKey&);void fn_8023E994(MenuPlayerNode*,MenuPlayerDefaultHandle&,int);void fn_802072D4(MenuPlayerNode*,const MenuPlayerKey&,int);void fn_802408BC(MenuPlayerNode*,MenuPlayerZero1,int);void fn_80269FE0(MenuPlayerNode*);void fn_8023DE28(MenuPlayerNode*);MenuPlayerZero0 fn_80260868(void*,const MenuPlayerKey&,int);MenuPlayerZero0 fn_80260BA4(void*,const char*);void fn_802002A4(MenuPlayerOwner*,int,const void*,const MenuPlayerSetupHandle&);void fn_8025BF0C(MenuPlayerNode*,const Handle_801F7F10*);int sprintf(char*,const char*,...);extern const char lbl_802AD8F8[],lbl_802AD904[];}
inline MenuPlayerNode*resolve(const Handle_801F7F10&h){int i=h.bits.index;MenuPlayerManager*m=lbl_801E9D24.manager;int tag=m->entries[i].getTag();if(tag==h.bits.tag)return m->entries[i].object;return 0;}
inline void assign(Handle_801F7F10&target,const Handle_801F7F10&source){fn_801F86C8(lbl_801E9D24.manager,&target,-1);target.word=source.word;fn_801F86C8(lbl_801E9D24.manager,&source,1);}
inline void configurePlayer(MenuPlayerNode*node,MenuPlayerOwner*self,int number,const Handle_801F7F10&selected){node->setOwner(selected);const Handle_801F7F10&originalSetup=node->handle70;fn_802002A4(self,number-1,node->position64,MenuPlayerSetupHandle(originalSetup));}
extern "C"int fn_80200EEC(MenuPlayerOwner*self,int number,const MenuPlayerKey&name,int mode){
 if(fn_801F7EB8(self->actorsA4+(number-1)))return 0;
 MenuPlayerZero1 resource(fn_80263308(lbl_801E9D24.factory,name));if(!fn_801F7EB8(&resource))return 0;
 MenuPlayerDefaultHandle selected;fn_8023E994(resolve(resource),selected,0);
 MenuPlayerZero1 context(resolve(selected)->context1C);
 char label[128];sprintf(label,lbl_802AD8F8,number);
 MenuPlayerNode*named=resolve(selected);fn_802072D4(named,MenuPlayerKey(label),0);
 fn_802408BC(resolve(resolve(self->owner0C)->parent30),MenuPlayerZero1(selected),0);
 fn_80269FE0(resolve(self->owner0C));fn_8023DE28(resolve(resolve(self->owner0C)->parent30));
 MenuPlayerPlayerHandle player((MenuPlayerPlayerHandle(fn_80260868(lbl_801E9D24.engine,name,0))));
 const Handle_801F7F10&originalContext=self->context04;MenuPlayerZero0 owner(originalContext);
 if(fn_801F7EB8(&player)){
  resolve(player)->setOwner(selected);resolve(player)->setIndex(number-1);resolve(player)->setMode(mode-1);resolve(player)->enableIndex(number-1);resolve(player)->setContext(owner);
 }else{
  player=MenuPlayerPlayerHandle(fn_80260BA4(lbl_801E9D24.engine,lbl_802AD904));
  configurePlayer(resolve(player),self,number,selected);
 }
 assign(self->playersB0[number-1],player);
 resolve(self->actorsA4[number-1])->setPlayer(selected);
 resolve(self->actorsA4[number-1])->setSlot(self->slots98+(number-1));
 fn_8025BF0C(resolve(self->slots98[number-1]),self->actorsA4+(number-1));
 return 1;
}
