/* MSL allocator reconstructed for GSQE78 from pinned Strikers and TWW
 * matching source references, with original target layout and retained paths.
 * License/provenance: reference/strikers-msl/, reference/tww-msl/.
 * Original text: 0x80121104..0x80121EEC.
 */
typedef unsigned long u32;
typedef unsigned char u8;
#define NULL 0
extern void *memset(void *, int, unsigned long);

void __sys_free(void*);
void* __sys_alloc(u32);

typedef struct Block
{
    struct Block* prev;
    struct Block* next;
    u32 max_size;
    u32 size;
} Block;

typedef struct SubBlock
{
    u32 size;
    Block* block;
    struct SubBlock* prev;
    struct SubBlock* next;
} SubBlock;

struct FixSubBlock;

typedef struct FixBlock
{
    struct FixBlock* prev_;
    struct FixBlock* next_;
    u32 client_size_;
    struct FixSubBlock* start_;
    u32 n_allocated_;
} FixBlock;

typedef struct FixSubBlock
{
    FixBlock* block_;
    struct FixSubBlock* next_;
} FixSubBlock;

typedef struct FixStart
{
    FixBlock* tail_;
    FixBlock* head_;
} FixStart;

typedef struct __mem_pool_obj
{
    Block* start_;
    FixStart fix_start[6];
} __mem_pool_obj;

typedef struct __mem_pool
{
    void* reserved[14];
} __mem_pool;

static inline SubBlock* SubBlock_merge_prev(SubBlock*, SubBlock**);
static void SubBlock_merge_next(SubBlock*, SubBlock**);
void Block_link(Block*, SubBlock*);
static inline Block* link_new_block(__mem_pool_obj*, u32);

#define SubBlock_size(ths)  ((ths)->size & 0xFFFFFFF8)
#define SubBlock_block(ths) ((Block*)((u32)((ths)->block) & ~0x1))
#define Block_size(ths)     ((ths)->size & 0xFFFFFFF8)
#define Block_start(ths)    (*(SubBlock**)((char*)(ths) + Block_size((ths)) - sizeof(u32)))

#define SubBlock_set_free(ths)                 \
    u32 this_size = SubBlock_size((ths));      \
    (ths)->size &= ~0x2;                       \
    *(u32*)((char*)(ths) + this_size) &= ~0x4; \
    *(u32*)((char*)(ths) + this_size - sizeof(u32)) = this_size

#define SubBlock_is_free(ths) !((ths)->size & 2)
#define SubBlock_set_size(ths, sz)    \
    (ths)->size &= ~0xFFFFFFF8;       \
    (ths)->size |= (sz) & 0xFFFFFFF8; \
    if (SubBlock_is_free((ths)))      \
    *(u32*)((char*)(ths) + (sz) - sizeof(u32)) = (sz)

#define SubBlock_from_pointer(ptr)    ((SubBlock*)((char*)(ptr) - 8))
#define FixSubBlock_from_pointer(ptr) ((FixSubBlock*)((char*)(ptr) - 4))

#define FixBlock_client_size(ths) ((ths)->client_size_)
#define FixSubBlock_size(ths)     (FixBlock_client_size((ths)->block_))

#define classify(ptr) (*(u32*)((char*)(ptr) - sizeof(u32)) & 1)
#define __msize_inline(ptr) \
    (!classify(ptr) ? FixSubBlock_size(FixSubBlock_from_pointer(ptr)) : SubBlock_size(SubBlock_from_pointer(ptr)) - 8)

#define Block_empty(ths) (_sb = (SubBlock*)((char*)(ths) + 16)), SubBlock_is_free(_sb) && SubBlock_size(_sb) == Block_size((ths)) - 24

static const u32 fix_pool_sizes[] = { 4, 12, 20, 36, 52, 68 };

#define fix_var_flag    0x01
#define this_alloc_flag 0x02

static inline void Block_construct(Block* ths, u32 size)
{
    SubBlock* sb = (SubBlock*)((char*)ths + sizeof(Block));

    ths->size = size | 3;
    *(u32*)((char*)ths + size - 8) = ths->size;
    sb->block = (Block*)((u32)ths | 1);
    sb->size = size - 24;
    *(u32*)((char*)sb + (size - 24) - sizeof(u32)) = size - 24;
    ths->max_size = size - 24;
    Block_start(ths) = NULL;

    Block_link(ths, sb);
}

static inline void SubBlock_construct(SubBlock* ths, u32 size, Block* bp, int prev_alloc, int this_alloc)
{
    ths->block = (Block*)((u32)bp | 1);
    ths->size = size;
    if (prev_alloc)
        ths->size |= 4;
    if (this_alloc)
    {
        ths->size |= 2;
        *(u32*)((char*)ths + size) |= 4;
    }
    else
    {
        *(u32*)((char*)ths + size - sizeof(u32)) = size;
    }
}

