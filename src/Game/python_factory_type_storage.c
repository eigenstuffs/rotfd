/* The native registration loop fills one slot for each of its 56 type entries. */
struct FactoryType;
struct FactoryType* lbl_80318988[56];

typedef char FactoryTypePointerSizeCheck[sizeof(struct FactoryType*) == 4 ? 1 : -1];
typedef char FactoryTypeRegistrySizeCheck[sizeof(lbl_80318988) == 224 ? 1 : -1];
