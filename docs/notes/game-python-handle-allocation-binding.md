# Python typed Handle allocation binding

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The `800D00E8` binding parses three Python objects, converts their native
pointers, constructs an empty typed Handle, passes a Key aggregate by value to
the native service, and allocates a copy of its returned Handle. Ordinary C++
source reproduces all 604 code bytes, 68 exception bytes and twelve index bytes,
including all 37 actual retained relocations.

The native Handle at `80020B90` has two zero-initializing layers; it shares the
`80020478` base with the separate copied `80020834` type. A first private
three-layer declaration reproduced the retained instructions but emitted an
incorrect 120-byte duplicate destructor. The strict strong-owner size gate
rejected it. The corrected ordinary declaration emits the original 116-byte
shape. All rejected private evidence remains preserved and uncredited.

Two `DESTROYLOCALCOND` records contain uninitialized compiler alignment pairs
at object offsets 50–51 and 62–63 in `extab`, original addresses `8001397A` and
`80013986`. The runtime structure places these two bytes between the `local`
short and the aligned destructor pointer; the unwinder does not read them.
The build framework's supported `extab_padding=[0x37,0x01,0x37,0x01]` invokes
`dtk extab clean`, restoring the original `37 01` pairs without changing the
reference DOL or any instruction, semantic exception field, symbol extent or
actual allocated relocation. Raw and cleaned object hashes and every changed
allocated byte are frozen in the manifest.

DTK removes the nonallocated `.mwcats.text` category metadata. A separate,
bounded adapter verifies complete category coverage in a fresh raw compiler
object, checks all raw/clean allocated bytes and actual relocation identities,
and carries that verified inventory into the unchanged strict allocation and
exception-group checks. Its source differs from the adopted core at only that
metadata check; the original adopted verifier and hashes remain intact. Twelve
guard tests accept the valid cleanup and reject changed instructions, condition
and local fields, relocations, padding values, action placement, runtime proof,
missing or changed raw categories, and a mismatched adapter inventory.

Three duplicate weak destructors add 344 code and 156 metadata bytes with 21
backup relocations. These remain uncredited. Final native linking must select
the independently verified original strong owners at `80020478`, `80020834`,
and `80020B90`, and discard every duplicate body and backup exception record.
Original exception-index and startup/shutdown ownership remains complete.

Evidence is preserved in `scratch/game_python_handle_allocation/` and the
continuation's `audit_extab_padding.py`, `weak_override_padding.py` and
`test_extab_padding_guard.py`.
