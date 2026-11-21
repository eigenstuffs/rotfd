// Game allocation shims: each user pointer follows a four-byte size header.
typedef unsigned long size_t;
extern "C" {
extern char lbl_8028F698[];
void *fn_8028FF24(void *, size_t);
void *fn_8028FAF4(void *, void *, size_t, size_t);
void fn_8028FD50(void *, void *, size_t);

void *malloc(size_t size) {
    size_t *block = static_cast<size_t *>(fn_8028FF24(lbl_8028F698, size + sizeof(size_t)));
    *block++ = size + sizeof(size_t);
    return block;
}
void *realloc(void *memory, size_t size) {
    memory = static_cast<char *>(memory) - sizeof(size_t);
    size_t *block = static_cast<size_t *>(fn_8028FAF4(lbl_8028F698, memory,
        *static_cast<size_t *>(memory), size + sizeof(size_t)));
    *block++ = size + sizeof(size_t);
    return block;
}
void free(void *memory) {
    size_t *block = static_cast<size_t *>(memory);
    fn_8028FD50(lbl_8028F698, block - 1, block[-1]);
}
}
