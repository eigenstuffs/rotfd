# Loading screen construction at 800CAEA0

The isolated native constructor proposal owns 800CAEA0..800CB000 (352 text),
extab 80013448..8001348C (68), and extabindex 8001D1F0..8001D1FC (12).
The existing LoadingScreen.h:45 factory at 8007E2C0 allocates 0x28 bytes.
The accepted C-entry destructor at 800CB000 establishes the same original
72-byte external table and member layout; its current `fn_800CB000` identity
is preserved. The private class is named `Object_800CB000`. Its virtual
DT declaration emits no native Object destructor symbol or relocation.

The genuine Root/Draw polymorphic base occupies 0x20 bytes, with vptr at +8.
Member +20 is the original triply-zeroed Handle_800C5EC8; member +24 is the
original twice-zeroed Handle_800723F4. Their native destructors are externally
declared, so retained cleanup references directly target the accepted owners.
The source emits no retained weak override and no new vtable allocation.

A signed byte at the start of original external lbl_80377880 guards a one-time
initialization of 100 original 24-byte records at lbl_80318028. Five successive
calls to the original random-value function populate floats at offsets
+C,+8,+0,+4,+10, multiplying the original five borrowed constants. Byte +14
is cleared. The three padding bytes of each record remain opaque. All globals,
constants, vtables and other data ownership remain external and unchanged.

The first probe's named record reference produced the exact extent but twelve
instruction differences and two EH PC words, by computing the record address
before the first random call and rotating the loop index/pointer registers.
Direct `array[index].field` assignments reproduce the original source evaluation
and close the complete body and metadata, without forced instructions.

The unchanged strict ELF/EH verifier proves all 352+80 retained original bytes
and 26 actual retained relocations. Two unreferenced, uniquely named private
zero-layer destructor backups contain 156 uncredited code bytes, 40 metadata
bytes and eight real relocations. The actual native linker discards all six
backup text/extab/index allocations; a wrong fixture input basename rejects.
The first native harness failed because absolute linker-generated aliases
cannot satisfy SDA relocation types. The preserved successful v2 proof uses
the actual original constant input and accepted random_state input instead.
No synthetic data definitions or aliases are introduced into production.

Guarded identities are proposed for the constructor (`fn_800CAEA0` to
`__ct__15Object_800CB000Fv`) and the same external 72-byte table
(`lbl_802C1808` to `__vt__15Object_800CB000`). Exactly two accepted source
consumers have private identifier-only proposals: factories_8007E160.cpp and
engine_fn_handle_cleanup_eh_800CB000.cpp. Their current source/canonical pins
include the parent's preceding A5D68 migration. All original allocated bytes,
alignments, actual relocation places/targets and all other symbols remain
identical. The accepted source files were not edited by this proposal.

The refreshed active input census checked 5,578 inputs and 131,788 real
relocations. The constructor's incoming references are its factory call and
original self-index; the table has two references in the original constructor
and two in the accepted destructor. Full original extabindex/ctors/dtors,
direct branches and initialized pointers at every byte offset are audited.
This is a partial original translation unit with no owned data allocation or
startup-list record. Root adoption must repeat fresh consumer identity/history
checks and require dual full-native original constructor/table placement,
backup absence, original DOL hash, regressions, extent/progress and test gates.
Older cores and frozen work remain unchanged.
