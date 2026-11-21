# Platform shutdown and field-free item deletion

`src/Game/platform_shutdown.cpp` reconstructs the complete 276-byte shutdown
routine at `801EA0FC..801EA210`. It releases the 900-entry cache, the ten-entry
cache, the polymorphic resource and the platform pool, clearing each global
pointer. It then blanks/flushed video, waits for retrace, finishes/aborts
pending graphics work, frees the arena allocation, and conditionally deletes
the final item. The ordering and both native/virtual destructor paths match
all original instructions with actual relocations.

`src/Game/platform_item_lifetime.cpp` reconstructs the 72-byte native destructor
at `802859A8..802859F0`. Its body performs no field cleanup; ordinary C++
deletion handles the null check, signed native deletion flag, arena release
and returned `this` pointer. The shared declaration establishes only this
interface. No object creation, instance size or unidentified fields are
claimed from this field-free destructor.

The shutdown routine verifies these offsets in the engine global state:

| Offset | Recovered role |
| --- | --- |
| `158` | Arena allocation |
| `178` | 900-entry cache |
| `17C` | Ten-entry cache |
| `180` | Polymorphic resource, destructor in vtable slot `08` |
| `184` | Platform pool with native destructor `80281EA4` |
| `18C` | Final item with native destructor `802859A8` |

The existing `Globals` declaration is extended through `+190`; its previous
prefix and all prior offsets are unchanged. Declaring these verified members
in that type reproduces the original compiler's overlapping global-address
register lifetimes. A separate cast view was eight bytes shorter and did not
match. Full recompilation checks the extended declaration against every
existing source user before refreshing header acceptance hashes.

`include/Game/platform_cache_internal.h` preserves the currently recovered
cache ABI, including the nonvirtual destructor and virtual binding operation.
Native destructor identities for both caches and the platform pool now replace
their original address labels; their bodies still come from original objects.
The cache lifetime probes remain uncredited with 32 instruction-register
differences in each 604-byte function. Their vtables point to binding methods,
not destructors. The larger pool destructor also remains original.

The two new units emit exactly **348 code bytes** and no allocated data,
BSS, metadata, padding or weak helpers. The strict verifier
`scratch/game_platform_shutdown/verify.py --production` checks every emitted
symbol/byte and applies **27 actual relocations**: 24 for shutdown and three
for item deletion. Compiler settings remain GC/1.3.2, Gekko hardware floating
point, `-O4,p -inline auto`, exceptions/RTTI disabled and
`-use_lmw_stmw on`. Class and field names are inferred from verified address
and behavior evidence; original source file names remain unknown.

Integration passes the byte-identical DOL and native objdiff checks. All
671 source units remain exact after recompiling the extended global header;
59 manifest header hashes were refreshed only after that proof. All 23
unit tests, progress exports and source extent/assembly audits pass. The
saved original baseline is unchanged. Evidence is recorded in
`scratch/platform_shutdown_checkpoint.json`.
