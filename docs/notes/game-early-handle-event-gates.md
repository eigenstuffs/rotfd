# Handle event gates: 80045D28

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ordinary C++ strictly matches all 524 original code bytes, the 48-byte exception record and 12-byte index of `fn_80045D28`, including all 16 retained actual relocations. Two fully inventoried weak backup destructors emit 228 uncredited code bytes and 104 uncredited metadata bytes with 14 relocations. Actual native MW linking selects the existing accepted strong Handle destructor and discards all six backup text/exception/index allocations; a wrong fixture basename is rejected. Complete original placement and the DOL hash remain integration requirements.

The routine handles events 0x8A and 0x8B through the unchanged event query. Each matching branch constructs a retained copy of its Handle at +0x28, resolves its node, and tests the node's 64-bit flags at +0x38 against mask 0x20000000. If that mask is clear, it calls virtual slot +0x84, then calls slot +0x7C. The first matching event excludes the second. The temporary is destroyed before either virtual call, with native base cleanup argument zero.

The real inline zeroing base `Handle_80020478` and derived copy constructor preserve the original constructor exception lifetime. Both retained exception relocations target the accepted original strong `__dt__15Handle_80020478Fv` at 80020478, whose 112-byte body and complete metadata are independently recompiled and compared with its current production object and canonical source/header hashes. The separate private copy destructor is unused. Every backup allocation has its binding, type, offset, size, raw hash and actual relocations recorded. The standard unchanged strong-owner/weak-output schema is sufficient; no new gate or native identity migration is required.

The eligibility helper's actual `bool` result is essential: an unsigned-byte return gave the same 524-byte extent but 26 instruction differences through truncation and register allocation. A bool return reproduces every original instruction, including the saved boolean across temporary destruction. Alternative unsigned-byte, signed-byte, integer and explicit 64-bit accessor diagnostics remain preserved without credit.

| Section | Original range | Bytes |
| --- | --- | ---: |
| `.text` | 80045D28..80045F34 | 524 |
| `extab` | 80008DF8..80008E28 | 48 |
| `extabindex` | 800178B0..800178BC | 12 |

The private owner view establishes storage through +0x2B and an eight-byte nonvirtual prefix with a vtable pointer at +0x08; the flag-node view establishes storage through +0x3F. Complete original index/startup scans find exactly the owned index and no startup entries. The initialized-pointer audit also records the unchanged callable pointer at 802B4A74 in the original 156-byte `lbl_802B49EC` pool, with complete symbol extent/raw hash. The pool, all globals, native dependencies and existing source/header consumers remain unchanged.

Frozen evidence is under `scratch/game_early_handle_event_gates_continuation`. `verify.py NEW_DIRECTORY` recompiles the production source and independent accepted strong owner; `native.py NEW_DIRECTORY` repeats actual strong selection and complete backup discard. Established GC 1.3.2 space optimization flags enable exceptions and lmw/stmw. No credited bytes extend beyond the retained original extent.
