# Original game leaf operations

The `src/Game/leaf_*.c` fragments recover ordinary scalar operations selected
from original fallback functions in `0x80020000..0x800F0000`. Every fragment
owns one physically contiguous text range. These are provisional text-only
splits; they do not identify complete original translation units or recover
class layouts.

The integrated initial batch contains **684 functions, 4,068 text bytes, and 317
contiguous fragments**:

| Behavior | Functions |
| --- | ---: |
| Empty operations | 362 |
| Direct global scalar reads | 123 |
| Direct global scalar writes | 114 |
| Integer constants | 43 |
| Scalar field writes | 17 |
| Scalar field reads | 12 |
| Subobject address accessors | 8 |
| Nullable subobject address accessors | 5 |

The original provisional function symbols are retained. Parameter and return
types express the observed register-level behavior and do not claim recovered
class identities. Unused parameters of empty operations remain unknown;
their bodies leave the original incoming argument registers untouched. Field
accessors use explicit byte offsets instead of invented structures. Direct
global stores retain the unused first argument and read their scalar value
from the observed second argument register. Float setters use the observed
floating-point argument register. Existing data symbol names are referenced
without relocating or claiming ownership of those data objects.

For example, `leaf_8002390C.c` contains two word setters at offsets `0x78` and
`0x7C`, four empty operations, and four integer constant-return functions.
`leaf_800E004C.c` contains 104 empty operations and five nullable subobject
accessors. The latter are ordinary null checks and byte-offset adjustments,
with no tail branches or synthesized native thunks.

All fragments compile with the existing Game library compiler **GC/1.3.2**
and its standard flags:

```
-proc gekko -fp hardware -enum int -str reuse -common off
-O4,p -inline auto -Cpp_exceptions off
```

`scratch/game_leaf_continuation/integration.json` records every function's
address, extent, provisional name, and observed operation, every contiguous
source range, and all 237 actual `R_PPC_EMB_SDA21` relocations. `splits.txt`
and `config.txt` in the same directory provide exact integration entries. No
symbol renaming or shared-header change is required.

The isolated verifier reads ELF32 symbol extents and text bytes, resolves each
SDA relocation using the versioned symbol's original address and section, and
compares the complete relocated text to the supported DOL. It rejects
unexpected allocatable relocation sections and any emitted owned data, BSS,
constructor, destructor, or exception-table section. CodeWarrior's
non-allocating `.mwcats` compiler metadata is verified as non-allocating and
has no DOL ownership. No relocation bits are masked. All 317 initial
candidates pass this strict isolated check with their full original function
sizes and symbol bindings.

The recovery generator and excluded candidates are preserved under
`scratch/game_leaf_continuation/`. Adjusting tail-branch wrappers, native ABI
entries, and more complex small functions are excluded. A standalone
`verify.py` recompiles the production sources without modifying ownership or
configuration. Full integration passes the original DOL hash, native objdiff,
source-extent audit and regression comparison. The original shared data and
unrecovered functions remain in the full progress denominator.
