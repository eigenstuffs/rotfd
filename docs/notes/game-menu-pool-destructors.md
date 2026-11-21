# Menu record-pool lifetime

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The partial source split reconstructs `800B4F28..800B5068` (320 bytes) and
`800B5254..800B53A4` (336 bytes) as ordinary C++ destructors. Their first typed
probes match the complete code and each original 40-byte exception table and
12-byte exception index after all actual relocations. Central acceptance is
required before source credit.

Both destruction views extend the external native `MenuBase_8021D7E4` prefix,
whose primary table pointer is at `08` and whose minimum extent is `4C`. The
pool layer contains two inline Handle layers at `4C` and `74`, an opaque span
`50..68`, and a dynamic record pool at `68`. Each record is `C4` bytes, with an
opaque `C0`-byte prefix and a two-layer Handle suffix. Ordinary member and
record destruction supplies every observed null check and forward traversal.
The pool frees `capacity * sizeof(Record)` bytes and clears the storage pointer
twice in the original order.

The second routine adds an empty derived layer and its own table transition,
then inlines the same pool layer cleanup. Native class deletion with an empty
exception specification generates the original handler and metadata. Existing
vtable data and the external MenuBase destructor stay outside these splits.
These are private minimum destruction views, not claims that every opaque byte
or neighboring class method has been reconstructed.

Every allocated symbol and section is exact; no unused output, padding, raw
instruction data, or aliases are used. Full original exception-index and
constructor/destructor-table scans prove exactly the two owned exception
entries and no startup references. Both provisional names have no compiled
callers, allowing guarded native-name migration. Frozen source hashes, compiler
flags, relocation records and metadata audits are in
`scratch/game_menu_pool_lifetime/final_integration.json`.
