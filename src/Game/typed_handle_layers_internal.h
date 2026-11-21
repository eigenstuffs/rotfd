#ifndef GAME_TYPED_HANDLE_LAYERS_INTERNAL_H
#define GAME_TYPED_HANDLE_LAYERS_INTERNAL_H
// Four-byte reference handle and observed empty typed-handle inheritance layers.
// Address-based classes do not claim the original template argument names.
extern "C" {extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Handle_801F7F10 {
 signed long generation:8;signed long index:24;
 Handle_801F7F10();~Handle_801F7F10();
};
template<int Depth> struct TypedHandleLayer:TypedHandleLayer<Depth-1> {
 ~TypedHandleLayer(){}
};
template<> struct TypedHandleLayer<1>:Handle_801F7F10 {
 ~TypedHandleLayer(){}
};
#endif
