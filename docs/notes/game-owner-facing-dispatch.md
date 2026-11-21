# Owner facing dispatch

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ordinary C++ `fn_80222CFC` matches all 328 original bytes at `80222CFC..80222E44`, with 11 actual relocations. Source: `src/Game/owner_facing_dispatch.cpp`. Verifier: `python3 scratch/game_owner_facing_dispatch/verify.py`; standard GC/1.3.2 Game flags, no new headers/symbols/flags.

The dispatcher checks bit35 in owner flags30 and forwards the original arguments, index and floating-point delta to fn_8022993C when active. Otherwise a valid related handle1B0 selects the first point, and the signed-byte primary-property query selects the second point. The fallback computes a yaw from third-second X/Z differences, halves the angle, constructs a W/X/Y/Z rotation from cosine and a Y-axis sine, then calls owner virtual slot C0 with second point, rotation and index zero.

The handle-validity query returns an unsigned word, while the property-enabled query is consumed as signed char; these declarations reproduce unsigned comparison and byte extension. Computing the full angle into a local and multiplying that local in place reproduces the native floating-point operand order. A single combined assignment was one instruction different.

The compiler emits only the retained 328-byte text function: no weak helpers, data, BSS or padding. The strict verifier checks all allocated bytes, complete actual relocation identities and targets, original DOL SHA1, and original extabindex/ctors/dtors ownership. Evidence is frozen in `scratch/game_owner_facing_dispatch/`. Central full-DOL/native-objdiff, source extent and regression checks establish final acceptance.
