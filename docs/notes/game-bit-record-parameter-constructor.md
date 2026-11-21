# Parameterized bit record constructor

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/bit_record_parameter_constructor.cpp` reconstructs the genuine C++
constructor originally labeled `fn_80225F74`, at `0x80225F74..0x80226134`
(448 bytes). Its emitted name is recorded exactly in the candidate manifest.
The production source uses the frozen declarations in
`include/Game/bit_record_native_lifetime.h` without changing them.

The 0xA8-byte record has the same established layout as the recovered copy
and default constructors. The constructor initializes its layered handles,
clears state `0x50`, and calls `fn_80209F80`. It assigns the fourth incoming
handle to `0x40` and the first three incoming handles to `0x44`, `0x48`, and
`0x4C`, using release/copy/retain operations. It then copies the input point
to `0x00`, stores two float arguments at `0x18` and `0x24`, stores the 64-bit
argument at `0x38`, and writes external scalar `lbl_8037B130` at `0x28`.
The 64-bit token occupies r9/r10; the float arguments independently occupy
f1/f2. Genuine member construction reproduces the native handle aliases and
constructor return value with ordinary C++.

`python3 scratch/game_bit_record_parameter_constructor/verify.py` recompiles
with standard GC 1.3.2 flags, checks the frozen header hash, and verifies all
448 retained bytes after processing all 16 actual relocations. The only
allocated section is 800 bytes of text: the constructor plus four unused
weak destructor backups totaling 352 bytes. Their bytes and eight relocations
are inventoried and must be absent from the final ELF. No retained relocation
references those helpers. Searches found no existing source/header callers
of the old function label, so no shared caller migration is proposed.

Complete original extabindex, constructor, and destructor table audits show
no ownership in the retained range. There is no owned data, BSS, or padding.
This partial text split does not recover the containing original translation
unit. Central integration and final DOL hash acceptance are parent-owned.
