# Native named resource construction at 800A5D68

The isolated proposal recovers `Object_800A6090::Object_800A6090()` at
800A5D68..800A5F20 (440 bytes), extab 8001078C..80010838 (172 bytes), and
extabindex 8001BABC..8001BAC8 (12 bytes). Native class identity is established
by the already accepted `__dt__15Object_800A6090Fv` at 800A6090. The existing
HudData.h:180 factory at 8007ED68 allocates 0x1988 bytes; the private view has
that full extent, preserving opaque storage and its final three padding bytes.
No claim is made about names or unobserved behavior of opaque members.

The constructor initializes the pool at +20, two twice-zeroed Handle members
at +30/+34, 400 raw records of stride16 beginning +78 through the original
accepted C initializer `fn_800A5F20`, and another twice-zeroed Handle at +1980.
Observed scalar defaults end at byte +1984. It invokes the existing setup
routine, assigns a retained empty Handle to member +34 using the original two
C++ temporary lifetimes, and clears the original global. Borrowed float
constants and all original vtables remain externally owned.

The initial manually stored vtable/base view produced 432 bytes, with eight
missing bytes and swapped saved member pointers. Declaring the genuine
polymorphic Root/Draw/Object hierarchy supplies both original `mr` instructions
and the complete original 440-byte body, without instruction forcing. The
private virtual declarations establish the vptr at +8 and native identity;
unused virtual slots are omitted and the source emits no vtable allocation.
The generated reference to `__vt__15Object_800A6090` denotes the existing
72-byte original object currently named `lbl_802BC988`. A guarded identifier
migration, preserving that object's original external ownership, is required.

The unchanged production ELF/EH verifier proves every emitted allocation and
all actual relocations. Retained code+EH/index match exactly: 35 real retained
relocations. Two weak Handle destructor backups contain 228 uncredited text
bytes plus 104 metadata bytes and fourteen real relocations. Accepted GLOBAL
owners at 80020478 (112) and 80020834 (116) were independently recompiled and
strictly verified, including their full original metadata, bytes, bindings,
and actual relocation targets. The real native linker selects these strong
owners and discards all six backup allocations (text/extab/index per owner);
wrong fixture input basenames are rejected.

Private before/after identifier recompiles cover exactly two accepted sources:
`factories_8007E160.cpp` changes its constructor identifier, and
`engine_fn_eh_800A6090.cpp` changes its vtable identifier. The first contains
one actual call; the second contains two address relocations. Every allocated
payload byte, allocation alignment, actual relocation place and target, and
all other symbols are identical. Neither accepted source was edited here.
Their canonical manifests and original source/object evidence are preserved
under consumer_before, with proposals under consumer_after. The root must
apply its existing ordered consumer-history guard, including prior migrations
of these sources, rather than replacing any historical proof.

The active-input audit examined 5,577 inputs and 131,769 real relocations.
The constructor has exactly one external compiled call plus its original
extabindex pointer; the vtable has the original constructor's two relocations
and the accepted destructor's two. Full original initialized-word and byte-
offset pointer scans, direct-branch census, complete extabindex/ctors/dtors
bounds, and original symbol extents are recorded. The source owns only the
three declared code/EH sections, with no constructor-list record or data pool.
This remains a partial original translation unit.

The proposal is not accepted source credit until the parent repeats fresh
current consumer/canonical/input checks, adopts both guarded native identities,
verifies the native constructor at its original address and extent, checks
all backup text+metadata absent and original strong owners retained in both
full ELFs, and passes the unchanged original DOL hash and regression gates.
All older cores and frozen handoffs remain untouched. Documentation hashes
are adoption evidence, while persistent compiler authorizations pin source,
manifest, compiler and ownership proof; accepted notes may be refreshed.
