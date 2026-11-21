# Callback handle transfers

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Five complete ordinary C++ functions reconstruct 1,116 text bytes.

| Entry | Bytes | Observed operation |
| --- | ---: | --- |
| `80257D20` | 228 | Conditionally update the target through owner handle `0x64`, then apply owner handle `0x58`. |
| `80258F60` | 168 | Check the original base status, look up owner handle `0x80`, and invoke target virtual slot `0x1C`. |
| `80259164` | 244 | Call the original state helper, clear flag `0x8000`, invoke target slot `0x34`, then deactivate the newly resolved target. |
| `80259FB4` | 240 | Apply the incoming target with handle `0x58`, run the original transfer, and conditionally apply handle `0x70`. |
| `8025A0A4` | 236 | Call the original transfer, then conditionally apply handle `0x70` in mode 4 and handle `0x58`. |

The frozen related-object interface supplies the signed generation/index
lookup and declaration-only virtual target. The new owner prefix records
observed handles at `0x58`, `0x64`, `0x70`, and `0x80`; it does not claim a
complete original class. Registry resolution is repeated at each native use,
including after calls that may change the registry. No stale resolved pointer
is substituted for those repeated lookups.

`scratch/game_callback_remaining_adapters/verify.py` recompiles the five
frozen production sources and checks all allocated bytes, exact global
function extents and actual versioned relocations without masking. The
objects contain no extra functions, helpers, data, exception records, or
padding. Shared declarations remain unchanged. Central acceptance also
checks all original exception/startup ownership, the full executable hash,
source extents, baseline changes, progress exports and the test suite.
