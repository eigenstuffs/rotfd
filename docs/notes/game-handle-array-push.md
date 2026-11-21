# Handle array push

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

`src/Game/handle_array_push.cpp` reconstructs `fn_80263650`, original `.text`
range `80263650..80263764` (276 bytes), as ordinary C++.

The function appends a refcounted four-byte handle. It grows capacity in blocks
of 32 using the existing allocator's sized resize/allocation/free helpers,
increments the array count, initializes the new native handle and copies/retains
the original handle. The original zero-capacity and null placement-address
branches are retained. The explicit native constructor ABI avoids emitted weak
placement helpers while preserving ordinary C++ behavior.

Run `python3 scratch/game_handle_array_push/verify.py`. Standard optimized GC/1.3.2 Game flags
reproduce every allocated byte, the exact global function extent and all actual
relocation sites, kinds, symbols, addends and targets. SDA21 relocations, where
present, include section/base/displacement checks. Relocated instructions are
compared directly against the protected original DOL. No weak helpers, owned
data, BSS, padding or other allocated sections are emitted. External strings,
globals, allocator storage and called helpers retain their original ownership.
Original extabindex, `.ctors` and `.dtors` audits find no overlap or reference
into this range. Candidate, relocation and original-metadata JSON preserve
hashes and dependencies.

This partial text-only split leaves neighboring functions and data external.
Central integration must pass full DOL hash, native objdiff, source-extent and
regression checks. No new symbols, shared headers or special flags are needed.
