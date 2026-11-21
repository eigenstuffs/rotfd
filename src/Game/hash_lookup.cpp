/* GSQE78 hash table; original names remain inferred. */
#include "hash_table_internal.h"

extern "C" {
HashKey* fn_80208240(HashTable*t){
 if(t->cursor<0)return 0;
 if(t->cursor>=t->capacity){t->cursor=-1;return 0;}
 while(t->cursor<t->capacity){
  HashKey*p=t->slots[t->cursor];++t->cursor;
  if(p && p!=(HashKey*)-1)return p;
 }
 t->cursor=-1;return 0;
}

void fn_802082C4(HashTable*t){if(!t->count){t->cursor=-1;return;}t->cursor=0;}

signed char fn_802082E8(HashTable*t,HashKey*key,HashKey**out){
 int index=(t->capacity-1)&key->hash();
 int step=key->stride();if(!(step&1))++step;
 for(;;){
  HashKey*p=t->slots[index];if(!p)return 0;
  if(p!=(HashKey*)-1 && p->equals(key)){*out=t->slots[index];return 1;}
  index=(t->capacity-1)&(index+step);
 }
}
}
