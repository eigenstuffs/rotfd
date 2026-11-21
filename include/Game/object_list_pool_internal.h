#ifndef GAME_OBJECT_LIST_POOL_INTERNAL_H
#define GAME_OBJECT_LIST_POOL_INTERNAL_H
#include "objects_owner_internal.h"
extern "C" void* __dt__15Handle_801F7F10Fv(void*,short);
// Four-byte null handle storage with the native cleanup ABI.
struct ObjectListEmptyHandle {
 union {u32 value;struct {signed int generation:8;signed int index:24;} bits;};
 ObjectListEmptyHandle(){bits.index=0;bits.generation=0;}
 ~ObjectListEmptyHandle(){__dt__15Handle_801F7F10Fv(this,-1);}
};
struct ObjectListNode {Handle_801F7F10 handle;int key;ObjectListNode*next;float field0C,field10;};
struct ObjectListRecord {char unknown00[0x1C];ObjectListRecord*next;char unknown20[12];};
struct ObjectListPool {char unknown00[0x40];ObjectListNode*freeNodes;ObjectListNode nodes[2048];ObjectListRecord*freeRecords;ObjectListRecord records[1024];};
struct ObjectListGroup {char unknown00[0x10];ObjectListRecord*recordHead,*recordTail;ObjectListNode*firstHead,*firstTail,*secondHead,*secondTail;};
struct ObjectListGlobals {char unknown00[0x124];ObjectListPool*pool;};
extern "C" {

extern const float lbl_8037B890,lbl_8037B894;
void fn_8025F7FC(ObjectListRecord*);
void fn_801F7914(void*,const void*);

void fn_80285C74(ObjectListPool*,ObjectListRecord*);
ObjectListRecord*fn_80285CC0(ObjectListPool*);
void fn_80285CDC(ObjectListPool*,ObjectListNode*);
ObjectListNode*fn_80285D34(ObjectListPool*);
}
inline ObjectListPool* objectListPool(){return ((ObjectListGlobals*)&lbl_801E9D24)->pool;}
typedef char CheckObjectListEmptyHandle[sizeof(ObjectListEmptyHandle)==4?1:-1];
typedef char CheckObjectListNode[sizeof(ObjectListNode)==20?1:-1];
typedef char CheckObjectListRecord[sizeof(ObjectListRecord)==44?1:-1];
typedef char CheckObjectListPool[sizeof(ObjectListPool)==0x15048?1:-1];
#endif
