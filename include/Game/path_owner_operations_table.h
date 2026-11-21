#ifndef GAME_PATH_OWNER_OPERATIONS_TABLE_H
#define GAME_PATH_OWNER_OPERATIONS_TABLE_H
#ifdef __cplusplus
struct SparseHandleDestroyOwner;
struct Table_801B57F8;
struct Owner;
struct Name;
struct Owner_801B4230;
struct PathLookupResult_801B3BE4;
struct PathLookupOwner_801B3BE4;
/* Path lookup slot28 carries the explicit native result-storage parameter. */
struct PathOwnerOperationsTable {
    const void *rtti;
    int offset_to_top;
    void * (*slot08)(void *);
    void * (*slot0C)(void *);
    void (*slot10)(void *);
    SparseHandleDestroyOwner * (*slot14)(SparseHandleDestroyOwner *, int);
    void (*slot18)(Table_801B57F8 *);
    void (*slot1C)(Owner *, const char *, const Name &);
    void (*slot20)(Owner_801B4230 *);
    void (*slot24)(void *, const char *);
    void (*slot28)(PathLookupResult_801B3BE4 *, PathLookupOwner_801B3BE4 *, const char *);
};
extern "C" {
#else
typedef struct PathOwnerOperationsTable PathOwnerOperationsTable;
#endif
extern PathOwnerOperationsTable lbl_802E9E70;
#ifdef __cplusplus
}
#endif
#endif
