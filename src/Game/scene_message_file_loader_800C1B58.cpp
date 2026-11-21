/* Original text-file loader; literal-pool/weak-EH proof is kept separately. */
#include "Game/early_resource_token_loop_views.h"
struct Message { unsigned long name; char text[256]; };
struct Owner { char unknown00[0xC]; Message* messages; int count; };
extern "C" { void*fn_801EFA1C(void*,unsigned long,const char*,const char*,int,int);void*__construct_new_array(void*,void*,void*,unsigned long,unsigned long);void*fn_800C19B8(void*);signed char fn_800C1D70(Owner*,ResourceTokenReader*,int);void fn_801F2E30(ResourceTokenReader*,int,int);extern const char lbl_80379500[8]; }
extern "C" signed char fn_800C1B58(Owner*self,const char*name) {
    int count; int index;
 Handle_8001FF04 handle(lbl_801E9D24.manager->load(name));
    if(!fn_801F7EB8(&handle))return 0;
    ResourceTokenReader* reader=&resolveResourceToken(handle)->reader;
    char token[256];
    fn_801F372C(reader,token);
    if(strcmp("BOX_TEXT_STRINGS",token))return 0;
    while(!fn_801F2E04(reader)) {
        if(!strcmp(token,lbl_80379500))++self->count;
        fn_801F372C(reader,token);
    }
    count=self->count;
    void* storage=fn_801EFA1C(lbl_801EF5C8,count*0x104+0x10,"Anonymous New","TextBoxString.cpp",0x6B,4);
    self->messages=(Message*)__construct_new_array(storage,(void*)fn_800C19B8,0,0x104,count);
    fn_801F2E30(reader,0,1);
    index=0;
    while(!fn_801F2E04(reader)) {
        if(!strcmp(token,lbl_80379500)){fn_800C1D70(self,reader,index);++index;}
        fn_801F372C(reader,token);
    }
    return 1;
}
