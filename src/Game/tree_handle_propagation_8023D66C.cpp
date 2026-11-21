#include "Game/tree_handle_propagation.h"

struct PropagateNode {char unknown00[0x10];Handle_801F7F10 child;int unknown14;Handle_801F7F10 next,selector;int unknown20;Handle_801F7F10 left,right;};
struct PropagateSelector {char unknown00[0x6C];unsigned short kind;char unknown6E[0x12];signed char flag80;char unknown81[0x27];signed char flagA8;};
struct PropagateEntry {PropagateNode*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;} PropagateNode* getObject()const{return object;}};
struct PropagateManager {char unknown00[8];PropagateEntry*entries;};
struct PropagateContext {char unknown00[0x118];PropagateManager*manager;};
extern "C" {extern PropagateContext lbl_801E9D24;void fn_801F86C8(PropagateManager*,const Handle_801F7F10*,short);}
struct PropagateZero:Handle_801F7F10 {PropagateZero(){value=0;}};
struct PropagateZero2:PropagateZero {PropagateZero2(){value=0;}};
struct PropagateCopy:PropagateZero2 {PropagateCopy(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
static inline void assign(Handle_801F7F10&to,const Handle_801F7F10&from){fn_801F86C8(lbl_801E9D24.manager,&to,-1);to.value=from.value;fn_801F86C8(lbl_801E9D24.manager,&from,1);}
static inline PropagateNode*resolve(const Handle_801F7F10&h){PropagateEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];return entry->tag==h.bits.tag?entry->object:0;}
struct HandleGeneration { signed char value; HandleGeneration(int v):value(v){} operator signed char()const{return value;} };
struct HandleIndex {int value;HandleIndex(int v):value(v){}operator const int&()const{return value;}};
static inline PropagateNode*resolveSelector(const Handle_801F7F10&h){
 PropagateManager* manager=lbl_801E9D24.manager;
 const HandleIndex index(h.bits.index);
 const HandleGeneration tag(h.bits.tag);
 return manager->entries[index].getTag()==tag?manager->entries[index].getObject():0;
}

#pragma dont_inline on
extern "C" void fn_8023D66C(void* object,const Handle_801F7F10&left,const Handle_801F7F10&right){
 PropagateNode* self=static_cast<PropagateNode*>(object);
 assign(self->left,left);assign(self->right,right);
 signed char propagate=1;
 PropagateNode*child=resolve(self->child);
 PropagateSelector*selector=(PropagateSelector*)resolveSelector(self->selector);
 if(selector){switch(selector->kind){
  case 12:if(selector->flagA8&&child){propagate=0;PropagateCopy temp(self->selector);fn_8023D66C(child,temp,self->right);}break;
  case 13:if(selector->flag80&&child){propagate=0;PropagateCopy temp(self->selector);fn_8023D66C(child,self->left,temp);}break;
 }}
 if(propagate&&child)fn_8023D66C(child,self->left,self->right);
 PropagateNode*next=resolve(self->next);
 if(next)fn_8023D66C(next,self->left,self->right);
}
#pragma dont_inline reset
