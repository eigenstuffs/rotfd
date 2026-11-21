#ifndef GAME_HASH_KEY_TABLES_H
#define GAME_HASH_KEY_TABLES_H
struct PointerKey;
struct IntegerKey;
typedef struct PointerKeyInterfaceTable {
    const void *rtti;
    int offset_to_top;
    void (*release)(struct PointerKey *);
    unsigned long (*hash_sum)(struct PointerKey *);
    unsigned long (*hash_xor)(struct PointerKey *);
    signed char (*equal)(struct PointerKey *, struct PointerKey *);
    signed char (*different)(struct PointerKey *, struct PointerKey *);
    struct PointerKey *(*clone)(struct PointerKey *);
} PointerKeyInterfaceTable;
typedef struct IntegerKeyInterfaceTable {
    const void *rtti;
    int offset_to_top;
    void (*release)(struct IntegerKey *);
    signed long (*hash_sum)(struct IntegerKey *);
    signed long (*hash_xor)(struct IntegerKey *);
    signed char (*equal)(struct IntegerKey *, struct IntegerKey *);
    signed char (*different)(struct IntegerKey *, struct IntegerKey *);
    struct IntegerKey *(*clone)(struct IntegerKey *);
} IntegerKeyInterfaceTable;
#ifdef __cplusplus
extern "C" {
#endif
extern PointerKeyInterfaceTable lbl_802EAF80;
extern IntegerKeyInterfaceTable lbl_802EAFC0;
#ifdef __cplusplus
}
#endif
#endif
