# Engine record buffer operations

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

This handoff reconstructs seven complete ordinary C functions in two adjacent
text-only units:

| Source | Complete functions | Text range | Bytes |
| --- | --- | --- | ---: |
| `src/Game/engine_record_buffer_copy.c` | `fn_8024B5D8`, `fn_8024B744` | `8024B5D8..8024B76C` | 404 |
| `src/Game/engine_record_buffer_rows.c` | `fn_8024B76C`, `fn_8024B7F4`, `fn_8024B8E0`, `fn_8024BBB8`, `fn_8024BC7C` | `8024B76C..8024BCA4` | 1,336 |

Both use GC/1.3.2 and the standard Game flags with `-use_lmw_stmw on`. All seven
symbols require global scope. The units total 1,740 text bytes, zero data bytes,
and 76 real relocations. `include/Game/engine_record_buffers.h` is a dedicated
new header; no existing declarations or central metadata are edited.

All arrays have signed count and capacity at offsets 0 and 4 and an element
pointer at 8. The first unit copies arrays of 24-byte records: a key, packed
handle, and four floats. It clears the destination through `fn_8024B744`,
reserves through existing `fn_80025898`, and appends each source record. Appending
grows capacity by 32, preserves the placement-construction null guard, calls the
original handle constructor, clears its word, copies the source handle, and
increments the original manager counter. The source retains each of these
operations and copies each float separately. Its clear wrapper calls existing
`fn_80025954` with count zero and mode one.

The second unit operates on arrays of 12-byte word-array rows. Its copy routine
clears and reserves the outer array, then appends each row with
`fn_8024B7F4`. Append grows outer capacity by eight, calls the complete word-array
copy constructor `fn_8024B8E0`, and returns the new index. That constructor zeros
the row's count, capacity, and pointer, reserves space for the input word count,
then appends each four-byte word with growth by eight. Its generic resize path
retains the native empty counted loops for scalar element construction and
destruction. The reserve operation `fn_8024BBB8` calls existing `fn_801D3088`
with mode zero when the requested capacity is below the current count; otherwise
it allocates, reallocates, or frees and sets capacity. The final clear wrapper
calls that existing resize routine with count zero and mode one.

All memory operations use the original allocator object `lbl_8028F698` and
existing `fn_8028FAF4`, `fn_8028FF24`, and `fn_8028FD50`. The zero-capacity free
branches and post-allocation capacity reloads are preserved. The global manager
at context offset 0x118, allocator data, original callees, and neighboring text
and data retain their previous owners. This partial text split does not claim
an original complete translation unit.

`scratch/engine_record_fields_20261010j/final_integration.json` records both
units, all seven complete extents and symbol bindings, exact compiler flags, and
all actual relocations. `freeze.py` compiles production source and verifies each
byte; `verify.py` independently recompiles and checks all relocated text against
the protected DOL with no masking. It rejects unexpected allocated sections or
extra functions. The final strict verification and `audit.py` pass. Original
assembly bounds were checked, and the complete 3,141-entry original extabindex,
24-entry ctor, and 8-entry dtor tables contain no references into these extents.
Source data, BSS, startup, and exception ownership are zero. Central NonMatching
registration and original DOL/native regression acceptance are the integrator's
remaining promotion steps.

Earlier record-copy probes differed only in register allocation. Expressing the
append as an ordinary inline operation and passing the indexed source record
directly, rather than storing an additional row local, gives the exact native
allocation. The initial word-array constructor also differed because it set
capacity from a value computed before allocation. The original append increments
capacity after the allocator call; restoring that operation produces an exact
728-byte constructor. All probes and results are retained in the new scratch
directory; no older research artifacts were changed.
