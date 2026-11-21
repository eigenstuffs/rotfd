# Early scene resource event controls at 80047470

The original C entry fn_80047470 matches all 908 retained instruction bytes at
80047470..800477FC, all 116 original exception bytes at 80008FEC..80009060,
and the 12-byte index at 8001791C..80017928. Strict isolated production and
fresh recompiles verify all 58 retained actual relocations and every allocation.
Parent full original-DOL hash and native placement acceptance remain required.

The function tests event codes D2/D3/D4/D5, consumes each matching event and
forwards selectors zero/one/two/five to the existing helper. For event C4 it
checks the first scene mode's +100 state. State three sends a retained self
Handle to UI, resets the scene message, resolves the selected resource's related
node and optional controlled node, and resets that node's +318 properties.
The alternative sends two retained Handle events, selects the second UI key,
and invokes the message callback with a copied Name and event six.

Private views establish only observed offsets: self Handle +4; context manager
+118, scene +124, resource +13C, UI +164; scene first mode +15058 and message
+15060; mode state +100; message key +620; resource selected Handle pointer +1C;
node controlled Handle +70, related Handle pointer +B0 and properties +318.
Manager entries +8 have 16-byte stride with object +0 and signed generation +C.
Four-byte Handles use signed eight-bit generation/signed 24-bit index. Other
storage stays opaque and no complete original class identities are claimed.

The first ordinary probe was exact except eight stack-slot operands: three
retained Handle temporaries and a copied Name had different slot ordering.
A genuine nontrivial Name copy constructor and by-value callback argument,
with Name(Name(original external literal)), reproduce both Name objects at
stack +8/+C after Handle temporaries +18/+14/+10. This preserves the observed
pointer ABI for the nontrivially copied value. Named self-Handle references
preserve source pointers before native base constructors. No instruction forcing,
assembly, relocation masking, data padding, or entry renaming is used.

GC1.3.2 proc750, O4,s, inline auto, exceptions on and lmw/stmw on emit the exact
retained object. One 112-byte weak native Handle_80020478 backup plus 40 EH and
12 index bytes is separately inventoried and uncredited, with seven backup
relocations. All three retained weak EH references resolve to the exact accepted
GLOBAL strong original destructor. Frozen canonical/source/recursive headers,
production object and fresh recompile proofs cover every original section and
actual relocation. The unchanged standard object/EH/native cores accept it.

Actual isolated MWLD links select the accepted strong owner and discard all
three backup text/extab/extabindex allocations. Wrong fixture basename rejects.
Root must repeat full-game native selection/discard and original hash acceptance.

Complete original exception-index, constructor/destructor tables and initialized
DOL pointer scans preserve both original references: the owned exception index
and an existing external callback-table entry. No startup/termination ownership
or data pool transfers. The Name literal at original lbl_8029AB24 remains
external with its existing owner and exact address. All existing source/header
callers and the original C entry remain intact. This is a partial original
translation-unit reconstruction; all other original code/data stay outside it.

The isolated handoff is scratch/game_early_scene_resource_event_controls_continuation.
final_integration.json records retained ranges, all raw allocated symbols and
real relocations. verify.py performs independent production/strong-owner
recompiles; native.py preserves actual linker evidence; ownership_audit.json
and original_pointer_audit.json retain full-table and consumer inventories.
The proposed source is src/Game/early_scene_resource_event_controls_80047470.cpp.
Split/config files are parent proposals only. All shared metadata, accepted
sources, protected inputs, verifier cores and expected executable hash remain
unchanged. The initial probe and bounded lifetime alternatives stay preserved.
