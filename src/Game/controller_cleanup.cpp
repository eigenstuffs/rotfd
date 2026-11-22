#include "game_controller.h"
#include "Game/service_interface_tables.h"

extern "C" {
extern unsigned char lbl_8028F698[16];
extern unsigned char lbl_801EF5C8[32];

void fn_8028FD50(void*, void*, int);
void fn_801EF610(void*, void*);
void fn_801FB1E8(void*, short);
}
struct ActionArray {
    int count, capacity;
    Action *data;
    void release_storage() {
        if(data) {
            fn_8028FD50(lbl_8028F698,data,capacity*sizeof(Action));
            data=0;
        }
    }
    ~ActionArray() {
        if(data) {
            for(int i=0;i<count;++i) data[i].~Action();
            release_storage();
            data=0;
        }
    }
};
struct ControllerStorage {
    unsigned char base[0xB10];
    void *vtable;
    ActionArray actions;
};
extern "C" ControllerStorage *fn_801F00B0(ControllerStorage *self,short flag)
{
    if(self) {
        self->vtable=&lbl_802EA8D8;
        self->actions.~ActionArray();
        fn_801FB1E8(self,0);
        if(flag>0) fn_801EF610(lbl_801EF5C8,self);
    }
    return self;
}
struct FlagController {
    unsigned char base[0xB04];
    unsigned int flags;
};
struct OutputBuffer {
    char *buffer;
    unsigned int reserved_04, length;
};
extern "C" {
unsigned long strlen(const char *);
void *memset(void *,int,unsigned long);
void OSReport(const char *,...);
extern const char lbl_8037A690[4];
void fn_801F01A8(void *) {}
void fn_801F01AC(FlagController *self,unsigned int mask) { self->flags |= mask; }
void fn_801F01BC(FlagController *self,unsigned int mask) { self->flags &= ~mask; }
void fn_801F01CC(OutputBuffer *self)
{
    unsigned long length = strlen(self->buffer);
    self->buffer[length-2] = '\n';
    self->buffer[length-1] = '\0';
    OSReport(lbl_8037A690,self->buffer);
    memset(self->buffer,0,0x6000);
    self->length=0;
}
void fn_801F0244(void *) {}
}

extern "C" void fn_801EFE3C(Controller *);
extern "C" int fn_801F0248(Controller *self)
{
    fn_801EFE3C(self);
    self->select(1);
    return 1;
}
