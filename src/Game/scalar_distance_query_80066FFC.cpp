/* Original scalar distance and query leaves; see docs/notes/game-scalar-distance-query-leafs.md. */
struct Object{char opaque00[0x38];unsigned long long flags;char opaque40[0x44];long value;};extern "C"long fn_80066FFC(void*ignored,const Object*target){if(target->flags&0x200000000000ULL)return target->value;return 0;}