static inline SubBlock* SubBlock_split(SubBlock* ths, u32 size)
{
    u32 origsize;
    int isfree;
    int isprevalloc;
    SubBlock* np;
    Block* bp;

    origsize = SubBlock_size(ths);
    isfree = SubBlock_is_free(ths);
    isprevalloc = ths->size & 4;
    np = (SubBlock*)((char*)ths + size);
    bp = SubBlock_block(ths);

    SubBlock_construct(ths, size, bp, isprevalloc, !isfree);
    SubBlock_construct(np, origsize - size, bp, !isfree, !isfree);
    if (isfree)
    {
        np->next = ths->next;
        np->next->prev = np;
        np->prev = ths;
        ths->next = np;
    }
    return np;
}

static inline void Block_unlink(Block* ths, SubBlock* sb)
{
    SubBlock** st;
    u32 tag;
    u32 tag_size;

    tag = sb->size;
    sb->size = tag | 2;
    tag_size = tag & ~7;
    *(u32*)((char*)sb + tag_size) |= 4;

    st = &Block_start(ths);
    if (*st == sb)
        *st = sb->next;
    if (*st == sb)
    {
        *st = 0;
        ths->max_size = 0;
    }
    else
    {
        sb->next->prev = sb->prev;
        sb->prev->next = sb->next;
    }
}

static SubBlock* Block_subBlock(Block* ths, u32 size)
{
    SubBlock* sb;
    SubBlock* st;
    u32 sb_size;
    u32 max_size;

    st = Block_start(ths);

    if (st == 0)
    {
        return 0;
    }

    sb = st;
    sb_size = SubBlock_size(sb);
    max_size = sb_size;

    while (sb_size < size)
    {
        sb = sb->next;
        sb_size = SubBlock_size(sb);
        if (max_size < sb_size)
            max_size = sb_size;
        if (sb == st)
        {
            ths->max_size = max_size;
            return 0;
        }
    }

    if (sb_size - size >= 0x50)
        SubBlock_split(sb, size);

    Block_start(ths) = sb->next;
    Block_unlink(ths, sb);

    return sb;
}

static inline SubBlock* SubBlock_merge_prev(SubBlock* ths, SubBlock** start)
{
    u32 prevsz;
    SubBlock* p;

    if (!(ths->size & 0x04))
    {
        prevsz = *(u32*)((char*)ths - sizeof(u32));
        if (prevsz & 0x2)
            return ths;
        p = (SubBlock*)((char*)ths - prevsz);
        SubBlock_set_size(p, prevsz + SubBlock_size(ths));

        if (*start == ths)
            *start = (*start)->next;
        ths->next->prev = ths->prev;
        ths->next->prev->next = ths->next;
        return p;
    }
    return ths;
}

void Block_link(Block* ths, SubBlock* sb)
{
    SubBlock** st;
    SubBlock_set_free(sb);
    st = &Block_start(ths);

    if (*st != 0)
    {
        sb->prev = (*st)->prev;
        sb->prev->next = sb;
        sb->next = *st;
        (*st)->prev = sb;
        *st = sb;
        *st = SubBlock_merge_prev(*st, st);
        SubBlock_merge_next(*st, st);
    }
    else
    {
        *st = sb;
        sb->prev = sb;
        sb->next = sb;
    }
    if (ths->max_size < SubBlock_size(*st))
        ths->max_size = SubBlock_size(*st);
}

static void SubBlock_merge_next(SubBlock* pBlock, SubBlock** pStart)
{
    SubBlock* next_sub_block;
    u32 this_cur_size;

    next_sub_block = (SubBlock*)((char*)pBlock + (pBlock->size & 0xFFFFFFF8));

    if (!(next_sub_block->size & 2))
    {
        this_cur_size = (pBlock->size & 0xFFFFFFF8) + (next_sub_block->size & 0xFFFFFFF8);

        pBlock->size &= ~0xFFFFFFF8;
        pBlock->size |= this_cur_size & 0xFFFFFFF8;

        if (!(pBlock->size & 2))
        {
            *(u32*)((char*)(pBlock) + (this_cur_size)-4) = (this_cur_size);
        }

        if (!(pBlock->size & 2))
        {
            *(u32*)((char*)pBlock + this_cur_size) &= ~4;
        }
        else
        {
            *(u32*)((char*)pBlock + this_cur_size) |= 4;
        }

        if (*pStart == next_sub_block)
        {
            *pStart = (*pStart)->next;
        }

        if (*pStart == next_sub_block)
        {
            *pStart = 0;
        }

        next_sub_block->next->prev = next_sub_block->prev;
        next_sub_block->prev->next = next_sub_block->next;
    }
}

