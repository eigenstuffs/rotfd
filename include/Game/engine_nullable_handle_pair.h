#ifndef GAME_ENGINE_NULLABLE_HANDLE_PAIR_H
#define GAME_ENGINE_NULLABLE_HANDLE_PAIR_H

/* Partial views of the observed index/Handle fields. Source records retain
 * mutable Handle references; the full original class types are unrecovered. */
struct NullablePairContext {char unknown00[0x118];void*manager118;char unknown11C[0x3C];void*manager158;};
struct Handle_801F7F10 {unsigned long value;Handle_801F7F10();~Handle_801F7F10();};
extern "C" NullablePairContext lbl_801E9D24;
extern "C" void fn_801F86C8(void*,const Handle_801F7F10*,short);
extern "C" void fn_8023B418(void*,const Handle_801F7F10*,int,int,unsigned int,const Handle_801F7F10*);
struct NullablePairZeroHandle:Handle_801F7F10 {NullablePairZeroHandle(){value=0;}~NullablePairZeroHandle(){}};
struct NullablePairCopyHandle:NullablePairZeroHandle {NullablePairCopyHandle(const NullablePairZeroHandle&from){value=from.value;fn_801F86C8(lbl_801E9D24.manager118,&from,1);}};
struct NullablePairSource {unsigned long unknown00;NullablePairZeroHandle handle04;NullablePairZeroHandle&handle(){return handle04;}};
struct NullablePairSelf {char unknown00[0x54];int index54;NullablePairZeroHandle handle58;};
struct NullablePairTwoZeroHandle:NullablePairZeroHandle {NullablePairTwoZeroHandle(){value=0;}~NullablePairTwoZeroHandle(){}};
extern "C" void fn_80255D88(NullablePairSelf*,int,unsigned int,NullablePairSource*,NullablePairSource*);

#endif
