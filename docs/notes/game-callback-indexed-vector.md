# Indexed vector callback

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ordinary C++ source for `fn_80256674` reproduces all 360 original text bytes at `80256674..802567DC`, including each actual relocation. The callback resolves the owner handle, looks up the indexed mapping, resolves the nested target handle, and copies three input vector components to the target. An inline body called by the external entry preserves the original manager and mapped-index register allocation. Earlier private variants and their register differences remain preserved under `scratch/game_callback_indexed_vector/`.

Source: `src/Game/callback_indexed_vector.cpp`. The unit owns only this complete function; no initialized data, BSS, padding, or extra emitted helpers. It uses the standard GC/1.3.2 Game flags. The isolated verifier applies actual relocation addresses and checks the full extent and all allocated bytes. Central integration also audits the complete original exception, constructor, and destructor tables. Full-build acceptance remains pending.
