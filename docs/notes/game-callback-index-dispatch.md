# Callback index dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_8025D054` reconstructs the complete 372-byte function at
`0x8025D054..0x8025D1C8`. It resolves the owner's handle at `0x6C` and calls
three original operations, updates the `0x60` object, calls owner virtual
slot `0x74` with two zero arguments, and selects mode three. It then sends
the integer index at `0x64` as a float to the resolved `0x60` object, along
with the owner's handle at `0x04`, event eleven and mask `0x1F`.

The final conversion is evaluated before the final handle resolution.
Ordinary C++ integer-to-float conversion emits the native eight-byte bias
constant at `0x8037B550..0x8037B558`, including its eight-byte alignment.
This source owns that genuine compiler literal together with the function.
The current original assembly has no references to this constant outside
the reconstructed function. Other data and neighboring functions retain
their existing owners. The native virtual interface remains a partial
declaration with the observed vtable at offset eight.

`scratch/game_callback_index_dispatch/verify.py` checks all 380 allocated
bytes, exact function and literal extents, and every actual relocation
without masks, including the compiler's local SDA21 literal reference.
The strict verifier applies that relocation to the literal's owned section
address and the executable's real r2 base. No extra allocation, discarded
helper, exception table or startup entry is emitted. Full executable and
baseline acceptance is required before matching credit.
