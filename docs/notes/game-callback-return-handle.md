# Callback handle returned by value

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`fn_80257B70` reconstructs the complete 224-byte entry at
`0x80257B70..0x80257C50`. An invalid owner index produces a default typed
handle. Otherwise it retrieves a handle from the original record manager,
constructs a typed intermediate, destroys the raw result with native flag
-1, copies into the caller's result, and destroys the intermediate with
native flag 0. Registry retain calls and both default zero stores remain.

The raw record accessor returns an ordinary C++ handle by value. Its
nontrivial constructor gives the native hidden-output-pointer ABI. A trivial
one-word declaration incorrectly returns in a register; explicit local
output parameters reproduce the operations but swap the two temporary stack
slots. The final source uses actual C++ construction and destruction to
recover both the ABI and lifetime order, without assembly or forced storage.
The default constructor has an inline native implementation; it is not an
undefined helper used to influence code generation.

The observed fields and type layers are private partial views. They do not
establish complete class identities. The record manager, allocator and
neighboring functions retain their original external ownership.

The compiler emits four unused weak destructors totaling 348 bytes after
the exact 224-byte strong entry. The frozen manifest records their full
extents, bindings and raw SHA-256 values separately. Retained relocations do
not refer to them; they receive no progress credit and must be absent from
the linked executable. `scratch/game_callback_return_handle/verify.py`
recompiles all allocated bytes and checks actual relocations and extents
without masks. Central integration audits original exception/startup tables
and requires complete executable hash and regression acceptance.
