# Hierarchy entry dispatch and replacement

`src/Game/hierarchy_entry_control.cpp` recovers two contiguous methods at
`0x80206B44..0x80206E28`: the 272-byte entry dispatch and 468-byte resource
replacement. Their full original translation unit boundary and original class
names remain unknown. Complete DOL and native objdiff integration pass: two
functions, all 740 code bytes and the 16 emitted data bytes. The original
executable hash and source-section extent guard also pass.

The dispatch method chooses the hierarchy's offset at `0xE4` when its supplied
offset is negative, or adds the supplied offset otherwise. It resolves the
indexed handle from the list at `0xD0`/`0xD4`/`0xD8`, dispatches command 30 with
the position converted to float, forwards the same position through the existing
hierarchy traversal with mask 11, and calls the global dispatcher with `0.0f`.
The conditional expression for choosing position preserves its original saved
register. Separate if/else assignments swap the position and index registers.
Keeping the generation comparison directly in the dispatch argument preserves
the original argument preparation order; an inline resolve call schedules those
arguments later.

The replacement method rejects an index outside the list, obtains a handle
from `fn_80260868`, and converts it into the observed resource handle. Three
ordinary zeroing base layers precede the copy and reference increment. A valid
result replaces the list entry, with its old reference decremented and the new
reference incremented. The method constructs an owned copy of the hierarchy
identity, applies its integer argument through `fn_8025D588`, passes the identity
to virtual slot `0x40`, and destroys the local handles.

The factory returns a nontrivial derived handle through the native hidden
result pointer. Returning the bare base handle instead changes its cleanup
argument from zero to minus one. A derived return type naturally reproduces the
original base-destructor call with zero. No explicit destructor flags or manual
stack temporaries are used in the recovered source. The virtual declaration
preserves the observed identity pointer and lifetime; the original parameter's
source spelling is not established.

## Literal ownership

The dispatch method alone consumes both constants:

| Original object | Value | Original consumers |
| --- | --- | --- |
| `0x8037A958`, four bytes | `0.0f` | `0x80206C28` |
| `0x8037A960`, eight bytes | Integer-to-float conversion bias, bits `4330000080000000` | `0x80206BDC`, `0x80206C10` |

`scratch/game_hierarchy_entry_control/literal_consumers.py` checks the untouched
DOL hash, exhausts direct SDA2 address/load/store operands throughout the text
sections, and checks every aligned DOL word for absolute pointers to either
constant. It finds exactly those three instructions and no absolute pointers.
The original disassembly identifies the same consumers.

Ordinary integer-to-float casts and the actual `0.0f` call argument naturally
emit the exact 16-byte `.sdata2` section at `0x8037A958..0x8037A968`: a four-byte
zero literal, four internal alignment bytes, and the eight-byte conversion
bias. The object definitions therefore cover 12 bytes; the remaining four are
compiler-generated alignment between the literals. There is no trailing
padding, synthetic constant declaration, fixed-address alias, or external
consumer requiring a larger source group.

## Verification

The compiler is GC/1.3.2 with `-O4,p -inline auto -Cpp_exceptions off
-use_lmw_stmw on` and standard Gekko hardware-FP flags. Reproduce with:

```sh
python3 scratch/game_hierarchy_entry_control/verify.py
```

All 740 retained code bytes, 16 emitted literal-section bytes, and 27 actual
retained ELF relocations match the original after relocation. The verifier
checks the production source hash, every function extent, literal symbol sizes,
section coverage and alignment, and the complete original pool bytes. Every
relocated byte is compared directly, without mismatch masks or subsequent byte
changes. The original DOL SHA-1 remains
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

Seven unreferenced weak handle destructors occupy 628 further code bytes and
contain 14 relocations. Their exact symbol extents and weak binding are checked;
retained references to these bodies are rejected. Normal linker dead stripping
excludes them, and they receive no source progress credit. The source emits no
BSS, exception records, or other allocated sections.

The stable manifest is
`config/GSQE78/candidates/game_hierarchy_entry_control.json`, and the transcript
is `scratch/game_hierarchy_entry_control/verification.txt`. Existing shared
sources, headers, central configuration, and original files are unchanged.
