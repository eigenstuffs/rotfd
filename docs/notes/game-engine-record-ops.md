# Engine queue operations

Accepted production integration passes the original full-DOL SHA-1,
`ninja changes` with no regressions, source-extent/progress audits and all
26 unit tests. The final canonical manifest is `config/GSQE78/candidates/game-engine-record-ops.json`.

This batch reconstructs **six complete original functions, 960 text bytes,
and zero data bytes** in four partial source fragments. The canonical handoff is
`scratch/engine_record_ops_20261010/final_integration.json`, with
`final_splits.txt`, `final_config.txt`, and `ownership_audit.json` alongside it.
All production source and scratch names were checked absent before creation.

| Source fragment | Complete original functions | Text extent | Bytes |
| --- | --- | --- | ---: |
| `engine_record_ops_80230B78.cpp` | `fn_80230B78` | `80230B78..80230C18` | 160 |
| `engine_record_ops_80230CE8.cpp` | `fn_80230CE8`, `fn_80230D4C` | `80230CE8..80230DF8` | 272 |
| `engine_record_ops_802311F4.cpp` | `fn_802311F4`, `fn_8023127C` | `802311F4..80231330` | 316 |
| `engine_record_ops_8023152C.cpp` | `fn_8023152C` | `8023152C..80231600` | 212 |

## Recovered behavior

The queues store eight handles and eight corresponding scalar values. The
grouped version stores four independent eight-entry groups, with a count,
cursor, completion byte, and dirty byte per group.

The append functions call original `fn_801F7914` to copy the supplied handle,
write the parallel scalar value using the current count, and increment that
count. Both retain the original count reads after the external call.

The reset-and-append functions call the original virtual slots in order, then
advance the cursor. The single queue calls slot `20` with two zero arguments;
the grouped queue calls slot `3C` with the group and zero. Both then call slots
`34` and `2C`, preserving their original arguments.

The advance functions mark the queue complete when its cursor reaches its
count. If complete, they return zero. Otherwise they call virtual slot `2C` for
the current handle, advance the cursor, clear its dirty byte, and return one.

`include/Game/engine_record_ops_queue.h` declares only the observed storage and
virtual method prefixes. No constructors, destructors, virtual implementations,
or virtual tables are defined. Ordinary C function-pointer probes had correct
semantics but chose different table-load registers and call scheduling. The C++
virtual declarations reproduce the native virtual dispatch sequences exactly.

## Verification and integration

`python3 scratch/engine_record_ops_20261010/verify.py` recompiles all four
production files with GC/1.3.2 and checks all allocated sections, six function
bindings, offsets and sizes, and both real REL24 relocations to `fn_801F7914`.
Every resolved byte matches the normalized original DOL; no relocation bits are
masked. There are no allocated compiler helpers, tables, exception sections, or
unexpected data sections. The header also checks the observed prefix sizes.
Only physically adjacent functions with identical flags are grouped.

The standard GC/1.3.2 flags recorded in the manifest suffice. The isolated
compiler additionally receives `-i include`; the normal project include path
already supplies it. No extra object flags are needed. Set all six existing
`fn_...` symbols to global scope, register the four objects as `NonMatching`,
and carve only the four listed `.text` ranges from their original fallback
owners. The usual promotion, full DOL hash, and regression checks remain the
integrator's acceptance gate.

## Original ownership and excluded probes

`audit.py` checks each complete original `.fn` / `.endfn` extent, its current
fallback owner, all **3,141 twelve-byte original extabindex records**, and the
complete original `.ctors` and `.dtors` sections. None references these six
functions. The sources emit and own no exception or startup records. Original
virtual-table references to these entry points retain their existing data
owners, and neighboring text stays outside the new fragments.

The time-based record search at `8020EADC` remains five instruction words from
matching; the handle-chain lookup at `8023A5DC` remains fifteen words away.
The nested search at `8024A800` also remains private. Their ordinary source,
compiler probes, original disassembly, and comparisons are preserved in scratch.
None receives matching-source credit.
