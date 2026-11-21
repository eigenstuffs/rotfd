#include "Game/callback_snapshot_internal.h"
extern "C" {
extern char lbl_8028F698[];
void fn_801EF610(void*,void*);
void fn_8028FD50(void*,void*,u32);
}
inline void *operator new(u32, void *p) {return p;}
struct ResetKey {
 int key;signed char state;char unknown5[3];
 ResetKey():key(-1),state(0) {}
 ~ResetKey() {}
};
struct ResetKeyArray {
 int length,capacity;ResetKey *data;
 inline void releaseStorage() {
  if(data) {fn_8028FD50(lbl_8028F698,data,capacity*sizeof(ResetKey));data=0;}
  capacity=0;
 }
 inline void clear() {
  if(length<0) {
   releaseStorage();
   for(int i=length;i<0;++i)new(data+i)ResetKey;
   length=0;
  } else if(length>0) {
   for(int i=length-1;i>=0;--i)data[i].~ResetKey();
   releaseStorage();
   length=0;
  }
 }
};
struct ResetNode {
 void *table;char unknown4[0xc];ResetKeyArray keys;ResetNode *next;
 void *bytes;int size;unsigned short flags,count;
};
inline void reset(ResetNode *self) {
 if(self->size)fn_801EF610(lbl_801EF5C8,self->bytes);
 self->bytes=0;self->size=0;
 self->flags&=0xfff8;self->count=0;self->next=0;
 self->keys.clear();
}

extern "C" void fn_8025F7FC(ResetNode *self) {reset(self);}
#include "Game/typed_cleanup_tables.h"
extern "C" ResetNode *fn_8025F92C(ResetNode *self) {
 self->table=&lbl_802ED0B0;
 self->keys.length=0;self->keys.capacity=0;self->keys.data=0;
 self->size=0;self->bytes=0;
 reset(self);
 return self;
}
