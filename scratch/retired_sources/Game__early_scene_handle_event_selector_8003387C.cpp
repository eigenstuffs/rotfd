/* Scene callback dispatch and handle-specific selection transitions. */
typedef unsigned long Word;
struct MemberPointer { Word a,b,c; };
struct Callback { char unknown00[0x28]; unsigned short flags; short index; };
struct Handle { union {Word value;struct{signed int tag:8,index:24;}bits;}; };
struct Node { char unknown00[0x64]; Word transition; Word unknown68; Handle current,alternate,group,subgroup,target,subobject,other,state,previous,mode; };
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; signed char getTag()const{return tag;} };
struct Manager { int count,capacity; Entry* entries; };
struct Scene { char unknown00[0x15058]; Node* owner; };
extern "C" struct Context { char unknown00[0x118]; Manager* manager; char unknown11C[8]; Scene* scene; }lbl_801E9D24;
inline Node*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline bool equal(const Handle&left,const Handle&right){Node*first=resolve(left);return first==resolve(right);}
extern "C" {
extern const struct SelectorPool {char unknown00[0x218];MemberPointer entries[5];}lbl_802B1918;
extern Word lbl_8037808C,lbl_80378090;extern int lbl_80378094;extern signed char lbl_80377788;
extern const char lbl_8029A354[];
void fn_8025EF34(Node*,MemberPointer,int);void fn_8025EEB4(Node*,MemberPointer);void fn_8025EB70(Node*,MemberPointer);Callback*fn_8025F074(Node*,MemberPointer);
void fn_8025F4F4(Callback*,int,const char*);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,Word);void fn_8025F620(Callback*,Word);signed char fn_8025E9FC(Node*,int);
void fn_80057294(Node*);void fn_80059340(Node*,int);void fn_80031328(Node*);void fn_80030A08(Node*,const Handle*,Word);
}
extern "C" MemberPointer lbl_802B1B30[5]={{0,0x84,8},{0,0x84,8},{0,0x84,8},{0,0x84,8},{0,0x84,8}};
extern "C" int fn_8003387C(Node*self,int event,Callback*callback){
 const SelectorPool*members=&lbl_802B1918;int result=1;
 switch(event){
 case 0:fn_8025EF34(self,members->entries[0],-1);return 1;
 case 1:fn_8025EEB4(self,members->entries[1]);return 1;
 case 2:fn_8025EB70(self,members->entries[2]);return 1;
 case 3:if(callback)return(signed char)((callback->flags>>2)&1);callback=fn_8025F074(self,members->entries[3]);if(callback)return(signed char)((callback->flags>>2)&1);return 0;
 case 4:if(callback)return(signed char)(callback->flags&1);callback=fn_8025F074(self,members->entries[4]);if(callback)return(signed char)(callback->flags&1);return 0;
 case 5:return 1;
 case 6:if(callback)return callback->index;return -9999;
 }
 lbl_8037808C=0;lbl_80378090=0;lbl_80378094=-1;
 if(event==8||event==7)fn_8025F4F4(callback,13,lbl_8029A354);
 if(event==11&&callback->index==-1)return 1;
 fn_8025F658(callback,lbl_80378090);
 int action;if(event>=14)action=event+callback->index*2;else action=event;
 switch(action){
 case 7:fn_8025F694(callback,lbl_8037808C);
 case 8:break;
 case 14:result=fn_8025E9FC(self,0x5D);break;
 case 15:
  if(!lbl_80377788)fn_80057294(lbl_801E9D24.scene->owner);
  if(equal(self->current,self->target)){if(!lbl_80377788)fn_80031328(self);}
  else if(equal(self->previous,self->target))fn_80031328(self);
  else if(equal(self->state,self->target))fn_80031328(self);
  else if(equal(self->mode,self->target))fn_80031328(self);
  else if(equal(self->alternate,self->target))fn_80030A08(self,&self->current,self->transition);
  else if(equal(self->group,self->target))fn_80030A08(self,&self->current,self->transition);
  else if(equal(self->subgroup,self->target))fn_80030A08(self,&self->group,self->transition);
  else if(equal(self->other,self->target))fn_80030A08(self,&self->group,self->transition);
  else if(equal(self->subobject,self->target))fn_80030A08(self,&self->group,self->transition);
  if(!lbl_80377788)fn_80059340(lbl_801E9D24.scene->owner,0x28);
  break;
 default:result=2;break;
 }
 fn_8025F620(callback,lbl_80378090);return result;
}
