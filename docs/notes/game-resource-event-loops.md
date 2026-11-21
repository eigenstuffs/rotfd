# Resource event loops at 8002BAB4

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

This partial source split reconstructs the three queued event loops (0x1B, 0x1C, and 0xDC), resource lookup, target dispatch, time threshold, and conditional resource completion. The third queue is disabled for scene state 6. It owns 972 code bytes and 20 exception/index bytes. Original external callback data and all names/literals remain outside this split.

The four-byte return wrapper preserves the native handle return ABI and inlines the inherited native base destructor. Its unused 80-byte weak destructor and 20 metadata bytes are fully inventoried, have no retained references, receive no matching credit, and require final native-link discard. Full original exception/startup descriptors, all initialized byte offsets, native C identity/consumer extents and all 39 real relocations were audited; 35 retained plus 4 discarded.

Full native DOL hash, regressions, generated progress and all repository tests remain required.
