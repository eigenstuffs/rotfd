struct VisitRecordA { char pad00[4]; char value04[0x18]; };
struct VisitRecordB { char value00[8]; };
struct VisitGroupB { char pad00[4]; int count04; char pad08[4]; VisitRecordB* data0C; };
struct VisitOwner {
    char pad00[0x20]; char first20[0x4C]; int count6C; char pad70[4];
    VisitRecordA* data74; char pad78[4]; int count7C; char pad80[4];
    VisitGroupB* groups84; char pad88[0x20]; char tailA8[4];
};
extern "C" struct {char pad00[0x118]; void* manager;} lbl_801E9D24;
extern "C" void fn_801B3E54(void*, void*);
extern "C" void fn_801F6AF8(void*);
extern "C" void fn_801ACFC0(VisitOwner* self) {
    fn_801B3E54(lbl_801E9D24.manager, self->first20);
    int i;
    for (i=0; i<self->count6C; ++i) {
        fn_801B3E54(lbl_801E9D24.manager, self->data74[i].value04);
    }
    for (i=0; i<self->count7C; ++i) {
        for (int j=0; j<((VisitGroupB*)((char*)self->groups84 + 16*i))->count04; ++j) {
            fn_801B3E54(lbl_801E9D24.manager, ((VisitGroupB*)((char*)self->groups84 + 16*i))->data0C[j].value00);
        }
    }
    fn_801F6AF8(self->tailA8);
}
