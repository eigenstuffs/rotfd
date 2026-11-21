# Python factories for native early constructors

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Four bindings at `800DBB70`, `800DD514`, `800DD63C` and `800DD764` each
reconstruct native placement construction followed by pointer-name encoding.
All 296 original code bytes, eight exception bytes, twelve exception-index bytes
and twenty actual relocations per binding match in isolated production objects.
The dedicated native constructor view header preserves the established 0x98 and
0x200 factory extents, all observed fields and opaque storage. Its four native
constructor refinements preserve existing code/metadata and receive zero credit.

The wrapper manifests freeze source/header hashes, complete allocated extents,
actual relocation records and complete original exception/startup/shutdown table
ownership. No wrapper emits extra weak code, data, BSS or padding. Frozen evidence
is in `scratch/game_python_sdk_native_factories/`.
