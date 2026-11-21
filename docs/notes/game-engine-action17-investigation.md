# Private action-17 exception-record investigation

`fn_800E8130` remains original assembly and receives no source credit. Its ordinary local-object probe matches all 152 code bytes, its twelve-byte exception index, every actual relocation, and all exception data except the two bytes at `80014FB6..80014FB8`. The original action word at `80014FB4` is `91003701`; GC 1.3.2 emits `9100186C`. Three fresh recompiles reproduce the same discrepancy. The existing lifecycle probe and all accepted sources are unchanged.

The leading action byte is `91`, meaning masked action 17 with the end bit set. The following words are the large negative local-stack offset and native destructor target, but this investigation has **not established a supported action-17 runtime structure or proved the two differing bytes are structure padding**.

The actual matched target unwinder does not support action 17. Its reconstructed `src/Runtime/Gecko_ExceptionPPC.cpp` defines actions 0 through 16. More directly, original instruction checks in `report.json` verify that normal exception dispatch masks the action byte at `8011FF68..8011FF6C`, bounds it at 16 at `8011FF7C`, and branches to `terminate` at `80120080` for larger values. Rethrow dispatch rejects values at or above 17 at `8011FEB4..8011FEC4`. Stack unwinding similarly bounds the masked action at 16 at `8012045C..80120468` and calls `terminate` at `801208CC`; iterator dispatch has the same bound at `80120BE8..80120BEC`. Thus the original target reads the action discriminator and rejects 17; it has no action-17 payload reader establishing a field/alignment layout. This is static original-code evidence, not a runtime execution claim.

Installed `tools/dtk` also rejects the candidate record before producing an output object:

```
Failed to decode @9 (extab 0x00000000..0x0000001C)
Invalid action value 17 at offset 0x10
```

All three `dtk extab clean --padding 3701` attempts fail with no output file. The retained DTK 1.8.3 primary source `scratch/dtk-reference/src/util/extab.rs` calls `cwextab::decode_extab` before asking decoded actions for their structure-padding offsets. It consequently provides no supported cleanup path for this record. The source and binary hashes, exact commands, failures, raw objects, resolved relocations and original instruction bytes are frozen in `scratch/game_engine_action17_investigation/`.

The existing supported DESTROYLOCALCOND normalization is inapplicable: it requires masked action 3 and the proven two-byte alignment between native short fields and a pointer. No root verifier, cleanup tool, shared file, compiler output or original input was changed. The differing bytes remain unnormalized. Promoting this function would require a separate supported format/cleanup proof or an exact raw compiler emission; neither is established here.
