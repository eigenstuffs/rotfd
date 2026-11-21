# Early actor named-effect reset at 80094FE8

The preserved fn_80094FE8 C entry matches 904 original text bytes at
80094FE8..80095370, 44 exception bytes at 8000F164..8000F190, and the 12-byte
index at 8001AB44..8001AB50. Strict independent production recompiles verify
all retained bytes, 36 real retained relocations, and every emitted allocation.
Parent full-game original placement/hash acceptance remains required.

The function sends actor event 20, queries the first scene mode using actor
key +90, looks up two externally named effects, and activates/repositions each
present effect from the controller's virtual position return. It copies the
Handle at +20 of the actor's related target, calls its virtual reset(-1), sets
actor flag 40000, updates related and controller objects, stops the actor,
updates mode/key state, and conditionally notifies the existing monitor.

Private views retain opaque storage. Owner controller/actor pointers are +8/+C;
context manager/scene are +118/+124; scene first mode is +15058. Objects have
vptr +8, self Handle +20, unsigned 64-bit flags +38, related Handles +58/+64,
and key +90. Monitor active pointer is +140. Manager entries +8 have 16-byte
stride with object +0 and signed generation +C; four-byte Handles contain signed
eight-bit generation and signed 24-bit index. Position returns are genuine
12-byte ordinary C++ structs through the hidden return pointer ABI. These views
establish only observed fields, not complete original classes.

The first ordinary probe matched the operation sequence and all temporary
positions. A nontrivial returned Handle view with an inline empty destructor
reproduces native base-destruction argument zero. Treating the actor's flags
as the observed 64-bit field, updated by ordinary |=0x40000ULL, reproduces
the original five-instruction low-word update rather than a shorter 32-bit
immediate operation. The final source matches every original instruction with
GC1.3.2 proc750, O4,s, inline auto, exceptions on and lmw/stmw on. No forcing,
assembly, masks, new literal pools or data padding are used.

Two retained native EH references resolve to exact accepted GLOBAL strong
Handle_8001FF78 and Handle_80027528 owners. Frozen canonical/source/recursive
headers, production objects and fresh independent recompiles verify all original
sections and actual relocations. Three weak backups are fully inventoried and
uncredited: native Handle_8001FF78 (112), native Handle_80027528 (116), and private
Returned_94FE8 (76). Together they emit 304 text and 124 EH/index bytes, with
18 backup relocations. The unchanged standard object/EH/native cores accept
this complete production object.

Actual isolated MWLD links select both accepted strong inputs and discard all
nine backup text/extab/extabindex allocations. Wrong fixture basename rejects.
Root must repeat all complete actual-game native checks and original-DOL hash.

Full original exception-index/ctors/dtors/initialized-pointer scans identify
the owned index and one unchanged external callback-table reference, with no
startup or termination ownership. Both Name literals lbl_8029DD08/lbl_8029DD28
stay external under their existing original ownership. Existing source/header
consumers and C identity remain unchanged. This is partial original TU recovery;
all other original functions and data retain their owners.

The isolated handoff is scratch/game_early_actor_named_effect_reset_continuation.
final_integration.json records retained ranges, raw allocated symbols and all
real relocations. verify.py recompiles the production source and accepted strong
owners; native.py preserves actual link/discard evidence; ownership_audit.json
and original_pointer_audit.json retain complete table and consumer inventories.
The new source is src/Game/early_actor_named_effect_reset_80094FE8.cpp. Split/
config files are parent proposals only. Shared metadata, accepted/protected
sources, old verifier cores and expected executable hash are unchanged.
