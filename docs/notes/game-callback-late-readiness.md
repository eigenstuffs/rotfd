# Late callback readiness

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Isolated exact source; central full-DOL acceptance pending.

`src/Game/callback_late_readiness.cpp` reconstructs all 236 bytes of
`fn_8025D3E0`, at `8025D3E0..8025D4CC`. It first calls the original Root
readiness entry. If that reports false, it returns zero. Otherwise it resolves
the receiver's generation-tagged handles at offsets `0x6C` and `0x68`, calls
virtual slot `0x1C` on each resolved object and returns the latter result.
The recovered generation is signed eight-bit and the index signed 24-bit;
entries have the original sixteen-byte stride and generation at offset `0xC`.
The manager remains the original global context's member at offset `0x118`.

A nonpolymorphic eight-byte prefix places the native virtual table at receiver
offset eight; two native table header entries precede the declared slots.
All layouts are bounded partial views. Adjacent methods, complete original
class declarations and data remain under their existing owners.

The recorded GC/1.3.2 flags reproduce the complete allocated text and all three
actual call/address relocations. The object emits only one global function,
with no weak code, data, BSS, literals, padding or exception allocations. Full
original exception-index, ctor and dtor scans have no references to the range.
`scratch/game_callback_late_controls/final_integration.json` contains the
frozen source/object hashes, symbol inventory, actual relocated targets and
ownership proof; `freeze_readiness.py` independently recompiles production
source through the unchanged strict verifier.

The related D4D0/D5F4/EBF0 probes remain private and uncredited.
