# Native memory-card resource and status strings

Four ordinary C++ data units reconstruct eleven existing GLOBAL `const char[]`
objects. They emit no code, helpers, constructors, destructors or relocations.
This is a partial data reconstruction; the original translation-unit boundary is
not claimed.

| Source suffix | Owned `.rodata` interval | Allocated bytes | String/NUL bytes | Natural alignment bytes |
| --- | --- | ---: | ---: | ---: |
| `802AB4A0` | `802AB4A0..802AB4F9` | 89 | 82 | 7 |
| `802AB598` | `802AB598..802AB60B` | 115 | 109 | 6 |
| `802AB2B0` | `802AB2B0..802AB2C4` | 20 | 20 | 0 |
| `802AB2C8` | `802AB2C8..802AB2DF` | 23 | 23 | 0 |

The two groups contain independent original strings with their existing native
names and exact original object sizes. Compiler-generated internal gaps follow
ordinary four-byte object alignment, contain original zero bytes, and are
inventoried separately. There are no dummy objects, explicit padding fields,
alignment directives, byte-array scaffolds or aliases. The section alignment is
naturally eight bytes. The two single-string units avoid an additional original
four-byte gap that the grouped diagnostic did not reproduce; that failed probe
remains private and uncredited.

The strings are `MSG_MC_OVERWRITE_CONFIRMATION`, `MSG_MC_SAVING`,
`SaveFile returned %d`, `Ending CheckSave`, `UNDEFINED FORMAT ERROR`,
`MSG_MC_FORMAT_COMPLETE`, `MSG_MC_DELETING_FILE`, `MSG_MC_DELETE_COMPLETE`,
`MSG_MC_WARN_MANAGE`, `Corrupted Save Game`, and `Begin AccessingForSave`.
Every array contains precisely its printable text and final NUL.

The preflight verifies all eleven existing native ELF identities (GLOBAL OBJECT,
`.rodata`, exact address and size), original bytes, and absence of canonical or
C/C++ split ownership. Its recursive canonical scan checks both `sections` and
older `splits` schemas. The original strong data owner is
`auto_06_802A2418_rodata.o`; all other data in that original unit stays outside
these sources.

The complete original/current input census covers 10,391 ELF inputs and 204,101
allocated relocations. Each string has one original and one accepted-source
HA/LO pair: 44 union relocation records total, 22 original and 22 active. Every
reference names the exact original string with zero addend. No relocation points
into alignment bytes or outside a named object's extent. The scan of 501,416
initialized DOL byte positions finds no pointer into the strings or their gaps.
All words of all 3,144 exception-index, 24 constructor and eight destructor
records have been checked, with no references to these ranges.

Fresh production compiles reproduce all 247 allocated bytes and every defined
symbol. The unchanged strict ELF verifier resolves all actual relocations (none
are emitted) and compares the entire owned sections, including the 13 natural
alignment bytes. A supplemental inventory guard rejects extra allocations,
zero-sized aliases, incorrect alignment and incomplete byte ownership. Four
positive fixtures and twenty adverse raw allocation/native identity mutations
pass their expected outcomes.

Final integration remains root-owned. Both full native ELFs and maps must retain
all eleven original GLOBAL identities at the exact addresses and sizes; all
owned bytes, adjacent original strings and original-only trailing gaps must stay
exact, and the original DOL hash and all existing gates must pass. This handoff
credits zero functions and zero code bytes. This producer note is frozen;
acceptance updates belong in a separate note.
