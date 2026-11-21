# Early named resource target selection (8002C810)

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated production object matches all 1,348 original code bytes, the eight-byte exception record at 80006B04 and its twelve-byte index at 80016A7C. The unchanged strict ELF verifier resolves and compares all 74 actual relocations. There are no additional emitted allocations, helpers, owned literals or weak overrides. Full-game integration and the original DOL hash remain the parent integrator's acceptance step.

`fn_8002C810` preserves its existing C entry and four-argument ABI: first Name reference, first selection word, second Name reference and second selection word. It copies the second name, substitutes the first external sentinel name when both names agree, and updates the two existing resource globals at 803775C8/803775CC. Their -1 sentinel and zero handling are preserved. Each active resource selects a target from its opposite resource's related Handle, or from the current indexed 0x4C-byte record's Handle at +0x14. The original manager-entry lookup compares the signed generation byte against the Handle and returns its object without adding a bounds check.

For resource flag 0x10000000, the routine resolves its own Handle, stores the target at node+0x3C4, and sets node+0x390 according to the target's name. It forwards selection events 0xE/0x11 with the original signed-short narrowing. The alternative system paths retain the returned Handle query, default selections 0xB9/0x7B, target/state writes at +0x440/+0x444, and controller transition 0x33. The final current-state check and callback are unchanged.

Private layouts express only observed offsets. Resource flags are the original 64-bit pair at +0x38, related/own Handles are +0x58/+0x70, and entry stride is sixteen with object at zero and signed generation at +0xC. The copied local Name is held as the sole member of a local wrapper and accessed through a mutable member reference. This ordinary stack-backed copy preserves the original object lifetime and stack slot; a standalone Name local is scalarized by this compiler. The current index is staged before the byte-backed record expression, reproducing the original indexed loads and scratch register allocation. These source views do not establish complete original class layouts or translation-unit boundaries.

Compiler: GC/1.3.2 with established `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` container flags. `index-local.cpp` and `record-helper.cpp` both produce exact original sections. Every earlier diagnostic remains preserved, including nonmatching Name-interface variants; no masked result receives credit.

All original strings, the two state globals, manager/list storage and external function tables retain their original owners. `ownership_audit.json` records borrowed string bytes and full exception/startup scans. `original_pointer_audit.json` scans every initialized DOL data slot and records all original pointers into this routine, preserving its original symbol and address. No constructor/destructor startup table entry transfers. No native identifier migration, source-consumer change, pool retirement, forced retention or new verifier adapter is proposed.

Frozen handoff: `scratch/game_early_resource_target_selection_continuation/final_integration.json`, with `final_splits.txt`, `final_config.txt`, `verification/report.json`, complete allocated inventory, compiler evidence and pointer audits. The parent owns all central configuration and final acceptance.
