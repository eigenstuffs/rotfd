# Python native and indexed Handle returns

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two wrappers reconstruct 756 code bytes and 40 original exception/index bytes: 800DA150 and 800DFEFC. Production source and all allocated sections are strictly checked before central acceptance.

800DFEFC parses two Python objects, converts the receiver and integer index, invokes the native pointer-returning entry, and encodes the result with the established pointer-name helper. The reversed helper parameter order preserves native evaluation order without extending a saved register's lifetime.

800DA150 invokes the existing indexed Handle-returning entry through its genuine C++ hidden return value. The native Handle declares its constructor and destructor; a typed returned Handle has an empty derived destructor, which correctly performs non-deleting base destruction with flag zero. A signed 24-bit index and signed generation byte resolve the manager entry; the resolved pointer survives the end of the Handle full expression, then becomes a Python pointer name or None.

The compiler also emits one unused weak typed destructor and its associated exception/index records. These bytes earn no credit. Their complete allocations, raw hashes, actual relocations and category/group metadata are frozen through the existing bounded backup audit with an empty strong-override set. Final native linking must prove that the helper and all its metadata are absent; primary bytes and all original startup/exception table ownership remain exact. No expected hash or original input changes are permitted.
