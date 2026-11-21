# Callback record defaults

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_8025B928` reconstructs the complete 428-byte function at
`0x8025B928..0x8025BAD4`. Its second argument is the record to initialize.
It assigns scalar defaults, copies the original zero vector into two pairs
of vector members, sets the index at `0x48` to minus one, and assigns a
zero-initialized retained handle to both `0x90` and `0x8C`. A final group of
scalar assignments supplies the callback-specific defaults.

Ordinary chained scalar assignments reproduce the native store order.
The handle assignment releases the destination, copies the source word,
retains the source, and returns the destination reference for the second
assignment. Three zero-initializing handle layers reproduce the observed
construction before both assignments, and normal temporary destruction
occurs after the complete expression. All scalar constants, the zero
vector, and neighboring functions retain their original ownership.

`scratch/game_callback_record_defaults/verify.py` checks the exact function
extent, every retained allocated byte, and actual relocations without
masks. Four trailing unused weak destructors occupy 360 bytes and are
inventoried separately by name, offset, extent, binding, raw hash and
relocations. They receive no matching credit and must be absent from the
final executable. Full executable acceptance is required before credit.
