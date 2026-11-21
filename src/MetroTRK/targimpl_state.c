/* MetroTRK target register state storage.
 *
 * Deferred uninitialized definitions preserve the original CPU, default-save,
 * and temporary-value order. The saved exception ID and target control state
 * remain in original storage. The next four native bytes are linker alignment.
 */
#include "targimpl_abi.h"

u128 TRKvalue128_temp;
Default_PPC gTRKSaveState;
ProcessorState_PPC gTRKCPUState;

typedef char CPUSizeCheck[sizeof(ProcessorState_PPC) == 0x430 ? 1 : -1];
typedef char SaveSizeCheck[sizeof(Default_PPC) == 0x94 ? 1 : -1];
typedef char TempSizeCheck[sizeof(u128) == 0x10 ? 1 : -1];
