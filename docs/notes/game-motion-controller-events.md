# Motion controller notification and monitor events

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three ordinary C++ functions reconstruct 352 text bytes and 60 owned exception/index bytes: 800A379C forwards a value to actor virtual slot 45; 800A37D0 and 800A386C resolve the actor Handle, obtain the original monitor and issue the corresponding keyed event when its first/second slot exists. The first monitor event also writes the original floating constant to actor offset 0x394.

Native declarations preserve the actor vtable at offset 8, Handle at 0x24, key at 0x320, monitor slots at 0x130/0x134, signed Handle index/tag comparison and original external context/constant ownership. All allocated bytes, actual relocations, symbols and compiler-local exception records match after production recompilation. The complete original exception index, descriptor and startup tables are audited.

This is a partial text-only reconstruction. Other original class methods, virtual tables, registration data and all borrowed constants remain outside it. No weak helpers, owned data/BSS/padding, aliases, object payload edits or symbol migrations occur. Frozen isolated evidence is in `scratch/game_motion_controller_events/final_integration.json`; central original-DOL acceptance is required.
