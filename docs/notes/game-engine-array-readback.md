# Engine dynamic-array readback and occupancy reset

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: two units/functions, 876 retained text bytes, zero data bytes, 41 actual relocations. Both preserve their external names and use ordinary GC/1.3.2 Gekko hardware optimization flags, with exceptions off and no extra flags.

- `fn_801CF628`: 444 bytes, 20 actual relocations, range 0x801CF628..0x801CF7E4. Refreshes the owner through `fn_801D5338`, copies its source count at 0xA0 into the bit count at 0xE4, grows a word array at 0xD8 as needed to `(count >> 5) + 1` words, and clears its active bytes. The private bit-count member helper reproduces the original argument test before storing the count and the subsequent field reload for the array resize.
- `fn_801CFC90`: 432 bytes, 21 actual relocations, range 0x801CFC90..0x801CFE40. Calls the existing base reader, reads a signed count through the stream cursor, resizes a 12-byte record array at owner offset 0x74, and reads its packed contents. Its empty record constructor/destructor establish the original generic array resize loops; incoming stream bytes initialize the records.

Both arrays use the existing allocator facade, preserving original old/new byte sizes and all grow, shrink, and zero-size branches. The ordinary generic `keep` argument is zero at these call sites, so growth and shrink both reserve exactly the requested element count. Private layouts only specify observed fields.

`final_integration.json` freezes source SHA256, the empty quoted-header inventories, all retained symbol extents, all emitted allocated bytes, and actual relocation targets. `final_splits.txt` and `final_config.txt` provide proposed central edits. Production sources recompile and strictly verify through `verify.py`. No helper/weak functions, initialized data, BSS, or padding are emitted. Full original table audits cover extabindex 0x80015F60..0x8001F2C0 (stride 12), constructors 0x80299920..0x80299980 (stride 4), and destructors 0x80299980..0x802999A0 (stride 4); all records for these functions are absent.

These are partial text splits. Original function `fn_801CF624` at 0x801CF624..0x801CF628 stays original assembly. The remaining functions in the original 0x801CFC8C..0x801D05D8 fragment also stay assembly. The ownership audit preserves all original ranges. Parent integration and final DOL/regression acceptance remain required.

Uncredited probes preserve `fn_801CC760` (260 bytes), which resolves serialized handles into object pointers through a two-layer native handle temporary, and `fn_801CCE04` (288 bytes), which rebinds stored handles then removes an owner key from one or both active registries. Their extents match, but genuine GPR/scheduling differences remain. All emitted weak cleanup functions in the former are separate diagnostic bytes, never credited. Private wrapper, conversion, declaration-order, and inline member variants did not give exact code. No production source was published for either, and both reservations are released.
