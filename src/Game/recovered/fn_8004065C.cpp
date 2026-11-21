typedef unsigned long u32;
struct Handle_801F7F10{union{u32 word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(void*,const Handle_801F7F10*,int);u32 fn_801F948C(void*,const char*);}
struct Node;struct Entry{Node*object;u32 opaque04,opaque08;signed char generation;char opaque0D[3];};struct Manager{char opaque00[8];Entry*entries;};struct Service{char opaque00[0x1C];Handle_801F7F10*state1C;};
extern "C" struct Global{char opaque00[0x118];Manager*manager118;char opaque11C[8];void*world124;char opaque128[0x14];Service*service13C;}lbl_801E9D24;
struct InitWord_0065C:Handle_801F7F10{InitWord_0065C(){word=0;}~InitWord_0065C(){}};
struct Handle_80020834:InitWord_0065C{Handle_80020834(){word=0;}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:InitWord_0065C{Handle_80020B90(){word=0;}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Key{u32 word;Key(){}Key(const char*s){word=fn_801F948C(this,s);}void set(const char*s){word=fn_801F948C(this,s);}};
inline Node*resolve(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager118->entries[h.bits.index];return e->generation==h.bits.tag?e->object:0;}
/* Object returned by fn_801F7EB8. refresh() rewrites the first word with itself through a by-value copy;
 * the load/store-back pair survives until the final (post-RA) peephole, which deletes it (L_S pattern),
 * but while present it reads r3 before the temporary's destructor arguments are set up. */
struct Resolved{u32 word;Resolved(){}Resolved(const Resolved&o):word(o.word){}Resolved&operator=(const Resolved&o){word=o.word;return*this;}void refresh(){Resolved copy(*this);*this=copy;}};
extern "C"{Resolved*fn_801F7EB8(const Handle_801F7F10*);void*fn_800BE2B0(void*);Handle_80020834 fn_801FCF20(Node*,const Key&,const Key&,const Handle_80020B90&);extern const char lbl_8029AA20[];}
/* Matching notes: the result temporary's destructor is preceded by `li r4,0; addi r3,r1,8` (li first) because the
 * block originally also held a load/store-back of the word behind fn_801F7EB8's result (see Resolved::refresh);
 * that pair pins `addi r3` behind the readers of r3 in the pre-RA schedule and is deleted by the final peephole.
 * Stack layout: the three Key slots (0x18/0x14/0x10) are declared before ctx (0xc) and filled in afterwards, and
 * the fourth fn_801FCF20 parameter is a reference (no by-value copy slot). */
extern "C" void fn_8004065C(void){
    if(!fn_800BE2B0(lbl_801E9D24.world124)){
        Key k,a,b;Handle_80020B90 ctx;Node*root=resolve(*lbl_801E9D24.service13C->state1C);
        k.set(lbl_8029AA20);b.set(lbl_8029AA20);a=b;
        fn_801F7EB8(&fn_801FCF20(root,k,a,ctx))->refresh();
    }
}
