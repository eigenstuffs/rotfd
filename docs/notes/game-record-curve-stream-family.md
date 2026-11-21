# Record curve stream and application family

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three separate ordinary source units reconstruct788 original text bytes: fn801ADF58..801AE018192-byte scalar/vector curve reader, fn801AE018..801AE1DC452-byte curve application wrapper, and fn801AE240..801AE2D0144-byte vector/rotation stream reader. All retain their original C identities and have independent contiguous sections.

Each reader first registers the stream's Handle through the original manager, reads a two-byte identifier and forwards the remaining member curves to their existing readers. The application wrapper conditionally samples eight populated tracks, updates corresponding signed-short cached indices, writes four scalar properties plus opacity, position, scale and angle, then dispatches virtual slot24. The established four-word curve view exposes count@4; the remaining members are unchanged partial declarations.

Reader probes match on first compile. For application, branch-local scalar/Vector declarations emit separate stack slots. One function-scope scalar and one function-scope Vector shared by the relevant branches naturally reproduce the original8/C temporary slots and0x40 frame, closing all24 original stack-address differences.

Production GC1.3.2 Gekko/O4,p objects match all788 allocated text bytes and28 actual relocations (12/8/8). Fresh unchanged-core recompiles verify all sections and real relocation targets; there are no weak helpers, data/literal/BSS/padding/EH/startup allocations. Current original names/full1,671-canonical overlap/43,659-source body preflight passes. Stable5,583-object/119,086-real-relocation/777,360-word audit pins every active input hash and verifies config/inputs unchanged throughout. It finds exactly three original entry references/direct calls: the two stream readers from accepted Game/engine_streams_801B311C.c, and the application from original assembly auto_03_80232458_text. No aliases or initialized data pointers overlap. All caller spellings remain unchanged; no header/identifier migration is required. Full original table ownership audits have zero EH/startup references.

Evidence: scratch/game_record_curve_stream_family_801adf58. Frozen handoff scratch/game_engine_batch247. Central/native acceptance pending.
