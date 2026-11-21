# Handle list operations

`src/Game/handle_list_operations.cpp` reconstructs two consecutive functions
at `80267FCC..80268194`, totaling 456 code bytes:

| Entry | Size | Observed operation |
| --- | ---: | --- |
| `fn_80267FCC` | 180 | Apply `fn_801EE978` to every live list handle |
| `fn_80268080` | 276 | Find a list handle by its object's related handle |

The native object has an array at `C100`, with count/capacity/data fields at
`C100/C104/C108`. Its handles use the established signed generation/index
8/24-bit layout. The original global at `801E9D24` holds a manager pointer at
`118`; the manager's entries pointer is at `08`. Each 16-byte entry has the
object pointer at `00` and generation byte at `0C`. The object's related
handle is at `20`. All descriptive names remain inferred.

The release loop checks each handle through `fn_801F7EB8`, then resolves the
handle inline and invokes `fn_801EE978`. The lookup first resolves the current
list object, then the target handle and that object's related handle. Pointer
equality establishes a match. It returns the list's data pointer if no match
is found, preserving the original behavior. Explicit local pointers in the
comparison helper preserve the observed evaluation and register order.

GC/1.3.2 with standard optimized Game flags emits exactly 456 text bytes,
two global functions and six actual relocations. The strict verifier applies
both call relocations and four address halves for the original manager global
and compares the entire allocation against the verified original DOL:

```
python3 scratch/game_handle_list_operations/verify.py
```

The object emits no additional function, weak symbol, constant, data, BSS,
constructor table, destructor table, exception table or alignment padding.
Original assembly references are ordinary calls and definitions, with no
constructor-table entry to transfer. `candidate.json` and the applied
relocation inventory are preserved in the same scratch directory.

This split is integrated and passes the original DOL SHA-1 and native objdiff. The split owns
only these text functions; neighboring code and all original data remain
outside it. No original translation-unit boundary is claimed.
