typedef unsigned int u32;

typedef struct StreamCallbackRecord {
 u32 unknown00;char fileInfo[0x3C];u32 unknown40,unknown44,unknown48,unknown4C,unknown50;
 u32 flags,unknown58;
} StreamCallbackRecord;
typedef struct StreamCallbackState {
 StreamCallbackRecord records[6];
} StreamCallbackState;
typedef struct StreamCallbackGlobals {char unknown00[0x110];void*logger;} StreamCallbackGlobals;

extern StreamCallbackGlobals lbl_801E9D24;
extern const char lbl_802AF6A0[];
void fn_801FA014(void*,const char*,...);
int fn_8028F4B4(void);
int fn_8028EF84(void*);

void fn_8028AE40(void*unused,StreamCallbackState*self){
 int i;
 if(self){
  for(i=0;i<5;i++){
   if((self->records[i].flags&2)&&!(self->records[i].flags&0x40)){
    int status=fn_8028F4B4();
    char error;
    if(status)fn_801FA014(lbl_801E9D24.logger,lbl_802AF6A0,status);
    error=status==4||status==5||status==6||status==11||status==-1;
    if(error)fn_8028EF84(self);
    return;
   }
  }
 }
}
