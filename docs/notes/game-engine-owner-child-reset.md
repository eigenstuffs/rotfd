# Owner child reset

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: `scratch/engine_owner_child_reset_20261011ez/final_integration.json`.

Ordinary C++ `src/Game/engine_owner_child_reset.cpp` reproduces the complete `fn_80237924` extent, `80237924..80237BC8`, all 676 text bytes and 20 actual retained ELF relocations. The new public header declares only its existing C entry through an opaque partial owner type. Standard Game GC/1.3.2 `-O4,p`, exceptions off, plus `-use_lmw_stmw on` reproduce the original 0x30-byte stack frame.

When the owner's index is nonnegative and its source handle is valid, the routine caches the resolved child count and visits each child. The child lookup returns a nontrivial four-layer native handle by value. The caller copies it into its own retained handle, destroys the returned temporary, resets the resolved child, and then destroys its local copy. The separate local and returned temporary reproduce the original stack offsets `C` and `8`, four zero stores, retain call, and destructor order. Modeling the returned temporary as the bare native base incorrectly passes `-1` to the base destructor; the observed derived return type passes zero exactly. The original external child lookup at `80237BC8` independently constructs through four zeroing layers, confirming the return model. Its body remains external and uncredited by this unit.

If the owner's related handle is valid, the routine sets the resolved object's state bytes `22D` and `22C` through separate resolutions. It then resets the owner's motion, active flag, scalar defaults, position and enabled flag. The original shared zero vector is writable external data: declaring it nonconst reproduces the original sequential floating-point loads/stores and the later reload for the second vector assignment. A const approximation caches the vector and loses twelve original bytes.

The only allocated section is 1,136 bytes of `.text`: the retained 676-byte entry and five unused weak derived destructors totaling 460 bytes. Their sizes are 100, 92, 88, 84 and 96 bytes. All ten weak-code relocations and raw bytes are inventoried separately; the retained entry has no reference to any weak copy, so ordinary unused-weak discard applies. No special override adapter is proposed. The source emits no initialized data, BSS, exception record, constructor/destructor table entry, vtable or owned padding.

Strict production recompilation compares every retained byte, all 30 actual emitted relocation targets, complete symbol extents and the full raw/allocation inventory. Complete original scans of the exception index at `80015F60..8001F2C0`, constructors at `80299920..80299980`, and destructors at `80299980..802999A0`, including descriptors and padding, find no reference to this entry. All original functions, tables, manager state, scalar constants and vector data outside the retained text range keep their existing owners. No entry renaming, consumer change or central metadata edit is needed.

`verify.py`, `allocation_discard_audit.json`, `original_full_tables.json`, the production object, original primary and return-callee assembly, and all isolated variants are preserved in the scratch namespace. Root must register this source NonMatching and complete the full native DOL/hash and regression acceptance before credit.
