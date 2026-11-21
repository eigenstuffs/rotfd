# Native world curve arrays

Four text-only units reconstruct the resize/destructor pairs for the 60-byte
and 76-byte records used by the world loader:

| Source | Address | Bytes |
| --- | --- | ---: |
| `world_curve_resize.cpp` | `0x801E3AC4` | 552 |
| `world_curve3c_destructor.cpp` | `0x801E3CEC` | 576 |
| `world_curve4c_resize.cpp` | `0x801E3F2C` | 580 |
| `world_curve4c_destructor.cpp` | `0x801E4170` | 736 |

Total: 2,444 code bytes and four functions. These are partial units; their
shared tables and other world/curve functions retain separate ownership.

## Native layout and behavior

`world_curve_arrays_internal.h` reconstructs a four-byte curve base, a
count/capacity/pointer key array, and a 16-byte curve containing both. The
60-byte record owns three curves: one with 20-byte keys and two with
16-byte keys. The 76-byte record owns four curves with 16-byte keys. Key
contents are still opaque; only their size and empty destructor behavior are
needed for these routines.

Both records inherit a prefix with a word, a signed short identifier, and an
uninitialized short. A single virtual reset hook places the table pointer at
offset eight. Construction installs the base/derived tables, clears the word,
sets the identifier to -1, calls the curve-base constructor for each curve,
and initializes each array's count, capacity and pointer to zero.

Growth and shrinkage preserve the verified world-array policy: construct new
elements in place, destroy removed elements in reverse order, and either
preserve capacity or resize storage according to the signed byte flag.
Equal-size requests do nothing. Destructors release owned curve arrays in
reverse member order and optionally free the record using the signed native
destructor flag. C++ member lifetime, empty key destructors and the target
compiler naturally reproduce the original empty destruction loops and checks.
No assembly bodies, object edits or instruction masks are used.

The previously matched base routines at `0x801B1088` and `0x801B1040` now
have their recovered native constructor/destructor symbol names. The only
change to existing source is those two identifiers in `curve_base.c`; their
84 compiled bytes remain exact. Address-based class names describe recovered
ABI relationships rather than claiming original identifiers.

## Tables and emitted helpers

The original strong tables at `0x802E9E08`, `0x802EA7D8`, and `0x802EA7E4`
remain original data. All three are 12 bytes and point to the same inherited
reset hook at `0x801B3A24`. The compiler emits a weak 12-byte derived table
in each new object. Those copies match the original bytes but are overridden
by the original strong definitions and earn no data credit.

The two resize objects additionally emit 872 and 436 bytes of unreferenced
weak curve/array destructors. Those helpers are absent from the final image
and receive no credit. The standalone record destructors emit no extra text.
Every allocated symbol and byte is accounted for; no trailing alignment, BSS
or initialized data is attributed to this addition.

## Acceptance

`python3 scratch/game_world_curve_arrays/verify.py --production` compiles all
four ordinary C++ objects, checks retained bytes with all 91 actual
relocations, verifies weak table contents, and accounts for excluded output.
`python3 scratch/game_world_curve_arrays/link_proof.py` verifies final function
addresses and bytes, original strong tables, preserved base routines, and
absence of discarded helpers.

The full DOL is byte-identical and all 640 source units match. All 23 tests,
progress validation, source extent checks and assembly audits pass. All 637
candidate source/object hashes and 98 recorded header hashes are current.
The original baseline is immutable; all pre-existing source except the two
native curve-base identifiers is unchanged. `ninja changes` retains its
previously documented fallback/native/padding accounting differences; the
checkpoint separately verifies that every previously linked source unit
retains its exact code and data match.

See `scratch/world_curve_arrays_checkpoint.json`,
`scratch/world_curve_arrays_link_proof.json`, and the corresponding build,
changes and test logs. The 80-byte record and its specialized final curve,
remaining array operations, and shared tables remain unfinished.
