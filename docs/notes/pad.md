# Dolphin controller driver

`src/dolphin/pad/pad.c` recovers all 20 linked C functions at `0x800FCF94..0x800FEB1C` (7,048 bytes). These implement device-origin calibration, wireless probing, controller status decoding, motor control, reset participation, and sampling callbacks. No assembly fallback is needed in this unit.

| Function | Address | Size | Scope |
| --- | --- | --- | --- |
| UpdateOrigin | 0x800FCF94 | 0x1A4 | local |
| PADOriginCallback | 0x800FD138 | 0xC4 | local |
| PADOriginUpdateCallback | 0x800FD1FC | 0xC0 | local |
| PADProbeCallback | 0x800FD2BC | 0xD8 | local |
| PADTypeAndStatusCallback | 0x800FD394 | 0x32C | local |
| PADReceiveCheckCallback | 0x800FD6C0 | 0x134 | local |
| PADReset | 0x800FD7F4 | 0x100 | global |
| PADRecalibrate | 0x800FD8F4 | 0x104 | global |
| PADInit | 0x800FD9F8 | 0x218 | global |
| PADRead | 0x800FDC10 | 0x3AC | global |
| PADControlAllMotors | 0x800FDFBC | 0xB8 | global |
| PADControlMotor | 0x800FE074 | 0xA4 | global |
| PADSetSpec | 0x800FE118 | 0x60 | global |
| SPEC0_MakeStatus | 0x800FE178 | 0x174 | local |
| SPEC1_MakeStatus | 0x800FE2EC | 0x174 | local |
| SPEC2_MakeStatus | 0x800FE460 | 0x3F8 | local |
| OnReset | 0x800FE858 | 0x194 | local |
| SamplingHandler | 0x800FE9EC | 0x60 | local |
| PADSetSamplingCallback | 0x800FEA4C | 0x54 | global |
| __PADDisableRecalibration | 0x800FEAA0 | 0x7C | global |

The [Pikmin 2 controller reconstruction](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/pad/Pad.c) provides the retained algorithms and state declarations. The target identifies its September 5, 2002 release. It predates the reference's barrel-controller handling and the `GameChoice` bit 0x20 override that disables motor commands. Those later branches and `BarrelBits` state are omitted. The remaining source matches all original operations, including the earlier status-decoding and origin calibration paths.

The [Melee controller reconstruction](https://github.com/doldecomp/melee/blob/master/extern/dolphin/src/dolphin/pad/pad.c) corroborates the older behavior and supplies the explicit `GameChoice &= 0xBF` expression: its narrower mask generates the original immediate AND and instruction order. Helpers that are only inlined in this image are explicitly marked inline; retained `PADReset`, `PADRecalibrate`, and `PADSync` calls also inline where the compiler chooses, preserving the original larger callers. Unlinked APIs and reference placeholders are omitted. The local header retains the exact 12-byte controller record, callback signatures, 64-bit time type, low-memory bindings, and SI constants.

`.data` is `0x802CA880..0x802CA8D8` (88 bytes): the 69-byte version string, three padding bytes, and a 16-byte reset-function record. `.sdata` is `0x80375D38..0x80375D58` (32 bytes), eight four-byte values including the version and status-decoder pointers. `.bss` is `0x803198D0..0x80319920` (80 bytes), comprising the four device types, four 12-byte origins, and four probe commands. `.sbss` is `0x80377A98..0x80377AC0` (40 bytes), ten four-byte values including the inline reset callback's static flag. All sections have alignment 8; the manifest records each private symbol's local scope. No literal or object is represented by a larger inferred blob.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| @1 | .data | 0x802CA880 | 0x45 |
| ResetFunctionInfo | .data | 0x802CA8C8 | 0x10 |
| Type | .bss | 0x803198D0 | 0x10 |
| Origin | .bss | 0x803198E0 | 0x30 |
| CmdProbeDevice | .bss | 0x80319910 | 0x10 |
| __PADVersion | .sdata | 0x80375D38 | 0x4 |
| ResettingChan | .sdata | 0x80375D3C | 0x4 |
| XPatchBits | .sdata | 0x80375D40 | 0x4 |
| AnalogMode | .sdata | 0x80375D44 | 0x4 |
| Spec | .sdata | 0x80375D48 | 0x4 |
| MakeStatus | .sdata | 0x80375D4C | 0x4 |
| CmdReadOrigin | .sdata | 0x80375D50 | 0x4 |
| CmdCalibrate | .sdata | 0x80375D54 | 0x4 |
| Initialized | .sbss | 0x80377A98 | 0x4 |
| EnabledBits | .sbss | 0x80377A9C | 0x4 |
| ResettingBits | .sbss | 0x80377AA0 | 0x4 |
| RecalibrateBits | .sbss | 0x80377AA4 | 0x4 |
| WaitingBits | .sbss | 0x80377AA8 | 0x4 |
| CheckingBits | .sbss | 0x80377AAC | 0x4 |
| PendingBits | .sbss | 0x80377AB0 | 0x4 |
| SamplingCallback | .sbss | 0x80377AB4 | 0x4 |
| recalibrated$370 | .sbss | 0x80377AB8 | 0x4 |
| __PADSpec | .sbss | 0x80377ABC | 0x4 |

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/pad -Cpp_exceptions off`, with peephole optimization enabled. The isolated scripts in `scratch/pad` resolve all calls, pointers, hardware-address accesses, and small-data relocations, then compare 7,048/7,048 code bytes and 120/120 initialized data bytes against the original DOL. Whole-DOL SHA-1 and native objdiff remain the integration checks.
