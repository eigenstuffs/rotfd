# Native nested-record constructor

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_nested_record_construct_800E65F4.cpp` recovers the native
`Record_800E6A58` constructor at `0x800E65F4..0x800E69E4`. Its complete 1,008
code bytes, 272 exception bytes, 12 index bytes and 57 actual relocations match
under GC/1.3.2 with the established space-optimization and exception flags.
No extra functions, weak helpers, initialized data, BSS or padding are emitted.

The source retains seven observed group classes at offsets F0/A80/1070/1830/
1FF0/27B0/3140, with capacities 5/3/4/4/4/5/4 and 0x1D0-byte records. Their
existing native destructor identities remain unchanged. Each group derives
from the observed 0x80 header with its existing native destructor; its inline
constructor clears the observed words/flags and 50 short indices, sets nine
header bytes, then invokes the original array-construction runtime on its
byte-backed record storage. The final 300 two-byte records use the same runtime.
Its declared callback arguments follow the runtime's actual `void*` ABI.

Both existing accepted C initializer callbacks, 800E5F40 and 800E6A48, preserve
their identifiers, implementation and ownership. The proposal does not require
renaming those callbacks or changing any accepted source. All constructor and
destructor callback addresses passed into the runtime are verified actual ELF
relocations. Group-header cleanup, all seven group lifetimes and exception-action
branch reuse reproduce the original 272-byte exception table exactly.

The outer prefix initializes its observed words before its member groups; the
body finally clears the 100 short indices at offset28. It also explicitly
initializes word3B58 to zero. This directly proves the final four-byte tail and
complete 0x3B5C record extent previously established by array stride. The older
accepted destructor's minimum private destruction view of 0x3B58 is unchanged.
Size assertions check the 0x80 group header, 0xF0 outer prefix and full record.

The native name `__ct__15Record_800E6A58Fv` preserves the existing destructor's
class identity. It is the same guarded dependency proposed by the preceding
record/string-constructor pair; integration must coordinate that publication
with this body. No earlier accepted C-name callers require migration. The full
original exception-index/constructor/destructor and initialized-data-pointer
scans found only the owned exception-index self-pointer. Existing metadata and
all original code/data outside this partial fragment retain their ownership.

The isolated verifier recompiles the production source and checks all allocated
sections, symbol extents, bytes and real relocations without masks. Full native
DOL/hash, source-extent and regression acceptance remain the integrator's gate.
