#ifndef GAME_CALLBACK_HANDLE_CHAIN_INTERNAL_H
#define GAME_CALLBACK_HANDLE_CHAIN_INTERNAL_H

struct ChainHandle {signed int generation:8;signed int index:24;};
struct ChainObject {char unknown0[0x1C];ChainHandle related;};
struct ChainEntry {ChainObject *object;char unknown4[8];signed char generation;char unknownD[3];signed char getGeneration()const{return generation;}};
struct ChainManager {char unknown0[8];ChainEntry *entries;};
extern "C" {extern struct {char unknown0[0x118];ChainManager *manager;} lbl_801E9D24;void fn_802432A8(ChainObject*);void fn_802431F8(ChainObject*);}
struct ChainOwner {char unknown0[0x58];ChainHandle owner;};
inline ChainObject *resolve(const ChainHandle&h) {int index=h.index;ChainManager *m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();return generation==h.generation?m->entries[index].object:0;}

#endif
