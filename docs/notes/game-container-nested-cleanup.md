# Container nested allocation cleanup at 80052AA4

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated genuine C++ destructor recovers 1,260 original code bytes and all 164 original exception metadata bytes. It walks eight 148-byte groups, each holding counted 32-byte records with three owned allocation pointers, releases those allocations and group storage through the original allocator, then restores observed position and rotation defaults. Automatic member/base destruction handles seven inline two-layer handles, two fixed handle arrays, two dynamic three-layer handle pools, observed lower handles and the native owner base.

The private view models observed offsets only. Opaque ranges preserve unobserved fields. Its base prefix ends at +60, avoiding speculative trailing constructor flags from separate views. Actual native member cleanup, signed loop counts, allocator capacity sizes, pointer reloads and repeated pointer clears are retained. Scalar copy assignment expresses the original serial float load/store order.

The deletion implementation matters for owned metadata: all five body releases use the same inline global `operator delete throw()`, while deleting the container uses its inherited class operator. This naturally deduplicates the shared exception specification record exactly as the original 152-byte exception table at 80009D84; its index occupies 12 bytes at 80017F4C. Three separate class deletion methods produced identical body semantics with larger exception metadata and remain preserved private probes. No exception bytes are authored manually.

Production source is `src/Game/container_nested_cleanup.cpp`. Run `python3 scratch/game_container_nested_cleanup/verify.py`; the frozen manifest records complete function/object extents, source hashes, owned sections and all 65 actual relocations. No other allocated helper, literal, BSS, padding, vtable or allocator storage is emitted or credited. The destructor preserves the previously established native Agent_80052520 identity at 80052AA4. Its initial private Container_80052AA4 spelling is preserved in scratch history; no central symbol rename is required. No alias, thunk, object patch, assembly or mismatch mask is used. Central production and original executable acceptance remain required.
