# Owner handle validity helper

The isolated ordinary C++ definition of `fn_8023C2AC` matches all 48 bytes at 8023C2AC..8023C2DC and its sole actual REL24 relocation to the existing `fn_801F7EB8`. It converts that helper’s nonzero result to a signed-byte Boolean. The dedicated handle declaration is a four-byte partial view; no complete owner or handle class layout is claimed.

GC1.3.2 uses `-O4,p`, `-proc gekko`, exceptions/RTTI off, and `-use_lmw_stmw on`. The entire allocated object is one 48-byte `.text` section, alignment 4, with the original global C function identity. There is no emitted data, literal, weak backup, BSS, exception table, constructor, destructor, padding, or additional function. The original complete exception-index, constructor and destructor tables contain no references to this extent.

The current canonical-section and native-symbol preflight found this body still assembly-owned. A complete active census covered 10,239 ELF inputs and 630 records referring to this entry or its borrowed validity helper. The full original initialized-data scan found no pointers to this function, and the full text scan found four external direct calls, all to its entry. Existing sources and declarations require no edits or identity migration.

This body was already expressed as a private inline helper in the preserved DV recursive-query research and was independently verified as a standalone leaf during the JY recursive-component investigation. Those recursive functions remain private and uncredited. JZ adds only this independently owned exact helper. All old research artifacts are unchanged.

The production source is `src/Game/engine_owner_handle_validity.cpp`, with declarations in `include/Game/engine_owner_handle_validity.h`. The complete frozen handoff is `scratch/engine_owner_handle_validity_20261011jz/final_integration.json`; `verify.py` freshly recompiles and verifies every allocated byte, symbol, real relocation, and original table extent. Central NonMatching registration, production linking, original DOL hash and regression acceptance are pending the integrator. This text-only split is not a claim to the original whole translation unit.
