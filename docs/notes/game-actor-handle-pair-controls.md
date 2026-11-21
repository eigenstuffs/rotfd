# Actor Handle pair and counter control

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Isolated exact ordinary C++ for `fn_8006ECE8` (228 bytes) and `fn_80087D04` (360 bytes), pending central full-DOL acceptance. Both preserve their original C entry identities and use GC 1.3.2, proc 750, O4,s, C++ exceptions on and use_lmw_stmw.

The pair dispatcher obtains its actor, resets modes 1 and 2, then passes two retained Handle copies to the existing pair operation. An ordinary `Record::getHandle() const` returning `const Handle_801F7F10&` preserves the member address across base construction and exactly reproduces the original 228-byte body. Direct public-member access compiles to 220 bytes; those diagnostic probes are preserved.

The counter control tests the actor enable byte, constructs a retained two-copy target Handle, and checks its key. An empty key clears the related Handle and bit 31 of the actor flags, then updates the counter using the actor query. The final counter update uses 24. A three-layer private zero base plus the established native Handle hierarchy reproduces the original temporary construction and destruction.

Ownership is complete: first function owns extab 8000C3D4..8000C434 and index 80018FFC..80019008; second owns extab 8000DF88..8000DFF0 and index 8001A1B4..8001A1C0. Actual local object names are @62/@63 and @131/@132. Full exception/startup table and initialized-word audits find only their EH indices and the second function pointer at 802B8D04 in externally owned GLOBAL lbl_802B8CF4 (28 bytes). No data, BSS, literals or padding are transferred. The sole existing first-function source caller remains unchanged.

Strict standard weak-EH verification accounts for all emitted allocations and 40 retained / 47 unlinked real relocations. Fresh accepted strong production/recompile proofs cover Handle1FF78,20B90,25B74,25BF4,38014. Actual isolated MWLD links select those GLOBAL owners and discard all six and eighteen backup allocations respectively; 852 backup code bytes and 320 backup metadata bytes earn no credit. Three zero helper names are unique and unreferenced by retained EH. No new proof gate is required. Full original-layout native audits and original-DOL acceptance remain root integration requirements.

Frozen handoff: scratch/game_engine_batch214/manifest-list.json, HANDOFF.md and frozen_hashes.json. Replay verify.py into a new output directory. Every predecessor and shared file remains unchanged.
