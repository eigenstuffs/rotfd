# Container member destruction at 8002E014

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated genuine C++ destructor recovers 740 original code bytes and all 52 compiler-generated exception metadata bytes. The production source is `src/Game/container_member_destruction.cpp`.

Its minimum destruction view uses the observed object vptr at +8, pool at +48, two inline handle layers at +58 and the derived handle at +60. The base prefix is therefore 0x60 bytes in this private view; it does not reuse speculative trailing flags from the separate container constructor view. Opaque fields retain only observed member offsets. Eight four-layer handles occupy +6C/+70/+74/+7C/+80/+84/+88/+90, and five-layer handles occupy +78/+8C. Ordinary automatic member/base destruction produces every original member-address guard, loop, capacity release and native owner destructor call. The first probe omitted one inline handle wrapper; the preserved corrected layer model matches all bytes and all 26 actual relocations.

The destructor body restores the original external vtable. The pool destroys each element, frees capacity through the original allocator and clears the pointer. The inherited `operator delete throw()` naturally generates the original unexpected path, 40-byte exception record at 80006F04 and 12-byte index at 80016B78. The original vtables and allocator storage remain external and uncredited. The compiler emits no additional allocated helpers, literals, padding or BSS. The class name is address-qualified; the complete original type and translation-unit boundaries are not established.

Run `python3 scratch/game_container_member_destruction/verify.py`. Frozen production source hashes, exact function/object extents, real relocation targets and owned sections are recorded in `scratch/game_container_member_destruction/final_integration.json`. The provisional `dtor_8002E014` name has no compiled source/header callers and can be replaced by its genuine native C++ name at the same address. No alias, thunk, object patch, assembly or mismatch mask is used. Central production and full executable acceptance remain required.
