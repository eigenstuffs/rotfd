#ifndef GAME_ENGINE_CALLBACK_MEMBER_ACTIVATION_H
#define GAME_ENGINE_CALLBACK_MEMBER_ACTIVATION_H
// Isolated layout views; repeated native status reads recover this volatile member.
typedef unsigned long u32;
struct CallbackCycle;
struct DispatchNode {
 u32 unknown0;
 int (CallbackCycle::*callback)(int, DispatchNode *);
 char unknown10[0xc];
 DispatchNode *next;
 char unknown20[8];
 volatile unsigned short flags;unsigned short count;
};
struct SelectedNode {u32 unknown;int key;SelectedNode *next;u32 unknownC;float time;};
struct CallbackCycle {
 char unknown0[0xc];signed char reset;char unknownD[3];DispatchNode *head;u32 unknown14;
 SelectedNode *active,*activeTail,*pending,*pendingTail;u32 handle;float time;int key;char unknown34[0xc];u32 state;
 inline DispatchNode *next();
};
extern "C" {extern DispatchNode *lbl_80378088;void fn_80286158(CallbackCycle*);void fn_8025F240(DispatchNode*,CallbackCycle*);void fn_801F7914(u32*,SelectedNode*);}

typedef int (CallbackCycle::*CycleCallback)(int, DispatchNode *);
inline DispatchNode *find(CallbackCycle *self, CycleCallback callback) {
 for (DispatchNode *node=self->head;node;node=node->next) {
  if(callback == node->callback) return node;
 }
 return 0;
}
extern "C" {
extern u32 lbl_80378090;
void fn_8025F620(DispatchNode*,u32);
void fn_8025F658(DispatchNode*,u32);
DispatchNode *fn_8028625C(CallbackCycle*);
signed char fn_8025F37C(DispatchNode*,int);
}
inline DispatchNode *getOrCreate(CallbackCycle*self,const CycleCallback &callback) {
 DispatchNode *found=find(self,callback);
 if(!found) {
  u32 previous;
  if(lbl_80378088) {previous=lbl_80378090;fn_8025F620(lbl_80378088,previous);}
  found=fn_8028625C(self);
  found->callback=callback;
  (self->*callback)(7,found);
  found->next=self->head;
  self->head=found;
  if(lbl_80378088) {lbl_80378090=previous;fn_8025F658(lbl_80378088,previous);}
 }
 return found;
}
inline void activate(CallbackCycle*self,DispatchNode*found,int key) {
 if(key==-1 || fn_8025F37C(found,key)) {
  if(!(found->flags&4)) {
   found->flags|=4;
   found->flags&=0xfffe;
   self->reset=1;
  }
 }
}
struct CallbackMethodLink {CycleCallback callback;CallbackMethodLink*next;};
struct CallbackSelector {int key;CallbackMethodLink*methods;int unknown08;CallbackSelector*next;};

extern "C" {
void fn_8025ED38(CallbackCycle*, int, CallbackSelector*);
void fn_8025EF34(CallbackCycle*, const CycleCallback&, int);
}

#endif
