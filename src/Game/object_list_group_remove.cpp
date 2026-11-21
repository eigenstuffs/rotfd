#include "Game/object_list_pool_internal.h"
extern "C" int fn_80285ED8(ObjectListGroup*self,int key,void*object){
 ObjectListNode*node;ObjectListNode*previous;int changed;previous=0;changed=0;node=self->firstHead;
 while(node){
  if(key==node->key){
   if(object&&object!=fn_801F7EB8(&node->handle)){previous=node;node=node->next;continue;}
   changed=1;if(previous)previous->next=node->next;else self->firstHead=node->next;
   if(!node->next)self->firstTail=previous;
   fn_80285CDC(objectListPool(),node);
   if(!previous)node=self->firstHead;else node=previous->next;
  }else{previous=node;node=node->next;}
 }
 previous=self->secondHead;node=0;
 while(previous){
  if(key==previous->key){
   if(object&&object!=fn_801F7EB8(&previous->handle)){node=previous;previous=previous->next;continue;}
   changed=1;if(node)node->next=previous->next;else self->secondHead=previous->next;
   if(!previous->next)self->secondTail=node;
   fn_80285CDC(objectListPool(),previous);
   if(!node)previous=self->secondHead;else previous=node->next;
  }else{node=previous;previous=previous->next;}
 }
 return changed;
}
extern "C" int fn_80286058(ObjectListGroup*self,int key){
 ObjectListNode*node;ObjectListNode*previous=0;node=self->firstHead;
 while(node){if(key==node->key){if(previous)previous->next=node->next;else self->firstHead=node->next;if(!node->next)self->firstTail=previous;fn_80285CDC(objectListPool(),node);return 1;}previous=node;node=node->next;}
 ObjectListNode*second=self->secondHead;ObjectListNode*secondPrevious=0;
 while(second){if(key==second->key){if(secondPrevious)secondPrevious->next=second->next;else self->secondHead=second->next;if(!second->next)self->secondTail=secondPrevious;fn_80285CDC(objectListPool(),second);return 1;}secondPrevious=second;second=second->next;}
 return 0;
}
