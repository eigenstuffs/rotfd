#ifndef GAME_PLATFORM_OWNER_COMPLETION_H
#define GAME_PLATFORM_OWNER_COMPLETION_H
typedef unsigned long Word;
struct CompletionHandle {signed int generation:8; signed int index:24;};
#include "Game/tree_handle_propagation.h"
struct CompletionZero1:Handle_801F7F10{CompletionZero1(){value=0;}};
struct CompletionZero2:CompletionZero1{CompletionZero2(){value=0;}};
struct CompletionZero3:CompletionZero2{CompletionZero3(){value=0;}};
struct CompletionObject {char unknown00[0x1c];CompletionHandle classHandle,related;char unknown24[0x48];unsigned short type;char unknown6e[0xb2];Word flags;};
struct CompletionEntry{CompletionObject*object;char unknown04[8];signed char generation;char unknown0d[3];signed char getGeneration()const{return generation;}};
struct CompletionManager{char unknown00[8];CompletionEntry*entries;};
struct CompletionResourceView {char unknown00[0x28C];Handle_801F7F10 propagationHandle;};
struct CompletionContext{char unknown00[0x118];CompletionManager*manager;char unknown11c[0x30];CompletionResourceView*resource;};
struct CompletionOwner{char unknown00[12];int count,capacity;CompletionHandle*items;char unknown18[24];CompletionHandle owner;};
extern "C"{extern CompletionContext lbl_801E9D24;void fn_801CBC64(CompletionObject*,CompletionObject*);}
static inline CompletionObject*resolve(const CompletionHandle& h){int index=h.index;CompletionManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();return generation==h.generation?m->entries[index].object:0;}

typedef char CompletionHandleSize[sizeof(CompletionHandle)==4?1:-1];
typedef char CompletionEntrySize[sizeof(CompletionEntry)==16?1:-1];
#endif
