# Resource cleanup and cursor serialization at 801F0518

The partial source `src/Game/resource_lifetime_801F0518.cpp` reconstructs two
complete functions at `801F0518..801F05D4`, totaling 188 bytes. The class name
is provisional; the private view records only observed fields.

`fn_801F0518` restores the original interface pointer at offset eight, calls
`fn_80243E90` with flag zero, and frees the object through the original arena
only when the signed short destruction flag is positive. It returns the
original object pointer, including the null case. `fn_801F0580` calls the
base serializer, transfers the 184-byte observed range beginning at offset
`74` through `fn_801E9F40`, and stores the returned cursor. Its range size is
expressed from the observed `74` and `EC` field boundaries plus 64 bytes.

The active original fallback `auto_03_801F0518_text` owns only 2,376 text
bytes and no data. This split owns only the first 188 bytes. Rendering,
construction, and following lifetime routines stay in the original fallback.
The 88-byte table at `lbl_802EA958` remains in original `.data`, with its
existing references to these functions. No constructor, exception, scalar
constant, BSS, or table ownership transfers to this fragment.

GC/1.3.2 with the recorded Game flags emits exactly the two original global
functions and no helpers or other allocated sections. The strict verifier
applies all eight real relocations before checking every original text byte,
and checks the two nonallocated compiler metadata references:

```
python3 scratch/game_resource_lifetime_801F0518/verify.py
```

Full executable acceptance passed: the rebuilt DOL has the original SHA-1,
`ninja changes` reports no regressions, and source-extent/progress audits pass.
All 26 unit tests pass. Any emitted unlinked weak helpers are absent from the
final ELF and receive no matching credit.
