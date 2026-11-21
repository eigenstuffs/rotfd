# Early scalar flag and fixed-record search

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

This isolated continuation recovers two ordinary C-entry functions. The parent
integrator retains responsibility for promotion and the original full DOL hash.
All earlier frozen sources and verifier cores remain unchanged.

| Function | Original text | Result |
| --- | --- | --- |
| `fn_80081210` | `80081210..80081270` (96 bytes) | Complete isolated match |
| `fn_800B3FC8` | `800B3FC8..800B409C` (212 bytes) | Complete isolated match |

The production sources are `src/Game/engine_scalar_last_80081210.cpp` and
`src/Game/engine_scalar_last_800B3FC8.cpp`. GC 1.3.2 uses the established
`-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` profile, with the full
flags frozen in `scratch/game_engine_scalar_last_continuation/final_integration.json`.
Both ELF objects contain only their original `.text` extent; no helper functions,
literals, exception metadata, initialized data or BSS are emitted. Strict
verification resolves all six actual relocations and compares every byte.

## Observed layouts and behavior

`80081210` reads a child pointer at owner offset 8, then its handle at child
`+0x24`. The handle contains signed generation and index fields of 8 and 24 bits.
The context at `lbl_801E9D24` supplies the manager at `+0x118`; its entries pointer
is at `+8`. Entries have stride 16, an object pointer at 0 and signed generation
byte at `+0xC`. A matching generation yields the object; a mismatch yields null,
following the original's unchecked subsequent access. The function sets
`0x20000` in the established 64-bit flags field at object `+0x38`. Treating only
its low word at `+0x3C` as a separate 32-bit field shortened the code by four
bytes and changed the logical-OR form. The complete 64-bit field produces all
96 original bytes exactly, consistent with the accepted nearby clear routines
`scalar_early_more_800810B0.c` and `scalar_early_more_800812E8.c`.

`800B3FC8` searches the unchanged external BSS array `lbl_802F4208`, 300 records
of size `0x50` (`0x5DC0` total). A record has an integer key at `+4` and a signed
byte at `+0x4C`; other bytes remain opaque. The owner has a key at `+0x188` and
six result indices at `+0x18C`. It clears all results to -1, finds the first
matching key with byte value 1, then searches successively after the previous
result for each remaining result slot. The source preserves the original
behavior when a preceding result remains -1. Initializing the first search index
before the clear loop reproduces the original register lifetimes. Signed-byte
comparison emits the original `cmpwi` without adding a sign-extension instruction.
A private unsigned-byte view with explicit signed-int promotion also matches,
but the production declaration uses the simpler observed signed comparison.

## Ownership and identity audit

`ownership_audit.json` scans the full original extabindex table
`80015F60..8001F2C0` with stride 12, ctors `80299920..80299980`, and dtors
`80299980..802999A0` with stride 4. Neither function owns a record in those
tables. Both original assembly function extents were independently checked.

The original member-pointer table at `lbl_802B8490` (`802B8490..802B84A8`) contains
`fn_80081210` at `802B849C`; that table stays in its original assembly owner and
its C-entry identity is unchanged. No existing source/header consumers of either
entry were found. The context and record array keep their current external
identities and original ownership. No shared metadata or headers were changed.

## Excluded startup research

`800AE2B8` remains uncredited, with all probes preserved separately in the same
scratch directory. Its original 128-byte startup body owns the constructor
pointer `80299934..80299938` and fills two external 12-float arrays,
`lbl_802F41A8` and `lbl_802F41D8`. The values describe three four-component color
records in each array, not a new invented padding object.

Using ordinary float literals reproduces all native instruction forms and FPR
assignments, but emits a 20-byte literal pool `[1, 0.64705884, 0.49019608, 0,
0.25098041]`. The original uses zero at `803790A8`, while its other four values
are contiguous at `80379150..80379160`. Replacing zero with the established
external constant emits those 16 pool bytes exactly but changes 26 code words.
All-external constants preserve the 128-byte extent and original constructor
entry but change FPR allocation. Bounded local declaration permutations and
ordinary inline color/record initialization helpers did not close it. No data
remapping, relocation masking or startup source is proposed for acceptance.

## Frozen handoff

`final_integration.json`, `final_splits.txt`, `final_config.txt`,
`allocated_inventory.json`, `ownership_audit.json`, and `verify.py` describe the
308-byte pair. `handoff.json` pins production sources, this note, and the complete
scratch evidence. The fresh recheck runs strict object verification with complete
allocated-section and symbol inventories and real external relocations.
