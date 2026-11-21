# Engine keyed child and resource rebinding

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: `fn_801D23D0`, 360 retained text bytes, zero data bytes, ten actual relocations, range 0x801D23D0..0x801D2538. Its external name is preserved. GC/1.3.2 uses the ordinary hardware Gekko optimization flags plus `-use_lmw_stmw on`, with exceptions off.

The owner has a handle-array view at +0x20 and three arrays of 24-byte records at +0x40, +0x4C and +0x58. The routine visits each record and rebinds its handle at +4 through the existing keyed selection `fn_801B3D80`, using the owner's +0x20 handle set. After `fn_801D0CBC`, it visits the nested arrays of 32-bit resource references at +0x70, copies each reference to a reusable key through `fn_801B3FC8`, and replaces the element with the result of `fn_801F4F8C` on the global resource registry at +0x144. Private declarations only specify observed fields.

An ordinary inline count accessor on the inner array reproduces the original object-pointer reuse between the condition and loop body. Direct field access folds that pointer calculation into an indexed load and yields a four-byte-short near-match. The production source uses the accessor and matches every retained byte and relocation.

`final_integration.json` under `scratch/game_engine_resource_rebind_continuation` freezes source SHA256, the empty recursive quoted-header inventory, all symbol extents, and all allocated sections and actual relocations. Proposed central split/config edits and `ownership_audit.json` are siblings. Strict production recompile through `verify.py` passes. No unused helper/weak functions, data, BSS, or padding are emitted. Full extabindex, constructor, and destructor table audits find no records. The remaining original 0x801D0650..0x801D3088 fragment stays assembly: this is a partial text split. Parent final DOL and regression acceptance remain required.
