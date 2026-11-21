/* Platform allocator state (32 bytes, zero in the DOL). Like the engine
 * context at 0x801E9D24, the original executable keeps this global inside
 * .text, directly before heap_pool_insert_before (fn_8028F6B8); allocator
 * callers pass it as the pool argument of fn_8028FAF4/fn_8028FF24/fn_8028FD50.
 * symbols.txt types it as a 0x20-byte function so dtk does not synthesize a
 * padding symbol over it. */
__declspec(section ".text") unsigned long lbl_8028F698[8];
