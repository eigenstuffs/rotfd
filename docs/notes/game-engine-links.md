# Engine list links and drawing-object lifetimes

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Six ordinary C/C++ functions reconstruct **1,552 text bytes**, with no owned
non-text data. The frozen handoff is
`scratch/game_engine_links_continuation/final_integration.json`; exact split and
configure snippets are `final_splits.txt` and `final_config.txt`. All six use
GC/1.3.2 with the standard game flags and exceptions off, without extra flags.

| Original entry | Compiler entry | Bytes | Recovered behavior |
| --- | --- | ---: | --- |
| `fn_801C2F70` | `__dt__17DrawPair_801C2F70Fv` | 500 | Destroy two 32-byte-record pools, three typed owner handles, and the existing object base; conditionally free the allocation. |
| `fn_801C8374` | `__dt__17DrawNode_801C8374Fv` | 268 | Destroy a 32-byte-record pool and the existing object base; conditionally free the allocation. |
| `fn_801CF7E4` | unchanged | 232 | Obtain a list slot, call the previous owner's virtual slot 0x54 when present, and replace its record number and owner. |
| `fn_801D7B5C` | unchanged | 204 | Obtain a list slot, clear its previous owner's 0x68-byte record backlink, and replace the record number and owner. |
| `fn_801D7C28` | unchanged | 180 | Perform the corresponding typed-owner operation using the owner's record pointer at 0xD0. |
| `fn_801EDAAC` | unchanged | 168 | Apply the observed state-bit conditions and scalar writes at 0xC0, 0xC4 and 0xC8. |

The list entries have 12-byte stride: packed owner at 0, record number at 4,
and list links at 8 and 0xA. The tagged registry lookup uses an eight-bit signed
tag, signed 24-bit index, 16-byte registry entries and the registry pointer at
global offset 0x118. Byte-addressed backing storage and an ordinary inline
entry accessor preserve the original index arithmetic. These private views
state only fields observed in this code; they do not establish full class names.

The native drawing destructors use ordinary C++ member/base destruction and
class-specific `operator delete`. Their empty element destructors naturally
retain the original optimized destructor loops. The pair's handle members at
0x24 and 0x28 have two inline type layers; its 0x30 handle has three. Existing
native handle and object-owner destructor symbols remain dependencies.

## Native names and integration

Only the two drawing destructors require symbol-definition renames. Their
manifest function records include `original_symbol`; neither old provisional
name occurs in accepted source callers. The integrator should rename each
single versioned definition to its compiler entry. Existing original assembly
references, including the original table data, retain the same target address.
No alias, assembly thunk, duplicate implementation or caller-byte change is
needed. Every relocation dependency is listed with its versioned address and
section in the manifest. The four other global entry names are unchanged.

## Verification and ownership

The strict verifier recompiles all six production sources and checks complete
allocated sections, exact function names/bindings/offsets/sizes and **38 actual
relocations** against the normalized original DOL. No relocation bits are
masked. Every allocated byte is accounted for; these accepted objects emit no
additional weak functions, helper functions, data or exception records. The
finalizer and verifier passed after formatting and private type-name cleanup.

`ownership_audit.json` records the original units' complete section ranges and
checks every true function extent against original assembly. Independent scans
of the complete original `.extabindex` and `.ctors` found no associated records
or startup references. These are partial text units: other original functions,
vtable/type data and remaining sections retain original ownership. Native
whole-DOL hash, extent, and regression checks remain with the integrator.
No shared metadata, progress files or expected hashes were changed here.

## Uncredited probes

The scratch directory retains bounded probes for `fn_801D8580`, `fn_801D864C`,
`fn_801D9ED0`, `fn_801E1378`, `fn_801C9E3C` and `fn_801C4BC4`. They are absent
from the manifest. Register allocation and container-addressing differences
remain. The layered temporary probe for `fn_801C4BC4` emits unused weak
functions and still differs in its retained entry; none of those bytes is
claimed. Raw/masked diagnostic similarities are not acceptance evidence.
