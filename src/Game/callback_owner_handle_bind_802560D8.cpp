/* fn_802560D8: bind a callback owner to an incoming handle.
 * Stores `incoming` in owner->handle58 (counted assignment), hands the owner's
 * identity handle (+0x04) to the incoming object's owner slot (+0x130), and
 * when owner flag 0x4000 is set registers the bound object's related handle
 * (+0x1C) with the registry at lbl_801E9D24+0x158, output word at +0x54.
 * Compiled without exceptions (no extab); the Handle_801F7F10 ctor/dtor are
 * out-of-line (__ct__/__dt__15Handle_801F7F10Fv).
 *
 * EXACT-WEAK (retry2): the resolve uses an entry pointer
 * (`Entry*e=&m->entries[index]; if(e->tag==(signed char)h.tag)`) and the
 * registry key reads the generation through an explicit (signed char) cast;
 * together they colour the temporaries of the copy's resolve like the
 * original (previous indexed form stalled at 99.76%).
 * Flags: -O4,p -Cpp_exceptions off -RTTI off -use_lmw_stmw on, GC/1.3.2. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word value;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Object;
struct Entry{Object*object;Word key,unknown08;signed char tag;char pad[3];signed char generation()const{return tag;}};
struct Manager{int count,capacity;union{Entry*entries;char*bytes;};};
extern "C" struct Globals{char unknown00[0x118];Manager*manager;char unknown11C[0x3C];void*registry;}lbl_801E9D24;
struct Key;
extern "C"{void fn_801F86C8(Manager*,const void*,int);char fn_801F5F28(void*,Object*,const Key*,Word*,int);}
struct Zero1:Handle_801F7F10{Zero1(){value=0;}};
struct OneCopy:Zero1{OneCopy(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct DirectCopy:Handle_801F7F10{DirectCopy(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct Stored{
 union{Word value;struct{signed int tag:8,index:24;}bits;};
 template<class H>Stored&operator=(const H&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};
template<class H>inline Object*resolve(const H&h){
 Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];
 if(e->tag==(signed char)h.bits.tag)return e->object;
 return 0;
}
struct Key{Word value;Key(Word w):value(w){}};
template<class H>inline Key key(const H&h){
 Manager*m=lbl_801E9D24.manager;int index=h.bits.index;int generation=(signed char)h.bits.tag;int valid=0;
 if(index<m->count&&generation==((signed char*)m->entries)[index*16+12])valid=1;
 if(valid)return Key(*(Word*)((char*)m->entries+index*16+4));
 return Key(0);
}
struct Object{
 char unknown00[0x1C];Handle_801F7F10 related1C;char unknown20[0x110];Stored owner130;
 void setOwner(const Handle_801F7F10&h){owner130=OneCopy(h);}
};
struct Owner{Word unknown00;Handle_801F7F10 identity;char unknown08[0x30];unsigned long long flags;char unknown40[0x14];Word output54;Stored handle58;};
extern "C" void fn_802560D8(Owner*self,const Handle_801F7F10&incoming){
 self->handle58=incoming;
 const Handle_801F7F10&id=self->identity;
 resolve(incoming)->setOwner(DirectCopy(id));
 if(self->flags&0x4000ULL){
  OneCopy copy(resolve(self->handle58)->related1C);
  fn_801F5F28(lbl_801E9D24.registry,resolve(copy),&key(copy),&self->output54,0);
 }
}
