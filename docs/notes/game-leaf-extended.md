# Extended original scalar operations

This continuation adds **64 functions, 1,340 text bytes, and 41 contiguous
bounded fragments** under `src/Game/leaf_extended_*.c`. It retains original
provisional symbol names and standard Game **GC/1.3.2** compiler flags. It
changes no shared declarations. One startup pointer is owned with its initializer.

The recovered functions include scalar field/global resets, output error-code
writers, flag updates, indirect float copies, integer record indexing,
64-bit word-pair flag clearing and loading, and floating-point minimum and
maximum selection. All source consists of ordinary C. No native adjusting
tail-branch thunk or assembly body is counted.

Record views expose only independently observed offsets and strides. The
selected-record accessors at `0x80055CD0..0x80055D90` use a default record index
from offset `0xF0`, a record pointer from offset `0x138`, and a `0x94`-byte
record stride. Nested byte accessors use a pointer at record offset `0x2C`,
a second index at object offset `0xF4`, and a 32-byte nested-entry stride.
These private source views preserve unknown regions as padding; they do not
claim original class or field names. Their array/field types reproduce the
original displaced loads without changing the demonstrated behavior.

The two double selectors at `0x800AA52C..0x800AA54C` preserve the original
ordered comparisons. They select the first argument when it is strictly
greater (maximum) or strictly less (minimum), respectively, and otherwise
select the second argument. This includes equal and unordered comparisons.

`scratch/game_leaf_continuation/extended_integration.json` records the final
source ranges, every full function extent, and every external relocation.
`extended_splits.txt` and `extended_config.txt` give exact integration entries.
No symbol renaming is required. Isolated compilation verifies all final
grouped objects against the supported DOL, including actual SDA21 address
relocations. The checker also supports actual address-half relocations for
larger globals; no relocation bits are masked. It rejects unexpected data/BSS,
exception sections, extra functions, and differing section extents.

Initial source variants and failed probes remain in the scratch directory.
Only complete, byte-equal functions enter the final handoff. In particular,
the 64-bit flag-test function and the packed-word helper remain fallback.
The initializer `fn_800C0850` also owns its four-byte `.ctors` entry at
`8029993C..80299940`. An ordinary C function-pointer initializer preserves
that startup registration. The production audit is
`python3 scratch/game_leaf_continuation/verify_extended.py`, which verifies
all allocated sections, complete symbol extents, and actual relocations,
including the constructor pointer. The whole batch is integrated and passes
the original DOL SHA-1 and native objdiff checks.
