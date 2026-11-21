/* Native scene-effect selection; see docs/notes/game-early-actor-scene-selection.md. */
#include "Game/early_actor_scene_selection_views.h"
extern "C" void fn_80089328(SelectionOwner*self){
 const char*strings=lbl_8029D680;
 self->first=0;self->second=0;
 SelectionMode*mode=lbl_801E9D24.scene->mode;
 if(self->actor->hasFlags(0x0400000000000000ULL)){
  self->first=resolveSelection(fn_80058778(mode,SelectionName(strings+0x70),0));
  self->second=resolveSelection(fn_80058778(mode,SelectionName(strings+0x84),0));
 }else if(self->actor->flags&0x2000000000000000ULL){
  self->first=resolveSelection(fn_80058778(mode,SelectionName(strings+0x94),0));
 }else if(self->actor->flags&0x4000000000000000ULL){
  self->first=resolveSelection(fn_80058778(mode,SelectionName(strings+0xA4),0));
 }else if(self->actor->flags&0x8000000000000000ULL){
  Handle_80020C04 owner(*lbl_801E9D24.node->handle);
  SelectionObject*object=resolveSelection(owner);
  Handle_80020B90 child(fn_8026A494(object,SelectionName(strings+0xB4)));
  if(fn_801F7EB8(&child))self->first=resolveSelectionSecond(resolveSelection(child)->related);
 }else if(mode->mode==3&&mode->submode==1){
  self->second=resolveSelection(fn_80058778(mode,SelectionName(strings+0xC4),0));
 }else{
  self->first=resolveSelection(fn_80058778(mode,SelectionName(strings+0xD4),0));
  self->second=resolveSelection(fn_80058778(mode,SelectionName(strings+0xEC),0));
  fn_80089B74(self);
 }
}
