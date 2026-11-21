# Python name and Handle pointer bindings

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ten isolated ordinary C++ wrappers reconstruct 3,256 code bytes and 200 original exception/index bytes. The routines are 800CDD4C, 800CDE64, 800CE414, 800D91BC, 800D9E68, 800D9FDC, 800DB9FC, 800DE87C, 800DEAE4 and 800DF478. All allocated bytes and actual relocation targets match the original normalized executable in production-source probes; central acceptance remains pending.

The two name lookups construct a four-byte name key from the existing native hash entry, then copy a nested temporary for the by-value lookup call. The setter passes the constructed key by reference. The explicit nested name expression reproduces the original two distinct stack values without aliases or manual ABI thunks.

The five owner-member getters resolve a signed 24-bit Handle index and signed generation byte through the existing manager at 801E9D24+118. Entry generation is read through an ordinary signed-byte accessor. Invalid generation resolves to null; pointer results use the established Python pointer-name encoding and None reference increment.

The indexed virtual query has an optional integer default of -1 and resolves the returned Handle before pointer encoding. The integer query invokes the same virtual slot with -1 and reads the resolved object's field at offset20. Unobserved virtual slots and fields remain opaque declarations and earn no additional source credit.

Both shared Python ABI headers remain unchanged. Every routine owns its exact eight-byte exception record and twelve-byte index entry. Complete original exception/startup tables are scanned for references into retained function extents; no additional startup references or emitted helpers/data/BSS/padding occur. Near pointer-member encoding probes and earlier nonmatching named-key variants remain private and uncredited.
