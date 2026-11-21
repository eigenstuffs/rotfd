# Viewport render slots

Verified text-only source: `src/Game/viewport_slots.cpp`,
`0x801E1F3C..0x801E2370`, three functions and 1,076 code bytes.
It uses the verified viewport storage layout and a partial typed view for
render dispatch. This is another bounded part of `Viewport_Z.cpp`.

## Behavior

- `fn_801E1F3C` (312 bytes) searches eight slots by their resolved object
  pointers. On the first equal pointer it assigns a default, zero handle.
  Equality includes the case where both handles resolve to null; it is not
  changed to compare packed handle words.
- `fn_801E2074` (428 bytes) inserts a handle. Ordinary insertion uses the
  first vacant slot. Priority insertion uses slot 7; if it is occupied, a
  retained copy is moved to the first vacant slot found searching 6 down to
  0 before slot 7 is replaced. If all slots are occupied, replacement still
  occurs, and the displaced temporary is released at scope exit. No new
  capacity, eviction policy, or bounds behavior is invented.
- `fn_801E2220` (336 bytes) resets the record count, binds the viewport into
  the supplied context, and invokes the world helper when world and camera
  are present. It invokes engine virtual slot `0x74`, then dispatches each
  resolved render object's virtual slot `0x40`, invoking the same engine
  hook after each object. The hook's meaning remains unidentified; the
  existing `Engine::unknown_27` declaration already describes that slot.

The slot copy constructor preserves two base-layer zero stores before copy
and retain. The default constructor has three zero stores. Ordinary C++
constructors, assignment and destruction reproduce the reference accounting;
local temporary lifetime explains the original release calls. Explicit inline
empty destruction also preserves the compiler's original function order.
The partial view leaves the original canonical handle destructor and storage
constructor definitions in their existing units.

## Verification

`scratch/game_viewport_slots/verify.py --production` verifies every allocated
symbol, all 1,076 retained code bytes, and all 30 actual retained relocations.
The compiler emits another 264 bytes of unreferenced weak destructors. All
are absent from the final executable; none receive source credit. No data,
BSS, or alignment bytes are claimed by this unit. Original strings, viewport
projection/camera routines and neighboring dispatch code remain outside it.

The full DOL is byte-identical, all 634 source units match, and all 23 tests
pass. Candidate source/object hashes (631) and recorded header hashes (86)
are current. Previously linked source and the original baseline are unchanged.
Source extent, assembly and progress audits pass. Final addresses and bytes
for all eleven newly recovered viewport functions are checked in
`scratch/viewport_slots_link_proof.json`; full checkpoint and logs are under
`scratch/viewport_slots_*`.
