/* Menu/score record visibility (fn_800A6234): stores the enable byte (+0x3C).
 * Enabled: every 0xD4-byte record (array +0x28, count +0x20) gets flag bit 0
 * (+0xA9) set, then cleared again for the TIMER, SCORE_ME, SCORE_YOU,
 * DISPLAY_MESSAGE and MENU_ACTION keys. Disabled: resets the time (+0x38) to
 * lbl_80378F8C (5.0f), clears the flag of the record found for a non-empty
 * name (fn_800A78E4), clears every record's flag for an empty name and sets
 * it for the MENU_NEWGAME/LOADGAME/OPTIONS/EXTRAS keys.
 *
 * Matching notes: the original used string literals pooled into
 * lbl_8029EC80 (shared with fn_800A7510) addressed from one base register.
 * The strings stay external here: a const pool pointer keeps the base in r31
 * and the offset-0 string is reached through a member pointer inside an
 * inline helper, which reproduces the original per-use addi rX,base,0 without
 * hoisting it out of the loop. The first loop's flag set reads and writes
 * through two pointer-increment accessor results, giving the original
 * add/lbz 0xA9 addressing; the indexed clear goes through a reference
 * accessor for the original addi/lbzx form. */
typedef unsigned long Word;
struct Name{Word value;Name(const char*s);bool operator==(const Name&n)const{return value==n.value;}};
struct Record{Word unknown00;Name key;char unknown08[0xA1];unsigned char flags;char unknownAA[0x2A];};
struct Owner{char unknown00[0x20];int count;char unknown24[4];Record*records;char unknown2C[0xC];float time;signed char enabled;
 Record&getRecord(int i){return records[i];}
 Record*at(int n){Record*r=records;r+=n;return r;}};
struct Strings{char scoreMe[0xC];char scoreYou[0xC];char displayMessage[0x10];char menuAction[0xC];
 char menuNewGame[0x10];char menuLoadGame[0x10];char menuOptions[0x10];char menuExtras[0xC];};
extern "C"{
extern const Strings lbl_8029EC80;
extern const char lbl_80378F84[6]; /* "TIMER" */
extern const char lbl_80378F90[4]; /* "" */
extern const float lbl_80378F8C;
Word fn_801F948C(void*,const char*);
int fn_800A78E4(Owner*,const Name&);
}
inline Name::Name(const char*s){value=fn_801F948C(this,s);}
inline const char*scoreMe(const Strings*s){const char(Strings::*m)[0xC]=&Strings::scoreMe;return s->*m;}

extern "C" void fn_800A6234(Owner*self,signed char enable,const Name&name){
 const Strings*const s=&lbl_8029EC80;
 self->enabled=enable;
 if(enable){
  for(int i=0;i<self->count;i++){
   self->at(i)->flags=self->at(i)->flags|1;
   if(self->records[i].key==Name(lbl_80378F84)||self->records[i].key==Name(scoreMe(s))||
      self->records[i].key==Name(s->scoreYou)||self->records[i].key==Name(s->displayMessage)||
      self->records[i].key==Name(s->menuAction))
    self->records[i].flags&=~1;
  }
 }else{
  self->time=lbl_80378F8C;
  if(!(name==Name(lbl_80378F90))){
   int index=fn_800A78E4(self,name);
   if(index>=0)self->getRecord(index).flags&=~1;
  }
  for(int i=0;i<self->count;i++){
   if(name==Name(lbl_80378F90))self->records[i].flags&=~1;
   if(self->records[i].key==Name(s->menuNewGame))self->records[i].flags|=1;
   else if(self->records[i].key==Name(s->menuLoadGame))self->records[i].flags|=1;
   else if(self->records[i].key==Name(s->menuOptions))self->records[i].flags|=1;
   else if(self->records[i].key==Name(s->menuExtras))self->records[i].flags|=1;
  }
 }
}
