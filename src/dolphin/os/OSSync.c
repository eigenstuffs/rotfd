typedef unsigned long u32;
extern void __OSSystemCallVectorStart(void), __OSSystemCallVectorEnd(void);
extern void *memcpy(void *, const void *, unsigned long);
extern void DCFlushRangeNoSync(void *, u32), ICInvalidateRange(void *, u32);
#define OSPhysicalToCached(address) ((void *)((u32)(address) + 0x80000000))

void __OSInitSystemCall(void) {
    void *addr = (void*)OSPhysicalToCached(0xC00);

    memcpy(addr, __OSSystemCallVectorStart, (u32)&__OSSystemCallVectorEnd - (u32)&__OSSystemCallVectorStart);
    DCFlushRangeNoSync(addr, 0x100);
    __sync();
    ICInvalidateRange(addr, 0x100);
}
