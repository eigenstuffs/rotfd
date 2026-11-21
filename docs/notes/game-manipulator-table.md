# Native Manipulator table ownership

The integrated replacement preserves the existing four
`src/Game/objects_root_callbacks.cpp` functions (**168 code bytes**) and its
four-byte zero constant, and adds the compiler-generated **64-byte** native
table at `0x802EB200..0x802EB240`. The isolated proof, full normal link,
original-DOL comparison and native objdiff checks pass. The change adds exactly
64 data bytes to source coverage, with no new code, functions or source units.

The proposed source in
`scratch/game_manipulator_vtable_emission/objects_root_callbacks.cpp` has been
copied into the existing production source without changing its unit identity.
Its new
private header is `src/Game/manipulator_callbacks_internal.h`. The existing
`objects_root_callbacks_internal.h`, also used by the activation source, is
unchanged. The canonical manifest is
`config/GSQE78/candidates/game-objects-root-callbacks.json`; the original proposal
is archived in `scratch/manipulator_table_before/game-objects-root-callbacks-table.json`.

The original standalone native destructor probe generated 124 exact code bytes,
40 exception-table bytes, 12 exception-index bytes and the complete native
table. It remains in `scratch/game_manipulator_destructor/probe.cpp`, with an
independent all-section review in `independent_review.json`. Linking its early
code at `0x8002798C` and later table at `0x802EB200` as one object introduced an
ordering cycle with the lower Activable unit. The accepted early source
`src/Game/manipulator_destructor.cpp` therefore uses the observed native
destructor/storage view and an external table, preserving its 124 code bytes
and 52 metadata bytes.

The later proposal uses an ordinary inline virtual destructor definition. That
makes `slot2C(float)` the first non-inline virtual introduced by this class,
so CodeWarrior emits the native table with the existing callback definitions.
The inline destructor is also emitted as a weak out-of-line duplicate. Its
canonical identity is the same as the already accepted strong definition:
`__dt__20ObjectsRoot_80213EBCFv` at `0x8002798C`. Ordinary strong/weak resolution
must select that earlier definition and discard the later duplicate and its
associated exception metadata.

The proposal uses the established `GC/1.3.2` Gekko hardware-FP settings with
`-O4,s -inline auto -Cpp_exceptions on -RTTI off -use_lmw_stmw on`.
`#pragma exceptions off` surrounds the original callback bodies, which have no
exception records, and `#pragma exceptions on` restores the setting before
deferred emission of the inline destructor. This preserves the destructor's
original `throw()` deletion handler and metadata without adding callback
metadata. These are supported compiler pragmas already used by the project;
no emitted object is altered.

| Output | Emitted bytes | Treatment |
| --- | ---: | --- |
| `.text` original callback prefix | 168 | Existing retained source at `0x80213E58..0x80213F00` |
| `.text` weak destructor suffix | 124 | Exact duplicate at object offset `0xA8`; resolves to existing strong `0x8002798C` |
| `extab` | 40 | Exact duplicate of original destructor metadata at `0x80006500` |
| `extabindex` | 12 | Exact duplicate of original index at `0x80016590` |
| `.data` native table | 64 | New ownership at `0x802EB200..0x802EB240`, alignment eight |
| `.sdata2` local `@19` | 4 | Existing zero constant at `0x8037AC50..0x8037AC54`, alignment eight |

The four following original constant-padding bytes at
`0x8037AC54..0x8037AC58` keep their existing fallback owner. The table has no
internal or trailing alignment bytes beyond its semantic entries: two ABI
header words, 13 function pointers and one null abstract-method slot.
Its last word at `+0x3C` points to `slot3C()` at `0x80213E5C`.

The null word at table offset `+0x38` is a semantic virtual slot. The original
`slot2C(float)` loads the object's vptr from offset eight at `0x80213E9C`, loads
the function pointer at table offset `0x38` at `0x80213EA0`, then dispatches
through it with the incoming float. A following nonzero entry at `+0x3C`
also rules out trailing padding. An ordinary pure `slot38(float)` declaration
reproduces this interior null; declaring the destructor pure instead changes
table offset eight to zero and was rejected. The verified inherited
`Root::slot1C()` signed-char return declaration is retained.

The runtime type registry identifies the class as `Manipulator`, derived from
`Activable`. The established address-qualified source identity remains
`ObjectsRoot_80213EBC`. This is a reconstructed native interface and ownership
boundary, not a claim to have recovered every original source declaration.

Run `python3 scratch/game_manipulator_vtable_emission/verify_replacement.py --production`.
The proof records all **28 actual ELF relocations**, split into **19 retained**
and **nine duplicate** records. It compares all allocated bytes, including the
weak destructor and metadata, against the original DOL after real relocation.
The table's destructor relocation resolves to the canonical strong address;
no retained relocation targets the duplicate exception records. The verifier
also reads the configured earlier object and checks that the destructor is
actually `STB_GLOBAL`, `STT_FUNC`, size 124, while the replacement suffix is
`STB_WEAK`, size 124. Source, private/shared-header, object and original-DOL
hashes are recorded in `replacement_proof.json` and the manifest.

The final-link audit checks a single selected destructor at `0x8002798C`,
the table's nonzero destructor pointer to that address, and normal removal of
the duplicate's 124 code and 52 metadata bytes. Central integration passes the
complete original DOL and native source comparisons; byte equality confirms
that duplicate code and metadata introduce no extra linked allocation.
No tooling changes were needed. No aliases, forced object ordering, common-symbol tricks,
invented method bodies, opcode masks or object patches are used.

The supplemental final ELF audit in
[`linked_proof.json`](../../scratch/game_manipulator_vtable_emission/linked_proof.json)
passes: one strong 124-byte destructor remains at `0x8002798C`, one strong
64-byte table remains at `0x802EB200`, and its destructor, null `+0x38`, and
following callback entries have their original values. Native objdiff records
168 code bytes, four functions and 68 data bytes for the callback unit;
duplicate exception records receive no additional credit.

The completed ELF selection audit is
`scratch/game_manipulator_vtable_emission/linked_proof.json`; reproduce with
`python3 scratch/game_manipulator_vtable_emission/verify_link.py`. It confirms
one strong 124-byte destructor and one strong 64-byte table at their original
addresses, with no duplicate code or metadata added to the executable.
