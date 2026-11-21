# Text record formatting

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/early_text_record_format_800a7510.cpp` reconstructs the 648-byte routine at 800A7510. It fills up to four formatting arguments by resolving the owner Handle and calling the actor query slot. For special Name keys it selects a difficulty-dependent record or the owner's saved text, records whether saved text was selected, and formats the record into the supplied output.

The record stride is D4: Name key at04, text at08, four Handles at88, four argument words at98 and an unsigned count atA8. The owner stores the record array at28, actor Handle at30, saved text/time at48/4C and selection flag at1984. All labels and floating constants remain external and retain their original ownership.

An ordinary owner `getText(index)` accessor gives the native indexed clear operation. For the source of the record-to-record copy, the nested `getRecord(found).getText()` accessors preserve the original record-pointer address sequence. All Name temporaries are genuine ordinary objects invoking the existing Name hash routine; their original stack offsets and stored results match. No register constraints or assembly are used.

The isolated GC1.3.2 O4,s/exceptions-on production object matches all648 text bytes, eight EH bytes at800108F4 and12 index bytes at8001BB1C. All23 actual allocated relocations and complete symbol extents match. No helpers, literals, BSS or padding are emitted. The dependency inventory derives only from undefined ELF symbols, while compiler-local metadata @76/@77 remains local.

Full original exception-index and startup tables pass. The complete initialized-data word scan finds only the owned exception index; there are no startup/table pointers or existing source callers. The new private header has only this production consumer. Matching credit waits for root native placement and original DOL/regression acceptance.

Frozen handoff: `scratch/game_engine_batch158/HANDOFF.md`. Repeat: `python3 scratch/game_early_text_record_format/verify.py`.
