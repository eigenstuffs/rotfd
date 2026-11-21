#ifndef GAME_EARLY_TEXT_RECORD_FORMAT_VIEWS_H
#define GAME_EARLY_TEXT_RECORD_FORMAT_VIEWS_H
typedef unsigned long Word;
struct TextHandle{signed int tag:8,index:24;};
struct TextPrefix{char unknown00[8];};
struct TextActor:TextPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23();virtual void slot24();virtual void slot25();virtual Word query(const Word&,const TextHandle&);};
struct TextEntry{TextActor*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct TextManager{char unknown00[8];TextEntry*entries;};
struct TextContext{char unknown00[0x118];TextManager*manager;};
extern "C"TextContext lbl_801E9D24;
inline TextActor*resolveText(const TextHandle&h){int index=h.index;TextManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct TextName{Word value;TextName(const char*s);bool operator==(const TextName&n)const{return value==n.value;}};
struct TextRecord{Word unknown00;TextName key;char text[0x80];TextHandle handles[4];Word values[4];unsigned char count;char unknownA9[0x2B];char*getText(){return text;}};
struct TextOwner{char unknown00[0x28];TextRecord*records;char unknown2C[4];TextHandle handle;char unknown34[0x14];char*savedText;float time;char unknown50[0x1934];unsigned char flag;TextRecord&getRecord(int i){return records[i];}char*getText(int i){return records[i].text;}};
extern "C"{extern const char lbl_8029EC80[];extern int lbl_8037767C;extern const float lbl_80378F78;Word fn_801F948C(void*,const char*);int fn_800A78E4(TextOwner*,const TextName&);char*strcpy(char*,const char*);void fn_801F44DC(void*,const char*,Word*);}
inline TextName::TextName(const char*s){value=fn_801F948C(this,s);}
#endif
