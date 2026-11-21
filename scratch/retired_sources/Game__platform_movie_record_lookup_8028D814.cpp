/* Movie audio DMA worker thread (8028D814..8028D8BC).
 *
 * Waits on the DMA-ready semaphore at storage offset 4648, records the
 * current audio address, and when a transfer is pending DMAs from that
 * address up to the active buffer record's end (32-byte aligned length),
 * then polls until the transfer completes.  If the other audio address
 * equals the transferred one, the DMA-available semaphore at 4654 is
 * signalled.
 *
 * The original translation unit kept the threads, stacks, semaphores and
 * the two 0x30-byte buffer records as separate pooled BSS objects, so the
 * record array address was materialised as pool base + 0x4660 at the use
 * and not folded into the load displacement.  This unit references the
 * shared storage label instead; the record pointer and offset are kept in
 * locals behind a constant-folded branch so CodeWarrior neither forwards
 * nor hoists the record address, which reproduces the pooled code exactly.
 */
typedef unsigned long u32;

struct MovieBufferRecord {
    u32 word00;
    u32 end04;
    char unknown08[0x28];
};
typedef char CheckMovieBufferRecord[sizeof(MovieBufferRecord) == 0x30 ? 1 : -1];

extern "C" {
    extern char lbl_8036E9D0[];  /* movie thread/semaphore/buffer storage */
    extern int lbl_803780EC;     /* DMA request pending */
    extern u32 lbl_80378130;     /* current audio buffer address */
    extern u32 lbl_80378134;     /* other audio buffer address */
    extern u32 lbl_80378138;     /* address of the transfer in progress */
    extern u32 lbl_8037813C;     /* DMA byte count */
    extern int lbl_80378148;     /* active buffer record index */
    int OSWaitSemaphore(void*);
    int OSSignalSemaphore(void*);
    void AIInitDMA(u32, u32);
    void DCStoreRange(void*, u32);
    void AIStartDMA();
    u32 AIGetDMABytesLeft();
}

extern "C" void* fn_8028D814(void*)
{
    char* base = lbl_8036E9D0;
    while (1) {
        OSWaitSemaphore(base + 0x4648);
        int pending = lbl_803780EC;
        u32 address = lbl_80378130;
        int index = lbl_80378148;
        lbl_80378138 = address;
        if (!pending)
            continue;
        int valid = 1;
        MovieBufferRecord* records = (MovieBufferRecord*)(base + 0x4660);
        u32 offset = index * sizeof(MovieBufferRecord);
        u32 end = valid ? ((MovieBufferRecord*)((char*)records + offset))->end04 : 0;
        lbl_8037813C = end - address;
        AIInitDMA(address, lbl_8037813C & ~31UL);
        DCStoreRange((void*)address, lbl_8037813C);
        AIStartDMA();
        lbl_803780EC = 0;
        while (AIGetDMABytesLeft() != 0) {}
        if (lbl_80378134 == lbl_80378138)
            OSSignalSemaphore(base + 0x4654);
        lbl_80378138 = 0;
    }
}
