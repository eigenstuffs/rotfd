# Scene binding and callback controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two isolated production units match their complete original allocations and actual relocations. Integrated production acceptance has passed.

`800E13F4` binds the returned native Handle to the owner, clears bit zero of its 64-bit flags and invokes the original setup routine. Ordinary return-by-value Handle lifetime and the existing native destructor reproduce all 132 code bytes and 36 exception-table/index bytes. `800E33A8` performs the original owner setup, resolves its generation-checked Handle and initializes the resolved actor callback group; all 124 code bytes and 20 exception-table/index bytes match. Both use native `-proc 750` and emit no additional weak definitions, data, padding, aliases or startup allocations.

All original extabindex/startup-table entries and initialized-data word references are audited. Borrowed manager data and every existing constructor, destructor and callback identity stay external. Fresh production recompilation checks every allocated byte, symbol extent and actual relocation.

The adjacent `800E8130` large local registration routine remains private. The native base-constructor/derived-destructor typed view reproduces all 152 text bytes and the large stack frame, but two bytes in the original exception action differ. The existing supported DESTROYLOCALCOND alignment-cleanup gate does not cover action 0x11, so it is not used for this routine. No source or metadata credit is claimed for that investigation.
