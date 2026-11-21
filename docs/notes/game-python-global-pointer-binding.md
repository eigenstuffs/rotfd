# Python global pointer binding

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The `800CDC54` wrapper accepts an empty Python argument tuple and encodes the
current engine singleton pointer from `80377548`, using type-table entry `5C`.
All 248 code bytes and twenty exception/index bytes match with actual
relocations and complete original table ownership. No additional allocation is
emitted.

An ordinary volatile read of the mutable global pointer reproduces the original
single memory read before the null check, keeping that value separate from the
hexadecimal loop's copy. The wrapper then uses the same unchanged encoding
routine as the indexed/member bindings. Both null checks, Python None reference
increment, string operations and exact original instruction order are retained.
The global declaration is private to this unit; shared headers stay unchanged.

The nonvolatile near-match and bounded qualifier/order probes remain preserved
under `scratch/game_python_global_pointer_binding/`, alongside the frozen
production source, object, manifest and ownership proof. No object bytes,
relocation operands or original executable data were edited.
