# Texture payload stream reader and record constructor

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated batch236 reconstructs fn801C9474..801C96D8 (612 text bytes), its compiler-local56-byte jump table802EA0C0..802EA0F8, and the genuine12-byte TexturePayloadRecord constructor at801C96D8..801C96E4. Two independent production recompiles pass the unchanged all-allocated-section verifier with45 real relocations and no helpers, EH, startup, BSS or padding allocations. Full native placement and original DOL acceptance remain root's responsibility.

The reader calls Root_80207414::slot0C, reads the packed width/height/format/level header, computes format-dependent payload and palette sizes, allocates and reads the main image/palette/mipmap payloads, then optionally constructs144 twenty-byte records in a0xB4C-byte bundle and reads the bundle. The record constructor initializes only its float at+0x10 from external lbl_8037A420. Fields without behavioral evidence remain offset-named.

A single cached diagnostic-pool pointer before the base read preserves the native pool allocation. Computing signed byte count before declaring palette count gives the original saved-register lifetimes. Signed division and shifts, the pointer-difference header length and ordinary placement construction preserve the native instruction sequence and all fourteen switch destinations. The source owns only the original local jump table; its standalone eight-byte section alignment matches original802EA0C0 naturally.

Complete5579-input/119086-actual-relocation and777360-initialized-word audits found only the reader consuming the jump table, fourteen table pointers into the reader, and one external reader pointer at802EBEEC within the unchanged32-byte Bitmap_802EBEE0 vtable. Original ctor references come from this reader and assembly80261C0C; no existing compiled source/header consumers require edits. Root must rename the actual original GLOBAL fn_801C96D8 to __ct__20TexturePayloadRecordFv at the same12-byte extent. This is a genuine constructor identity migration, with no alias or extra ownership. The private verifier lookup is diagnostic until that real migration.

Full original extabindex80015F60..8001F2C0, ctors80299920..80299980 and dtors80299980..802999A0 scans contain neither function. External diagnostic pool lbl_802ACC58 (80 bytes), SDA literal lbl_8037A420 (8 bytes), Bitmap table and all other functions remain in their original owners. Frozen evidence is scratch/game_texture_payload_stream_801c9474; scratch/game_engine_batch236 contains the immutable manifest list and hashes. This unit note is mutable after central acceptance.
