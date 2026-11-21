# Callback control constructor replacement proposal

The already accepted104-byte fn8025BC5C is reproduced exactly as genuine CallbackControl802ECC00 construction. It calls the native CP constructor, keeps the original ECC00 table identity, clears flag1 and sets flag4. The partial opaque suffix brings the complete allocation to128 bytes, matching Throwable_Z.h.

Default GC1.3.2/O4,p reproduces104 retained bytes with three actual relocations. One unused weak Single destructor emits228 inventoried text bytes and nine relocations, discarded with no retained references. There are no data/BSS/padding/EH/startup allocations or original raw-table references.

This is an ownership and identity replacement with zero new code credit. The existing432-byte callback_virtual_controls.cpp owner retains its first328 bytes BB14..BC5C and three functions. Removing only its final104-byte definition produces an isolated prefix object that exactly matches all328 bytes and actual relocations; original full owner source/canonical metadata and this partition proof are preserved privately. Root owns that source/split/canonical transaction and guarded caller renames. No old owner, consumer or central metadata was edited here.

All current old-name source/header consumers are inventoried with hashes and exact lines. Integrate CP first. The strict constructor proposal and complete original table audit are frozen in scratch/engine_callback_control_ctor_20261010cs; full build/regression acceptance and prevention of double credit remain with root.
