# Callback single-handle constructor

The complete108-byte fn8025A58C is reconstructed as genuine CallbackSingle802ECA18 construction. It calls the native CallbackPair constructor recovered by CO, installs the unchanged original ECA18 table through an empty construction stage, constructs the three-stage handle at70 and sets flag1. The partial pair view retains opaque6C..70 bytes, keeping the derived handle at its native offset; the full object is120 bytes, as the MovingAgent_Z.h factory allocates.

The independent lifetime view repeats the pair's observed inline destruction sequence from container_two_handle_initialization.cpp: C798 table, second/first handles, ED000 table and native ContainerBase destruction. It avoids unresolved synthetic destructor dependencies without changing the frozen CO header. It must not be combined with the CO full declaration in the same translation unit. No external destructor symbol migration is needed.

Default GC1.3.2/O4,p reproduces108 retained bytes with four actual relocations. Three weak handle destructors plus one weak pair destructor emit448 additional text bytes and14 relocations; every symbol and raw byte is inventoried and discarded, with no retained references. No data/BSS/padding/EH/startup ownership is claimed. Full original extabindex/.ctors/.dtors scans contain no references to the retained extent. Existing vtable identities and ownership remain unchanged.

Seven compiled sources and callback_startup_internal.h reference the old entry; exact paths, complete hashes and lines are in compiled_consumer_inventory.json. Root owns guarded identifier-only migrations, preserved originals and complete recompilation proofs. No existing consumers or central metadata were edited. Integrate the frozen CO constructor first.

The complete isolated proof is frozen in scratch/engine_callback_single_ctor_20261010cp. Global executable hash and regression acceptance remain with root.
