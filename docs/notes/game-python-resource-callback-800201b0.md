# Python resource factory callback at 800201B0

`src/Game/python_resource_callback_800201B0.cpp` reconstructs the 712-byte
callback at `800201B0..80020478`. It copies the current Python dictionary,
boxes the selected name, finds and invokes the resource factory, and resolves
fallback scene handles while retaining the original reference-count cleanup.

An inline helper captures the name value before copying the dictionary and
returns the boxed Python object. This reproduces the native register lifetime.
The fallback handles remain real C++ temporaries with their original exception
cleanup boundaries. GC/1.3.2 flags are frozen in
`config/GSQE78/candidates/game_python_resource_callback_800201B0.json`.

The unit owns 56 bytes of `extab` and 12 bytes of `extabindex`. All 50 retained
relocations resolve to their actual native targets. The compiler also emits a
weak 112-byte destructor with 52 bytes of exception metadata. The existing
strong `typed_handle_80020478.cpp` provider is selected; the backup allocations
are discarded and receive no additional credit. Private native link-map proof
and the production ELF both establish retention and discard behavior.

The standard build passes SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`,
`ninja changes` reports no regressions, the extent audit passes 5,801 source
units / 6,775 data sections, and all 66 tests pass. The native objdiff report
credits 712 code bytes and one function. It reports the 68 metadata bytes as
source-complete but does not count them as matched data because its comparison
includes the extra weak output. The native report is preserved unchanged.

Checkpoint: 1,921,584 / 2,607,776 matched code bytes (73.6867%), 7,971 / 8,803
functions, and 965,953 / 1,030,936 matched data bytes (93.6967%).
The surrounding cache callbacks, startup code and BSS remain separate work.
Evidence: `scratch/resource_cache_callback_201B0_20261020/`.
