# Animation event application and channel closure

The source unit `src/Game/animation_event_pair_80233450.cpp` reconstructs two complete functions:

| Function | Range | Code bytes |
| --- | --- | ---: |
| Close a channel and emit its remaining events |80233450..80233944|1268|
| Advance cursors and apply emitted events |80233944..802340F4|1968|

This partial unit does not claim the neighboring original 8023297C function or the separately accepted cursor reset at 802340F4. Its inferred layout views are checked at compile time: four-byte handles, 16-byte manager entries, 44-byte event records, 0x74-byte states, 0x50/0x8C/0x1C-byte track records and 8/16/2-byte cursors.

## Behavior

Closing a channel samples remaining action-curve events up to its duration. Both routines attach the four active animation states and target/actor/owner context, apply visibility and flag commands, convert packed color channels, and dispatch resource events with native handle retain/release lifetimes. The interval routine also advances color and scalar cursors. The original dispatcher vtable is borrowed at offset 0x7C; no new vtable data is claimed.

The reconstructed handle and array APIs retain the observed lifetimes. A value getter for the event array and a constant actor pointer recover the closing routine's register allocation. The interval routine uses typed manager indexing and the original event/actor handle lifetimes. All code is ordinary C++ compiled with GC/1.3.2 and the flags recorded in the canonical candidate.

## Shared constants

The new source owns 16 bytes at 8037B1E8..8037B1F8:

- GLOBAL `lbl_8037B1E8`, the float volume 1, retains its address and external consumers.
- LOCAL `@232`, the native RGB reciprocal at 8037B1EC.
- LOCAL `@234`, the native signed conversion bias at 8037B1F0.

An inline constant-reference volume getter appears before its definition, preserving GLOBAL loads while allowing the other two literals to be emitted naturally. The old scalar source retains its six GLOBAL floats at 8037B1D0..8037B1E8. Both emitted boundaries align to eight bytes. All 40 original scalar bytes remain source-owned; this migration adds no data credit and leaves no padding gap.

## Evidence and acceptance

The frozen private package is `scratch/animation_event_pair_80233450_20261020_parallel/HANDOFF.md`. It records source/object hashes, all original and compiled symbolic relocations, the native unused-helper link, and a complete before-integration census of 6,875 active inputs. Both EC loads and all four F0 loads occur only in these two functions. E8's outside consumers retain the same GLOBAL definition.

The source object contains 3,236 retained text bytes plus 172 bytes of unused WEAK handle destructors. Every emitted byte is accounted for: 73 retained relocations, four helper relocations and four nonallocated compiler metadata relocations. All 20 undefined symbols have GLOBAL binding. The native linker discards both complete helpers, whose sizes and hashes are preserved in the canonical manifest.

Root integration evidence is in `scratch/animation_events_integration_20261020`. Production objects are compared with the immutable private objects before promotion. The two canonical records are `game_animation_event_pair_80233450.json` and `game_animation_cursor_scalar_constants.json`. Earlier 28-byte and 40-byte scalar receipts remain intact and are referenced as historical evidence.

Acceptance: the production DOL retains SHA1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`; `ninja changes` is empty; the extent audit passes 5,769 source units and 6,743 data/BSS sections; all 66 tests pass. Overall source coverage is 1,931,124 / 2,607,776 code bytes (74.0525%), 7,982 / 8,803 functions and 971,656 / 1,030,936 data bytes (94.2499%). Function, code and data denominators are unchanged.
