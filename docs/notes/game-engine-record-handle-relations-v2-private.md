# Private relation lookup second pass

Uncredited ordinary C++ investigation of fn_800E9738 (932 original bytes) and fn_800E9BAC (852 bytes). The first pass remains frozen under game_engine_record_handle_relations_continuation.

Twelve additional variants use the original hidden-return handle hierarchy and signed-long bitfield, signed-byte union, or explicit signed-char tag access. Pointer-return resolver variants emit 948/868 bytes (170/152 differing instruction positions, or 175/157 with swapped equality operands). Integer-return resolvers allow common-subexpression elimination and collapse to 340/260 bytes. No variant matches either original body. The E9738 tail now uses the original two separate conditional message calls.

results.json records actual relocated primary-text comparisons; allocated_inventory.json preserves every emitted allocation and defined allocated symbol. This is diagnostic evidence only: original EH and strong override verification have not passed, and none of these bytes receive matching credit. No production source, central symbols, splits, or build settings were changed.
