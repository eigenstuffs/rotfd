/* MetroTRK saved exception ID and target control state.
 *
 * Uninitialized definitions are emitted in reverse order, so the 16-bit
 * exception ID lands first at 0x8033AA80 and gTRKState (0xA4 bytes) at
 * 0x8033AA84. The exception ID keeps its address-suffixed linkage name, which
 * targimpl_asm.c references directly. */
#include "targimpl_abi.h"

typedef char TRKStateSizeCheck[sizeof(TRKState_PPC) == 0xA4 ? 1 : -1];

TRKState_PPC gTRKState;
u16 TRK_saved_exceptionID_8033AA80;
