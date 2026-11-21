> Superseded by the accepted [native record value constructor](game-engine-record-value-constructor.md).
> The single 64-bit argument matches all 232 native bytes. The following note
> preserves the earlier two-word approximation and its uncredited probes.

# Record constructor near-match

`src/Game/record_constructor.cpp` reconstructs native construction at
`0x80226134..0x8022621C` (232 bytes), using a private refinement of the accepted
`Record_80209EA0` layout. **The source is unregistered and receives zero
progress credit:** four instruction bytes still differ after every actual
relocation is applied. The original and verified build baseline are unchanged.

The constructor's incoming handle is a borrowed `const Handle_801F7F10&`.
It constructs the two-layer member at `+0x40` and the three-layer members at
`+0x44/+0x48/+0x4C`, zeroes `+0x50`, calls accepted reset `fn_80209F80`, then
assigns the borrowed handle to `+0x40` using release/copy/retain. It stores its
second word argument at `+0x3C`, followed by its first at `+0x38`. The word
arguments' domain meanings and signedness remain unestablished; `u32` preserves
the observed full-word ABI. The private view exposes these two fields inside
the accepted header's formerly opaque `+0x2C..+0x40` interval and preserves the
complete `0xA8` size. `record_pool_internal.h` was not modified.

The original caller at `0x8022F784` constructs a record on the stack at `+0x10`,
passes the existing handle temporary at stack `+8` by address, and supplies
zero in both word arguments. It passes the record to `fn_802257EC`, destroys
the record through accepted `__dt__15Record_80209EA0Fv` at `0x8022F7A4`, and
then releases the separate handle temporary. This supports the native record
identity and preserves caller ownership of the incoming handle. The candidate
adds no handle argument copy or argument destructor.

With GC/1.3.2 and the standard `-O4,p -inline auto` game flags, the native
constructor emits exactly 232 bytes. Only the two saved word-argument
registers differ:

| Instruction address | Original | Compiled |
| --- | --- | --- |
| `0x80226150` | `mr r30,r5` | `mr r29,r5` |
| `0x80226154` | `mr r29,r6` | `mr r30,r6` |
| `0x802261FC` | `stw r29,0x3C(r27)` | `stw r30,0x3C(r27)` |
| `0x80226204` | `stw r30,0x38(r27)` | `stw r29,0x38(r27)` |

The actual byte differences are at `0x80226151`, `0x80226155`, `0x802261FD`,
and `0x80226205`. The entire handle construction, reset, reference adjustment,
frame, and remaining parameter/return behavior is exact after relocation.

Bounded probes preserved in `scratch/game_record_constructor` tested store
order, signed word types, pointer views, setter/accessor and inline-body
boundaries, member initialization, a zero-word wrapper, implicit destructors,
const-reference setters, direct assignment, and the caller's one-layer handle
reference. They do not solve the parameter-register swap. GC/1.3 and GC/2.0
produce the same remaining differences; GC/1.2.5 changes the function shape.
`-O4,s` does not improve the match. Narrow argument types add conversion
instructions absent from the original. The production near-source retains the
simple borrowed-handle and full-word model; no compiler barriers, assembly,
artificial dependencies, or address substitutions are introduced.

`config/GSQE78/candidates/game_record_constructor.json` is marked
`nonmatching` and `do_not_integrate`, with its range under `proposed_splits`.
Its proposed native symbol is
`__ct__15Record_80209EA0FRC15Handle_801F7F10UlUl`; no central alias was changed.

Run:

```sh
python3 scratch/game_record_constructor/verify.py
```

The verifier intentionally exits with failure for the four unmatched bytes.
It first verifies the protected DOL SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`, source/header/object hashes,
physical function ordering, complete allocated-section/function coverage, and
**all nine retained ELF relocations**. It also accounts for three unreferenced
weak handle destructors (264 bytes and six relocations), excluded from the
retained comparison and any credit. Only `.text` is emitted; there is no owned
data, BSS, exception metadata, literal pool, or padding. Results are saved in
`verification.txt` and `strict_result.json` within the scratch directory.

This is a preserved near-match for a later source or type discriminator, not a
successful full-DOL integration. No global build or baseline command was run.
