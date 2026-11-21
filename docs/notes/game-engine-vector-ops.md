# Engine vector and record operation fragments

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Two production C++ units reconstruct four complete functions, 808 bytes of
`.text`, and no data. Dedicated declarations are in
`include/Game/engine_vector_ops.h`. The names describe observed operation/layout;
these are partial text splits rather than confirmed original translation units.

| Source suffix | Owned text | Functions / bytes | Extra flags |
| --- | --- | ---: | --- |
| `engine_vector_ops_80239458.cpp` | `80239458..802396D0` | 3 / 632 | `-fp_contract on` |
| `engine_vector_ops_80239C80.cpp` | `80239C80..80239D30` | 1 / 176 | none |

Both use the standard Game GC/1.3.2 configuration plus the listed addition.
All four function symbols need global scope. No existing header/source is changed.

## Observed behavior and layout

`fn_80239458` evaluates the original two trigonometric helpers with the angle at
0x50. It scales the resulting coefficients into matrix members at 0x2C, 0x30,
0x38 and 0x3C and computes translation at 0x44/0x48 from the observed centers,
scales, flag byte at 0x70, and original small-data constant. The exact source
retains the two original flag paths and expression association. Enabling floating
point contraction emits the native `fnmsubs`/`fmsubs` instructions; ordinary C++
also produces the native paired-single save/restore for f31. No instructions are
inserted, rewritten or supplied by assembly.

`fn_80239568` calls the Root predicate, then iterates over two packed handles at
0x74/0x78. A valid handle is resolved through the manager's 16-byte generation
entries and receives virtual slot 0x1C. `fn_80239638` restores the observed
external table, destroys those two four-byte handles with the original array
helper/destructor, installs the Resource table and invokes the Root destructor.
A positive signed deletion parameter releases the object through the original
allocator. The explicit source emits no replacement tables or helper bodies.

`fn_80239C80` calls the Root predicate, invokes the original curve operation on
the subobject at 0x10, and dispatches virtual slot 0x1C through the validated
handle at 0xB8. Handle views preserve signed 8-bit generations and signed 24-bit
indices. The declared virtual methods have no definitions and emit no virtual
tables or method implementations.

## Verification and ownership

`scratch/engine_vector_ops_20261010g/final_integration.json` records the two section
extents, all four complete functions/bindings, compiler flags, and 24 actual
relocations. The verifier recompiles the final formatted production sources,
rejects extra allocated sections or functions, applies each REL24/HA/LO/SDA21
relocation to its versioned target, and compares every owned byte directly to
the protected DOL without masking. Both `verify.py` and `audit.py` pass.

Original assembly confirms all complete function bounds. All 3,141 original
`.extabindex` entries and the complete 24-entry `.ctors`/8-entry `.dtors` sections
have no references into the selected functions. There are zero source-owned
exception, startup, data, or BSS bytes. Existing original tables, constants,
manager/allocator globals, trigonometric helpers, handle destructor, curve
operation, and all neighboring functions keep their owners. The ownership audit
retains the original fallback ranges. Central NonMatching registration, full
DOL hash/native comparison and final promotion are the integrator's acceptance.

Private list-update probes for `fn_8023A9FC`/`fn_8023AAAC` retain register allocation
differences. The chain flag routine `fn_8023D8D8` and constructor `fn_802396D0`
also remain private near matches. All probes are preserved and uncredited.
