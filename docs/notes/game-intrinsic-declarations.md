# Reciprocal-estimate intrinsic declaration investigation

No source or matching credit is claimed. This bounded research is preserved in `scratch/game_intrinsic_declarations_continuation`, with reproducible `probe.py` and `audit.py`, every input source, compiler diagnostics, successful object and disassembly, and `report.json`. The report freezes compiler and source SHA256, exact commands, allocated-section hashes, emitted symbols, and actual ELF relocations. No assembly was added and no comparison was masked.

The compiler is the workspace's `GC/1.3.2/mwcceppc.exe`, using `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -Cpp_exceptions off`. Twenty minimal C/C++ variants test `float estimate(float x) { return __fres(__frsqrte(x)); }`.

Both C and C++ with no declarations recognize compiler built-ins, producing the same 16-byte body as the standard `double __frsqrte(double); float __fres(float);` prototypes:

```
frsqrte f0, f1
frsp    f0, f0
fres    f1, f0
blr
```

These successful bodies have no allocated data or external relocations. The intermediate rounding is real emitted code.

Redeclaring `__fres` with a double input and C linkage, with either float or double result, fails with `illegal function overloading` in C++; the analogous C declarations also fail. C empty-parameter declarations fail because the known `float (float)` built-in is redeclared as `float (...)`. Changing `__frsqrte` to return float also fails.

A C++ declaration without C linkage permits the distinct overload `float __fres(double)` or `double __fres(double)`. This is an ordinary external call: the object contains a genuine branch relocation to `__fres__Fd`, not a reciprocal-estimate instruction. The float-return variant has a 36-byte body; the double-return variant adds a final rounding instruction and has 40 bytes. These are not substitutes for the original inline instruction pair.

The accepted pragma spellings `intrinsic(__frsqrte, __fres)`, `intrinsic __frsqrte` / `intrinsic __fres`, and `intrinsic on` do not change the emitted standard body. They produce no pragma-specific diagnostics, which does not establish that the compiler implements those pragmas. `gecko_float_typecons on`, `gecko_float_typecons off`, and `fp_contract on` also leave the same intermediate `frsp`. Combining typecons-on with the incompatible C-linkage double-input declaration still fails.

The original geometry functions often use `frsqrte f4,...` followed immediately by `fres`, with no intermediate rounding. These declaration-only alternatives do not reproduce that behavior or its fixed scratch register. The geometry, audio and other reciprocal-estimate families therefore remain uncredited; their original ownership is unchanged. Earlier full-function probes are preserved in `scratch/game_engine_geometry_update_continuation` and `scratch/game_platform_audio_update`.
