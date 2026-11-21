#include "Game/bitset_internal.h"
struct IndexSelectionView {
    char unknown0[0x18];
    int cursor;
    BitSet_80207EE8 bits;
};
extern "C" int fn_80207B94(BitSet_80207EE8*,signed char,int);
extern "C" int fn_802654E8(IndexSelectionView*self,short*output,short limit){
    if(self->cursor<0)return 0;
    int count=0;
    while((short)count!=limit){
        self->cursor=fn_80207B94(&self->bits,1,self->cursor);
        if(self->cursor<0)break;
        output[(short)count++]=self->cursor++;
    }
    return count;
}
