# Hierarchy range distribution

`src/Game/hierarchy_distribution.cpp` recovers the observed method
`fn_8020279C`, 636 bytes at `0x8020279C..0x80202A18`. The original translation
unit boundary is not established. The source is integrated and passes complete
DOL and native objdiff verification.

The method first evaluates the related-object status query and discards its result, then compares the count at `0x9C`
against the global group count. If it fits, it records the width and offset at
`0xE0`/`0xE4`, walks the two handle lists with data at `0xB0` and `0x98`, and
assigns each valid entry `offset + index % width` through the respective virtual
slots `0x9C` and `0x7C`. It updates the related object at handle offset `0xC0`,
runs the existing hierarchy update, sends an owned copy of its identity to the
global dispatcher, and triggers the final hierarchy notification.

The private layouts preserve the signed 24-bit index/signed 8-bit generation
handle representation and the observed 16-byte manager entry. Native C++ virtual
calls put the object vptr at `0x08` and dispatcher vptr at `0x30`. The source
uses the centrally canonical native Handle constructor/destructor.

## Compiler and source evidence

The exact compiler is `GC/1.3.2`, with `-O4,p -inline auto`, hardware floating
point, exceptions disabled, and `-use_lmw_stmw on`; all options are recorded in
`config/GSQE78/candidates/game-hierarchy-distribution.json`.

The count must be read before calling the global count helper. An explicit local
recovers the original saved register and load order. The final identity copy uses
a genuine inline `const Handle& getOwner() const` accessor. Its result remains in
`r29` across the native constructor, reproducing the original 636-byte method.
Direct member access produces a 632-byte body and rematerializes the identity
address after the constructor. The owned wrapper derives directly from the native
Handle; inserting a separate zeroing base retains an extra zero store and changes
the temporary pointer lifetime. These variants remain under
`scratch/game_hierarchy_distribution/` for comparison.

## Verification and ownership

Run:

```sh
python3 scratch/game_hierarchy_distribution/verify.py
```

The verifier compiles the production source and applies all 17 retained ELF
relocations at their original addresses. Every one of the 636 retained text bytes
matches the protected original DOL. There are no owned data sections; the global
context, float at `0x8037A900`, and existing callees remain external dependencies.
The original DOL SHA-1 is checked before comparison:
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

One unused weak wrapper destructor, `__dt__18DistributionHandleFv`, occupies
84 bytes at object offset `0x27C` and contains two relocations. It has no retained
references and is left to normal linker dead stripping. Its extent, weak binding,
and exclusion are explicitly checked; it receives no new source credit. The
verifier accounts for the entire allocated object, requires the original section
alignment, and rejects references into discarded functions. No original bytes,
instructions, or relocation fields are patched or masked.

The integrated candidate `config/GSQE78/candidates/game-hierarchy-distribution.json`
records successful full-DOL and native objdiff verification, and its recorded
source hash matches the current file. `build/GSQE78/report.json` reports 100%
matching for `main/Game/hierarchy_distribution`: one function, all 636 code
bytes, and no owned data. The rebuilt and untouched original DOL both have
SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.