static inline Block* __unlink(__mem_pool_obj* pool_obj, Block* bp)
{
    Block* result = bp->next;
    if (result == bp)
    {
        result = 0;
    }

    if (pool_obj->start_ == bp)
    {
        pool_obj->start_ = result;
    }

    if (result != 0)
    {
        result->prev = bp->prev;
        result->prev->next = result;
    }

    bp->next = 0;
    bp->prev = 0;
    return result;
}

static inline Block* link_new_block(__mem_pool_obj* pool_obj, u32 size)
{
    Block* block;

    size = (size + 0x1f) & ~7;
    if (size < 0x10000)
    {
        size = 0x10000;
    }

    block = (Block*)__sys_alloc(size);
    if (block == NULL)
    {
        return NULL;
    }

    Block_construct(block, size);

    if (pool_obj->start_ != NULL)
    {
        block->prev = pool_obj->start_->prev;
        block->prev->next = block;
        block->next = pool_obj->start_;
        pool_obj->start_->prev = block;
        pool_obj->start_ = block;
    }
    else
    {
        pool_obj->start_ = block;
        block->prev = block;
        block->next = block;
    }

    return block;
}

static void* allocate_from_var_pools(__mem_pool_obj* pool_obj, u32 size)
{
    Block* bp;
    SubBlock* sb;

    size = (size + 0xf) & ~7;
    if (size < 0x50)
    {
        size = 0x50;
    }

    bp = pool_obj->start_ != NULL ? pool_obj->start_ : link_new_block(pool_obj, size);

    if (bp == NULL)
    {
        return NULL;
    }

    do
    {
        if (size <= bp->max_size)
        {
            sb = Block_subBlock(bp, size);
            if (sb != NULL)
            {
                pool_obj->start_ = bp;
                goto done;
            }
        }

        bp = bp->next;
    } while (bp != pool_obj->start_);

    bp = link_new_block(pool_obj, size);
    if (bp == NULL)
    {
        return NULL;
    }

    sb = Block_subBlock(bp, size);
done:
    return (char*)sb + 8;
}

static void* soft_allocate_from_var_pools(Block** start_ptr, u32 size, u32* max_free_size)
{
    Block* bp;
    SubBlock* sb;

    size = (size + 0xf) & ~7;
    if (size < 0x50)
    {
        size = 0x50;
    }

    *max_free_size = 0;
    bp = *start_ptr;

    if (bp == NULL)
    {
        return NULL;
    }

    do
    {
        if (size <= bp->max_size)
        {
            sb = Block_subBlock(bp, size);
            if (sb != NULL)
            {
                *start_ptr = bp;
                goto found;
            }
        }

        if (bp->max_size > 8)
        {
            u32 free_size = bp->max_size - 8;
            if (*max_free_size < free_size)
            {
                *max_free_size = free_size;
            }
        }

        bp = bp->next;
    } while (bp != *start_ptr);

    return NULL;

found:
    return (char*)sb + 8;
}

static inline void deallocate_from_var_pools(__mem_pool_obj* pool_obj, void* ptr)
{
    SubBlock* sb = SubBlock_from_pointer(ptr);
    SubBlock* _sb;

    Block* bp = SubBlock_block(sb);
    Block_link(bp, sb);

    if (Block_empty(bp))
    {
        __unlink(pool_obj, bp);
        __sys_free(bp);
    }
}

static inline void __init_pool_obj(__mem_pool* pool_obj)
{
    memset(pool_obj, 0, sizeof(__mem_pool_obj));
}

static inline __mem_pool* get_malloc_pool(void)
{
    static __mem_pool protopool;
    static u8 init = 0;
    if (!init)
    {
        __init_pool_obj(&protopool);
        init = 1;
    }

    return &protopool;
}

static void FixBlock_construct(FixBlock* b, FixBlock* tail, FixBlock* head, u32 index, char* first, u32 msize)
{
    char *p = first;
    u32 sub_size = fix_pool_sizes[index] + 4;
    u32 num_subblocks = msize / sub_size;
    u32 k;
    b->prev_ = tail;
    b->next_ = head;
    tail->next_ = b;
    head->prev_ = b;
    b->client_size_ = fix_pool_sizes[index];
    for (k = 0; k < num_subblocks - 1; ++k)
    {
        char* np;
        FixSubBlock* sb;

        sb = (FixSubBlock*)p;
        np = p + sub_size;
        sb->block_ = b;
        sb->next_ = (FixSubBlock*)np;
        p = np;
    }
    ((FixSubBlock*)p)->block_ = b;
    ((FixSubBlock*)p)->next_ = NULL;
    b->start_ = (FixSubBlock *)first;
    b->n_allocated_ = 0;
}

