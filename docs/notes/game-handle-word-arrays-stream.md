# Handle and word array stream reader

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_801CC864..801CCE04` is reconstructed as ordinary C++ in
`src/Game/handle_word_arrays_stream_801CC864.cpp`. Isolated GC1.3.2
Gekko/O4,p/exceptions-off compilation matches all1,440 original text bytes and
89 retained actual relocation targets. Root's full native link remains the
acceptance boundary.

The owner reads its native base, resizes a two-layer Handle array at0x20,
reads each Handle through the registry, and copies the previous Handle when a
lookup returns null. It then reads fixed ranges0x2C..0x4C and0xC0..0x104,
three registry names, an unsigned heap-backed word buffer at0x110 and a typed
word array at0x11C. Genuine copy assignment and the array's inline subscript
operator reproduce the original saved-register allocation. Representing the
last fixed range with its trailing Vector3 reproduces the native range
arithmetic.

The compiler additionally emits one unused84-byte weak destructor,
`__dt__20HandleWordStreamZeroFv`, with two actual relocations. It has no retained
reference and receives no credit. The unchanged strict verifier accounts for
it as contiguous trailing weak text. Both complete native ELFs must discard
this helper and its allocation; no retained EH exists.

Original extabindex, constructor and destructor tables have no ownership in
this function. The complete active ELF scan covers5,570 inputs and119,086
actual relocations. The777,360-word original initialized-section scan finds
two data pointers to the entry:802EA2EC in the external
`__vt__23SpatialHandles_802EA2E0[80]`, and802ED184 in external
`lbl_802ED178[76]`. Both original table identities and allocations remain
external. There are no compiled source consumers requiring migration and no
literal, data, BSS, startup or padding ownership transfers.

Evidence and isolated replay are preserved in
`scratch/game_handle_word_arrays_stream_801cc864/`; batch228 contains the
immutable handoff manifest and hashes. No central files were changed by the
agent.
