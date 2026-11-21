#ifndef GAME_ENGINE_OWNER_DIRTY_PROPAGATION_H
#define GAME_ENGINE_OWNER_DIRTY_PROPAGATION_H
typedef unsigned long OwnerDirtyWord;
struct OwnerDirtyHandle{
    signed int generation:8,index:24;
};
struct OwnerDirtyNode{
    char unknown00[0xC];
    OwnerDirtyHandle parent;
    char unknown10[0x120-0x10];
    OwnerDirtyWord flags;
};
struct OwnerDirtyEntry{
    OwnerDirtyNode*object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
};
struct OwnerDirtyManager{
    int count,capacity;
    OwnerDirtyEntry*entries;
};
extern "C"{
    extern struct{
        char unknown00[0x118];
        OwnerDirtyManager*manager;
    }
    lbl_801E9D24;
    void fn_8023D400(OwnerDirtyNode*,OwnerDirtyWord);
}
extern "C"{
    inline signed char fn_8023C798(const OwnerDirtyHandle*h){
        return h->generation;
    }
    inline int fn_8023C7B4(const OwnerDirtyHandle*h){
        return h->index;
    }
    inline OwnerDirtyEntry*fn_8023C7A4(OwnerDirtyManager*m,unsigned int index){
        return m->entries+index;
    }
    inline OwnerDirtyNode*fn_8023C2DC(OwnerDirtyManager*m,const OwnerDirtyHandle*h){
        int index=fn_8023C7B4(h);
        int generation=fn_8023C798(h);
        int actual=fn_8023C7A4(m,index)->generation;
        if(actual==generation)return fn_8023C7A4(m,index)->object;
        return 0;
    }
    inline OwnerDirtyNode*fn_8023C1C8(const OwnerDirtyHandle*h){
        return fn_8023C2DC(lbl_801E9D24.manager,h);
    }
    inline OwnerDirtyHandle*fn_8023D640(OwnerDirtyNode*n){
        return &n->parent;
    }
    inline OwnerDirtyWord fn_8023D638(const OwnerDirtyNode*n){
        return n->flags;
    }
    inline void fn_8023CD28(OwnerDirtyNode*n,OwnerDirtyWord flags){
        n->flags|=flags;
    }
}
#endif
