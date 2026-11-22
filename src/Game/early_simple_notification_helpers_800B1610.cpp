extern "C" char* strcpy(char*,const char*);
extern "C" char* strcat(char*,const char*);
extern "C" char lbl_803791C8[2];
extern "C" void fn_800B1610(void*,char* output,const char* input) {
 if(!*output)strcpy(output,input);
 else {strcat(output,lbl_803791C8);strcat(output,input);}
}
