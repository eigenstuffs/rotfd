#ifndef GAME_HASH_TABLE_INTERNAL_H
#define GAME_HASH_TABLE_INTERNAL_H
struct Prefix { unsigned long unknown; };
struct HashKey : Prefix {
    virtual void dispose();
    virtual int hash();
    virtual int stride();
    virtual signed char equals(HashKey*);
    virtual void unknown18();
    virtual HashKey* clone();
};
struct HashTable { int cursor,capacity,count; HashKey**slots; };

extern "C" {
void fn_801EF610(void*,void*);
extern char lbl_801EF5C8[];
void fn_80207FDC(HashTable*,int);
}
#endif
