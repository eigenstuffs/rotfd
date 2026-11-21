#include "Game/callback_cycle_internal.h"
extern "C" {
extern char lbl_8028F698[];
void *fn_8028FAF4(void*,void*,u32,u32);
void *fn_8028FF24(void*,u32);
void fn_8028FD50(void*,void*,u32);
}
inline void *operator new(u32,void *p){return p;}
struct UpdateKey {
 int key;signed char state;char unknown5[3];
 UpdateKey(int value,signed char mode):key(value),state(mode){}
};
struct UpdateArray {
 int length,capacity;UpdateKey *data;
 inline void grow() {
  int size=capacity+3;
  if(size) {
   if(data)data=(UpdateKey*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(UpdateKey),size*sizeof(UpdateKey));
   else data=(UpdateKey*)fn_8028FF24(lbl_8028F698,size*sizeof(UpdateKey));
  } else if(data) {fn_8028FD50(lbl_8028F698,data,capacity*sizeof(UpdateKey));data=0;}
  capacity+=3;
 }
 inline UpdateKey *append() {
  if(length+1>capacity)grow();
  return data+length++;
 }
};
struct UpdateNode {char unknown0[0x10];UpdateArray keys;};
inline void update(UpdateNode *self,int key,signed char state) {
 for(int i=0;i<self->keys.length;++i) {
  if(key==self->keys.data[i].key) {/* Byte view of the verified state field at offset four. */
   ((signed char*)self->keys.data)[i*sizeof(UpdateKey)+4]=state;return;}
 }
 new(self->keys.append())UpdateKey(key,state);
}
extern "C" void fn_8025F3C8(UpdateNode *self,int key) {update(self,key,0);}
extern "C" void fn_8025F4F4(UpdateNode *self,int key) {update(self,key,1);}
