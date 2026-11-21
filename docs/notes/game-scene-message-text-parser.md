# Scene message text parser

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated production unit for `800C1D70` matches its complete 468-byte text extent and 20 original exception-table/index bytes. Integrated production acceptance has passed.

The parser seeks the opening brace, reads the named message field, collects and decodes text lines, removes the final newline, and copies the name and 255 text bytes into the indexed message record. Retaining a reference to that destination record reproduces the original pointer lifetime and final copy. Its 2048-byte initialization buffer and all small strings remain borrowed original data; this partial text-only split owns no initialized data.

Native `-proc 750`, ordinary Name construction and aggregate buffer copying reproduce the original instructions, stack temporaries and exception metadata. No extra weak definitions, data, padding, aliases, startup allocations, consumer edits or identity migrations are accepted. The complete original extabindex, constructor/destructor-table and initialized-data reference scans are recorded in `scratch/game_scene_message_text_controls/ownership_audit.json`. Fresh production recompilation verifies every allocated byte, symbol extent and actual relocation.

Adjacent escape parser `800C1F44` remains private research: its best 420-byte candidate has two differing instructions involving the initial byte conversion and move ordering. The allocator `800C2474` remains private: external-pool candidates retain one `mr` versus `addi` difference, and the original shared string pool also belongs to the unreconstructed `800C2CB8` consumer. Neither routine nor that pool receives matching source credit.
