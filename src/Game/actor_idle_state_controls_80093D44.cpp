/* Actor idle-state controls: unless one of the blocking control states is
   active, chooses the idle follow-up state (0x1A from a retained copy of the
   owner's actor handle when states 0x18/0x19 are active and the actor state
   is 0 or 1; else 0x0A, 0x05 or 0x09).
   Handle layers follow actor_handle_counter_control_80087D04.cpp; the
   resolve helper (ActorIndex/EntryArray/matchesTag) is the one used by
   node_group_availability_query_80066624.cpp, which gives the original
   index/tag register allocation for the repeated state lookup. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node{char unknown00[0x3EC];int state;};
struct ActorIndex{int value;ActorIndex(int v):value(v){}operator const int&()const{return value;}};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};
struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};
struct Manager{int count,capacity;EntryArray entries;};
extern "C"struct Global{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
extern "C"{void fn_801F86C8(Manager*,const Handle_801F7F10*,int);extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Zero1_80093D44:Handle_801F7F10{Zero1_80093D44(){word=0;}~Zero1_80093D44(){}};
struct Zero2_80093D44:Zero1_80093D44{Zero2_80093D44(){word=0;}~Zero2_80093D44(){}};
struct Zero3_80093D44:Zero2_80093D44{Zero3_80093D44(){word=0;}~Zero3_80093D44(){}};
struct Handle_80025BF4:Zero3_80093D44{Handle_80025BF4(){word=0;}~Handle_80025BF4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80025B74:Handle_80025BF4{Handle_80025B74(){word=0;}~Handle_80025B74(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80038014:Handle_80025B74{Handle_80038014(const Handle_80038014&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80038014(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Controls{};
struct Owner{char unknown00[0x1AC];Handle_80038014 actor;char unknown1B0[0x168];Controls controls;};
extern "C"{void fn_80286058(void*,int);signed char fn_8007D604(Controls*,int);void fn_8007D6A0(Controls*,int);signed char fn_800946FC(Owner*);}
inline Node*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;const ActorIndex index(h.bits.index);const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}

extern "C" void fn_80093D44(Owner* self, void* event)
{
    fn_80286058(event, 0x6D);
    if (!fn_8007D604(&self->controls, 0x0E) && !fn_8007D604(&self->controls, 0x0F)
        && !fn_8007D604(&self->controls, 0x26) && !fn_8007D604(&self->controls, 0x10)
        && !fn_8007D604(&self->controls, 0x13) && !fn_8007D604(&self->controls, 0x06)
        && !fn_8007D604(&self->controls, 0x14) && !fn_8007D604(&self->controls, 0x15)
        && !fn_8007D604(&self->controls, 0x17) && !fn_8007D604(&self->controls, 0x1A)
        && !fn_8007D604(&self->controls, 0x1B) && !fn_8007D604(&self->controls, 0x28)
        && !fn_8007D604(&self->controls, 0x29) && !fn_8007D604(&self->controls, 0x12)
        && !fn_8007D604(&self->controls, 0x2C) && !fn_8007D604(&self->controls, 0x2D)
        && !fn_8007D604(&self->controls, 0x2E) && !fn_8007D604(&self->controls, 0x2F)
        && !fn_8007D604(&self->controls, 0x33)) {
        if (fn_8007D604(&self->controls, 0x18) || fn_8007D604(&self->controls, 0x19)) {
            const Handle_80038014& original = self->actor;
            Handle_80038014 actor((Handle_80038014(original)));
            if (resolve(actor)->state == 0 || resolve(actor)->state == 1)
                fn_8007D6A0(&self->controls, 0x1A);
        } else if (fn_8007D604(&self->controls, 0x0D))
            fn_8007D6A0(&self->controls, 0x0A);
        else if (fn_800946FC(self))
            fn_8007D6A0(&self->controls, 0x05);
        else if (!fn_8007D604(&self->controls, 0x05) && !fn_8007D604(&self->controls, 0x09)
                 && !fn_8007D604(&self->controls, 0x0A) && !fn_8007D604(&self->controls, 0x0B)
                 && !fn_8007D604(&self->controls, 0x0C) && !fn_8007D604(&self->controls, 0x1C))
            fn_8007D6A0(&self->controls, 0x09);
    }
}
