# Frame gate

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_frame_gate.cpp` reconstructs the complete ordinary C++ extent `8020C0F8..8020C248` (336 text bytes). It reports a startup message, calls the retained setup entry, selects a command from the original flag, and clears that flag. It then waits on a volatile byte, resolves two generation-checked handles, calls virtual slot `38` when both objects exist, and runs the retained tick entry until the completion query succeeds. The retained exit entry is called before returning one.

`include/Game/engine_frame_gate.h` records the observed context offsets: console `110`, manager `118`, root `124`; root handle `18`; object target handle `48`; manager entry storage `08`; and entry generation `0C` within each 16-byte entry. The eight-byte storage base places the native virtual table pointer at object offset `08`. Slot names are offsets, not inferred semantic API names.

Frozen evidence is in `scratch/engine_frame_gate_20261010ao/`. GC/1.3.2 uses the standard Game flags plus `-opt nocse`. Explicit context/message pointers and a manager cached per iteration reproduce the original lifetimes while disabling common-subexpression elimination retains the repeated entry-storage load. Declaring the message pointer before the context pointer reproduces native allocation. The actual virtual declaration emits the original register-12 virtual call sequence.

`freeze.py` and `verify.py` compile current production source, verify its single global function and complete extent, reject additional functions or allocated sections, apply all 17 real REL24/HA/LO/SDA21 relocations, and compare every byte with the normalized original DOL. No bits are masked. The source owns zero data, BSS, exception or startup-table bytes. Original flags, message storage, context, floating constants, and all called entries retain their current ownership.

`audit.py` checks the complete original extent, all 3,141 exception index entries, 24 constructors and eight destructors; none references this text. `final_integration.json`, `final_splits.txt`, `final_config.txt`, `scope_edits.txt` and `ownership_audit.json` provide central integration instructions. Register NonMatching with the extra flag and preserve global function scope, then promote only after the native original DOL hash and regression checks. This is a partial text-only split.

The adjacent `fn_8020E27C` value-update probe remains private and uncredited. Its automatic integer-to-float conversion emits an additional constant section; no production source or ownership is claimed for that routine.
