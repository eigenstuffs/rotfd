# Early action and component controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Twenty-one ordinary C++ functions reconstruct 1128 original text bytes and 420 exception/index bytes. Production recompilation passes the strict complete allocated-section, symbol extent and actual relocation checks (66 relocations). The original exception index has exactly one owned entry for each function; the full exception descriptor, constructor table and destructor table have been audited. No weak helpers, original data, BSS, padding, aliases or symbol migrations are owned.

The source views preserve the native vtable at offset 8, component at 0x318, actor flags at 0x30, controller flags at 0x38 and vector at 0x3B8. Controller updates use the original 64-bit flag operation. The vector callback copies three floating components individually, preserving the original floating loads and exception save record. Other routines forward state transitions, issue component events, or update controller flags before a virtual call.

This is a partial text-only reconstruction: the surrounding original constructors, destructors, adjustment thunks, virtual tables, registry data and other methods remain outside these splits. Dedicated declarations are shared by all twenty-one source consumers. No probe disassembly or relocation-masked score is credited.

The isolated handoff is frozen in `scratch/game_early_action_controls/final_integration.json`; central registration and complete original-DOL acceptance remain required.
