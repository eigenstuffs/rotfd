# Early record default settings

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`early_record_default_settings_800221DC.cpp` reconstructs the existing C entry at `800221DC..80022384` (424 bytes). The retained extab is `80005B98..80005BB0` (24 bytes), with its 12-byte index at `80016158`. All retained bytes and 28 real relocations pass the isolated strict verifier. Parent original-placement native linking, original DOL hash and regression checks remain required before source credit.

The function takes an unused context and a caller-owned record pointer. An ordinary inline defaults helper writes the same scalar/vector defaults as the accepted native Record constructor, resets the signed index at `+48`, and performs `first = second = Handle()` assignments at `+8C/+90`. It then replaces the preset scalars at `0/4/8/C/10/14/18/1C`. The 12-byte vector assignment copies individual floats, preserving the original load/store order. These are field operations on existing storage; the source does not create an additional whole Record temporary or change the accepted constructor.

The private view covers 148 bytes (`94` hex), leaving `68..8C` opaque. The external zero Vector and all float constants keep their original ownership. The original C entry is unchanged. The complete original extabindex/startup-table audit transfers only its own exception pair. The initialized-data scan finds that index pointer plus seven existing callable-table pointers; their complete original symbol extents and raw hashes are recorded, and all seven data tables remain external.

GC1.3.2 with `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` emits exactly the original retained code and metadata. It also emits a 120-byte weak native Handle21B54 destructor and two private 80/76-byte weak layer destructors, plus 92 metadata bytes. Their 15 actual relocations and all nine allocations are inventoried and receive no credit. The retained exception action resolves to the existing accepted strong Handle21B54 destructor. Its complete original object and fresh recompile match all bytes and relocations, including its recursive quoted header.

The standard unchanged weak/EH verifier schema suffices; no new outer gate, source alias, identity migration or metadata rule is proposed. The private native MWLD proof selects the exact accepted strong production owner and discards all nine backup code/EH/index allocations. Root must repeat the full-game native discard audit and original DOL acceptance. All probes, ownership evidence, manifest and replay scripts are frozen under `scratch/game_early_record_settings_continuation`; the separate adjacent Record activation research is preserved there historically and continues in a fresh namespace.
