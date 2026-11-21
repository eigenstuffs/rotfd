# Fixed-capacity engine sphere records

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three ordinary C++ functions are recovered as partial text-only splits:

| Function | Extent | Behavior |
| --- | --- | --- |
| `fn_801BA988` | `0x801BA988..0x801BAA54` (204 bytes) | Append sphere metadata to eight fixed slots |
| `fn_801BB960` | `0x801BB960..0x801BBAF4` (404 bytes) | Transform a sphere and append it to eight fixed slots |
| `fn_801BC2B4` | `0x801BC2B4..0x801BC408` (340 bytes) | Update selected records, then reset two fixed arrays |

Strict production recompilation verifies all 948 retained text bytes and 21
actual relocations. Every emitted allocation is accounted for. There are no
helper functions, weak cleanup functions, data, BSS, exception records or
constructor references. Original external names remain unchanged.

The append routines check the signed enabled byte at owner `+0x18`. Their
24-byte slots contain a sphere (three float position components and a float
radius) followed by two float metadata fields. The first routine stores slots
at `+0x850` with a count at `+0x910`; the second stores slots at `+0x96C` with
a count at `+0xA2C`. When the count reaches eight, the final slot is reconstructed
and reused. Otherwise the count increments and the next slot is constructed.
The default sphere copies the first three floats of `game_vec4_zero` and a
versioned radius constant. Explicit scalar vector copy construction reproduces
the original float loads and stores.

The transformed append obtains the object at owner `+0xB94` and refreshes its
cached matrix using the same dirty-flag/cache layout established by the result
builder in `game-engine-transform-build.md`. It then uses the nontrivial C++
sphere return from `fn_80099A00` directly in assignment to the destination
sphere. This preserves the original hidden result-pointer ABI and avoids
constructing an extra default sphere. Naming the return object before assigning
it changes the load/store scheduling.

The reset routine visits pointers at `+0x24 + i*0x94` while `i` is below the
count at `+0x968`. For objects whose `+0x120` flags contain `0x2000`, it calls
`fn_801BBDC8(self,i,delta)`. It then calls `fn_8024C338` on owner `+0xB98`.
The array count at `+0xB90` and sphere-record count at `+0xA2C` are resized to
zero, preserving the original signed growth/shrink paths and compiler-emitted
empty loops. The sphere array uses raw byte storage, as in the independently
accepted destructor at `0x801BB7CC`. The private first-record view describes
only the observed pointer offset and stride; its separate count at `+0x964`
is not read or changed here.

Compiler: CodeWarrior GC/1.3.2 with standard game flags. `fn_801BC2B4` adds
`-opt nostrength`, which preserves the original byte-offset traversal and
placement-construction loop. The append routines use standard flags. All
private type names carry their entry-point address to avoid accidental ODR
linkage across independently reconstructed fragments.

The original fragments own additional functions outside these ranges. They
retain original ownership. `ownership_audit.json` records the full original
fragment ranges, zero original data sizes, complete retained function extents,
and exhaustive exception/constructor scans.

Frozen integration files are under
`scratch/game_engine_fixed_records_continuation/`: `final_integration.json`,
`final_splits.txt`, `final_config.txt`, and `ownership_audit.json`. The manifest
includes raw production source SHA256 and recursive quoted-header hashes (none
are included). `verify.py` recompiles every production source and compares all
retained bytes with applied real relocations. Central integration and the full
DOL hash remain the integrator's job.
