# Callback activation flag guard at 8025A244

The guard skips activation when either state mask 0x20000 or 0x10000 is set.
Otherwise it resolves the handle at owner+0x70, forwards the valid object to
802139D8, and invokes 802573E4 on the owner.

A file-local partial owner view describes the established 64-bit flags at
+0x38 and the existing CallbackVirtualHandle at +0x70. Its signed-char const
member predicate expresses the native full-width mask test and shared flag
loads. The shared handle header is unchanged. No casts, virtual hierarchy or
additional emitted helper is introduced.

The complete 224-byte function at 8025A244..8025A324 preserves all five actual
relocations and all four undefined symbols have GLOBAL binding. It emits no
other allocated sections, exception data, padding or weak backups. The complete
original exception-index and constructor/destructor scans find no associated
metadata outside this text unit.

Frozen evidence is in `scratch/callback_flag_guard_8025A244_20261020_parallel/`.
Production receipts and the strict verifier are in
`scratch/callback_flag_guard_integration_20261020/`.

The production object, native bytes/bindings, original DOL hash, baseline
regression check, source extent audit and all 66 unit tests pass. Generated
progress is 1,933,756 code bytes (74.1535%), 975,908 data bytes (94.6623%),
and 7,986 of 8,803 functions.
