# Bitmap pixel conversion

Current status: the split also includes exact 176-byte source for
`fn_802380D0`; see [bitmap color decode](game-bitmap-color-decode-802380d0.md).
The enlarged 1,248-byte text section and retained 56-byte table match in
the full native build, which passes the original DOL hash and current
regression checks. The integration instructions below describe the earlier
1,072-byte checkpoint.

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Isolated ordinary C++ in `src/Game/engine_bitmap_convert.cpp` matches fn80237CA0 at `80237CA0..802380D0`, all 1,072 text bytes, and the complete 56-byte compiler-generated jump table at `802EBF00..802EBF38`. GC 1.3.2 with the default Game flags plus `-use_lmw_stmw on` emits exactly those two allocations: one strong function and one local data object, with no weak helper or other allocated section. All 23 actual relocations match their original resolved targets, including the fourteen local table entries. Full production executable acceptance remains with the root integrator.

The entry allocates four output bytes per pixel and selects the conversion through the bitmap format byte at 3C. Format1 expands two four-bit palette indices per input byte. Format2 traverses eight-by-four tiles and expands indexed pixels using the palette format byte at 3E. Formats7,8 and10 expand packed sixteen-bit channels, format13 expands three-byte colors with opaque alpha, and format12 copies four-byte pixels. Unsupported format codes return the allocated result without writing pixels. Dimensions at30/34 and palette/data pointers at10/0C are retained in the dedicated partial storage view. The source preserves the original byte truncation, channel shifts and unsigned tile-loop comparisons. The palette channel locals intentionally retain their prior values if the palette format is unsupported, as in the original; valid palette formats assign all four channels.

The first probe used byte channel locals, which emitted seven additional merge moves. Ordinary integer channel locals remove those moves, and their reverse declaration order reproduces the original saved-register allocation. Separating the final copy loop's input increment from its output assignment restores the original two-instruction ordering. All earlier probes remain preserved without credit.

The original local `jumptable_802EBF00` is referenced only by the retained function at37CF4 and37CFC. `original_reference_audit.json` records the two current active assembly references, the single current data allocation, stale cached duplicate assembly separately, and zero current source/header references to the old table spelling. The compiler emits this table naturally as local `@84`; central integration should guard the original object identity and retain its exact address, size, alignment and local unit scope. No alias or compiler-object payload change is proposed. The original allocator strings at2AEA60/2AEA70 and all other external objects retain their current owners.

The frozen manifest is `scratch/engine_bitmap_convert_20261011ej/final_integration.json`. Its unchanged strict ELF verifier checks every allocated byte, exact complete symbol inventory and actual relocation sequence. The original table audit scans all extabindex `80015F60..8001F2C0`, ctors `80299920..80299980` and dtors `80299980..802999A0`, including descriptors, padding and terminators; none refers to this retained function. There is no emitted BSS, owned padding, exception table or startup allocation. The isolated repeat additionally checks frozen production, header and research hashes.

This is a partial text/data split. Adjacent routines and the rest of the original translation-unit data remain outside it. Central registration should begin as NonMatching, apply the audited local-table identity ownership, and promote only after the original full DOL hash and standard acceptance checks pass.
