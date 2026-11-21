# Action allocation and component binding

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ordinary C++ reconstructs `fn_80097474` at 80097474..80097504: 144 text bytes and 20 owned exception/index bytes. It calls the original base method, allocates a 16-byte action through the existing heap helper, constructs it when allocation succeeds, stores the action at target offset 0x14 and invokes embedded component virtual slot 2 with event 6. The component occupies 0x318..0x344 and the target pointer follows it.

All allocated bytes, actual relocations, compiler-local exception records, symbol extents and production recompilation match. The complete original exception index/descriptor and constructor/destructor tables are audited. The heap, source strings and constructor remain borrowed external originals, with their existing symbols and owners. No data, BSS, weak helpers, aliases, padding or symbol migrations are owned.

This is a partial text-only split; surrounding methods and original class/registry data remain outside it. The isolated source/header/proof is frozen in `scratch/game_action_factory_80097474/final_integration.json`; central original-DOL acceptance is required.
