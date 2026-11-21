# Native 80-byte world curve record

`src/Game/world_curve50_resize.cpp` reconstructs `fn_801E4450` (592 bytes).
`src/Game/world_curve50_destructor.cpp` reconstructs the native record
destructor at `0x801E46A0` (588 bytes). Together these add two functions and
1,180 matching code bytes. They complete the resize implementations for all
five array types traversed by the recovered world-record loader; they do not
complete the entire world or curve subsystems.

The 80-byte record owns three ordinary curves at `0x0C`, `0x1C` and `0x2C`,
with key strides 40, 20 and 20 bytes. Its final member at `0x3C` is a
20-byte specialized curve. Its recovered shared declaration now owns the
nested row array directly after the curve base, with the virtual pointer at
`0x10`. The constructor clears the array words after table installation.
See [specialized curve lifetime](game-world-action-curve.md) for the refined
layout and its matching destructor.

The record destructor invokes the specialized member destructor, then destroys
the three ordinary curves in reverse order. The specialized destructor and
its 12-byte native table now have matching source. Four bytes following that
table remain original alignment storage. The record's 16-byte table extent at
`0x802F15C0` and its reset override remain original. Address-based names remain
inferred.

Resizing follows the same keep-capacity and placement-construction behavior
verified for the other four record types. The source reuses their shared
native curve declarations. The shared header was refined during the specialized curve integration;
both retained functions remain exact. The resize object emits 1,188
unreferenced weak helper bytes;
they are absent from the final image and receive no credit. The standalone
destructor emits only its retained body. Neither object emits data or BSS.

Production verification applies all 47 actual retained relocations and checks
every retained byte and every allocated symbol:

```
python3 scratch/game_world_curve50/verify.py --production
python3 scratch/game_world_curve50/link_proof.py
```

At the original record-pair checkpoint, the full DOL was byte-identical,
all 642 source units matched, and all 23 tests passed. All 639 candidate source/object hashes and 104 recorded header hashes
are current. The baseline is immutable and progress, source extent and
assembly audits pass. See `scratch/world_curve50_checkpoint.json` and the
corresponding build, changes and test logs. Neighboring world operations,
and remaining original tables are unfinished. The newer specialized-curve
checkpoint validates the shared-header update and both record routines.
