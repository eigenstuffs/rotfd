# Owner array resize

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/engine_owner_arrays_resize.cpp` reconstructs original C entry `fn_8022FE68`, the full `.text` extent `8022FE68..802304E0` (1,656 bytes), as ordinary C++. Its dedicated declaration is `include/Game/engine_owner_arrays_resize.h`.

The source first delegates base storage resizing to `fn_80226AEC`, then resizes five related arrays to the requested signed count. The arrays at offsets `1D0`, `1DC`, `1AC`, `1B8` and `1C4` contain 16-, 4-, 4-, 4- and 4-byte elements respectively, with count/capacity/pointer fields at successive four-byte offsets. Each changed count reallocates existing storage or allocates fresh storage through the established allocator at `lbl_8028F698`; zero releases the backing storage. Growth constructs the newly added elements and shrinkage destroys removed elements before resizing storage. Ordinary empty element constructors/destructors reproduce the original empty counted loops. Equal counts leave each array unchanged.

Fresh GC/1.3.2 compilation with the default Game flags (`-O4,p`, exceptions off) strictly matches all 1,656 bytes and all 91 actual relocations. The complete object contains one strong function and no weak helpers, data, BSS, exception records, startup emissions or owned padding. No forced registers, assembly, aliases or object transformations are used. Existing C entry, allocator, base-resize and external data identities are retained; no consumer migration is needed.

`scratch/engine_owner_arrays_resize_20261011em/final_integration.json` freezes source/header hashes, flags, full allocated extent, symbol inventory and actual relocation targets. Run `python3 scratch/engine_owner_arrays_resize_20261011em/verify.py` to rebuild and repeat the complete strict verification. The verifier core is copied unchanged from the accepted shutdown proof. The full original `extabindex` range `80015F60..8001F2C0`, `ctors` range `80299920..80299980`, and `dtors` range `80299980..802999A0` have no reference into this original function. Original allocator data, base routine, adjacent functions and all other sections retain their owners.

This is a frozen isolated exact handoff pending central NonMatching registration, production linking and original-DOL/native regression acceptance. No progress is credited by this private handoff alone.
