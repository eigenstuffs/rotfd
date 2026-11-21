# Renderer string continuation at 802AF064

The existing `native_readable_pools_802AEF48.cpp` now emits 434 exact read-only
bytes through `802AF0FA`. Its prior 282 bytes and eleven GLOBAL symbols are
unchanged. Seven additional complete character arrays contribute 138 bytes;
14 bytes of natural inter-string alignment give 152 newly credited data bytes.

The recovered strings include the encoded renderer diagnostic, ShadowBitmap,
ShadowMaterial, Material, Anonymous Alloc, GCRenderer_Z.cpp and Anonymous New.
The original `lbl_802AF064` name and address are preserved, with its oversized
156-byte lump divided into the seven complete string extents. The final six
bytes at `802AF0FA..802AF100` remain explicitly original-owned; they are not
compiler-emitted data and earn no source credit.

An independent recompile reproduces the complete candidate object. The audit
covers all 6,875 active linker inputs and finds 23 direct pool relocations. The
only direct `lbl_802AF064` consumer is the existing diagnostic pointer at
`80377508`, with addend zero. Nineteen checked immediate-offset instructions
in the existing screen-registration source and original renderer code provide
additional evidence for the following six names. All addresses and consumers
are preserved. There are no code, relocation, weak or undefined allocations in
the new data-only object.

Frozen evidence is in
`scratch/renderer_string_append_audit_20261020_parallel/`; production integration
and exact linked-symbol checks are in
`scratch/renderer_strings_integration_20261020/`. Historical ten-byte readable
pool receipts remain preserved alongside the accepted 282-byte predecessor.
The new canonical candidate describes the complete 434-byte owner.
