# Callback flag constructor

The complete108-byte original fn8025C4B4 is reconstructed as the genuine CallbackFlag802ECD68 constructor. It calls native ContainerBase, installs the unchanged original ECD68 table through an empty construction stage, constructs the three-stage handle at60, and sets flag0x400. The stage adds no storage; native tail-padding reuse and eight-byte alignment yield the observed104-byte allocation. The empty stage preserves the original receiver allocation without modifying vtable identity or data ownership.

Default GC1.3.2/O4,p emits108 exact retained text bytes with four real relocations. Three unused weak handle destructors contribute264 fully inventoried text bytes and six relocations, discarded with no retained references. No data/BSS/padding/EH/startup allocation is claimed; the complete raw original extabindex/.ctors/.dtors scans have no references to this extent.

Five existing compiled files mention the old entry: factories80261388.cpp and engine_early_flag_construct80035294.cpp/8003CD88.cpp/8002CF70.cpp/800737D8.cpp. Three of those only carry a shared declaration; the factory and8002CF70 actually call it. All exact paths, hashes and lines are in compiled_consumer_inventory.json. Root owns guarded identifier-only replacement and unchanged-byte consumer recompilation; no consumers or central metadata were edited here.

The source/header and strict isolated proofs are frozen under scratch/engine_callback_flag_ctor_20261010cq. Frozen CN declarations are reused unchanged. Full executable hash/regression acceptance belongs to the integrator and is separate from this isolated proof.
