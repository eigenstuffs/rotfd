# HUD, tile and WaterBall native strings

The isolated proposal contains 46 original GLOBAL char objects in four
read-only source runs: `8029EDF0..8029EE52` (98 bytes),
`8029EE58..8029EECB` (115 bytes), `8029EED0..8029EFF8` (296 bytes),
and `802A0178..802A024E` (214 bytes). Ordinary external `const char[]`
definitions reproduce all 723 bytes: 650 string bytes including terminators
and 73 bytes of natural four-byte alignment between objects. No source
padding objects, aliases, helpers, relocations or startup code are emitted.

Five existing original GLOBAL gaps remain outside source ownership:
`8029EDED..8029EDF0` (3), `8029EE52..8029EE58` (6),
`8029EECB..8029EED0` (5), `802A0171..802A0178` (7), and
`802A024E..802A0250` (2). Their 23 zero bytes require original-only ownership
and no source credit. The preceding `SUBTITLE` object at `8029EDE4` is
preserved, as are the opaque original objects at `8029EBF0..8029EDE4`,
`8029EFF8..802A0154`, `802A0154..802A0171`, and `802A0250` onward.
The discontinuous runs do not establish a complete original translation unit.

Historical canonical and proposed split snapshots contain no ownership
overlap. Exact native-label source history found no previous definitions.
The original DOL's complete 501,416 bytewise initialized-data positions have
35 aligned zero-addend descriptor pointers into these strings and none into
internal or external gaps. These pointers select 35 genuine eight-byte sdata
descriptors and 31 distinct data companions; four companion pointers are
originally null. All 66 borrowed providers remain outside source ownership.
The full original extabindex, constructor and destructor tables have no
references to these source runs or boundary gaps.

Four fresh production compiler objects and eight actual private MWLD links
match all source bytes, native identities and map owners. Four of those
links retain the real original `.data` and `.sdata` provider inputs, including
all 40,892 bytes and all 35 original pointer pairs. Other undefined original
providers in those private links use explicit native-address fixture bindings;
this is not a production provider or symbol migration.

The frozen static proposal is
`scratch/game_hud_tile_waterball_names_8029edf0_20261011/static_handoff.json`.
It is unregistered and earns zero source credit. Current input closure,
exact accepted-owner repartition, all original GLOBAL multiplicities and all
35 internal gap multiplicities remain pending Root's v41 stable release.
Both full-game native links, original DOL hash, denominators and regression
checks remain required before acceptance. Root alone edits shared build files.
