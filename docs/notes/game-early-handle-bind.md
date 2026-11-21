# Early returned-handle bindings

Five frozen isolated ordinary C++ reconstructions, 2026-10-11. Central integration pending. New header `include/Game/early_handle_bind_views.h` has five verified consumers. Standard GC1.3.2 plus `-O4,s` and `-Cpp_exceptions on` throughout.

| Source suffix | Function | Text extent | Bytes | extab | extabindex |
| --- | --- | --- | ---: | --- | --- |
| 80060f84 | fn_80060F84 | 80060F84..80061044 | 192 | 8000B1BC..8000B1D4 | 80018498..800184A4 |
| 8006154c | fn_8006154C | 8006154C..8006160C | 192 | 8000B22C..8000B244 | 800184F8..80018504 |
| 80065730 | fn_80065730 | 80065730..8006579C | 108 | 8000B8BC..8000B8D4 | 8001887C..80018888 |
| 800659e4 | fn_800659E4 | 800659E4..80065A50 | 108 | 8000B93C..8000B954 | 800188F4..80018900 |
| 80065d34 | fn_80065D34 | 80065D34..80065DA0 | 108 | 8000B9BC..8000B9D4 | 8001896C..80018978 |

Production sources are `src/Game/early_handle_bind_SUFFIX.cpp`. All use the existing C-entry fn_801B52EC declared as returning genuine `Handle_801F7F10` by value. The compiler supplies its hidden result address at stack offset eight. Passing that returned value directly to a const-reference consumer creates a full-expression temporary; native cleanup calls the existing destructor with flag -1. No fake manual construction/destruction or new Handle implementation is introduced. The24-byte EH record describes the temporary and relocates its existing destructor at offset20.

The first pair look up the original external lbl_8029B9B8 name, bind via fn_8025A3C8, clear low flag bit8, call fn_8002B780, dispatch genuine virtual methods at0x5C/0x60 with0x85, and set high-word flag0x1000. The final three first invoke accepted fn_80063074, look up their original external names lbl_8029BD28/BDE0/BE98, and bind through genuine native virtual slot0x144. All existing string, function, and native Handle identities remain unchanged.

Combined: **708 text +180 EH/index =888 allocated bytes**. There are37 actual text relocations, five destructor relocations in extab, ten EH-index relocations, and five nonallocated compiler metadata refs. No extra data, BSS, weak helpers or padding.

Manifest list: `scratch/game_early_handle_bind/manifest-list.json`. Each strict `verify.py` recompiles production source, checks every allocated original byte, actual local ELF object/extents, actual relocations including extab destructor identity, and the complete original extabindex/ctors/dtors ownership tables. Original DOL SHA1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`. All production/header/evidence/verifiers frozen.

Adjacent472-byte fn80061224 flag synchronization remains private/uncredited: ordinary repeated generation resolution is optimized to reuse intermediate results, yielding416bytes/88words. This finding is preserved separately; no ownership assigned.
