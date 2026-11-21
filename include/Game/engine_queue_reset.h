#ifndef GAME_ENGINE_QUEUE_RESET_H
#define GAME_ENGINE_QUEUE_RESET_H

struct Handle_801F7F10 {
 union {unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};
 Handle_801F7F10(){bits.index=0;bits.tag=0;}
 ~Handle_801F7F10();
};
struct QueueResetTarget {char unknown00[0x1C];float value;};
struct QueueResetEntry {QueueResetTarget*object;unsigned long key;int unknown08;signed char tag;char unknown0D[3];};
struct QueueResetManager {int count,capacity;QueueResetEntry*entries;};
struct QueueResetContext {char unknown00[0x118];QueueResetManager*manager;};
struct QueueResetPrefix {char unknown00[8];};
struct QueueResetOwner : QueueResetPrefix {
 virtual ~QueueResetOwner();
 virtual void unknown0C();virtual void unknown10();virtual void unknown14();virtual void unknown18();
 virtual void unknown1C();virtual void unknown20();virtual void unknown24();virtual void unknown28();
 virtual void replace(const Handle_801F7F10&,int);
 virtual void unknown30();virtual void unknown34();virtual int size();
 Handle_801F7F10 parent;
 int scalar10;
 Handle_801F7F10 handles[16];
 int count,state;
 char flag5C,flag5D;
};
extern "C" {
extern QueueResetContext lbl_801E9D24;
extern const float lbl_8037B1D4;
void fn_801F7914(Handle_801F7F10*,const Handle_801F7F10&);
unsigned long fn_801F7EB8(const Handle_801F7F10*);
}

typedef char CheckQueueResetHandleSize[sizeof(Handle_801F7F10) == 4 ? 1 : -1];
typedef char CheckQueueResetEntrySize[sizeof(QueueResetEntry) == 16 ? 1 : -1];
extern "C" void fn_80230DF8(QueueResetOwner *, int, signed char);

#endif
