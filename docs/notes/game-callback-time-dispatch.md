# Callback time and action dispatch

`fn_802603E8`, `802603E8..80260724`, is reconstructed in
`src/Game/callback_time_dispatch.cpp`. The isolated GC 1.3.2 production object
matches all 828 retained instruction bytes and all 12 actual relocations. Its
only allocated section is the 828-byte `.text`; there are no cleanup backups,
owned literals, BSS, constructors, or exception tables. Full-build integration
and acceptance remain the integrator's responsibility.

An active dispatcher advances its tick and, unless paused, its time. It removes
due nodes from its pending chain, resolves each node's Handle, clears the Handle
through the established assignment/destructor ABI, and submits the node to its
resolved action. It then updates the audio control, resets eligible state-3
actions to state 2, and dispatches state-2 actions while advancing an inline
iterator. The filter tests preserve the original 64-bit masks `0x20000` and
`0x800000`; the returned byte reports whether an eligible action ran.

The recovered ordinary member `CallbackTimeOwner::update` preserves the native
saved registers where a free C body rotates the owner and node registers.
Caching the action count before its first loop reproduces the original CTR
loop. Naming the old iterator index before resolving the incremented cursor
preserves the required load order. An ordinary `hasFlags` member with separate
true/false returns preserves the native byte result and its final scheduling.
All unsuccessful source and compiler probes remain in the isolated directory.

The source uses partial layouts: owner cursor/action/byte flags at `00/04/08`,
time/delta/tick at `0C/10/14`, pending chain at `1C`, action count and storage at
`34/3C`; action flags/state at `38/40`; node Handle/next/time at `00/08/0C`.
The Handle has signed 8-bit generation and signed 24-bit index. Existing global
manager and audio pointers retain their original `118/144` offsets. Original
global identity and all borrowed symbol addresses remain unchanged.

This is a partial text-only TU. The shared global, two external float constants,
other functions, and surrounding data remain external and uncredited. A full
original extabindex/ctors/dtors audit finds no ownership in this extent. The
initialized-data pointer census examines every byte offset, and the active ELF
input census records all definitions and references to the unchanged entry.

The existing accepted `hierarchy_entry_control.cpp` declaration returns `void`
and ignores the returned register. It is preserved unchanged. The new definition
and dedicated header expose the recovered low-byte return; no caller source,
header, symbol, or canonical metadata was edited by this handoff.

Frozen handoff: `scratch/engine_callback_time_dispatch_20261011iz/`.
`verify.py` recompiles production source, checks full ownership and actual
relocations using the unchanged strict verifier, repeats the original full
table audit, and verifies every frozen hash.
