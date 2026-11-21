# Scene agent startup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`scene_agent_startup_800CCEEC.cpp` reconstructs original `800CCEEC..800CCF38`,
76 code bytes with the complete eight-byte exception record and twelve-byte
exception index. It clears the original global, calls agent setup and uses an
ordinary temporary derived agent. Its constructor and destructor both set the
original scene vtable, followed by the existing native base destruction.

The observed temporary extent is `0x90`; the reconstructed view preserves the
native base layout and opaque tail. All retained allocated bytes, extents and
actual relocation targets match. The compiler emits no unused helpers, data,
BSS, extra metadata or padding. Complete original exception/startup tables,
initialized pointers and source consumers are inventoried in
`scratch/game_scene_agent_startup/`. Borrowed vtables, the reset global and
base operations retain their original owners and identities. This is a
partial original translation unit; full production acceptance passed.
