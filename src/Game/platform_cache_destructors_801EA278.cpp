#include "Game/platform_cache_internal.h"

struct CacheNodeIndex {
    unsigned int value;
    CacheNodeIndex(unsigned int v) : value(v) {}
    operator const unsigned int&() const { return value; }
};

Cache10_802F1490::~Cache10_802F1490() {
    unlink(1);
    prepend(1);
    void* allocation = blocks[0].data;
    for (unsigned short i = 0; i < 10; ++i) {
        const CacheNodeIndex node = i + 1;
        unlink(node);
        prepend(node);
        blocks[i * stride].clear();
    }
    fn_801EF610(lbl_801EF5C8, allocation);
}

Cache900_802F149C::~Cache900_802F149C() {
    unlink(1);
    prepend(1);
    void* allocation = blocks[0].data;
    for (unsigned short i = 0; i < 900; ++i) {
        const CacheNodeIndex node = i + 1;
        unlink(node);
        prepend(node);
        blocks[i * stride].clear();
    }
    fn_801EF610(lbl_801EF5C8, allocation);
}
