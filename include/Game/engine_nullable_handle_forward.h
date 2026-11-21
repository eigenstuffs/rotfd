#ifndef GAME_ENGINE_NULLABLE_HANDLE_FORWARD_H
#define GAME_ENGINE_NULLABLE_HANDLE_FORWARD_H

/* Partial storage views for a nullable source's Handle and the destination
 * control index. Only the observed fields are declared here. */
struct NullableForwardContext {char unknown00[0x118];void*manager118;char unknown11C[0x3C];void*manager158;};
struct Handle_801F7F10 {unsigned long value;Handle_801F7F10();~Handle_801F7F10();};
extern "C" NullableForwardContext lbl_801E9D24;
extern "C" void fn_801F86C8(void*,const Handle_801F7F10*,short);
extern "C" void fn_8023B35C(void*,const Handle_801F7F10*,int,int);
struct NullableForwardZeroHandle:Handle_801F7F10 {NullableForwardZeroHandle(){value=0;}~NullableForwardZeroHandle(){}};
struct NullableForwardCopyHandle:NullableForwardZeroHandle {NullableForwardCopyHandle(const NullableForwardZeroHandle&from){value=from.value;fn_801F86C8(lbl_801E9D24.manager118,&from,1);}};
struct NullableForwardSource {unsigned long unknown00;NullableForwardZeroHandle handle04;};
struct NullableForwardSelf {char unknown00[0x54];int index54;NullableForwardZeroHandle handle58;};
extern "C" void fn_80255CBC(NullableForwardSelf*,int,NullableForwardSource*);

#endif