void* allocate_from_fixed_pools(__mem_pool_obj* pool_obj, u32 size)
{
    u32 i = 0;
    FixStart* fs;

    while (size > fix_pool_sizes[i])
    {
        ++i;
    }

    fs = &pool_obj->fix_start[i];

    if (fs->head_ == NULL || fs->head_->start_ == NULL)
    {
        u32 n = 0xFEC / (fix_pool_sizes[i] + 4);
        void* block;
        u32 max_n;
        u32 max_free_size;
        u32 msize;

        if (n > 0x100)
        {
            n = 0x100;
        }

        max_n = n;

        while (n >= 10)
        {
            block = soft_allocate_from_var_pools((Block**)pool_obj, n * (fix_pool_sizes[i] + 4) + 0x14, &max_free_size);
            if (block != NULL)
            {
                break;
            }

            if (max_free_size > 0x14)
            {
                n = (max_free_size - 0x14) / (fix_pool_sizes[i] + 4);
            }
            else
            {
                n = 0;
            }
        }

        if (block == NULL && n < max_n)
        {
            block = allocate_from_var_pools(pool_obj, max_n * (fix_pool_sizes[i] + 4) + 0x14);
            if (block == NULL)
            {
                return NULL;
            }
        }

        msize = __msize_inline(block);

        if (fs->head_ == NULL)
        {
            fs->head_ = (FixBlock*)block;
            fs->tail_ = (FixBlock*)block;
        }

        FixBlock_construct((FixBlock*)block, fs->tail_, fs->head_, i, (char*)block + 0x14, msize - 0x14);
        fs->head_ = (FixBlock*)block;
    }

    {
        FixSubBlock* p = fs->head_->start_;

        fs->head_->start_ = p->next_;
        ++fs->head_->n_allocated_;

        if (fs->head_->start_ == NULL)
        {
            fs->head_ = fs->head_->next_;
            fs->tail_ = fs->tail_->next_;
        }

        return (char*)p + 4;
    }
}

void deallocate_from_fixed_pools(__mem_pool_obj* pool_obj, void* ptr, u32 size)
{
    u32 i = 0;
    FixSubBlock* p;
    FixBlock* b;
    FixStart* fs;

    while (size > fix_pool_sizes[i])
    {
        ++i;
    }

    fs = &pool_obj->fix_start[i];
    p = FixSubBlock_from_pointer(ptr);
    b = p->block_;

    if (b->start_ == 0 && fs->head_ != b)
    {
        if (fs->tail_ == b)
        {
            fs->head_ = fs->head_->prev_;
            fs->tail_ = fs->tail_->prev_;
        }
        else
        {
            b->prev_->next_ = b->next_;
            b->next_->prev_ = b->prev_;
            b->next_ = fs->head_;
            b->prev_ = b->next_->prev_;
            b->prev_->next_ = b;
            b->next_->prev_ = b;
            fs->head_ = b;
        }
    }

    p->next_ = b->start_;
    b->start_ = p;

    if (--b->n_allocated_ == 0)
    {
        if (fs->head_ == b)
        {
            fs->head_ = b->next_;
        }

        if (fs->tail_ == b)
        {
            fs->tail_ = b->prev_;
        }

        b->prev_->next_ = b->next_;
        b->next_->prev_ = b->prev_;

        if (fs->head_ == b)
        {
            fs->head_ = 0;
        }

        if (fs->tail_ == b)
        {
            fs->tail_ = 0;
        }

        deallocate_from_var_pools(pool_obj, b);
    }
}

static inline void* __pool_alloc(__mem_pool* pool, u32 size)
{
    if (size == 0)
    {
        return 0;
    }

    if (size > (u32)-0x31)
    {
        return 0;
    }

    if (size <= 68)
    {
        return allocate_from_fixed_pools((__mem_pool_obj*)pool, size);
    }

    return allocate_from_var_pools((__mem_pool_obj*)pool, size);
}

static inline void __pool_free(__mem_pool* pool, void* ptr)
{
    __mem_pool_obj* pool_obj;
    u32 size;

    if (ptr == 0)
    {
        return;
    }

    pool_obj = (__mem_pool_obj*)pool;
    size = __msize_inline(ptr);

    if (size <= 68)
    {
        deallocate_from_fixed_pools(pool_obj, ptr, size);
    }
    else
    {
        deallocate_from_var_pools(pool_obj, ptr);
    }
}

void* __msl_malloc(u32 size)
{
    void* ptr;
    ptr = __pool_alloc(get_malloc_pool(), size);
    return ptr;
}

void __msl_free(void* ptr)
{
    __pool_free(get_malloc_pool(), ptr);
}
