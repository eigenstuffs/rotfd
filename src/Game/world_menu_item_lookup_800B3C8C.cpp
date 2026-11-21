// World menu item lookup (fn_800B3C8C): maps the world index (+0x188) to its
// WORLD_* name from the pooled strings at lbl_802A0400 (base register; offset 0
// reached through a member pointer for the original addi r4,r4,0) and returns the
// first 0xC4-byte item in [first, first+count) whose name (+0x80) matches.
// The switch jump table is compiler-generated (EXACT-DATA -> jumptable_802BD720).
typedef unsigned long Word;
extern "C" Word fn_801F948C(void*,const char*);
struct Name{Word word;Name(){word=0;}Name(const char*s){word=fn_801F948C(this,s);}
 Name&operator=(const Name&n){word=n.word;return*this;}
 bool operator==(const Name&n)const{return word==n.word;}};
struct Item{char unknown00[0x80];Name name;char unknown84[0x40];};
struct Owner{char unknown00[0x2C];short first;char unknown2E[0x18];unsigned short count;char unknown48[0x28];Item*items;char unknown74[0x114];unsigned long world;
 Item*find(Name key){for(int i=first;i<first+count;++i){Item*item=&items[i];if(item->name==key)return item;}return 0;}};
struct Strings{char bb[12];char jf[12];char ca[12];char dn[12];char gl[12];char dg[12];char td[12];char test[12];};
extern "C" const Strings lbl_802A0400;
inline const char*worldBB(const Strings*s){const char(Strings::*m)[12]=&Strings::bb;return s->*m;}
extern "C" Item*fn_800B3C8C(Owner*self){
 const Strings*const s=&lbl_802A0400;
 Name key;
 switch(self->world){
 case 0:key=Name(worldBB(s));break;
 case 1:key=Name(s->jf);break;
 case 2:key=Name(s->ca);break;
 case 3:key=Name(s->dn);break;
 case 4:key=Name(s->gl);break;
 case 5:key=Name(s->dg);break;
 case 6:key=Name(s->td);break;
 case 7:key=Name(s->test);break;
 }
 Item*found=self->find(key);
 Item*result=0;
 if(found)result=found;
 return result;
}
