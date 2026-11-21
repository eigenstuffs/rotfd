/* Message box initialization: allocate and load the box text table, reset the
   line list to the text buffer and bind the default font service, reporting a
   missing font.  The diagnostic strings live in the shared MessageBox.cpp
   literal pool lbl_802A2218 ("Anonymous New" +0x0, "MessageBox.cpp" +0x10,
   "Message Box: No font, incorrect initialization !" +0x20), which is owned by
   native_readable_pools_802A2218.cpp.  The original addressed that pool as a
   pooled base plus offset (addi rX,base,0x0 for the first string); reading the
   pool text through a data member pointer keeps that zero-offset addi. */
struct MessageBoxFont;
struct MessageBoxFontService{char unknown00[0x24];MessageBoxFont*font;};
struct MessageBoxContext{char unknown00[0x110];void*console;char unknown114[0x38];MessageBoxFontService*fontService;};
struct MessageBoxInitView{
 char unknown00[0x34];MessageBoxFont*font;
 char*lines[10];int lineCount;
 char text[256];char unknown164[0x624-0x164];void*table;
};
struct MessageBoxStrings{char text[0x54];};
extern "C"{
extern char lbl_801EF5C8[];
extern MessageBoxContext lbl_801E9D24;
extern const MessageBoxStrings lbl_802A2218;
void*fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);
void*fn_800C1A08(void*);
void fn_800C1B58(void*,void*);
void fn_801FA014(void*,const char*,...);
}
inline const char*poolText(const MessageBoxStrings*pool){const char(MessageBoxStrings::*text)[0x54]=&MessageBoxStrings::text;return pool->*text;}
extern "C" void fn_800C2474(MessageBoxInitView*self,void*name){
 void*table=fn_801EFA1C(lbl_801EF5C8,0x18,poolText(&lbl_802A2218),poolText(&lbl_802A2218)+0x10,0x8A,4);
 if(table)table=fn_800C1A08(table);
 self->table=table;
 fn_800C1B58(self->table,name);
 self->lines[0]=self->text;
 self->lineCount=1;
 if(!self->font)self->font=lbl_801E9D24.fontService->font;
 if(!self->font)fn_801FA014(lbl_801E9D24.console,poolText(&lbl_802A2218)+0x20);
}
