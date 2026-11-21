/* Owner handle selection update; linker discards the weak inline handle destructor copy. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed long tag:8,index:24;}bits;};Handle_801F7F10();Handle_801F7F10(int){bits.index=0;bits.tag=0;}~Handle_801F7F10();};
struct NodePrefix{char unknown00[8];};
struct Node:NodePrefix{virtual void s08();virtual void s0C();virtual void s10();virtual void s14();virtual void s18();virtual void s1C();virtual void s20();virtual void s24();virtual void s28();virtual void s2C();virtual void s30();virtual void s34();virtual void s38();virtual void s3C();virtual void s40();virtual void select(int);virtual void activate();char unknown0C[0x46-0xC];unsigned short count;};
struct ActorIndex{int value;ActorIndex(int v):value(v){}operator const int&()const{return value;}};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};struct Manager{int count,capacity;EntryArray entries;};
struct SceneOwner{char unknown00[0xF0];int keyF0;};
struct Scene{char unknown00[0x15058];SceneOwner*owner;};
struct UI{char unknown00[0x1C];int*modes;const int&modeRef(int i)const{return modes[i];}};
extern "C" struct Context{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x164-0x128];UI*ui;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);Word fn_801F7EB8(const Handle_801F7F10*);}
struct Handle_80020478:Handle_801F7F10{Handle_80020478(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Owner{Word unknown00;Handle_801F7F10 self;char unknown08[0x64-0x8];int selected,mode;char unknown6C[4];Handle_801F7F10 h70;char unknown74[8];Handle_801F7F10 h7C;};
extern "C"{extern int lbl_803777B8;extern Word lbl_803777BC,lbl_803777B0;void fn_800B6C84(UI*,int,Word);void fn_800B6DA8(UI*,Word,int,const Handle_80020478&);void fn_800B6F70(UI*,Word,int,const Handle_80020478&);void fn_800B3C68(Node*,int);signed char fn_8021CDAC(Node*,int);}
inline Node*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;const ActorIndex index(h.bits.index);const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
inline void showFirst(Owner*self){const Handle_801F7F10&source=self->self;fn_800B6DA8(lbl_801E9D24.ui,lbl_803777BC,0,Handle_80020478(source));}
inline void showSecond(Owner*self){const Handle_801F7F10&source=self->self;fn_800B6F70(lbl_801E9D24.ui,lbl_803777BC,0,Handle_80020478(source));}
extern "C" void fn_80030A08(Owner*self,const Handle_801F7F10&h,int selected){
 if(resolve(h)==resolve(self->h7C))return;
 if(resolve(Handle_801F7F10(0))==resolve(self->h7C)){
  self->selected=selected;
  if(lbl_803777B8==lbl_801E9D24.ui->modeRef(0))self->mode=lbl_803777B8;
  fn_800B6C84(lbl_801E9D24.ui,0,lbl_803777BC);
  showFirst(self);
  if(fn_801F7EB8(&self->h70)){SceneOwner*owner=lbl_801E9D24.scene->owner;fn_800B3C68(resolve(self->h70),owner->keyF0);}
 }else resolve(self->h7C)->activate();
 fn_801F86C8(lbl_801E9D24.manager,&self->h7C,-1);self->h7C.word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);
 if(resolve(Handle_801F7F10(0))==resolve(self->h7C)){
  fn_800B6C84(lbl_801E9D24.ui,0,lbl_803777B0);
  showSecond(self);
  self->selected=-1;
  return;
 }
 for(int i=0;i<resolve(self->h7C)->count;i++)if(fn_8021CDAC(resolve(self->h7C),i))break;
 resolve(self->h7C)->select(6);
}
