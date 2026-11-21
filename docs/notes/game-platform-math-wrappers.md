# Platform logarithm and clamped inverse-cosine wrappers

The partial unit `src/Game/platform_math_wrappers.cpp` owns `.text
0x80284DB0..0x80284E34`: **132 code bytes in three functions**. Its empty
platform callback, float-result logarithm wrapper and clamped inverse-cosine
wrapper reproduce every byte and all eight actual relocations using GC/1.3.2.
No data, weak helpers or padding are emitted or credited.

The inverse-cosine path compares against borrowed native float bounds and
passes the corresponding double bounds to `acos` outside the interval. The
in-range input is promoted from float and passed directly. Each result rounds
back to float; NaN follows the original comparison behavior. The logarithm
wrapper preserves the same float-to-double/result-rounding convention.
The empty callback is used by the neighboring sprite renderer; its pointer
parameters describe only the observed call ABI.

Shared constants and neighboring routines remain outside this split. Strict
proof: `scratch/game_platform_math_wrappers/verify.py --production`.
Full-build, native-objdiff, linked-symbol, regression, extent, source-assembly
and 23-test acceptance evidence is in
`scratch/platform_math_wrappers_checkpoint.json`, its linked proof and logs.
The original DOL, earlier source files and initial baseline remain unchanged.
