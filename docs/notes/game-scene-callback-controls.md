# Scene callback forward and query controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Thirty-two ordinary C++ functions at `800BF598..800C0600` reconstruct sixteen pairs of callback forwarding and lookup methods. Each forwarding entry sends its original external selector through `fn_8025ED38`, then invokes its parent method. Each lookup entry returns the result from `fn_8025E70C` unless it is -1, then returns the parent lookup result. The original selector pointers and parent identities remain external and unchanged.

Every typed first probe matched its complete text and original exception allocations. The final production sources share `include/Game/scene_callback_controls.h`, with exactly32 consumers, and preserve the established opaque two-argument callback ABI. The family contains sixteen64-byte forwarding methods and sixteen76-byte lookup methods, totaling2,240 text bytes and640 original exception/index bytes.

Each final object owns exactly one strong text function, an8-byte exception record and a12-byte index. Complete extent/local-symbol and actual relocation verification passes for all160 retained relocations. Full scans of the3,141 original exception records, constructor/destructor slots and exception terminal record preserve all original ownership. No additional data, BSS, weak helpers, padding, aliases or identifier migrations are claimed. Durable private probes, original disassembly and isolated production evidence are in `scratch/game_scene_leaf_controls`. The complete original DOL, regression and repository acceptance checks pass.
