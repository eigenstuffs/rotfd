typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;struct Entry{Node*object;char opaque04[8];signed char tag;char opaque0D[3];signed char getTag()const{return tag;}};struct Manager{char opaque00[8];Entry*entries;};struct Service{char opaque00[0x1C];const Handle_801F7F10*owner;};
extern "C"{extern struct Global{char opaque00[0x118];Manager*manager;char opaque11C[0x20];Service*service;}lbl_801E9D24;void fn_801F86C8(Manager*,const Handle_801F7F10*,int);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];}
struct Handle_8002B67C:Handle_801F7F10{Handle_8002B67C(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002B67C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct QueryZero_7D074:Handle_801F7F10{QueryZero_7D074(){word=0;}~QueryZero_7D074(){}};
struct Handle_80021BCC:QueryZero_7D074{Handle_80021BCC(){word=0;}~Handle_80021BCC(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct QueryCopied_7D074:Handle_80021BCC{QueryCopied_7D074(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~QueryCopied_7D074(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Storage{char opaque00[8];};struct Node:Storage{
virtual void slot08();
virtual void slot0C();
virtual void slot10();
virtual void slot14();
virtual void slot18();
virtual void slot1C();
virtual void slot20();
virtual void slot24();
virtual void slot28();
virtual void slot2C();
virtual void slot30();
virtual void slot34();
virtual void slot38();
virtual void slot3C();
virtual void slot40();
virtual void slot44();
virtual void slot48();
virtual void slot4C();
virtual void slot50();
virtual void slot54();
virtual void slot58();
virtual void slot5C();
virtual void slot60();
virtual void slot64();
virtual void slot68();
virtual void slot6C();
virtual void slot70();
virtual void slot74();
virtual const Handle_801F7F10*getHandle(int);
char opaque0C[0x8C];const Handle_801F7F10*child;};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return m->entries[index].object;return 0;}
extern "C" Node*fn_8007D074(void*ignored){const Handle_801F7F10&source=*lbl_801E9D24.service->owner;Handle_8002B67C parent(source);const Handle_801F7F10&borrowed=*resolve(*resolve(parent)->child)->getHandle(0);QueryCopied_7D074 result(borrowed);return resolve(result);}
