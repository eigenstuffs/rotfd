#include "Game/node_matrix_pool.h"
extern "C" {
void *memset(void *, int, unsigned long);
extern const float lbl_8037A428;
}
struct NodePoolMatrix_801C9E3C {
    float values[16];
    void identity() {
        memset(this, 0, sizeof(*this));
        values[0]=lbl_8037A428;
        values[5]=lbl_8037A428;
        values[10]=lbl_8037A428;
        values[15]=lbl_8037A428;
    }
};
extern "C" short fn_801C9E3C(NodePool *self)
{
    short slot=fn_80207B94(&self->occupied, 0, 0);
    self->occupied.words[slot>>5] |= 1U<<(slot&31);
    for(int i=0; i<self->bankCount; ++i)
        reinterpret_cast<NodePoolMatrix_801C9E3C *>(self->banks[i])[slot].identity();
    return slot;
}
