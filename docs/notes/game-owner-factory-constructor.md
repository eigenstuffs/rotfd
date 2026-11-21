# Native callback owner constructor

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The120-byte constructor uses genuine multiple inheritance: an original32-byte ObjectsRoot base and44-byte controller base, followed by the callback-slot pointer. Ordinary C++ base construction and destruction declarations reproduce both original DESTROYBASE actions, the48-byte exception table and12-byte index. The constructor retains the original external primary and secondary table addresses, then allocates24 callback slots from original external heap/debug strings. The very first probe matches all allocated bytes and actual relocation targets without backups, helper data or synthetic padding. The source naturally emits `__ct__15Object_800F04E8Fv`; integration replaces only the provisional original `fn_800F04E8` spelling at its unchanged address and extent. No existing compiled C caller or shared header uses that provisional spelling; original assembly consumers and tables regenerate with the true constructor identity. Both native ELFs must retain the GLOBAL120-byte constructor, original48-byte exception actions/index and original strong base-destructor identities; zero duplicate provisional entries.

Full original exception/startup table descriptors and padding, every initialized byte offset for function pointers, exact symbol/instruction extents and all actual relocations pass. This partial text split preserves original external tables, literals and callers. Complete production hash, regression and native checkpoint acceptance remain required.
