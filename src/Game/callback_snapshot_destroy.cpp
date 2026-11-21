#include "Game/callback_snapshot_internal.h"
#include "Game/typed_cleanup_tables.h"
extern "C" {
extern char lbl_8028F698[];
void fn_801EF610(void*,void*);
void fn_8028FD50(void*,void*,u32);
}
struct SnapshotKey {
 int key;u32 unknown;
 inline ~SnapshotKey() {}
};
struct SnapshotKeyArray {
 int length,capacity;SnapshotKey *data;
 inline ~SnapshotKeyArray() {
  if(data) {
   for(int i=0;i<length;++i)data[i].~SnapshotKey();
   if(data) {fn_8028FD50(lbl_8028F698,data,capacity*sizeof(SnapshotKey));data=0;}
   data=0;
  }
 }
};
struct SnapshotOwner {
 void *table;char unknown4[0xc];SnapshotKeyArray keys;u32 unknown1C;
 void *bytes;int size;
};
extern "C" SnapshotOwner *fn_8025F6F4(SnapshotOwner *self,int flag) {
 if(self) {
  self->table=&lbl_802ED0B0;
  if(self->size)fn_801EF610(lbl_801EF5C8,self->bytes);
  self->keys.~SnapshotKeyArray();
  if((short)flag>0)fn_801EF610(lbl_801EF5C8,self);
 }
 return self;
}
