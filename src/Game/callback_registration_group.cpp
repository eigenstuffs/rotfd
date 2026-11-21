extern "C" {
extern const char lbl_802AECC8[];
extern const char lbl_8037B580[5], lbl_8037B588[6], lbl_8037B590[5];
extern struct { char unknown00[0x144]; void* first; char unknown148[0x10]; void* second; } lbl_801E9D24;
void fn_8025FD04(void*, const char*, const char*, void*);
}
extern "C" void fn_80260BFC(void* self)
{
    const char* messages = (const char*)&lbl_802AECC8;
    fn_8025FD04(self, messages + 0x20, lbl_8037B580, (char*)self + 0x20);
    fn_8025FD04(self, messages + 0x48, lbl_8037B588, lbl_801E9D24.first);
    fn_8025FD04(self, messages + 0x70, lbl_8037B590, lbl_801E9D24.second);
}
