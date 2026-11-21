# Nested scene Handle state: 8005112C

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ordinary C++ strictly reproduces the 272 original code bytes, 8-byte exception record and 12-byte index of `fn_8005112C`. All six retained actual relocations resolve to their original targets. A separately inventoried private weak destructor emits 76 uncredited code bytes and 20 uncredited exception/index bytes with four relocations. The actual native MW linker discards all three backup allocations; a wrong fixture-input basename is rejected. Full integration, original placement and the DOL hash remain the integrator's acceptance requirements.

The routine ignores its owner argument and writes its byte argument to +0x1DC of a resolved scene node. It follows the external related service at global +0x13C to the Handle pointer at +0x1C, resolves its node, then resolves the child Handle pointer at +0x98. The unchanged `fn_8004A6C8` returns another four-byte Handle through the ordinary C++ hidden-return-pointer ABI. Its resolved node receives the byte, and the inline derived return-value destructor invokes the existing native base destructor with argument zero. The private return type establishes this observed storage and cleanup behavior; it does not claim the complete original class hierarchy.

The original second lookup returns the object word as an integer before the argument converts it back to a node pointer. This ordinary helper shape preserves the native early hidden-result address and manager register lifetime. Pointer-return lookup alternatives emitted the same 272-byte extent but differed in 19 words. Named local return values created additional copies and cleanup; those diagnostics are preserved uncredited. The minimal node view establishes storage through +0x1DC, and the related-service view through +0x1F.

| Section | Original range | Bytes |
| --- | --- | ---: |
| `.text` | 8005112C..8005123C | 272 |
| `extab` | 80009A90..80009A98 | 8 |
| `extabindex` | 80017D78..80017D84 | 12 |

The C entry, existing native Handle destructor identity, external callee and global data ownership are preserved. The complete original exception-index/startup tables and initialized-data pointer words were audited; only the owned index points to this body, with no constructor or destructor startup entries. All original source/header consumers are recorded without edits. The primary and the uncredited helper/EH/index are fully inventoried with raw hashes and real relocation targets. The unchanged standard weak-output verifier schema is sufficient; no new outer gate is needed.

Frozen evidence is under `scratch/game_early_scene_nested_state_continuation`. `verify.py NEW_DIRECTORY` recompiles the production source and rechecks every allocation and actual relocation; `native.py NEW_DIRECTORY` repeats actual linker discard proof. GC 1.3.2 uses the established space optimization flags with exceptions and lmw/stmw enabled.
