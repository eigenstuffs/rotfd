# Indexed context handle getter

`fn_80235C08` returns the address of the handle at offset `0x10` in a
`0x4C`-byte context record. The signed record index is read from the owner
at offset `0x20`; the array pointer is borrowed from the existing GLOBAL
context at `lbl_801E9D24 + 0x114`.

The ordinary C++ array/member expression reproduces all 32 original text
bytes and both HA/LO relocations on the first body probe. The sole allocated
section is 32 bytes of `.text`; no helper, data, exception metadata, startup,
or alias is emitted. One nonallocated `.mwcats.text` compiler category
relocation is explicitly verified using the unchanged strict verifier.

The current native identity, complete canonical ownership, balanced direct
source-body census, and semantic/probe-alias references are checked before
source reconstruction. The containing assembly unit was omitted by the old
individual-file research census; the corrected all-unit census includes it.
Full original exception index, constructor, and destructor tables have no
references to this function. Its existing original/accepted callers and any
stored pointers are inventoried in the complete consumer census.

This is an isolated source match pending independent review and full-game
native acceptance. Original functions and data outside the declared text
split retain their existing owners. The producer note is permanently frozen
with the handoff; later acceptance is recorded separately.
