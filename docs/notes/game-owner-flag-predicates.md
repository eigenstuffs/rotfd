# Owner flag predicates

`src/Game/owner_flag_predicates.cpp` reconstructs three functions through compiler-managed virtual getters:

- `fn_800670B4`, `800670B4..80067130` (124 bytes), resolves the handle returned by the getter at table offset `28`, reads the word at `3D8`, and returns its low 16 bits.
- `fn_8006727C`, `8006727C..8006734C` (208 bytes), tests mask `8000000000` in the resolved owner's 64-bit flags at `30`. An unset flag accepts signed-byte input one; a set flag accepts input zero. The result is a signed byte.
- `fn_80067754`, `80067754..80067808` (180 bytes), obtains the resource through table offset `14`, resolves its handle at `58`, and tests bit `10000` in the word at `120`. Its signed-byte input and return follow the same zero/one predicate.

The local query type view has a four-byte prefix and compiler-managed virtual pointer. Uncalled declarations establish the observed slots without emitting or owning the original table. All generation-tagged handle resolution uses the context manager at `lbl_801E9D24+118`.

Standard GC/1.3.2 with `-Cpp_exceptions on` emits exactly 512 bytes of `.text`, 24 bytes of `extab`, and 36 bytes of `extabindex`. Exception allocations are `8000BBC0..8000BBC8`, `8000BBC8..8000BBD0`, and `8000BC0C..8000BC14`; their index entries are `80018B28..80018B34`, `80018B34..80018B40`, and `80018B58..80018B64`. Intervening original bytes remain unclaimed.

`python3 scratch/game_owner_flag_predicates/verify.py` verifies all 572 allocated bytes across the nine original ranges, the complete function/local-object extents and actual symbol identities, six text and six EH-index relocations, and three nonallocated metadata relocations. No weak functions, literals, BSS, padding, or headers are emitted. The complete original extabindex (`80015F60..8001F2C0`), ctors (`80299920..80299980`), and dtors (`80299980..802999A0`) are audited; all three EH owners are reconstructed and no ctors/dtors ownership is omitted. The original DOL SHA1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`. Central whole-DOL acceptance is pending.
