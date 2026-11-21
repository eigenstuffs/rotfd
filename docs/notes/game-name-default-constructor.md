# Hashed-name default constructor

`src/Game/name_default_constructor.cpp` reconstructs the 12-byte function at
`0x800A59D4..0x800A59E0` as an ordinary native C++ constructor. It stores zero
in the object's first word and preserves the native returned object pointer.
The constructor emits a strong `STB_GLOBAL/STT_FUNC` symbol,
`__ct__13Name_800A59D4Fv`, with no relocations, weak helpers, metadata or data.
`Name_800A59D4` is an address-qualified working identity.

The menu-item parser provides concrete constructor evidence: its original
`__construct_array` call uses this function pointer, a four-byte element size
and eight elements. The same parser's scalar name values are initialized to
zero, assigned hashes through `fn_801F948C`, and copied as four-byte words.
This establishes a default construction callback for that name-value storage;
it does not establish the complete original class declaration or original name.

The ordinary inline constructor in the private combined menu-parser probe emits
the same 12 bytes as a weak body. Its two retained HA/LO relocations form the
array callback pointer at `0x802149F2` and `0x80214A02`, targeting the original
`0x800A59D4`. The independent strong source owner here gives that callback a
normal native linker identity. Any later parser integration must verify the
strong/weak selection in the final ELF and exclude the duplicate weak body
from source credit. The parser itself remains uncredited while two of its
instructions differ. Its private inline declaration is a provisional view,
not a claim that original translation-unit boundaries have been recovered.

Run `python3 scratch/game_name_default_constructor/verify.py --production`.
The verifier compiles the current source with GC/1.3.2 and the established Gekko
`-O4,p -inline auto -Cpp_exceptions off` settings. It requires exactly one
12-byte allocated text section aligned to four, exactly one strong function,
no allocated relocations and byte equality with the protected original DOL.
The canonical candidate is
`config/GSQE78/candidates/game-name-default-constructor.json`.

The complete DOL hash check and native objdiff integration pass. The final ELF contains exactly one strong 12-byte native constructor at the original address. `scratch/menu_completion_link_proof.json` verifies that identity and `scratch/menu_completion_checkpoint.json` records its source credit; the combined menu parsers remain uncredited.
