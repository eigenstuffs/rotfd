# Sparse Handle slot insertion

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

fn801ADC08..801ADF18 is784 bytes of ordinary sparse-row insertion. It searches for a clear bit and increments active count. A reused slot is placement constructed and marked present. If none exists, the row array grows capacity by32 when needed, constructs one20-byte row, grows the bit word array to cover the high-water index, marks the bit and increments high-water count.

Rows contain three zero-initialized array words, one zero key and an untouched reference-count field. The BitSet partial view contains its word array and requested bit count; the pool adds a separate high-water index and active count. Sequential count/capacity initialization preserves the native store order. `(n>>5)+1 > words.count` preserves the original comparison operand order. Trivial word construction/destruction leaves the native empty counted loops.

Production GC1.3.2 Gekko/O4,p matches all784 allocated text bytes and28 actual relocations. Two fresh unchanged-core strict compilations pass. There are no compiler helper, literal/data/BSS/padding/EH/startup allocations. Current original C identity and all1,671 canonical section overlap checks pass; full43,644-file body census found no prior implementation. Stable5,581-object/119,086-relocation/777,360-word ownership snapshot verifies every config/input hash unchanged throughout. Sole original direct caller801ADBC8 is intra-unit; no aliases/initialized data pointers or compiled consumers require migration.

Evidence: scratch/game_sparse_handle_slot_insert_801adc08; frozen handoff scratch/game_engine_batch246. Root integration/native acceptance pending.
