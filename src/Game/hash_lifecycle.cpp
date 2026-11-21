/* GSQE78 hash table; original names remain inferred. */
#include "hash_table_internal.h"

extern "C" {
void fn_802086C8(HashTable*t,signed char destroy){
 if(t->count){
  for(int i=0;i<t->capacity;++i){
   HashKey*p=t->slots[i];
   if(p){if(p!=(HashKey*)-1 && destroy)p->dispose();t->slots[i]=0;}
  }
  t->count=0;
 }
}

HashTable* fn_80208768(HashTable*t,short destroy){
 if(t){
  fn_802086C8(t,1);
  fn_801EF610(lbl_801EF5C8,t->slots);
  if(destroy>0)fn_801EF610(lbl_801EF5C8,t);
 }
 return t;
}

HashTable* fn_80208830(HashTable*t,int size){
 int n=1;while(n<size)n*=2;
 t->count=0;t->capacity=0;fn_80207FDC(t,n*2);return t;
}

HashTable* fn_80208888(HashTable*t){t->cursor=-1;t->count=0;t->capacity=0;fn_80207FDC(t,256);return t;}
}
