# Memory-card state names

The private source `src/Game/memory_card_state_names_802AB638.cpp` reconstructs
twenty-three ordinary GLOBAL character arrays from `802AB638` through `802AB87A`.
Their names describe deletion, formatting, save/load and card-status states.
Each initializer includes exactly one terminating NUL. Seventeen natural
compiler alignment gaps contribute 36 bytes, giving 578 emitted `.rodata` bytes
with no code or relocations.

The adjacent original-only gaps are three bytes at `802AB635` and six bytes at
`802AB87A`. They are excluded from source ownership. Native ELF identities are
GLOBAL OBJECT even though the original config entries omit explicit scope.

The frozen accepted snapshot contains twenty-three genuine ADDR32 `.sdata`
references and twenty-three initialized pointer words to these names. These
must retain their original origins and targets. The current consumer census,
native link proof, final handoff and full-build acceptance are pending; this
private compiler match earns no progress yet.
