# Callback object wrappers

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Eleven complete functions in nine bounded text splits reconstruct 1,124 bytes
of callback lookup and dispatch. Private prefix declarations model observed
fields and native virtual slots without emitting original tables or claiming
complete original classes. `scratch/game_callback_object_wrappers/verify.py`
checks every allocated byte, complete function extent and actual relocation.
There are no extra helpers, data, BSS, exception sections, or padding.

- `80252DE0` (60): dispatch a nonnegative indexed 24-byte record to the original
  helper with mode one.
- `80253540` and `802535D8` (68 each): set callback mode four, then invoke the
  global dispatch object's virtual slot `20` with mode two. Its observed table
  pointer is at offset `B10`.
- `80254E90` and `80254F00` (112 each): resolve a signed 8-bit generation and
  signed 24-bit index handle against the global 16-byte entry table, then pass
  the receiver's `+64` member to the original resolved-object helper.
- `802550CC` (116): resolve the receiver's `+64` handle and forward the incoming
  second argument to virtual slot `48`. Native code preserves incoming `r4`
  throughout lookup; the zero-argument probe has nine register differences and
  is retained uncredited.
- `802554F4` (148): invoke resolved slot `40`, then receiver slot `74`.
- `80255588` (144): set the resolved object's byte at `+24`, call its original
  helper, then invoke receiver slot `74`.
- `80256370` (92): call original setup/key filtering and clear state mask
  `38000` in the observed unsigned 64-bit flag field at `+38`.
- `8025885C` (68): call original facade setup, then slot `68` with zero.
- `8025BFF8` (136): get a handle from receiver slot `78` with minus one, resolve
  it, and assign the incoming word to the result's `+20` field.

Original globals, dispatch tables, entry storage and callees retain their
existing owners. Generation mismatch returns null as in the native routines;
no added null guard changes the observed subsequent access. Central integration
must audit original exception/startup ownership and pass the full-DOL hash
and baseline regression checks before accepting these fragments.
