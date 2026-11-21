# Curve Handle actions and packed encoding

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three independent ordinary C++ units match complete original text and actual relocations under GC1.3.2 Gekko/O4,p, exceptions off:

- `fn_801B0E28..801B0EB8`: 144 bytes, two actual calls to the existing `fn_801F7EB8`. Iterates eight-byte timed Handle keys, resolves each non-null Handle again, and invokes virtual slot 1C.
- `fn_801B115C..801B11EC`: 144 bytes, one SDA relocation. Scales quaternion components x/y/z/w and stores signed 12-bit values while preserving each packed short's low four bits. The input quaternion stores w/x/y/z. Direct float-to-field assignment reproduces the native narrowing; an unnecessary intermediate int generated four extra extsh instructions.
- `fn_801B12DC..801B13C4`: 232 bytes, one SDA relocation. Scales three input vectors and truncates their nine components into signed shorts following a two-byte timed-key field.

All 520 emitted allocated bytes are retained text; there are no emitted helpers, literals, data/BSS, EH, startup entries, padding, or native identity migrations. The external original GLOBAL constants `lbl_8037A210` and `lbl_8037A214` remain under their existing .sdata2 ownership. Float-to-integer lowering uses fctiwz and emits no integer-to-float bias pool. Each source has translation-local partial layout declarations and no new shared header.

Both the production compile and fresh unchanged-core verifier recompiles match complete extents and all four actual relocation targets. Full original extabindex (including its terminal descriptor), ctor and dtor tables contain no ownership for these ranges. Current symbol/canonical/body preflight scanned 1,680 manifests and 44,024 body files without overlap. A guarded snapshot scanned 5,602 active inputs, 119,086 actual relocations and 777,360 initialized original words; config and every input hash remained unchanged. It found seven original entry references/direct calls, no aliases and no initialized pointers into these functions. Existing source/header consumers retain their exact C spellings and bytes.

Frozen evidence and three per-function manifests: `scratch/game_engine_batch251/manifest-list.json`. Root owns central integration and full native original-DOL acceptance.
