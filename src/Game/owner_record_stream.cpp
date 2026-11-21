struct OwnerRecordStreamView {
    char unknown00[0x11C];
    char record[8];
    char unknown124[0xC];
    unsigned long handle;
};

extern "C" {
extern struct {
    char unknown00[0x118];
    void* manager;
} lbl_801E9D24;
void fn_80243E44(OwnerRecordStreamView*, void**);
void* fn_801E9F40(void*, const void*, unsigned long);
void fn_801B41B8(void*, void*, void**);
}

extern "C" void fn_80241DAC(OwnerRecordStreamView* self, void** cursor)
{
    fn_80243E44(self, cursor);
    *cursor = fn_801E9F40(self->record, *cursor, 8);
    fn_801B41B8(lbl_801E9D24.manager, &self->handle, cursor);
}
