# Console callbacks and buffer lifecycle

`src/Game/logger_callbacks.cpp` reconstructs the six adjacent functions at `0x801FAFE8..0x801FB1E8` as C++. Their 512 code bytes and all 50 owned read-only data bytes match the protected original after applying 25 real ELF relocations. `scratch/game_logger_callbacks/verify.py` compiles with GC/1.3.2, `-O4,p -inline deferred -use_lmw_stmw on`, and compares every allocated section. The complete build passes the original DOL SHA-1 and native objdiff verification.

The callbacks request console mode 2, show help when no extra arguments are supplied, and clear the console. A fourth routine invokes the interpreter's update method when present. The final pair release the command list and buffer, then allocate and zero a 24 KiB buffer. Cleanup preserves the observed stores: buffer, last-line pointer, and interpreter are cleared; the command-head field is not cleared. The allocation call retains all six ABI arguments, including `Console_Z.cpp:32` metadata and alignment 4.

The private observed storage classes give the console its vtable at `0xB10` and the interpreter its vtable at offset 8. Normal C++ virtual methods reproduce the original `r12` dispatch through slot `0x1C`. Unknown fields and preceding virtual slots remain explicit placeholders; semantic names for the two virtual operations describe their observed use rather than claiming recovered original identifiers.

This fragment owns `.rodata` `0x802AD5F0..0x802AD622`: the 20-byte parameter error string, two 14-byte allocation metadata strings, and two internal alignment bytes. Bytes beginning at `0x802AD622` remain outside its ownership. The preceding interpreter command callback at `0x801FAE58` is a separate work item. The original complete translation-unit boundary is not established.

No raw assembly substitutes, instruction patching, masked comparisons, or volatile workarounds are used. The protected DOL SHA-1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.
