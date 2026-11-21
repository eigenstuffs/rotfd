# Callback unique-value list

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80255B78` reconstructs the complete 264-byte function at
`0x80255B78..0x80255C80`. It skips an already present signed 32-bit value,
grows capacity by four when required, and appends through the original
conditional destination check. Existing data is resized, missing data is
allocated, and a zero resulting capacity takes the original free path.

The partial owner exposes count at `0x48`, capacity at `0x4C`, and the
four-byte-element array at `0x50`. Allocation sizes and count increment
retain the original arithmetic. The native signed comparison is preserved.
No extra function, data, helper, exception record or padding is emitted.

`scratch/game_callback_value_list/verify.py` recompiles the frozen source
and checks every allocated byte, exact complete extent and actual relocations
without masks. Original allocator objects, neighboring methods and other
class fields remain external. Central integration audits complete original
exception/startup ownership and requires the original executable hash,
baseline/source-extent checks, progress exports and tests.
