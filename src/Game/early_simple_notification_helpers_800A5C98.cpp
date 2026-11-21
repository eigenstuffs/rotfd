/* Original notification, virtual setup and string helpers; see docs/notes/game-early-simple-notification-helpers.md. */
extern "C" char* strcpy(char*,const char*);
extern "C" char* strcat(char*,const char*);
extern "C" char lbl_80378F70[2];
extern "C" void fn_800A5C98(void*,char* output,const char* input) {
 if(!*output)strcpy(output,input);
 else {strcat(output,lbl_80378F70);strcat(output,input);}
}
