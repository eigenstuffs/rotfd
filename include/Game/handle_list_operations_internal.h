#ifndef GAME_HANDLE_LIST_OPERATIONS_INTERNAL_H
#define GAME_HANDLE_LIST_OPERATIONS_INTERNAL_H

struct Handle {union {unsigned long value;struct {signed int generation:8;signed int index:24;} bits;};};
struct Object {char unknown00[0x20];Handle related;};
struct Entry {Object*object;int unknown04,unknown08;signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct Manager {int count,capacity;Entry*entries;};
extern "C" {extern struct {char unknown00[0x118];Manager*manager;} lbl_801E9D24;Object* fn_801F7EB8(Handle*);void fn_801EE978(Object*);}
static inline Object*resolved(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();return generation==h.bits.generation?m->entries[index].object:0;}
static inline bool equal(const Handle&a,const Handle&b){Object*object=resolved(b);Object*other=resolved(a);return object==other;}
struct Array {int count,capacity;Handle*data;Handle&operator[](int i){return data[i];}};
struct View {char unknown00[0xC100];Array handles;};

typedef char CheckHandleListOperationHandle[sizeof(Handle)==4?1:-1];
typedef char CheckHandleListOperationEntry[sizeof(Entry)==16?1:-1];
typedef char CheckHandleListOperationArray[sizeof(Array)==12?1:-1];
#endif
