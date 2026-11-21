/* Keyed engine record flag clear/set (fn_8024A1AC / fn_8024A430) reconstructed from GSQE78.
 * find() is the inlined body of fn_8024A86C; the row loops match fn_8024A6B4. */
struct Handle {
    signed int generation : 8;
    signed int index : 24;
};
struct Key {
    unsigned int value;
};
struct NodePrefix {
    Key key;
    char unknown04[4];
};
struct Node : NodePrefix {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void method40(int);
    virtual void method44(int);
    unsigned int flags0C;
    char unknown10[0x110];
    unsigned int flags120;
};
struct Entry {
    Node* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
};
struct Manager {
    char unknown00[8];
    Entry* entries;
};
struct Row {
    int count, capacity;
    int* items;
};
struct Owner {
    char unknown00[0x20];
    int targetCount, targetCapacity;
    Handle* targets;
    char unknown2C[0x38];
    int count, capacity;
    Handle* items;
    int rowCount, rowCapacity;
    Row* rows;
};

extern "C" {
extern struct Global {
    char unknown00[0x118];
    Manager* manager;
} lbl_801E9D24;
unsigned int fn_801F7EB8(const Handle*);
}

static inline Node* resolve(const Handle* handle)
{
    Entry* entry = &lbl_801E9D24.manager->entries[handle->index];
    return entry->generation == handle->generation ? entry->object : 0;
}

static inline int equal(const Node* object, const Key* key)
{
    return object->key.value == key->value;
}

static inline int find(Owner* self, const Key* key)
{
    int i;
    for (i = 0; i < self->count; i++) {
        if (fn_801F7EB8(&self->items[i]) && equal(resolve(&self->items[i]), key))
            return i;
    }
    return -1;
}

static inline void clearRow(Owner* self, Row* row)
{
    int j;
    for (j = 0; j < row->count; j++)
        resolve(&self->targets[row->items[j]])->flags120 &= ~0x1000;
}

static inline void setRow(Owner* self, Row* row)
{
    int j;
    for (j = 0; j < row->count; j++)
        resolve(&self->targets[row->items[j]])->flags120 |= 0x1000;
}

extern "C" signed char fn_8024A1AC(Owner* self, const Key* key, signed char mode)
{
    int i = find(self, key);
    Node* node;
    if (i < 0)
        return 0;
    node = resolve(&self->items[i]);
    if (!node)
        return 0;
    if (!mode) {
        if (node->flags0C & 2)
            return 0;
        node->flags0C &= ~1;
        clearRow(self, &self->rows[i]);
        return 1;
    }
    clearRow(self, &self->rows[i]);
    node->method44(-1);
    return 1;
}

extern "C" signed char fn_8024A430(Owner* self, const Key* key, signed char mode)
{
    int i = find(self, key);
    Node* node;
    if (i < 0)
        return 0;
    node = resolve(&self->items[i]);
    if (!node)
        return 0;
    if (!mode) {
        if (node->flags0C & 2)
            return 0;
        node->flags0C |= 1;
        setRow(self, &self->rows[i]);
        return 1;
    }
    setRow(self, &self->rows[i]);
    node->method40(-1);
    return 1;
}
