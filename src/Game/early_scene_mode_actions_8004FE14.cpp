typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Target;
struct Entry{Target*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Child{char unknown00[0x178];int first178,second17C;};
struct SceneOwner{char unknown00[0xEC];Child*childEC;};
struct Scene{char unknown00[0x15058];SceneOwner*first;void*second;};
struct UI;
extern "C"struct Context{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x3C];UI*ui;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);signed char fn_8025E9FC(void*,int);extern int lbl_8037767C,lbl_803777B8;int fn_80030E9C(Target*,int,int);void fn_80031654(Target*,int,int);void fn_80056434(SceneOwner*,int);void fn_800E88EC(void*);}
struct InitZero_FE14:Handle_801F7F10{InitZero_FE14(){word=0;}~InitZero_FE14(){}};
struct Handle_80020834:InitZero_FE14{Handle_80020834(){word=0;}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8003E120:Handle_80020834{Handle_8003E120(const Handle_8003E120&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8003E120(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C"{Handle_8003E120 fn_800BCF58(Scene*,const Handle_801F7F10&);void fn_800B6F70(UI*,int,int,const Handle_80020478&);}
inline Target*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct Owner{char unknown00[4];Handle_801F7F10 self;char unknown08[0x58];Handle_801F7F10 target;int selection;};
extern "C"void fn_8004FE14(Owner*self){
 if(fn_8025E9FC(self,0x8A))lbl_8037767C=self->selection;
 else if(fn_8025E9FC(self,0x8B))lbl_8037767C=0;
 else if(fn_8025E9FC(self,0x5C)){
  Handle_8003E120 target=fn_800BCF58(lbl_801E9D24.scene,self->target);
  switch(lbl_8037767C){
   case 1:
    fn_80030E9C(resolve(target),0,0);
    Child*child=lbl_801E9D24.scene->first->childEC;int second=child->second17C;int first=child->first178;fn_80031654(resolve(target),second,first);
    fn_80056434(lbl_801E9D24.scene->first,1);
    const Handle_801F7F10&source=self->self;fn_800B6F70(lbl_801E9D24.ui,lbl_803777B8,0,Handle_80020478(source));
    lbl_8037767C=0;break;
   case 2:fn_800E88EC(lbl_801E9D24.scene->second);fn_80030E9C(resolve(target),0,1);break;
   case 3:fn_80030E9C(resolve(target),0,2);break;
   case 4:fn_80030E9C(resolve(target),0,3);break;
  }
 }
}
