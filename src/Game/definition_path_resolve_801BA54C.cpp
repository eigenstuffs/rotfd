// Partial text split: fn_801BA54C only. fn_801B9318..fn_801BA38C before it
// (sphere/capsule collision queries, 89.6-99.6%) remain original code; full
// draft: scratch/claude_match/auto_03_801B9318_text/final.cpp.
/* auto_03_801B9318_text, partial run fn_801BA54C: resolve a relative
   definition-file path against a base path (strip "..\" components from the
   base, skip a leading ".\"); absolute paths ("X:" or "\\") are copied.
   GC/1.3.2, -O4,p, -Cpp_exceptions off, fp_contract on (same flags as
   segment_shape_collision_queries_801B602C.cpp).

   Notes: the first parameter must be a plain char*: the char* -> const char*
   conversion of `path = original` stops copy propagation, so the path checks
   read the copy (r29) as in the original.  `absolute` is declared before
   `path` (saved-register order), the first strstr result is copied into the
   loop variable (cmplwi on the call result, then mr), and the diagnostic
   pool lbl_802AC980 (owned by native_readable_pools_802AC980) is reached via
   one base pointer, its offset-0 string as dbPath - 0x24. */
typedef unsigned long Word;
struct Globals {char unknown00[0x10C];Word flags;void*console;};
struct Pool{char conflict[0x24];char dbPath[0x10];char relative[0x10];};
extern "C"{
 extern Globals lbl_801E9D24;
 extern const Pool lbl_802AC980;
 extern __declspec(section ".sdata2") const char lbl_8037A270[],lbl_8037A274[];
 Word strlen(const char*);
 const char*strstr(const char*,const char*);
 char*strncpy(char*,const char*,Word);
 char*strcpy(char*,const char*);
 void fn_801FA014(void*,const char*,...);
}
inline const char*dbPathText(const Pool*p){const char(Pool::*m)[0x10]=&Pool::dbPath;return p->*m;}
inline const char*conflictText(const Pool*p){return dbPathText(p)-sizeof(p->conflict);}

extern "C" void fn_801BA54C(char*original,char*output,const char*base){
 const Pool*const pool=&lbl_802AC980;
 int length=strlen(base);signed char absolute=0;const char*path=original;
 if(original[1]==':')absolute=1;
 if(path[0]=='\\'&&original[1]=='\\')absolute=1;
 if(strlen(path)<2)absolute=0;
 if(!absolute){
  while(base[length]!='\\')--length;
  const char*first=strstr(path,lbl_8037A270);const char*found=first;
  if(!first){if(strstr(path,lbl_8037A274))path+=2;}
  else while(found){
   --length;
   while(length>=0&&base[length]!='\\')--length;
   if(length<0){
    if(!(lbl_801E9D24.flags&0x800)){
     fn_801FA014(lbl_801E9D24.console,conflictText(pool));
     fn_801FA014(lbl_801E9D24.console,pool->dbPath,base);
     fn_801FA014(lbl_801E9D24.console,pool->relative,original);
    }
    strcpy(output,original);return;
   }
   path=found+strlen(lbl_8037A270);
   found=strstr(path,lbl_8037A270);
  }
  strncpy(output,base,length+1);strcpy(output+(length+1),path);
 }else strcpy(output,original);
}
