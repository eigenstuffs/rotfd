/* Game heap manager instance (44 bytes, zero-initialized).
 *
 * The original image stores this object inside .text, between the recovered
 * TU ending at 0x801EF5C8 and fn_801EF5F4 (allocator_copy.c). The allocator
 * (allocator.c, engine_leaf_801EF610.c) and every operator delete pass its
 * address as the Heap*; see allocator_internal.h for the layout. */
#include "allocator_internal.h"

#pragma explicit_zero_data on
#pragma force_active on
__declspec(section ".text") Heap lbl_801EF5C8 = { 0 };
#pragma force_active reset
