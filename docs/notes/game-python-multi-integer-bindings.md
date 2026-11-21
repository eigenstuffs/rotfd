# Python multiple integer and object arguments

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Twenty-seven ordinary C++ wrappers match 6,152 original text bytes, 540 exception metadata bytes and 377 actual relocations. All original C entry names are retained. Sources and both shared Python ABI headers are frozen by SHA256; complete original exception/startup tables are audited. No additional helpers, data, BSS or padding are emitted.

The wrappers preserve original parse formats, converted type-table entries, native argument order, signed scalar widths and optional integer defaults. Integer conversion events stay in their observed order relative to native object conversion. Declaring required integer values before the optional value preserves their distinct register lifetimes across conversion calls; initial five/seven-instruction register rotations remain in the private evidence.

Game player insertion passes a four-byte native word by value through an ordinary nontrivial copy constructor. This emits the observed hidden temporary pointer and word copy without a destructor or helper allocation. The three-object virtual method passes its converted eight-byte category by value as an unsigned long long; the resulting two argument words match exactly. Additional wrappers cover short/float pairs, named registration, message dispatch and the empty log-initialization binding.

Every retained text/extab/extabindex byte, symbol extent and real relocation matches in isolated and production-source-path compilation. Full executable acceptance remains pending central integration.
