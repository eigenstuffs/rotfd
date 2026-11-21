# Agent construction and native Lod destructor identity

This is a frozen, isolated proposal. The source is not registered or credited by
this handoff. Root must first adopt the guarded destructor ownership and consumer
identity transaction, then pass the full production checkpoint.

`Agent_8002B5F4::Agent_8002B5F4()` at `8002B5F4..8002B67C` reconstructs
136 original text bytes and its original 28-byte exception record at
`80006A14..80006A30`, with the 12-byte index at `800169F8..80016A04`.
The constructor name already exists in current symbols and accepted callers;
there is no new constructor rename. It calls the existing native Lod constructor
and constructs a nontrivial four-byte Handle member at offset `80`, then clears
that handle word, clears byte `88`, sets short `8A` to one, and clears word `8C`.
It sets the three observed bits in the 64-bit flags at `38`. The word at `84`
remains opaque and untouched.

The source uses same-layout partial views with a small empty constructor layer
expressing the required vtable store before member construction. This layer is
an ordinary source reconstruction, not a claim about an original class name.
The observed base extent is `80` and Agent extent is `90`, both eight-byte
aligned. Existing factory and derived-class headers remain independent partial
views and are unchanged. All original vtable labels and table ownership remain
external, including `lbl_802B170C` and `lbl_802EC8A8`.

The original exception record destroys the Lod base via `dtor_80024E50`.
A genuine C++ constructor emits the native name
`__dt__17LodAgent_802EC8A8Fv`. The new destructor source independently reproduces
all 124 original text bytes at `80024E50..80024ECC`, all 40 exception bytes at
`80005F70..80005F98`, and its 12-byte index at `80016398..800163A4`.
Its ordinary destructor body writes the Lod vtable and calls `fn_80020FE8`;
its class delete operator retains the original allocator and empty exception
specification. All 176 owned raw bytes, section attributes, symbol extents, and
nine resolved relocation places, kinds, addends, and targets equal the existing
accepted C implementation. This replacement earns zero additional credit.
The old source, canonical, object, and all consumer files have preserved copies.

The active census inspected 10,379 current original/source ELFs. The native Lod
destructor name has no current strong, weak, undefined, or relocation entry.
Exactly three compiled consumer sources and one shared header use the old C
name; their exact paths, hashes, objects, canonical owners, and proposed
identifier replacements are in `consumer_migration_proposal.json`. None was
edited. Original generated assembly and vtable references will retain the same
addresses when root adopts the native identity. The full original bytewise
initialized-data and branch scans found four entry pointers and 24 external
entry branches, with no external interior pointers. Both functions have exactly
one original exception record and no constructor or shutdown table slots.

The Agent constructor additionally emits one unreferenced 76-byte weak Handle
cleanup helper and its 8-byte exception/12-byte index backups. Those allocations
and all four backup relocations are fully inventoried, discarded, and uncredited.
The unchanged standard weak/EH verifier accepts the exact fixture with an empty
strong-override list; there is no retained reference to a defined weak helper and
no new verifier route or relaxation. The constructor has seven retained actual
relocations. The final manifest includes all eleven constructor relocations,
including backups, and all nine destructor relocations.

Fresh independent compiles reproduce both complete ELF byte streams and full
symbol inventories. Twenty-three rejecting mutations exercise source/header
hashes, original section placements, function and index extents, dependency
addresses, retained code/EH payloads, backup payload/inventory, and the pending
native base-destructor target. The original strict verifier is unchanged.
The isolated proof explicitly binds the proposed native destructor to its
separately proved original extent; this private proposal binding is not an alias
or a change to production symbols. Production acceptance requires root's actual
identity adoption and complete native backup-discard checks in both full ELFs,
original DOL SHA-1, baseline comparison, source extents, progress, and tests.

Preserved audit iterations include a relocation-displacement guard that was
corrected to mutate an opcode outside a relocation, and two census bookkeeping
repairs for hexadecimal section bounds and destructor-versus-constructor names.
They changed no source, compiler object, original data, or verifier core.
