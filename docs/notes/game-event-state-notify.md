# Event state notification

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/event_state_notify_80096f3c.cpp` reconstructs `fn_80096F3C`, 140 text bytes at `80096F3C..80096FC8`, together with extab `8000F4D8..8000F4E0` and extabindex `8001AD24..8001AD30`.

The owner uses a genuine compiler-generated vptr at offset eight. Virtual notification slot `0xBC` accepts a position pointer and zero. A transition from cached state eight to current state five uses the owner's position at `0x3C4`; all other cases forward the incoming third argument. The second argument is unused. After notification, a changed current state at `0x320` replaces the cached state at `0x3E8`.

The new frozen declarations are `include/Game/event_state_notify_views.h`. GC1.3.2 uses standard optimization and Object extra `['-Cpp_exceptions on']`. The strict isolated verifier `scratch/game_owner_state_events/event_state_notify_80096f3c/verify.py` proves all160allocated bytes, actual local symbol names/extents and both owned exception-index relocations. The one nonallocated metadata relocation is audited. No external text relocation, weak helper, data allocation, BSS or padding occurs. Original full DOL SHA1 and full original exception/constructor/destructor ownership audits pass.

Two neighboring research candidates remain private and uncredited: `800927C0`132/11 temporary-register differences and `8006D56C`280/5 register differences. Bounded findings are preserved in `scratch/game_owner_state_events/FINDINGS.md`; neither is part of this source or manifest list.
