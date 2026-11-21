// Assign a hierarchy group to its active game range and bind its owner.
typedef unsigned long u32;
struct Handle {union {u32 value;struct{signed int generation:8;signed int index:24;}bits;};};
struct Object {
    char unknown[0xC];Handle owner;char unknown10[0xE0-0x10];int width,offset;
    const Handle& getOwner()const{return owner;}
    int getWidth()const{return width;}
};
struct Entry {Object* object;u32 unused[2];signed char generation;char padding[3];};
struct Manager {u32 unused[2];Entry* entries;};
struct Game {char unknown[0x234];u32 flags;};
struct Globals {char unknown[0x114];Game* game;Manager* manager;};
struct HandleList {int count,capacity;Handle* data;};
struct Groups {char unknown[0x14];HandleList entries;};
extern "C" Globals lbl_801E9D24;
struct Handle_801F7F10 {Handle_801F7F10();~Handle_801F7F10();u32 value;};
extern "C" void fn_801F86C8(Manager*,const void*,short);
struct StateZeroHandle:Handle_801F7F10 {StateZeroHandle(){value=0;}};
struct StateHandle:StateZeroHandle {
    StateHandle(){value=0;}
    StateHandle(const Handle& h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
};
inline Object* get(Manager* manager,const Handle& h) {
    Entry* entry=manager->entries+h.bits.index;
    if(entry->generation==h.bits.generation)return entry->object;
    return 0;
}
inline Object* resolve(const Handle& h) {
    Entry* entry=lbl_801E9D24.manager->entries+h.bits.index;
    return entry->generation==h.bits.generation?entry->object:0;
}
inline int available(Groups* self) {
    Manager* manager=lbl_801E9D24.manager;
    int count=4;
    for(int i=0;i<self->entries.count;++i) {
        Object* object=get(manager,self->entries.data[i]);
        if(object && object->offset>=0)count-=object->width;
    }
    return count;
}
inline int assigned(Groups* self) {
    Manager* manager=lbl_801E9D24.manager;
    int count=0;
    for(int i=0;i<self->entries.count;++i) {
        Object* object=get(manager,self->entries.data[i]);
        if(object && object->offset>=0)count+=object->width;
    }
    return count;
}
extern "C" {
void fn_80202464(Object*);
void fn_801E1658(Game*,int);
void fn_8003125C(Game*,int,StateHandle);
void fn_8020279C(Object*,int,int);
void fn_801FEF6C(Groups*,int);
void fn_801FEF6C(Groups* self,int index) {
    int capacity=available(self);
    int offset=assigned(self);
    Object* object=resolve(self->entries.data[index]);
    int width=object->getWidth();
    if(object->offset>=0){capacity+=width;offset-=width;}
    int start=4-capacity;
    fn_801E1658(lbl_801E9D24.game,start+width);
    for(int i=0;i<width;++i)
        fn_8003125C(lbl_801E9D24.game,offset+i,StateHandle(object->getOwner()));
    lbl_801E9D24.game->flags|=2;
    fn_8020279C(object,start,width);
}
}
