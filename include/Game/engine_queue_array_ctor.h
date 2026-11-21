#ifndef GAME_ENGINE_QUEUE_ARRAY_CTOR_H
#define GAME_ENGINE_QUEUE_ARRAY_CTOR_H

struct RootStorage_80207414 {unsigned long unknown00,identity;};
struct BaseObject_Z:RootStorage_80207414 {BaseObject_Z();virtual ~BaseObject_Z();virtual void slot0C(unsigned long);virtual void slot10();virtual void slot14();virtual void slot18();virtual signed char slot1C();};
struct Handle_801F7F10 {unsigned long value;Handle_801F7F10();~Handle_801F7F10();};
struct QueueArrayZeroHandle:Handle_801F7F10 {QueueArrayZeroHandle(){value=0;}};
struct QueueArrayTwoZeroHandle:QueueArrayZeroHandle {QueueArrayTwoZeroHandle(){value=0;}};
struct QueueArray_802EBD60:BaseObject_Z {
 QueueArrayTwoZeroHandle first;QueueArrayZeroHandle second;Handle_801F7F10 handles[8];char unknown34[0x20];int field54,field58;char unknown5C[2];unsigned char flag;char unknown5F;
 QueueArray_802EBD60();virtual ~QueueArray_802EBD60();virtual void drain(int,int);
};

typedef char QueueArray_802EBD60SizeCheck[(sizeof(QueueArray_802EBD60)==0x60)?1:-1];

#endif
