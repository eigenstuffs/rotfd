# Callback pair constructor

The complete168-byte original fn802588A0 is reconstructed as the genuine `CallbackPair_802EC798` constructor. Two ordinary inline base stages call native ContainerBase and install the original ED000/C798 tables. The second stage receives the complete owner pointer, preserving the original distinction between base and owner receivers. It then constructs two-stage and three-stage handle members at60/64, sets flags0x4280 and initializes index68 to-1. The emitted object is112 bytes, using the original base tail padding.

GC1.3.2 with default O4,p flags reproduces every retained byte after seven actual relocations. Three unused weak handle destructors contribute264 inventoried text bytes and six relocations; they are discarded and have no retained references. No data/BSS/padding/EH/startup allocation is claimed. Complete original exception-index, constructor and destructor allocations contain no references into the retained extent. Original table identities and ownership remain unchanged.

Five compiled old-entry consumers are inventoried with hashes and exact declaration/call lines: callback_flag_setup8025ac88.cpp, callback_flag_setup80259968.cpp, engine_early_setup_more80064D90.cpp, engine_early_setup_more80064744.cpp and factories80261388.cpp. No old-name header consumers exist. Root owns their identifier-only migration, complete preserved originals, unchanged-address recompilation and canonical proof refresh. This agent changed no consumers or central metadata.

The strict isolated candidate is frozen in scratch/engine_callback_pair_ctor_20261010co. The already frozen container-layer declaration header is included and hashed without modification. Integration, full executable hash and regression acceptance remain with root.
