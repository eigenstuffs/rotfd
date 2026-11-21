/* Resource parent binding; see docs/notes/game-early-resource-parent-bind.md. */
struct Handle_801F7F10{union{unsigned long value;struct{signed int tag:8,index:24;}bits;};};
struct BindNode{char unknown00[0xC];Handle_801F7F10 parent;char unknown10[0x110];unsigned long flags;signed char active()const{return(flags>>7)&1;}};
struct BindEntry{BindNode*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct BindManager{int count,capacity;BindEntry*entries;};
struct BindSystem{char unknown00[8];Handle_801F7F10*handle;};
extern "C" struct BindContext{char unknown00[0x118];BindManager*manager;BindSystem*system;}lbl_801E9D24;
inline BindNode*resolve(const Handle_801F7F10&h){int index=h.bits.index;BindManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct BindRecord{char unknown00[0x58];Handle_801F7F10 handle;};
struct BindOwner{char unknown00[0xC];BindRecord*record;BindNode*node;BindNode*target;};
extern "C" {const Handle_801F7F10&fn_80268080(BindNode*,const Handle_801F7F10&);void fn_801EE978(BindNode*);void fn_801EDAAC(BindNode*,float,float,float);extern const float lbl_8037826C,lbl_80378274;}

extern "C" void fn_80026258(BindOwner* self) {
    self->node = resolve(self->record->handle);
    if (!self->node->active()) {
        if (resolve(self->node->parent)->flags & 0x80) {
            BindNode* system = resolve(*lbl_801E9D24.system->handle);
            self->target = resolve(fn_80268080(system, resolve(self->record->handle)->parent));
        }
    } else {
        self->target = resolve(fn_80268080(resolve(*lbl_801E9D24.system->handle), self->record->handle));
    }
    fn_801EE978(self->target);
    fn_801EDAAC(self->target, lbl_8037826C, lbl_8037826C, lbl_80378274);
}
