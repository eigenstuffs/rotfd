# Streaming state initialization

`src/Game/platform_audio_stream_init.cpp` reconstructs all 544 code bytes of
`8028AC20..8028AE40`. The new header records a physical `4AD8`-byte view, including
six 92-byte DVD/stream records, four 60-byte single-voice entries, the 32-byte
music group at `318`, embedded thread at `338`, queue at `650`, stack pointer at
`670`, observed control words near `A04`, file information and names near `4A28`,
and the trailing allocation at `4AD4`. These offsets describe proven access
relationships rather than recovered original class identity. Earlier convenient
six-voice views overlap part of the embedded thread; this initializer makes the
four single voices and the distinct music/thread storage explicit.

The function allocates `10800` bytes at alignment 32, resets each stream record
in its original word-store order, clears four single-voice control pairs and the
observed music control words, then acquires two AX voices at priority 31. It
clears queue/control/open-state words, assigns the borrowed music-level constant,
clears 96 name bytes, allocates a `4000`-byte stack at alignment four, initializes
the thread queue, and creates the original `80288D00` worker with that stack's
upper address, priority zero and attribute one. Only a successful signed-byte
thread result triggers resume. Native allocation behavior has no added failure
check. Record initialization is explicit per entry because the original stores
are unrolled.

No state BSS, diagnostics, floating constant or worker implementation is owned
by this text-only partial split. All remain present under existing ownership or
original objects. `python3 scratch/game_audio_stream_init/verify.py --production`
checks the exact 544-byte section, all 23 actual relocations including the r2
music-level load, global function binding/type/extent, absence of emitted data,
helpers or padding, and all included headers. Full linked proof, original DOL
SHA-1, previous source/header and match preservation, source extent/assembly
audits and tooling tests establish integration credit.
