# Mesh scratch startup

The genuine C++ global-array source reconstructs `fn_80281674`
(`80281674..802816D0`, 92 bytes), its original four-byte constructor-table
pointer (`8029995C..80299960`), and both original 48 KiB vector arrays
(`80341360..80359360`). All initialized allocated bytes, eleven actual ELF
relocations, BSS extents and symbol bindings match in an isolated production
compile. Full original-DOL acceptance remains the integrator's next step.

Two ordinary definitions of `Vector3_801D5330[4096]` naturally emit the exact
initializer and `.ctors` entry. The compiler-local identity is
`__sinit_engine_mesh_scratch_startup_cpp`; it replaces the provisional C name
`fn_80281674` at the same address and extent. The original constructor table
is the only reference to the old startup entry. No C wrapper, hand-built
constructor table, alias, custom section or object-payload change is used.
The external existing four-byte `__ct__16Vector3_801D5330Fv` constructor is
called through `__construct_array` and receives no new credit.

Both BSS symbols retain their original global names, addresses and complete
`0xC000` extents: `lbl_80341360` and `lbl_8034D360`. The compiler emits one
`SHT_NOBITS` allocation of `0x18000` bytes with alignment eight; the two
objects occupy offsets zero and `0xC000`, with no gap or trailing padding.
This is zero-initialized storage with no executable-file payload. The original
DOL BSS span covers it completely and no initialized DOL section overlaps it.
Existing byte-view declarations in other translation units are preserved.
The dedicated vector declaration agrees with the existing native three-float
layout and external constructor declaration.

The full active census inspected 9,741 distinct target/source ELF objects.
It found the two original BSS definitions and 24 actual allocated references
to the owned range; original initialized data has no aligned or unaligned
pointer into either array. All original and current function, constructor and
array consumers are inventoried with hashes. The new native startup name has
no prior active binding. Complete original extabindex/ctor/dtor auditing finds
exactly the owned constructor pointer and no exception/destructor record.
No accepted source, header or canonical record is changed by this proposal.

The Game compiler is `GC/1.3.2 -O4,p`, exceptions off, with its standard
flags. It emits only the initializer, constructor-table pointer and arrays;
there are no weak helpers, extra data, BSS, exception allocations or destructor
records. One compiler `.mwcats.text` relocation is nonallocated metadata,
fully inventoried and excluded from source ownership.

The immutable continuation ELF core assumes initialized DOL storage, so a
separate source-bound `strict.py` verifies this exact NOBITS case. It uses the
unchanged core reader, original initialized-byte accessor and external symbol
map, checks the complete section/symbol inventory, resolves every real
relocation and validates the BSS type/extent/alignment against the DOL header.
It does not synthesize or rewrite object bytes. Thirteen rejected test-only
mutations cover allocation types, sizes, alignments, flags, symbol extents,
bindings, offsets, instructions, relocation kinds and addends. Mutated test
objects are not build proposals.

Evidence is frozen under `scratch/engine_mesh_scratch_startup_20261011hc`.
`final_integration.json` records every source allocation; `verify.py` recompiles
production source, repeats the strict object and complete original table
checks, and validates frozen hashes. `adoption_proposal.json` pins the separate
verifier and immutable core for root review. Other mesh transforms and renderer
routines remain outside this unit.
