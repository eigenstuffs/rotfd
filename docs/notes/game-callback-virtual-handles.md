# Callback virtual-handle controls

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Six complete functions in four bounded text units reconstruct 1,224 bytes.
The partial interface declares the native virtual pointer at `+08`, state at
`+38`, and the observed handle getter at slot `78`; original tables and global
manager storage remain externally owned.

`8025A190` (180) checks 64-bit state mask `40000`, conditionally forwards through
handle `+70`, and invokes the original lower control. `8025BE2C` (224) requests
handle minus one through slot `78`, checks the original pointer resolver,
requests the handle again, resolves its generation/index, releases its owned
handle at `+28`, copies the incoming handle, then retains it. The second getter
and resolve are preserved around the observable virtual call.

`8025C080` (172) preserves the signed-char root status and otherwise returns
the resolved slot `1C` status. `8025C12C` and `8025C208` (220 each) conditionally
forward activation/deactivation through virtual handles and invoke their
original local controls. `8025C2E4` (208) invokes receiver slot `28` with zero,
then resolved slot `34` when the original virtual handle lookup succeeds.

`scratch/game_callback_virtual_handles/verify.py` checks every final allocated
byte, all six complete global function extents and actual relocations. No
weak helpers, source data, BSS, exception sections or padding are emitted.
Central production, original-table, original DOL hash and regression checks
remain required before matching acceptance.

Neighboring `8025BF0C` remains private: a final pointer comparison is absent
from the compiled probe. `8025A244` also retains unresolved control-flow and
register differences. Neither receives matching credit; all probes remain
under the dedicated scratch directory.
