# Actor record-key existence query

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated ordinary C++ handoff recovers `fn_8009C12C` at0x8009C12C..0x8009C228 (252 bytes) and its original60-byte exception record plus12-byte index. The query resolves its actor handle, rejects a negative record index, looks up an integer key in that record, and returns whether the retained lookup handle is valid.

GC1.3.2/Gekko/O4,s/exceptions on reproduces every retained byte and16 real relocations. The standard weak-EH gate freshly proves existing strong native Handle destructors at8001FF78/80042FA4; both exact weak backups228text+104metadata are discarded in an isolated native link. All six backup allocations and14 backup relocations are accounted.

Full original EH/ctors/dtors, initialized-pointer and active-object audits preserve all caller and native symbol identities. No extra data/BSS/startup allocation, shared header edit or consumer migration is proposed. Parent integration/full DOL acceptance remains pending. Evidence: `scratch/game_actor_record_key_exists_8009c12c/`; batch266 frozen manifest list.
