# Engine record state and handle selection wrapper

Production integration is accepted. The canonical manifest is
`config/GSQE78/candidates/game-engine-queue-iterator.json`. The full normalized DOL
passes its original SHA-1, `ninja changes` shows no regressions, source extents
and generated progress checks pass, and all 26 unit tests pass.

`src/Game/engine_queue_iterator_80232290.c` reconstructs **three complete
adjacent original functions and 456 text bytes**, at `80232290..80232458`.
The source owns zero data. The canonical isolated handoff is
`scratch/engine_queue_iterator_20261010c/final_integration.json`, with split,
configuration, scope, and original ownership audit files alongside it. All new
paths were checked absent before creation; earlier queue handoffs remain frozen.

| Function | Bytes | Observed behavior |
| --- | ---: | --- |
| `fn_80232290` | 40 | Calls original `fn_801B353C` for the subobject at `+0C`, passing the requested count and one |
| `fn_802322B8` | 116 | Writes the four record ages, then clears flag bits `6` and sets bit `10` in each record |
| `fn_8023232C` | 300 | Assigns the supplied handle, attempts selection, and clears both handles on failure |

The owner prefix contains four `74`-byte state records at offset `20`, followed
by handles at `1F0` and `1F4`. Each state exposes only its active pointer, age,
weight, and short flags; unknown fields retain offset-based names.

Handle assignment calls original `fn_801F86C8` with minus one for the outgoing
handle, copies the complete packed word, then calls it with plus one for the
incoming handle. The selection wrapper checks original `fn_801F7EB8` and the
signed-byte result of `fn_80232458`. A successful selection returns one. On
failure, it constructs the two observed empty typed handle wrappers, assigns
them to the owner, destroys both temporaries through the original nondeleting
ABI, and returns zero. The two wrapper initializers retain their respective
two- and three-store clearing sequences after base construction.

The ordinary C++ lifetime probe reproduced all 300 entry-point bytes but also
emitted 264 bytes of unused destructor helpers. That probe is not submitted.
The production C source expresses the same initialization, reference adjustment,
and original destructor calls directly, and emits only the claimed 456 bytes.
It uses no embedded assembly, object patching, synthetic table data, or volatile
workaround. The temporary declarations preserve the original stack layout.

## Verification and integration

`python3 scratch/engine_queue_iterator_20261010c/verify.py` recompiles the
production source with standard GC/1.3.2 engine flags. It checks all allocated
sections, all three function bindings, offsets and sizes, and **15 actual
relocations**, including constructor/destructor calls and the manager address.
Every resolved byte matches the normalized original DOL. No bits are masked,
and the object emits no weak helpers, tables, constants, exception sections, or
startup records. No extra object flags or header changes are required.

Register the source as `NonMatching`, carve only `.text 80232290..80232458`,
and set all three existing `fn_...` entry-point symbols to global scope.
Central full-DOL hash and regression checks remain the final acceptance gate.

`audit.py` verifies complete original function extents and their fallback owner,
all **3,141 twelve-byte original extabindex records**, and complete original
`.ctors` and `.dtors` tables. No associated exception or startup reference
exists for these three functions. All original class data, manager storage,
constructor/destructor implementations, and neighboring text retain their
prior owners.

The state setup at `8023297C` and handle selector at `80232458` remain private
probes with instruction and register allocation differences. Their source and
comparisons are preserved without matching credit. In particular, the original
state setup clears bit `80` before setting its active flags and clears bit `8`
when the target flag requires it; the corrected probe records these masks.
