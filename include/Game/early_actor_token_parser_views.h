#ifndef GAME_EARLY_ACTOR_TOKEN_PARSER_VIEWS_H
#define GAME_EARLY_ACTOR_TOKEN_PARSER_VIEWS_H
extern "C" {void fn_801F372C(void*,char*);int strcmp(const char*,const char*);char*strcpy(char*,const char*);unsigned long fn_801F948C(void*,const char*);void fn_800A5CF8(void*,char*,unsigned char);void fn_800B1670(void*,char*,unsigned char);void fn_800A5C98(void*,char*,const char*);void fn_800B1610(void*,char*,const char*);
extern const char lbl_80378EBC[2],lbl_80378F50[2],lbl_80378F60[8],lbl_80378F68[8],lbl_80379194[2],lbl_803791B8[8],lbl_803791C0[8],lbl_803791CC[2];extern const char lbl_8029EBF0[],lbl_802A0250[],agent_type_registry_CMsgBoxManipulator[],lbl_8029E660[];extern const float lbl_80378E40;}
struct TokenParserName{unsigned long value;TokenParserName(const char*s){value=fn_801F948C(this,s);}TokenParserName&operator=(const TokenParserName&n){value=n.value;return*this;}bool operator==(const TokenParserName&n)const{return value==n.value;}};
struct TokenParserHandle{signed int tag:8,index:24;};
struct TokenParserActor{char unknown00[0x24];TokenParserHandle handle;char unknown28[0x390];float limit;char unknown3BC[0x15];signed char active;};
struct TokenParserOwner{char unknown00[8];TokenParserActor*actor;};
struct TokenParserEntry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct TokenParserManager{char unknown00[8];TokenParserEntry*entries;};
struct TokenParserContext{char unknown00[0x110];void*log;char unknown114[4];TokenParserManager*manager;};
extern "C" TokenParserContext lbl_801E9D24;
inline void*resolveParser(const TokenParserHandle&h){int index=h.index;TokenParserManager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.tag?m->entries[index].object:0;}
struct TokenParserScreen{char unknown00[0x100];int kind;};
struct TokenParserScene{char unknown00[0x15058];TokenParserScreen*screen;};
extern "C"{void*fn_8009F170(TokenParserActor*);void*fn_8005EE10(void*);void*fn_8005E9A0();signed char fn_80066454(void*,void*);float fn_8009F3E8(TokenParserActor*,void*,float*);void fn_8009FABC(TokenParserActor*,int);void fn_8009FB80(TokenParserActor*,int);void fn_800A4DF0(TokenParserOwner*,float);void fn_801F9D68(void*,const char*,...);void fn_801FA1F0(void*,const char*);}
#endif
