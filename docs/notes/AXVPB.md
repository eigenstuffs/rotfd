# Dolphin AX voice parameter blocks

`src/dolphin/ax/AXVPB.c` recovers 17 linked C functions and 4,292 code bytes.

| Function | Address | Size |
| --- | --- | --- |
| __AXGetNumVoices | 0x80102EDC | 0x8 |
| __AXServiceVPB | 0x80102EE4 | 0x6FC |
| __AXSyncPBs | 0x801035E0 | 0x268 |
| __AXGetPBs | 0x80103848 | 0xC |
| __AXSetPBDefault | 0x80103854 | 0x3C |
| __AXVPBInit | 0x80103890 | 0x1FC |
| __AXVPBQuit | 0x80103A8C | 0x4 |
| AXSetVoiceSrcType | 0x80103A90 | 0xC4 |
| AXSetVoiceState | 0x80103B54 | 0x5C |
| AXSetVoiceType | 0x80103BB0 | 0x4C |
| AXSetVoiceAddr | 0x80103BFC | 0x110 |
| AXSetVoiceLoop | 0x80103D0C | 0x4C |
| AXSetVoiceAdpcm | 0x80103D58 | 0xA4 |
| AXSetVoiceSrc | 0x80103DFC | 0x98 |
| AXSetVoiceSrcRatio | 0x80103E94 | 0x98 |
| AXSetVoiceAdpcmLoop | 0x80103F2C | 0x6C |
| AXGetMaxDspCycles | 0x80103F98 | 0x8 |

The original voice-block stride is `0xEC` and the CPU voice object is `0x224`. Its fields match the older Melee layout through the ADPCM loop state, followed by 25 reserved halfwords. The newer TTYD header instead inserts an eight-byte low-pass-filter state and has a `0xF4` stride. The private ABI header preserves the target layout; previously recovered AX units were recompiled and remained byte-identical after the reserved-field correction.

The TTYD reconstruction supplies the matching split main/auxiliary cycle tables and most control flow. The original has no low-pass-filter branch, filter cycle surcharge or filter default store. When selectively copying address fields, this version does not copy the DSP current address back to the CPU unless none of the selective address flags is set. The source selector takes a signed type, confirmed by signed comparisons. Only the seventeen setters and service functions actually linked in the target are retained; mixer and envelope setters are absent from this range. The copy-all path explicitly transfers the same 52 words as the reference and original instructions, rather than treating the reserved tail as meaningful signal parameters.

The cycle tables occupy `.data` `0x802CA9F8..0x802CAACC` (212 bytes), alignment 8. The following 20 zero bytes before the compressor table at `0x802CAAE0` remain outside this unit. The source-ratio multiplier is the float 65536 at `.sdata2` `0x803798A0..0x803798A4`, alignment 8, followed by external four-byte padding. BSS is `0x80321580..0x80332980` (70,656 bytes), **alignment 32**, with parameter blocks, interaural-delay buffers, update words and CPU voice objects. Small BSS is `0x80377BE8..0x80377BF4` (12 bytes), alignment 8, followed by four external padding bytes. All owned state and tables are private.

References are [Melee's AX family](https://github.com/doldecomp/melee/tree/master/extern/dolphin/src/dolphin/ax) and [TTYD's AX family](https://github.com/doldecomp/ttyd/tree/main/libs/dolsdk2004/src/ax). Unchanged source files, hashes and license information are recorded under `reference/`. Differences above are derived from the original instructions and data.

| Object | Section | Address | Size |
| --- | --- | --- | --- |
| __AXSrcCycles | .data | 0x802CA9F8 | 0x14 |
| __AXMainMixCycles | .data | 0x802CAA0C | 0x40 |
| __AXAuxMixCycles | .data | 0x802CAA4C | 0x80 |
| __AXPB | .bss | 0x80321580 | 0x3B00 |
| __AXITD | .bss | 0x80325080 | 0x1000 |
| __AXUpdates | .bss | 0x80326080 | 0x4000 |
| __AXVPB | .bss | 0x8032A080 | 0x8900 |
| __AXMaxDspCycles | .sbss | 0x80377BE8 | 0x4 |
| __AXRecDspCycles | .sbss | 0x80377BEC | 0x4 |
| __AXNumVoices | .sbss | 0x80377BF0 | 0x4 |
| @179 | .sdata2 | 0x803798A0 | 0x4 |

GC/1.2.5n matches with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -i src/dolphin/ax -Cpp_exceptions off` and ordinary peephole optimization. The isolated scripts in `scratch/AXVPB` resolve applicable relocations and verify all 4,292 text bytes and 216 initialized data bytes exactly. No native assembly is introduced or counted. Whole-DOL SHA-1 and native objdiff remain the integration checks.
