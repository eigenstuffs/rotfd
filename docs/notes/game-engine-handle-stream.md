# Registry visits and native handle stream input

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two ordinary C++ routines are recovered as partial text-only splits:

| Function | Text range | Bytes | Retained relocations |
| --- | --- | ---: | ---: |
| `fn_801B4494` | `0x801B4494..0x801B4634` | 416 | 13 |
| `fn_801B4634` | `0x801B4634..0x801B480C` | 472 | 20 |

Strict production recompilation verifies all 888 retained bytes and 33 actual
relocations. Standard CodeWarrior GC/1.3.2 game flags reproduce both bodies.
Original external entry-point names remain unchanged. Neither routine owns
original data, BSS, exception records or constructor references.

`fn_801B4494` measures elapsed time around three passes. Its first pass visits
16-byte entries from owner `+8` while the index is below owner `+0`. For each
nonnull object pointer, it initializes a 12-byte key with `fn_80208BFC(-1)`,
stores the entry's `+4` key and loop index, then calls `fn_802083C8` on owner
`+0xC4` with insertion enabled. Its second and third passes resolve the handle
array at `+0xB8/+0xBC/+0xC0` and call virtual slots `+0x10` and `+0x14` through
object vtables at `+8`. It converts scaled elapsed time to unsigned ticks and
logs minutes, seconds and the remainder modulo 1,000. Reusing the loop index
across the three passes preserves the original zero-register copies.

`fn_801B4634` reads three four-byte words from a stream cursor, updating the
cursor with each `fn_801E9F40` return. The first word is a record size; the
second and third are initialized to zero before the reads. It searches the
registry at owner `+0xC4` using the third word. If the found record points to
a nonnull owner entry, it skips `size-12` additional stream bytes. Otherwise
it obtains a native handle from `fn_801B550C`, copies it through `fn_801F7CB4`,
resolves it, and invokes virtual slot `+0x0C` with the stream. It grows the
owner's handle capacity by 32 when needed and appends a copied handle.

The return declaration for `fn_801B550C` uses the established nontrivial
`Handle_801F7F10` type. A distinct private raw-word `CopyHandle` conversion
constructor calls the original fixed `fn_801F7CB4` entry point. This preserves
the separate returned temporary at stack `+8`, copied handle at `+0x0C`, and
native destructor order without aliases or assembly. Declaring the two key
locals before the size local produces the original stack offsets. The private
copy type's automatic destructor calls the established native destructor;
its known stack address lets the compiler remove an extra null check.

The copy type also emits one unreferenced weak destructor after the retained
472-byte function: `__dt__19CopyHandle_801B4634Fv`, object offset 472, size 84,
with two actual relocations. Its raw SHA256, weak binding, extent and relocation
targets are frozen in the manifest. These 84 bytes are **uncredited and must
be absent from the final linked ELF**. Every emitted allocation is otherwise
fully accounted for; no retained instruction refers to this weak destructor.

Both functions originally belong to the 2,172-byte assembly fragment starting
at `0x801B4230`. Its remaining functions retain original ownership. The audit
checks the full retained extents and all original exception/constructor tables.
Frozen files are under `scratch/game_engine_handle_stream_continuation/`:
`final_integration.json`, `ownership_audit.json`, `final_splits.txt`,
`final_config.txt`, and strict `verify.py`. Production source SHA256 and recursive
quoted-header inventories (empty) are frozen. Final native DOL hash, regression
checks and weak-symbol absence remain the central integrator's acceptance step.
