# Indexed resource actions

`src/Game/resource_actions.cpp` recovers four contiguous ordinary C++ routines at `801F694C..801F6BFC`: 688 text bytes and 14 relocations. Every allocated section has been compared with the original DOL after relocation, with zero differences. No data or BSS is claimed; the original vtables and constructor float are external dependencies. The source uses GC/1.3.2 with the ordinary Game `-O4,p -inline auto -bool off` flags recorded in `config/GSQE78/candidates/game_resource_actions.json`. The central build also passed the complete original DOL SHA-1 and native objdiff code/data checks.

The routines perform indexed child-action lookup, virtual reset, owner initialization, and resolution of references in nested resource rows. Original class names and the original full translation-unit boundary remain unknown. The observed owner has an eight-byte prefix before its vtable; indexed action elements are 80 bytes and nested reference records are 12 bytes.

The lookup at `801F694C` also forwards three floating-point arguments to `801F72E4`. These are preserved in floating-point registers without explicit move instructions. Inspecting the callee identified those arguments; recovering the complete signature fixed the last two reordered instructions. An integer-only prototype would have been incomplete even though most instruction bytes already matched.

The nested reference resolver at `801F6AF8` uses typed array `operator[]` accessors. These preserve the original address calculation and the destination's lifetime across reference resolution. Replacing those accesses with direct nested pointer expressions changes register allocation and can move the destination calculation after the external call. The shared `RefArray<T>` template reproduces all instructions naturally. It updates only the six observed reference-bearing record kinds and retains the original four-byte temporary-handle lifecycle.

Verification transcript: `scratch/game_file_io/resource_actions_verification.txt`. Recompile the source and run `python3 scratch/game_file_io/verify.py resource_actions` to repeat the complete owned-section comparison. This script only regenerates the candidate manifest; it does not change the original DOL or central build configuration. The original SHA-1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

## Resource decoding and row resizing

`resource_decode.cpp` owns `801F6BFC..801F6F04` (776 text bytes, 30 relocations); `resource_resize.cpp` owns `801F6F04..801F7154` (592 text bytes, 21 relocations). Both match every retained allocated section after relocation. No data or BSS is claimed. Their individual candidate manifests record the compiler flags and exact function extents. The central build passed the complete original DOL SHA-1 and native objdiff code/data checks for both.

The decoder reads row and entry counts, grows the nested arrays, decodes three string-bearing entry kinds, interns their names, and resolves the following field. The original fixed 128-byte local buffer and unchecked length are preserved. Inspection of `801B4C30` confirms that its interface takes only the context and string arguments. The length and zero terminator present in other argument registers are incidental values, not additional call arguments. Correcting this prototype reproduced the original register allocation throughout the function.

The resize routine preserves or replaces capacity according to its third argument, placement-constructs new rows, and destroys removed rows and their nested arrays. Ordinary template constructors/destructors produce the original empty element loops and nested pointer checks. The compiler additionally emits an unreferenced 208-byte local inline destructor in the resize object. The candidate records it under `unretained_functions`; isolated verification proves no retained allocated section refers to it. The central linker discarded this helper normally, as with other recovered inline/template bodies. It is excluded from matched progress.

These two partial source units use local names for the observed layouts and preserve an external call boundary between decoding and resizing; the complete original C++ type identities and source boundary are not claimed.

Verification transcripts: `scratch/game_file_io/resource_decode_verification.txt` and `resource_resize_verification.txt`. The timed action query beginning at `801F72E4` remains under reconstruction.

## Reference marking

`resource_release.cpp` recovers `801F7154..801F72E4`: 400 text bytes and eight relocations, all allocated sections exact. The function retains referenced object handles and invokes their virtual release/mark operation after checking their generation, or marks the indexed string entry for the three string-bearing types. The signed 24-bit handle index and signed generation bytes reproduce the original extraction and comparison. The central build passed the complete original DOL SHA-1 and native objdiff code/data checks. Transcript: `scratch/game_file_io/resource_release_verification.txt`.


## Channel state application

`resource_channels.cpp` owns three contiguous routines at `801F77A4..801F7914`: 368 text bytes, one four-byte zero float at `8037A818`, and 12 relocations. Every allocated section matches after relocation, and the central build passed the complete original DOL SHA-1 and native objdiff code/data checks. These routines decode a reference and scalar channel curve, apply the last key's state, and interpolate the current state before applying it. The original 16-byte key layout includes a short time index, scalar value, and two tangents.

The interpolation helper at `801B0AA0` writes one float through its output pointer and consumes the incoming time in `f1`. Inspection of that callee distinguishes the scalar output from a misleading three-float stack array in the initial Ghidra export. The source also preserves the implicit floating-point conditions: spelling them as comparisons with a literal zero swaps the two floating-point registers even though the condition is equivalent. Transcript: `scratch/game_file_io/resource_channels_verification.txt`.

## Remaining adjacent recovery

The timed resource query at `801F72E4` has a 636-byte C++ candidate with the original interval wrapping, forward/backward searches, record copying, and literal values recovered. `scratch/game_file_io/timing4.cpp` preserves the closest basic candidate (106 differing bytes, mostly register allocation); `timing_index_shared.cpp` reduces that to 100. The 580-byte resource destructor at `801F7560` is also semantically reconstructed; `dtor_active.cpp` currently emits 576 bytes, with the remaining word reload and register allocation unresolved. Both functions remain original fallback and are excluded from matched progress. No assembly substitutions or original-byte changes were used.
