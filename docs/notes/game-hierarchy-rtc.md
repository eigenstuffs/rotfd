# Hierarchy RTC resource command

`src/Game/hierarchy_rtc_resource.cpp` recovers the full 648-byte function at
`0x80203B10..0x80203D98`, registered as `LoadRTC`. With console `argc >= 4`
(including the command token), it looks up `argv[1]` as the named `WORLD`,
builds `DB:><argv[3]>_RTC.TRTC`, looks up that resource, and resolves the
group's index. Exactly `argc == 5` uses the agent name in `argv[4]`; other
accepted counts use the default `RtcAgent_Z`. Missing
handles or a negative group index return zero; the completed path returns one.

The original argument count, string pointers and parsed numeric values use the
established [console argument layout](console-argument-layout.md). The RTC id
in `values[2]` at `0x8BC` is converted to an integer and decremented before
forwarding, without an added numeric-validity check. Ordinary scoped C++
handles reproduce every early-return cleanup path, including the native returned-handle deletion flags.
The final name argument is a const reference: passing it by value adds two
copies and enlarges the original stack frame. The private declaration preserves
the verified pointer ABI of the existing `fn_80206F14` forwarding function.

All literals remain external original storage: `WORLD` at `0x8037A918`, `DB:>`
at `0x8037A920`, `_RTC.TRTC` at `0x802AD958`, and `RtcAgent_Z` at `0x802AD964`.
No literal, data, metadata, or padding bytes are claimed by this source.

`scratch/game_hierarchy_rtc/verify.py` uses GC/1.3.2 with `-O4,p`, `-inline auto`,
and `-use_lmw_stmw on`. It resolves all 38 retained relocations and compares all
648 retained instruction bytes against the SHA-1-checked original DOL. Two
unused weak wrapper destructors total 172 bytes; all four helper relocations,
their exact extents and bindings, and the absence of retained references are
checked before exclusion through ordinary linker dead stripping.

The candidate is `config/GSQE78/candidates/game_hierarchy_rtc_resource.json`.
Full-DOL and native objdiff integration pass: one function and all 648 code
bytes, with no owned data. The original executable hash and direct byte
comparison pass, as does the source-section extent guard.
