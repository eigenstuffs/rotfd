# Logged and timed control delegates

Isolated reconstruction handoff for 17 ordinary C++ entry points: 896 text bytes, 340 original exception/index bytes and 83 actual ELF relocations. Root integration and the full original DOL hash remain pending. All provisional external entry identities are preserved.

The six 80062Axx/62Bxx message hooks call the existing variadic logger at context+0x110 using seven existing original message labels (the seventh is used by 64848). The first three ignore their incoming owner; 62BBC/BF8 return 0, and 62C34 returns -1. 64848 logs then forwards the original owner and incoming Handle pointer to the accepted 80257E04. No message or string pool is emitted, renamed, retired, or partitioned.

7F860 updates its embedded controller at +0x318 before the accepted velocity update; AF6A4/E2F40 reverse those two calls and use controller+0x1F8. These three save f31 using the original ordinary stfd/lfd convention and compile with -proc 750. The other fourteen units use the established gekko flags. All units use GC1.3.2 -O4,s, automatic inlining, exceptions on, and lmw/stmw on.

83EB0/87BDC/8CF6C/8D110 forward actor+8 and the incoming f1 to 92DAC. Existing accepted actor callers use a double delta; the original 92DAC body uses f1 in single-precision multiplication, and these declarations preserve direct f1 forwarding with no conversion. E1224/E2BF8/F0D6C delegate to the accepted signed-char-returning 7DA74 at embedded addresses +0x168/+0x318/+0x20 and ignore the result. All observed layouts are private partial views, with opaque storage elsewhere.

Every first probe, production compile, and independent fresh compile matches all emitted allocations, symbol bindings/types/sizes, and actual relocation targets. Each object emits only its original text, 8-byte exception record, and 12-byte exception index. There are no weak helpers, synthetic padding, new literals, constructors, BSS, symbol migrations, or source-specific verifier gates.

The original full extabindex, constructor, and destructor tables were scanned. Each entry owns exactly its original exception pair; no constructor or destructor pointer belongs to these units. Initialized data was scanned at every byte offset: 34 original entry-point pointers remain with their existing owners. Seven original text sections were scanned for direct branches. Every entry has a real external reference beyond its owned exception index. The source/private census and central split audit are recorded separately.

These are partial original translation-unit splits. All other functions, literals, tables and storage of the original units remain under their current assembly/source owners. Central configuration, splits, symbols, accepted source and protected files were not edited.

| Entry | Text bytes | Processor | Behavior |
| --- | ---: | --- | --- |
| `fn_80062A68` | 56 | gekko | original external diagnostic message |
| `fn_80062AA0` | 56 | gekko | original external diagnostic message |
| `fn_80062AD8` | 56 | gekko | original external diagnostic message |
| `fn_80062BBC` | 60 | gekko | original external diagnostic message |
| `fn_80062BF8` | 60 | gekko | original external diagnostic message |
| `fn_80062C34` | 60 | gekko | original external diagnostic message |
| `fn_80064848` | 88 | gekko | diagnostic then retained Handle delegation |
| `fn_8007F860` | 72 | 750 | paired controller/velocity delta forwarding |
| `fn_800AF6A4` | 68 | 750 | paired controller/velocity delta forwarding |
| `fn_800E2F40` | 68 | 750 | paired controller/velocity delta forwarding |
| `fn_80083EB0` | 36 | gekko | observed actor+8 delta forwarding |
| `fn_80087BDC` | 36 | gekko | observed actor+8 delta forwarding |
| `fn_8008CF6C` | 36 | gekko | observed actor+8 delta forwarding |
| `fn_8008D110` | 36 | gekko | observed actor+8 delta forwarding |
| `fn_800E1224` | 36 | gekko | embedded controller delta forwarding |
| `fn_800E2BF8` | 36 | gekko | embedded controller delta forwarding |
| `fn_800F0D6C` | 36 | gekko | embedded controller delta forwarding |

`final_integration.json` is the proposed compiler/ownership contract. `final_splits.txt` and `final_config.txt` are integration suggestions only. `terminal_abi_evidence.json` pins accepted terminal sources, private declarations and the original 92DAC body. `ownership_audit.json`, `original_calls_and_caller_abi.json`, per-object inventories, and the fresh verification report preserve the complete proof. `handoff.json` freezes this proposal; documentation may be refreshed after acceptance without widening any compiler authorization.
